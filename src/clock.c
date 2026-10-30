#include "global.h"
#include "event_data.h"
#include "rtc.h"
#include "time_events.h"
#include "field_specials.h"
#include "lottery_corner.h"
#include "dewford_trend.h"
#include "tv.h"
#include "field_weather.h"
#include "berry.h"
#include "main.h"
#include "overworld.h"
#include "wallclock.h"
#include "random.h"
#include "constants/items.h"

#define OLDALE_GYM_FOLLOWER_REWARD_WAIT_MINUTES 30

static const u16 sOldaleGymFollowerRewardBalls[] =
{
    ITEM_ULTRA_BALL,
    ITEM_GREAT_BALL,
    ITEM_POKE_BALL,
    ITEM_NET_BALL,
    ITEM_DIVE_BALL,
    ITEM_NEST_BALL,
    ITEM_REPEAT_BALL,
    ITEM_TIMER_BALL,
    ITEM_LUXURY_BALL,
    ITEM_PREMIER_BALL,
};

static void UpdatePerDay(struct Time *localTime);
static void UpdatePerMinute(struct Time *localTime);
static void UpdateOldaleGymFollowerTimer(struct Time *localTime);

static void InitTimeBasedEvents(void)
{
    FlagSet(FLAG_SYS_CLOCK_SET);
    RtcCalcLocalTime();
    gSaveBlock2Ptr->lastBerryTreeUpdate = gLocalTime;
    VarSet(VAR_DAYS, gLocalTime.days);
}

void DoTimeBasedEvents(void)
{
    if (FlagGet(FLAG_SYS_CLOCK_SET) && !InPokemonCenter())
    {
        RtcCalcLocalTime();
        UpdatePerDay(&gLocalTime);
        UpdatePerMinute(&gLocalTime);
    }
}

void StartOldaleGymFollowerTimer(void)
{
    if (VarGet(VAR_OLDALE_GYM_FOLLOWER_TIMER_STATE) == 0
     && VarGet(VAR_OLDALE_GYM_FOLLOWERS) != 0)
    {
        RtcCalcLocalTime();
        VarSet(VAR_OLDALE_GYM_FOLLOWER_START_DAY, gLocalTime.days);
        VarSet(VAR_OLDALE_GYM_FOLLOWER_START_MINUTE, gLocalTime.hours * 60 + gLocalTime.minutes);
        VarSet(VAR_OLDALE_GYM_FOLLOWER_START_SECOND, gLocalTime.seconds);
        VarSet(VAR_OLDALE_GYM_FOLLOWER_TIMER_STATE, 1);
    }
}

void CheckOldaleGymFollowerTimer(void)
{
    if (VarGet(VAR_OLDALE_GYM_FOLLOWER_TIMER_STATE) == 0)
    {
        StartOldaleGymFollowerTimer();
        return;
    }

    if (VarGet(VAR_OLDALE_GYM_FOLLOWER_TIMER_STATE) == 1)
    {
        RtcCalcLocalTime();
        UpdateOldaleGymFollowerTimer(&gLocalTime);
    }
}

u16 GetOldaleGymFollowerReward(void)
{
    u16 followerCount = VarGet(VAR_OLDALE_GYM_FOLLOWERS);

    if (followerCount == 0)
        return ITEM_NONE;
    if (followerCount > 5)
        followerCount = 5;

    if (Random() % 100 < followerCount * 20)
        return ITEM_MASTER_BALL;

    return sOldaleGymFollowerRewardBalls[Random() % ARRAY_COUNT(sOldaleGymFollowerRewardBalls)];
}

void CompleteOldaleGymFollowerReward(void)
{
    if (VarGet(VAR_OLDALE_GYM_FOLLOWER_TIMER_STATE) == 3)
    {
        VarSet(VAR_OLDALE_GYM_FOLLOWER_TIMER_STATE, 0);
        StartOldaleGymFollowerTimer();
    }
}

static void UpdateOldaleGymFollowerTimer(struct Time *localTime)
{
    struct Time startTime;
    struct Time difference;
    s32 elapsedSeconds;

    if (VarGet(VAR_OLDALE_GYM_FOLLOWER_TIMER_STATE) == 0)
    {
        StartOldaleGymFollowerTimer();
        return;
    }

    if (VarGet(VAR_OLDALE_GYM_FOLLOWER_TIMER_STATE) != 1)
        return;

    startTime.days = VarGet(VAR_OLDALE_GYM_FOLLOWER_START_DAY);
    startTime.hours = 0;
    startTime.minutes = 0;
    startTime.seconds = VarGet(VAR_OLDALE_GYM_FOLLOWER_START_SECOND);
    startTime.hours = VarGet(VAR_OLDALE_GYM_FOLLOWER_START_MINUTE) / 60;
    startTime.minutes = VarGet(VAR_OLDALE_GYM_FOLLOWER_START_MINUTE) % 60;
    CalcTimeDifference(&difference, &startTime, localTime);
    elapsedSeconds = (((difference.days * 24) + difference.hours) * 60 + difference.minutes) * 60 + difference.seconds;

    if (elapsedSeconds >= OLDALE_GYM_FOLLOWER_REWARD_WAIT_MINUTES * 60)
        VarSet(VAR_OLDALE_GYM_FOLLOWER_TIMER_STATE, 2);
}

static void UpdatePerDay(struct Time *localTime)
{
    u16 *days = GetVarPointer(VAR_DAYS);
    u16 daysSince;

    if (*days != localTime->days && *days <= localTime->days)
    {
        daysSince = localTime->days - *days;
        ClearDailyFlags();
        UpdateDewfordTrendPerDay(daysSince);
        UpdateTVShowsPerDay(daysSince);
        UpdateWeatherPerDay(daysSince);
        UpdatePartyPokerusTime(daysSince);
        UpdateMirageRnd(daysSince);
        UpdateBirchState(daysSince);
        UpdateFrontierManiac(daysSince);
        UpdateFrontierGambler(daysSince);
        SetShoalItemFlag(daysSince);
        SetRandomLotteryNumber(daysSince);
        *days = localTime->days;
    }
}

static void UpdatePerMinute(struct Time *localTime)
{
    struct Time difference;
    int minutes;

    CalcTimeDifference(&difference, &gSaveBlock2Ptr->lastBerryTreeUpdate, localTime);
    minutes = 24 * 60 * difference.days + 60 * difference.hours + difference.minutes;
    if (minutes != 0)
    {
        if (minutes >= 0)
        {
            BerryTreeTimeUpdate(minutes);
            gSaveBlock2Ptr->lastBerryTreeUpdate = *localTime;
        }
    }
}

static void ReturnFromStartWallClock(void)
{
    InitTimeBasedEvents();
    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void StartWallClock(void)
{
    SetMainCallback2(CB2_StartWallClock);
    gMain.savedCallback = ReturnFromStartWallClock;
}

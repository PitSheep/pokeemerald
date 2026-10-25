#include "global.h"
#include "overworld_wild_mon.h"
#include "wild_encounter.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "field_control_avatar.h"
#include "fieldmap.h"
#include "metatile_behavior.h"
#include "battle_setup.h"
#include "sound.h"
#include "event_data.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/species.h"
#include "constants/trainer_types.h"
#include "constants/vars.h"
#include "constants/wild_encounter.h"
#include "random.h"

EWRAM_DATA static struct OverworldWildMon sOverworldWildMons[MAX_OVERWORLD_WILD_MONS];
EWRAM_DATA static bool8 sWildBattleTriggered = FALSE;
EWRAM_DATA static u8 sPostBattleInvulnerabilitySteps = 0;
EWRAM_DATA static u8 sStepSpawnCounter = 0;
EWRAM_DATA static u16 sRefreshFrameCounter = 0;

bool8 IsOverworldWildMonObjEvent(u8 localId)
{
    return (localId >= OBJ_EVENT_ID_OW_MON_FIRST && localId <= OBJ_EVENT_ID_OW_MON_LAST);
}

s8 GetOverworldWildMonIndexByLocalId(u8 localId)
{
    u8 i;
    for (i = 0; i < MAX_OVERWORLD_WILD_MONS; i++)
    {
        if (sOverworldWildMons[i].active && sOverworldWildMons[i].localId == localId)
            return i;
    }
    return -1;
}

u8 GetActiveOverworldWildMonCount(void)
{
    u8 i;
    u8 count = 0;
    for (i = 0; i < MAX_OVERWORLD_WILD_MONS; i++)
    {
        if (sOverworldWildMons[i].active)
            count++;
    }
    return count;
}

static s8 GetFreeOverworldWildMonSlot(void)
{
    u8 i;
    for (i = 0; i < MAX_OVERWORLD_WILD_MONS; i++)
    {
        if (!sOverworldWildMons[i].active)
            return i;
    }
    return -1;
}

static u8 CountFreeObjectEvents(void)
{
    u8 i;
    u8 count = 0;
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (!gObjectEvents[i].active)
            count++;
    }
    return count;
}

static bool8 TrySpawnOverworldWildMonAt(s16 x, s16 y, u8 terrain)
{
    s8 slot = GetFreeOverworldWildMonSlot();
    u16 species = SPECIES_NONE;
    u8 level = 5;
    u16 graphicsId;
    u8 objEventId;
    struct ObjectEventTemplate template;

    if (slot < 0)
        return FALSE;

    if (CountFreeObjectEvents() < 2)
        return FALSE;

    if (!GetWildEncounterDataForTerrain(terrain, &species, &level) || species == SPECIES_NONE)
        return FALSE;

    graphicsId = species + OBJ_EVENT_GFX_BULBASAUR - 1;

    // Handle Unown letter sprite mapping if applicable
    if (graphicsId == OBJ_EVENT_GFX_UNOWN_A)
    {
        u8 unownLetter = Random() % 28;
        if (unownLetter)
            graphicsId = OBJ_EVENT_GFX_DEOXYS_SPEED + unownLetter;
    }

    template.localId = OBJ_EVENT_ID_OW_MON_FIRST + slot;
    template.graphicsId = graphicsId;
    template.kind = OBJ_KIND_NORMAL;
    template.x = x - MAP_OFFSET;
    template.y = y - MAP_OFFSET;
    template.elevation = 3;
    template.movementType = MOVEMENT_TYPE_WANDER_AROUND;
    template.movementRangeX = 2;
    template.movementRangeY = 2;
    template.trainerType = TRAINER_TYPE_NONE;
    template.trainerRange_berryTreeId = 0;
    template.script = NULL;
    template.flagId = 0;

    objEventId = SpawnSpecialObjectEvent(&template);
    if (objEventId == OBJECT_EVENTS_COUNT)
        return FALSE;

    sOverworldWildMons[slot].active = TRUE;
    sOverworldWildMons[slot].objEventId = objEventId;
    sOverworldWildMons[slot].localId = template.localId;
    sOverworldWildMons[slot].species = species;
    sOverworldWildMons[slot].level = level;
    sOverworldWildMons[slot].terrain = terrain;
    sOverworldWildMons[slot].spawnX = x;
    sOverworldWildMons[slot].spawnY = y;
    return TRUE;
}

void TrySpawnOverworldWildMons(void)
{
    u8 i;
    s16 playerX, playerY;
    u8 currentCount;

    if (sWildBattleTriggered)
        return;

    // Don't spawn while Repel is active.
    if (VarGet(VAR_REPEL_STEP_COUNT) != 0)
        return;

    if (gPlayerAvatar.objectEventId >= OBJECT_EVENTS_COUNT || !gObjectEvents[gPlayerAvatar.objectEventId].active)
        return;

    currentCount = GetActiveOverworldWildMonCount();
    if (currentCount >= MAX_OVERWORLD_WILD_MONS)
        return;

    playerX = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x;
    playerY = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y;

    for (i = 0; i < 20; i++)
    {
        s16 dx = (Random() % 15) - 7;
        s16 dy = (Random() % 13) - 6;
        s16 tx = playerX + dx;
        s16 ty = playerY + dy;
        s16 distX = dx < 0 ? -dx : dx;
        s16 distY = dy < 0 ? -dy : dy;
        u8 behavior;
        u8 terrain;

        if (distX + distY < 3)
            continue;

        if (tx < MAP_OFFSET || ty < MAP_OFFSET)
            continue;
        if (tx >= gMapHeader.mapLayout->width + MAP_OFFSET || ty >= gMapHeader.mapLayout->height + MAP_OFFSET)
            continue;

        if (MapGridGetCollisionAt(tx, ty) != 0)
            continue;

        if (GetObjectEventIdByPosition(tx, ty, 3) != OBJECT_EVENTS_COUNT)
            continue;

        behavior = MapGridGetMetatileBehaviorAt(tx, ty);
        if (MetatileBehavior_IsLandWildEncounter(behavior))
            terrain = WILD_AREA_LAND;
        else if (MetatileBehavior_IsWaterWildEncounter(behavior))
            terrain = WILD_AREA_WATER;
        else
            continue;

        if (TrySpawnOverworldWildMonAt(tx, ty, terrain))
        {
            if (GetActiveOverworldWildMonCount() >= MAX_OVERWORLD_WILD_MONS)
                break;
        }
    }
}

void UpdateOverworldWildMons(void)
{
    u8 i;
    s16 playerX, playerY;
    s16 dx, dy, dist;
    u8 objId;

    if (sPostBattleInvulnerabilitySteps > 0)
        sPostBattleInvulnerabilitySteps--;

    if (sWildBattleTriggered)
        return;

    if (gPlayerAvatar.objectEventId >= OBJECT_EVENTS_COUNT || !gObjectEvents[gPlayerAvatar.objectEventId].active)
        return;

    playerX = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x;
    playerY = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y;

    for (i = 0; i < MAX_OVERWORLD_WILD_MONS; i++)
    {
        if (sOverworldWildMons[i].active)
        {
            objId = sOverworldWildMons[i].objEventId;
            if (objId >= OBJECT_EVENTS_COUNT || !gObjectEvents[objId].active || gObjectEvents[objId].localId != sOverworldWildMons[i].localId)
            {
                sOverworldWildMons[i].active = FALSE;
                continue;
            }

            dx = playerX - gObjectEvents[objId].currentCoords.x;
            dy = playerY - gObjectEvents[objId].currentCoords.y;
            dist = (dx < 0 ? -dx : dx) + (dy < 0 ? -dy : dy);
            if (dist > 14)
            {
                RemoveObjectEvent(&gObjectEvents[objId]);
                sOverworldWildMons[i].active = FALSE;
            }
        }
    }

    sStepSpawnCounter++;
    if (sStepSpawnCounter >= 2 || GetActiveOverworldWildMonCount() == 0)
    {
        sStepSpawnCounter = 0;
        TrySpawnOverworldWildMons();
    }
}

void ClearOverworldWildMons(void)
{
    u8 i;
    for (i = 0; i < MAX_OVERWORLD_WILD_MONS; i++)
    {
        if (sOverworldWildMons[i].active)
        {
            u8 objId = sOverworldWildMons[i].objEventId;
            if (objId < OBJECT_EVENTS_COUNT && gObjectEvents[objId].active && gObjectEvents[objId].localId == sOverworldWildMons[i].localId)
            {
                RemoveObjectEvent(&gObjectEvents[objId]);
            }
            sOverworldWildMons[i].active = FALSE;
        }
    }
    sWildBattleTriggered = FALSE;
    sStepSpawnCounter = 0;
    sRefreshFrameCounter = 0;
}
bool8 TriggerOverworldWildBattle(u8 objEventId)
{
    u8 i;
    u16 species = SPECIES_NONE;
    u8 level = 5;
    u8 slot = MAX_OVERWORLD_WILD_MONS;

    if (sWildBattleTriggered || sPostBattleInvulnerabilitySteps > 0)
        return FALSE;

    for (i = 0; i < MAX_OVERWORLD_WILD_MONS; i++)
    {
        if (sOverworldWildMons[i].active && sOverworldWildMons[i].objEventId == objEventId)
        {
            species = sOverworldWildMons[i].species;
            level = sOverworldWildMons[i].level;
            slot = i;
            break;
        }
    }

    if (slot == MAX_OVERWORLD_WILD_MONS || species == SPECIES_NONE)
        return FALSE;

    sWildBattleTriggered = TRUE;
    sOverworldWildMons[slot].active = FALSE;

    PlayCry_Normal(species, 0);
    CreateWildMon(species, level);
    RemoveObjectEvent(&gObjectEvents[objEventId]);
    BattleSetup_StartWildBattle();
    return TRUE;
}

bool8 TriggerOverworldWildBattleByObject(struct ObjectEvent *objectEvent)
{
    if (objectEvent == NULL)
        return FALSE;
    return TriggerOverworldWildBattle(GetObjectEventIdByPosition(objectEvent->currentCoords.x, objectEvent->currentCoords.y, objectEvent->currentElevation));
}

bool8 TryStartOverworldWildBattle(s16 x, s16 y)
{
    u8 objEventId;

    if (sWildBattleTriggered || sPostBattleInvulnerabilitySteps > 0)
        return FALSE;

    objEventId = GetObjectEventIdByPosition(x, y, 3);
    if (objEventId == OBJECT_EVENTS_COUNT)
        return FALSE;

    if (!IsOverworldWildMonObjEvent(gObjectEvents[objEventId].localId))
        return FALSE;

    return TriggerOverworldWildBattle(objEventId);
}

void OnReturnToFieldFromOverworldWildBattle(void)
{
    sWildBattleTriggered = FALSE;
    sPostBattleInvulnerabilitySteps = 4;
}


// Called every frame from CB2_Overworld.
// After OW_WILD_REFRESH_SECONDS seconds the current wild Pokémon are removed
// and a fresh batch is allowed to spawn, regardless of player movement.
void TickOverworldWildMonTimer(void)
{
#if OW_WILD_REFRESH_SECONDS > 0
    // Don't tick during a battle or while battle invulnerability is active.
    if (sWildBattleTriggered)
        return;

    // While Repel is active: keep the timer frozen and remove any visible wild Pokémon.
    if (VarGet(VAR_REPEL_STEP_COUNT) != 0)
    {
        u8 i;
        sRefreshFrameCounter = 0;
        for (i = 0; i < MAX_OVERWORLD_WILD_MONS; i++)
        {
            if (sOverworldWildMons[i].active)
            {
                u8 objId = sOverworldWildMons[i].objEventId;
                if (objId < OBJECT_EVENTS_COUNT && gObjectEvents[objId].active
                        && gObjectEvents[objId].localId == sOverworldWildMons[i].localId)
                    RemoveObjectEvent(&gObjectEvents[objId]);
                sOverworldWildMons[i].active = FALSE;
            }
        }
        return;
    }

    sRefreshFrameCounter++;

    // GBA runs at 60 fps → threshold = seconds × 60
    if (sRefreshFrameCounter >= (u16)(OW_WILD_REFRESH_SECONDS * 60))
    {
        sRefreshFrameCounter = 0;
        // Remove all active overworld wild Pokémon so TrySpawnOverworldWildMons
        // will repopulate them on the next step (or immediately below).
        {
            u8 i;
            for (i = 0; i < MAX_OVERWORLD_WILD_MONS; i++)
            {
                if (sOverworldWildMons[i].active)
                {
                    u8 objId = sOverworldWildMons[i].objEventId;
                    if (objId < OBJECT_EVENTS_COUNT && gObjectEvents[objId].active
                            && gObjectEvents[objId].localId == sOverworldWildMons[i].localId)
                        RemoveObjectEvent(&gObjectEvents[objId]);
                    sOverworldWildMons[i].active = FALSE;
                }
            }
        }
        // Immediately attempt to spawn a new batch.
        TrySpawnOverworldWildMons();
    }
#endif
}

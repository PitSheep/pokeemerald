#ifndef GUARD_OVERWORLD_WILD_MON_H
#define GUARD_OVERWORLD_WILD_MON_H

#define MAX_OVERWORLD_WILD_MONS 4

// Set to TRUE to disable standard invisible random wild encounters (only overworld visible encounters trigger battles)
#define OW_WILD_DISABLE_RANDOM_ENCOUNTERS TRUE

// After this many seconds the overworld wild Pokémon are cleared and a new batch spawns.
// Set to 0 to disable the timed refresh entirely.
#define OW_WILD_REFRESH_SECONDS 15

struct OverworldWildMon
{
    u8 objEventId;
    u8 localId;
    u16 species;
    u8 level;
    u8 terrain;
    s16 spawnX;
    s16 spawnY;
    bool8 active;
};

void ClearOverworldWildMons(void);
void TrySpawnOverworldWildMons(void);
void UpdateOverworldWildMons(void);
void TickOverworldWildMonTimer(void);
bool8 TryStartOverworldWildBattle(s16 x, s16 y);
bool8 TriggerOverworldWildBattle(u8 objEventId);
bool8 TriggerOverworldWildBattleByObject(struct ObjectEvent *objectEvent);
void OnReturnToFieldFromOverworldWildBattle(void);
bool8 IsOverworldWildMonObjEvent(u8 localId);
s8 GetOverworldWildMonIndexByLocalId(u8 localId);
u8 GetActiveOverworldWildMonCount(void);

#endif // GUARD_OVERWORLD_WILD_MON_H

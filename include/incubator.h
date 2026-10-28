#ifndef GUARD_INCUBATOR_H
#define GUARD_INCUBATOR_H

bool8 IsIncubatorOccupied(void);
void StoreSelectedPokemonInIncubator(void);
u16 TakePokemonFromIncubator(void);
bool8 IsIncubatorSlot2Occupied(void);
void StoreSelectedPokemonInIncubatorSlot2(void);
u16 TakePokemonFromIncubatorSlot2(void);
bool8 SendIncubatorMonToPC(void);
bool8 SendIncubatorMon2ToPC(void);
u8 CheckIncubatorCompatibility(void);
void ShowIncubatorMonsWindow(void);
void CloseIncubatorMonsWindow(void);
void ShowIncubatorSlot1Info(void);
void ShowIncubatorSlot2Info(void);
void CloseIncubatorSlotInfo(void);
void ShowIncubatorResultInfo(void);
bool8 IsIncubatorResultReady(void);
void CreateIncubatorResult(void);
u16 TakeIncubatorResult(void);
bool8 SendIncubatorResultToPC(void);

#endif // GUARD_INCUBATOR_H

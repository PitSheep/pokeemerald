#include "global.h"
#include "pokemon.h"
#include "daycare.h"
#include "incubator.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/maps.h"
#include "field_effect.h"
#include "international_string_util.h"
#include "item.h"
#include "main.h"
#include "random.h"
#include "constants/moves.h"
#include "overworld.h"
#include "pokedex.h"
#include "pokemon_summary_screen.h"
#include "menu.h"
#include "script_menu.h"
#include "sprite.h"
#include "text.h"
#include "window.h"
#include "mail.h"
#include "party_menu.h"
#include "pokemon_storage_system.h"
#include "string_util.h"
#include "constants/items.h"

#define INCUBATOR_SIGNATURE 0x494E4355

static void ClearIncubatorMail(struct DaycareMail *mail)
{
    CpuFill32(0, mail, sizeof(*mail));
}

static bool8 IsSlotOccupied(struct DaycareMon *incubatorMon, u32 *signature)
{
    return *signature == INCUBATOR_SIGNATURE
        && GetBoxMonData(&incubatorMon->mon, MON_DATA_SANITY_HAS_SPECIES);
}

static void StoreSelectedPokemonInSlot(struct DaycareMon *incubatorMon, u32 *signature)
{
    u8 monId = GetCursorSelectionMonId();
    struct Pokemon *mon = &gPlayerParty[monId];

    ClearIncubatorMail(&incubatorMon->mail);
    if (MonHasMail(mon))
    {
        u8 mailId;

        StringCopy(incubatorMon->mail.otName, gSaveBlock2Ptr->playerName);
        GetMonNickname2(mon, incubatorMon->mail.monName);
        StripExtCtrlCodes(incubatorMon->mail.monName);
        incubatorMon->mail.gameLanguage = GAME_LANGUAGE;
        incubatorMon->mail.monLanguage = GetMonData(mon, MON_DATA_LANGUAGE);
        mailId = GetMonData(mon, MON_DATA_MAIL);
        incubatorMon->mail.message = gSaveBlock1Ptr->mail[mailId];
        TakeMailFromMon(mon);
    }

    incubatorMon->mon = mon->box;
    BoxMonRestorePP(&incubatorMon->mon);
    incubatorMon->steps = 0;
    *signature = INCUBATOR_SIGNATURE;
    ZeroMonData(mon);
    CompactPartySlots();
    CalculatePlayerPartyCount();
}

static u16 TakePokemonFromSlot(struct DaycareMon *incubatorMon, u32 *signature)
{
    struct Pokemon mon;
    u16 species = GetBoxMonData(&incubatorMon->mon, MON_DATA_SPECIES);

    GetBoxMonNickname(&incubatorMon->mon, gStringVar1);
    BoxMonToMon(&incubatorMon->mon, &mon);
    if (incubatorMon->mail.message.itemId != ITEM_NONE)
    {
        GiveMailToMon(&mon, &incubatorMon->mail.message);
        ClearIncubatorMail(&incubatorMon->mail);
    }

    gPlayerParty[PARTY_SIZE - 1] = mon;
    ZeroBoxMonData(&incubatorMon->mon);
    ClearIncubatorMail(&incubatorMon->mail);
    incubatorMon->steps = 0;
    *signature = 0;
    CompactPartySlots();
    CalculatePlayerPartyCount();
    return species;
}

// Returns TRUE if the mon was stored in the first free PC box slot, FALSE if the PC is full.
static bool8 SendSlotToPC(struct DaycareMon *incubatorMon, u32 *signature)
{
    u8 boxNo = StorageGetCurrentBox();
    u8 startBox = boxNo;
    u8 boxPos;

    do
    {
        for (boxPos = 0; boxPos < IN_BOX_COUNT; boxPos++)
        {
            struct BoxPokemon *dest = GetBoxedMonPtr(boxNo, boxPos);

            if (GetBoxMonData(dest, MON_DATA_SPECIES) == SPECIES_NONE)
            {
                struct Pokemon mon;

                GetBoxMonNickname(&incubatorMon->mon, gStringVar1);
                StringCopy(gStringVar2, GetBoxNamePtr(boxNo));
                BoxMonToMon(&incubatorMon->mon, &mon);
                if (incubatorMon->mail.message.itemId != ITEM_NONE)
                    GiveMailToMon(&mon, &incubatorMon->mail.message);
                *dest = mon.box;
                ZeroBoxMonData(&incubatorMon->mon);
                ClearIncubatorMail(&incubatorMon->mail);
                incubatorMon->steps = 0;
                *signature = 0;
                return TRUE;
            }
        }
        boxNo = (boxNo + 1) % TOTAL_BOXES_COUNT;
    } while (boxNo != startBox);

    return FALSE;
}

bool8 SendIncubatorMonToPC(void)
{
    bool8 result = SendSlotToPC(&gSaveBlock1Ptr->incubatorMon, &gSaveBlock1Ptr->incubatorSignature);

    UpdateIncubatorObjectSprites();
    return result;
}

bool8 SendIncubatorMon2ToPC(void)
{
    bool8 result = SendSlotToPC(&gSaveBlock1Ptr->incubatorMon2, &gSaveBlock1Ptr->incubatorSignature2);

    UpdateIncubatorObjectSprites();
    return result;
}

#define INCUBATOR_OBJ_LOCAL_ID_FIRST 5 // Love Ball objects on the map: slot 1, slot 2, result

// Love Ball is used when the slot is empty or the species has no overworld sprite
static u16 GetIncubatorObjectGfx(struct BoxPokemon *boxMon, bool8 present)
{
    u16 species;
    u16 gfx;

    if (!present)
        return OBJ_EVENT_GFX_LOVE_BALL;

    species = GetBoxMonData(boxMon, MON_DATA_SPECIES);
    gfx = species + OBJ_EVENT_GFX_BULBASAUR - 1;
    if (species == SPECIES_NONE || gfx >= NUM_OBJ_EVENT_GFX || GetObjectEventGraphicsInfo(gfx) == NULL)
        return OBJ_EVENT_GFX_LOVE_BALL;
    return gfx;
}

void UpdateIncubatorObjectSprites(void)
{
    u16 gfx[3];
    u8 i;

    gfx[0] = GetIncubatorObjectGfx(&gSaveBlock1Ptr->incubatorMon.mon, IsIncubatorOccupied());
    gfx[1] = GetIncubatorObjectGfx(&gSaveBlock1Ptr->incubatorMon2.mon, IsIncubatorSlot2Occupied());
    gfx[2] = GetIncubatorObjectGfx(&gSaveBlock1Ptr->incubatorResult, IsIncubatorResultReady());

    VarSet(VAR_INCUBATOR_GFX_SLOT_1, gfx[0]);
    VarSet(VAR_INCUBATOR_GFX_SLOT_2, gfx[1]);
    VarSet(VAR_INCUBATOR_GFX_RESULT, gfx[2]);

    // Objects already on screen keep their old sprite, so refresh them too
    if (gSaveBlock1Ptr->location.mapGroup != MAP_GROUP(OLDALE_TOWN_HOUSE2)
     || gSaveBlock1Ptr->location.mapNum != MAP_NUM(OLDALE_TOWN_HOUSE2))
        return;

    for (i = 0; i < 3; i++)
    {
        u8 objectEventId;

        if (!TryGetObjectEventIdByLocalIdAndMap(INCUBATOR_OBJ_LOCAL_ID_FIRST + i, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectEventId)
         && gObjectEvents[objectEventId].graphicsId != gfx[i])
        {
            // Swapping graphics in place breaks the sprite (its tiles were sized for the old image), so respawn it
            RemoveObjectEvent(&gObjectEvents[objectEventId]);
            TrySpawnObjectEvent(INCUBATOR_OBJ_LOCAL_ID_FIRST + i, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
        }
    }
}

static bool8 IncubatorEggGroupsOverlap(u16 *eggGroups1, u16 *eggGroups2)
{
    u32 i, j;

    for (i = 0; i < EGG_GROUPS_PER_MON; i++)
    {
        for (j = 0; j < EGG_GROUPS_PER_MON; j++)
        {
            if (eggGroups1[i] == eggGroups2[j])
                return TRUE;
        }
    }

    return FALSE;
}

// Same rules as the Day Care compatibility score, applied to the two incubator mons.
static u8 GetIncubatorCompatibilityScore(void)
{
    u32 i;
    struct BoxPokemon *mons[2] = { &gSaveBlock1Ptr->incubatorMon.mon, &gSaveBlock1Ptr->incubatorMon2.mon };
    u16 eggGroups[2][EGG_GROUPS_PER_MON];
    u16 species[2];
    u32 trainerIds[2];
    u32 genders[2];

    for (i = 0; i < 2; i++)
    {
        u32 personality;

        species[i] = GetBoxMonData(mons[i], MON_DATA_SPECIES);
        trainerIds[i] = GetBoxMonData(mons[i], MON_DATA_OT_ID);
        personality = GetBoxMonData(mons[i], MON_DATA_PERSONALITY);
        genders[i] = GetGenderFromSpeciesAndPersonality(species[i], personality);
        eggGroups[i][0] = gSpeciesInfo[species[i]].eggGroups[0];
        eggGroups[i][1] = gSpeciesInfo[species[i]].eggGroups[1];
    }

    if (eggGroups[0][0] == EGG_GROUP_UNDISCOVERED || eggGroups[1][0] == EGG_GROUP_UNDISCOVERED)
        return PARENTS_INCOMPATIBLE;
    if (eggGroups[0][0] == EGG_GROUP_DITTO && eggGroups[1][0] == EGG_GROUP_DITTO)
        return PARENTS_INCOMPATIBLE;

    if (eggGroups[0][0] == EGG_GROUP_DITTO || eggGroups[1][0] == EGG_GROUP_DITTO)
    {
        if (trainerIds[0] == trainerIds[1])
            return PARENTS_LOW_COMPATIBILITY;

        return PARENTS_MED_COMPATIBILITY;
    }

    if (genders[0] == genders[1])
        return PARENTS_INCOMPATIBLE;
    if (genders[0] == MON_GENDERLESS || genders[1] == MON_GENDERLESS)
        return PARENTS_INCOMPATIBLE;
    if (!IncubatorEggGroupsOverlap(eggGroups[0], eggGroups[1]))
        return PARENTS_INCOMPATIBLE;

    if (species[0] == species[1])
        return trainerIds[0] == trainerIds[1] ? PARENTS_MED_COMPATIBILITY : PARENTS_MAX_COMPATIBILITY;

    return trainerIds[0] != trainerIds[1] ? PARENTS_MED_COMPATIBILITY : PARENTS_LOW_COMPATIBILITY;
}

// VAR_RESULT: 0 = an incubator slot is empty, 1 = incompatible, 2 = compatible
u8 CheckIncubatorCompatibility(void)
{
    if (!IsIncubatorOccupied() || !IsIncubatorSlot2Occupied())
        return 0;
    if (GetIncubatorCompatibilityScore() == PARENTS_INCOMPATIBLE)
        return 1;
    return 2;
}

#define INCUBATOR_SLOT_COUNT 2

static EWRAM_DATA u8 sIncubatorPicWindowIds[INCUBATOR_SLOT_COUNT] = {0};
static EWRAM_DATA u8 sIncubatorNameWindowIds[INCUBATOR_SLOT_COUNT] = {0};
static EWRAM_DATA u8 sIncubatorSpriteIds[INCUBATOR_SLOT_COUNT] = {0};

static const u8 sText_IncubatorEmptySlot[] = _("---");

static void ShowIncubatorSlotPic(u8 slot, struct BoxPokemon *boxMon, u8 tileX)
{
    // The pic frame is 8x8 tiles and the name frame sits right under it
    static const u16 picBaseBlocks[INCUBATOR_SLOT_COUNT] = {100, 170};
    static const u16 nameBaseBlocks[INCUBATOR_SLOT_COUNT] = {240, 256};
    const u8 tileY = 0;
    u16 species = GetBoxMonData(boxMon, MON_DATA_SPECIES);
    u8 name[POKEMON_NAME_LENGTH + 1];
    const u8 *text = sText_IncubatorEmptySlot;
    u8 x;
    struct WindowTemplate picTemplate = CreateWindowTemplate(0, tileX + 1, tileY + 1, 8, 8, 15, picBaseBlocks[slot]);
    struct WindowTemplate nameTemplate = CreateWindowTemplate(0, tileX + 1, tileY + 11, 8, 2, 15, nameBaseBlocks[slot]);

    sIncubatorSpriteIds[slot] = SPRITE_NONE;
    sIncubatorPicWindowIds[slot] = AddWindow(&picTemplate);
    PutWindowTilemap(sIncubatorPicWindowIds[slot]);
    SetStandardWindowBorderStyle(sIncubatorPicWindowIds[slot], TRUE);

    sIncubatorNameWindowIds[slot] = AddWindow(&nameTemplate);
    // The border style clears the window, so it must be drawn before the text
    SetStandardWindowBorderStyle(sIncubatorNameWindowIds[slot], FALSE);
    if (species != SPECIES_NONE)
    {
        GetSpeciesName(name, species);
        text = name;
        sIncubatorSpriteIds[slot] = CreateMonSprite_PicBox(species, tileX * 8 + 40, tileY * 8 + 40, 0);
        gSprites[sIncubatorSpriteIds[slot]].callback = SpriteCallbackDummy;
        gSprites[sIncubatorSpriteIds[slot]].oam.priority = 0;
    }
    x = GetStringCenterAlignXOffset(FONT_NORMAL, text, 64);
    AddTextPrinterParameterized(sIncubatorNameWindowIds[slot], FONT_NORMAL, text, x, 1, 0, NULL);
    CopyWindowToVram(sIncubatorNameWindowIds[slot], COPYWIN_FULL);
}

static void CloseIncubatorSlotPic(u8 slot)
{
    if (sIncubatorSpriteIds[slot] != SPRITE_NONE)
        FreeResourcesAndDestroySprite(&gSprites[sIncubatorSpriteIds[slot]], sIncubatorSpriteIds[slot]);
    sIncubatorSpriteIds[slot] = SPRITE_NONE;
    ClearToTransparentAndRemoveWindow(sIncubatorPicWindowIds[slot]);
    ClearToTransparentAndRemoveWindow(sIncubatorNameWindowIds[slot]);
}

static EWRAM_DATA bool8 sIncubatorInfoOpen = FALSE;
static EWRAM_DATA u8 sIncubatorInfoPicWindowId = 0;
static EWRAM_DATA u8 sIncubatorInfoWindowId = 0;
static EWRAM_DATA u8 sIncubatorInfoSpriteId = 0;

static const u8 sText_IncubatorNoItem[] = _("Item: ---");
static const u8 sText_IncubatorItemPrefix[] = _("Item: ");

static void ShowIncubatorSlotInfo(struct BoxPokemon *boxMon, bool8 isResult)
{
    u8 buffer[ITEM_NAME_LENGTH + 10];
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u16 species = GetBoxMonData(boxMon, MON_DATA_SPECIES);
    u16 item = GetBoxMonData(boxMon, MON_DATA_HELD_ITEM);
    u8 nature = GetNatureFromPersonality(GetBoxMonData(boxMon, MON_DATA_PERSONALITY));
    struct WindowTemplate picTemplate = CreateWindowTemplate(0, 1, 1, 8, 8, 15, 100);
    struct WindowTemplate infoTemplate = CreateWindowTemplate(0, 11, 1, 17, 6, 15, 170);

    if (sIncubatorInfoOpen || species == SPECIES_NONE)
        return;

    sIncubatorInfoOpen = TRUE;
    sIncubatorInfoPicWindowId = AddWindow(&picTemplate);
    PutWindowTilemap(sIncubatorInfoPicWindowId);
    SetStandardWindowBorderStyle(sIncubatorInfoPicWindowId, TRUE);
    sIncubatorInfoSpriteId = CreateMonSprite_PicBox(species, 40, 40, 0);
    gSprites[sIncubatorInfoSpriteId].callback = SpriteCallbackDummy;
    gSprites[sIncubatorInfoSpriteId].oam.priority = 0;

    sIncubatorInfoWindowId = AddWindow(&infoTemplate);
    SetStandardWindowBorderStyle(sIncubatorInfoWindowId, FALSE);
    if (isResult)
    {
        GetSpeciesName(nickname, species);
        StringCopy(gStringVar1, nickname);
    }
    else
    {
        GetBoxMonNickname(boxMon, nickname);
    }
    AddTextPrinterParameterized(sIncubatorInfoWindowId, FONT_NORMAL, nickname, 4, 1, 0, NULL);
    AddTextPrinterParameterized(sIncubatorInfoWindowId, FONT_NORMAL, gNatureNamePointers[nature], 4, 17, 0, NULL);
    if (isResult)
    {
        // The hatched mon has no held item to show
    }
    else if (item == ITEM_NONE)
    {
        AddTextPrinterParameterized(sIncubatorInfoWindowId, FONT_NORMAL, sText_IncubatorNoItem, 4, 33, 0, NULL);
    }
    else
    {
        u8 *end = StringCopy(buffer, sText_IncubatorItemPrefix);

        CopyItemName(item, end);
        AddTextPrinterParameterized(sIncubatorInfoWindowId, FONT_NORMAL, buffer, 4, 33, 0, NULL);
    }
    CopyWindowToVram(sIncubatorInfoWindowId, COPYWIN_FULL);
    ScheduleBgCopyTilemapToVram(0);
}

void ShowIncubatorSlot1Info(void)
{
    ShowIncubatorSlotInfo(&gSaveBlock1Ptr->incubatorMon.mon, FALSE);
}

void ShowIncubatorSlot2Info(void)
{
    ShowIncubatorSlotInfo(&gSaveBlock1Ptr->incubatorMon2.mon, FALSE);
}

// Shows sprite, species name (also copied to STR_VAR_1) and nature of the hatched mon
void ShowIncubatorResultInfo(void)
{
    ShowIncubatorSlotInfo(&gSaveBlock1Ptr->incubatorResult, TRUE);
}

void CloseIncubatorSlotInfo(void)
{
    if (!sIncubatorInfoOpen)
        return;

    sIncubatorInfoOpen = FALSE;
    FreeResourcesAndDestroySprite(&gSprites[sIncubatorInfoSpriteId], sIncubatorInfoSpriteId);
    ClearToTransparentAndRemoveWindow(sIncubatorInfoPicWindowId);
    ClearToTransparentAndRemoveWindow(sIncubatorInfoWindowId);
}

void ShowIncubatorMonsWindow(void)
{
    ShowIncubatorSlotPic(0, &gSaveBlock1Ptr->incubatorMon.mon, 9);
    ShowIncubatorSlotPic(1, &gSaveBlock1Ptr->incubatorMon2.mon, 19);
    ScheduleBgCopyTilemapToVram(0);
}

void CloseIncubatorMonsWindow(void)
{
    CloseIncubatorSlotPic(0);
    CloseIncubatorSlotPic(1);
}

// Egg generation: same rules as the Day Care (src/daycare.c), reimplemented here so that
// the incubator works only on its own save data and never touches the Day Care.
#define INCUBATOR_EGG_MOVES_SPECIES_OFFSET 20000
#define INCUBATOR_EGG_MOVES_TERMINATOR     0xFFFF
#define INCUBATOR_EGG_GENDER_MALE          0x8000

extern const u16 gEggMoves[];
extern const struct Evolution gEvolutionTable[][EVOS_PER_MON];

static EWRAM_DATA u16 sIncubatorLevelUpMoves[EGG_LVL_UP_MOVES_ARRAY_COUNT] = {0};
static EWRAM_DATA u16 sIncubatorFatherMoves[MAX_MON_MOVES] = {0};
static EWRAM_DATA u16 sIncubatorMotherMoves[MAX_MON_MOVES] = {0};
static EWRAM_DATA u16 sIncubatorFinalMoves[MAX_MON_MOVES] = {0};
static EWRAM_DATA u16 sIncubatorEggMoves[EGG_MOVES_ARRAY_COUNT] = {0};

static u16 GetIncubatorEggSpecies(u16 species)
{
    int i, j, k;
    bool8 found;

    for (i = 0; i < EVOS_PER_MON; i++)
    {
        found = FALSE;
        for (j = 1; j < NUM_SPECIES; j++)
        {
            for (k = 0; k < EVOS_PER_MON; k++)
            {
                if (gEvolutionTable[j][k].targetSpecies == species)
                {
                    species = j;
                    found = TRUE;
                    break;
                }
            }

            if (found)
                break;
        }

        if (j == NUM_SPECIES)
            break;
    }

    return species;
}

static s32 GetIncubatorParentToInheritNature(struct BoxPokemon **mons)
{
    s32 i;
    s32 dittoCount;
    s32 parent = -1;

    for (i = 0; i < 2; i++)
    {
        if (GetBoxMonGender(mons[i]) == MON_FEMALE)
            parent = i;
    }

    for (dittoCount = 0, i = 0; i < 2; i++)
    {
        if (GetBoxMonData(mons[i], MON_DATA_SPECIES) == SPECIES_DITTO)
            dittoCount++, parent = i;
    }

    if (dittoCount == 2)
    {
        if (Random() >= USHRT_MAX / 2)
            parent = 0;
        else
            parent = 1;
    }

    if (parent < 0
        || GetBoxMonData(mons[parent], MON_DATA_HELD_ITEM) != ITEM_EVERSTONE
        || Random() >= USHRT_MAX)
    {
        return -1;
    }

    return parent;
}

static u32 GetIncubatorOffspringPersonality(struct BoxPokemon **mons)
{
    s32 natureTries = 0;
    s32 parent;
    u32 personality;

    SeedRng2(gMain.vblankCounter2);
    parent = GetIncubatorParentToInheritNature(mons);

    if (parent < 0)
        return (Random2() << 16) | ((Random() % 0xfffe) + 1);

    {
        u8 wantedNature = GetNatureFromPersonality(GetBoxMonData(mons[parent], MON_DATA_PERSONALITY));

        do
        {
            personality = (Random2() << 16) | (Random());
            if (wantedNature == GetNatureFromPersonality(personality) && personality != 0)
                break;

            natureTries++;
        } while (natureTries <= 2400);
    }

    return personality;
}

static void RemoveIncubatorIVIndexFromList(u8 *ivs, u8 selectedIv)
{
    s32 i, j;
    u8 temp[NUM_STATS];

    ivs[selectedIv] = 0xFF;
    for (i = 0; i < NUM_STATS; i++)
        temp[i] = ivs[i];

    j = 0;
    for (i = 0; i < NUM_STATS; i++)
    {
        if (temp[i] != 0xFF)
            ivs[j++] = temp[i];
    }
}

static void InheritIncubatorIVs(struct Pokemon *egg, struct BoxPokemon **mons)
{
    u8 i;
    u8 selectedIvs[INHERITED_IV_COUNT];
    u8 availableIVs[NUM_STATS];
    u8 whichParents[INHERITED_IV_COUNT];
    u8 iv;

    for (i = 0; i < NUM_STATS; i++)
        availableIVs[i] = i;

    // Same selection as the Day Care, including its known quirk (see InheritIVs in daycare.c)
    for (i = 0; i < INHERITED_IV_COUNT; i++)
    {
        #ifndef BUGFIX
        selectedIvs[i] = availableIVs[Random() % (NUM_STATS - i)];
        RemoveIncubatorIVIndexFromList(availableIVs, i);
        #else
        u8 index = Random() % (NUM_STATS - i);
        selectedIvs[i] = availableIVs[index];
        RemoveIncubatorIVIndexFromList(availableIVs, index);
        #endif
    }

    for (i = 0; i < INHERITED_IV_COUNT; i++)
        whichParents[i] = Random() % 2;

    for (i = 0; i < INHERITED_IV_COUNT; i++)
    {
        switch (selectedIvs[i])
        {
        case 0:
            iv = GetBoxMonData(mons[whichParents[i]], MON_DATA_HP_IV);
            SetMonData(egg, MON_DATA_HP_IV, &iv);
            break;
        case 1:
            iv = GetBoxMonData(mons[whichParents[i]], MON_DATA_ATK_IV);
            SetMonData(egg, MON_DATA_ATK_IV, &iv);
            break;
        case 2:
            iv = GetBoxMonData(mons[whichParents[i]], MON_DATA_DEF_IV);
            SetMonData(egg, MON_DATA_DEF_IV, &iv);
            break;
        case 3:
            iv = GetBoxMonData(mons[whichParents[i]], MON_DATA_SPEED_IV);
            SetMonData(egg, MON_DATA_SPEED_IV, &iv);
            break;
        case 4:
            iv = GetBoxMonData(mons[whichParents[i]], MON_DATA_SPATK_IV);
            SetMonData(egg, MON_DATA_SPATK_IV, &iv);
            break;
        case 5:
            iv = GetBoxMonData(mons[whichParents[i]], MON_DATA_SPDEF_IV);
            SetMonData(egg, MON_DATA_SPDEF_IV, &iv);
            break;
        }
    }
}

static u8 GetIncubatorEggMoves(struct Pokemon *pokemon, u16 *eggMoves)
{
    u16 eggMoveIdx = 0;
    u16 numEggMoves = 0;
    u16 species = GetMonData(pokemon, MON_DATA_SPECIES);
    u16 i;

    for (i = 0; gEggMoves[i] != INCUBATOR_EGG_MOVES_TERMINATOR; i++)
    {
        if (gEggMoves[i] == species + INCUBATOR_EGG_MOVES_SPECIES_OFFSET)
        {
            eggMoveIdx = i + 1;
            break;
        }
    }

    for (i = 0; i < EGG_MOVES_ARRAY_COUNT; i++)
    {
        if (gEggMoves[eggMoveIdx + i] > INCUBATOR_EGG_MOVES_SPECIES_OFFSET)
            break;

        eggMoves[i] = gEggMoves[eggMoveIdx + i];
        numEggMoves++;
    }

    return numEggMoves;
}

static void BuildIncubatorEggMoveset(struct Pokemon *egg, struct BoxPokemon *father, struct BoxPokemon *mother)
{
    u16 numSharedParentMoves = 0;
    u32 numLevelUpMoves;
    u16 numEggMoves;
    u16 i, j;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        sIncubatorMotherMoves[i] = MOVE_NONE;
        sIncubatorFatherMoves[i] = MOVE_NONE;
        sIncubatorFinalMoves[i] = MOVE_NONE;
    }
    for (i = 0; i < EGG_MOVES_ARRAY_COUNT; i++)
        sIncubatorEggMoves[i] = MOVE_NONE;
    for (i = 0; i < EGG_LVL_UP_MOVES_ARRAY_COUNT; i++)
        sIncubatorLevelUpMoves[i] = MOVE_NONE;

    numLevelUpMoves = GetLevelUpMovesBySpecies(GetMonData(egg, MON_DATA_SPECIES), sIncubatorLevelUpMoves);
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        sIncubatorFatherMoves[i] = GetBoxMonData(father, MON_DATA_MOVE1 + i);
        sIncubatorMotherMoves[i] = GetBoxMonData(mother, MON_DATA_MOVE1 + i);
    }

    numEggMoves = GetIncubatorEggMoves(egg, sIncubatorEggMoves);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (sIncubatorFatherMoves[i] == MOVE_NONE)
            break;
        for (j = 0; j < numEggMoves; j++)
        {
            if (sIncubatorFatherMoves[i] == sIncubatorEggMoves[j])
            {
                if (GiveMoveToMon(egg, sIncubatorFatherMoves[i]) == MON_HAS_MAX_MOVES)
                    DeleteFirstMoveAndGiveMoveToMon(egg, sIncubatorFatherMoves[i]);
                break;
            }
        }
    }
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (sIncubatorFatherMoves[i] == MOVE_NONE)
            continue;
        for (j = 0; j < NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES; j++)
        {
            if (sIncubatorFatherMoves[i] == ItemIdToBattleMoveId(ITEM_TM01_FOCUS_PUNCH + j) && CanMonLearnTMHM(egg, j))
            {
                if (GiveMoveToMon(egg, sIncubatorFatherMoves[i]) == MON_HAS_MAX_MOVES)
                    DeleteFirstMoveAndGiveMoveToMon(egg, sIncubatorFatherMoves[i]);
            }
        }
    }
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (sIncubatorFatherMoves[i] == MOVE_NONE)
            break;
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            if (sIncubatorFatherMoves[i] == sIncubatorMotherMoves[j] && sIncubatorFatherMoves[i] != MOVE_NONE)
                sIncubatorFinalMoves[numSharedParentMoves++] = sIncubatorFatherMoves[i];
        }
    }

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (sIncubatorFinalMoves[i] == MOVE_NONE)
            break;
        for (j = 0; j < numLevelUpMoves; j++)
        {
            if (sIncubatorLevelUpMoves[j] != MOVE_NONE && sIncubatorFinalMoves[i] == sIncubatorLevelUpMoves[j])
            {
                if (GiveMoveToMon(egg, sIncubatorFinalMoves[i]) == MON_HAS_MAX_MOVES)
                    DeleteFirstMoveAndGiveMoveToMon(egg, sIncubatorFinalMoves[i]);
                break;
            }
        }
    }
}

static u16 DetermineIncubatorEggSpeciesAndParentSlots(struct BoxPokemon **mons, u32 offspringPersonality, u8 *parentSlots)
{
    u16 i;
    u16 species[2];
    u16 eggSpecies;

    for (i = 0; i < 2; i++)
    {
        species[i] = GetBoxMonData(mons[i], MON_DATA_SPECIES);
        if (species[i] == SPECIES_DITTO)
        {
            parentSlots[0] = i ^ 1;
            parentSlots[1] = i;
        }
        else if (GetBoxMonGender(mons[i]) == MON_FEMALE)
        {
            parentSlots[0] = i;
            parentSlots[1] = i ^ 1;
        }
    }

    eggSpecies = GetIncubatorEggSpecies(species[parentSlots[0]]);
    if (eggSpecies == SPECIES_NIDORAN_F && (offspringPersonality & INCUBATOR_EGG_GENDER_MALE))
        eggSpecies = SPECIES_NIDORAN_M;
    if (eggSpecies == SPECIES_ILLUMISE && (offspringPersonality & INCUBATOR_EGG_GENDER_MALE))
        eggSpecies = SPECIES_VOLBEAT;

    if (species[parentSlots[1]] == SPECIES_DITTO && GetBoxMonGender(mons[parentSlots[0]]) != MON_FEMALE)
    {
        u8 ditto = parentSlots[1];

        parentSlots[1] = parentSlots[0];
        parentSlots[0] = ditto;
    }

    return eggSpecies;
}

static void AlterIncubatorEggSpeciesWithIncense(u16 *species, struct BoxPokemon **mons)
{
    u16 motherItem, fatherItem;

    if (*species == SPECIES_WYNAUT || *species == SPECIES_AZURILL)
    {
        motherItem = GetBoxMonData(mons[0], MON_DATA_HELD_ITEM);
        fatherItem = GetBoxMonData(mons[1], MON_DATA_HELD_ITEM);
        if (*species == SPECIES_WYNAUT && motherItem != ITEM_LAX_INCENSE && fatherItem != ITEM_LAX_INCENSE)
            *species = SPECIES_WOBBUFFET;
        if (*species == SPECIES_AZURILL && motherItem != ITEM_SEA_INCENSE && fatherItem != ITEM_SEA_INCENSE)
            *species = SPECIES_MARILL;
    }
}

static void GiveIncubatorVoltTackleIfLightBall(struct Pokemon *mon, struct BoxPokemon **mons)
{
    u32 motherItem = GetBoxMonData(mons[0], MON_DATA_HELD_ITEM);
    u32 fatherItem = GetBoxMonData(mons[1], MON_DATA_HELD_ITEM);

    if (motherItem == ITEM_LIGHT_BALL || fatherItem == ITEM_LIGHT_BALL)
    {
        if (GiveMoveToMon(mon, MOVE_VOLT_TACKLE) == MON_HAS_MAX_MOVES)
            DeleteFirstMoveAndGiveMoveToMon(mon, MOVE_VOLT_TACKLE);
    }
}

bool8 IsIncubatorResultReady(void)
{
    return gSaveBlock1Ptr->incubatorResultSignature == INCUBATOR_SIGNATURE
        && GetBoxMonData(&gSaveBlock1Ptr->incubatorResult, MON_DATA_SANITY_HAS_SPECIES);
}

// Turns a Day Care style egg into the hatched mon, following the same steps as egg_hatch.c
static void HatchIncubatorEgg(struct Pokemon *egg, struct Pokemon *hatched)
{
    u16 species = GetMonData(egg, MON_DATA_SPECIES);
    u32 personality = GetMonData(egg, MON_DATA_PERSONALITY);
    u32 pokerus = GetMonData(egg, MON_DATA_POKERUS);
    u8 gameMet = GetMonData(egg, MON_DATA_MET_GAME);
    u8 markings = GetMonData(egg, MON_DATA_MARKINGS);
    u8 fatefulEncounter = GetMonData(egg, MON_DATA_MODERN_FATEFUL_ENCOUNTER);
    u16 moves[MAX_MON_MOVES];
    u32 ivs[NUM_STATS];
    u8 name[POKEMON_NAME_LENGTH + 1];
    u8 i, language, friendship, metLocation;
    u16 ball = ITEM_POKE_BALL;
    u16 metLevel = 0;
    u8 isEgg = FALSE;

    for (i = 0; i < MAX_MON_MOVES; i++)
        moves[i] = GetMonData(egg, MON_DATA_MOVE1 + i);
    for (i = 0; i < NUM_STATS; i++)
        ivs[i] = GetMonData(egg, MON_DATA_HP_IV + i);

    CreateMon(hatched, species, EGG_HATCH_LEVEL, USE_RANDOM_IVS, TRUE, personality, OT_ID_PLAYER_ID, 0);
    for (i = 0; i < MAX_MON_MOVES; i++)
        SetMonData(hatched, MON_DATA_MOVE1 + i, &moves[i]);
    for (i = 0; i < NUM_STATS; i++)
        SetMonData(hatched, MON_DATA_HP_IV + i, &ivs[i]);

    language = GAME_LANGUAGE;
    SetMonData(hatched, MON_DATA_LANGUAGE, &language);
    SetMonData(hatched, MON_DATA_MET_GAME, &gameMet);
    SetMonData(hatched, MON_DATA_MARKINGS, &markings);
    friendship = 120;
    SetMonData(hatched, MON_DATA_FRIENDSHIP, &friendship);
    SetMonData(hatched, MON_DATA_POKERUS, &pokerus);
    SetMonData(hatched, MON_DATA_MODERN_FATEFUL_ENCOUNTER, &fatefulEncounter);
    SetMonData(hatched, MON_DATA_IS_EGG, &isEgg);

    GetSpeciesName(name, species);
    SetMonData(hatched, MON_DATA_NICKNAME, name);
    SetMonData(hatched, MON_DATA_POKEBALL, &ball);
    // A met level of 0 is interpreted on the summary screen as "hatched at"
    SetMonData(hatched, MON_DATA_MET_LEVEL, &metLevel);
    metLocation = GetCurrentRegionMapSectionId();
    SetMonData(hatched, MON_DATA_MET_LOCATION, &metLocation);
    MonRestorePP(hatched);
    CalculateMonStats(hatched);

    species = SpeciesToNationalPokedexNum(species);
    GetSetPokedexFlag(species, FLAG_SET_SEEN);
    GetSetPokedexFlag(species, FLAG_SET_CAUGHT);
}

// Generates the egg with the Day Care rules working only on the incubator mons, then hatches it.
void CreateIncubatorResult(void)
{
    struct Pokemon egg;
    struct Pokemon hatched;
    struct BoxPokemon *mons[2] = { &gSaveBlock1Ptr->incubatorMon.mon, &gSaveBlock1Ptr->incubatorMon2.mon };
    u8 parentSlots[2];
    u32 offspringPersonality;
    u16 species;

    if (IsIncubatorResultReady())
        return;

    offspringPersonality = GetIncubatorOffspringPersonality(mons);
    species = DetermineIncubatorEggSpeciesAndParentSlots(mons, offspringPersonality, parentSlots);
    AlterIncubatorEggSpeciesWithIncense(&species, mons);
    CreateMon(&egg, species, EGG_HATCH_LEVEL, USE_RANDOM_IVS, TRUE, offspringPersonality, OT_ID_PLAYER_ID, 0);
    InheritIncubatorIVs(&egg, mons);
    BuildIncubatorEggMoveset(&egg, mons[parentSlots[1]], mons[parentSlots[0]]);
    if (species == SPECIES_PICHU)
        GiveIncubatorVoltTackleIfLightBall(&egg, mons);

    HatchIncubatorEgg(&egg, &hatched);
    gSaveBlock1Ptr->incubatorResult = hatched.box;
    gSaveBlock1Ptr->incubatorResultSignature = INCUBATOR_SIGNATURE;
    UpdateIncubatorObjectSprites();
}

static void ClearIncubatorResult(void)
{
    ZeroBoxMonData(&gSaveBlock1Ptr->incubatorResult);
    gSaveBlock1Ptr->incubatorResultSignature = 0;
}

u16 TakeIncubatorResult(void)
{
    struct Pokemon mon;
    u16 species = GetBoxMonData(&gSaveBlock1Ptr->incubatorResult, MON_DATA_SPECIES);

    GetBoxMonNickname(&gSaveBlock1Ptr->incubatorResult, gStringVar1);
    BoxMonToMon(&gSaveBlock1Ptr->incubatorResult, &mon);
    gPlayerParty[PARTY_SIZE - 1] = mon;
    ClearIncubatorResult();
    CompactPartySlots();
    CalculatePlayerPartyCount();
    UpdateIncubatorObjectSprites();
    return species;
}

bool8 SendIncubatorResultToPC(void)
{
    u8 boxNo = StorageGetCurrentBox();
    u8 startBox = boxNo;
    u8 boxPos;

    do
    {
        for (boxPos = 0; boxPos < IN_BOX_COUNT; boxPos++)
        {
            struct BoxPokemon *dest = GetBoxedMonPtr(boxNo, boxPos);

            if (GetBoxMonData(dest, MON_DATA_SPECIES) == SPECIES_NONE)
            {
                GetBoxMonNickname(&gSaveBlock1Ptr->incubatorResult, gStringVar1);
                StringCopy(gStringVar2, GetBoxNamePtr(boxNo));
                *dest = gSaveBlock1Ptr->incubatorResult;
                ClearIncubatorResult();
                UpdateIncubatorObjectSprites();
                return TRUE;
            }
        }
        boxNo = (boxNo + 1) % TOTAL_BOXES_COUNT;
    } while (boxNo != startBox);

    return FALSE;
}

bool8 IsIncubatorOccupied(void)
{
    return IsSlotOccupied(&gSaveBlock1Ptr->incubatorMon, &gSaveBlock1Ptr->incubatorSignature);
}

void StoreSelectedPokemonInIncubator(void)
{
    StoreSelectedPokemonInSlot(&gSaveBlock1Ptr->incubatorMon, &gSaveBlock1Ptr->incubatorSignature);
    UpdateIncubatorObjectSprites();
}

u16 TakePokemonFromIncubator(void)
{
    u16 species = TakePokemonFromSlot(&gSaveBlock1Ptr->incubatorMon, &gSaveBlock1Ptr->incubatorSignature);

    UpdateIncubatorObjectSprites();
    return species;
}

bool8 IsIncubatorSlot2Occupied(void)
{
    return IsSlotOccupied(&gSaveBlock1Ptr->incubatorMon2, &gSaveBlock1Ptr->incubatorSignature2);
}

void StoreSelectedPokemonInIncubatorSlot2(void)
{
    StoreSelectedPokemonInSlot(&gSaveBlock1Ptr->incubatorMon2, &gSaveBlock1Ptr->incubatorSignature2);
    UpdateIncubatorObjectSprites();
}

u16 TakePokemonFromIncubatorSlot2(void)
{
    u16 species = TakePokemonFromSlot(&gSaveBlock1Ptr->incubatorMon2, &gSaveBlock1Ptr->incubatorSignature2);

    UpdateIncubatorObjectSprites();
    return species;
}

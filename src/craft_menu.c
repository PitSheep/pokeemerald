#include "global.h"
#include "bg.h"
#include "battle_pyramid.h"
#include "craft_menu.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_object_lock.h"
#include "event_scripts.h"
#include "fieldmap.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "field_specials.h"
#include "field_weather.h"
#include "field_screen_effect.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item_menu.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "start_menu.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "constants/items.h"
#include "constants/rgb.h"
#include "constants/songs.h"

// Credits!!
//--------------
// TheSylphIsIn: comparing chosen items against an array
// Lunos: ChooseItem
// Ketsuban: Debug Menu / basics of windows
// MrGriffin: example-screen
// Ghoulslash: item icons
// Grunt-Lucas: Inspiration & Sample-UI
// & of course the good people of the PRET and Team Aqua discords! If you help out there, thank you!!!
//--------------------------------------------------------------------------------------------------------------
// This is based off start_menu.c, so the code flow is a bit chaotic. There's a user input portion,
// a few functions for the craft table logic, then a pinball game for the dialogue


// Ingredients (ITEM_1234) must be arranged with Smallest -> Largest ItemId.
// You can edit this for specific-order crafting à la minecraft if you comment out
// the "OrganizeCraftItems" call down "FindCraftProduct".
// Otherwise just follow the template & examples below to add more recipes!
static const u16 Craft_Recipes[][6] = {
//  {ITEM_1,        ITEM_2,            ITEM_3,            ITEM_4,             ||||  CRAFT_PRODUCT,          QUANTITY},    
    {0,             0,                 ITEM_POTION,       ITEM_PECHA_BERRY,         ITEM_ANTIDOTE,         3},
    {0,             ITEM_REPEL,        ITEM_REPEL,        ITEM_REPEL,               ITEM_SUPER_REPEL,      2},
    {0,             ITEM_SUPER_REPEL,  ITEM_SUPER_REPEL,  ITEM_SUPER_REPEL,         ITEM_MAX_REPEL,        2},
    {0,             0,                 ITEM_POKE_BALL,    ITEM_MAX_REPEL,           ITEM_SMOKE_BALL,       1},
    {0,             0,                 ITEM_ORAN_BERRY,   ITEM_ORAN_BERRY,          ITEM_BERRY_JUICE,      1}
};

// Here's some flags in case you want to lock away an item due to plot progression,
// If you want less than three just use this handy dandy NO_FLAG
#define NO_FLAG 0x86F // This is the Littleroot Flag, it should always be true unless you're doing something cool

static const u16 Craft_Flags[][4] = {
    //{CRAFT PRODUCT, ||||  FLAG 1,                        FLAG 2,                         FLAG 3},
    {ITEM_BERRY_JUICE,      FLAG_VISITED_PETALBURG_CITY,   FLAG_ITEM_ROUTE_102_POTION,     NO_FLAG}
};

#undef NO_FLAG // kthxbye


//--------------------------------------------------------------------------------------------------------------
// The rest of the code is below!
// Modify it if you like, and if you make improvements please
// submit a pull request so I can add it. Sharing is caring :D
// Also please do a PR if you find bugs or something that doesn't look
// intentional.
// Thx!
// - redsquidz くコ:彡

// Menu actions
enum CraftMenuActions {
    MENU_ACTION_SWAP,
    MENU_ACTION_BAG,
    MENU_ACTION_READY, //switch this out for GARBAGE / TOSS depending on if indoors
    MENU_ACTION_CANCEL,
};

// Table actions 
enum TableActions {
    TABLE_ACTION_BLANK,
    TABLE_ACTION_ITEM,
};

// sCurrentCraftTableItems[][] slot names
enum CraftTableSlots {
    CRAFT_TABLE_ITEM,
    CRAFT_TABLE_ACTION,
};

// Input handling
enum CraftState {
    STATE_TABLE_INPUT,
    STATE_OPTIONS_INPUT,
    STATE_CONFIRM_READY,
    STATE_CONFIRM_PACKUP,
};

// Confirm Messages
enum CraftConfirmMessages{
    CRAFT_PACKUP_CONFIRM,
    CRAFT_READY_CONFIRM
};

// IWRAM common
bool8 (*gMenuCallback)(void);

// EWRAM
EWRAM_DATA static u8 sCraftTableWindowId = 0;
EWRAM_DATA static u8 sCraftInfoWindowId = 0;
EWRAM_DATA static u8 sCraftOptionsWindowId = 0;
EWRAM_DATA static u8 sCraftSousChefsWindowId = 0;

EWRAM_DATA u16 sCurrentCraftTableItems[4][2] = {0}; //craft table items, actions
EWRAM_DATA u8 sCraftMenuCursorPos = 0;
EWRAM_DATA static u8 sInitCraftMenuData[1] = {0};
EWRAM_DATA static u8 sCraftState = 0;
EWRAM_DATA static u32 sPauseCounter = 0;
EWRAM_DATA static u8 (*sCraftDialogCallback)(void) = NULL;
EWRAM_DATA static u8 CraftMessage = 0;

static const u8 sStartButton_Gfx[] = INCBIN_U8("graphics/bag/start_button.4bpp");

// Menu action callbacks - SWAP/PUTAWAY/READY/CANCEL
static bool8 CraftMenuItemOptionsCallback(void);
static u8 CraftMenuPackUpCallback(void);
static bool8 CraftMenuAddSwapCallback(void);
static bool8 CraftMenuDoOptionsSwapCallback(void);
static bool8 CraftMenuDoOptionsReadyCallback(void);
static void CraftMenuRemoveBagCallback(void);
static u8 CraftMenuReadyCallback(void);
static bool8 CraftMenuCancelCallback(void);

// Functions
static void OrganizeCraftItems(u16 *SwapCraftOrder);
static u16 FindCraftProduct(int);  // Yeah go here if you want to do order-specific recipes
static void InitItemSprites(void);
static void HideOptionsWindow(void);
static void Task_AddCraftDelay(u8 taskId); // currently unused
static bool8 CraftDelay(void); // currently unused
static bool8 IsCraftTableEmpty(void);
static u8 CraftPackUpCheckItem(void); // currently unused
static u8 CraftPackUpFinish(void);

// Messaging
static void CraftReturnToTableFromDialogue(void);
static u8 CraftYesNoInputCallback(void);
static u8 CraftYesNoSetupCallback(void);
static void ShowCraftMessage(const u8 *message, u8 (*craftCallback)(void));
static u8 sCraftDialogueConfirmCallback(void);
static u8 CraftMessageCallback(void);
static bool8 CraftStartConfirmCallback(void);
static bool8 CraftConfirmCallback(void);
static u8 CraftDialoguePackUp(void);

// Menu callbacks
static bool8 HandleCraftMenuInput(void);

// Task callbacks
static void CraftMenuTask(u8 taskId);
static bool8 FieldCB_ReturnToFieldCraftMenu(void);

// Strings
static const u8 sText_Ready[] = _("READY");
static const u8 sText_ConfirmPackUp[] = _("Would you like to pack up?");
static const u8 sText_ConfirmReady[] = _("This looks like it'll be good.\nCraft {STR_VAR_1}{STR_VAR_2}?");
static const u8 sText_ConfirmReadyQty[] = _(" {COLOR GREEN}{SHADOW LIGHT_GREEN}({STR_VAR_1}){COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}");
static const u8 sText_CraftNo[] = _("Hmm, this won't make anything useful...");
static const u8 sText_NotReadyToCraft[] = _("Hmm, this still needs something...");
static const u8 sText_CraftInProcess[] = _("Prepping ingredients... {PAUSE 25}Assembling...\n{PAUSE 25}Finishing up.{PLAY_SE SE_BALL}{PAUSE 25}.{PLAY_SE SE_BALL}{PAUSE 25}.{PLAY_SE SE_BALL}{PAUSE 25}\p{PAUSE_MUSIC}{PLAY_BGM MUS_OBTAIN_ITEM}Item crafted!{PAUSE 130}{RESUME_MUSIC}\p{PLAYER} put away the {STR_VAR_1}\nin the {STR_VAR_2} pocket.{PAUSE_UNTIL_PRESS}");
static const u8 sText_AddItem[] = _("ADD ITEM");
static const u8 sText_ColorShadowBlue[] = _("{COLOR BLUE}{SHADOW LIGHT_BLUE}");
static const u8 sText_InBag[] = _("IN BAG:");
static const u8 sText_Var2Var1[] = _("{STR_VAR_2}{STR_VAR_1}");
extern const u8 gText_DiplomaEmpty[]; //red, lol
static const u8 sText_PackingUp[] = _("Packing up.{PLAY_SE SE_BALL}{PAUSE 25}.{PLAY_SE SE_BALL}{PAUSE 25}.{PLAY_SE SE_BALL}{PAUSE 25}\p{PLAYER} put the items back in the bag.{PAUSE_UNTIL_PRESS}");

static const struct MenuAction sCraftTableActions[] = {
    [TABLE_ACTION_BLANK]            = {gText_Dash,        {.u8_void = CraftMenuAddSwapCallback}},
    [TABLE_ACTION_ITEM]             = {gText_Dash,        {.u8_void = CraftMenuItemOptionsCallback}} //check out startmenusavecallback
};

static const struct MenuAction sCraftOptionsActions[] = { //craft actions, SWAP/READY/PUT AWAY/CANCEL
    [MENU_ACTION_SWAP]            = {gText_Swap,        {.u8_void = CraftMenuAddSwapCallback}},
    [MENU_ACTION_BAG]             = {gText_PutAway,                 NULL},
    [MENU_ACTION_READY]           = {sText_Ready,       {.u8_void = CraftMenuReadyCallback}},
    [MENU_ACTION_CANCEL]          = {gText_Cancel,      {.u8_void = CraftMenuCancelCallback}}
};

static const u8 sCraftOptionsActions_List[] = {
    MENU_ACTION_SWAP,       MENU_ACTION_READY,
    MENU_ACTION_BAG,        MENU_ACTION_CANCEL
};

enum TextColors {
    COLORID_GRAY,
    COLORID_BLACK,
    COLORID_LIGHT_GRAY,
    COLORID_BLUE,
    COLORID_GREEN,
    COLORID_RED,
};

static const u8 sTextColorTable[][3] =
{
    [COLORID_GRAY]       = {TEXT_COLOR_WHITE,       TEXT_COLOR_DARK_GRAY,  TEXT_COLOR_LIGHT_GRAY},
    [COLORID_BLACK]      = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,      TEXT_COLOR_DARK_GRAY},
    [COLORID_LIGHT_GRAY] = {TEXT_COLOR_WHITE,       TEXT_COLOR_LIGHT_GRAY, TEXT_COLOR_DARK_GRAY},
    [COLORID_BLUE]       = {TEXT_COLOR_WHITE,       TEXT_COLOR_BLUE,       TEXT_COLOR_LIGHT_BLUE},
    [COLORID_GREEN]      = {TEXT_COLOR_WHITE,       TEXT_COLOR_GREEN,      TEXT_COLOR_LIGHT_GREEN},
    [COLORID_RED]        = {TEXT_COLOR_WHITE,       TEXT_COLOR_RED,        TEXT_COLOR_LIGHT_RED},
};

enum CraftWindows {
    WINDOW_CRAFT_MSG,
    WINDOW_CRAFT_TABLE,
    WINDOW_CRAFT_INFO,
    WINDOW_CRAFT_YESNO,
    WINDOW_CRAFT_OPTIONS,
    WINDOW_CRAFT_SOUSCHEFS,
};

static const struct WindowTemplate sCraftWindowTemplates[] = {
    [WINDOW_CRAFT_MSG] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 1
    },    
    [WINDOW_CRAFT_TABLE] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 18,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 1 + 27*4,
    },
    [WINDOW_CRAFT_INFO] = {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 15,
        .width = 8,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 1 + 27*4 + 18*4,
    },
    [WINDOW_CRAFT_YESNO] = {
        .bg = 0,
        .tilemapLeft = 26,
        .tilemapTop = 9,
        .width = 3,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 1 + 27*4 + 18*4 + 8*4,
    },
    [WINDOW_CRAFT_OPTIONS] = {
        .bg = 0,
        .tilemapLeft = 15,
        .tilemapTop = 9,
        .width = 14,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 1 + 27*4 + 18*4 + 8*4 + 3*4,
    },
    DUMMY_WIN_TEMPLATE
};

//Local functions
static void BuildCraftTableActions(void);
static void ShowCraftTableWindow(void);
static void ShowCraftInfoWindow(void);
static void ShowCraftOptionsWindow(void);
static void ShowCraftTableAndInfoWindows(void);
static void LoadCraftWindows(void);

static const u8 *GetCraftTableItemName(u16 itemId);
static void RemoveExtraCraftMenuWindows(void);
static void PrintCraftTableItems(void);
static void PrintOptionsMenuGrid(u8, u8, u8);
static bool32 InitCraftMenuStep(void);
static void CraftMenuTask(u8 taskId);
static void UpdateCraftTable(void);
static void UpdateCraftInfoWindow(void);
static void ClearCraftTable(void);
static void Task_CreateCraftMenu(TaskFunc followupFunc);

// Alright, and with that out of the way..!

// Menu / Window Functions
static void BuildCraftTableActions(void){
    u32 i;

    //Stores action per item. 
    for (i = 0; i < 4; i++){
        if(sCurrentCraftTableItems[i][CRAFT_TABLE_ITEM] == ITEM_NONE ||
            sCurrentCraftTableItems[i][CRAFT_TABLE_ITEM] > ITEM_OLD_SEA_MAP){
            
            sCurrentCraftTableItems[i][CRAFT_TABLE_ITEM] = ITEM_NONE;
            sCurrentCraftTableItems[i][CRAFT_TABLE_ACTION] = TABLE_ACTION_BLANK;
        }
        else sCurrentCraftTableItems[i][CRAFT_TABLE_ACTION] = TABLE_ACTION_ITEM;
    } 

}

static void ShowCraftTableWindow(void){

    PutWindowTilemap(sCraftTableWindowId);
    DrawStdWindowFrame(sCraftTableWindowId, FALSE);
    CopyWindowToVram(sCraftTableWindowId, COPYWIN_GFX);
}

static void ShowCraftInfoWindow(void){
 
    PutWindowTilemap(sCraftInfoWindowId);
    DrawStdWindowFrame(sCraftInfoWindowId, FALSE);
    CopyWindowToVram(sCraftInfoWindowId, COPYWIN_GFX);
}

static void PrintOptionsMenuGrid(u8 windowId, u8 columns, u8 rows){

    PrintMenuActionGrid(windowId, FONT_NORMAL, 8, 1, 56, columns, rows, sCraftOptionsActions, sCraftOptionsActions_List);
    InitMenuActionGrid(windowId, 56, columns, rows, 0);
}

static void ShowCraftOptionsWindow(void){

    //clear junk first
    ClearStdWindowAndFrame(sCraftOptionsWindowId, TRUE);
    
    FillWindowPixelBuffer(sCraftOptionsWindowId, PIXEL_FILL(0));
    DrawStdWindowFrame(sCraftOptionsWindowId, FALSE);
    PrintOptionsMenuGrid(sCraftOptionsWindowId, 2, 2);
    
    ScheduleBgCopyTilemapToVram(0);
}

static void ShowCraftTableAndInfoWindows(void){

    ShowCraftTableWindow();
    ShowCraftInfoWindow();
}

static void LoadCraftWindows(void){
    //Craft Table
    sCraftTableWindowId = AddWindow(&sCraftWindowTemplates[WINDOW_CRAFT_TABLE]);

    //Info
    sCraftInfoWindowId = AddWindow(&sCraftWindowTemplates[WINDOW_CRAFT_INFO]);

    //Ready/Options
    sCraftOptionsWindowId = AddWindow(&sCraftWindowTemplates[WINDOW_CRAFT_OPTIONS]);
}

static const u8 *GetCraftTableItemName(u16 itemId){

    //Print filters for item names. GetFacilityCancelString makes the function a pointer so ¯\_(ツ)_/¯
    if(itemId == ITEM_NONE || itemId >= ITEMS_COUNT)
        return gText_Dash;
    else
        return ItemId_GetName(itemId);
}

static void RemoveExtraCraftMenuWindows(void)
{

}

static void PrintCraftTableItems(void){
    //Modified from PrintMenuGridTable
    u32 i, j;

    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++)
            AddTextPrinterParameterized(sCraftTableWindowId, 7,
             GetCraftTableItemName(sCurrentCraftTableItems[(i * 2) + j][CRAFT_TABLE_ITEM]),
             (9*8 * j) + 8, (i * 16) + 1, TEXT_SKIP_DRAW, NULL);
    }

}

static bool32 InitCraftMenuStep(void){

    //list items, draw window, check for extra windows, print menu actions, place cursor, draw everything
    s8 state = sInitCraftMenuData[0];

    switch (state){
        case 0:
            sInitCraftMenuData[0]++;
            break;
        case 1:
            BuildCraftTableActions();
            InitItemSprites();
            sInitCraftMenuData[0]++;
            break;
        case 2:
            LoadMessageBoxAndBorderGfx();
            LoadCraftWindows();
            sInitCraftMenuData[0]++;
            break;
        case 3:
            ShowCraftTableAndInfoWindows();
            sInitCraftMenuData[0]++;
            break;
        case 4:
            PrintCraftTableItems();
            UpdateCraftInfoWindow();
            sInitCraftMenuData[0]++;
            break;
        case 5:
            sCraftMenuCursorPos = InitMenuGrid(sCraftTableWindowId, FONT_NARROW, 0, 1, 9 * 8, 15, 2, //9*8 from ScriptMenu_MultichoiceGrid, 15 from FONT_NARROW
                                                    2, 4, sCraftMenuCursorPos);
            CopyWindowToVram(sCraftTableWindowId, COPYWIN_MAP);
            return TRUE;
    }

    return FALSE;
}

static void CraftMenuTask(u8 taskId){
    
    if (InitCraftMenuStep() == TRUE)
        SwitchTaskToFollowupFunc(taskId);
}

static void UpdateCraftTable(void){

    BuildCraftTableActions();
    FillWindowPixelBuffer(sCraftTableWindowId, PIXEL_FILL(TEXT_COLOR_WHITE));
    PrintCraftTableItems();
    PutWindowTilemap(sCraftTableWindowId);
    ScheduleBgCopyTilemapToVram(0);
}

static void UpdateCraftInfoWindow(void){
    //update info window with every cursor move (item: xQty in Bag & str to craft, \
     blank: A to add item & "items ? str to craft : B to leave")

    //Declare Vars
    u16 itemId, palette;
    bool32 handleFlash;
    u32 quantityInBag;

    //Init Vars
    itemId = sCurrentCraftTableItems[sCraftMenuCursorPos][CRAFT_TABLE_ITEM];
    handleFlash = FALSE;
    quantityInBag = CountTotalItemQuantityInBag(itemId);

    //Check for flash
    if (GetFlashLevel() > 0 || InBattlePyramid())
        handleFlash = TRUE;

    //Clean window
    FillWindowPixelBuffer(sCraftInfoWindowId, PIXEL_FILL(TEXT_COLOR_WHITE));

    //Display Info
    if (itemId){
        // ITEM   In Bag:   \
           ICON   xNum
        
        //icon
        ShowItemIconSprite(itemId, handleFlash, 184, 140); //176 = tilemapleft + 16 border pixels, 140 from GhoulSlash

        //IN BAG:
        AddTextPrinterParameterized(sCraftInfoWindowId, FONT_SMALL, sText_InBag, 25, 1, TEXT_SKIP_DRAW, NULL);
        ConvertIntToDecimalStringN(gStringVar1, quantityInBag, STR_CONV_MODE_LEFT_ALIGN, MAX_ITEM_DIGITS + 1);
        
        //Color for remaining qty
        if (quantityInBag == 0)
            StringCopy(gStringVar2, gText_DiplomaEmpty); //red
        else
            StringCopy(gStringVar2, gText_ColorDarkGray); //normal

        //xQty
        StringExpandPlaceholders(gStringVar4, sText_Var2Var1);
        StringCopy(gStringVar1, gStringVar4);
        StringExpandPlaceholders(gStringVar4, gText_xVar1);
        AddTextPrinterParameterized(sCraftInfoWindowId, FONT_NARROW, gStringVar4, 25, 15, TEXT_SKIP_DRAW, NULL);
        
    }
    else //No Item
    {
        // (A) Add Item      flag-> SEL-> Recipes   \
           (B) Cancel               STR-> Ready

        //------------------------
        //This and (A) button below will replace with SEL= Recipe Book, once the recipe book is implemented that is
        //Add Item 
        StringCopy(gStringVar1, sText_AddItem);
        StringCopy(gStringVar2, sText_ColorShadowBlue);
        StringExpandPlaceholders(gStringVar4, sText_Var2Var1);
        AddTextPrinterParameterized(sCraftInfoWindowId, FONT_SMALL, gStringVar4, 25, 1, TEXT_SKIP_DRAW, NULL);

        //(A) button
        DrawKeypadIcon(sCraftInfoWindowId, CHAR_A_BUTTON, 8, 1);
        //------------------------


        //START = Ready
        if (!IsCraftTableEmpty())
        {
            // (START)
            if (FindCraftProduct(0))
            {
                //Show hint that it's a good recipe
                palette = RGB_BLACK;
                LoadPalette(&palette, BG_PLTT_ID(15) + 10, PLTT_SIZEOF(1));

                BlitBitmapToWindow(sCraftInfoWindowId, sStartButton_Gfx, 0, 16, 24, 16);
            }
            else
            {
                DrawKeypadIcon(sCraftInfoWindowId, CHAR_START_BUTTON, 0, 16);
            }

            // READY
            StringCopy(gStringVar1, sText_Ready);
            StringCopy(gStringVar2, sText_ColorShadowBlue);
            StringExpandPlaceholders(gStringVar4, sText_Var2Var1);
            AddTextPrinterParameterized(sCraftInfoWindowId, FONT_SMALL, gStringVar4, 25, 16, TEXT_SKIP_DRAW, NULL);

        }
        else
        {
            // (B)
            DrawKeypadIcon(sCraftInfoWindowId, CHAR_B_BUTTON, 8, 16);

            // Cancel (in blue1)
            StringCopy(gStringVar1, gText_Cancel);
            StringCopy(gStringVar2, sText_ColorShadowBlue);
            StringExpandPlaceholders(gStringVar4, sText_Var2Var1);
            AddTextPrinterParameterized(sCraftInfoWindowId, FONT_SMALL, gStringVar4, 25, 16, TEXT_SKIP_DRAW, NULL);
        }
    }

    //Draw! (Insert cowboy emoji)
    PutWindowTilemap(sCraftInfoWindowId);
    CopyWindowToVram(sCraftInfoWindowId, COPYWIN_GFX);
    ScheduleBgCopyTilemapToVram(0);
}

static void RestockCraftTable(void){
    u32 i;
    u16 CraftItem;

    //reset cursor position
    sCraftMenuCursorPos = 0;

    //same as ClearCraftTable, but keeps items if there's still some left in the bag
    for (i = 0; i < 4; i++){
        CraftItem = sCurrentCraftTableItems[i][CRAFT_TABLE_ITEM];

        if (!CheckBagHasItem(CraftItem, 0)){
            sCurrentCraftTableItems[i][CRAFT_TABLE_ITEM] = ITEM_NONE;
            sCurrentCraftTableItems[i][CRAFT_TABLE_ACTION] = TABLE_ACTION_BLANK;
        }
        else
            RemoveBagItem(CraftItem, 1);
    }
}

static void ClearCraftTable(void){
    //ClearRoamerLocationData wasn't cool with just = {0} for a 2D array so we're gonna do it here too
    u32 i;

    //reset cursor position
    sCraftMenuCursorPos = 0;

    //clear table
    for (i = 0; i < 4; i++){
        sCurrentCraftTableItems[i][CRAFT_TABLE_ITEM] = ITEM_NONE;
        sCurrentCraftTableItems[i][CRAFT_TABLE_ACTION] = TABLE_ACTION_BLANK;
    }
}

static void ClearCraftInfo(u8 ItemSpot)
{
    if (sCurrentCraftTableItems[ItemSpot][CRAFT_TABLE_ITEM] > 0 || sCurrentCraftTableItems[ItemSpot][CRAFT_TABLE_ITEM] < ITEMS_COUNT)
        DestroyItemIconSprite();
}

static void Task_CreateCraftMenu(TaskFunc followupFunc){
    
    u8 taskId;

    sInitCraftMenuData[0] = 0;

    //everything else goes straight to Task_ShowStartMenu, so this Create function must be like a startup init    
    ClearCraftTable();

    taskId = CreateTask(CraftMenuTask, 0x50);
    SetTaskFuncWithFollowupFunc(taskId, CraftMenuTask, followupFunc);
}

static bool8 FieldCB_ReturnToFieldCraftMenu(void){

    if (InitCraftMenuStep() == FALSE)
        return FALSE;

    ReturnToField_OpenCraftMenu();
    return TRUE;
}

void ShowReturnToFieldCraftMenu(void){

    u16 *SwapItem;

    SwapItem = &sCurrentCraftTableItems[sCraftMenuCursorPos][CRAFT_TABLE_ITEM];

    sInitCraftMenuData[0] = 0;
    if (gSpecialVar_ItemId != ITEM_NONE){
        AddBagItem(*SwapItem, 1);
        RemoveBagItem(gSpecialVar_ItemId, 1);
        *SwapItem = gSpecialVar_ItemId;
    }
    BuildCraftTableActions();
    gFieldCallback2 = FieldCB_ReturnToFieldCraftMenu;
}

void Task_ShowCraftMenu(u8 taskId){
              
                //pointer for global task location, data[0] acts as state for create switch
    struct Task *task = &gTasks[taskId];

    switch(task->data[0]){
        case 0:
            gMenuCallback = HandleCraftMenuInput;
            task->data[0]++;
            break;
        case 1:
            if (gMenuCallback() == TRUE)
                DestroyTask(taskId);
            break;
    }
}

// The start of the show
void ShowCraftMenu(void){

    PlayerFreeze();
    StopPlayerAvatar();
    ScriptContext_Stop();

    Task_CreateCraftMenu(Task_ShowCraftMenu);
    LockPlayerFieldControls();
}

#define sCraftDelay data[2]

static bool8 CraftDelay(void){ // currently unused :(

    sPauseCounter--;

    if (JOY_HELD(A_BUTTON)){
        PlaySE(SE_SELECT);
        return TRUE;
    }
    if (sPauseCounter == 0 || --sPauseCounter == 0)
        return TRUE;
    
    return FALSE;
}

static void Task_AddCraftDelay(u8 taskId){  // currently unused

    if (--gTasks[taskId].sCraftDelay == 0)
        DestroyTask(taskId);
}

static bool8 IsCraftTableEmpty(void){

    u32 i;

    for (i = 0; i < 4; i++){

        if (sCurrentCraftTableItems[i][CRAFT_TABLE_ITEM] != ITEM_NONE)
            return FALSE;
    }

    return TRUE;
}

static bool8 HandleCraftMenuInput(void){

    u8 OptionsCursorPos;
    u8 OldPos;

    OldPos = sCraftMenuCursorPos;

    switch(sCraftState){

        case STATE_TABLE_INPUT:

            if (JOY_NEW(DPAD_UP))
            {
                PlaySE(SE_BALL);
                sCraftMenuCursorPos = ChangeGridMenuCursorPosition(0,-1);
            }
            if (JOY_NEW(DPAD_LEFT))
            {
                PlaySE(SE_BALL);
                sCraftMenuCursorPos = ChangeGridMenuCursorPosition(-1,0);
            }
            if (JOY_NEW(DPAD_RIGHT))
            {
                PlaySE(SE_BALL);
                sCraftMenuCursorPos = ChangeGridMenuCursorPosition(1,0);
            }
            if (JOY_NEW(DPAD_DOWN))
            {
                PlaySE(SE_BALL);
                sCraftMenuCursorPos = ChangeGridMenuCursorPosition(0,1);
            }

            if (JOY_NEW(A_BUTTON)){

                PlaySE(SE_SELECT);

                gMenuCallback = sCraftTableActions[
                    sCurrentCraftTableItems[sCraftMenuCursorPos][CRAFT_TABLE_ACTION]].func.u8_void;

                if (gMenuCallback == CraftMenuAddSwapCallback) //if it's blank
                    FadeScreen(FADE_TO_BLACK, 0);
                
                return FALSE;
            }

            if (JOY_NEW(START_BUTTON)){

                if (IsCraftTableEmpty())
                    PlaySE(SE_BOO);
                else {
                    ClearCraftInfo(sCraftMenuCursorPos);
                    CraftMessage = CRAFT_READY_CONFIRM;
                    gMenuCallback = CraftStartConfirmCallback;
                }
                
                return FALSE;
            }

            //select button, instant addswap item (or recipe book??)
            /*
            if (JOY_NEW(SELECT_BUTTON))
            {
                PlaySE(SE_WIN_OPEN);
                ShowCraftOptionsWindow();
                sCraftState = STATE_OPTIONS_INPUT;
            }
            */

            if (JOY_NEW(B_BUTTON)){

                //If !IsCraftTableEmpty then gmenucallback = CraftMenuPackUpCallback, otherwise just quit
                if (IsCraftTableEmpty()){

                    PlaySE(SE_SELECT);
                    HideCraftMenu();
                    ScriptContext_Enable();
                    return TRUE;
                }

                ClearCraftInfo(sCraftMenuCursorPos);
                CraftMessage = CRAFT_PACKUP_CONFIRM;
                gMenuCallback = CraftStartConfirmCallback; //let the gMenu pinball begin
                
                return FALSE;
            }

                ClearCraftInfo(OldPos);
                UpdateCraftInfoWindow();

            return FALSE;

        case STATE_OPTIONS_INPUT:
            OptionsCursorPos = Menu_GetCursorPos();

            if (JOY_NEW(DPAD_UP)){

                if (OptionsCursorPos > 1){

                    PlaySE(SE_SELECT);
                    ChangeMenuGridCursorPosition(MENU_CURSOR_DELTA_NONE, MENU_CURSOR_DELTA_UP);
                }
            }
            else if (JOY_NEW(DPAD_DOWN)){

                if (OptionsCursorPos < 2){

                    PlaySE(SE_SELECT);
                    ChangeMenuGridCursorPosition(MENU_CURSOR_DELTA_NONE, MENU_CURSOR_DELTA_DOWN);
                }
            }
            else if (JOY_NEW(DPAD_LEFT)){

                if (OptionsCursorPos + 1 == 2 || OptionsCursorPos + 1 == 4){
                    PlaySE(SE_SELECT);
                    ChangeMenuGridCursorPosition(MENU_CURSOR_DELTA_LEFT, MENU_CURSOR_DELTA_NONE);
                }
            }
            else if (JOY_NEW(DPAD_RIGHT)){

                if (OptionsCursorPos + 1 == 1 || OptionsCursorPos + 1 == 3){
                    PlaySE(SE_SELECT);
                    ChangeMenuGridCursorPosition(MENU_CURSOR_DELTA_RIGHT, MENU_CURSOR_DELTA_NONE);
                }
            }
            else if (JOY_NEW(A_BUTTON)){

                switch (sCraftOptionsActions_List[OptionsCursorPos]){
                    case MENU_ACTION_SWAP:
                        PlaySE(SE_SELECT);
                        CraftMenuDoOptionsSwapCallback();
                        FadeScreen(FADE_TO_BLACK, 0);
                        break;
                    case MENU_ACTION_BAG:
                        PlaySE(SE_WIN_OPEN);
                        CraftMenuRemoveBagCallback();
                        break;
                    case MENU_ACTION_READY:
                        PlaySE(SE_SELECT);
                        ClearCraftInfo(sCraftMenuCursorPos);
                        CraftMenuDoOptionsReadyCallback();
                    case MENU_ACTION_CANCEL:
                    default:
                        CraftMenuCancelCallback();
                        break;
                }

                return FALSE;
            }
           
            else if (JOY_NEW(B_BUTTON)){
                CraftMenuCancelCallback();
        }

            return FALSE;
    }
}

static void CraftMenu_PrintCursorAtPos(u8 cursorPos, u8 colorIndex){

    u8 x, y;

    y = 1;

    if (cursorPos == 0 || cursorPos == 2)
        x = 0;
    else
        x = 9*8;

    if (cursorPos > 1)
        y = 16;

    FillWindowPixelRect(sCraftTableWindowId, PIXEL_FILL(TEXT_COLOR_WHITE), 0, y, GetMenuCursorDimensionByFont(FONT_NORMAL, 0), GetMenuCursorDimensionByFont(FONT_NORMAL, 1));
    AddTextPrinterParameterized4(sCraftTableWindowId, FONT_NORMAL, x, y, 0, 0, sTextColorTable[colorIndex], 0, gText_SelectorArrow2);
}

//Callbacks / Actions
static bool8 CraftMenuItemOptionsCallback(void){
    
    CraftMenu_PrintCursorAtPos(sCraftMenuCursorPos, COLORID_LIGHT_GRAY);
    ShowCraftOptionsWindow();
    sCraftState = STATE_OPTIONS_INPUT;
    gMenuCallback = HandleCraftMenuInput;

    return FALSE;
}

// Watch out, code-explorer... from here on is some wip stuff where I tried to do an animation
// for the packup table unloading and am thus far unsuccessful
// Maybe you noticed some of the currently unused delay stuff earlier.
// Some of this stuff may be confusing to trace through.
// Add my 80% efforts and additions on top of that and, well, it's easy to get tangled up...
/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠔⠒⠒⠠⠄⢠
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣁⠴⠛⠋⠀⠀⡎
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠔⠉⠀⠀⠀⠀⡎⠰⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠜⠁⠀⠀⠀⠀⠀⡼⠒⠁⠀
⠀⠀⠀⠀⣀⢀⡀⠀⠀⠀⠀⠀⠀⠀⢀⣶⡓⠀⠀⠀⠀⠀⢀⠜⠀⠀⠀⠀
⠀⠀⢠⣪⠖⠒⢮⣢⠀⠀⠀⠀⡠⢊⢕⣢⡌⢦⠀⢤⣠⠔⠁⠀⠀⠀⠀⠀
⢳⣴⠷⠃⠔⣒⠚⠇⡢⠠⠤⠺⠃⠘⢞⣋⠅⢠⠧⠊⠁⠀⠀⠀⠀⠀⠀⠀
⡀⠀⣔⣕⣁⣤⣬⢦⣤⣭⠤⢂⡀⠀⣀⡀⠔⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠉⢋⡿⢛⣭⣴⣶⡿⢉⣤⣴⣿⠀⠁⡇⠀⢀⠠⠤⠀⠤⡀⠀⠀⠀⠀⠀⠀
⠀⣮⠁⣾⠟⠉⠀⢰⡘⡿⠁⣿⣄⠣⡍⠉⠔⠊⠉⠉⢱⡼⠀⠀⠀⠀⠀⠀
⠀⠿⠀⢹⠀⢀⣼⠟⠉⢊⠆⠻⣿⢓⠪⠥⡂⢄⠀⠀⢗⢅⣀⣀⡀⠀⠀⠀
⠀⠘⡹⡉⠀⢸⣟⠀⢀⢜⠆⠀⠹⣻⢦⡀⠈⡄⡇⠀⠀⠉⠉⠉⠁⠀⠀⠀
⠀⠀⠈⠺⢄⠀⠹⡆⠻⠁⠀⢀⡴⡹⠀⠻⣄⣽⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢱⣜⣦⠀⠀⠀⢠⡗⠉⠀⠀⠀⢩⡌⠙⢳⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢸⢽⣿⠀⠀⠀⠈⠓⠀⠀⠀⠀⢀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠫⣛⡄⠀⢀⢴⣾⣗⡶⢠⡴⠗⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠀⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
*/
// Ye be warned, code-explorer. Good luck! I'll let you know when you're back in safer waters.

enum PackUpState {
    NO_ITEM,
    YES_ITEM
};

static u8 CraftPackUpCheckItem(void){
    if (sCurrentCraftTableItems[sCraftMenuCursorPos][CRAFT_TABLE_ITEM] == ITEM_NONE || 
        sCurrentCraftTableItems[sCraftMenuCursorPos][CRAFT_TABLE_ITEM] >= ITEMS_COUNT)
    {
        return NO_ITEM;
    }
    else {
        return YES_ITEM;
    }
}

enum CraftMessageState {
    CRAFT_MESSAGE_IN_PROGRESS,
    CRAFT_MESSAGE_CONFIRM,
    CRAFT_MESSAGE_CANCEL
};

static u8 CraftPackUpFinish(void){

    //PlaySE(SE_RG_BAG_POCKET);
    //HideCraftMenu();

    //Until the delay/animated pack up works...
    ShowCraftMessage(sText_PackingUp, CraftDialoguePackUp);

    return CRAFT_MESSAGE_IN_PROGRESS;
}

static u8 CraftPackUpCheckDelay(void){

    //if (CraftDelay())
    //if(CraftMenuPackUpCallback == TRUE)
        sCraftDialogCallback = CraftPackUpFinish;

    return CRAFT_MESSAGE_IN_PROGRESS;
}

static u8 CraftMenuPackUpCallback(void){
    
    s8 i;
    u8 taskId;
    //u16 CraftItem;
    u16 *CraftItem;

    //CraftItem = sCurrentCraftTableItems[sCraftMenuCursorPos][CRAFT_TABLE_ITEM]; 
    CraftItem = &sCurrentCraftTableItems[sCraftMenuCursorPos][CRAFT_TABLE_ITEM]; 

    /*
    sPauseCounter--;
    if (sPauseCounter > 0)
        return FALSE;
    */

    //enabling the spausecounter above only allows for full crafting table packup, missing items cause freeze
    switch (sCraftMenuCursorPos)
    {
    case 0:
        if (*CraftItem == ITEM_NONE){

            sCraftDialogCallback = CraftPackUpFinish;
            break;
            //return TRUE;
            //return CraftPackUpFinish();
            //gMenuCallback = CraftPackUpFinish;
        }

    default:
        if (*CraftItem != ITEM_NONE){
            PlaySE(SE_BALL);
            CraftMenuRemoveBagCallback();
            //return FALSE;
            //break;
            sPauseCounter = 25;  //check out Task_AnimateAfterDelay
        }
        sCraftMenuCursorPos != 0 ? --sCraftMenuCursorPos : 0;
        break;
    }

    //sPauseCounter = (sCurrentCraftTableItems[sCraftMenuCursorPos - 1][CRAFT_TABLE_ITEM] == ITEM_NONE) ? 0 : 25000;

    return CRAFT_MESSAGE_IN_PROGRESS;

}

// Okay, we're back to smooth sailing more or less.
// There's one more tricky part at the end where
// the start menu pretty much played dialogue pinball with the
// "SaveDialogCallback" so you'll see some of that.
// My biggest concern in this area is if anything gets leftover
// from all the window switching and bugs start to appear
// but everything looks okay so far from what testing I've done.
// Again lmk if you have any pull requests!
// Thanks for looking through :)
// - redsquidzv くコ:彡

static void HideOptionsWindow(void){

    ClearStdWindowAndFrame(sCraftOptionsWindowId, TRUE);
    sCraftMenuCursorPos = InitMenuGrid(sCraftTableWindowId, FONT_NARROW, 0, 1, 9 * 8, 15, 2, //9*8 from ScriptMenu_MultichoiceGrid, 15 from FONT_NARROW
                                        2, 4, sCraftMenuCursorPos);
    sCraftState = STATE_TABLE_INPUT;
}

static bool8 CraftMenuAddSwapCallback(void){

    if (!gPaletteFade.active){

        PlayRainStoppingSoundEffect();
        HideCraftMenu();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_BagMenuFromCraftMenu);

        return TRUE;
    }

    return FALSE;  
}

static bool8 CraftMenuDoOptionsSwapCallback(void){

    gMenuCallback = CraftMenuAddSwapCallback;
    sCraftState = STATE_TABLE_INPUT;

    return FALSE;
}

static bool8 CraftMenuDoOptionsReadyCallback(void){

    CraftMessage = CRAFT_READY_CONFIRM;
    gMenuCallback = CraftStartConfirmCallback;

    return FALSE;
}

static void CraftMenuRemoveBagCallback(void){
     
    u16 *CraftItem;

    CraftItem = &sCurrentCraftTableItems[sCraftMenuCursorPos][CRAFT_TABLE_ITEM]; 
    
    if (*CraftItem != ITEM_NONE){
        DestroyItemIconSprite();
        AddBagItem(*CraftItem, 1);
        *CraftItem = ITEM_NONE;
    }

    UpdateCraftTable();
    UpdateCraftInfoWindow();
    HideOptionsWindow();
}

#define CRAFT_PRODUCT 0
#define CRAFT_QUANTITY 1

static u8 CraftMenuReadyCallback(void){

    u16 CraftProduct, CraftQty;

    CraftProduct = FindCraftProduct(CRAFT_PRODUCT);
    CraftQty = FindCraftProduct(CRAFT_QUANTITY);

    AddBagItem(CraftProduct, CraftQty);

    ClearCraftInfo(sCraftMenuCursorPos);

    CopyItemName(CraftProduct, gStringVar1);
    StringCopy(gStringVar2, gPocketNamesStringsTable[ItemId_GetPocket(CraftProduct) - 1]);
    StringExpandPlaceholders(gStringVar4, sText_CraftInProcess);
    ShowCraftMessage(gStringVar4, CraftDialoguePackUp);

    RestockCraftTable();
    UpdateCraftTable();

    return CRAFT_MESSAGE_IN_PROGRESS;
}

static bool8 CraftMenuCancelCallback(void){
    
    PlaySE(SE_WIN_OPEN);
    HideOptionsWindow();

    return FALSE;  
}

void HideCraftMenu(void){

    ClearStdWindowAndFrame(sCraftTableWindowId, TRUE);
    if (sCraftTableWindowId != WINDOW_NONE){
        RemoveWindow(sCraftTableWindowId);
        sCraftTableWindowId = WINDOW_NONE;
    }

    ClearStdWindowAndFrame(sCraftInfoWindowId, TRUE);
    if (sCraftInfoWindowId != WINDOW_NONE){
        RemoveWindow(sCraftInfoWindowId);
        sCraftInfoWindowId = WINDOW_NONE;
    }

    if (sCraftOptionsWindowId != WINDOW_NONE){
        RemoveWindow(sCraftOptionsWindowId);
        sCraftOptionsWindowId = WINDOW_NONE;
    }

    ScriptUnfreezeObjectEvents();
    UnlockPlayerFieldControls();
}

static void OrganizeCraftItems(u16 *SwapCraftOrder){

    u32 i;
    u16 CraftSwapItem;

    //Set up temp list
    for (i = 0; i < 4; i++){
        SwapCraftOrder[i] = sCurrentCraftTableItems[i][CRAFT_TABLE_ITEM];
    }

    //split into two groups and arrange ex: "DB CA" -> "BD AC"
    for (i = 0; i < 3; i += 2){        
        if (SwapCraftOrder[i] > SwapCraftOrder[i + 1])
            SWAP(SwapCraftOrder[i], SwapCraftOrder[i + 1], CraftSwapItem);
    }

    //arrange biggest items ex: "BD AC" -> "BC AD"
    if (SwapCraftOrder[1] > SwapCraftOrder[3])
        SWAP(SwapCraftOrder[1], SwapCraftOrder[3], CraftSwapItem);

    //arrange smallest items ex: "BC AD" -> "AC BD"
    if (SwapCraftOrder[0] > SwapCraftOrder[2])
        SWAP(SwapCraftOrder[0], SwapCraftOrder[2], CraftSwapItem);

    //compare biggest small against smallest big ex: "AC BD" -> "AB CD"
    if (SwapCraftOrder[1] > SwapCraftOrder[2])
        SWAP(SwapCraftOrder[1], SwapCraftOrder[2], CraftSwapItem);

    //Organized!
}

static u16 FindCraftProduct(int PrdOrQty){

    u32 i, j;
    u16 CraftSwapItem;
    u16 CraftProduct = ITEM_NONE;
    u16 CraftItems[4];

    OrganizeCraftItems(CraftItems); //comment this out if you want to do pattern/order specific recipes

    for (i = 0; i < ARRAY_COUNT(Craft_Recipes); i++){

        for (j = 0; j < 4; j++){

            if (CraftItems[j] != Craft_Recipes[i][j])
                break;
            else if (j == 3){
                CraftProduct = Craft_Recipes[i][4 + PrdOrQty];
                break;
            }
            else
                CraftProduct = ITEM_NONE;
        }

        if (CraftProduct != ITEM_NONE)
            break;
    }
    
    return CraftProduct;
}

static bool32 CheckCraftProductFlags(u16 itemId){

    u32 i, ItemPos;
    int FlagCount;

    //This counts columns aka dimension 2, so -1 for flags since first column is the itemId.
    //ARRAY_COUNT divides the specified array element by the first element therein,
    //so here arr[0] = row and arr[0][0] = first element in row.
    //Usually it's the whole array divided by the first element, aka rows
    FlagCount = ARRAY_COUNT(Craft_Flags[0]) - 1;

    //search Craft_Flags for the product. If there's no item, there's no flags, so it passes.
    for (i = 0; i < ARRAY_COUNT(Craft_Flags); i++){
        if (Craft_Flags[i][0] == itemId){
            ItemPos = i;
            break;
        }
    }

    if (i == ARRAY_COUNT(Craft_Flags))
        return TRUE;

    //Pass still uncertain. Check for flags.
    for (i = 1; i < FlagCount + 1; i++){
        if (!FlagGet(Craft_Flags[ItemPos][i]))
            return FALSE;
    }

    //Check passed
    return TRUE;
}

static void InitItemSprites(void){

    //Peaches for my peach <3
    ShowItemIconSprite(ITEM_PECHA_BERRY,FALSE,200,1);
    DestroyItemIconSprite();
}

static void CraftReturnToTableFromDialogue(void){

    ClearDialogWindowAndFrame(0, TRUE);
    ClearDialogWindowAndFrameToTransparent(0, FALSE);
    
    sInitCraftMenuData[0] = 0;
    while (!InitCraftMenuStep())
        ;
}

static u8 CraftYesNoInputCallback(void){

    switch (Menu_ProcessInputNoWrapClearOnChoose()){

        case 0: // Yes

            switch (CraftMessage){

                case CRAFT_PACKUP_CONFIRM: // You'll see some more attempts at the packup animation here
                    sCraftMenuCursorPos = 3;
                    sPauseCounter = 30;
                    //sCraftDialogCallback = CraftPackUpCheckDelay;
                    sCraftDialogCallback = CraftMenuPackUpCallback;
                    break;
                case CRAFT_READY_CONFIRM:
                    sCraftDialogCallback = CraftMenuReadyCallback;
                    break;
                default:
                    break;
            }
            break;
        case MENU_B_PRESSED:
        case 1:
            CraftReturnToTableFromDialogue();
            return CRAFT_MESSAGE_CANCEL;
    }

    return CRAFT_MESSAGE_IN_PROGRESS;
}

static u8 CraftYesNoSetupCallback(void){

    u8 MessageState;

    //For CraftMessages at or over 1, always choose Yes default. 
    MessageState = CraftMessage > 1 ? 0 : abs(CraftMessage - 1);
    
    DisplayYesNoMenuWithDefault(MessageState); // Show Yes/No menu, 0 = Yes, 1 = No
    
    sCraftDialogCallback = CraftYesNoInputCallback;
    
    return CRAFT_MESSAGE_IN_PROGRESS;
}

static u8 CraftMessageWaitForButtonPress(void){

    if (!IsTextPrinterActive(0) && (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))){

        CraftReturnToTableFromDialogue();
        return CRAFT_MESSAGE_CANCEL;
    }

    return CRAFT_MESSAGE_IN_PROGRESS;
}

static void ShowCraftMessage(const u8 *message, u8 (*craftCallback)(void)){

    StringExpandPlaceholders(gStringVar4, message);
    LoadMessageBoxAndFrameGfx(0, TRUE);
    AddTextPrinterForMessage_2(TRUE);
    sCraftDialogCallback = craftCallback;
}

static u8 sCraftDialogueConfirmCallback(void){

    const u8 *message;
    u16 CraftProduct, CraftQty;

    HideCraftMenu();
    FreezeObjectEvents();
    LockPlayerFieldControls();

    CraftProduct = FindCraftProduct(CRAFT_PRODUCT);
    CraftQty = FindCraftProduct(CRAFT_QUANTITY);

    switch (CraftMessage){

        case CRAFT_PACKUP_CONFIRM:
            PlaySE(SE_SELECT);
            message = sText_ConfirmPackUp;
            break;

        case CRAFT_READY_CONFIRM:
            if (CraftProduct == ITEM_NONE){
                message = sText_CraftNo;
                PlaySE(SE_BOO);
            }
            else if(CheckCraftProductFlags(CraftProduct)){
                PlaySE(SE_SELECT);

                //expand those placeholders
                if (CraftQty > 1){
                    ConvertIntToDecimalStringN(gStringVar1, CraftQty, STR_CONV_MODE_LEFT_ALIGN, 2);
                    StringExpandPlaceholders(gStringVar2, sText_ConfirmReadyQty);
                }
                else
                    StringCopy(gStringVar2, gText_EmptyString2);

                CopyItemName(CraftProduct, gStringVar1);
                StringExpandPlaceholders(gStringVar4, sText_ConfirmReady);
                message = gStringVar4;
                break;
            }
            else{
                PlaySE(SE_BOO);
                message = sText_NotReadyToCraft;
            }
            ShowCraftMessage(message, CraftMessageWaitForButtonPress);
            return CRAFT_MESSAGE_IN_PROGRESS;
            break;
    }

    ShowCraftMessage(message, CraftYesNoSetupCallback);
    
    return CRAFT_MESSAGE_IN_PROGRESS;
}

#undef CRAFT_PRODUCT
#undef CRAFT_QUANTITY

static u8 CraftMessageCallback(void){

    // True if text is still printing
    if (RunTextPrintersAndIsPrinter0Active() == TRUE)
        return CRAFT_MESSAGE_IN_PROGRESS;
    
    return sCraftDialogCallback();
}

static bool8 CraftStartConfirmCallback(void){

    sCraftDialogCallback = sCraftDialogueConfirmCallback;

    gMenuCallback = CraftConfirmCallback;

    return FALSE;
}

// Pinball time
static bool8 CraftConfirmCallback(void){
        
    switch (CraftMessageCallback()){

        case CRAFT_MESSAGE_IN_PROGRESS:
            return FALSE;
        case CRAFT_MESSAGE_CONFIRM:

            switch (CraftMessage){

                case CRAFT_PACKUP_CONFIRM:
                    HideCraftMenu();
                    ScriptContext_Enable();
                    return TRUE;
                case CRAFT_READY_CONFIRM:
                    CraftReturnToTableFromDialogue();
                    break;
            }
        case CRAFT_MESSAGE_CANCEL:
            gMenuCallback = HandleCraftMenuInput;
            return FALSE;
    }

    return FALSE;
}

static u8 CraftDialoguePackUp(void){

    ClearDialogWindowAndFrame(0, TRUE);
    return CRAFT_MESSAGE_CONFIRM;
}

#ifndef GUARD_CRAFT_MENU_H
#define GUARD_CRAFT_MENU_H

extern bool8 (*gMenuCallback)(void);
extern EWRAM_DATA u16 sCurrentCraftTableItems[4][2];
extern EWRAM_DATA u8 sCraftMenuCursorPos;

void ShowReturnToFieldCraftMenu(void);
void Task_ShowCraftMenu(u8 taskId);
void ShowCraftMenu(void);
void HideCraftMenu(void);

#endif // GUARD_CRAFT_MENU_H

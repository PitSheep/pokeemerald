Craft_EventScript_CraftTable::
    msgbox Text_CraftTable_WantToCraft, MSGBOX_YESNO
    delay 4
    goto_if_eq VAR_RESULT, YES, Craft_EventScript_OpenCraftMenu
    goto Craft_Cancel
    end

Text_CraftTable_WantToCraft:
    .string "There's a WORK STATION...\n"
    .string "Want to CRAFT something?$"

Craft_EventScript_OpenCraftMenu::
    playse SE_WIN_OPEN
    special ShowCraftMenu
    waitstate
    releaseall
    end

Craft_Cancel:
    releaseall
    end

@ CRAFT TUTORIAL
    @ State descriptions for VAR_ROUTE102_STATE
    @ 0: New Game
    @ 1: Fetch Quest
    @ 2: Antidote crafting
    @ 3: Normal. Free Use of Work Station

CraftTutorial_EventScript_Table::
    lock
    call_if_eq VAR_ROUTE102_STATE, 0, CraftTutorial_EventScript_FlowerBox
    goto_if_eq VAR_TEMP_0,         2, CraftTutorial_EventScript_AntidoteCheck
    goto_if_eq VAR_ROUTE102_STATE, 1, CraftTutorial_EventScript_WorkStation
    goto_if_eq VAR_ROUTE102_STATE, 3, Craft_EventScript_CraftTable
    goto CraftTutorial_EventScript_Hey
    end

CraftTutorial_EventScript_BoyDialogue::
    lock
    applymovement 5, Common_Movement_FacePlayer
    goto_if_eq VAR_TEMP_0,         2, CraftTutorial_EventScript_HowToCraft
    goto_if_eq VAR_ROUTE102_STATE, 1, CraftTutorial_EventScript_ItemCheck
    goto_if_eq VAR_ROUTE102_STATE, 3, CraftTutorial_EventScript_WantReminder
    return

CraftTutorial_EventScript_FlowerBox::
    msgbox CraftTutorial_Text_ItsAFlowerBox, MSGBOX_DEFAULT
    return

CraftTutorial_EventScript_Hey::
    lockall
    applymovement 5, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
    playse SE_PIN
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	delay 30
    setobjectmovementtype 5, MOVEMENT_TYPE_FACE_DOWN
    msgbox CraftTutorial_Text_HeyLikeMySetup, MSGBOX_DEFAULT
    specialvar VAR_RESULT, GetPlayerFacingDirection
	call_if_eq VAR_RESULT, DIR_SOUTH, CraftTutorial_EventScript_ApproachPlayer1
    call_if_eq VAR_RESULT, DIR_EAST,  CraftTutorial_EventScript_ApproachPlayer2
	call_if_eq VAR_RESULT, DIR_NORTH, CraftTutorial_EventScript_ApproachPlayer3
    msgbox CraftTutorial_Text_FindAPechaAndPotion, MSGBOX_DEFAULT
    closemessage
    applymovement 5, CraftTutorial_Movement_GoBackToGrass
    waitmovement 0
    setvar VAR_ROUTE102_STATE, 1
    releaseall
    end

CraftTutorial_EventScript_ApproachPlayer1::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
    applymovement 5, CraftTutorial_Movement_GoToCraftTable
    waitmovement 0
    turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
    msgbox CraftTutorial_Text_HeyLikeMySetup2, MSGBOX_DEFAULT
    turnobject 5, DIR_NORTH
    return

CraftTutorial_EventScript_ApproachPlayer2::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
    applymovement 5, CraftTutorial_Movement_GoToCraftTableMovePlayer1
    waitmovement 0
    turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
    msgbox CraftTutorial_Text_HeyLikeMySetup2, MSGBOX_DEFAULT
    applymovement OBJ_EVENT_ID_PLAYER, CraftTutorial_Movement_GoToCraftTableMovePlayer2
    applymovement 5, CraftTutorial_Movement_GoToCraftTableMovePlayer3
    waitmovement 0
    turnobject 5, DIR_SOUTH
    return

CraftTutorial_EventScript_ApproachPlayer3::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
    applymovement 5, CraftTutorial_Movement_GoToCraftTable
    waitmovement 0
    turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
    msgbox CraftTutorial_Text_HeyLikeMySetup2, MSGBOX_DEFAULT
    turnobject 5, DIR_SOUTH
    return

CraftTutorial_EventScript_WorkStation::
    msgbox CraftTutorial_Text_ItsAWorkStation, MSGBOX_DEFAULT
    release
    end

CraftTutorial_EventScript_ItemCheck::
    checkitem ITEM_PECHA_BERRY
    goto_if_eq VAR_RESULT, FALSE, CraftTutorial_EventScript_ItemCheckFail
    checkitem ITEM_POTION
    goto_if_eq VAR_RESULT, FALSE, CraftTutorial_EventScript_ItemCheckFail
    goto CraftTutorial_EventScript_LetsDoIt
    end

CraftTutorial_EventScript_ItemCheckFail::
    msgbox CraftTutorial_Text_NeedMoreItems, MSGBOX_DEFAULT
    closemessage
    releaseall
    end

CraftTutorial_EventScript_LetsDoIt::
	specialvar VAR_RESULT, GetPlayerFacingDirection
    msgbox CraftTutorial_Text_YouGotTheStuff, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_FOLLOW_ME, FALSE
    applymovement 5, CraftTutorial_Movement_GoToCraftTable2
    call_if_eq VAR_RESULT, DIR_SOUTH, CraftTutorial_EventScript_LetsGoN
    call_if_eq VAR_RESULT, DIR_NORTH, CraftTutorial_EventScript_LetsGoS
    call_if_eq VAR_RESULT, DIR_WEST,  CraftTutorial_EventScript_LetsGoE
    call_if_eq VAR_RESULT, DIR_EAST,  CraftTutorial_EventScript_LetsGoW
    msgbox CraftTutorial_Text_CraftingIsSimple, MSGBOX_DEFAULT
    closemessage
    turnobject 5, DIR_NORTH
    applymovement OBJ_EVENT_ID_PLAYER, CraftTutorial_Movement_FollowToCraftTableFinish
    waitmovement 0
    msgbox CraftTutorial_Text_ChooseSpaceAndAddItem, MSGBOX_DEFAULT
    setobjectxyperm 5, 39, 7
	setobjectmovementtype 5, MOVEMENT_TYPE_LOOK_AROUND
    setvar VAR_TEMP_0, 2
	fadedefaultbgm
    releaseall
    end

CraftTutorial_EventScript_HowToCraft::
    msgbox CraftTutorial_Text_ChooseSpaceAndAddItem, MSGBOX_DEFAULT
    closemessage
    releaseall
    end

CraftTutorial_EventScript_WantReminder::
    msgbox CraftTutorial_Text_WantCraftingInstructions, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, CraftTutorial_EventScript_HowToCraft
    msgbox CraftTutorial_Text_SpringWaterIsNice, MSGBOX_DEFAULT
    releaseall
    end

CraftTutorial_EventScript_AntidoteCheck::
    msgbox Text_CraftTable_WantToCraft, MSGBOX_YESNO
    delay 4
    goto_if_eq VAR_RESULT, YES, CraftTutorial_UseCraftTable
    goto Craft_Cancel
    end

CraftTutorial_UseCraftTable::
    playse SE_WIN_OPEN
    special ShowCraftMenu
    waitstate
    applymovement 5, Common_Movement_FacePlayer
    setvar VAR_RESULT, FALSE
    checkitem ITEM_ANTIDOTE, 3
    goto_if_eq VAR_RESULT, TRUE, CraftTutorial_EventScript_Finish
    releaseall
    end

CraftTutorial_EventScript_Finish::
    delay 20
    turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
    playse SE_PIN
    msgbox CraftTutorial_Text_ThatsIt, MSGBOX_DEFAULT
    closemessage
    applymovement 5, CraftTutorial_Movement_CollectPayment
    waitmovement 0
    playse SE_SHOP
    removeitem ITEM_ANTIDOTE, 2
    msgbox CraftTutorial_Text_PlayerGaveAntidote, MSGBOX_DEFAULT
    msgbox CraftTutorial_Text_PleasureDoingBusiness, MSGBOX_DEFAULT
    closemessage
    applymovement 5, CraftTutorial_Movement_GoBackToGrassAfterTutorial
    waitmovement 0
    setobjectmovementtype 5, MOVEMENT_TYPE_WANDER_AROUND
    setvar VAR_TEMP_0, 0
    setvar VAR_ROUTE102_STATE, 3
    releaseall
    end

CraftTutorial_EventScript_LetsGoN:
    applymovement OBJ_EVENT_ID_PLAYER, CraftTutorial_Movement_FollowToCraftTableNorth
    waitmovement 0
    return

CraftTutorial_EventScript_LetsGoS:
    applymovement OBJ_EVENT_ID_PLAYER, CraftTutorial_Movement_FollowToCraftTableSouth
    waitmovement 0
    return
    
CraftTutorial_EventScript_LetsGoE:
    applymovement OBJ_EVENT_ID_PLAYER, CraftTutorial_Movement_FollowToCraftTableEast
    waitmovement 0
    return

CraftTutorial_EventScript_LetsGoW:
    applymovement OBJ_EVENT_ID_PLAYER, CraftTutorial_Movement_FollowToCraftTableWest
    waitmovement 0
    return

CraftTutorial_Movement_GoToCraftTable:
    walk_down
    walk_down
    walk_right
    step_end

CraftTutorial_Movement_GoBackToGrass:
    walk_left
    walk_up
    walk_up
    face_right
    step_end

CraftTutorial_Movement_CollectPayment:
    walk_left
    face_up
    step_end

CraftTutorial_Movement_GoBackToGrassAfterTutorial:
    walk_left
    walk_up
    walk_up
    walk_up
    face_right
    step_end

CraftTutorial_Movement_GoToCraftTable2:
    walk_down
    walk_down
    walk_down
    walk_right
    walk_right
    face_left
    step_end

CraftTutorial_Movement_FollowToCraftTableSouth:
    face_right
    lock_facing_direction
    walk_left
    unlock_facing_direction
    walk_right
    walk_down
    walk_down
    walk_right
    step_end

CraftTutorial_Movement_FollowToCraftTableNorth:
    walk_down
    walk_down
    walk_down
    walk_down
    walk_right
    step_end

CraftTutorial_Movement_FollowToCraftTableWest:
    walk_right
    walk_down
    walk_down
    walk_down
    walk_right
    step_end

CraftTutorial_Movement_FollowToCraftTableFinish:
    walk_up
    face_right
    step_end

CraftTutorial_Movement_FollowToCraftTableEast:
    walk_left
    walk_down
    walk_down
    walk_down
    walk_right
    step_end

CraftTutorial_Movement_GoToCraftTableMovePlayer1:
    walk_down
    walk_down
    face_right
    step_end

CraftTutorial_Movement_GoToCraftTableMovePlayer2:
    face_up
    lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

CraftTutorial_Movement_GoToCraftTableMovePlayer3:
    delay_16
    walk_right
    step_end

CraftTutorial_Text_ItsAFlowerBox:
    .string "It's a simple flower box and paver\n"
    .string "stone.\p"
    .string "Someone's tools are laying there...$"

CraftTutorial_Text_HeyLikeMySetup:
    .string "Hey! Like my setup?$"

CraftTutorial_Text_HeyLikeMySetup2:
    .string "To the layman it might look like a simple\n"
    .string "flower box and paver stone,\p"
    .string "But this is actually the proud WORK\n"
    .string "STATION of my ANTIDOTE crafting.\p"
    .string "As part of my income, I make ANTIDOTE\n"
    .string "for the OLDALE POKéMART!$"

CraftTutorial_Text_FindAPechaAndPotion:
    .string "Tell you what. I've got a bit of extra\n"
    .string "time today, so if you're interested\l"
    .string "I can show you how to CRAFT.\p"
    .string "Find me a PECHA BERRY and a POTION, and\n"
    .string "I'll show you how to put two and two\l"
    .string "together!\p...for a small price.\p"
    .string "Sounds like a great deal, no? Find\n"
    .string "those items and meet me back here.\p"
    .string "I think I saw some PECHA BERRIES\n"
    .string "growing nearby.$"

CraftTutorial_Text_ItsAWorkStation:
    .string "It's a WORK STATION.$"

CraftTutorial_Text_YouGotTheStuff:
    .string "...You got the stuff?\n"
    .string "Were you followed?\p"
    .string "Haha, just kidding! Glad you were able to\n"
    .string "get everything.\l"
    .string "Let's do it - follow me!$"

CraftTutorial_Text_CraftingIsSimple:
    .string "Crafting ANTIDOTE is simple, provided\n"
    .string "you know what you're doing and\l"
    .string "have all the right ITEMS.$"
    
CraftTutorial_Text_ChooseSpaceAndAddItem:
    .string "When you use the WORK STATION, find an\n"
    .string "empty space and add an item from your\l"
    .string "BAG.\p"
    .string "If you want to manage multiple ITEMS at\n"
    .string "once, it can be a bit of a handful -\p"
    .string "With one hand, HOLD open the bag. With\n"
    .string "the other, you SELECT what you want\p"
    .string "AND remember: add items (A for add)\n"
    .string "or put it back in the bag (B for BAG)!\p"
    .string "Pretty simple, right? Give it a try!$"

CraftTutorial_Text_NeedMoreItems:
    .string "How's the item hunt going?\p"
    .string "...\p"
    .string "If you want me to show you how CRAFT\n"
    .string "my famous ANTIDOTE,\l"
    .string "you'll need a PECHA BERRY and a POTION.$"

CraftTutorial_Text_WantCraftingInstructions:
    .string "Want some pointers on how to\n"
    .string "craft with a WORK STATION?$"

CraftTutorial_Text_SpringWaterIsNice:
    .string "The spring water in this pond is some of\n"
    .string "the best in the PETALBURG watershed.\p"
    .string "It's perfect for keeping my WORK\n"
    .string "STATION clear of all the sticky PECHA\l"
    .string "juice...$"

CraftTutorial_Text_ThatsIt:
    .string "That's all there is to it! As for\l"
    .string "payment, I'll be happy with two of those\l"
    .string "ANTIDOTE.\p"
    .string "And as a bonus, I'll let you use my WORK\n"
    .string "STATION any time.\p"
    .string "If you ever need a reminder of how to\n"
    .string "CRAFT, I'll be happy to explain again.$"

CraftTutorial_Text_PlayerGaveAntidote:
    .string "{PLAYER} gave two ANTIDOTE as payment.$"

CraftTutorial_Text_PleasureDoingBusiness:
    .string "Pleasure doing business with ya.\p"
    .string "Remember, if anyone asks you\n"
    .string "where you learned this stuff,\l"
    .string "it wasn't from me. Capiche?\p"
    .string "...\p"
    .string "Only joking!\p"
    .string "I'll be around if you need me.\p"
    .string "This may be my working spot, but I'm\n"
    .string "also hoping to find a MARILL to train up\l"
    .string "as my assistant!$"

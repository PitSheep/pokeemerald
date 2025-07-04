OldaleTown_Hunter_House_MapScripts::
	.byte 0

OldaleTown_Hunter_House_EventScript_Totem::
	msgbox OldaleTown_Hunter_House_Text_Totem, MSGBOX_DEFAULT
	releaseall
	end

OldaleTown_Hunter_House_Text_Totem:
	.string "Good morning {PLAYER}.\n"
	.string "Welcome to HUNTER HOUSE.\p"
	.string "In the Hunter's House\n"
	.string "you can find:\p"
	.string "CRAFTING STATION in the BOX\n"
	.string "on the right.\p"
	.string "RED.\p"
	.string "Hunter Money Corner.\p"
	.string "3 Move Tutor.\p"
	.string "4 Event Ticket Vendor.\p"
	.string "ABILITY GURU.\p"
	.string "The Receptionist.\p"
	.string "PC.\p"
	.string "Have a good hunting!$"

OldaleTown_Hunter_House_EventScript_Guide::
	lock
	faceplayer
	msgbox OldaleTown_Hunter_House_Text_GuideAdvice, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_GuideAdvice:
	.string "Good morning {PLAYER}.\n"
	.string "Welcome to HUNTER HOUSE.\p"
	.string "Select a Pokemon via STATUE near him\n"
	.string "to receive information\p"
	.string "on his latest sighting.\n"
	.string "Then go there for hunting.\p"
	.string "Remember that you must insert\n"
	.string "a MASTER BALL to do this!\p"
	.string "Have a good hunting!$"

OldaleTown_Hunter_House_EventScript_Craft::
	lock
	faceplayer
    msgbox OldaleTown_Hunter_House_Text_Craft, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, OldaleTown_Hunter_House_Craft_yes
    msgbox OldaleTown_Hunter_House_Text_Craft_no, MSGBOX_DEFAULT
    releaseall
    end
	
OldaleTown_Hunter_House_Text_Craft:
	.string "Good morning {PLAYER}.\p"
	.string "Welcome to HUNTER HOUSE.\p"
	.string "the BOX nearby...\n"
	.string "is the crafting station.\p"
	.string "Want some pointers on how to\n"
    .string "craft with a WORK STATION?$"
	
OldaleTown_Hunter_House_Craft_yes:
    msgbox OldaleTown_Hunter_House_Text_Craft_yes, MSGBOX_DEFAULT
    closemessage
    releaseall
    end
	
OldaleTown_Hunter_House_Text_Craft_yes:
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
	
OldaleTown_Hunter_House_Text_Craft_no:
	.string "It can create many things,\n"
	.string "try combining stones with berries\p"
	.string "and who knows how many other\n"
	.string "things you can combine$"

OldaleTown_Hunter_House_Text_Monster_Quest_Giveup:
	.string "Do you want to cancel\n"
	.string "the current hunt?$"

OldaleTown_Hunter_House_Text_Monster_Quest_Cancelled:
	.string "Hunt cancelled.\n"
	.string "Thank you.$"

OldaleTown_Hunter_House_EventScript_Reception::
	lock
	faceplayer
	goto_if_set FLAG_HUNTER_HOUSE_IN_PROGRESS, OldaleTown_Hunter_House_EventScript_Already_Hunting_List
	msgbox OldaleTown_Hunter_House_Text_GuideAdvice, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_Already_Hunting_List:
	msgbox OldaleTown_Hunter_House_Text_Already_Hunting, MSGBOX_DEFAULT
	goto_if_unset FLAG_HUNTER_HOUSE_1, OldaleTown_Hunter_House_EventScript_Already_Hunting_1
	goto_if_unset FLAG_HUNTER_HOUSE_2, OldaleTown_Hunter_House_EventScript_Already_Hunting_2
	goto_if_unset FLAG_HUNTER_HOUSE_3, OldaleTown_Hunter_House_EventScript_Already_Hunting_3
	goto_if_unset FLAG_HUNTER_HOUSE_4, OldaleTown_Hunter_House_EventScript_Already_Hunting_4
	goto_if_unset FLAG_HUNTER_HOUSE_5, OldaleTown_Hunter_House_EventScript_Already_Hunting_5
	goto_if_unset FLAG_HUNTER_HOUSE_6, OldaleTown_Hunter_House_EventScript_Already_Hunting_6
	goto_if_unset FLAG_HUNTER_HOUSE_7, OldaleTown_Hunter_House_EventScript_Already_Hunting_7
	goto_if_unset FLAG_HUNTER_HOUSE_8, OldaleTown_Hunter_House_EventScript_Already_Hunting_8
	goto_if_unset FLAG_HUNTER_HOUSE_9, OldaleTown_Hunter_House_EventScript_Already_Hunting_9
	goto_if_unset FLAG_HUNTER_HOUSE_10, OldaleTown_Hunter_House_EventScript_Already_Hunting_10
	goto_if_unset FLAG_HUNTER_HOUSE_11, OldaleTown_Hunter_House_EventScript_Already_Hunting_11
	goto_if_unset FLAG_HUNTER_HOUSE_12, OldaleTown_Hunter_House_EventScript_Already_Hunting_12
	goto_if_unset FLAG_HUNTER_HOUSE_13, OldaleTown_Hunter_House_EventScript_Already_Hunting_13
	goto_if_unset FLAG_HUNTER_HOUSE_14, OldaleTown_Hunter_House_EventScript_Already_Hunting_14
	goto_if_unset FLAG_HUNTER_HOUSE_15, OldaleTown_Hunter_House_EventScript_Already_Hunting_15
	goto_if_unset FLAG_HUNTER_HOUSE_16, OldaleTown_Hunter_House_EventScript_Already_Hunting_16
	release
	end

OldaleTown_Hunter_House_EventScript_Already_Hunting_1:
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_1, MSGBOX_DEFAULT
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Giveup, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Cancel_Hunting_1
	release
	end

OldaleTown_Hunter_House_EventScript_Cancel_Hunting_1:
	clearflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	setflag FLAG_HUNTER_HOUSE_1
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Cancelled, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_Already_Hunting_2:
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_2, MSGBOX_DEFAULT
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Giveup, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Cancel_Hunting_2
	release
	end

OldaleTown_Hunter_House_EventScript_Cancel_Hunting_2:
	clearflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	setflag FLAG_HUNTER_HOUSE_2
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Cancelled, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_Already_Hunting_3:
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_3, MSGBOX_DEFAULT
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Giveup, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Cancel_Hunting_3
	release
	end

OldaleTown_Hunter_House_EventScript_Cancel_Hunting_3:
	clearflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	setflag FLAG_HUNTER_HOUSE_3
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Cancelled, MSGBOX_DEFAULT
	release
	end
	
OldaleTown_Hunter_House_EventScript_Already_Hunting_4:
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_4, MSGBOX_DEFAULT
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Giveup, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Cancel_Hunting_4
	release
	end

OldaleTown_Hunter_House_EventScript_Cancel_Hunting_4:
	clearflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	setflag FLAG_HUNTER_HOUSE_4
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Cancelled, MSGBOX_DEFAULT
	release
	end
	
OldaleTown_Hunter_House_EventScript_Already_Hunting_5:
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_5, MSGBOX_DEFAULT
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Giveup, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Cancel_Hunting_5
	release
	end

OldaleTown_Hunter_House_EventScript_Cancel_Hunting_5:
	clearflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	setflag FLAG_HUNTER_HOUSE_5
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Cancelled, MSGBOX_DEFAULT
	release
	end
	
OldaleTown_Hunter_House_EventScript_Already_Hunting_6:
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_6, MSGBOX_DEFAULT
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Giveup, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Cancel_Hunting_6
	release
	end

OldaleTown_Hunter_House_EventScript_Cancel_Hunting_6:
	clearflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	setflag FLAG_HUNTER_HOUSE_6
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Cancelled, MSGBOX_DEFAULT
	release
	end
	
OldaleTown_Hunter_House_EventScript_Already_Hunting_7:
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_7, MSGBOX_DEFAULT
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Giveup, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Cancel_Hunting_7
	release
	end

OldaleTown_Hunter_House_EventScript_Cancel_Hunting_7:
	clearflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	setflag FLAG_HUNTER_HOUSE_7
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Cancelled, MSGBOX_DEFAULT
	release
	end
	
OldaleTown_Hunter_House_EventScript_Already_Hunting_8:
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_8, MSGBOX_DEFAULT
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Giveup, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Cancel_Hunting_8
	release
	end

OldaleTown_Hunter_House_EventScript_Cancel_Hunting_8:
	clearflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	setflag FLAG_HUNTER_HOUSE_8
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Cancelled, MSGBOX_DEFAULT
	release
	end
	
OldaleTown_Hunter_House_EventScript_Already_Hunting_9:
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_9, MSGBOX_DEFAULT
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Giveup, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Cancel_Hunting_9
	release
	end

OldaleTown_Hunter_House_EventScript_Cancel_Hunting_9:
	clearflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	setflag FLAG_HUNTER_HOUSE_9
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Cancelled, MSGBOX_DEFAULT
	release
	end
	
OldaleTown_Hunter_House_EventScript_Already_Hunting_10:
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_10, MSGBOX_DEFAULT
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Giveup, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Cancel_Hunting_10
	release
	end

OldaleTown_Hunter_House_EventScript_Cancel_Hunting_10:
	clearflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	setflag FLAG_HUNTER_HOUSE_10
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Cancelled, MSGBOX_DEFAULT
	release
	end
	
OldaleTown_Hunter_House_EventScript_Already_Hunting_11:
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_11, MSGBOX_DEFAULT
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Giveup, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Cancel_Hunting_11
	release
	end

OldaleTown_Hunter_House_EventScript_Cancel_Hunting_11:
	clearflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	setflag FLAG_HUNTER_HOUSE_11
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Cancelled, MSGBOX_DEFAULT
	release
	end
	
OldaleTown_Hunter_House_EventScript_Already_Hunting_12:
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_12, MSGBOX_DEFAULT
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Giveup, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Cancel_Hunting_12
	release
	end

OldaleTown_Hunter_House_EventScript_Cancel_Hunting_12:
	clearflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	setflag FLAG_HUNTER_HOUSE_12
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Cancelled, MSGBOX_DEFAULT
	release
	end
	
OldaleTown_Hunter_House_EventScript_Already_Hunting_13:
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_13, MSGBOX_DEFAULT
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Giveup, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Cancel_Hunting_13
	release
	end

OldaleTown_Hunter_House_EventScript_Cancel_Hunting_13:
	clearflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	setflag FLAG_HUNTER_HOUSE_13
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Cancelled, MSGBOX_DEFAULT
	release
	end
	
OldaleTown_Hunter_House_EventScript_Already_Hunting_14:
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_14, MSGBOX_DEFAULT
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Giveup, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Cancel_Hunting_14
	release
	end

OldaleTown_Hunter_House_EventScript_Cancel_Hunting_14:
	clearflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	setflag FLAG_HUNTER_HOUSE_14
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Cancelled, MSGBOX_DEFAULT
	release
	end
	
OldaleTown_Hunter_House_EventScript_Already_Hunting_15:
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_15, MSGBOX_DEFAULT
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Giveup, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Cancel_Hunting_15
	release
	end

OldaleTown_Hunter_House_EventScript_Cancel_Hunting_15:
	clearflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	setflag FLAG_HUNTER_HOUSE_15
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Cancelled, MSGBOX_DEFAULT
	release
	end
	
OldaleTown_Hunter_House_EventScript_Already_Hunting_16:
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_16, MSGBOX_DEFAULT
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Giveup, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Cancel_Hunting_16
	release
	end

OldaleTown_Hunter_House_EventScript_Cancel_Hunting_16:
	clearflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	setflag FLAG_HUNTER_HOUSE_16
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest_Cancelled, MSGBOX_DEFAULT
	release
	end
	
OldaleTown_Hunter_House_Text_Monster_Quest:
	.string "Wanna try Hunt?\n"
	.string "Insert 1 MASTER BALL!$"

OldaleTown_Hunter_House_Text_Monster_NoMasterball:
	.string "You don't have any MasterBall.$"

OldaleTown_Hunter_House_EventScript_Answer_No:
	msgbox OldaleTown_Hunter_House_Text_Answer_No, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_Answer_No:
	.string "Well Hunter,\n"
	.string "come back when you are ready...$"

OldaleTown_Hunter_House_EventScript_Already_Hunting:
	msgbox OldaleTown_Hunter_House_Text_Already_Hunting, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_Already_Hunting:
	.string "You've already started a hunt.\n"
	.string "You can't start another hunt$"

OldaleTown_Hunter_House_EventScript_Monster_1::
	lock
	goto_if_set FLAG_HUNTER_HOUSE_IN_PROGRESS, OldaleTown_Hunter_House_EventScript_Already_Hunting
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Answer_Yes_1
	release
	end

OldaleTown_Hunter_House_EventScript_Answer_Yes_1:
	checkitem ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_Hunter_House_EventScript_Start_Hunt_1
	msgbox OldaleTown_Hunter_House_Text_Monster_NoMasterball, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_Start_Hunt_1:
	removeitem ITEM_MASTER_BALL
	clearflag FLAG_HUNTER_HOUSE_1
	setflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_1, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_Start_Hunt_1:
	.string "Hunting Mewtwo:\p"
	.string "I see home...\n"
	.string "I see a corner...\p"
	.string "I see it!$"

OldaleTown_Hunter_House_EventScript_Monster_2::
	lock
	goto_if_set FLAG_HUNTER_HOUSE_IN_PROGRESS, OldaleTown_Hunter_House_EventScript_Already_Hunting
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Answer_Yes_2
	release
	end

OldaleTown_Hunter_House_EventScript_Answer_Yes_2:
	checkitem ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_Hunter_House_EventScript_Start_Hunt_2
	msgbox OldaleTown_Hunter_House_Text_Monster_NoMasterball, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_Start_Hunt_2:
	removeitem ITEM_MASTER_BALL
	clearflag FLAG_HUNTER_HOUSE_2
	setflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_2, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_Start_Hunt_2:
	.string "Hunting Mew:\p"
	.string "close to 4...\n"
	.string "lose to the champion...\p"
	.string "I can see it!$"

OldaleTown_Hunter_House_EventScript_Monster_3::
	lock
	goto_if_set FLAG_HUNTER_HOUSE_IN_PROGRESS, OldaleTown_Hunter_House_EventScript_Already_Hunting
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Answer_Yes_3
	release
	end

OldaleTown_Hunter_House_EventScript_Answer_Yes_3:
	checkitem ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_Hunter_House_EventScript_Start_Hunt_3
	msgbox OldaleTown_Hunter_House_Text_Monster_NoMasterball, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_Start_Hunt_3:
	removeitem ITEM_MASTER_BALL
	clearflag FLAG_HUNTER_HOUSE_3
	setflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_3, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_Start_Hunt_3:
	.string "Hunting REGIROCK:\p"
	.string "I see six rocks and an entrance.\n"
	.string "I see his puzzle to solve...\p"
	.string "I see it!$"

OldaleTown_Hunter_House_EventScript_Monster_4::
	lock
	goto_if_set FLAG_HUNTER_HOUSE_IN_PROGRESS, OldaleTown_Hunter_House_EventScript_Already_Hunting
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Answer_Yes_4
	release
	end

OldaleTown_Hunter_House_EventScript_Answer_Yes_4:
	checkitem ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_Hunter_House_EventScript_Start_Hunt_4
	msgbox OldaleTown_Hunter_House_Text_Monster_NoMasterball, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_Start_Hunt_4:
	removeitem ITEM_MASTER_BALL
	clearflag FLAG_HUNTER_HOUSE_4
	setflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_4, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_Start_Hunt_4:
	.string "Hunting REGICE:\p"
	.string "I see six rocks and an entrance.\n"
	.string "I see his puzzle to solve...\p"
	.string "I see it!$"

OldaleTown_Hunter_House_EventScript_Monster_5::
	lock
	goto_if_set FLAG_HUNTER_HOUSE_IN_PROGRESS, OldaleTown_Hunter_House_EventScript_Already_Hunting
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Answer_Yes_5
	release
	end

OldaleTown_Hunter_House_EventScript_Answer_Yes_5:
	checkitem ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_Hunter_House_EventScript_Start_Hunt_5
	msgbox OldaleTown_Hunter_House_Text_Monster_NoMasterball, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_Start_Hunt_5:
	removeitem ITEM_MASTER_BALL
	clearflag FLAG_HUNTER_HOUSE_5
	setflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_5, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_Start_Hunt_5:
	.string "Hunting REGISTEEL:\p"
	.string "I see six rocks and an entrance.\n"
	.string "I see his puzzle to solve...\p"
	.string "I see it!$"

OldaleTown_Hunter_House_EventScript_Monster_6::
	lock
	goto_if_set FLAG_HUNTER_HOUSE_IN_PROGRESS, OldaleTown_Hunter_House_EventScript_Already_Hunting
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Answer_Yes_6
	release
	end

OldaleTown_Hunter_House_EventScript_Answer_Yes_6:
	checkitem ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_Hunter_House_EventScript_Start_Hunt_6
	msgbox OldaleTown_Hunter_House_Text_Monster_NoMasterball, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_Start_Hunt_6:
	removeitem ITEM_MASTER_BALL
	clearflag FLAG_HUNTER_HOUSE_6
	setflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_6, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_Start_Hunt_6:
	.string "Hunting LATIAS:$"
	.string "I see red water...\n"
	.string "I see Cable Car Station...\p"
	.string "I see it!$"

OldaleTown_Hunter_House_EventScript_Monster_7::
	lock
	goto_if_set FLAG_HUNTER_HOUSE_IN_PROGRESS, OldaleTown_Hunter_House_EventScript_Already_Hunting
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Answer_Yes_7
	release
	end

OldaleTown_Hunter_House_EventScript_Answer_Yes_7:
	checkitem ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_Hunter_House_EventScript_Start_Hunt_7
	msgbox OldaleTown_Hunter_House_Text_Monster_NoMasterball, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_Start_Hunt_7:
	removeitem ITEM_MASTER_BALL
	clearflag FLAG_HUNTER_HOUSE_7
	setflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_7, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_Start_Hunt_7:
	.string "Hunting LATIOS:\p"
	.string "I see the sky above...\n"
	.string "I see under many gravestones...\p"
	.string "I see it!$"

OldaleTown_Hunter_House_EventScript_Monster_8::
	lock
	goto_if_set FLAG_HUNTER_HOUSE_IN_PROGRESS, OldaleTown_Hunter_House_EventScript_Already_Hunting
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Answer_Yes_8
	release
	end

OldaleTown_Hunter_House_EventScript_Answer_Yes_8:
	checkitem ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_Hunter_House_EventScript_Start_Hunt_8
	msgbox OldaleTown_Hunter_House_Text_Monster_NoMasterball, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_Start_Hunt_8:
	removeitem ITEM_MASTER_BALL
	clearflag FLAG_HUNTER_HOUSE_8
	setflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_8, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_Start_Hunt_8:
	.string "Hunting KYOGRE:\p"
	.string "I see it close to 4...\n"
	.string "I see a huge waterfall...\p"
	.string "I see it!$"

OldaleTown_Hunter_House_EventScript_Monster_9::
	lock
	goto_if_set FLAG_HUNTER_HOUSE_IN_PROGRESS, OldaleTown_Hunter_House_EventScript_Already_Hunting
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Answer_Yes_9
	release
	end

OldaleTown_Hunter_House_EventScript_Answer_Yes_9:
	checkitem ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_Hunter_House_EventScript_Start_Hunt_9
	msgbox OldaleTown_Hunter_House_Text_Monster_NoMasterball, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_Start_Hunt_9:
	removeitem ITEM_MASTER_BALL
	clearflag FLAG_HUNTER_HOUSE_9
	setflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_9, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_Start_Hunt_9:
	.string "Hunting CELEBI:\p"
	.string "I see two wheels...\n"
	.string "I see many wheels...\p"
	.string "I see it!$"

OldaleTown_Hunter_House_EventScript_Monster_10::
	lock
	goto_if_set FLAG_HUNTER_HOUSE_IN_PROGRESS, OldaleTown_Hunter_House_EventScript_Already_Hunting
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Answer_Yes_10
	release
	end

OldaleTown_Hunter_House_EventScript_Answer_Yes_10:
	checkitem ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_Hunter_House_EventScript_Start_Hunt_10
	msgbox OldaleTown_Hunter_House_Text_Monster_NoMasterball, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_Start_Hunt_10:
	removeitem ITEM_MASTER_BALL
	clearflag FLAG_HUNTER_HOUSE_10
	setflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_10, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_Start_Hunt_10:
	.string "Hunting GROUDON:\p"
	.string "I see a tunnel nearby with\n"
	.string "a passage that was closed...\p"
	.string "I see a Blackglasses...\n"
	.string "I see it!$"

OldaleTown_Hunter_House_EventScript_Monster_11::
	lock
	goto_if_set FLAG_HUNTER_HOUSE_IN_PROGRESS, OldaleTown_Hunter_House_EventScript_Already_Hunting
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Answer_Yes_11
	release
	end

OldaleTown_Hunter_House_EventScript_Answer_Yes_11:
	checkitem ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_Hunter_House_EventScript_Start_Hunt_11
	msgbox OldaleTown_Hunter_House_Text_Monster_NoMasterball, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_Start_Hunt_11:
	removeitem ITEM_MASTER_BALL
	clearflag FLAG_HUNTER_HOUSE_11
	setflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_11, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_Start_Hunt_11:
	.string "Hunting RAYQUAZA:\p"
	.string "I see tall grass surrounded by trees.\n"
	.string "I see TM01...\p"
	.string "I see it!$"

OldaleTown_Hunter_House_EventScript_Monster_12::
	lock
	goto_if_set FLAG_HUNTER_HOUSE_IN_PROGRESS, OldaleTown_Hunter_House_EventScript_Already_Hunting
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Answer_Yes_12
	release
	end

OldaleTown_Hunter_House_EventScript_Answer_Yes_12:
	checkitem ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_Hunter_House_EventScript_Start_Hunt_12
	msgbox OldaleTown_Hunter_House_Text_Monster_NoMasterball, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_Start_Hunt_12:
	removeitem ITEM_MASTER_BALL
	clearflag FLAG_HUNTER_HOUSE_12
	setflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_12, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_Start_Hunt_12:
	.string "Hunting JIRACHI:\p"
	.string "I see the sky above...\n"
	.string "I see below the DEPARTMENT STORE...\p"
	.string "I see!$"

OldaleTown_Hunter_House_EventScript_Monster_13::
	lock
	goto_if_set FLAG_HUNTER_HOUSE_IN_PROGRESS, OldaleTown_Hunter_House_EventScript_Already_Hunting
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Answer_Yes_13
	release
	end

OldaleTown_Hunter_House_EventScript_Answer_Yes_13:
	checkitem ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_Hunter_House_EventScript_Start_Hunt_13
	msgbox OldaleTown_Hunter_House_Text_Monster_NoMasterball, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_Start_Hunt_13:
	removeitem ITEM_MASTER_BALL
	clearflag FLAG_HUNTER_HOUSE_13
	setflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_13, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_Start_Hunt_13:
	.string "Hunting DEOXYS:\p"
	.string "I can clearly hear a...\n"
	.string "rocket launch...\p"
	.string "I can hear it!$"

OldaleTown_Hunter_House_EventScript_Monster_14::
	lock
	goto_if_set FLAG_HUNTER_HOUSE_IN_PROGRESS, OldaleTown_Hunter_House_EventScript_Already_Hunting
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Answer_Yes_14
	release
	end

OldaleTown_Hunter_House_EventScript_Answer_Yes_14:
	checkitem ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_Hunter_House_EventScript_Start_Hunt_14
	msgbox OldaleTown_Hunter_House_Text_Monster_NoMasterball, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_Start_Hunt_14:
	removeitem ITEM_MASTER_BALL
	clearflag FLAG_HUNTER_HOUSE_14
	setflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_14, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_Start_Hunt_14:
	.string "Hunting ENTEI:\p"
	.string "You need to CUT in the\n"
	.string "first ....Woods$"

OldaleTown_Hunter_House_EventScript_Monster_15::
	lock
	goto_if_set FLAG_HUNTER_HOUSE_IN_PROGRESS, OldaleTown_Hunter_House_EventScript_Already_Hunting
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Answer_Yes_15
	release
	end

OldaleTown_Hunter_House_EventScript_Answer_Yes_15:
	checkitem ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_Hunter_House_EventScript_Start_Hunt_15
	msgbox OldaleTown_Hunter_House_Text_Monster_NoMasterball, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_Start_Hunt_15:
	removeitem ITEM_MASTER_BALL
	clearflag FLAG_HUNTER_HOUSE_15
	setflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_15, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_Start_Hunt_15:
	.string "Hunting RAIKOU:\p"
	.string "I see a mirage...\n"
	.string "I see a sandstorm...\p"
	.string "I see it!$"

OldaleTown_Hunter_House_EventScript_Monster_16::
	lock
	goto_if_set FLAG_HUNTER_HOUSE_IN_PROGRESS, OldaleTown_Hunter_House_EventScript_Already_Hunting
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Answer_Yes_16
	release
	end

OldaleTown_Hunter_House_EventScript_Answer_Yes_16:
	checkitem ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_Hunter_House_EventScript_Start_Hunt_16
	msgbox OldaleTown_Hunter_House_Text_Monster_NoMasterball, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_Start_Hunt_16:
	removeitem ITEM_MASTER_BALL
	clearflag FLAG_HUNTER_HOUSE_16
	setflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt_16, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_Start_Hunt_16:
	.string "Hunting SUICUNE:\p"
	.string "I see the Winstrate family...\n"
	.string "then I see some water...\p"
	.string "then I see him...$"


OldaleTown_Hunter_House_Buy_Ticket_Answer_No:
	msgbox OldaleTown_Hunter_House_Text_Answer_No, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_Ticket_Thx:
	.string "Thank you for your purchase.\p"
	.string "Happy Adventure!$"

OldaleTown_Hunter_House_Ticket_Already:
	msgbox OldaleTown_Hunter_House_Text_Ticket_Already, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_Ticket_Already:
	.string "You've already this Ticket.\n"
	.string "Use it before buying another one.$"

OldaleTown_Hunter_House_EventScript_Ticket_1::
	lock
	goto_if_set FLAG_SHOWN_EON_TICKET, OldaleTown_Hunter_House_Ticket_Already
	msgbox OldaleTown_Hunter_House_Text_Buy_Ticket_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_Buy_Ticket_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Buy_Ticket_Answer_Yes_1
	release
	end

OldaleTown_Hunter_House_Text_Buy_Ticket_1:
	.string "Wanna buy Eon Ticket?\n"
	.string "Costs 1 MASTER BALL!$"

OldaleTown_Hunter_House_EventScript_Buy_Ticket_Answer_Yes_1:
	checkitem ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_Hunter_House_EventScript_Give_Ticket_1
	msgbox OldaleTown_Hunter_House_Text_Monster_NoMasterball, MSGBOX_DEFAULT
	release
	end
	
OldaleTown_Hunter_House_EventScript_Give_Ticket_1:
	removeitem ITEM_MASTER_BALL
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	setflag FLAG_SHOWN_EON_TICKET
	giveitem ITEM_EON_TICKET
	msgbox OldaleTown_Hunter_House_Text_Ticket_Thx, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_Ticket_2::
	lock
	goto_if_set FLAG_SHOWN_AURORA_TICKET, OldaleTown_Hunter_House_Ticket_Already
	msgbox OldaleTown_Hunter_House_Text_Buy_Ticket_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_Buy_Ticket_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Buy_Ticket_Answer_Yes_2
	release
	end

OldaleTown_Hunter_House_Text_Buy_Ticket_2:
	.string "Wanna buy Aurora Ticket?\n"
	.string "Costs 1 MASTER BALL!$"

OldaleTown_Hunter_House_EventScript_Buy_Ticket_Answer_Yes_2:
	checkitem ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_Hunter_House_EventScript_Give_Ticket_2
	msgbox OldaleTown_Hunter_House_Text_Monster_NoMasterball, MSGBOX_DEFAULT
	release
	end
	
OldaleTown_Hunter_House_EventScript_Give_Ticket_2:
	removeitem ITEM_MASTER_BALL
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_SHOWN_AURORA_TICKET
	giveitem ITEM_AURORA_TICKET
	msgbox OldaleTown_Hunter_House_Text_Ticket_Thx, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_Ticket_3::
	lock
	goto_if_set FLAG_SHOWN_MYSTIC_TICKET, OldaleTown_Hunter_House_Ticket_Already
	msgbox OldaleTown_Hunter_House_Text_Buy_Ticket_3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_Buy_Ticket_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Buy_Ticket_Answer_Yes_3
	release
	end

OldaleTown_Hunter_House_Text_Buy_Ticket_3:
	.string "Wanna buy Mystic Ticket?\n"
	.string "Costs 1 MASTER BALL!$"

OldaleTown_Hunter_House_EventScript_Buy_Ticket_Answer_Yes_3:
	checkitem ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_Hunter_House_EventScript_Give_Ticket_3
	msgbox OldaleTown_Hunter_House_Text_Monster_NoMasterball, MSGBOX_DEFAULT
	release
	end
	
OldaleTown_Hunter_House_EventScript_Give_Ticket_3:
	removeitem ITEM_MASTER_BALL
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_SHOWN_MYSTIC_TICKET
	giveitem ITEM_MYSTIC_TICKET
	msgbox OldaleTown_Hunter_House_Text_Ticket_Thx, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_Ticket_4::
	lock
	goto_if_set FLAG_SHOWN_OLD_SEA_MAP, OldaleTown_Hunter_House_Ticket_Already
	msgbox OldaleTown_Hunter_House_Text_Buy_Ticket_4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_Buy_Ticket_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Buy_Ticket_Answer_Yes_4
	release
	end

OldaleTown_Hunter_House_Text_Buy_Ticket_4:
	.string "Wanna buy Old Sea Map?\n"
	.string "Costs 1 MASTER BALL!$"

OldaleTown_Hunter_House_EventScript_Buy_Ticket_Answer_Yes_4:
	checkitem ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_Hunter_House_EventScript_Give_Ticket_4
	msgbox OldaleTown_Hunter_House_Text_Monster_NoMasterball, MSGBOX_DEFAULT
	release
	end
	
OldaleTown_Hunter_House_EventScript_Give_Ticket_4:
	removeitem ITEM_MASTER_BALL
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_SHOWN_OLD_SEA_MAP
	giveitem ITEM_OLD_SEA_MAP
	msgbox OldaleTown_Hunter_House_Text_Ticket_Thx, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_name_rate::
call SlateportCity_NameRatersHouse_EventScript_NameRater
end










OldaleTown_Hunter_House_EventScript_AbilityChange::
	special ShowBattlePointsWindow
	setvar VAR_0x8008, 50
	msgbox OldaleTown_Hunter_House_EventScript_AbilityChange_intro_text, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_AbilityChange_cancel
	goto OldaleTown_Hunter_House_EventScript_AbilityChange_yes
	release
	end


OldaleTown_Hunter_House_EventScript_AbilityChange_yes::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, OldaleTown_Hunter_House_EventScript_AbilityChange_chose
	msgbox OldaleTown_Hunter_House_EventScript_AbilityChange_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

OldaleTown_Hunter_House_EventScript_AbilityChange_Text_DontHaveEnoughPoints:
	.string "I'm so sorry…\n"
	.string "You don't have enough Battle Points…$"

OldaleTown_Hunter_House_EventScript_AbilityChange_chose::
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, OldaleTown_Hunter_House_EventScript_AbilityChange_success
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, OldaleTown_Hunter_House_EventScript_AbilityChange_cancel
	end

OldaleTown_Hunter_House_EventScript_AbilityChange_cancel::
	lock
	faceplayer
	msgbox OldaleTown_Hunter_House_EventScript_AbilityChange_cancel_text, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

OldaleTown_Hunter_House_EventScript_AbilityChange_cancel_text:
	.string "Oh, have you cange idea?!\p"
	.string "no problem...\n"
	.string "come back any time.$"

OldaleTown_Hunter_House_EventScript_AbilityChange_intro_text:
	.string "Hi {PLAYER},\n"
	.string "I'm the ABILITY GURU!,\p"
	.string "I can change the special ability\n"
	.string "of the pokemon you want,\p"
	.string "in exchange for 50 BP, of course.\n"
	.string "do you like the exchange?.$"

OldaleTown_Hunter_House_EventScript_AbilityChange_success::
	special SwitchMonAbility
	copyvar VAR_0x8004, VAR_0x8008
	special ShowBattlePointsWindow
	special TakeFrontierBattlePoints
	special UpdateBattlePointsWindow
	lock
	faceplayer
	msgbox OldaleTown_Hunter_House_EventScript_AbilityChange_success_text, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

OldaleTown_Hunter_House_EventScript_AbilityChange_success_text:
	.string "thanks for the deal!\n"
	.string "come back any time.$"
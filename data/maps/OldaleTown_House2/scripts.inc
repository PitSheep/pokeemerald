OldaleTown_House2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_House2_OnTransition
	.byte 0

OldaleTown_House2_OnTransition:
	special UpdateIncubatorObjectSprites
	end

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "Welcome to the HUNTER CARE!\p"
	.string "Put one POKéMON in each of the two\n"
	.string "INCUBATORS on the left.\p"
	.string "If they are compatible, an EGG can\n"
	.string "be made from them.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Then use the machine on the right.\n"
	.string "Pay 8 BP and the EGG hatches at once!\p"
	.string "Your POKéMON stay in the INCUBATORS,\n"
	.string "so you can make more EGGS.\p"
	.string "If your party is full, the new POKéMON\n"
	.string "can be sent to the PC.$"

OldaleTown_House2_EventScript_Incubatore_1::
	lock
	faceplayer
	specialvar VAR_RESULT, IsIncubatorOccupied
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_House2_EventScript_Incubatore_1_RetrievePrompt
	msgbox OldaleTown_House2_Text_Incubatore_DepositPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, OldaleTown_House2_EventScript_Incubatore_1_Deposit
	goto OldaleTown_House2_EventScript_Incubatore_1_Cancel
	end

OldaleTown_House2_EventScript_Incubatore_1_Deposit::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, OldaleTown_House2_EventScript_Incubatore_1_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, OldaleTown_House2_EventScript_Incubatore_1_OnlyTwoAliveMons
	msgbox OldaleTown_House2_Text_Incubatore_ChoosePokemon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, OldaleTown_House2_EventScript_Incubatore_1_Cancel
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, OldaleTown_House2_EventScript_Incubatore_1_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	call_if_eq VAR_0x8004, 0, Route117_EventScript_CheckFollowerVisibility
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox OldaleTown_House2_Text_Incubatore_Depositing, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInIncubator
	updatefollowerpokemongraphic
	msgbox OldaleTown_House2_Text_Incubatore_Deposited, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_EventScript_Incubatore_1_RetrievePrompt::
	special ShowIncubatorSlot1Info
	msgbox OldaleTown_House2_Text_Incubatore_RetrievePrompt, MSGBOX_YESNO
	special CloseIncubatorSlotInfo
	goto_if_eq VAR_RESULT, YES, OldaleTown_House2_EventScript_Incubatore_1_Retrieve
	goto OldaleTown_House2_EventScript_Incubatore_1_Cancel
	end

OldaleTown_House2_EventScript_Incubatore_1_Retrieve::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, PARTY_SIZE, OldaleTown_House2_EventScript_Incubatore_1_AskPC
	special TakePokemonFromIncubator
	updatefollowerpokemongraphic
	msgbox OldaleTown_House2_Text_Incubatore_Retrieved, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_EventScript_Incubatore_1_AskPC::
	msgbox OldaleTown_House2_Text_Incubatore_AskSendToPC, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_House2_EventScript_Incubatore_1_NoRoom
	specialvar VAR_RESULT, SendIncubatorMonToPC
	goto_if_eq VAR_RESULT, FALSE, OldaleTown_House2_EventScript_Incubatore_PCFull
	msgbox OldaleTown_House2_Text_Incubatore_SentToPC, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_EventScript_Incubatore_PCFull::
	msgbox OldaleTown_House2_Text_Incubatore_PCFull, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_EventScript_Incubatore_1_OnlyOneMon::
	msgbox OldaleTown_House2_Text_Incubatore_OnlyOneMon, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_EventScript_Incubatore_1_OnlyTwoAliveMons::
	msgbox OldaleTown_House2_Text_Incubatore_OnlyTwoAliveMons, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_EventScript_Incubatore_1_OnlyOneAliveMon::
	msgbox OldaleTown_House2_Text_Incubatore_OnlyOneAliveMon, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_EventScript_Incubatore_1_NoRoom::
	msgbox OldaleTown_House2_Text_Incubatore_NoRoom, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_EventScript_Incubatore_1_Cancel::
	msgbox OldaleTown_House2_Text_Incubatore_Cancel, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_Text_Incubatore_DepositPrompt:
	.string "The incubator is empty.\p"
	.string "Would you like to deposit a POKéMON?$"

OldaleTown_House2_Text_Incubatore_ChoosePokemon:
	.string "Which POKéMON would you like to\n"
	.string "leave in the incubator?$"

OldaleTown_House2_Text_Incubatore_Depositing:
	.string "We'll take your {STR_VAR_1}.$"

OldaleTown_House2_Text_Incubatore_Deposited:
	.string "Your POKéMON is now in the incubator.$"

OldaleTown_House2_Text_Incubatore_RetrievePrompt:
	.string "A POKéMON is in the incubator.\p"
	.string "Would you like to take it back?$"

OldaleTown_House2_Text_Incubatore_Retrieved:
	.string "You took {STR_VAR_1} back from the\n"
	.string "incubator.$"

OldaleTown_House2_Text_Incubatore_OnlyOneMon:
	.string "You need to keep at least one\n"
	.string "POKéMON with you.$"

OldaleTown_House2_Text_Incubatore_OnlyTwoAliveMons:
	.string "You need more healthy POKéMON before\n"
	.string "you can leave one here.$"

OldaleTown_House2_Text_Incubatore_OnlyOneAliveMon:
	.string "You can't leave your last healthy\n"
	.string "POKéMON in the incubator.$"

OldaleTown_House2_Text_Incubatore_NoRoom:
	.string "Your party is full.\n"
	.string "Make room before retrieving your POKéMON.$"

OldaleTown_House2_Text_Incubatore_AskSendToPC:
	.string "Your party is full.\p"
	.string "Send the POKéMON to the PC instead?$"

OldaleTown_House2_Text_Incubatore_SentToPC:
	.string "{STR_VAR_1} was sent to BOX\n"
	.string "“{STR_VAR_2}” in the PC.$"

OldaleTown_House2_Text_Incubatore_PCFull:
	.string "The PC is full.\n"
	.string "The POKéMON stays in the incubator.$"

OldaleTown_House2_Text_Incubatore_Cancel:
	.string "All right. Come back any time.$"

OldaleTown_House2_EventScript_Incubatore_2::
	lock
	faceplayer
	specialvar VAR_RESULT, IsIncubatorSlot2Occupied
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_House2_EventScript_Incubatore_2_RetrievePrompt
	msgbox OldaleTown_House2_Text_Incubatore_DepositPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, OldaleTown_House2_EventScript_Incubatore_2_Deposit
	goto OldaleTown_House2_EventScript_Incubatore_1_Cancel
	end

OldaleTown_House2_EventScript_Incubatore_2_Deposit::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, OldaleTown_House2_EventScript_Incubatore_1_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, OldaleTown_House2_EventScript_Incubatore_1_OnlyTwoAliveMons
	msgbox OldaleTown_House2_Text_Incubatore_ChoosePokemon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, OldaleTown_House2_EventScript_Incubatore_1_Cancel
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, OldaleTown_House2_EventScript_Incubatore_1_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	call_if_eq VAR_0x8004, 0, Route117_EventScript_CheckFollowerVisibility
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox OldaleTown_House2_Text_Incubatore_Depositing, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInIncubatorSlot2
	updatefollowerpokemongraphic
	msgbox OldaleTown_House2_Text_Incubatore_Deposited, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_EventScript_Incubatore_2_RetrievePrompt::
	special ShowIncubatorSlot2Info
	msgbox OldaleTown_House2_Text_Incubatore_RetrievePrompt, MSGBOX_YESNO
	special CloseIncubatorSlotInfo
	goto_if_eq VAR_RESULT, YES, OldaleTown_House2_EventScript_Incubatore_2_Retrieve
	goto OldaleTown_House2_EventScript_Incubatore_1_Cancel
	end

OldaleTown_House2_EventScript_Incubatore_2_Retrieve::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, PARTY_SIZE, OldaleTown_House2_EventScript_Incubatore_2_AskPC
	special TakePokemonFromIncubatorSlot2
	updatefollowerpokemongraphic
	msgbox OldaleTown_House2_Text_Incubatore_Retrieved, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_EventScript_Incubatore_2_AskPC::
	msgbox OldaleTown_House2_Text_Incubatore_AskSendToPC, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_House2_EventScript_Incubatore_1_NoRoom
	specialvar VAR_RESULT, SendIncubatorMon2ToPC
	goto_if_eq VAR_RESULT, FALSE, OldaleTown_House2_EventScript_Incubatore_PCFull
	msgbox OldaleTown_House2_Text_Incubatore_SentToPC, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_EventScript_Incubatore_Result::
	lock
	faceplayer
	specialvar VAR_RESULT, IsIncubatorResultReady
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_House2_EventScript_Incubatore_Result_Deliver
	specialvar VAR_RESULT, CheckIncubatorCompatibility
	goto_if_eq VAR_RESULT, 0, OldaleTown_House2_EventScript_Incubatore_Result_NeedTwo
	goto_if_eq VAR_RESULT, 1, OldaleTown_House2_EventScript_Incubatore_Result_Incompatible
	special ShowBattlePointsWindow
	special ShowIncubatorMonsWindow
	msgbox OldaleTown_House2_Text_Incubatore_Compatible, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_House2_EventScript_Incubatore_Result_PayCancel
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_lt VAR_TEMP_1, 8, OldaleTown_House2_EventScript_Incubatore_Result_NoBP
	setvar VAR_0x8004, 8
	special TakeFrontierBattlePoints
	special UpdateBattlePointsWindow
	msgbox OldaleTown_House2_Text_Incubatore_Paid, MSGBOX_DEFAULT
	special CloseIncubatorMonsWindow
	special CloseBattlePointsWindow
	special CreateIncubatorResult
	goto OldaleTown_House2_EventScript_Incubatore_Result_Deliver
	end

OldaleTown_House2_EventScript_Incubatore_Result_Deliver::
	special ShowIncubatorResultInfo
	msgbox OldaleTown_House2_Text_Incubatore_Hatched, MSGBOX_DEFAULT
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, PARTY_SIZE, OldaleTown_House2_EventScript_Incubatore_Result_AskPC
	special TakeIncubatorResult
	special CloseIncubatorSlotInfo
	updatefollowerpokemongraphic
	msgbox OldaleTown_House2_Text_Incubatore_ResultReceived, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_EventScript_Incubatore_Result_AskPC::
	msgbox OldaleTown_House2_Text_Incubatore_AskSendToPC, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_House2_EventScript_Incubatore_Result_StayHere
	specialvar VAR_RESULT, SendIncubatorResultToPC
	special CloseIncubatorSlotInfo
	goto_if_eq VAR_RESULT, FALSE, OldaleTown_House2_EventScript_Incubatore_PCFull
	msgbox OldaleTown_House2_Text_Incubatore_SentToPC, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_EventScript_Incubatore_Result_StayHere::
	special CloseIncubatorSlotInfo
	goto OldaleTown_House2_EventScript_Incubatore_1_NoRoom
	end

OldaleTown_House2_Text_Incubatore_Hatched:
	.string "The EGG hatched!\p"
	.string "It's a {STR_VAR_1}!$"

OldaleTown_House2_Text_Incubatore_ResultReceived:
	.string "{PLAYER} received {STR_VAR_1}!$"

OldaleTown_House2_EventScript_Incubatore_Result_PayCancel::
	special CloseIncubatorMonsWindow
	special CloseBattlePointsWindow
	goto OldaleTown_House2_EventScript_Incubatore_1_Cancel
	end

OldaleTown_House2_EventScript_Incubatore_Result_NoBP::
	msgbox OldaleTown_House2_Text_Incubatore_NoBP, MSGBOX_DEFAULT
	special CloseIncubatorMonsWindow
	special CloseBattlePointsWindow
	release
	end

OldaleTown_House2_EventScript_Incubatore_Result_NeedTwo::
	msgbox OldaleTown_House2_Text_Incubatore_NeedTwo, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_EventScript_Incubatore_Result_Incompatible::
	msgbox OldaleTown_House2_Text_Incubatore_Incompatible, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_Text_Incubatore_NeedTwo:
	.string "Both incubators must hold a POKéMON\n"
	.string "before an EGG can be made.$"

OldaleTown_House2_Text_Incubatore_Incompatible:
	.string "These two POKéMON are not compatible.\n"
	.string "No EGG can be made.$"

OldaleTown_House2_Text_Incubatore_Compatible:
	.string "These two POKéMON are compatible!\p"
	.string "Pay 8 BP to produce an EGG?$"

OldaleTown_House2_Text_Incubatore_Paid:
	.string "You paid 8 BP.$"

OldaleTown_House2_Text_Incubatore_NoBP:
	.string "You don't have enough Battle Points.\n"
	.string "You need 8 BP.$"

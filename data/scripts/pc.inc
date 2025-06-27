EventScript_PC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_OTHER
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox Text_BootUpPC, MSGBOX_DEFAULT
	goto EventScript_PCMainMenu
	end

EventScript_PCMainMenu::
	message gText_WhichPCShouldBeAccessed
	waitmessage
	special ScriptMenu_CreatePCMultichoice
	waitstate
	goto EventScript_AccessPC
	end

EventScript_AccessPC::
	switch VAR_RESULT
	case 0, EventScript_AccessPokemonStorage
	case 1, EventScript_AccessPlayersPC
	case 2, EventScript_AccessHallOfFame
	case 3, EventScript_TurnOffPC
	case MULTI_B_PRESSED, EventScript_TurnOffPC
	end

EventScript_AccessPlayersPC::
	playse SE_PC_LOGIN
	msgbox gText_AccessedPlayersPC, MSGBOX_DEFAULT
	special PlayerPC
	waitstate
	goto EventScript_PCMainMenu
	end

EventScript_AccessPokemonStorage::
	playse SE_PC_LOGIN
	call_if_unset FLAG_SYS_PC_LANETTE, EventScript_AccessSomeonesPC
	call_if_set FLAG_SYS_PC_LANETTE, EventScript_AccessLanettesPC
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
	special ShowPokemonStorageSystemPC
	waitstate
	goto EventScript_PCMainMenu
	end

EventScript_AccessSomeonesPC::
	msgbox gText_AccessedSomeonesPC, MSGBOX_DEFAULT
	return

EventScript_AccessLanettesPC::
	msgbox gText_AccessedLanettesPC, MSGBOX_DEFAULT
	return

EventScript_TurnOffPC::
	setvar VAR_0x8004, PC_LOCATION_OTHER
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

EventScript_AccessHallOfFame::
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_TurnOffPC
	playse SE_PC_LOGIN
	special AccessHallOfFamePC
	waitstate
	goto EventScript_AccessPC
	end

EventScript_PC_Lite::
	lockall
	setvar VAR_0x8004, PC_LOCATION_OTHER
	playse SE_PC_ON
	msgbox Text_BootUpPC, MSGBOX_DEFAULT
	goto EventScript_PCMainMenu_Lite
	end

EventScript_TurnOffPC_Lite::
	setvar VAR_0x8004, PC_LOCATION_OTHER
	playse SE_PC_OFF
	releaseall
	end

EventScript_AccessPC_Lite::
	switch VAR_RESULT
	case 0, EventScript_AccessPokemonStorage_Lite
	case 1, EventScript_AccessPlayersPC_Lite
	case 2, EventScript_AccessHallOfFame_Lite
	case 3, EventScript_TurnOffPC_Lite
	case MULTI_B_PRESSED, EventScript_TurnOffPC_Lite
	end

EventScript_AccessPokemonStorage_Lite::
	playse SE_PC_LOGIN
	call_if_unset FLAG_SYS_PC_LANETTE, EventScript_AccessSomeonesPC
	call_if_set FLAG_SYS_PC_LANETTE, EventScript_AccessLanettesPC
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
	special ShowPokemonStorageSystemPC
	waitstate
	goto EventScript_PCMainMenu_Lite
	end

EventScript_AccessHallOfFame_Lite::
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_TurnOffPC_Lite
	playse SE_PC_LOGIN
	special AccessHallOfFamePC
	waitstate
	goto EventScript_AccessPC_Lite
	end

EventScript_AccessPlayersPC_Lite::
	playse SE_PC_LOGIN
	msgbox gText_AccessedPlayersPC, MSGBOX_DEFAULT
	special PlayerPC
	waitstate
	goto EventScript_PCMainMenu_Lite
	end

EventScript_PCMainMenu_Lite::
	message gText_WhichPCShouldBeAccessed
	waitmessage
	special ScriptMenu_CreatePCMultichoice
	waitstate
	goto EventScript_AccessPC_Lite
	end
EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	.byte 0

EverGrandeCity_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

EverGrandeCity_EventScript_VictoryRoadSign::
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_CitySign::
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_PokemonLeagueSign::
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_SetVisitedEverGrande::
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setvar VAR_TEMP_1, 1
	end

EverGrandeCity_Text_EnteringVictoryRoad:
	.string "ENTERING VICTORY ROAD$"

EverGrandeCity_Text_EnteringPokemonLeague:
	.string "ENTERING POKéMON LEAGUE\n"
	.string "CENTER GATE$"

EverGrandeCity_Text_CitySign:
	.string "EVER GRANDE CITY\p"
	.string "“The paradise of flowers, the sea,\n"
	.string "and POKéMON.”$"

EverGrandeCity_EventScript_HunterHouse_Battle_2::
	playmoncry SPECIES_MEW, CRY_MODE_ENCOUNTER
	delay 40
	clearflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	setflag FLAG_HUNTER_HOUSE_2
	removeobject 1
	setwildbattle SPECIES_MEW, 40
	dowildbattle
	end

EverGrandeCity_EventScript_HunterHouse_Battle_8::
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	delay 40
	clearflag FLAG_HUNTER_HOUSE_IN_PROGRESS
	setflag FLAG_HUNTER_HOUSE_8
	removeobject 2
	setwildbattle SPECIES_KYOGRE, 40
	dowildbattle
	end
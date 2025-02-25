.set LOCALID_ARCHIE, 2
.set LOCALID_OLD_LADY, 3
.set LOCALID_GRUNT_1, 4
.set LOCALID_GRUNT_2, 5
.set LOCALID_GRUNT_3, 6
.set LOCALID_GRUNT_4, 7
.set LOCALID_MAXIE, 8

MtPyre_Summit_MapScripts:: @ 8231FF7
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition: @ 8231FFD
	compare VAR_MT_PYRE_STATE, 2
	call_if_eq MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions:: @ 8232009
	setobjectxyperm LOCALID_MAXIE, 23, 6
	setobjectxyperm LOCALID_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0:: @ 8232018
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1:: @ 8232024
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2:: @ 8232030
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits:: @ 823203C
	playbgm MUS_ENCOUNTER_AQUA, 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 50
	compare VAR_0x8008, 0
	call_if_eq MtPyre_Summit_EventScript_ArchieFacePlayer0
	compare VAR_0x8008, 1
	call_if_eq MtPyre_Summit_EventScript_ArchieFacePlayer1
	compare VAR_0x8008, 2
	call_if_eq MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	compare VAR_0x8008, 0
	call_if_eq MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	compare VAR_0x8008, 1
	call_if_eq MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	compare VAR_0x8008, 2
	call_if_eq MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	call GetItem_Magma_Emblem
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0:: @ 82320E0
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	waitmovement 0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1:: @ 82320EB
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2:: @ 82320EC
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0:: @ 82320F7
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1:: @ 823210C
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2:: @ 8232117
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0: @ 823212C
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1: @ 8232130
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2: @ 8232132
	walk_down
	walk_down
	walk_in_place_fastest_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0: @ 8232136
	walk_left
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2: @ 8232139
	walk_right
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_EventScript_OldMan:: @ 823213C
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq MtPyre_Summit_EventScript_OldManTale
	compare VAR_RESULT, NO
	call_if_eq MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza:: @ 8232167
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq MtPyre_Summit_EventScript_OldManNewTale
	compare VAR_RESULT, NO
	call_if_eq MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale:: @ 8232187
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale:: @ 8232190
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale:: @ 8232199
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady:: @ 82321A2
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	compare VAR_MT_PYRE_STATE, 3
	call_if_ge MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned:: @ 82321CB
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake:: @ 82321D8
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned:: @ 82321E2
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0:: @ 82321EC
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1:: @ 82321F8
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2:: @ 8232204
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs:: @ 8232210
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 60
	compare VAR_0x8008, 0
	call_if_eq MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	compare VAR_0x8008, 1
	call_if_eq MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	compare VAR_0x8008, 2
	call_if_eq MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	compare VAR_0x8008, 0
	call_if_eq MtPyre_Summit_EventScript_MaxieApproachPlayer0
	compare VAR_0x8008, 1
	call_if_eq MtPyre_Summit_EventScript_MaxieApproachPlayer1
	compare VAR_0x8008, 2
	call_if_eq MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq MtPyre_Summit_EventScript_MaxieApproachArchie0
	compare VAR_0x8008, 1
	call_if_eq MtPyre_Summit_EventScript_MaxieApproachArchie1
	compare VAR_0x8008, 2
	call_if_eq MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0:: @ 82322C4
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1:: @ 82322DD
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2:: @ 82322F6
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0:: @ 823230F
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1:: @ 8232328
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2:: @ 8232341
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0:: @ 823235A
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1:: @ 8232376
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2:: @ 8232392
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0: @ 82323AE
	delay_16
	delay_16
	walk_in_place_fastest_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie: @ 82323B2
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

MtPyre_Summit_Movement_ArchieExit: @ 82323B6
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit: @ 82323BD
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0: @ 82323C4
	delay_16
	delay_8
	walk_left
	walk_in_place_fastest_right
	delay_16
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1: @ 82323CB
	delay_16
	delay_8
	walk_right
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2: @ 82323D2
	delay_16
	delay_8
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0: @ 82323D8
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1: @ 82323DD
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2: @ 82323E2
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie: @ 82323E7
	delay_16
	walk_in_place_fastest_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie: @ 82323EA
	delay_16
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0: @ 82323ED
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1: @ 82323F3
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2: @ 82323F8
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

MtPyre_Summit_EventScript_Grunt1:: @ 82323FD
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2:: @ 8232414
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3:: @ 823242B
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4:: @ 8232442
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro: @ 8232459
	.string "No! Those TEAM MAGMA goons got\n"
	.string "here ahead of us!\p"
	.string "We can't fall behind!$"

MtPyre_Summit_Text_Grunt1Defeat: @ 82324A0
	.string "I thought you were one of the MAGMAS\n"
	.string "who happened to come back…$"

MtPyre_Summit_Text_Grunt1PostBattle: @ 82324E0
	.string "Yeah, so you are strong…\n"
	.string "But there're a lot of us!$"

MtPyre_Summit_Text_Grunt2Intro: @ 8232513
	.string "Hah!\n"
	.string "Too bad for you!\p"
	.string "If you came earlier, you only would've\n"
	.string "had to battle the wimpy TEAM MAGMA.\p"
	.string "But since you arrived now, you have\n"
	.string "to take on us toughies!$"

MtPyre_Summit_Text_Grunt2Defeat: @ 82325B0
	.string "Urgh… I should've let you take on\n"
	.string "TEAM MAGMA first…$"

MtPyre_Summit_Text_Grunt2PostBattle: @ 82325E4
	.string "You don't know anything!\n"
	.string "So why are you messing with us?$"

MtPyre_Summit_Text_Grunt3Intro: @ 823261D
	.string "You…\n"
	.string "We saw you at MT. CHIMNEY.\p"
	.string "You don't belong to either TEAM,\n"
	.string "so why would you be here?$"

MtPyre_Summit_Text_Grunt3Defeat: @ 8232678
	.string "If you're going to mess with anyone,\n"
	.string "let it be TEAM MAGMA…$"

MtPyre_Summit_Text_Grunt3PostBattle: @ 82326B3
	.string "Heh, it doesn't matter!\n"
	.string "We bought ourselves some time!\p"
	.string "The BOSS should have snatched what\n"
	.string "he was after!$"

MtPyre_Summit_Text_Grunt4Intro: @ 823271B
	.string "Oh, I know!\n"
	.string "You tried to join TEAM MAGMA,\l"
	.string "but they wouldn't have you!\p"
	.string "Well, don't think that we'll let you\n"
	.string "join our TEAM AQUA!$"

MtPyre_Summit_Text_Grunt4Defeat: @ 823279A
	.string "If you want to join TEAM AQUA that\n"
	.string "badly, we can consider it…$"

MtPyre_Summit_Text_Grunt4PostBattle: @ 82327D8
	.string "We have a great combination going\n"
	.string "with us members and our leader.$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo: @ 823281A
	.string "ARCHIE: TEAM MAGMA's MAXIE got ahead\n"
	.string "of us, but we also got what we wanted.\p"
	.string "The RED ORB preserved at MT. PYRE…\n"
	.string "I, ARCHIE, now have it in my possession!\p"
	.string "Fufufu… Now we can bring our ultimate\n"
	.string "objective to fruition!\p"
	.string "Okay, TEAM!\n"
	.string "We're pulling out!$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis: @ 823290E
	.string "Oh, no…\n"
	.string "This cannot happen…\p"
	.string "Not only the BLUE ORB, but even\n"
	.string "the RED ORB has been taken…\p"
	.string "The BLUE ORB and RED ORB must never\n"
	.string "be separated. They belong together.\p"
	.string "What are those men trying to do with\n"
	.string "the two ORBS?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Oh, yes. Was it TEAM MAGMA who came\n"
	.string "and took the BLUE ORB first?\p"
	.string "Well, in their haste, they left this\n"
	.string "behind.\p"
	.string "I couldn't imagine what exactly it\n"
	.string "could be.\p"
	.string "I would like you to have it.\n"
	.string "Perhaps it will be useful in some way.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken: @ 8232AD8
	.string "The BLUE ORB and RED ORB taken by\n"
	.string "those sinister men…\p"
	.string "They must never be apart…\n"
	.string "I fear something terrible will happen…$"

MtPyre_Summit_Text_GroudonKyogreAwakened: @ 8232B4F
	.string "Oh, my goodness…\p"
	.string "You say that both GROUDON and KYOGRE\n"
	.string "have been awakened?\p"
	.string "It is said that the BLUE ORB and\n"
	.string "the RED ORB quelled the rage of\l"
	.string "the two POKéMON…\p"
	.string "It is also said that the true owner\n"
	.string "of the ORBS still exists.\p"
	.string "However, no one knows who, or what\n"
	.string "exactly, the ORBS belong to.\p"
	.string "It could be a human, or perhaps\n"
	.string "a POKéMON, but no one knows.$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs: @ 8232CA6
	.string "The two men who took the ORBS came\n"
	.string "back to return them on their own.\p"
	.string "Those men…\n"
	.string "Perhaps they are not so evil after all…$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs: @ 8232D1E
	.string "The embodiments of the land, sea,\n"
	.string "and the sky…\p"
	.string "That is said to be the identities of\n"
	.string "the super-ancient POKéMON…\p"
	.string "In the same way that we humans and\n"
	.string "POKéMON have life, our world, too,\l"
	.string "is alive…\p"
	.string "The super-ancient POKéMON have\n"
	.string "taught us that…$"

MtPyre_Summit_Text_WillYouHearOutMyTale: @ 8232E0C
	.string "MT. PYRE is where we calm the spirits\n"
	.string "of POKéMON that have passed on…\p"
	.string "This is a high place where one can\n"
	.string "see all of HOENN…\p"
	.string "The disembodied spirits of POKéMON\n"
	.string "must find solace here…\p"
	.string "Is it coincidence that you are here…\p"
	.string "Will you hear out my tale? A tale long\n"
	.string "told in the HOENN region?$"

MtPyre_Summit_Text_GroudonKyogreTale: @ 8232F27
	.string "It happened long, long ago…\p"
	.string "The world was wracked by a ferocious\n"
	.string "clash between the POKéMON of the land\l"
	.string "and the POKéMON of the sea…\p"
	.string "The POKéMON of the land raised\n"
	.string "mountains and created continents…\p"
	.string "The POKéMON of the sea raised huge\n"
	.string "waves and carved out oceans…\p"
	.string "Their fierce duel raged without end.\p"
	.string "The world was engulfed in massive\n"
	.string "infernos and vicious storms.\p"
	.string "The BLUE ORB and the RED ORB brought\n"
	.string "an end to the calamity.\p"
	.string "Light poured from the two ORBS and\n"
	.string "becalmed the enraged adversaries.\p"
	.string "The pair, made docile, dove deep into\n"
	.string "the sea where eventually they\l"
	.string "disappeared…$"

MtPyre_Summit_Text_WellThatTooIsFine: @ 8233162
	.string "I see…\n"
	.string "Well, that, too, is fine…$"

MtPyre_Summit_Text_MaxieSilence: @ 8233183
	.string "MAXIE: {PLAYER}…\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn: @ 82331A6
	.string "It is my role to pass on the legends\n"
	.string "of HOENN to future generations.\p"
	.string "And the crisis that just ended in\n"
	.string "SOOTOPOLIS rewrote a legend…\p"
	.string "Have you the time to hear the new\n"
	.string "legend of HOENN?$"

MtPyre_Summit_Text_HoennTrioTale: @ 823325D
	.string "It happened long, long ago…\p"
	.string "The world was wracked by a ferocious\n"
	.string "clash between the POKéMON of the land\l"
	.string "and the POKéMON of the sea…\p"
	.string "The POKéMON of the land raised\n"
	.string "mountains and created continents…\p"
	.string "The POKéMON of the sea raised huge\n"
	.string "waves and carved out oceans…\p"
	.string "Their fierce duel raged without end.\p"
	.string "The world was engulfed in massive\n"
	.string "fires and vicious storms.\p"
	.string "It was then that the POKéMON of\n"
	.string "the sky descended from a storm.\p"
	.string "The POKéMON, shining a vivid green,\n"
	.string "becalmed the two enraged POKéMON.\p"
	.string "Then, its duty done, the green POKéMON\n"
	.string "flew off into the wild blue yonder…$"


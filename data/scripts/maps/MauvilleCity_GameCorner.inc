MauvilleCity_GameCorner_MapScripts:: @ 8156A33
	.byte 0

MauvilleCity_GameCorner_EventScript_156A34:: @ 8156A34
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_181C35, 4
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_156B32
	message MauvilleCity_GameCorner_Text_181CB4
	waittext
	showmoney 0, 0
	snop
	showcoins 0, 5
	jump MauvilleCity_GameCorner_EventScript_156A60

MauvilleCity_GameCorner_EventScript_156A60:: @ 8156A60
	multichoicedef 15, 0, 49, 0, 0
	switch RESULT
	case 0, MauvilleCity_GameCorner_EventScript_156AAE
	case 1, MauvilleCity_GameCorner_EventScript_156AF0
	jump MauvilleCity_GameCorner_EventScript_156B4C
	end

@ 8156A87
	multichoicedef 15, 0, 49, 1, 0
	switch RESULT
	case 0, MauvilleCity_GameCorner_EventScript_156AAE
	case 1, MauvilleCity_GameCorner_EventScript_156AF0
	jump MauvilleCity_GameCorner_EventScript_156B4C
	end

MauvilleCity_GameCorner_EventScript_156AAE:: @ 8156AAE
	checkcoins 16385
	compare 0x4001, 9950
	jumpif 4, MauvilleCity_GameCorner_EventScript_156B5C
	checkmoney 0x3e8, 0
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_156B3C
	givecoins 50
	paymoney 0x3e8, 0
	updatemoney 0, 0
	snop
	updatecoins 0, 5
	playsfx 95
	msgbox MauvilleCity_GameCorner_Text_181CFE, 4
	hidemoney 0, 0
	hidecoins 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_156AF0:: @ 8156AF0
	checkcoins 16385
	compare 0x4001, 9500
	jumpif 4, MauvilleCity_GameCorner_EventScript_156B5C
	checkmoney 0x2710, 0
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_156B3C
	givecoins 500
	paymoney 0x2710, 0
	updatemoney 0, 0
	snop
	updatecoins 0, 5
	playsfx 95
	msgbox MauvilleCity_GameCorner_Text_181CFE, 4
	hidemoney 0, 0
	hidecoins 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_156B32:: @ 8156B32
	msgbox MauvilleCity_GameCorner_Text_181C53, 4
	release
	end

MauvilleCity_GameCorner_EventScript_156B3C:: @ 8156B3C
	msgbox MauvilleCity_GameCorner_Text_181D28, 4
	hidemoney 0, 0
	hidecoins 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_156B4C:: @ 8156B4C
	msgbox MauvilleCity_GameCorner_Text_181D73, 4
	hidemoney 0, 0
	hidecoins 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_156B5C:: @ 8156B5C
	msgbox MauvilleCity_GameCorner_Text_181D57, 4
	hidemoney 0, 0
	hidecoins 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_156B6C:: @ 8156B6C
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_181DE1, 4
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 1
	jumpeq MauvilleCity_GameCorner_EventScript_156B88
	release
	end

MauvilleCity_GameCorner_EventScript_156B88:: @ 8156B88
	message MauvilleCity_GameCorner_Text_181E17
	waittext
	showcoins 0, 0
	setvar 0x4001, 0
	jump MauvilleCity_GameCorner_EventScript_156BA6

MauvilleCity_GameCorner_EventScript_156B9B:: @ 8156B9B
	message MauvilleCity_GameCorner_Text_181E17
	waittext
	jump MauvilleCity_GameCorner_EventScript_156BA6

MauvilleCity_GameCorner_EventScript_156BA6:: @ 8156BA6
	multichoice 12, 0, 48, 0
	switch RESULT
	case 0, MauvilleCity_GameCorner_EventScript_156BE2
	case 1, MauvilleCity_GameCorner_EventScript_156BF0
	case 2, MauvilleCity_GameCorner_EventScript_156BFE
	case 3, MauvilleCity_GameCorner_EventScript_156D0D
	jump MauvilleCity_GameCorner_EventScript_156D0D
	end

MauvilleCity_GameCorner_EventScript_156BE2:: @ 8156BE2
	setvar 0x4001, 1
	bufferdecor 0, 88
	jump MauvilleCity_GameCorner_EventScript_156C0C

MauvilleCity_GameCorner_EventScript_156BF0:: @ 8156BF0
	setvar 0x4001, 2
	bufferdecor 0, 89
	jump MauvilleCity_GameCorner_EventScript_156C0C

MauvilleCity_GameCorner_EventScript_156BFE:: @ 8156BFE
	setvar 0x4001, 3
	bufferdecor 0, 90
	jump MauvilleCity_GameCorner_EventScript_156C0C

MauvilleCity_GameCorner_EventScript_156C0C:: @ 8156C0C
	msgbox MauvilleCity_GameCorner_Text_181E33, 5
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_156D0D
	switch 0x4001
	case 1, MauvilleCity_GameCorner_EventScript_156C46
	case 2, MauvilleCity_GameCorner_EventScript_156C80
	case 3, MauvilleCity_GameCorner_EventScript_156CBA
	end

MauvilleCity_GameCorner_EventScript_156C46:: @ 8156C46
	checkcoins 16386
	compare 0x4002, 1000
	jumpif 0, MauvilleCity_GameCorner_EventScript_156CF4
	bufferdecor 1, 88
	checkdecor 88
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_156D02
	removecoins 1000
	adddecor 88
	updatecoins 0, 0
	playsfx 95
	msgbox MauvilleCity_GameCorner_Text_181E49, 4
	jump MauvilleCity_GameCorner_EventScript_156B9B
	end

MauvilleCity_GameCorner_EventScript_156C80:: @ 8156C80
	checkcoins 16386
	compare 0x4002, 1000
	jumpif 0, MauvilleCity_GameCorner_EventScript_156CF4
	bufferdecor 1, 89
	checkdecor 89
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_156D02
	removecoins 1000
	adddecor 89
	updatecoins 0, 0
	playsfx 95
	msgbox MauvilleCity_GameCorner_Text_181E49, 4
	jump MauvilleCity_GameCorner_EventScript_156B9B
	end

MauvilleCity_GameCorner_EventScript_156CBA:: @ 8156CBA
	checkcoins 16386
	compare 0x4002, 1000
	jumpif 0, MauvilleCity_GameCorner_EventScript_156CF4
	bufferdecor 1, 90
	checkdecor 90
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_156D02
	removecoins 1000
	adddecor 90
	updatecoins 0, 0
	playsfx 95
	msgbox MauvilleCity_GameCorner_Text_181E49, 4
	jump MauvilleCity_GameCorner_EventScript_156B9B
	end

MauvilleCity_GameCorner_EventScript_156CF4:: @ 8156CF4
	msgbox MauvilleCity_GameCorner_Text_181E76, 4
	jump MauvilleCity_GameCorner_EventScript_156B9B
	end

MauvilleCity_GameCorner_EventScript_156D02:: @ 8156D02
	call MauvilleCity_GameCorner_EventScript_1A02B8
	jump MauvilleCity_GameCorner_EventScript_156B9B
	end

MauvilleCity_GameCorner_EventScript_156D0D:: @ 8156D0D
	msgbox MauvilleCity_GameCorner_Text_181EC2, 4
	hidecoins 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_156D1A:: @ 8156D1A
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_181DE1, 4
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 1
	jumpeq MauvilleCity_GameCorner_EventScript_156D36
	release
	end

MauvilleCity_GameCorner_EventScript_156D36:: @ 8156D36
	message MauvilleCity_GameCorner_Text_181E17
	waittext
	showcoins 0, 0
	setvar 0x4001, 0
	jump MauvilleCity_GameCorner_EventScript_156D54

MauvilleCity_GameCorner_EventScript_156D49:: @ 8156D49
	message MauvilleCity_GameCorner_Text_181E17
	waittext
	jump MauvilleCity_GameCorner_EventScript_156D54

MauvilleCity_GameCorner_EventScript_156D54:: @ 8156D54
	multichoice 12, 0, 55, 0
	switch RESULT
	case 0, MauvilleCity_GameCorner_EventScript_156DA6
	case 1, MauvilleCity_GameCorner_EventScript_156DB4
	case 2, MauvilleCity_GameCorner_EventScript_156DC2
	case 3, MauvilleCity_GameCorner_EventScript_156DD0
	case 4, MauvilleCity_GameCorner_EventScript_156DDE
	case 5, MauvilleCity_GameCorner_EventScript_156F77
	jump MauvilleCity_GameCorner_EventScript_156F77
	end

MauvilleCity_GameCorner_EventScript_156DA6:: @ 8156DA6
	setvar 0x4001, 1
	bufferitem 0, ITEM_TM32
	jump MauvilleCity_GameCorner_EventScript_156DEC

MauvilleCity_GameCorner_EventScript_156DB4:: @ 8156DB4
	setvar 0x4001, 2
	bufferitem 0, ITEM_TM29
	jump MauvilleCity_GameCorner_EventScript_156DEC

MauvilleCity_GameCorner_EventScript_156DC2:: @ 8156DC2
	setvar 0x4001, 3
	bufferitem 0, ITEM_TM35
	jump MauvilleCity_GameCorner_EventScript_156DEC

MauvilleCity_GameCorner_EventScript_156DD0:: @ 8156DD0
	setvar 0x4001, 4
	bufferitem 0, ITEM_TM24
	jump MauvilleCity_GameCorner_EventScript_156DEC

MauvilleCity_GameCorner_EventScript_156DDE:: @ 8156DDE
	setvar 0x4001, 5
	bufferitem 0, ITEM_TM13
	jump MauvilleCity_GameCorner_EventScript_156DEC

MauvilleCity_GameCorner_EventScript_156DEC:: @ 8156DEC
	msgbox MauvilleCity_GameCorner_Text_181E33, 5
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_156F77
	switch 0x4001
	case 1, MauvilleCity_GameCorner_EventScript_156E3C
	case 2, MauvilleCity_GameCorner_EventScript_156E76
	case 3, MauvilleCity_GameCorner_EventScript_156EB0
	case 4, MauvilleCity_GameCorner_EventScript_156EEA
	case 5, MauvilleCity_GameCorner_EventScript_156F24
	end

MauvilleCity_GameCorner_EventScript_156E3C:: @ 8156E3C
	checkcoins 16386
	compare 0x4002, 1500
	jumpif 0, MauvilleCity_GameCorner_EventScript_156F5E
	checkitemspace ITEM_TM32, 1
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_156F6C
	removecoins 1500
	additem ITEM_TM32, 1
	updatecoins 0, 0
	playsfx 95
	msgbox MauvilleCity_GameCorner_Text_181F08, 4
	jump MauvilleCity_GameCorner_EventScript_156D49
	end

MauvilleCity_GameCorner_EventScript_156E76:: @ 8156E76
	checkcoins 16386
	compare 0x4002, 3500
	jumpif 0, MauvilleCity_GameCorner_EventScript_156F5E
	checkitemspace ITEM_TM29, 1
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_156F6C
	removecoins 3500
	additem ITEM_TM29, 1
	updatecoins 0, 0
	playsfx 95
	msgbox MauvilleCity_GameCorner_Text_181F08, 4
	jump MauvilleCity_GameCorner_EventScript_156D49
	end

MauvilleCity_GameCorner_EventScript_156EB0:: @ 8156EB0
	checkcoins 16386
	compare 0x4002, 4000
	jumpif 0, MauvilleCity_GameCorner_EventScript_156F5E
	checkitemspace ITEM_TM35, 1
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_156F6C
	removecoins 4000
	additem ITEM_TM35, 1
	updatecoins 0, 0
	playsfx 95
	msgbox MauvilleCity_GameCorner_Text_181F08, 4
	jump MauvilleCity_GameCorner_EventScript_156D49
	end

MauvilleCity_GameCorner_EventScript_156EEA:: @ 8156EEA
	checkcoins 16386
	compare 0x4002, 4000
	jumpif 0, MauvilleCity_GameCorner_EventScript_156F5E
	checkitemspace ITEM_TM24, 1
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_156F6C
	removecoins 4000
	additem ITEM_TM24, 1
	updatecoins 0, 0
	playsfx 95
	msgbox MauvilleCity_GameCorner_Text_181F08, 4
	jump MauvilleCity_GameCorner_EventScript_156D49
	end

MauvilleCity_GameCorner_EventScript_156F24:: @ 8156F24
	checkcoins 16386
	compare 0x4002, 4000
	jumpif 0, MauvilleCity_GameCorner_EventScript_156F5E
	checkitemspace ITEM_TM13, 1
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_156F6C
	removecoins 4000
	additem ITEM_TM13, 1
	updatecoins 0, 0
	playsfx 95
	msgbox MauvilleCity_GameCorner_Text_181F08, 4
	jump MauvilleCity_GameCorner_EventScript_156D49
	end

MauvilleCity_GameCorner_EventScript_156F5E:: @ 8156F5E
	msgbox MauvilleCity_GameCorner_Text_181E76, 4
	jump MauvilleCity_GameCorner_EventScript_156D49
	end

MauvilleCity_GameCorner_EventScript_156F6C:: @ 8156F6C
	call MauvilleCity_GameCorner_EventScript_1A02A5
	jump MauvilleCity_GameCorner_EventScript_156D49
	end

MauvilleCity_GameCorner_EventScript_156F77:: @ 8156F77
	msgbox MauvilleCity_GameCorner_Text_181EC2, 4
	hidecoins 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_156F84:: @ 8156F84
	msgbox MauvilleCity_GameCorner_Text_1821C1, 2
	end

MauvilleCity_GameCorner_EventScript_156F8D:: @ 8156F8D
	msgbox MauvilleCity_GameCorner_Text_1821F3, 2
	end

MauvilleCity_GameCorner_EventScript_156F96:: @ 8156F96
	lock
	faceplayer
	checkflag 226
	jumpeq MauvilleCity_GameCorner_EventScript_157072
	msgbox MauvilleCity_GameCorner_Text_181F3D, 5
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_157068
	switch 0x4023
	case 0, MauvilleCity_GameCorner_EventScript_156FDB
	case 1, MauvilleCity_GameCorner_EventScript_157005
	case 2, MauvilleCity_GameCorner_EventScript_15702F
	end

MauvilleCity_GameCorner_EventScript_156FDB:: @ 8156FDB
	bufferdecor 1, 88
	checkdecor 88
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_157059
	msgbox MauvilleCity_GameCorner_Text_181F89, 4
	givedecoration 88
	setflag 226
	jump MauvilleCity_GameCorner_EventScript_157072
	end

MauvilleCity_GameCorner_EventScript_157005:: @ 8157005
	bufferdecor 1, 89
	checkdecor 89
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_157059
	msgbox MauvilleCity_GameCorner_Text_181F89, 4
	givedecoration 89
	setflag 226
	jump MauvilleCity_GameCorner_EventScript_157072
	end

MauvilleCity_GameCorner_EventScript_15702F:: @ 815702F
	bufferdecor 1, 90
	checkdecor 90
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_157059
	msgbox MauvilleCity_GameCorner_Text_181F89, 4
	givedecoration 90
	setflag 226
	jump MauvilleCity_GameCorner_EventScript_157072
	end

MauvilleCity_GameCorner_EventScript_157059:: @ 8157059
	call MauvilleCity_GameCorner_EventScript_1A02B8
	msgbox MauvilleCity_GameCorner_Text_181F97, 4
	release
	end

MauvilleCity_GameCorner_EventScript_157068:: @ 8157068
	msgbox MauvilleCity_GameCorner_Text_181FBC, 4
	release
	end

MauvilleCity_GameCorner_EventScript_157072:: @ 8157072
	msgbox MauvilleCity_GameCorner_Text_181FE9, 4
	release
	end

MauvilleCity_GameCorner_EventScript_15707C:: @ 815707C
	lock
	faceplayer
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 1
	jumpeq MauvilleCity_GameCorner_EventScript_15709C
	msgbox MauvilleCity_GameCorner_Text_18201E, 4
	jump MauvilleCity_GameCorner_EventScript_157108
	end

MauvilleCity_GameCorner_EventScript_15709C:: @ 815709C
	checkflag 225
	jumpeq MauvilleCity_GameCorner_EventScript_1570CA
	checkcoins 16385
	compare 0x4001, 1
	jumpif 4, MauvilleCity_GameCorner_EventScript_1570CA
	setflag 225
	givecoins 20
	msgbox MauvilleCity_GameCorner_Text_18208E, 4
	playsfx 95
	jump MauvilleCity_GameCorner_EventScript_1570CA
	end

MauvilleCity_GameCorner_EventScript_1570CA:: @ 81570CA
	msgbox MauvilleCity_GameCorner_Text_1820DD, 4
	jump MauvilleCity_GameCorner_EventScript_157108
	end

MauvilleCity_GameCorner_EventScript_1570D8:: @ 81570D8
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_182120, 4
	jump MauvilleCity_GameCorner_EventScript_157108
	end

MauvilleCity_GameCorner_EventScript_1570E8:: @ 81570E8
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_18217C, 4
	jump MauvilleCity_GameCorner_EventScript_157108
	end

MauvilleCity_GameCorner_EventScript_1570F8:: @ 81570F8
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_182241, 4
	jump MauvilleCity_GameCorner_EventScript_157108
	end

MauvilleCity_GameCorner_EventScript_157108:: @ 8157108
	closebutton
	move LAST_TALKED, MauvilleCity_GameCorner_Movement_1A083D
	waitmove 0
	release
	end

MauvilleCity_GameCorner_EventScript_157115:: @ 8157115
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_182272, 4
	jump MauvilleCity_GameCorner_EventScript_157108
	end

MauvilleCity_GameCorner_EventScript_157125:: @ 8157125
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_1822F4, 4
	jump MauvilleCity_GameCorner_EventScript_157108
	end

MauvilleCity_GameCorner_EventScript_157135:: @ 8157135
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_1572B5
	setvar 0x8004, 0
	specialval RESULT, 286
	pokecasino RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_157155:: @ 8157155
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_1572B5
	setvar 0x8004, 1
	specialval RESULT, 286
	pokecasino RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_157175:: @ 8157175
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_1572B5
	setvar 0x8004, 2
	specialval RESULT, 286
	pokecasino RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_157195:: @ 8157195
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_1572B5
	setvar 0x8004, 3
	specialval RESULT, 286
	pokecasino RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_1571B5:: @ 81571B5
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_1572B5
	setvar 0x8004, 4
	specialval RESULT, 286
	pokecasino RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_1571D5:: @ 81571D5
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_1572B5
	setvar 0x8004, 5
	specialval RESULT, 286
	pokecasino RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_1571F5:: @ 81571F5
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_1572B5
	setvar 0x8004, 6
	specialval RESULT, 286
	pokecasino RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_157215:: @ 8157215
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_1572B5
	setvar 0x8004, 7
	specialval RESULT, 286
	pokecasino RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_157235:: @ 8157235
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_1572B5
	setvar 0x8004, 8
	specialval RESULT, 286
	pokecasino RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_157255:: @ 8157255
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_1572B5
	setvar 0x8004, 9
	specialval RESULT, 286
	pokecasino RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_157275:: @ 8157275
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_1572B5
	setvar 0x8004, 10
	specialval RESULT, 286
	pokecasino RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_157295:: @ 8157295
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	jumpeq MauvilleCity_GameCorner_EventScript_1572B5
	setvar 0x8004, 11
	specialval RESULT, 286
	pokecasino RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_1572B5:: @ 81572B5
	msgbox MauvilleCity_GameCorner_Text_182420, 4
	releaseall
	end

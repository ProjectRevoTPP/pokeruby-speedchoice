#ifndef GUARD_SONGS_H
#define GUARD_SONGS_H

enum
{
    /*0x00*/ SE_STOP,
    /*0x01*/ SE_KAIFUKU,
    /*0x02*/ SE_PC_LOGON,
    /*0x03*/ SE_PC_OFF,
    /*0x04*/ SE_PC_ON,
    /*0x05*/ SE_SELECT,
    /*0x06*/ SE_WIN_OPEN,
    /*0x07*/ SE_WALL_HIT,
    /*0x08*/ SE_DOOR,
    /*0x09*/ SE_KAIDAN,
    /*0x0A*/ SE_DANSA,
    /*0x0B*/ SE_JITENSYA,
    /*0x0C*/ SE_KOUKA_L,
    /*0x0D*/ SE_KOUKA_M,
    /*0x0E*/ SE_KOUKA_H,
    /*0x0F*/ SE_BOWA2,
    /*0x10*/ SE_POKE_DEAD,
    /*0x11*/ SE_NIGERU,
    /*0x12*/ SE_JIDO_DOA,
    /*0x13*/ SE_NAMINORI,
    /*0x14*/ SE_BAN,
    /*0x15*/ SE_PIN,
    /*0x16*/ SE_BOO,
    /*0x17*/ SE_BOWA,
    /*0x18*/ SE_JYUNI,
    /*0x19*/ SE_A,
    /*0x1A*/ SE_I,
    /*0x1B*/ SE_U,
    /*0x1C*/ SE_E,
    /*0x1D*/ SE_O,
    /*0x1E*/ SE_N,
    /*0x1F*/ SE_SEIKAI,
    /*0x20*/ SE_HAZURE,
    SE_EXP,
    SE_JITE_PYOKO,
    SE_MU_PACHI,
    SE_TK_KASYA,
    SE_FU_ZAKU,
    SE_FU_ZAKU2,
    SE_FU_ZUZUZU,
    SE_RU_GASHIN,
    SE_RU_GASYAN,
    SE_RU_BARI,
    SE_RU_HYUU,
    SE_KI_GASYAN,
    SE_TK_WARPIN,
    SE_TK_WARPOUT,
    SE_TU_SAA,
    SE_HI_TURUN,
    SE_TRACK_MOVE,
    SE_TRACK_STOP,
    SE_TRACK_HAIK,
    SE_TRACK_DOOR,
    SE_MOTER,
    SE_CARD,
    SE_SAVE,
    SE_KON,
    SE_KON2,
    SE_KON3,
    SE_KON4,
    SE_SUIKOMU,
    SE_NAGERU,
    SE_TOY_C,
    SE_TOY_D,
    SE_TOY_E,
    SE_TOY_F,
    SE_TOY_G,
    SE_TOY_A,
    SE_TOY_B,
    SE_TOY_C1,
    SE_MIZU,
    SE_HASHI,
    SE_DAUGI,
    SE_PINPON,
    SE_FUUSEN1,
    SE_FUUSEN2,
    SE_FUUSEN3,
    SE_TOY_KABE,
    SE_TOY_DANGO,
    SE_DOKU,
    SE_ESUKA,
    SE_T_AME,
    SE_T_AME_E,
    SE_T_OOAME,
    SE_T_OOAME_E,
    SE_T_KOAME,
    SE_T_KOAME_E,
    SE_T_KAMI,
    SE_T_KAMI2,
    SE_ELEBETA,
    /*0x5A*/ SE_HINSI,
    SE_EXPMAX,
    SE_TAMAKORO,
    SE_TAMAKORO_E,
    SE_BASABASA,
    SE_REGI,
    SE_C_GAJI,
    SE_C_MAKU_U,
    SE_C_MAKU_D,
    SE_C_PASI,
    SE_C_SYU,
    SE_C_PIKON,
    SE_REAPOKE,
    SE_OP_BASYU,
    SE_BT_START,
    SE_DENDOU,
    SE_JIHANKI,
    SE_TAMA,
    SE_Z_SCROLL,
    /*0x6D*/ SE_Z_PAGE,
    /*0x6E*/ SE_PN_ON,
    /*0x6F*/ SE_PN_OFF,
    /*0x70*/ SE_Z_SEARCH,
    /*0x71*/ SE_TAMAGO,
    /*0x72*/ SE_TB_START,
    /*0x73*/ SE_TB_KON,
    /*0x74*/ SE_TB_KARA,
    /*0x75*/ SE_BIDORO,
    SE_W085,
    SE_W085B,
    SE_W231,
    SE_W171,
    SE_W233,
    SE_W233B,
    SE_W145,
    SE_W145B,
    SE_W145C,
    SE_W240,
    SE_W015,
    SE_W081,
    SE_W081B,
    SE_W088,
    SE_W016,
    SE_W016B,
    SE_W003,
    SE_W104,
    SE_W013,
    SE_W196,
    SE_W086,
    SE_W004,
    SE_W025,
    SE_W025B,
    SE_W152,
    SE_W026,
    SE_W172,
    SE_W172B,
    SE_W053,
    SE_W007,
    SE_W092,
    SE_W221,
    SE_W221B,
    SE_W052,
    SE_W036,
    SE_W059,
    SE_W059B,
    SE_W010,
    SE_W011,
    SE_W017,
    SE_W019,
    SE_W028,
    SE_W013B,
    SE_W044,
    SE_W029,
    SE_W057,
    SE_W056,
    SE_W250,
    SE_W030,
    SE_W039,
    SE_W054,
    SE_W077,
    SE_W020,
    SE_W082,
    SE_W047,
    SE_W195,
    SE_W006,
    SE_W091,
    SE_W146,
    SE_W120,
    SE_W153,
    SE_W071B,
    SE_W071,
    SE_W103,
    SE_W062,
    SE_W062B,
    SE_W048,
    SE_W187,
    SE_W118,
    SE_W155,
    SE_W122,
    SE_W060,
    SE_W185,
    SE_W014,
    SE_W043,
    SE_W207,
    SE_W207B,
    SE_W215,
    SE_W109,
    SE_W173,
    SE_W280,
    SE_W202,
    SE_W060B,
    SE_W076,
    SE_W080,
    SE_W100,
    SE_W107,
    SE_W166,
    SE_W129,
    SE_W115,
    SE_W112,
    SE_W197,
    SE_W199,
    SE_W236,
    SE_W204,
    SE_W268,
    SE_W070,
    SE_W063,
    SE_W127,
    SE_W179,
    SE_W151,
    SE_W201,
    SE_W161,
    SE_W161B,
    SE_W227,
    SE_W227B,
    SE_W226,
    SE_W208,
    SE_W213,
    SE_W213B,
    SE_W234,
    SE_W260,
    SE_W328,
    SE_W320,
    SE_W255,
    SE_W291,
    SE_W089,
    SE_W239,
    SE_W230,
    SE_W281,
    SE_W327,
    SE_W287,
    SE_W257,
    SE_W253,
    SE_W258,
    SE_W322,
    SE_W298,
    SE_W287B,
    SE_W114,
    SE_W063B,
    BGM_STOP = 349,
    BGM_TETSUJI,
    BGM_FIELD13,
    BGM_KACHI22,
    BGM_KACHI2,
    BGM_KACHI3,
    BGM_KACHI5,
    BGM_PCC,
    BGM_NIBI,
    BGM_SUIKUN,
    BGM_DOORO1,
    BGM_DOORO_X1,
    BGM_DOORO_X3,
    BGM_MACHI_S2,
    BGM_MACHI_S4,
    BGM_GIM,
    BGM_NAMINORI,
    BGM_DAN01,
    /*0x16F*/ BGM_FANFA1,
    BGM_ME_ASA,
    BGM_ME_BACHI,
    BGM_FANFA4,
    BGM_FANFA5,
    BGM_ME_WAZA,
    BGM_BIJYUTU,
    BGM_DOORO_X4,
    BGM_FUNE_KAN,
    BGM_ME_SHINKA,
    BGM_SHINKA,
    BGM_ME_WASURE,
    BGM_SYOUJOEYE,
    BGM_BOYEYE,
    BGM_DAN02,
    BGM_MACHI_S3,
    BGM_ODAMAKI,
    BGM_B_TOWER,
    BGM_SWIMEYE,
    BGM_DAN03,
    BGM_ME_KINOMI,
    BGM_ME_TAMA,
    BGM_ME_B_BIG,
    BGM_ME_B_SMALL,
    BGM_ME_ZANNEN,
    BGM_BD_TIME,
    BGM_TEST1,
    BGM_TEST2,
    BGM_TEST3,
    BGM_TEST4,
    BGM_TEST,
    BGM_GOMACHI0,
    BGM_GOTOWN,
    BGM_POKECEN,
    BGM_NEXTROAD,
    BGM_GRANROAD,
    BGM_CYCLING,
    BGM_FRIENDLY,
    BGM_MISHIRO,
    BGM_TOZAN,
    BGM_GIRLEYE,
    BGM_MINAMO,
    BGM_ASHROAD,
    BGM_EVENT0,
    BGM_DEEPDEEP,
    BGM_KACHI1,
    BGM_TITLE3,
    BGM_DEMO1,
    BGM_GIRL_SUP,
    BGM_HAGESHII,
    BGM_KAKKOII,
    BGM_KAZANBAI,
    BGM_AQA_0,
    BGM_TSURETEK,
    BGM_BOY_SUP,
    BGM_RAINBOW,
    BGM_AYASII,
    BGM_KACHI4,
    BGM_ROPEWAY,
    BGM_CASINO,
    BGM_HIGHTOWN,
    BGM_SAFARI,
    BGM_C_ROAD,
    BGM_AJITO,
    BGM_M_BOAT,
    BGM_M_DUNGON,
    BGM_FINECITY,
    BGM_MACHUPI,
    BGM_P_SCHOOL,
    BGM_DENDOU,
    BGM_TONEKUSA,
    BGM_MABOROSI,
    BGM_CON_FAN,
    BGM_CONTEST0,
    BGM_MGM0,
    BGM_T_BATTLE,
    BGM_OOAME,
    BGM_HIDERI,
    BGM_RUNECITY,
    BGM_CON_K,
    BGM_EIKOU_R,
    BGM_KARAKURI,
    BGM_HUTAGO,
    BGM_SITENNOU,
    BGM_YAMA_EYE,
    BGM_CONLOBBY,
    BGM_INTER_V,
    BGM_DAIGO,
    BGM_THANKFOR,
    BGM_END,
    BGM_BATTLE27, // wild
    BGM_BATTLE31, // aqua/magma grunt
    BGM_BATTLE20, // trainer
    BGM_BATTLE32, // gym leader
    BGM_BATTLE33, // champion
    BGM_BATTLE36, // regi
    BGM_BATTLE34, // weather trio
    BGM_BATTLE35, // rival
    BGM_BATTLE38, // elite four
    BGM_BATTLE30, // aqua/magma leader
};

#endif // GUARD_SONGS_H

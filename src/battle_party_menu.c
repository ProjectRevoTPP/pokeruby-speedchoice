#include "global.h"
#include "battle_party_menu.h"
#include "asm.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "pokemon.h"
#include "songs.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"

#define DATA_COUNT (6)

extern u8 ewram[];

struct Unk201B000
{
    //u8 filler0[0x260];
    struct Pokemon unk0[6];
    u8 filler258[1];
    u8 unk259;
    u8 filler25A[6];
    u8 unk260;
    u8 unk261;
    u8 filler262[2];
    s16 unk264[DATA_COUNT * 2];  // This may be a union
    u8 filler27C[2];
    s16 unk27E;
    s16 unk280;
    s16 unk282;
};

#define ewram1B000 (*(struct Unk201B000 *)(ewram + 0x1B000))
#define UNK_201606C_ARRAY (ewram + 0x1606C) // lazy define but whatever.

extern u8 IsLinkDoubleBattle(void);
extern void TryCreatePartyMenuMonIcon(u8, u8, struct Pokemon *);
extern void LoadHeldItemIconGraphics(void);
extern void CreateHeldItemIcons_806DC34();
extern u8 sub_806BD58(u8, u8);
extern void PartyMenuPrintMonsLevelOrStatus(void);
extern void PrintPartyMenuMonNicknames(void);
extern void PartyMenuTryPrintMonsHP(void);
extern void nullsub_13(void);
extern void PartyMenuDrawHPBars(void);
extern u8 sub_806B58C(u8);
extern u8 GetItemEffectType();
extern void sub_806E750(u8, const struct PartyPopupMenu *, const struct PartyMenuItem *, int);
extern u16 sub_806BD80();
extern u8 sub_806CA38();
extern void sub_806D5A4(void);
extern void sub_802E414(void);
extern void sub_80A6DCC(void);
extern void sub_806AF4C();
extern u8 sub_80F9344(void);
extern u8 sub_806B124(void);
extern void sub_806C994();
extern void sub_806BF74();
extern void sub_806AEDC(void);
extern TaskFunc PartyMenuGetPopupMenuFunc(u8, const struct PartyPopupMenu *, const struct PartyMenuItem *, u8);
extern void ShowPokemonSummaryScreen(struct Pokemon *, u8, u8, void (*)(u8), int);
extern void sub_806E7D0(u8, const struct PartyPopupMenu *);
extern u8 *sub_8040D08();
extern void sub_8040B8C(void);
extern void sub_806E6F0();
extern void sub_806D538();
extern void nullsub_14();
extern void OpenPartyMenu();
extern u8 sub_803FBBC(void);

extern u16 gScriptItemId;
extern u8 gPlayerPartyCount;
extern u8 gNoOfAllBanks;
extern u16 gBattlePartyID[];
extern u8 gBankInMenu;
extern u8 gUnknown_0202E8F4;
extern u8 gUnknown_0202E8F5;
extern u8 gUnknown_0202E8F6;
extern u8 gUnknown_02038470[3];
extern u8 gUnknown_02038473;
extern u8 gUnknown_020384F0;
extern void (*gUnknown_03004AE4)();  //don't know types yet
extern struct PokemonStorage gPokemonStorage;

void sub_8094C98(u8, u8);
static void sub_8094998(u8[3], u8);
static void sub_8094A74(u8[3], u8, u32);
u8 pokemon_order_func(u8);
static void sub_8094D60(void);
static void Task_809527C(u8);
static void Task_80952B4(u8);
static void Task_80952E4(u8);
static void Task_8095330(u8);
static void Task_809538C(void);
static void Task_HandlePopupMenuInput(u8);
static void Task_BattlePartyMenuSummary(u8 taskId);
static void Task_BattlePartyMenuShift(u8 taskId);
static void Task_BattlePartyMenuCancel(u8 taskId);

static const struct PartyMenuItem sBattlePartyMenuActions[] =
{
    {OtherText_Summary,             Task_BattlePartyMenuSummary},
    {gOtherText_CancelNoTerminator, Task_BattlePartyMenuCancel},
    {OtherText_Shift,               Task_BattlePartyMenuShift},
    {OtherText_SendOut,             Task_BattlePartyMenuShift},
};
static const u8 Unknown_83B5FEC[] = {2, 0, 1};  //SHIFT, SUMMARY, CANCEL
static const u8 Unknown_83B5FEF[] = {3, 0, 1};  //SEND OUT, SUMMARY, CANCEL
static const u8 Unknown_83B5FF2[] = {0, 1};     //SUMMARY, CANCEL
static const struct PartyPopupMenu sBattlePartyPopupMenus[] =
{
    {ARRAY_COUNT(Unknown_83B5FEC), 9, Unknown_83B5FEC},
    {ARRAY_COUNT(Unknown_83B5FEF), 9, Unknown_83B5FEF},
    {ARRAY_COUNT(Unknown_83B5FF2), 9, Unknown_83B5FF2},
};

void unref_sub_8094928(struct PokemonStorage *ptr)
{
    *ptr = gPokemonStorage;
}

void unref_sub_8094940(struct PokemonStorage *ptr)
{
    gPokemonStorage = *ptr;
}

void sub_8094958(void)
{
    sub_8094998(gUnknown_02038470, sub_803FBBC());
}

void sub_8094978(u8 arg1, u8 arg2)
{
    sub_8094A74((UNK_201606C_ARRAY) + arg1 * 3, arg2, arg1);
}

static void sub_8094998(u8 arg[3], u8 player_number)
{
    int i;
    u32 pos;
    u8 temp[6];
    if (IsLinkDoubleBattle() == TRUE)
    {
        if (player_number)
        {
            *arg = 0x30;
            arg[1] = 0x45;
            arg[2] = 0x12;
        }
        else
        {
            *arg = 0x03;
            arg[1] = 0x12;
            arg[2] = 0x45;
        }
    }
    else
    {
        if (!IsDoubleBattle())
        {
            pos = 1;
            *temp = gBattlePartyID[GetBankByPlayerAI(0)];
            for (i = 0; i <= 5; i++)
                if (i != *temp)
                    temp[pos++] = i;
        }
        else
        {
            pos = 2;
            *temp = gBattlePartyID[GetBankByPlayerAI(0)];
            temp[1] = gBattlePartyID[GetBankByPlayerAI(2)];
            for (i = 0; i <= 5; i++)
                if ((i != *temp) && (i != temp[1]))
                    temp[pos++] = i;
        }
        for (i = 0; i <= 2; i++)
            arg[i] = (temp[i << 1] << 4) | temp[(i << 1) + 1];
    }
}

static void sub_8094A74(u8 arg[3], u8 player_number, u32 arg3)
{
    int i, j;
    u8 temp[6];
    if (!GetBankSide(arg3))
    {
        i = GetBankByPlayerAI(0);
        j = GetBankByPlayerAI(2);
    }
    else
    {
        i = GetBankByPlayerAI(1);
        j = GetBankByPlayerAI(3);
    }
    if (IsLinkDoubleBattle() == TRUE)
    {
        if (player_number)
        {
            *arg = 0x30;
            arg[1] = 0x45;
            arg[2] = 0x12;
        }
        else
        {
            *arg = 0x03;
            arg[1] = 0x12;
            arg[2] = 0x45;
        }
    }
    else
    {
        if (!IsDoubleBattle())
        {
            int pos = 1;
            *temp = gBattlePartyID[i];
            for (i = 0; i <= 5; i++)
                if (i != *temp)
                    temp[pos++] = i;
        }
        else
        {
            int pos = 2;
            *temp = gBattlePartyID[i];
            temp[1] = gBattlePartyID[j];
            for (i = 0; i <= 5; i++)
                if ((i != *temp) && (i != temp[1]))
                    temp[pos++] = i;
        }
        for (i = 0; i <= 2; i++)
            arg[i] = (temp[i << 1] << 4) | temp[(i << 1) + 1];
    }
}

void sub_8094B6C(u8 a, u8 b, u8 c)
{
    s32 i;
    s32 j;
    u8 temp[6];
    u8 r3;
    u8 r7 = 0;

    if (IsLinkDoubleBattle())
    {
        u8 *arr = ewram + 0x1606C + a * 3;

        for (i = 0, j = 0; i < 3; i++)
        {
            temp[j++] = arr[i] >> 4;
            temp[j++] = arr[i] & 0xF;
        }
        r3 = temp[c];
        for (i = 0; i < 6; i++)
        {
            if (temp[i] == b)
            {
                r7 = temp[i];
                temp[i] = r3;
                break;
            }
        }
        if (i != 6)
        {
            temp[c] = r7;

            arr[0] = (temp[0] << 4) | temp[1];
            arr[1] = (temp[2] << 4) | temp[3];
            arr[2] = (temp[4] << 4) | temp[5];
        }
    }
}

u8 sub_8094C20(u8 a)
{
    u8 retVal;
    u8 val = a & 1;

    a /= 2;
    if (val)
        retVal = gUnknown_02038470[a] & 0xF;
    else
        retVal = gUnknown_02038470[a] >> 4;
    return retVal;
}

void sub_8094C54(u8 a, u8 b)
{
    u8 val = a & 1;

    a /= 2;
    if (val)
        gUnknown_02038470[a] = (gUnknown_02038470[a] & 0xF0) | b;
    else
        gUnknown_02038470[a] = (gUnknown_02038470[a] & 0xF) | (b << 4);
}

void sub_8094C98(u8 a, u8 b)
{
    u8 r4 = sub_8094C20(a);
    u8 r1 = sub_8094C20(b);

    sub_8094C54(a, r1);
    sub_8094C54(b, r4);
}

u8 pokemon_order_func(u8 a)
{
    u8 i;
    u8 r2;

    for (i = 0, r2 = 0; i < 3; i++)
    {
        if ((gUnknown_02038470[i] >> 4) == a)
            return r2;
        r2++;
        if ((gUnknown_02038470[i] & 0xF) == a)
            return r2;
        r2++;
    }
    return 0;
}

void pokemon_change_order(void)
{
    u8 i;

    memcpy(ewram1B000.unk0, gPlayerParty, sizeof(gPlayerParty));
    for (i = 0; i < 6; i++)
    {
        u8 n = pokemon_order_func(i);

        memcpy(&gPlayerParty[n], &ewram1B000.unk0[i], sizeof(struct Pokemon));
    }
}

static void sub_8094D60(void)
{
    struct Pokemon temp[6];
    u8 i;

    memcpy(temp, gPlayerParty, sizeof(gPlayerParty));
    for (i = 0; i < 6; i++)
    {
        u8 n = sub_8094C20(i);

        memcpy(&gPlayerParty[n], &temp[i], sizeof(struct Pokemon));
    }
}

void unref_sub_8094DB0(void)
{
    u8 i;
    u8 r4;

    for (i = 1; i < 6; i++)
    {
        u8 n = sub_8094C20(i);

        if (GetMonData(&gPlayerParty[n], MON_DATA_SPECIES) != 0
         && GetMonData(&gPlayerParty[n], MON_DATA_HP) != 0)
        {
            r4 = sub_8094C20(0);
            sub_8094C98(0, i);
            sub_806E6F0(&gPlayerParty[r4], &gPlayerParty[n]);
            break;
        }
    }
}

void sub_8094E20(u8 a)
{
    gPaletteFade.bufferTransferDisabled = TRUE;
    gUnknown_02038473 = a;
    nullsub_14();
    pokemon_change_order();
    OpenPartyMenu(1, 0xFF);
}

void sub_8094E4C(void)
{
    sub_8094E20(3);
}

int SetUpBattlePartyMenu(void)
{
    switch (EWRAM_1B000.unk264)
    //switch (ewram1B000.unk264[0])
    {
    case 0:
        //TODO: try to get rid of this duplicate code
        if (IsLinkDoubleBattle() == TRUE)
        {
            if (EWRAM_1B000.unk266 != 6)
            {
                TryCreatePartyMenuMonIcon(EWRAM_1B000.unk260, EWRAM_1B000.unk266, &gPlayerParty[EWRAM_1B000.unk266]);
                EWRAM_1B000.unk266++;
            }
            else
            {
                EWRAM_1B000.unk266 = 0;
                EWRAM_1B000.unk264++;
            }
        }
        else
        {
            if (EWRAM_1B000.unk266 < 6)
            {
                TryCreatePartyMenuMonIcon(EWRAM_1B000.unk260, EWRAM_1B000.unk266, &gPlayerParty[EWRAM_1B000.unk266]);
                EWRAM_1B000.unk266++;
            }
            else
            {
                EWRAM_1B000.unk266 = 0;
                EWRAM_1B000.unk264++;
            }
        }
        break;
    case 1:
        LoadHeldItemIconGraphics();
        EWRAM_1B000.unk264++;
        break;
    case 2:
        CreateHeldItemIcons_806DC34(EWRAM_1B000.unk260);
        EWRAM_1B000.unk264++;
        break;
    case 3:
        if (sub_806BD58(EWRAM_1B000.unk260, EWRAM_1B000.unk266) == 1)
        {
            EWRAM_1B000.unk266 = 0;
            EWRAM_1B000.unk264++;
        }
        else
            EWRAM_1B000.unk266++;
        break;
    case 4:
        PartyMenuPrintMonsLevelOrStatus();
        EWRAM_1B000.unk264++;
        break;
    case 5:
        PrintPartyMenuMonNicknames();
        EWRAM_1B000.unk264++;
        break;
    case 6:
        PartyMenuTryPrintMonsHP();
        EWRAM_1B000.unk264++;
        break;
    case 7:
        nullsub_13();
        EWRAM_1B000.unk264++;
        break;
    case 8:
        PartyMenuDrawHPBars();
        EWRAM_1B000.unk264++;
        break;
    case 9:
        if (sub_806B58C(EWRAM_1B000.unk266) == 1)
        {
            EWRAM_1B000.unk266 = 0;
            EWRAM_1B000.unk264++;
        }
        else
            EWRAM_1B000.unk266++;
        break;
    case 10:
        if (gUnknown_02038473 == 3)
        {
            if (GetItemEffectType(gScriptItemId) == 10)
                ewram1B000.unk259 = 0xFF;
            else
                ewram1B000.unk259 = 3;
        }
        return TRUE;
    }
    return FALSE;
}

static void sub_8095050(u8 a, u8 b)
{
    if (!GetMonData(&gPlayerParty[b], MON_DATA_IS_EGG))
    {
        if (gUnknown_02038473 == 1)
        {
            gTasks[EWRAM_1B000.unk260].data[4] = 1;
            gTasks[EWRAM_1B000.unk260].data[5] = 1;
        }
        else
        {
            gTasks[EWRAM_1B000.unk260].data[4] = 0;
            gTasks[EWRAM_1B000.unk260].data[5] = 0;
        }
    }
    else
    {
        gTasks[EWRAM_1B000.unk260].data[4] = 2;
        gTasks[EWRAM_1B000.unk260].data[5] = 2;
    }
    sub_806E750(gTasks[a].data[4], sBattlePartyPopupMenus, sBattlePartyMenuActions, 0);
}

void SetUpBattlePokemonMenu(u8 a)
{
    if (!gPaletteFade.active)
    {
        if (gUnknown_02038473 == 3 && GetItemEffectType(gScriptItemId) == 10)
        {
            gUnknown_03004AE4(a, gScriptItemId, Task_80952E4);
            return;
        }

        switch (sub_806BD80(a))
        {
        case 1:
            if (gUnknown_02038473 == 3)
            {
                if (GetMonData(&gPlayerParty[sub_806CA38(a)], MON_DATA_IS_EGG))
                    PlaySE(SE_HAZURE);
                else
                {
                    sub_806D5A4();
                    gUnknown_03004AE4(a, gScriptItemId, Task_80952E4);
                }
            }
            else
            {
                PlaySE(SE_SELECT);
                GetMonNickname(&gPlayerParty[sub_806CA38(a)], gStringVar1);
                sub_8095050(a, sub_806CA38(a));
                SetTaskFuncWithFollowupFunc(a, Task_HandlePopupMenuInput, SetUpBattlePokemonMenu);
            }
            break;
        case 2:
            if (gUnknown_02038473 == 1)
                PlaySE(SE_HAZURE);
            else
            {
                PlaySE(SE_SELECT);
                if (gUnknown_02038473 == 3)
                {
                    gUnknown_0202E8F4 = 0;
                    gTasks[a].func = Task_80952E4;
                }
                else
                {
                    gUnknown_0202E8F4 = 0;
                    gTasks[a].func = Task_809527C;
                }
            }
            break;
        }
    }
}

static void Task_809527C(u8 taskId)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
    gTasks[taskId].func = Task_80952B4;
}

static void Task_80952B4(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sub_8094D60();
        DestroyTask(taskId);
        SetMainCallback2(sub_802E414);
    }
}

static void Task_80952E4(u8 taskId)
{
    if (gUnknown_0202E8F4 != 0)
        Task_809527C(taskId);
    else
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
        gTasks[taskId].func = Task_8095330;
    }
}

static void Task_8095330(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sub_8094D60();
        DestroyTask(taskId);
        sub_80A6DCC();
    }
}

static void Task_809535C(u8 taskId)
{
    gPaletteFade.bufferTransferDisabled = TRUE;
    sub_806AF4C(1, 0xFF, SetUpBattlePokemonMenu, 5);
    SetMainCallback2(Task_809538C);
}

static void Task_809538C(void)
{
    do
    {
        if (sub_806B124() == 1)
        {
            sub_806C994(EWRAM_1B000.unk260, gUnknown_020384F0);
            sub_806BF74(EWRAM_1B000.unk260, 0);
            GetMonNickname(&gPlayerParty[gUnknown_020384F0], gStringVar1);
            sub_8095050(EWRAM_1B000.unk260, gUnknown_020384F0);
            SetTaskFuncWithFollowupFunc(EWRAM_1B000.unk260, Task_HandlePopupMenuInput, SetUpBattlePokemonMenu);
            SetMainCallback2(sub_806AEDC);
            return;
        }
    } while (sub_80F9344() != 1);
}

static void Task_HandlePopupMenuInput(u8 taskId)
{
    TaskFunc func;

    if (!gPaletteFade.active)
    {
        if (gMain.newAndRepeatedKeys & DPAD_UP)
        {
            PlaySE(SE_SELECT);
            MoveMenuCursor(-1);
            return;
        }
        if (gMain.newAndRepeatedKeys & DPAD_DOWN)
        {
            PlaySE(SE_SELECT);
            MoveMenuCursor(1);
            return;
        }
        if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            func = PartyMenuGetPopupMenuFunc(gTasks[taskId].data[4],
                               sBattlePartyPopupMenus,
                               sBattlePartyMenuActions,
                               GetMenuCursorPos());
            func(taskId);
            return;
        }
        if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            Task_BattlePartyMenuCancel(taskId);
            return;
        }
    }
}

static void Task_80954C0(u8 taskId)
{
    if (gUnknown_0202E8F6 == 0)
        Task_BattlePartyMenuCancel(taskId);
}

static void Task_ShowSummaryScreen(u8 taskId)
{
    u8 partySelection = sub_806CA38(taskId);

    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        EWRAM_1B000.unk262 = 1;
        ShowPokemonSummaryScreen(gPlayerParty, partySelection, gPlayerPartyCount - 1, Task_809535C, 4);
    }
}

static void Task_BattlePartyMenuSummary(u8 taskId)
{
    sub_806CA38(taskId);  //an unused variable was probably set with this.
    gTasks[taskId].func = Task_ShowSummaryScreen;
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
}

static void Task_BattlePartyMenuShift(u8 taskId)
{
    u8 partySelection;
    u8 i;
    u8 r4;

    sub_806E7D0(gTasks[taskId].data[4], sBattlePartyPopupMenus);
    partySelection = sub_806CA38(taskId);
    if (IsLinkDoubleBattle() == TRUE && (partySelection == 1 || partySelection == 4 || partySelection == 5))
    {
        sub_806D5A4();
        StringCopy(gStringVar1, sub_8040D08());
        StringExpandPlaceholders(gStringVar4, gOtherText_CantSwitchPokeWithYours);
        sub_806E834(gStringVar4, 0);
        gTasks[taskId].func = Task_80954C0;
        return;
    }
    if (GetMonData(&gPlayerParty[partySelection], MON_DATA_HP) == 0)
    {
        sub_806D5A4();
        GetMonNickname(&gPlayerParty[partySelection], gStringVar1);
        StringExpandPlaceholders(gStringVar4, gOtherText_NoEnergyLeft);
        sub_806E834(gStringVar4, 0);
        gTasks[taskId].func = Task_80954C0;
        return;
    }
    for (i = 0; i < gNoOfAllBanks; i++)
    {
        if (GetBankSide(i) == 0
         && sub_8094C20(partySelection) == gBattlePartyID[i])
        {
            sub_806D5A4();
            GetMonNickname(&gPlayerParty[partySelection], gStringVar1);
            StringExpandPlaceholders(gStringVar4, gOtherText_AlreadyBattle);
            sub_806E834(gStringVar4, 0);
            gTasks[taskId].func = Task_80954C0;
            return;
        }
    }
    if (GetMonData(&gPlayerParty[partySelection], MON_DATA_IS_EGG))
    {
        sub_806D5A4();
        StringExpandPlaceholders(gStringVar4, gOtherText_EGGCantBattle);
        sub_806E834(gStringVar4, 0);
        gTasks[taskId].func = Task_80954C0;
        return;
    }
    if (sub_8094C20(partySelection) == EWRAM_1609D)
    {
        sub_806D5A4();
        GetMonNickname(&gPlayerParty[partySelection], gStringVar1);
        StringExpandPlaceholders(gStringVar4, gOtherText_AlreadySelected);
        sub_806E834(gStringVar4, 0);
        gTasks[taskId].func = Task_80954C0;
        return;
    }
    if (gUnknown_02038473 == 4)
    {
        sub_806D5A4();
        sub_8040B8C();
        sub_806E834(gStringVar4, 0);
        gTasks[taskId].func = Task_80954C0;
        return;
    }
    if (gUnknown_02038473 == 2)
    {
        u8 r0;
        u8 r4 = gBankInMenu;

        sub_806D5A4();
        r0 = pokemon_order_func(gBattlePartyID[r4]);
        GetMonNickname(&gPlayerParty[r0], gStringVar1);
        StringExpandPlaceholders(gStringVar4, gOtherText_CantBeSwitched);
        sub_806E834(gStringVar4, 0);
        gTasks[taskId].func = Task_80954C0;
        return;
    }
    gUnknown_0202E8F5 = sub_8094C20(partySelection);
    gUnknown_0202E8F4 = 1;
    r4 = pokemon_order_func(gBattlePartyID[gBankInMenu]);
    sub_8094C98(r4, partySelection);
    sub_806E6F0(&gPlayerParty[r4], &gPlayerParty[partySelection]);
    gTasks[taskId].func = Task_809527C;
}

static void Task_BattlePartyMenuCancel(u8 taskId)
{
    HandleDestroyMenuCursors();
    sub_806E7D0(gTasks[taskId].data[4], sBattlePartyPopupMenus);
    gTasks[taskId].data[4] = gTasks[taskId].data[5];
    sub_806D538(0, 0);
    SwitchTaskToFollowupFunc(taskId);
}

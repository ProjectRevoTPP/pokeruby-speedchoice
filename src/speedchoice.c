#include "global.h"
#include "option_menu.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "sprite.h"
#include "task.h"
#include "sound.h"
#include "songs.h"
#include "string_util.h"
#include "text.h"
#include "speedchoice.h"

// global speedchoice config
#define CURRENT_OPTIONS_NUM 12
#define MAX_CHOICES 6
#define OPTIONS_PER_PAGE 5
#define ALLOPTIONS_PER_PAGE OPTIONS_PER_PAGE + 2 // page + start game
#define MAX_PAGES 3

#define MENUOPTIONCOORDS(i) (5 + (2 * i))

extern void Task_NewGameSpeech1(u8);
extern void remove_some_task(void);

extern u8 gUnknown_0839F63C[];
extern u8 gUnknown_0839F5FC[];  //palette

extern u8 gSystemText_Terminator[];

const u8 gSpeedchoiceTextHeader[] = _("{PALETTE 9}SPEEDCHOICE MENU");

// OPTION CHOICES
const u8 gSpeedchoiceTextYes[] = _("{PALETTE 15}YES");
const u8 gSpeedchoiceTextNo[] = _("{PALETTE 15}NO");
const u8 gSpeedchoiceTextOn[] = _("{PALETTE 15}ON");
const u8 gSpeedchoiceTextOff[] = _("{PALETTE 15}OFF");
const u8 gSpeedchoiceTextNerf[] = _("{PALETTE 15}NERF");
const u8 gSpeedchoiceTextKeep[] = _("{PALETTE 15}KEEP");
const u8 gSpeedchoiceTextHell[] = _("{PALETTE 15}HELL");
const u8 gSpeedchoiceTextSemi[] = _("{PALETTE 15}SEMI");
const u8 gSpeedchoiceTextFull[] = _("{PALETTE 15}FULL");

// PAGE 1
const u8 gSpeedchoiceOptionBWExp[] = _("{PALETTE 8}B/W EXP");
const u8 gSpeedchoiceOptionAqualess[] = _("{PALETTE 15}AQUALESS");
const u8 gSpeedchoiceOptionInstantText[] = _("{PALETTE 15}INSTANT TEXT");
const u8 gSpeedchoiceOptionSpinners[] = _("{PALETTE 8}SPINNERS");
const u8 gSpeedchoiceOptionMaxVision[] = _("{PALETTE 15}MAX VISION");

// PAGE 2
const u8 gSpeedchoiceOptionNerfRoxanne[] = _("{PALETTE 15}NERF ROXANNE");
const u8 gSpeedchoiceOptionSuperBike[] = _("{PALETTE 15}SUPER BIKE");
const u8 gSpeedchoiceOptionNewWildEnc[] = _("{PALETTE 15}NEW WILD ENC.");
const u8 gSpeedchoiceOptionEarlyFly[] = _("{PALETTE 15}EARLY FLY");
const u8 gSpeedchoiceOptionRunEverywhere[] = _("{PALETTE 15}RUN EVERYWHERE");

// PAGE 3
const u8 gSpeedchoiceOptionMemeIsland[] = _("{PALETTE 15}MEME ISLAND");
const u8 gSpeedchoiceOptionEmeraldDoubles[] = _("{PALETTE 15}EMERALD DOUBLES");

// CONSTANT OPTIONS
const u8 gSpeedchoiceOptionPage[] = _("{PALETTE 15}PAGE");
const u8 gSpeedchoiceOptionStartGame[] = _("{PALETTE 15}START GAME");

// TOOLTIPS
const u8 gSpeedchoiceTooltipBWEXP[] = _("(WIP) Will replace the\ncurrent experience system\pin favor of Black/White’s\nimplementation.");
const u8 gSpeedchoiceTooltipAqualess[] = _("SEMI: Stops villian team events\nafter Mt. Chimney.\pFULL: Skips all the villian team\nevents. Also allows Dive to be used\pwithout Gym 7’s badge.");
const u8 gSpeedchoiceTooltipInstantText[] = _("Self-explanatory.\nHold A or B to mash.");
const u8 gSpeedchoiceTooltipSpinners[] = _("(WIP)\nNERF: Will prevent\pspinners from noticing\nthe player while running.\pHELL: Rapidly spins\nevery spinner every frame.");
const u8 gSpeedchoiceTooltipMaxVision[] = _("Extends trainer vision to 8.");
const u8 gSpeedchoiceTooltipNerfRoxanne[] = _("Reduces Gym Leader Roxanne’s\nteam levels by 2 and\premoves 1 of her potions.");
const u8 gSpeedchoiceTooltipSuperBike[] = _("While riding the bicycle, you\ncan switch between bikes with\pthe R button.");
const u8 gSpeedchoiceTooltipNewWildEnc[] = _("Intended to be used with\nthe randomizer.\pTreats grass and fishing slots\nas 6 and 2 slots respectively.");
const u8 gSpeedchoiceTooltipEarlyFly[] = _("Recieve HM02 instead of\nItemfinder at Rival 2.\pAllows use of Fly without use of\nGym 6’s badge.");
const u8 gSpeedchoiceTooltipRunEverywhere[] = _("Allows the Running Shoes to\nbe used anywhere, including\pinside of houses.\pAlso allows bike in most places.");
const u8 gSpeedchoiceTooltipMemeIsland[] = _("Mirage Island always appears.");
const u8 gSpeedchoiceTooltipEmeraldDoubles[] = _("Treat double battle trainers\n(such as twins) as having either\p0 vision or greater than 1 vision.");

// START GAME
const u8 gSpeedchoiceStartGameText[] = _("CV: {STR_VAR_1}\nStart the game?");

const struct OptionChoiceConfig OptionChoiceConfigYesNo[MAX_CHOICES] = 
{
    { 184, 40, (u8 *)&gSpeedchoiceTextYes },
    { 155, 40, (u8 *)&gSpeedchoiceTextNo },
    { -1, -1, NULL },
    { -1, -1, NULL },
    { -1, -1, NULL },
    { -1, -1, NULL }
};

const struct OptionChoiceConfig OptionChoiceConfigOnOff[MAX_CHOICES] = 
{
    { 184, 40, (u8 *)&gSpeedchoiceTextOn },
    { 155, 40, (u8 *)&gSpeedchoiceTextOff },
    { -1, -1, NULL },
    { -1, -1, NULL },
    { -1, -1, NULL },
    { -1, -1, NULL }
};

const struct OptionChoiceConfig OptionChoiceConfigNerfKeep[MAX_CHOICES] = 
{
    { 124, 40, (u8 *)&gSpeedchoiceTextNerf },
    { 154, 40, (u8 *)&gSpeedchoiceTextKeep },
    { 184, 40, (u8 *)&gSpeedchoiceTextHell },
    { -1, -1, NULL },
    { -1, -1, NULL },
    { -1, -1, NULL }
};

const struct OptionChoiceConfig OptionChoiceConfigSemiFull[MAX_CHOICES] = 
{
    { 124, 40, (u8 *)&gSpeedchoiceTextSemi },
    { 154, 40, (u8 *)&gSpeedchoiceTextKeep },
    { 184, 40, (u8 *)&gSpeedchoiceTextFull },
    { -1, -1, NULL },
    { -1, -1, NULL },
    { -1, -1, NULL }
};

// this is totally weird, but in order to use ProcessGeneralInput, a struct is needed for page, so, I opt to have a dummy struct which only has the number of choices relevent to the calculation of the selection.
const struct OptionChoiceConfig OptionChoiceConfigPage[MAX_CHOICES] = 
{
    { -1, -1, NULL },
    { -1, -1, NULL },
    { -1, -1, NULL },
    { -1, -1, NULL },
    { -1, -1, NULL },
    { -1, -1, NULL }
};

const struct SpeedchoiceOption SpeedchoiceOptions[CURRENT_OPTIONS_NUM + 1] = // plus one for page.
{
    { 2, (u8 *)&gSpeedchoiceOptionBWExp, (struct OptionChoiceConfig *)OptionChoiceConfigOnOff, (u8 *)&gSpeedchoiceTooltipBWEXP, OFF, FALSE },
    { 3, (u8 *)&gSpeedchoiceOptionAqualess, (struct OptionChoiceConfig *)OptionChoiceConfigSemiFull, (u8 *)&gSpeedchoiceTooltipAqualess, KEEP, TRUE },
    { 2, (u8 *)&gSpeedchoiceOptionInstantText, (struct OptionChoiceConfig *)OptionChoiceConfigOnOff, (u8 *)&gSpeedchoiceTooltipInstantText, OFF, TRUE },
    { 3, (u8 *)&gSpeedchoiceOptionSpinners, (struct OptionChoiceConfig *)OptionChoiceConfigNerfKeep, (u8 *)&gSpeedchoiceTooltipSpinners, KEEP, FALSE },
    { 2, (u8 *)&gSpeedchoiceOptionMaxVision, (struct OptionChoiceConfig *)OptionChoiceConfigOnOff, (u8 *)&gSpeedchoiceTooltipMaxVision, OFF, TRUE },
    { 2, (u8 *)&gSpeedchoiceOptionNerfRoxanne, (struct OptionChoiceConfig *)OptionChoiceConfigYesNo, (u8 *)&gSpeedchoiceTooltipNerfRoxanne, NO, TRUE },
    { 2, (u8 *)&gSpeedchoiceOptionSuperBike, (struct OptionChoiceConfig *)OptionChoiceConfigOnOff, (u8 *)&gSpeedchoiceTooltipSuperBike, OFF, TRUE },
    { 2, (u8 *)&gSpeedchoiceOptionNewWildEnc, (struct OptionChoiceConfig *)OptionChoiceConfigOnOff, (u8 *)&gSpeedchoiceTooltipNewWildEnc, OFF, TRUE },
    { 2, (u8 *)&gSpeedchoiceOptionEarlyFly, (struct OptionChoiceConfig *)OptionChoiceConfigYesNo, (u8 *)&gSpeedchoiceTooltipEarlyFly, NO, TRUE },
    { 2, (u8 *)&gSpeedchoiceOptionRunEverywhere, (struct OptionChoiceConfig *)OptionChoiceConfigOnOff, (u8 *)&gSpeedchoiceTooltipRunEverywhere, OFF, TRUE },
    { 2, (u8 *)&gSpeedchoiceOptionMemeIsland, (struct OptionChoiceConfig *)OptionChoiceConfigYesNo, (u8 *)&gSpeedchoiceTooltipMemeIsland, NO, TRUE },
    { 2, (u8 *)&gSpeedchoiceOptionEmeraldDoubles, (struct OptionChoiceConfig *)OptionChoiceConfigOnOff, (u8 *)&gSpeedchoiceTooltipEmeraldDoubles, OFF, TRUE },
    { MAX_PAGES, (u8 *)&gSpeedchoiceOptionPage, (struct OptionChoiceConfig *)OptionChoiceConfigPage, NULL, 1, TRUE } // see above comment.
};

extern u32 gRandomizerCheckValue;

EWRAM_DATA u8 gStoredPageNum = 0; // default is 0, only renders options again if it's different than the task data's page number.

static void Task_SpeedchoiceMenuFadeIn(u8);
static void Task_SpeedchoiceMenuProcessInput(u8);
static void HighlightOptionMenuItem(u8);
static void DrawGeneralChoices(struct SpeedchoiceOption *option, u8 selection, u8 row);
static void DrawPageChoice(u8);
static void Task_SpeedchoiceMenuSave(u8);
static void Task_DrawYesNoText(u8);
static void HighlightTextBox(void);

void InitializeOptionChoicesAndConfig(u8 taskId)
{
    u8 i;

    for(i = 0; i < CURRENT_OPTIONS_NUM; i++)
        gTasks[taskId].data[i] = SpeedchoiceOptions[i].defaultOption;

    gSaveBlock2.speedchoiceConfig.bwexp = SpeedchoiceOptions[0].defaultOption;
    gSaveBlock2.speedchoiceConfig.aqualess = SpeedchoiceOptions[1].defaultOption;
    gSaveBlock2.speedchoiceConfig.instantText = SpeedchoiceOptions[2].defaultOption;
    gSaveBlock2.speedchoiceConfig.spinners = SpeedchoiceOptions[3].defaultOption;
    gSaveBlock2.speedchoiceConfig.maxVision = SpeedchoiceOptions[4].defaultOption;
    gSaveBlock2.speedchoiceConfig.nerfRoxanne = SpeedchoiceOptions[5].defaultOption;
    gSaveBlock2.speedchoiceConfig.superbike = SpeedchoiceOptions[6].defaultOption;
    gSaveBlock2.speedchoiceConfig.newwildencounters = SpeedchoiceOptions[7].defaultOption;
    gSaveBlock2.speedchoiceConfig.earlyfly = SpeedchoiceOptions[8].defaultOption;
    gSaveBlock2.speedchoiceConfig.runEverywhere = SpeedchoiceOptions[9].defaultOption;
    gSaveBlock2.speedchoiceConfig.memeIsland = SpeedchoiceOptions[10].defaultOption;
    gSaveBlock2.speedchoiceConfig.emeraldDoubles = SpeedchoiceOptions[11].defaultOption;
}

bool8 CheckSpeedchoiceOption(u8 option, u8 selection)
{
    switch(option)
    {
        case TD_BWEXP:
            return gSaveBlock2.speedchoiceConfig.bwexp == selection;
        case TD_AQUALESS:
            return gSaveBlock2.speedchoiceConfig.aqualess == selection;
        case TD_INSTANTTEXT:
            return gSaveBlock2.speedchoiceConfig.instantText == selection;
        case TD_SPINNERS:
            return gSaveBlock2.speedchoiceConfig.spinners == selection;
        case TD_MAX_VISION:
            return gSaveBlock2.speedchoiceConfig.maxVision == selection;
        case TD_NERF_ROXANNE:
            return gSaveBlock2.speedchoiceConfig.nerfRoxanne == selection;
        case TD_SUPER_BIKE:
            return gSaveBlock2.speedchoiceConfig.superbike == selection;
        case TD_NEW_WILD_ENC:
            return gSaveBlock2.speedchoiceConfig.newwildencounters == selection;
        case TD_EARLY_FLY:
            return gSaveBlock2.speedchoiceConfig.earlyfly == selection;
        case TD_RUN_EVERYWHERE:
            return gSaveBlock2.speedchoiceConfig.runEverywhere == selection;
        case TD_MEME_ISLAND:
            return gSaveBlock2.speedchoiceConfig.memeIsland == selection;
        case TD_EMERALD_DOUBLES:
            return gSaveBlock2.speedchoiceConfig.emeraldDoubles == selection;
        default:
            return FALSE;
    }
}

static void DrawOptionMenuChoice(u8 *text, u8 x, u8 y, u8 style)
{
    u8 dst[16];
    u16 i;
    
    for(i = 0; *text != EOS && i <= 14; i++)
        dst[i] = *(text++);
    
    dst[2] = style;
    dst[i] = EOS;
    MenuPrint_PixelCoords(dst, x, y, 1);
}

// for selecting options. not unstubbed yet.
static u8 ProcessGeneralInput(struct SpeedchoiceOption *option, u8 selection)
{
    if(gMain.newKeys & DPAD_RIGHT)
    {
        if(option->enabled == FALSE)
        {
            PlaySE(SE_HAZURE);
            return selection;
        }
        if(selection == (option->optionCount - 1)) // options are indexed by 0.
            selection = 0;
        else
            selection++;
        PlaySE(SE_SELECT);
    }
    // i dont return immediately because emulators could hold both right and left down.
    if(gMain.newKeys & DPAD_LEFT)
    {
        if(option->enabled == FALSE)
        {
            PlaySE(SE_HAZURE);
            return selection;
        }
        if(selection == 0)
            selection = (option->optionCount - 1); // indexed by 0.
        else
            selection--;
        PlaySE(SE_SELECT);
    }
    return selection;
}

// todo: combine with above function
static u8 ProcessGeneralInputIndexedToOne(struct SpeedchoiceOption *option, u8 selection)
{
    if(gMain.newKeys & DPAD_RIGHT)
    {
        if(selection == (option->optionCount)) // pages are indexed by 1.
            selection = 1;
        else
            selection++;
    }
    // i dont return immediately because emulators could hold both right and left down.
    if(gMain.newKeys & DPAD_LEFT)
    {
        if(selection == 1)
            selection = (option->optionCount); // indexed by 1.
        else
            selection--;
    }

    // sanity check, but im unsure if it matters. do NOT let page escape the allowed number of pages!
    if(selection < 1)
        selection = 1;
    if(selection > (option->optionCount))
        selection = option->optionCount;

    return selection;
}

static void MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void RedrawSpeedchoiceWindows(void)
{
    MenuDrawTextWindow(2, 4, 27, 19); // only the lower menu needs to be redrawn.
}

u8 GetPageDrawCount(u8 page)
{
    if ((page * OPTIONS_PER_PAGE) > CURRENT_OPTIONS_NUM)
        return CURRENT_OPTIONS_NUM % OPTIONS_PER_PAGE;

    return OPTIONS_PER_PAGE;
}

void DrawPageOptions(u8 taskId, u8 page)
{
    u8 i;
    u8 drawCount = GetPageDrawCount(page);

    RedrawSpeedchoiceWindows();

    // print page options.
    for(i = 0; i < drawCount; i++)
    {
        struct SpeedchoiceOption *option = (struct SpeedchoiceOption *)&SpeedchoiceOptions[i + (OPTIONS_PER_PAGE * (page - 1))];
        u8 *string = option->string;

        MenuPrint(string, 4, MENUOPTIONCOORDS(i)); // the 5 here does not represent options_per_page, it's just a coincidence.
        DrawGeneralChoices(option, gTasks[taskId].data[i + ((page-1) * 5)], i);
    }

    MenuPrint(gSpeedchoiceOptionPage, 4, MENUOPTIONCOORDS(5));
    MenuPrint(gSpeedchoiceOptionStartGame, 4, MENUOPTIONCOORDS(6));
}

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

void SetPageIndexFromTrueIndex(u8 taskId, s16 index) // data is s16.
{
    if(index == MENUITEM_PAGE || index == MENUITEM_START_GAME)
        gTasks[taskId].data[TD_PAGEMENUINDEX] = index - 10; // your visual row is 6 or 7.
    else
        gTasks[taskId].data[TD_PAGEMENUINDEX] = (min((index % OPTIONS_PER_PAGE), OPTIONS_PER_PAGE));
}

void HighlightHeaderBox(void)
{
    REG_WIN0H = WIN_RANGE(17, 223);
    REG_WIN0V = WIN_RANGE(1, 31);
}

void CB2_InitSpeedchoiceMenu(void)
{
    switch (gMain.state)
    {
        default:
        case 0:
        {
            u8 *addr;
            u32 size;

            SetVBlankCallback(NULL);
            REG_DISPCNT = 0;
            REG_BG2CNT = 0;
            REG_BG1CNT = 0;
            REG_BG0CNT = 0;
            REG_BG2HOFS = 0;
            REG_BG2VOFS = 0;
            REG_BG1HOFS = 0;
            REG_BG1VOFS = 0;
            REG_BG0HOFS = 0;
            REG_BG0VOFS = 0;
            addr = (u8 *)VRAM;
            size = 0x18000;
            while (1)
            {
                DmaFill16(3, 0, addr, 0x1000);
                addr += 0x1000;
                size -= 0x1000;
                if (size <= 0x1000)
                {
                    DmaFill16(3, 0, addr, size);
                    break;
                }
            }
            DmaClear32(3, OAM, OAM_SIZE);
            DmaClear16(3, PLTT, PLTT_SIZE);
            gMain.state++;
            break;
        }
        case 1:
            ResetPaletteFade();
            remove_some_task();
            ResetTasks();
            ResetSpriteData();
            gMain.state++;
            break;
        case 2:
            SetUpWindowConfig(&gWindowConfig_81E71B4);
            gMain.state++;
            break;
        case 3:
            MultistepInitMenuWindowBegin(&gWindowConfig_81E71B4);
            gMain.state++;
            break;
        case 4:
            if (!MultistepInitMenuWindowContinue())
                return;
            gMain.state++;
            break;
        case 5:
            LoadPalette(gUnknown_0839F5FC, 0x80, 0x40);
            CpuCopy16(gUnknown_0839F63C, (void *)0x0600BEE0, 0x40);
            gMain.state++;
            break;
        case 6:
            BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);
            gMain.state++;
            break;
        case 7:
        {
            u16 savedIme;

            REG_WIN0H = 0;
            REG_WIN0V = 0;
            REG_WIN1H = 0;
            REG_WIN1V = 0;
            REG_WININ = 0x1111;
            REG_WINOUT = 0x31;
            REG_BLDCNT = 0xE1;
            REG_BLDALPHA = 0;
            REG_BLDY = 7;
            savedIme = REG_IME;
            REG_IME = 0;
            REG_IE |= INTR_FLAG_VBLANK;
            REG_IME = savedIme;
            REG_DISPSTAT |= DISPSTAT_VBLANK_INTR;
            SetVBlankCallback(VBlankCB);
            REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_OBJ_ON |
              DISPCNT_WIN0_ON | DISPCNT_WIN1_ON;
            gMain.state++;
            break;
        }
        case 8:
        {
            u8 taskId = CreateTask(Task_SpeedchoiceMenuFadeIn, 0);

            gStoredPageNum = 1;

            // set default options and current selection.
            gTasks[taskId].data[TD_TRUEMENUINDEX] = 0;
            gTasks[taskId].data[TD_PAGEMENUINDEX] = 0;

            InitializeOptionChoicesAndConfig(taskId);

            gTasks[taskId].data[TD_PAGE_NUM] = 1; // pages are indexed by 1.

            MenuDrawTextWindow(2, 0, 27, 3);
            MenuPrint(gSpeedchoiceTextHeader, 4, 1); // draw header.

            DrawPageOptions(taskId, gTasks[taskId].data[TD_PAGE_NUM]);
            DrawPageChoice(gTasks[taskId].data[TD_PAGE_NUM]);

            HighlightHeaderBox();

            HighlightOptionMenuItem(gTasks[taskId].data[TD_PAGEMENUINDEX]);
            PlayBGM(BGM_CONLOBBY);
            gMain.state++;
            break;
        }
        case 9:
            SetMainCallback2(MainCB);
            return;
    }
}

static void Task_SpeedchoiceMenuFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_SpeedchoiceMenuProcessInput;
    }
}

// lastOrFirst, TRUE means last, FALSE means first available
u8 GetPageOptionTrueIndex(bool8 lastOrFirst, u8 page)
{
    if(lastOrFirst == LAST)
        return (OPTIONS_PER_PAGE * (page - 1)) + GetPageDrawCount(page) - 1;
    else
        return (OPTIONS_PER_PAGE * (page - 1));
}

// same as above, but return the page index.
u8 GetPageOptionPageIndex(bool8 lastOrFirst, u8 page)
{
    return (lastOrFirst) ? GetPageDrawCount(page) : 1;
}

//This version uses addition '+' instead of OR '|'.
#define WIN_RANGE_(a, b) (((a) << 8) + (b))

static void HighlightOptionMenuItem(u8 index)
{
    REG_WIN1H = WIN_RANGE(24, 215);
    REG_WIN1V = WIN_RANGE_(index * 16 + 40, index * 16 + 56);
}

// used for all but page.
static void DrawGeneralChoices(struct SpeedchoiceOption *option, u8 selection, u8 row)
{
    u8 styles[MAX_CHOICES];
    u8 numChoices = option->optionCount;
    u8 i;
    
    styles[0] = 0xF;
    styles[1] = 0xF;
    styles[2] = 0xF;
    styles[3] = 0xF;
    styles[4] = 0xF;
    styles[5] = 0xF;
    styles[selection] = 0x8;
    
    for(i = 0; i < numChoices; i++)
    {
        s16 x = option->options[i].x;
        s16 y = 40 + (row * 16);
        u8 *string = option->options[i].string;

        DrawOptionMenuChoice(string, x, y, styles[i]);
    }
}

#define CHAR_0 0xA1 //Character code of '0' character

static void DrawPageChoice(u8 selection)
{
    u8 text[5];
    
    memcpy(text, gSystemText_Terminator, 3); // copy the palette control code.

    // there are no more than 10 pages, so format it as a single digit.
    text[3] = selection + CHAR_0;
    text[4] = EOS;

    MenuPrint(text, 8, MENUOPTIONCOORDS(5));
}

void Task_WaitForTooltip(u8 taskId)
{
    if (MenuUpdateWindowText())
    {
        if (gMain.newKeys & A_BUTTON)
        {
            MenuZeroFillWindowRect(2, 14, 27, 19);
            HighlightOptionMenuItem(gTasks[taskId].data[TD_PAGEMENUINDEX]);
            DrawPageOptions(taskId, gTasks[taskId].data[TD_PAGE_NUM]);
            DrawPageChoice(gTasks[taskId].data[TD_PAGE_NUM]);
            gTasks[taskId].func = Task_SpeedchoiceMenuProcessInput;
        }
    }
}

static void DrawTooltip(u8 taskId, struct SpeedchoiceOption *option)
{
    REG_WIN1H = WIN_RANGE(1, 241);
    REG_WIN1V = WIN_RANGE_(114, 160);
    MenuDrawTextWindow(2, 14, 27, 19);
    MenuPrintMessage(option->tooltip, 3, 15);    
    gTasks[taskId].func = Task_WaitForTooltip;
}

static void Task_SpeedchoiceMenuProcessInput(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON)
    {
        if (gTasks[taskId].data[TD_TRUEMENUINDEX] == MENUITEM_START_GAME) // START_GAME
        {
            gTasks[taskId].func = Task_SpeedchoiceMenuSave;
        }
    }
    else if (gMain.newKeys & SELECT_BUTTON) // do tooltip.
    {
        if(gTasks[taskId].data[TD_TRUEMENUINDEX] <= CURRENT_OPTIONS_NUM)
            DrawTooltip(taskId, (struct SpeedchoiceOption *)&SpeedchoiceOptions[gTasks[taskId].data[TD_TRUEMENUINDEX]]);
    }
    else if (gMain.newKeys & DPAD_UP)
    {
        if(gTasks[taskId].data[TD_TRUEMENUINDEX] == MENUITEM_PAGE) // page index is 15, but the last index may be less than that. set it to the last of the current page's index.
            gTasks[taskId].data[TD_TRUEMENUINDEX] = GetPageOptionTrueIndex(LAST, gTasks[taskId].data[TD_PAGE_NUM]); // set the entry to the last available option.
        else if(gTasks[taskId].data[TD_TRUEMENUINDEX] > GetPageOptionTrueIndex(FIRST, gTasks[taskId].data[TD_PAGE_NUM]))
            gTasks[taskId].data[TD_TRUEMENUINDEX]--; // index can be 16 and reduced to page.
        else
            gTasks[taskId].data[TD_TRUEMENUINDEX] = MENUITEM_START_GAME;

        SetPageIndexFromTrueIndex(taskId, gTasks[taskId].data[TD_TRUEMENUINDEX]);
        HighlightOptionMenuItem(gTasks[taskId].data[TD_PAGEMENUINDEX]);
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        if(gTasks[taskId].data[TD_TRUEMENUINDEX] == GetPageOptionTrueIndex(LAST, gTasks[taskId].data[TD_PAGE_NUM]))
            gTasks[taskId].data[TD_TRUEMENUINDEX] = MENUITEM_PAGE; // you are at the last option when you press down, go to page index.
        else if(gTasks[taskId].data[TD_TRUEMENUINDEX] == MENUITEM_START_GAME)
            gTasks[taskId].data[TD_TRUEMENUINDEX] = GetPageOptionTrueIndex(FIRST, gTasks[taskId].data[TD_PAGE_NUM]);
        else
            gTasks[taskId].data[TD_TRUEMENUINDEX]++;

        SetPageIndexFromTrueIndex(taskId, gTasks[taskId].data[TD_TRUEMENUINDEX]);
        HighlightOptionMenuItem(gTasks[taskId].data[TD_PAGEMENUINDEX]);
    }
    else
    {
        switch (gTasks[taskId].data[TD_TRUEMENUINDEX])
        {
            case TD_BWEXP:
                gTasks[taskId].data[TD_BWEXP] = ProcessGeneralInput((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_BWEXP], gTasks[taskId].data[TD_BWEXP]);
                DrawGeneralChoices((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_BWEXP], gTasks[taskId].data[TD_BWEXP], gTasks[taskId].data[TD_PAGEMENUINDEX]);
                break;
            case TD_AQUALESS:
                gTasks[taskId].data[TD_AQUALESS] = ProcessGeneralInput((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_AQUALESS], gTasks[taskId].data[TD_AQUALESS]);
                DrawGeneralChoices((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_AQUALESS], gTasks[taskId].data[TD_AQUALESS], gTasks[taskId].data[TD_PAGEMENUINDEX]);
                break;
            case TD_INSTANTTEXT:
                gTasks[taskId].data[TD_INSTANTTEXT] = ProcessGeneralInput((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_INSTANTTEXT], gTasks[taskId].data[TD_INSTANTTEXT]);
                DrawGeneralChoices((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_INSTANTTEXT], gTasks[taskId].data[TD_INSTANTTEXT], gTasks[taskId].data[TD_PAGEMENUINDEX]);
                break;
            case TD_SPINNERS:
                gTasks[taskId].data[TD_SPINNERS] = ProcessGeneralInput((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_SPINNERS], gTasks[taskId].data[TD_SPINNERS]);
                DrawGeneralChoices((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_SPINNERS], gTasks[taskId].data[TD_SPINNERS], gTasks[taskId].data[TD_PAGEMENUINDEX]);
                break;
            case TD_MAX_VISION:
                gTasks[taskId].data[TD_MAX_VISION] = ProcessGeneralInput((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_MAX_VISION], gTasks[taskId].data[TD_MAX_VISION]);
                DrawGeneralChoices((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_MAX_VISION], gTasks[taskId].data[TD_MAX_VISION], gTasks[taskId].data[TD_PAGEMENUINDEX]);
                break;
            case TD_NERF_ROXANNE:
                gTasks[taskId].data[TD_NERF_ROXANNE] = ProcessGeneralInput((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_NERF_ROXANNE], gTasks[taskId].data[TD_NERF_ROXANNE]);
                DrawGeneralChoices((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_NERF_ROXANNE], gTasks[taskId].data[TD_NERF_ROXANNE], gTasks[taskId].data[TD_PAGEMENUINDEX]);
                break;
            case TD_SUPER_BIKE:
                gTasks[taskId].data[TD_SUPER_BIKE] = ProcessGeneralInput((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_SUPER_BIKE], gTasks[taskId].data[TD_SUPER_BIKE]);
                DrawGeneralChoices((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_SUPER_BIKE], gTasks[taskId].data[TD_SUPER_BIKE], gTasks[taskId].data[TD_PAGEMENUINDEX]);
                break;
            case TD_NEW_WILD_ENC:
                gTasks[taskId].data[TD_NEW_WILD_ENC] = ProcessGeneralInput((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_NEW_WILD_ENC], gTasks[taskId].data[TD_NEW_WILD_ENC]);
                DrawGeneralChoices((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_NEW_WILD_ENC], gTasks[taskId].data[TD_NEW_WILD_ENC], gTasks[taskId].data[TD_PAGEMENUINDEX]);
                break;
            case TD_EARLY_FLY:
                gTasks[taskId].data[TD_EARLY_FLY] = ProcessGeneralInput((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_EARLY_FLY], gTasks[taskId].data[TD_EARLY_FLY]);
                DrawGeneralChoices((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_EARLY_FLY], gTasks[taskId].data[TD_EARLY_FLY], gTasks[taskId].data[TD_PAGEMENUINDEX]);
                break;
            case TD_RUN_EVERYWHERE:
                gTasks[taskId].data[TD_RUN_EVERYWHERE] = ProcessGeneralInput((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_RUN_EVERYWHERE], gTasks[taskId].data[TD_RUN_EVERYWHERE]);
                DrawGeneralChoices((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_RUN_EVERYWHERE], gTasks[taskId].data[TD_RUN_EVERYWHERE], gTasks[taskId].data[TD_PAGEMENUINDEX]);
                break;
            case TD_MEME_ISLAND:
                gTasks[taskId].data[TD_MEME_ISLAND] = ProcessGeneralInput((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_MEME_ISLAND], gTasks[taskId].data[TD_MEME_ISLAND]);
                DrawGeneralChoices((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_MEME_ISLAND], gTasks[taskId].data[TD_MEME_ISLAND], gTasks[taskId].data[TD_PAGEMENUINDEX]);
                break;
            case TD_EMERALD_DOUBLES:
                gTasks[taskId].data[TD_EMERALD_DOUBLES] = ProcessGeneralInput((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_EMERALD_DOUBLES], gTasks[taskId].data[TD_EMERALD_DOUBLES]);
                DrawGeneralChoices((struct SpeedchoiceOption *)&SpeedchoiceOptions[TD_EMERALD_DOUBLES], gTasks[taskId].data[TD_EMERALD_DOUBLES], gTasks[taskId].data[TD_PAGEMENUINDEX]);
                break;
            case TD_PAGE_NUM:
                gTasks[taskId].data[TD_PAGE_NUM] = ProcessGeneralInputIndexedToOne((struct SpeedchoiceOption *)&SpeedchoiceOptions[CURRENT_OPTIONS_NUM], gTasks[taskId].data[TD_PAGE_NUM]);
                DrawPageChoice(gTasks[taskId].data[TD_PAGE_NUM]);
                if(gTasks[taskId].data[TD_PAGE_NUM] != gStoredPageNum) // only redraw if the page updates!
                {
                    PlaySE(SE_WIN_OPEN);
                    DrawPageOptions(taskId, gTasks[taskId].data[TD_PAGE_NUM]);
                    gStoredPageNum = gTasks[taskId].data[TD_PAGE_NUM]; // update the page.
                }
                break;
        }
    }
}

u32 CalculateCheckValue(u8 taskId)
{
    volatile u32 randomizerValue = gRandomizerCheckValue; // this doesnt work without having the value externally anyway but whatever.
    u32 checkValue;
    u8 i;

    for(checkValue = 0, i = 0; i < CURRENT_OPTIONS_NUM; i++)
        checkValue += gTasks[taskId].data[i] << (i + (SpeedchoiceOptions[i].optionCount - 2));

    // seed RNG with checkValue for more hash-like number.
    checkValue = 0x41c64e6d * checkValue + 0x00006073;

    // xor with randomizer value, if one is present.
    checkValue = checkValue ^ randomizerValue;

    // get rid of sign extension.
    checkValue = (checkValue << 1) >> 1;

    return checkValue;
}

static void SaveSpeedchoiceOptions(u8 taskId)
{
    gSaveBlock2.speedchoiceConfig.bwexp = gTasks[taskId].data[TD_BWEXP];
    gSaveBlock2.speedchoiceConfig.aqualess = gTasks[taskId].data[TD_AQUALESS];
    gSaveBlock2.speedchoiceConfig.instantText = gTasks[taskId].data[TD_INSTANTTEXT]; // don't update instant text until its time to start the game!
    gSaveBlock2.speedchoiceConfig.spinners = gTasks[taskId].data[TD_SPINNERS];
    gSaveBlock2.speedchoiceConfig.maxVision = gTasks[taskId].data[TD_MAX_VISION];
    gSaveBlock2.speedchoiceConfig.nerfRoxanne = gTasks[taskId].data[TD_NERF_ROXANNE];
    gSaveBlock2.speedchoiceConfig.superbike = gTasks[taskId].data[TD_SUPER_BIKE];
    gSaveBlock2.speedchoiceConfig.newwildencounters = gTasks[taskId].data[TD_NEW_WILD_ENC];
    gSaveBlock2.speedchoiceConfig.earlyfly = gTasks[taskId].data[TD_EARLY_FLY];
    gSaveBlock2.speedchoiceConfig.runEverywhere = gTasks[taskId].data[TD_RUN_EVERYWHERE];
    gSaveBlock2.speedchoiceConfig.memeIsland = gTasks[taskId].data[TD_MEME_ISLAND];
    gSaveBlock2.speedchoiceConfig.emeraldDoubles = gTasks[taskId].data[TD_EMERALD_DOUBLES];
}

static void Task_SpeedchoiceMenuSave(u8 taskId)
{
    // calculate check Value. a pass into a local variable is required for ConvertIntToHexStringN to not raise a warning, even though the local variable is unused.
    ConvertIntToHexStringN(gStringVar1, CalculateCheckValue(taskId), STR_CONV_MODE_LEADING_ZEROS, 8);

    gTasks[taskId].func = Task_DrawYesNoText;
}

static void HighlightYesNoMenu(void)
{
    REG_WIN0H = WIN_RANGE(168, 242);
    REG_WIN0V = WIN_RANGE_(64, 112);
}

static void HighlightTextBox(void)
{
    REG_WIN1H = WIN_RANGE(1, 241);
    REG_WIN1V = WIN_RANGE(114, 160);
}

static void Task_SpeedchoiceMenuFadeOut(u8 taskId)
{
    if(!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_NewGameSpeech1;
    }
}

static void Task_HandleYesNoStartGame(u8 taskId)
{
     switch (ProcessMenuInputNoWrap_())
    {
        case 0: // YES
            PlayBGM(BGM_STOP);
            PlaySE(SE_SELECT);
            SaveSpeedchoiceOptions(taskId);
            BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
            gTasks[taskId].func = Task_SpeedchoiceMenuFadeOut;
            break;
        case -1:
        case 1: // NO
            PlaySE(SE_SELECT);
            REG_WIN1H = WIN_RANGE(0, 0); // unhighlight the text box and YES/NO window before redrawing.
            REG_WIN1V = WIN_RANGE(0, 0);
            REG_WIN0H = WIN_RANGE(0, 0);
            REG_WIN0V = WIN_RANGE_(0, 0);
            DrawPageOptions(taskId, gTasks[taskId].data[TD_PAGE_NUM]);
            DrawPageChoice(gTasks[taskId].data[TD_PAGE_NUM]);
            HighlightOptionMenuItem(6);
            HighlightHeaderBox();
            gTasks[taskId].func = Task_SpeedchoiceMenuProcessInput;
            break;
    }
}

static void Task_AskToStartGame(u8 taskId)
{
    if (MenuUpdateWindowText())
    {
        DisplayYesNoMenu(21, 8, 1);
        HighlightYesNoMenu();
        gTasks[taskId].func = Task_HandleYesNoStartGame;
    }
}

static void Task_DrawYesNoText(u8 taskId)
{
    MenuDrawTextWindow(2, 14, 27, 19);
    HighlightTextBox();
    MenuPrint(gSpeedchoiceStartGameText, 3, 15);

    gTasks[taskId].func = Task_AskToStartGame;
}

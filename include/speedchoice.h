#ifndef GUARD_SPEEDCHOICE_H
#define GUARD_SPEEDCHOICE_H

// global speedchoice config
#define CURRENT_OPTIONS_NUM 15
#define MAX_CHOICES 6
#define OPTIONS_PER_PAGE 5
#define ALLOPTIONS_PER_PAGE OPTIONS_PER_PAGE + 2 // page + start game
#define MAX_PAGES 3

#define MENUOPTIONCOORDS(i) (5 + (2 * i))

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

#define SPINNER_HELL_TIMER 4 // once every 2 frames since the game runs at 60FPS.
#define MAX_VISION_RANGE 8

// options
enum
{
    BWEXP,
    AQUALESS,
    INSTANTTEXT,
    SPINNERS,
    MAXVISION,
    NERFGYMLEADERS,
    SUPERBIKE,
    NEWWILDENC,
    EARLYFLY,
    RUN_EVERYWHERE,
    MEME_ISLAND,
    EMERALD_DOUBLES,
    GLITCH_ROD,
    BETTER_MARTS,
    GOOD_EARLY_WILDS,

    // STATIC OPTIONS
    PAGE, // to make it match task data
    START_GAME
};

enum
{
    YES,
    NO
};

enum
{
    ON,
    OFF
};

enum
{
    NERF,
    KEEP,
    HELL
};

enum
{
    SEMI,
    KEEP_2, // same as before but renamed to prevent conflict.
    FULL
};

enum
{
    FIRST,
    LAST
};

enum
{
    OFF_2,
    STATIC,
    RAND
};

enum
{
    // off_2 is taken up by 0.
    SANE = 1,
    // hell is taken up by 2.
};

struct OptionChoiceConfig
{
    s16 x; // do not store the Y coordinate. Y is automatically calculated depending on the row the option is placed and therefore is not necessary.
    u8 *string; // can be null
};

// every 5 elements belongs to a page, page struct is unnecessary.
struct SpeedchoiceOption
{
    u8 optionCount; // needed for process general input, im sure there's a way to avoid using this
    u8 *string;
    struct OptionChoiceConfig *options; // use a NULL for non existent ones, optional things in structs were introduced in C++ and this is limited.
    u8 *tooltip;
    u8 defaultOption;
    bool8 enabled;
}; 

struct SpeedchoiceConfigStruct
{
    u8 optionConfig[CURRENT_OPTIONS_NUM];
    u8 trueIndex;
    u8 pageIndex;
    u8 pageNum;
};

struct MapObjectTimerBackup
{
    bool8 backedUp;
    s16 timer;
};

void CB2_InitSpeedchoiceMenu(void);
bool8 CheckSpeedchoiceOption(u8, u8);

#endif

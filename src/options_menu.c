#include "defines.h"
#include "defines_battle.h"
#include "../include/options_menu.h"
#include "../include/battle_setup.h"
#include "../include/event_data.h"
#include "../include/pokemon.h"
#include "../include/pokemon_storage_system.h"
#include "../include/random.h"
#include "../include/script.h"
#include "../include/string_util.h"
#include "../include/wild_encounter.h"
#include "../include/constants/event_objects.h"
#include "../include/constants/items.h"
#include "../include/constants/maps.h"
#include "../include/constants/pokedex.h"
#include "../include/constants/region_map_sections.h"
#include "../include/constants/species.h"
#include "../include/constants/trainer_classes.h"
#include "../include/constants/trainers.h"
#include "../include/constants/tutors.h"

#include "../include/new/ability_tables.h"
#include "../include/new/ai_advanced.h"
#include "../include/new/build_pokemon.h"
#include "../include/new/build_pokemon_2.h"
#include "../include/new/catching.h"
#include "../include/new/dexnav.h"
#include "../include/new/dynamax.h"
#include "../include/new/form_change.h"
#include "../include/new/frontier.h"
#include "../include/new/item.h"
#include "../include/new/learn_move.h"
#include "../include/new/mega.h"
#include "../include/new/multi.h"
#include "../include/new/pokemon_storage_system.h"
#include "../include/new/util2.h"
#include "../include/text.h"
#include "../include/overworld.h"
#include "../include/tm_case.h"
#include "../include/text_window.h"
#include "../include/bg.h"
#include "../include/mgba.h"
#include "../include/menu_helpers.h"
#include "../include/gba/m4a_internal.h"
#include "../include/malloc.h"

#include "../include/pokemon_summary_screen.h"
#include "../include/menu.h"
#include "../include/new/battle_strings.h"
#include "../include/pokedex.h"
#include "../include/base_stats.h"

void CB2_OptionMenu(void);
bool8 LoadOptionMenuPalette(void);
void LoadOptionMenuItemNames(void);
void Task_OptionMenu(u8 taskId);
void CloseAndSaveOptionMenu(u8 taskId);
u8 OptionMenu_ProcessInput(void);
void BufferOptionMenuString(u8 selection);

// Menu items
enum
{
    MENUITEM_TEXTSPEED = 0,
    MENUITEM_BATTLESCENE,
    MENUITEM_BATTLESTYLE,
    MENUITEM_SOUND,
    MENUITEM_BUTTONMODE,
    MENUITEM_FRAMETYPE,
    MENUITEM_CANCEL,
    /*MENUITEM_PAGE1_COUNT,
    MENUITEM_RBUTTONMODE,
    MENUITEM_PAGE2_COUNT,*/
    MENUITEM_COUNT,
};

// Window Ids
enum
{
    WIN_TEXT_OPTION,
    WIN_OPTIONS
};

struct OptionMenu
{
    /*0x00*/ u16 option[MENUITEM_COUNT];
    /*0x??*/ u16 cursorPos;
    /*0x??*/ u8 loadState;
    /*0x??*/ u8 state;
    /*0x??*/ u8 loadPaletteState;
    /*0x??*/ u8 page;
};

extern struct OptionMenu *sOptionMenuPtr;

extern const u8 gText_TextSpeed[];
extern const u8 gText_BattleScene[];
extern const u8 gText_BattleStyle[];
extern const u8 gText_Sound[];
extern const u8 gText_ButtonMode[];
extern const u8 gText_Frame[];
extern const u8 gText_OptionMenuCancel[];
extern const u8 gText_RButtonMode[];

static const u8 *const sOptionMenuItemsNames[MENUITEM_COUNT] =
{
    [MENUITEM_TEXTSPEED]   = gText_TextSpeed,
    [MENUITEM_BATTLESCENE] = gText_BattleScene,
    [MENUITEM_BATTLESTYLE] = gText_BattleStyle,
    [MENUITEM_SOUND]       = gText_Sound,
    [MENUITEM_BUTTONMODE]  = gText_ButtonMode,
    [MENUITEM_FRAMETYPE]   = gText_Frame,
    [MENUITEM_CANCEL]      = gText_OptionMenuCancel,
    //[MENUITEM_RBUTTONMODE] = gText_RButtonMode,
};

extern const u8 gText_TextSpeedSlow[];
extern const u8 gText_TextSpeedMid[];
extern const u8 gText_TextSpeedFast[];
extern const u8 gText_BattleSceneOn[];
extern const u8 gText_BattleSceneOff[];
extern const u8 gText_BattleStyleShift[];
extern const u8 gText_BattleStyleSet[];
extern const u8 gText_SoundMono[];
extern const u8 gText_SoundStereo[];
extern const u8 gText_ButtonTypeHelp[];
extern const u8 gText_ButtonTypeLR[];
extern const u8 gText_ButtonTypeLEqualsA[];
extern const u8 gText_MenuOption[];
extern const u8 gText_FrameType[];

static const u8 *const sTextSpeedOptions[] =
{
    gText_TextSpeedSlow, 
    gText_TextSpeedMid, 
    gText_TextSpeedFast
};

static const u8 *const sBattleSceneOptions[] =
{
    gText_BattleSceneOn, 
    gText_BattleSceneOff
};

static const u8 *const sBattleStyleOptions[] =
{
    gText_BattleStyleShift,
    gText_BattleStyleSet
};

static const u8 *const sSoundOptions[] =
{
    gText_SoundMono, 
    gText_SoundStereo
};

static const u8 *const sButtonTypeOptions[] =
{
    gText_ButtonTypeHelp,
	gText_ButtonTypeLR,
	gText_ButtonTypeLEqualsA
};

static const u16 sOptionMenuItemCounts[MENUITEM_COUNT] = {3, 2, 2, 2, 3, 10, 0};

void CB2_OptionsMenuFromStartMenu(void)
{
    u8 i;
    
    if (gMain.savedCallback == NULL)
        gMain.savedCallback = CB2_ReturnToFieldWithOpenMenu;
    MgbaPrintf(MGBA_LOG_INFO, "Hello world! 0");
    sOptionMenuPtr = AllocZeroed(sizeof(struct OptionMenu));
    MgbaPrintf(MGBA_LOG_INFO, "Hello world! 1");
    sOptionMenuPtr->loadState = 0;
    MgbaPrintf(MGBA_LOG_INFO, "Hello world! 2");
    sOptionMenuPtr->loadPaletteState = 0;
    MgbaPrintf(MGBA_LOG_INFO, "Hello world! 3");
    sOptionMenuPtr->state = 0;
    MgbaPrintf(MGBA_LOG_INFO, "Hello world! 4");
    sOptionMenuPtr->cursorPos = 0;
    MgbaPrintf(MGBA_LOG_INFO, "Hello world! 5");
    sOptionMenuPtr->option[MENUITEM_TEXTSPEED] = gSaveBlock2->optionsTextSpeed;
    sOptionMenuPtr->option[MENUITEM_BATTLESCENE] = gSaveBlock2->optionsBattleSceneOff;
    sOptionMenuPtr->option[MENUITEM_BATTLESTYLE] = gSaveBlock2->optionsBattleStyle;
    sOptionMenuPtr->option[MENUITEM_SOUND] = gSaveBlock2->optionsSound;
    sOptionMenuPtr->option[MENUITEM_BUTTONMODE] = gSaveBlock2->optionsButtonMode;
    sOptionMenuPtr->option[MENUITEM_FRAMETYPE] = gSaveBlock2->optionsWindowFrameType;
    
    for (i = 0; i < MENUITEM_COUNT - 1; i++)
    {
        if (sOptionMenuPtr->option[i] > (sOptionMenuItemCounts[i]) - 1)
            sOptionMenuPtr->option[i] = 0;
    }
    SetMainCallback2(CB2_OptionMenu);
}

void Task_OptionMenu(u8 taskId)
{
    switch (sOptionMenuPtr->loadState)
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        OptionMenu_SetVBlankCallback();
        sOptionMenuPtr->loadState++;
        break;
    case 1:
        if (gPaletteFade->active)
            return;
        sOptionMenuPtr->loadState++;
        break;
    case 2:
        if (((bool32)MenuHelpers_CallLinkSomething()) == TRUE)
            break;
        switch (OptionMenu_ProcessInput())
        {
        case 0:
            break;
        case 1:
            sOptionMenuPtr->loadState++;
            break;
        case 2:
            LoadBgTiles(1, GetUserFrameGraphicsInfo(sOptionMenuPtr->option[MENUITEM_FRAMETYPE])->tiles, 0x120, 0x1AA);
            LoadPalette(GetUserFrameGraphicsInfo(sOptionMenuPtr->option[MENUITEM_FRAMETYPE])->palette, 0x20, 0x20);
            BufferOptionMenuString(sOptionMenuPtr->cursorPos);
            break;
        case 3:
            UpdateSettingSelectionDisplay(sOptionMenuPtr->cursorPos);
            break;
        case 4:
            BufferOptionMenuString(sOptionMenuPtr->cursorPos);
            break;
        }
        break;
    case 3:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
        sOptionMenuPtr->loadState++;
        break;
    case 4:
        if (gPaletteFade->active)
            return;
        sOptionMenuPtr->loadState++;
        break;
    case 5:
        CloseAndSaveOptionMenu(taskId);
        break;
    }
}

void CloseAndSaveOptionMenu(u8 taskId)
{
    gFieldCallback = FieldCB_DefaultWarpExit;
    SetMainCallback2(gMain.savedCallback);
    FreeAllWindowBuffers();
    gSaveBlock2->optionsTextSpeed = sOptionMenuPtr->option[MENUITEM_TEXTSPEED];
    gSaveBlock2->optionsBattleSceneOff = sOptionMenuPtr->option[MENUITEM_BATTLESCENE];
    gSaveBlock2->optionsBattleStyle = sOptionMenuPtr->option[MENUITEM_BATTLESTYLE];
    gSaveBlock2->optionsSound = sOptionMenuPtr->option[MENUITEM_SOUND];
    gSaveBlock2->optionsButtonMode = sOptionMenuPtr->option[MENUITEM_BUTTONMODE];
    gSaveBlock2->optionsWindowFrameType = sOptionMenuPtr->option[MENUITEM_FRAMETYPE];
    SetPokemonCryStereo(gSaveBlock2->optionsSound);
    FREE_AND_SET_NULL(sOptionMenuPtr);
    DestroyTask(taskId);
}

void CB2_OptionMenu(void)
{
    u8 i, state;
    state = sOptionMenuPtr->state;
    switch (state)
    {
    case 0:
        OptionMenu_InitCallbacks();
        break;
    case 1:
        InitOptionMenuBg();
        break;
    case 2:
        OptionMenu_ResetSpriteData();
        break;
    case 3:
        if (LoadOptionMenuPalette() != TRUE)
            return;
        break;
    case 4:
        PrintOptionMenuHeader();
        break;
    case 5:
        DrawOptionMenuBg();
        break;
    case 6:
        LoadOptionMenuItemNames();
        break;
    case 7:
        for (i = 0; i < MENUITEM_COUNT; i++)
            BufferOptionMenuString(i);
        break;
    case 8:
        UpdateSettingSelectionDisplay(sOptionMenuPtr->cursorPos);
        break;
    case 9:
        OptionMenu_PickSwitchCancel();
        break;
    default:
        SetOptionMenuTask();
		break;
    }
    sOptionMenuPtr->state++;
}

static const u8 sOptionMenuPickSwitchCancelTextColor[] = {TEXT_DYNAMIC_COLOR_6, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GREY};
static const u8 sOptionMenuTextColor[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_RED, TEXT_COLOR_RED};

void BufferOptionMenuString(u8 selection)
{
    u8 str[20];
    u8 buf[12];
    u8 dst[3];
    u8 x, y;
    
    memcpy(dst, sOptionMenuTextColor, 3);
    x = 0x82;
    y = ((GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT) - 1) * selection) + 2;
    FillWindowPixelRect(1, 1, x, y, 0x46, GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT));

    switch (selection)
    {
    case MENUITEM_TEXTSPEED:
        AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sTextSpeedOptions[sOptionMenuPtr->option[selection]]);
        break;
    case MENUITEM_BATTLESCENE:
        AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sBattleSceneOptions[sOptionMenuPtr->option[selection]]);
        break;
    case MENUITEM_BATTLESTYLE:
        AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sBattleStyleOptions[sOptionMenuPtr->option[selection]]);
        break;
    case MENUITEM_SOUND:
        AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sSoundOptions[sOptionMenuPtr->option[selection]]);
        break;
    case MENUITEM_BUTTONMODE:
        AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sButtonTypeOptions[sOptionMenuPtr->option[selection]]);
        break;
    case MENUITEM_FRAMETYPE:
        StringCopy(str, gText_FrameType);
        ConvertIntToDecimalStringN(buf, sOptionMenuPtr->option[selection] + 1, 1, 2);
        StringAppendN(str, buf, 3);
        AddTextPrinterParameterized3(1, 2, x, y, dst, -1, str);
        break;
    default:
        break;
    }
    PutWindowTilemap(1);
    CopyWindowToVram(1, COPYWIN_BOTH);
}

u8 OptionMenu_ProcessInput(void)
{ 
    u16 current;
    u16* curr;
    if (JOY_REPT(DPAD_RIGHT))
    {
        current = sOptionMenuPtr->option[(sOptionMenuPtr->cursorPos)];
        if (current == (sOptionMenuItemCounts[sOptionMenuPtr->cursorPos] - 1))
            sOptionMenuPtr->option[sOptionMenuPtr->cursorPos] = 0;
        else
            sOptionMenuPtr->option[sOptionMenuPtr->cursorPos] = current + 1;
        if (sOptionMenuPtr->cursorPos == MENUITEM_FRAMETYPE)
            return 2;
        else
            return 4;
    }
    else if (JOY_REPT(DPAD_LEFT))
    {
        curr = &sOptionMenuPtr->option[sOptionMenuPtr->cursorPos];
        if (*curr == 0)
            *curr = sOptionMenuItemCounts[sOptionMenuPtr->cursorPos] - 1;
        else
            --*curr;
        
        if (sOptionMenuPtr->cursorPos == MENUITEM_FRAMETYPE)
            return 2;
        else
            return 4;
    }
    else if (JOY_REPT(DPAD_UP))
    {
        if (sOptionMenuPtr->cursorPos == MENUITEM_TEXTSPEED)
            sOptionMenuPtr->cursorPos = MENUITEM_CANCEL;
        else
            sOptionMenuPtr->cursorPos = sOptionMenuPtr->cursorPos - 1;
        return 3;        
    }
    else if (JOY_REPT(DPAD_DOWN))
    {
        if (sOptionMenuPtr->cursorPos == MENUITEM_CANCEL)
            sOptionMenuPtr->cursorPos = MENUITEM_TEXTSPEED;
        else
            sOptionMenuPtr->cursorPos = sOptionMenuPtr->cursorPos + 1;
        return 3;
    }
    else if (JOY_NEW(B_BUTTON) || JOY_NEW(A_BUTTON))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

extern const u16 sOptionMenuPalette[];

bool8 LoadOptionMenuPalette(void)
{
    switch (sOptionMenuPtr->loadPaletteState)
    {
    case 0:
        LoadBgTiles(1, GetUserFrameGraphicsInfo(sOptionMenuPtr->option[MENUITEM_FRAMETYPE])->tiles, 0x120, 0x1AA);
        break;
    case 1:
        LoadPalette(GetUserFrameGraphicsInfo(sOptionMenuPtr->option[MENUITEM_FRAMETYPE])->palette, 0x20, 0x20);
        break;
    case 2:
        LoadPalette(sOptionMenuPalette, 0x10, 0x20);
        LoadPalette(stdpal_get(2), 0xF0, 0x20);
        break;
    case 3:
        DrawWindowBorderWithStdpal3(1, 0x1B3, 0x30);
        break;
    default:
        return TRUE;
    }
    sOptionMenuPtr->loadPaletteState++;
    return FALSE;
}

void LoadOptionMenuItemNames(void)
{
    u8 i;
    
    FillWindowPixelBuffer(1, PIXEL_FILL(1));
    for (i = 0; i < MENUITEM_COUNT; i++)
    {
        AddTextPrinterParameterized(WIN_OPTIONS, 2, sOptionMenuItemsNames[i], 8, (u8)((i * (GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT))) + 2) - i, TEXT_SPEED_FF, NULL);    
    }
}
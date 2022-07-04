#include "../defines.h"
#include "../../include/constants/event_objects.h"

#define EVENT_OBJ_PAL_TAG_NONE 0x1102
#define gEventObjectBaseOam_16x16 ((const struct OamData*) 0x83A36F8)
#define gEventObjectBaseOam_16x32 ((const struct OamData*) 0x83A3710)
#define gEventObjectBaseOam_32x32 ((const struct OamData*) 0x83A3718)
#define gEventObjectBaseOam_64x64 ((const struct OamData*) 0x83A3720)
#define gEventObjectSpriteOamTables_16x16 ((const struct SubspriteTable*) 0x83A3748)
#define gEventObjectSpriteOamTables_16x32 ((const struct SubspriteTable*) 0x83A379C)
#define gEventObjectSpriteOamTables_32x32 ((const struct SubspriteTable*) 0x83A37F0)
#define gEventObjectSpriteOamTables_64x64 ((const struct SubspriteTable*) 0x83A38D0)
#define gEventObjectImageAnimTable_PlayerNormal ((const union AnimCmd* const*) 0x83A3470)
#define gEventObjectImageAnimTable_Standard ((const union AnimCmd* const*) 0x83A3368)
#define gEventObjectImageAnimTable_Surfing ((const union AnimCmd* const*) 0x83A3584)
#define gEventObjectImageAnimTable_FieldMove ((const union AnimCmd* const*) 0x83A3638)
#define gEventObjectImageAnimTable_Fishing ((const union AnimCmd* const*) 0x83A3668)
#define gEventObjectImageAnimTable_VsSeekerBike ((const union AnimCmd* const*) 0x83A3640)

extern const u8 gEventObjectPic_CresseliaTiles[];

static const struct SpriteFrameImage gEventObjectPicTable_Cresselia[] =
{
    overworld_frame(gEventObjectPic_CresseliaTiles, 4, 4, 0),
    overworld_frame(gEventObjectPic_CresseliaTiles, 4, 4, 1),
    overworld_frame(gEventObjectPic_CresseliaTiles, 4, 4, 2),
    overworld_frame(gEventObjectPic_CresseliaTiles, 4, 4, 4),
    overworld_frame(gEventObjectPic_CresseliaTiles, 4, 4, 4),
    overworld_frame(gEventObjectPic_CresseliaTiles, 4, 4, 6),
    overworld_frame(gEventObjectPic_CresseliaTiles, 4, 4, 6),
    overworld_frame(gEventObjectPic_CresseliaTiles, 4, 4, 8),
    overworld_frame(gEventObjectPic_CresseliaTiles, 4, 4, 8),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Cresselia =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1201,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (32 * 32) / 2,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_32x32,
    .subspriteTables = gEventObjectSpriteOamTables_32x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Cresselia,
    .affineAnims = gDummySpriteAffineAnimTable,
};


extern const u8 gEventObjectPic_DarkraiTiles[];

static const struct SpriteFrameImage gEventObjectPicTable_Darkrai[] =
{
    overworld_frame(gEventObjectPic_DarkraiTiles, 4, 4, 0),
    overworld_frame(gEventObjectPic_DarkraiTiles, 4, 4, 1),
    overworld_frame(gEventObjectPic_DarkraiTiles, 4, 4, 2),
    overworld_frame(gEventObjectPic_DarkraiTiles, 4, 4, 4),
    overworld_frame(gEventObjectPic_DarkraiTiles, 4, 4, 4),
    overworld_frame(gEventObjectPic_DarkraiTiles, 4, 4, 6),
    overworld_frame(gEventObjectPic_DarkraiTiles, 4, 4, 6),
    overworld_frame(gEventObjectPic_DarkraiTiles, 4, 4, 8),
    overworld_frame(gEventObjectPic_DarkraiTiles, 4, 4, 8),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Darkrai =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1202,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (32 * 32) / 2,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_32x32,
    .subspriteTables = gEventObjectSpriteOamTables_32x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Darkrai,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u8 gEventObjectPic_PidgeotTiles[];

static const struct SpriteFrameImage gEventObjectPicTable_Pidgeot[] =
{
    overworld_frame(gEventObjectPic_PidgeotTiles, 4, 4, 0),
    overworld_frame(gEventObjectPic_PidgeotTiles, 4, 4, 1),
    overworld_frame(gEventObjectPic_PidgeotTiles, 4, 4, 2),
    overworld_frame(gEventObjectPic_PidgeotTiles, 4, 4, 4),
    overworld_frame(gEventObjectPic_PidgeotTiles, 4, 4, 4),
    overworld_frame(gEventObjectPic_PidgeotTiles, 4, 4, 6),
    overworld_frame(gEventObjectPic_PidgeotTiles, 4, 4, 6),
    overworld_frame(gEventObjectPic_PidgeotTiles, 4, 4, 8),
    overworld_frame(gEventObjectPic_PidgeotTiles, 4, 4, 8),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Pidgeot =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1203,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (32 * 32) / 2,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_32x32,
    .subspriteTables = gEventObjectSpriteOamTables_32x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Pidgeot,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u8 gEventObjectPic_ChanseyTiles[];

static const struct SpriteFrameImage gEventObjectPicTable_Chansey[] =
{
    overworld_frame(gEventObjectPic_ChanseyTiles, 4, 4, 0),
    overworld_frame(gEventObjectPic_ChanseyTiles, 4, 4, 1),
    overworld_frame(gEventObjectPic_ChanseyTiles, 4, 4, 2),
    overworld_frame(gEventObjectPic_ChanseyTiles, 4, 4, 4),
    overworld_frame(gEventObjectPic_ChanseyTiles, 4, 4, 4),
    overworld_frame(gEventObjectPic_ChanseyTiles, 4, 4, 6),
    overworld_frame(gEventObjectPic_ChanseyTiles, 4, 4, 6),
    overworld_frame(gEventObjectPic_ChanseyTiles, 4, 4, 8),
    overworld_frame(gEventObjectPic_ChanseyTiles, 4, 4, 8),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Chansey =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1204,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (32 * 32) / 2,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_32x32,
    .subspriteTables = gEventObjectSpriteOamTables_32x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Chansey,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u8 gEventObjectPic_RegirockTiles[];

static const struct SpriteFrameImage gEventObjectPicTable_Regirock[] =
{
    overworld_frame(gEventObjectPic_RegirockTiles, 4, 4, 0),
    overworld_frame(gEventObjectPic_RegirockTiles, 4, 4, 1),
    overworld_frame(gEventObjectPic_RegirockTiles, 4, 4, 2),
    overworld_frame(gEventObjectPic_RegirockTiles, 4, 4, 4),
    overworld_frame(gEventObjectPic_RegirockTiles, 4, 4, 4),
    overworld_frame(gEventObjectPic_RegirockTiles, 4, 4, 6),
    overworld_frame(gEventObjectPic_RegirockTiles, 4, 4, 6),
    overworld_frame(gEventObjectPic_RegirockTiles, 4, 4, 8),
    overworld_frame(gEventObjectPic_RegirockTiles, 4, 4, 8),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Regirock =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1205,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (32 * 32) / 2,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_32x32,
    .subspriteTables = gEventObjectSpriteOamTables_32x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Regirock,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u8 gEventObjectPic_RegielekiTiles[];

static const struct SpriteFrameImage gEventObjectPicTable_Regieleki[] =
{
    overworld_frame(gEventObjectPic_RegielekiTiles, 4, 4, 0),
    overworld_frame(gEventObjectPic_RegielekiTiles, 4, 4, 1),
    overworld_frame(gEventObjectPic_RegielekiTiles, 4, 4, 2),
    overworld_frame(gEventObjectPic_RegielekiTiles, 4, 4, 4),
    overworld_frame(gEventObjectPic_RegielekiTiles, 4, 4, 4),
    overworld_frame(gEventObjectPic_RegielekiTiles, 4, 4, 6),
    overworld_frame(gEventObjectPic_RegielekiTiles, 4, 4, 6),
    overworld_frame(gEventObjectPic_RegielekiTiles, 4, 4, 8),
    overworld_frame(gEventObjectPic_RegielekiTiles, 4, 4, 8),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Regieleki =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1206,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (32 * 32) / 2,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_32x32,
    .subspriteTables = gEventObjectSpriteOamTables_32x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Regieleki,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u8 gEventObjectPic_RegisteelTiles[];

static const struct SpriteFrameImage gEventObjectPicTable_Registeel[] =
{
    overworld_frame(gEventObjectPic_RegisteelTiles, 4, 4, 0),
    overworld_frame(gEventObjectPic_RegisteelTiles, 4, 4, 1),
    overworld_frame(gEventObjectPic_RegisteelTiles, 4, 4, 2),
    overworld_frame(gEventObjectPic_RegisteelTiles, 4, 4, 4),
    overworld_frame(gEventObjectPic_RegisteelTiles, 4, 4, 4),
    overworld_frame(gEventObjectPic_RegisteelTiles, 4, 4, 6),
    overworld_frame(gEventObjectPic_RegisteelTiles, 4, 4, 6),
    overworld_frame(gEventObjectPic_RegisteelTiles, 4, 4, 8),
    overworld_frame(gEventObjectPic_RegisteelTiles, 4, 4, 8),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Registeel =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1207,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (32 * 32) / 2,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_32x32,
    .subspriteTables = gEventObjectSpriteOamTables_32x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Registeel,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u8 gEventObjectPic_ShinySlowbroTiles[];

static const struct SpriteFrameImage gEventObjectPicTable_ShinySlowbro[] =
{
    overworld_frame(gEventObjectPic_ShinySlowbroTiles, 4, 4, 0),
    overworld_frame(gEventObjectPic_ShinySlowbroTiles, 4, 4, 1),
    overworld_frame(gEventObjectPic_ShinySlowbroTiles, 4, 4, 2),
    overworld_frame(gEventObjectPic_ShinySlowbroTiles, 4, 4, 3),
    overworld_frame(gEventObjectPic_ShinySlowbroTiles, 4, 4, 4),
    overworld_frame(gEventObjectPic_ShinySlowbroTiles, 4, 4, 5),
    overworld_frame(gEventObjectPic_ShinySlowbroTiles, 4, 4, 6),
    overworld_frame(gEventObjectPic_ShinySlowbroTiles, 4, 4, 7),
    overworld_frame(gEventObjectPic_ShinySlowbroTiles, 4, 4, 8),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_ShinySlowbro =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1208,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (32 * 32) / 2,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_32x32,
    .subspriteTables = gEventObjectSpriteOamTables_32x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_ShinySlowbro,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u8 gEventObjectPic_TamerTiles[];

static const struct SpriteFrameImage gEventObjectPicTable_Tamer[] =
{
    overworld_frame(gEventObjectPic_TamerTiles, 2, 4, 0),
    overworld_frame(gEventObjectPic_TamerTiles, 2, 4, 1),
    overworld_frame(gEventObjectPic_TamerTiles, 2, 4, 2),
    overworld_frame(gEventObjectPic_TamerTiles, 2, 4, 3),
    overworld_frame(gEventObjectPic_TamerTiles, 2, 4, 4),
    overworld_frame(gEventObjectPic_TamerTiles, 2, 4, 5),
    overworld_frame(gEventObjectPic_TamerTiles, 2, 4, 6),
    overworld_frame(gEventObjectPic_TamerTiles, 2, 4, 7),
    overworld_frame(gEventObjectPic_TamerTiles, 2, 4, 8),
    overworld_frame(gEventObjectPic_TamerTiles, 2, 4, 9),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_Tamer =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x1209,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (16 * 32) / 2,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_16x32,
    .subspriteTables = gEventObjectSpriteOamTables_16x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_Tamer,
    .affineAnims = gDummySpriteAffineAnimTable,
};

extern const u8 gEventObjectPic_PC2Tiles[];

static const struct SpriteFrameImage gEventObjectPicTable_PC2[] =
{
    overworld_frame(gEventObjectPic_PC2Tiles, 4, 4, 0),
};

const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_PC2 =
{
    .tileTag = 0xFFFF,
    .paletteTag1 = 0x120A,
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,
    .size = (32 * 32) / 2,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M, //Can also be SHADOW_SIZE_S, SHADOW_SIZE_L, or SHADOW_SIZE_XL
    .inanimate = FALSE,
    .disableReflectionPaletteLoad = FALSE,
    .tracks = TRACKS_FOOT, //Can also be TRACKS_TIRE
    .gender = MALE, //Can also be FEMALE
    .oam = gEventObjectBaseOam_32x32,
    .subspriteTables = gEventObjectSpriteOamTables_32x32,
    .anims = gEventObjectImageAnimTable_Standard,
    .images = gEventObjectPicTable_PC2,
    .affineAnims = gDummySpriteAffineAnimTable,
};
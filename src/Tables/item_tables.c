#include "../defines.h"
#include "../../include/battle.h"
#include "../../include/constants/hold_effects.h"
#include "../../include/constants/items.h"
#include "../../include/new/item.h"
#include "../../include/new/pickup_items.h"
/*
item_tables.c
	set up item data tables
		-pickup lists
		-fling
		-ban lists

tables to edit:
	sPickupCommonItems
	sPickupRareItems
	gFlingTable
	gConsumableItemEffects
	gItemsByType

*/

const item_t sPickupCommonItems[PU_NUM_COMMON_ITEMS] =
{
	ITEM_POTION,
	ITEM_ANTIDOTE,
	ITEM_SUPER_POTION,
	ITEM_GREAT_BALL,
	ITEM_REPEL,
	ITEM_ESCAPE_ROPE,
	ITEM_FULL_HEAL,
	ITEM_HYPER_POTION,
	ITEM_ULTRA_BALL,
	ITEM_REVIVE,
	ITEM_RARE_CANDY,
	ITEM_SUN_STONE,
	ITEM_MOON_STONE,
	ITEM_HEART_SCALE,
	ITEM_FULL_RESTORE,
	ITEM_MAX_REVIVE,
	ITEM_PP_UP,
	ITEM_MAX_ELIXIR,
};

const item_t sPickupRareItems[PU_NUM_RARE_ITEMS] =
{
#ifndef UNBOUND //Modify this
	ITEM_HYPER_POTION,
	ITEM_NUGGET,
	ITEM_KINGS_ROCK,
	ITEM_FULL_RESTORE,
	ITEM_ETHER,
	ITEM_IRON_BALL,
	ITEM_DESTINY_KNOT,
	ITEM_ELIXIR,
	ITEM_DESTINY_KNOT,
	ITEM_LEFTOVERS,
	ITEM_DESTINY_KNOT,

#else //For Pokemon Unbound
	ITEM_HYPER_POTION,
	ITEM_NUGGET,
	ITEM_KINGS_ROCK,
	ITEM_FULL_RESTORE,
	ITEM_ETHER,
	ITEM_IRON_BALL,
	ITEM_DESTINY_KNOT,
	ITEM_ELIXIR,
	ITEM_BOTTLE_CAP,
	ITEM_LEFTOVERS,
	ITEM_ABILITY_CAPSULE,
#endif
};

const u32 pickup_common_item_ceilings[PU_COMMON_PER_ROW] =
{
	19661, 26214, 32768, 39322, 45875, 52429, 58982, 61604, 64225
};

const u32 pickup_rare_item_ceilings[PU_RARE_PER_ROW] =
{
	64881, 65536
};

//Any values not listed default to BP 30
const struct FlingStruct gFlingTable[ITEMS_COUNT] =
{
	[ITEM_CHERI_BERRY] = {10, 0},
	[ITEM_CHESTO_BERRY] = {10, 0},
	[ITEM_PECHA_BERRY] = {10, 0},
	[ITEM_RAWST_BERRY] = {10, 0},
	[ITEM_ASPEAR_BERRY] = {10, 0},
	[ITEM_LEPPA_BERRY] = {10, 0},
	[ITEM_ORAN_BERRY] = {10, 0},
	[ITEM_PERSIM_BERRY] = {10, 0},
	[ITEM_LUM_BERRY] = {10, 0},
	[ITEM_SITRUS_BERRY] = {10, 0},
	[ITEM_FIGY_BERRY] = {10, 0},
	[ITEM_WIKI_BERRY] = {10, 0},
	[ITEM_MAGO_BERRY] = {10, 0},
	[ITEM_AGUAV_BERRY] = {10, 0},
	[ITEM_IAPAPA_BERRY] = {10, 0},
	[ITEM_RAZZ_BERRY] = {10, 0},
	[ITEM_BLUK_BERRY] = {10, 0},
	[ITEM_NANAB_BERRY] = {10, 0},
	[ITEM_WEPEAR_BERRY] = {10, 0},
	[ITEM_PINAP_BERRY] = {10, 0},
	[ITEM_POMEG_BERRY] = {10, 0},
	[ITEM_KELPSY_BERRY] = {10, 0},
	[ITEM_QUALOT_BERRY] = {10, 0},
	[ITEM_HONDEW_BERRY] = {10, 0},
	[ITEM_GREPA_BERRY] = {10, 0},
	[ITEM_TAMATO_BERRY] = {10, 0},
	[ITEM_CORNN_BERRY] = {10, 0},
	[ITEM_MAGOST_BERRY] = {10, 0},
	[ITEM_RABUTA_BERRY] = {10, 0},
	[ITEM_NOMEL_BERRY] = {10, 0},
	[ITEM_SPELON_BERRY] = {10, 0},
	[ITEM_PAMTRE_BERRY] = {10, 0},
	[ITEM_WATMEL_BERRY] = {10, 0},
	[ITEM_DURIN_BERRY] = {10, 0},
	[ITEM_BELUE_BERRY] = {10, 0},
	[ITEM_LIECHI_BERRY] = {10, 0},
	[ITEM_GANLON_BERRY] = {10, 0},
	[ITEM_SALAC_BERRY] = {10, 0},
	[ITEM_PETAYA_BERRY] = {10, 0},
	[ITEM_APICOT_BERRY] = {10, 0},
	[ITEM_LANSAT_BERRY] = {10, 0},
	[ITEM_STARF_BERRY] = {10, 0},
	[ITEM_ENIGMA_BERRY] = {10, 0},
	[ITEM_OCCA_BERRY] = {10, 0},
	[ITEM_PASSHO_BERRY] = {10, 0},
	[ITEM_WACAN_BERRY] = {10, 0},
	[ITEM_RINDO_BERRY] = {10, 0},
	[ITEM_YACHE_BERRY] = {10, 0},
	[ITEM_CHOPLE_BERRY] = {10, 0},
	[ITEM_KEBIA_BERRY] = {10, 0},
	[ITEM_SHUCA_BERRY] = {10, 0},
	[ITEM_COBA_BERRY] = {10, 0},
	[ITEM_PAYAPA_BERRY] = {10, 0},
	[ITEM_TANGA_BERRY] = {10, 0},
	[ITEM_CHARTI_BERRY] = {10, 0},
	[ITEM_KASIB_BERRY] = {10, 0},
	[ITEM_HABAN_BERRY] = {10, 0},
	[ITEM_COLBUR_BERRY] = {10, 0},
	[ITEM_BABIRI_BERRY] = {10, 0},
	[ITEM_CHILAN_BERRY] = {10, 0},
	[ITEM_MICLE_BERRY] = {10, 0},
	[ITEM_CUSTAP_BERRY] = {10, 0},
	[ITEM_JABOCA_BERRY] = {10, 0},
	[ITEM_ROWAP_BERRY] = {10, 0},
	[ITEM_ROSELI_BERRY] = {10, 0},
	[ITEM_KEE_BERRY] = {10, 0},
	[ITEM_MARANGA_BERRY] = {10, 0},
	[ITEM_SEA_INCENSE] = {10, 0},
	[ITEM_LAX_INCENSE] = {10, 0},
	[ITEM_LUCK_INCENSE] = {10, 0},
	[ITEM_FULL_INCENSE] = {10, 0},
	[ITEM_ODD_INCENSE] = {10, 0},
	[ITEM_PURE_INCENSE] = {10, 0},
	[ITEM_ROCK_INCENSE] = {10, 0},
	[ITEM_ROSE_INCENSE] = {10, 0},
	[ITEM_WAVE_INCENSE] = {10, 0},
	[ITEM_AIR_BALLOON] = {10, 0},
	[ITEM_BIG_ROOT] = {10, 0},
	[ITEM_BRIGHT_POWDER] = {10, 0},
	[ITEM_CHOICE_BAND] = {10, 0},
	[ITEM_CHOICE_SCARF] = {10, 0},
	[ITEM_CHOICE_SPECS] = {10, 0},
	[ITEM_DESTINY_KNOT] = {10, 0},
	[ITEM_ELECTRIC_SEED] = {10, 0},
	[ITEM_EXPERT_BELT] = {10, 0},
	[ITEM_FOCUS_BAND] = {10, 0},
	[ITEM_FOCUS_SASH] = {10, 0},
	[ITEM_GRASSY_SEED] = {10, 0},
	[ITEM_LAGGING_TAIL] = {10, 0},
	[ITEM_LEFTOVERS] = {10, 0},
	[ITEM_MENTAL_HERB] = {10, 0},
	[ITEM_METAL_POWDER] = {10, 0},
	[ITEM_MISTY_SEED] = {10, 0},
	[ITEM_MUSCLE_BAND] = {10, 0},
	[ITEM_PINK_NECTAR] = {10, 0},
	[ITEM_POWER_HERB] = {10, 0},
	[ITEM_PSYCHIC_SEED] = {10, 0},
	[ITEM_PURPLE_NECTAR] = {10, 0},
	[ITEM_QUICK_POWDER] = {10, 0},
	[ITEM_REAPER_CLOTH] = {10, 0},
	[ITEM_RED_CARD] = {10, 0},
	[ITEM_RED_NECTAR] = {10, 0},
	[ITEM_RING_TARGET] = {10, 0},
	[ITEM_SHED_SHELL] = {10, 0},
	[ITEM_SILK_SCARF] = {10, 0},
	[ITEM_SILVER_POWDER] = {10, 0},
	[ITEM_SMOOTH_ROCK] = {10, 0},
	[ITEM_SOFT_SAND] = {10, 0},
	[ITEM_SOOTHE_BELL] = {10, 0},
	[ITEM_WHITE_HERB] = {10, 0},
	[ITEM_WIDE_LENS] = {10, 0},
	[ITEM_WISE_GLASSES] = {10, 0},
	[ITEM_YELLOW_NECTAR] = {10, 0},
	[ITEM_ZOOM_LENS] = {10, 0},
	[ITEM_HEALTH_WING] = {20, 0},
	[ITEM_MUSCLE_WING] = {20, 0},
	[ITEM_RESIST_WING] = {20, 0},
	[ITEM_GENIUS_WING] = {20, 0},
	[ITEM_CLEVER_WING] = {20, 0},
	[ITEM_SWIFT_WING] = {20, 0},
	[ITEM_PRETTY_WING] = {20, 0},
	[ITEM_ETHER] = {30, 0},
	[ITEM_ELIXIR] = {30, 0},
	[ITEM_MAX_ETHER] = {30, 0},
	[ITEM_MAX_ELIXIR] = {30, 0},
	[ITEM_ABSORB_BULB] = {30, 0},
	[ITEM_ADRENALINE_ORB] = {30, 0},
	[ITEM_AMULET_COIN] = {30, 0},
	[ITEM_BALM_MUSHROOM] = {30, 0},
	[ITEM_BERRY_JUICE] = {30, 0},
	[ITEM_BIG_MALASADA] = {30, 0},
	[ITEM_BIG_MUSHROOM] = {30, 0},
	[ITEM_BIG_NUGGET] = {30, 0},
	[ITEM_BIG_PEARL] = {30, 0},
	[ITEM_BINDING_BAND] = {30, 0},
	[ITEM_BLACK_BELT] = {30, 0},
	[ITEM_BLACK_GLASSES] = {30, 0},
	[ITEM_BLACK_SLUDGE] = {30, 0},
	[ITEM_BOTTLE_CAP] = {30, 0},
	[ITEM_CASTELIACONE] = {30, 0},
	[ITEM_CELL_BATTERY] = {30, 0},
	[ITEM_CHARCOAL] = {30, 0},
	[ITEM_CLEANSE_TAG] = {30, 0},
	[ITEM_COMET_SHARD] = {30, 0},
	[ITEM_DEEP_SEA_SCALE] = {30, 0},
	[ITEM_DRAGON_SCALE] = {30, 0},
	[ITEM_EJECT_BUTTON] = {30, 0},
	[ITEM_ESCAPE_ROPE] = {30, 0},
	[ITEM_EVERSTONE] = {30, 0},
	[ITEM_EXP_SHARE] = {30, 0},
	[ITEM_FIRE_STONE] = {30, 0},
	[ITEM_FLAME_ORB] = {30, MOVE_EFFECT_BURN},
	[ITEM_FLOAT_STONE] = {30, 0},
	[ITEM_FLUFFY_TAIL] = {30, 0},
	[ITEM_FROST_ORB] = {30, MOVE_EFFECT_FREEZE},
	[ITEM_GOLD_BOTTLE_CAP] = {30, 0},
	[ITEM_HEART_SCALE] = {30, 0},
	[ITEM_HONEY] = {30, 0},
	[ITEM_ICE_STONE] = {30, 0},
	[ITEM_KINGS_ROCK] = {30, MOVE_EFFECT_FLINCH},
	[ITEM_LAVA_COOKIE] = {30, 0},
	[ITEM_LEAF_STONE] = {30, 0},
	[ITEM_LIFE_ORB] = {30, 0},
	[ITEM_LIGHT_BALL] = {30, MOVE_EFFECT_PARALYSIS},
	[ITEM_LIGHT_CLAY] = {30, 0},
	[ITEM_LUCKY_EGG] = {30, 0},
	[ITEM_LUMINOUS_MOSS] = {30, 0},
	[ITEM_LUMIOSE_GALETTE] = {30, 0},
	[ITEM_MAGNET] = {30, 0},
	[ITEM_MAX_REVIVE] = {30, 0},
	[ITEM_METAL_COAT] = {30, 0},
	[ITEM_METRONOME] = {30, 0},
	[ITEM_MIRACLE_SEED] = {30, 0},
	[ITEM_MOON_STONE] = {30, 0},
	[ITEM_MYSTIC_WATER] = {30, 0},
	[ITEM_NEVER_MELT_ICE] = {30, 0},
	[ITEM_NUGGET] = {30, 0},
	[ITEM_OLD_GATEAU] = {30, 0},
	[ITEM_PEARL_STRING] = {30, 0},
	[ITEM_PEARL] = {30, 0},
	[ITEM_POKE_DOLL] = {30, 0},
	[ITEM_PRISM_SCALE] = {30, 0},
	[ITEM_PROTECTIVE_PADS] = {30, 0},
	[ITEM_RAZOR_FANG] = {30, MOVE_EFFECT_FLINCH},
	[ITEM_RELIC_BAND] = {30, 0},
	[ITEM_RELIC_COPPER] = {30, 0},
	[ITEM_RELIC_CROWN] = {30, 0},
	[ITEM_RELIC_GOLD] = {30, 0},
	[ITEM_RELIC_SILVER] = {30, 0},
	[ITEM_RELIC_STATUE] = {30, 0},
	[ITEM_RELIC_VASE] = {30, 0},
	[ITEM_REVIVE] = {30, 0},
	[ITEM_SACRED_ASH] = {30, 0},
	[ITEM_SCOPE_LENS] = {30, 0},
	[ITEM_SHALOUR_SABLE] = {30, 0},
	[ITEM_SHELL_BELL] = {30, 0},
	[ITEM_SHOAL_SALT] = {30, 0},
	[ITEM_SHOAL_SHELL] = {30, 0},
	[ITEM_SMOKE_BALL] = {30, 0},
#ifdef UNBOUND
	[ITEM_SNOWBALL] = {30, MOVE_EFFECT_FREEZE},
#else
	[ITEM_SNOWBALL] = {30, 0},
#endif
	[ITEM_SOUL_DEW] = {30, 0},
	[ITEM_SPELL_TAG] = {30, 0},
	[ITEM_STAR_PIECE] = {30, 0},
	[ITEM_STARDUST] = {30, 0},
	[ITEM_SUN_STONE] = {30, 0},
	[ITEM_THUNDER_STONE] = {30, 0},
	[ITEM_TINY_MUSHROOM] = {30, 0},
	[ITEM_TOXIC_ORB] = {30, MOVE_EFFECT_TOXIC},
	[ITEM_TWISTED_SPOON] = {30, 0},
	[ITEM_UP_GRADE] = {30, 0},
	[ITEM_WATER_STONE] = {30, 0},
	[ITEM_EVIOLITE] = {40, 0},
	[ITEM_ICY_ROCK] = {40, 0},
	[ITEM_LUCKY_PUNCH] = {40, 0},
	[ITEM_FIGHTING_MEMORY] = {50, 0},
	[ITEM_FLYING_MEMORY] = {50, 0},
	[ITEM_POISON_MEMORY] = {50, 0},
	[ITEM_GROUND_MEMORY] = {50, 0},
	[ITEM_ROCK_MEMORY] = {50, 0},
	[ITEM_BUG_MEMORY] = {50, 0},
	[ITEM_GHOST_MEMORY] = {50, 0},
	[ITEM_STEEL_MEMORY] = {50, 0},
	[ITEM_FIRE_MEMORY] = {50, 0},
	[ITEM_WATER_MEMORY] = {50, 0},
	[ITEM_GRASS_MEMORY] = {50, 0},
	[ITEM_ELECTRIC_MEMORY] = {50, 0},
	[ITEM_PSYCHIC_MEMORY] = {50, 0},
	[ITEM_ICE_MEMORY] = {50, 0},
	[ITEM_DRAGON_MEMORY] = {50, 0},
	[ITEM_DARK_MEMORY] = {50, 0},
	[ITEM_FAIRY_MEMORY] = {50, 0},
	[ITEM_DUBIOUS_DISC] = {50, 0},
	[ITEM_SHARP_BEAK] = {50, 0},
	[ITEM_ADAMANT_ORB] = {60, 0},
	[ITEM_DAMP_ROCK] = {60, 0},
	[ITEM_GRISEOUS_ORB] = {60, 0},
	[ITEM_HEAT_ROCK] = {60, 0},
	[ITEM_LUSTROUS_ORB] = {60, 0},
	[ITEM_MACHO_BRACE] = {60, 0},
	[ITEM_ROCKY_HELMET] = {60, 0},
	[ITEM_LEEK] = {60, 0},
	[ITEM_TERRAIN_EXTENDER] = {60, 0},
	[ITEM_BURN_DRIVE] = {70, 0},
	[ITEM_DOUSE_DRIVE] = {70, 0},
	[ITEM_SHOCK_DRIVE] = {70, 0},
	[ITEM_CHILL_DRIVE] = {70, 0},
	[ITEM_DRAGON_FANG] = {70, 0},
	[ITEM_POISON_BARB] = {70, MOVE_EFFECT_POISON},
	[ITEM_POWER_ANKLET] = {70, 0},
	[ITEM_POWER_BAND] = {70, 0},
	[ITEM_POWER_BELT] = {70, 0},
	[ITEM_POWER_BRACER] = {70, 0},
	[ITEM_POWER_LENS] = {70, 0},
	[ITEM_POWER_WEIGHT] = {70, 0},
	[ITEM_ULTRANECROZIUM_Z] = {80, 0},
	[ITEM_VENUSAURITE] = {80, 0},
	[ITEM_CHARIZARDITE_X] = {80, 0},
	[ITEM_CHARIZARDITE_Y] = {80, 0},
	[ITEM_BLASTOISINITE] = {80, 0},
	[ITEM_BEEDRILLITE] = {80, 0},
	[ITEM_PIDGEOTITE] = {80, 0},
	[ITEM_ALAKAZITE] = {80, 0},
	[ITEM_SLOWBRONITE] = {80, 0},
	[ITEM_GENGARITE] = {80, 0},
	[ITEM_KANGASKHANITE] = {80, 0},
	[ITEM_PINSIRITE] = {80, 0},
	[ITEM_GYARADOSITE] = {80, 0},
	[ITEM_AERODACTYLITE] = {80, 0},
	[ITEM_MEWTWONITE_X] = {80, 0},
	[ITEM_MEWTWONITE_Y] = {80, 0},
	[ITEM_AMPHAROSITE] = {80, 0},
	[ITEM_STEELIXITE] = {80, 0},
	[ITEM_SCIZORITE] = {80, 0},
	[ITEM_HERACRONITE] = {80, 0},
	[ITEM_HOUNDOOMINITE] = {80, 0},
	[ITEM_TYRANITARITE] = {80, 0},
	[ITEM_SCEPTILITE] = {80, 0},
	[ITEM_BLAZIKENITE] = {80, 0},
	[ITEM_SWAMPERTITE] = {80, 0},
	[ITEM_GARDEVOIRITE] = {80, 0},
	[ITEM_SABLENITE] = {80, 0},
	[ITEM_MAWILITE] = {80, 0},
	[ITEM_AGGRONITE] = {80, 0},
	[ITEM_MEDICHAMITE] = {80, 0},
	[ITEM_MANECTITE] = {80, 0},
	[ITEM_SHARPEDONITE] = {80, 0},
	[ITEM_CAMERUPTITE] = {80, 0},
	[ITEM_ALTARIANITE] = {80, 0},
	[ITEM_BANETTITE] = {80, 0},
	[ITEM_ABSOLITE] = {80, 0},
	[ITEM_GLALITITE] = {80, 0},
	[ITEM_SALAMENCITE] = {80, 0},
	[ITEM_METAGROSSITE] = {80, 0},
	[ITEM_LATIASITE] = {80, 0},
	[ITEM_LATIOSITE] = {80, 0},
	[ITEM_LOPUNNITE] = {80, 0},
	[ITEM_GARCHOMPITE] = {80, 0},
	[ITEM_LUCARIONITE] = {80, 0},
	[ITEM_ABOMASITE] = {80, 0},
	[ITEM_GALLADITE] = {80, 0},
	[ITEM_AUDINITE] = {80, 0},
	[ITEM_DIANCITE] = {80, 0},
	[ITEM_ASSAULT_VEST] = {80, 0},
	[ITEM_DAWN_STONE] = {80, 0},
	[ITEM_DUSK_STONE] = {80, 0},
	[ITEM_ELECTIRIZER] = {80, 0},
	[ITEM_MAGMARIZER] = {80, 0},
	[ITEM_ODD_KEYSTONE] = {80, 0},
	[ITEM_OVAL_STONE] = {80, 0},
	[ITEM_PROTECTOR] = {80, 0},
	[ITEM_QUICK_CLAW] = {80, 0},
	[ITEM_RAZOR_CLAW] = {80, 0},
	[ITEM_SACHET] = {80, 0},
	[ITEM_SAFETY_GOGGLES] = {80, 0},
	[ITEM_SHINY_STONE] = {80, 0},
	[ITEM_STICKY_BARB] = {80, 0},
	[ITEM_WEAKNESS_POLICY] = {80, 0},
	[ITEM_WHIPPED_DREAM] = {80, 0},
	[ITEM_STRAWBERRY_SWEET] = {80, 0},
	[ITEM_BERRY_SWEET] = {80, 0},
	[ITEM_LOVE_SWEET] = {80, 0},
	[ITEM_CLOVER_SWEET] = {80, 0},
	[ITEM_FLOWER_SWEET] = {80, 0},
	[ITEM_RIBBON_SWEET] = {80, 0},
	[ITEM_STAR_SWEET] = {80, 0},
	[ITEM_SWEET_APPLE] = {80, 0},
	[ITEM_TART_APPLE] = {80, 0},
	[ITEM_CRACKED_POT] = {80, 0},
	[ITEM_CHIPPED_POT] = {80, 0},
	[ITEM_GALARICA_CUFF] = {80, 0},
	[ITEM_GALARICA_WREATH] = {80, 0},
	[ITEM_FIST_PLATE] = {90, 0},
	[ITEM_SKY_PLATE] = {90, 0},
	[ITEM_TOXIC_PLATE] = {90, 0},
	[ITEM_EARTH_PLATE] = {90, 0},
	[ITEM_STONE_PLATE] = {90, 0},
	[ITEM_INSECT_PLATE] = {90, 0},
	[ITEM_SPOOKY_PLATE] = {90, 0},
	[ITEM_IRON_PLATE] = {90, 0},
	[ITEM_FLAME_PLATE] = {90, 0},
	[ITEM_SPLASH_PLATE] = {90, 0},
	[ITEM_MEADOW_PLATE] = {90, 0},
	[ITEM_ZAP_PLATE] = {90, 0},
	[ITEM_MIND_PLATE] = {90, 0},
	[ITEM_ICICLE_PLATE] = {90, 0},
	[ITEM_DRACO_PLATE] = {90, 0},
	[ITEM_DREAD_PLATE] = {90, 0},
	[ITEM_PIXIE_PLATE] = {90, 0},
	[ITEM_DEEP_SEA_TOOTH] = {90, 0},
	[ITEM_GRIP_CLAW] = {90, 0},
	[ITEM_THICK_CLUB] = {90, 0},
	[ITEM_HELIX_FOSSIL] = {100, 0},
	[ITEM_DOME_FOSSIL] = {100, 0},
	[ITEM_ROOT_FOSSIL] = {100, 0},
	[ITEM_CLAW_FOSSIL] = {100, 0},
	[ITEM_SKULL_FOSSIL] = {100, 0},
	[ITEM_ARMOR_FOSSIL] = {100, 0},
	[ITEM_COVER_FOSSIL] = {100, 0},
	[ITEM_PLUME_FOSSIL] = {100, 0},
	[ITEM_JAW_FOSSIL] = {100, 0},
	[ITEM_SAIL_FOSSIL] = {100, 0},
	[ITEM_FOSSILIZED_BIRD] = {100, 0}, 
	[ITEM_FOSSILIZED_FISH] = {100, 0},
	[ITEM_FOSSILIZED_DRAKE] = {100, 0},
	[ITEM_FOSSILIZED_DINO] = {100, 0},
	[ITEM_HARD_STONE] = {100, 0},
	[ITEM_RARE_BONE] = {100, 0},
	[ITEM_IRON_BALL] = {130, 0},
};

const u16 gBannedBattleEatBerries[] =
{
	ITEM_POMEG_BERRY,
	ITEM_KELPSY_BERRY,
	ITEM_QUALOT_BERRY,
	ITEM_HONDEW_BERRY,
	ITEM_GREPA_BERRY,
	ITEM_TAMATO_BERRY,
	ITEM_TABLES_TERMIN
};

const u8 gConsumableItemEffects[] =
{
	ITEM_EFFECT_RESTORE_HP,
	ITEM_EFFECT_CURE_PAR,
	ITEM_EFFECT_CURE_SLP,
	ITEM_EFFECT_CURE_PSN,
	ITEM_EFFECT_CURE_BRN,
	ITEM_EFFECT_CURE_FRZ,
	ITEM_EFFECT_RESTORE_PP,
	ITEM_EFFECT_CURE_CONFUSION,
	ITEM_EFFECT_CURE_STATUS,
	ITEM_EFFECT_CONFUSE_SPICY,
	ITEM_EFFECT_CONFUSE_DRY,
	ITEM_EFFECT_CONFUSE_SWEET,
	ITEM_EFFECT_CONFUSE_BITTER,
	ITEM_EFFECT_CONFUSE_SOUR,
	ITEM_EFFECT_ATTACK_UP,
	ITEM_EFFECT_DEFENSE_UP,
	ITEM_EFFECT_SPEED_UP,
	ITEM_EFFECT_SP_ATTACK_UP,
	ITEM_EFFECT_SP_DEFENSE_UP,
	ITEM_EFFECT_CRITICAL_UP,
	ITEM_EFFECT_RANDOM_STAT_UP,
	ITEM_EFFECT_RESTORE_STATS,
	ITEM_EFFECT_CURE_ATTRACT,
	ITEM_EFFECT_WEAKNESS_POLICY,
	ITEM_EFFECT_GEM,
	ITEM_EFFECT_WEAKNESS_BERRY,
	ITEM_EFFECT_CUSTAP_BERRY,
	ITEM_EFFECT_ABSORB_BULB,
	ITEM_EFFECT_AIR_BALLOON,
	ITEM_EFFECT_CELL_BATTERY,
	ITEM_EFFECT_EJECT_BUTTON,
	ITEM_EFFECT_LUMINOUS_MOSS,
	ITEM_EFFECT_RED_CARD,
	ITEM_EFFECT_SNOWBALL,
	ITEM_EFFECT_SEEDS,
	ITEM_EFFECT_JABOCA_ROWAP_BERRY,
	ITEM_EFFECT_KEE_BERRY,
	ITEM_EFFECT_MARANGA_BERRY,
	ITEM_EFFECT_ADRENALINE_ORB,
	ITEM_EFFECT_POWER_HERB,
	ITEM_EFFECT_MICLE_BERRY,
	ITEM_EFFECT_ENIGMA_BERRY,
	ITEM_EFFECT_EJECT_PACK,
	ITEM_EFFECT_ROOM_SERVICE,
	ITEM_EFFECT_BLUNDER_POLICY,
	ITEM_EFFECT_HEAVY_DUTY_BOOTS,
	ITEM_EFFECT_UTILITY_UMBRELLA,
	ITEM_EFFECT_THROAT_SPRAY,
	0xFF,
};

const u16 gItemsByType[ITEMS_COUNT] =
{
	[ITEM_REPEL] = ITEM_TYPE_FIELD_USE,
	[ITEM_SUPER_REPEL] = ITEM_TYPE_FIELD_USE,
	[ITEM_MAX_REPEL] = ITEM_TYPE_FIELD_USE,
	[ITEM_ESCAPE_ROPE] = ITEM_TYPE_FIELD_USE,
	[ITEM_HONEY] = ITEM_TYPE_FIELD_USE,

	[ITEM_POTION] = ITEM_TYPE_HEALTH_RECOVERY,
	[ITEM_FULL_RESTORE] = ITEM_TYPE_HEALTH_RECOVERY,
	[ITEM_MAX_POTION] = ITEM_TYPE_HEALTH_RECOVERY,
	[ITEM_HYPER_POTION] = ITEM_TYPE_HEALTH_RECOVERY,
	[ITEM_SUPER_POTION] = ITEM_TYPE_HEALTH_RECOVERY,
	[ITEM_REVIVE] = ITEM_TYPE_HEALTH_RECOVERY,
	[ITEM_MAX_REVIVE] = ITEM_TYPE_HEALTH_RECOVERY,
	[ITEM_FRESH_WATER] = ITEM_TYPE_HEALTH_RECOVERY,
	[ITEM_SODA_POP] = ITEM_TYPE_HEALTH_RECOVERY,
	[ITEM_LEMONADE] = ITEM_TYPE_HEALTH_RECOVERY,
	[ITEM_MOOMOO_MILK] = ITEM_TYPE_HEALTH_RECOVERY,
	[ITEM_ENERGY_POWDER] = ITEM_TYPE_HEALTH_RECOVERY,
	[ITEM_ENERGY_ROOT] = ITEM_TYPE_HEALTH_RECOVERY,
	[ITEM_REVIVAL_HERB] = ITEM_TYPE_HEALTH_RECOVERY,
	[ITEM_BERRY_JUICE] = ITEM_TYPE_HEALTH_RECOVERY,
	[ITEM_SACRED_ASH] = ITEM_TYPE_HEALTH_RECOVERY,

	[ITEM_ANTIDOTE] = ITEM_TYPE_STATUS_RECOVERY,
	[ITEM_BURN_HEAL] = ITEM_TYPE_STATUS_RECOVERY,
	[ITEM_ICE_HEAL] = ITEM_TYPE_STATUS_RECOVERY,
	[ITEM_AWAKENING] = ITEM_TYPE_STATUS_RECOVERY,
	[ITEM_PARALYZE_HEAL] = ITEM_TYPE_STATUS_RECOVERY,
	[ITEM_FULL_HEAL] = ITEM_TYPE_STATUS_RECOVERY,
	[ITEM_LAVA_COOKIE] = ITEM_TYPE_STATUS_RECOVERY,
	[ITEM_BIG_MALASADA] = ITEM_TYPE_STATUS_RECOVERY,
	[ITEM_CASTELIACONE] = ITEM_TYPE_STATUS_RECOVERY,
	[ITEM_LUMIOSE_GALETTE] = ITEM_TYPE_STATUS_RECOVERY,
	[ITEM_RAGE_CANDY_BAR] = ITEM_TYPE_STATUS_RECOVERY,
	[ITEM_SHALOUR_SABLE] = ITEM_TYPE_STATUS_RECOVERY,
	[ITEM_OLD_GATEAU] = ITEM_TYPE_STATUS_RECOVERY,
	[ITEM_HEAL_POWDER] = ITEM_TYPE_STATUS_RECOVERY,

	[ITEM_ETHER] = ITEM_TYPE_PP_RECOVERY,
	[ITEM_MAX_ETHER] = ITEM_TYPE_PP_RECOVERY,
	[ITEM_ELIXIR] = ITEM_TYPE_PP_RECOVERY,
	[ITEM_MAX_ELIXIR] = ITEM_TYPE_PP_RECOVERY,

	[ITEM_HP_UP] = ITEM_TYPE_STAT_BOOST_DRINK,
	[ITEM_PROTEIN] = ITEM_TYPE_STAT_BOOST_DRINK,
	[ITEM_IRON] = ITEM_TYPE_STAT_BOOST_DRINK,
	[ITEM_CARBOS] = ITEM_TYPE_STAT_BOOST_DRINK,
	[ITEM_CALCIUM] = ITEM_TYPE_STAT_BOOST_DRINK,
	[ITEM_RARE_CANDY] = ITEM_TYPE_STAT_BOOST_DRINK,
	[ITEM_PP_UP] = ITEM_TYPE_STAT_BOOST_DRINK,
	[ITEM_ZINC] = ITEM_TYPE_STAT_BOOST_DRINK,
	[ITEM_PP_MAX] = ITEM_TYPE_STAT_BOOST_DRINK,
	[ITEM_ABILITY_CAPSULE] = ITEM_TYPE_STAT_BOOST_DRINK,
	[ITEM_DYNAMAX_CANDY] = ITEM_TYPE_STAT_BOOST_DRINK,

	[ITEM_HEALTH_WING] = ITEM_TYPE_STAT_BOOST_WING,
	[ITEM_MUSCLE_WING] = ITEM_TYPE_STAT_BOOST_WING,
	[ITEM_RESIST_WING] = ITEM_TYPE_STAT_BOOST_WING,
	[ITEM_GENIUS_WING] = ITEM_TYPE_STAT_BOOST_WING,
	[ITEM_CLEVER_WING] = ITEM_TYPE_STAT_BOOST_WING,
	[ITEM_SWIFT_WING] = ITEM_TYPE_STAT_BOOST_WING,
	[ITEM_PRETTY_WING] = ITEM_TYPE_STAT_BOOST_WING,

	[ITEM_POWER_BRACER] = ITEM_TYPE_STAT_BOOST_HELD_ITEM,
	[ITEM_POWER_BELT] = ITEM_TYPE_STAT_BOOST_HELD_ITEM,
	[ITEM_POWER_LENS] = ITEM_TYPE_STAT_BOOST_HELD_ITEM,
	[ITEM_POWER_BAND] = ITEM_TYPE_STAT_BOOST_HELD_ITEM,
	[ITEM_POWER_ANKLET] = ITEM_TYPE_STAT_BOOST_HELD_ITEM,
	[ITEM_POWER_WEIGHT] = ITEM_TYPE_STAT_BOOST_HELD_ITEM,
	[ITEM_MACHO_BRACE] = ITEM_TYPE_STAT_BOOST_HELD_ITEM,

	[ITEM_SUN_STONE] = ITEM_TYPE_EVOLUTION_STONE,
	[ITEM_MOON_STONE] = ITEM_TYPE_EVOLUTION_STONE,
	[ITEM_FIRE_STONE] = ITEM_TYPE_EVOLUTION_STONE,
	[ITEM_THUNDER_STONE] = ITEM_TYPE_EVOLUTION_STONE,
	[ITEM_WATER_STONE] = ITEM_TYPE_EVOLUTION_STONE,
	[ITEM_LEAF_STONE] = ITEM_TYPE_EVOLUTION_STONE,
	[ITEM_DAWN_STONE] = ITEM_TYPE_EVOLUTION_STONE,
	[ITEM_DUSK_STONE] = ITEM_TYPE_EVOLUTION_STONE,
	[ITEM_SHINY_STONE] = ITEM_TYPE_EVOLUTION_STONE,
	[ITEM_ICE_STONE] = ITEM_TYPE_EVOLUTION_STONE,
	[ITEM_OVAL_STONE] = ITEM_TYPE_EVOLUTION_STONE,
	[ITEM_LINK_CABLE] = ITEM_TYPE_EVOLUTION_STONE,
	[ITEM_BLACK_AUGURITE] = ITEM_TYPE_EVOLUTION_STONE,

	[ITEM_KINGS_ROCK] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_DEEP_SEA_TOOTH] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_DEEP_SEA_SCALE] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_EVERSTONE] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_METAL_COAT] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_DRAGON_SCALE] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_UP_GRADE] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_PROTECTOR] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_MAGMARIZER] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_PRISM_SCALE] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_SACHET] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_WHIPPED_DREAM] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_RAZOR_CLAW] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_RAZOR_FANG] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_REAPER_CLOTH] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_DUBIOUS_DISC] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_ELECTIRIZER] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_STRAWBERRY_SWEET] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_BERRY_SWEET] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_LOVE_SWEET] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_CLOVER_SWEET] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_FLOWER_SWEET] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_RIBBON_SWEET] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_STAR_SWEET] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_SWEET_APPLE] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_TART_APPLE] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_CRACKED_POT] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_CHIPPED_POT] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_GALARICA_CUFF] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_GALARICA_WREATH] = ITEM_TYPE_EVOLUTION_ITEM,
	[ITEM_GUARD_SPEC] = ITEM_TYPE_BATTLE_ITEM,
	[ITEM_DIRE_HIT] = ITEM_TYPE_BATTLE_ITEM,
	[ITEM_X_ATTACK] = ITEM_TYPE_BATTLE_ITEM,
	[ITEM_X_DEFEND] = ITEM_TYPE_BATTLE_ITEM,
	[ITEM_X_SPEED] = ITEM_TYPE_BATTLE_ITEM,
	[ITEM_X_ACCURACY] = ITEM_TYPE_BATTLE_ITEM,
	[ITEM_X_SPECIAL] = ITEM_TYPE_BATTLE_ITEM,
	//[ITEM_X_SP_DEF] = ITEM_TYPE_BATTLE_ITEM,
	[ITEM_POKE_DOLL] = ITEM_TYPE_BATTLE_ITEM,
	[ITEM_FLUFFY_TAIL] = ITEM_TYPE_BATTLE_ITEM,

	[ITEM_BRIGHT_POWDER] = ITEM_TYPE_HELD_ITEM,
	[ITEM_WHITE_HERB] = ITEM_TYPE_HELD_ITEM,
	[ITEM_EXP_SHARE] = ITEM_TYPE_HELD_ITEM,
	[ITEM_QUICK_CLAW] = ITEM_TYPE_HELD_ITEM,
	[ITEM_SOOTHE_BELL] = ITEM_TYPE_HELD_ITEM,
	[ITEM_MENTAL_HERB] = ITEM_TYPE_HELD_ITEM,
	[ITEM_CHOICE_BAND] = ITEM_TYPE_HELD_ITEM,
	[ITEM_SILVER_POWDER] = ITEM_TYPE_HELD_ITEM,
	[ITEM_AMULET_COIN] = ITEM_TYPE_HELD_ITEM,
	[ITEM_CLEANSE_TAG] = ITEM_TYPE_HELD_ITEM,
	[ITEM_SOUL_DEW] = ITEM_TYPE_HELD_ITEM,
	[ITEM_SMOKE_BALL] = ITEM_TYPE_HELD_ITEM,
	[ITEM_FOCUS_BAND] = ITEM_TYPE_HELD_ITEM,
	[ITEM_LUCKY_EGG] = ITEM_TYPE_HELD_ITEM,
	[ITEM_SCOPE_LENS] = ITEM_TYPE_HELD_ITEM,
	[ITEM_LEFTOVERS] = ITEM_TYPE_HELD_ITEM,
	[ITEM_LIGHT_BALL] = ITEM_TYPE_HELD_ITEM,
	[ITEM_SOFT_SAND] = ITEM_TYPE_HELD_ITEM,
	[ITEM_HARD_STONE] = ITEM_TYPE_HELD_ITEM,
	[ITEM_MIRACLE_SEED] = ITEM_TYPE_HELD_ITEM,
	[ITEM_BLACK_GLASSES] = ITEM_TYPE_HELD_ITEM,
	[ITEM_BLACK_BELT] = ITEM_TYPE_HELD_ITEM,
	[ITEM_MAGNET] = ITEM_TYPE_HELD_ITEM,
	[ITEM_MYSTIC_WATER] = ITEM_TYPE_HELD_ITEM,
	[ITEM_SHARP_BEAK] = ITEM_TYPE_HELD_ITEM,
	[ITEM_POISON_BARB] = ITEM_TYPE_HELD_ITEM,
	[ITEM_NEVER_MELT_ICE] = ITEM_TYPE_HELD_ITEM,
	[ITEM_SPELL_TAG] = ITEM_TYPE_HELD_ITEM,
	[ITEM_TWISTED_SPOON] = ITEM_TYPE_HELD_ITEM,
	[ITEM_CHARCOAL] = ITEM_TYPE_HELD_ITEM,
	[ITEM_DRAGON_FANG] = ITEM_TYPE_HELD_ITEM,
	[ITEM_SILK_SCARF] = ITEM_TYPE_HELD_ITEM,
	[ITEM_SHELL_BELL] = ITEM_TYPE_HELD_ITEM,
	[ITEM_LUCKY_PUNCH] = ITEM_TYPE_HELD_ITEM,
	[ITEM_METAL_POWDER] = ITEM_TYPE_HELD_ITEM,
	[ITEM_THICK_CLUB] = ITEM_TYPE_HELD_ITEM,
	[ITEM_LEEK] = ITEM_TYPE_HELD_ITEM,
	[ITEM_ADAMANT_ORB] = ITEM_TYPE_MEGA_STONE,
	[ITEM_LUSTROUS_ORB] = ITEM_TYPE_MEGA_STONE,
	[ITEM_GRISEOUS_ORB] = ITEM_TYPE_HELD_ITEM,
	[ITEM_RUSTED_SWORD] = ITEM_TYPE_HELD_ITEM,
	[ITEM_RUSTED_SHIELD] = ITEM_TYPE_HELD_ITEM,
	[ITEM_EXPERT_BELT] = ITEM_TYPE_HELD_ITEM,
	[ITEM_POWER_HERB] = ITEM_TYPE_HELD_ITEM,
	[ITEM_WIDE_LENS] = ITEM_TYPE_HELD_ITEM,
	[ITEM_ZOOM_LENS] = ITEM_TYPE_HELD_ITEM,
	[ITEM_DESTINY_KNOT] = ITEM_TYPE_HELD_ITEM,
	[ITEM_SMOOTH_ROCK] = ITEM_TYPE_HELD_ITEM,
	[ITEM_DAMP_ROCK] = ITEM_TYPE_HELD_ITEM,
	[ITEM_HEAT_ROCK] = ITEM_TYPE_HELD_ITEM,
	[ITEM_ICY_ROCK] = ITEM_TYPE_HELD_ITEM,
	[ITEM_BIG_ROOT] = ITEM_TYPE_HELD_ITEM,
	[ITEM_LIGHT_CLAY] = ITEM_TYPE_HELD_ITEM,
	[ITEM_SAFETY_GOGGLES] = ITEM_TYPE_HELD_ITEM,
	[ITEM_ROCKY_HELMET] = ITEM_TYPE_HELD_ITEM,
	[ITEM_WEAKNESS_POLICY] = ITEM_TYPE_HELD_ITEM,
	[ITEM_ASSAULT_VEST] = ITEM_TYPE_HELD_ITEM,
	[ITEM_EVIOLITE] = ITEM_TYPE_HELD_ITEM,
	[ITEM_ABSORB_BULB] = ITEM_TYPE_HELD_ITEM,
	[ITEM_AIR_BALLOON] = ITEM_TYPE_HELD_ITEM,
	[ITEM_ADRENALINE_ORB] = ITEM_TYPE_HELD_ITEM,
	[ITEM_BINDING_BAND] = ITEM_TYPE_HELD_ITEM,
	[ITEM_CELL_BATTERY] = ITEM_TYPE_HELD_ITEM,
	[ITEM_EJECT_BUTTON] = ITEM_TYPE_HELD_ITEM,
	[ITEM_FLOAT_STONE] = ITEM_TYPE_HELD_ITEM,
	[ITEM_FOCUS_SASH] = ITEM_TYPE_HELD_ITEM,
	[ITEM_GRIP_CLAW] = ITEM_TYPE_HELD_ITEM,
	[ITEM_IRON_BALL] = ITEM_TYPE_HELD_ITEM,
	[ITEM_LAGGING_TAIL] = ITEM_TYPE_HELD_ITEM,
	[ITEM_LUMINOUS_MOSS] = ITEM_TYPE_HELD_ITEM,
	[ITEM_QUICK_POWDER] = ITEM_TYPE_HELD_ITEM,
	[ITEM_METRONOME] = ITEM_TYPE_HELD_ITEM,
	[ITEM_MUSCLE_BAND] = ITEM_TYPE_HELD_ITEM,
	[ITEM_PROTECTIVE_PADS] = ITEM_TYPE_HELD_ITEM,
	[ITEM_RED_CARD] = ITEM_TYPE_HELD_ITEM,
	[ITEM_RING_TARGET] = ITEM_TYPE_HELD_ITEM,
	[ITEM_SHED_SHELL] = ITEM_TYPE_HELD_ITEM,
	[ITEM_SNOWBALL] = ITEM_TYPE_HELD_ITEM,
	[ITEM_STICKY_BARB] = ITEM_TYPE_HELD_ITEM,
	[ITEM_TERRAIN_EXTENDER] = ITEM_TYPE_HELD_ITEM,
	[ITEM_WISE_GLASSES] = ITEM_TYPE_HELD_ITEM,
	[ITEM_ELECTRIC_SEED] = ITEM_TYPE_HELD_ITEM,
	[ITEM_GRASSY_SEED] = ITEM_TYPE_HELD_ITEM,
	[ITEM_MISTY_SEED] = ITEM_TYPE_HELD_ITEM,
	[ITEM_PSYCHIC_SEED] = ITEM_TYPE_HELD_ITEM,
	[ITEM_LIFE_ORB] = ITEM_TYPE_HELD_ITEM,
	[ITEM_TOXIC_ORB] = ITEM_TYPE_HELD_ITEM,
	[ITEM_FLAME_ORB] = ITEM_TYPE_HELD_ITEM,
	[ITEM_BLACK_SLUDGE] = ITEM_TYPE_HELD_ITEM,
	[ITEM_CHOICE_SPECS] = ITEM_TYPE_HELD_ITEM,
	[ITEM_CHOICE_SCARF] = ITEM_TYPE_HELD_ITEM,
	[ITEM_EJECT_PACK] = ITEM_TYPE_HELD_ITEM,
	[ITEM_ROOM_SERVICE] = ITEM_TYPE_HELD_ITEM,
	[ITEM_BLUNDER_POLICY] = ITEM_TYPE_HELD_ITEM,
	[ITEM_HEAVY_DUTY_BOOTS] = ITEM_TYPE_HELD_ITEM,
	[ITEM_UTILITY_UMBRELLA] = ITEM_TYPE_HELD_ITEM,
	[ITEM_THROAT_SPRAY] = ITEM_TYPE_HELD_ITEM,
	[ITEM_FROST_ORB] = ITEM_TYPE_HELD_ITEM,

	[ITEM_FIST_PLATE] = ITEM_TYPE_PLATE,
	[ITEM_SKY_PLATE] = ITEM_TYPE_PLATE,
	[ITEM_TOXIC_PLATE] = ITEM_TYPE_PLATE,
	[ITEM_EARTH_PLATE] = ITEM_TYPE_PLATE,
	[ITEM_STONE_PLATE] = ITEM_TYPE_PLATE,
	[ITEM_INSECT_PLATE] = ITEM_TYPE_PLATE,
	[ITEM_SPOOKY_PLATE] = ITEM_TYPE_PLATE,
	[ITEM_IRON_PLATE] = ITEM_TYPE_PLATE,
	[ITEM_FLAME_PLATE] = ITEM_TYPE_PLATE,
	[ITEM_SPLASH_PLATE] = ITEM_TYPE_PLATE,
	[ITEM_MEADOW_PLATE] = ITEM_TYPE_PLATE,
	[ITEM_ZAP_PLATE] = ITEM_TYPE_PLATE,
	[ITEM_MIND_PLATE] = ITEM_TYPE_PLATE,
	[ITEM_ICICLE_PLATE] = ITEM_TYPE_PLATE,
	[ITEM_DRACO_PLATE] = ITEM_TYPE_PLATE,
	[ITEM_DREAD_PLATE] = ITEM_TYPE_PLATE,
	[ITEM_PIXIE_PLATE] = ITEM_TYPE_PLATE,

	[ITEM_FIGHTING_MEMORY] = ITEM_TYPE_MEMORY,
	[ITEM_FLYING_MEMORY] = ITEM_TYPE_MEMORY,
	[ITEM_POISON_MEMORY] = ITEM_TYPE_MEMORY,
	[ITEM_GROUND_MEMORY] = ITEM_TYPE_MEMORY,
	[ITEM_ROCK_MEMORY] = ITEM_TYPE_MEMORY,
	[ITEM_BUG_MEMORY] = ITEM_TYPE_MEMORY,
	[ITEM_GHOST_MEMORY] = ITEM_TYPE_MEMORY,
	[ITEM_STEEL_MEMORY] = ITEM_TYPE_MEMORY,
	[ITEM_FIRE_MEMORY] = ITEM_TYPE_MEMORY,
	[ITEM_WATER_MEMORY] = ITEM_TYPE_MEMORY,
	[ITEM_GRASS_MEMORY] = ITEM_TYPE_MEMORY,
	[ITEM_ELECTRIC_MEMORY] = ITEM_TYPE_MEMORY,
	[ITEM_PSYCHIC_MEMORY] = ITEM_TYPE_MEMORY,
	[ITEM_ICE_MEMORY] = ITEM_TYPE_MEMORY,
	[ITEM_DRAGON_MEMORY] = ITEM_TYPE_MEMORY,
	[ITEM_DARK_MEMORY] = ITEM_TYPE_MEMORY,
	[ITEM_FAIRY_MEMORY] = ITEM_TYPE_MEMORY,

	[ITEM_BURN_DRIVE] = ITEM_TYPE_DRIVE,
	[ITEM_DOUSE_DRIVE] = ITEM_TYPE_DRIVE,
	[ITEM_SHOCK_DRIVE] = ITEM_TYPE_DRIVE,
	[ITEM_CHILL_DRIVE] = ITEM_TYPE_DRIVE,

	[ITEM_NORMAL_GEM] = ITEM_TYPE_GEM,
	[ITEM_FIGHTING_GEM] = ITEM_TYPE_GEM,
	[ITEM_FLYING_GEM] = ITEM_TYPE_GEM,
	[ITEM_POISON_GEM] = ITEM_TYPE_GEM,
	[ITEM_GROUND_GEM] = ITEM_TYPE_GEM,
	[ITEM_ROCK_GEM] = ITEM_TYPE_GEM,
	[ITEM_BUG_GEM] = ITEM_TYPE_GEM,
	[ITEM_GHOST_GEM] = ITEM_TYPE_GEM,
	[ITEM_STEEL_GEM] = ITEM_TYPE_GEM,
	[ITEM_FIRE_GEM] = ITEM_TYPE_GEM,
	[ITEM_WATER_GEM] = ITEM_TYPE_GEM,
	[ITEM_GRASS_GEM] = ITEM_TYPE_GEM,
	[ITEM_ELECTRIC_GEM] = ITEM_TYPE_GEM,
	[ITEM_PSYCHIC_GEM] = ITEM_TYPE_GEM,
	[ITEM_ICE_GEM] = ITEM_TYPE_GEM,
	[ITEM_DRAGON_GEM] = ITEM_TYPE_GEM,
	[ITEM_DARK_GEM] = ITEM_TYPE_GEM,
	[ITEM_FAIRY_GEM] = ITEM_TYPE_GEM,

	[ITEM_SEA_INCENSE] = ITEM_TYPE_INCENSE,
	[ITEM_LAX_INCENSE] = ITEM_TYPE_INCENSE,
	[ITEM_LUCK_INCENSE] = ITEM_TYPE_INCENSE,
	[ITEM_FULL_INCENSE] = ITEM_TYPE_INCENSE,
	[ITEM_ODD_INCENSE] = ITEM_TYPE_INCENSE,
	[ITEM_PURE_INCENSE] = ITEM_TYPE_INCENSE,
	[ITEM_ROCK_INCENSE] = ITEM_TYPE_INCENSE,
	[ITEM_ROSE_INCENSE] = ITEM_TYPE_INCENSE,
	[ITEM_WAVE_INCENSE] = ITEM_TYPE_INCENSE,

	[ITEM_VENUSAURITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_CHARIZARDITE_X] = ITEM_TYPE_MEGA_STONE,
	[ITEM_CHARIZARDITE_Y] = ITEM_TYPE_MEGA_STONE,
	[ITEM_BLASTOISINITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_BEEDRILLITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_PIDGEOTITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_ALAKAZITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_SLOWBRONITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_GENGARITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_KANGASKHANITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_PINSIRITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_GYARADOSITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_AERODACTYLITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_MEWTWONITE_X] = ITEM_TYPE_MEGA_STONE,
	[ITEM_MEWTWONITE_Y] = ITEM_TYPE_MEGA_STONE,
	[ITEM_AMPHAROSITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_STEELIXITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_SCIZORITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_HERACRONITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_HOUNDOOMINITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_TYRANITARITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_SCEPTILITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_BLAZIKENITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_SWAMPERTITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_GARDEVOIRITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_SABLENITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_MAWILITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_AGGRONITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_MEDICHAMITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_MANECTITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_SHARPEDONITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_CAMERUPTITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_ALTARIANITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_BANETTITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_ABSOLITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_GLALITITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_SALAMENCITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_METAGROSSITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_LATIASITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_LATIOSITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_LOPUNNITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_GARCHOMPITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_LUCARIONITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_ABOMASITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_GALLADITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_AUDINITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_DIANCITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_ULTRANECROZIUM_Z] =  ITEM_TYPE_MEGA_STONE,
	[ITEM_RED_ORB] = ITEM_TYPE_MEGA_STONE,
	[ITEM_BLUE_ORB] = ITEM_TYPE_MEGA_STONE,

	[ITEM_BUTTERFREENITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_MACHAMPITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_KINGLERITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_LAPRASITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_SNORLAXITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_GARBODORITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_MELMETALITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_RILLABOOMITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_CINDERACITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_INTELEITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_CORVISITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_ORBEETLITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_DREDNAWITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_COALOSSITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_APPLITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_SANDACONDITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_TOXTRICITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_CENTISKITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_HATTERENITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_GRIMMSNALITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_ALCREMITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_COPPERANITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_DURALUDONITE] = ITEM_TYPE_MEGA_STONE,
	[ITEM_LUNALIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
	[ITEM_LYCANIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
	[ITEM_MARSHADIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
	[ITEM_MEWNIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
	[ITEM_MIMIKIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
	[ITEM_PIKANIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
	[ITEM_PIKASHUNIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
	[ITEM_PRIMARIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
	[ITEM_SNORLIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
	[ITEM_SOLGANIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
	[ITEM_TAPUNIUM_Z] = ITEM_TYPE_Z_CRYSTAL,

	[ITEM_BLUE_FLUTE] = ITEM_TYPE_FLUTE,
	[ITEM_YELLOW_FLUTE] = ITEM_TYPE_FLUTE,
	[ITEM_RED_FLUTE] = ITEM_TYPE_FLUTE,
	[ITEM_BLACK_FLUTE] = ITEM_TYPE_FLUTE,
	[ITEM_WHITE_FLUTE] = ITEM_TYPE_FLUTE,

	[ITEM_RED_NECTAR] = ITEM_TYPE_NECTAR,
	[ITEM_YELLOW_NECTAR] = ITEM_TYPE_NECTAR,
	[ITEM_PINK_NECTAR] = ITEM_TYPE_NECTAR,
	[ITEM_PURPLE_NECTAR] = ITEM_TYPE_NECTAR,

	[ITEM_HEART_SCALE] = ITEM_TYPE_SELLABLE,
	[ITEM_SHOAL_SALT] = ITEM_TYPE_SELLABLE,
	[ITEM_SHOAL_SHELL] = ITEM_TYPE_SELLABLE,
	[ITEM_TINY_MUSHROOM] = ITEM_TYPE_SELLABLE,
	[ITEM_BIG_MUSHROOM] = ITEM_TYPE_SELLABLE,
	[ITEM_PEARL] = ITEM_TYPE_SELLABLE,
	[ITEM_BIG_PEARL] = ITEM_TYPE_SELLABLE,
	[ITEM_STARDUST] = ITEM_TYPE_SELLABLE,
	[ITEM_STAR_PIECE] = ITEM_TYPE_SELLABLE,
	[ITEM_NUGGET] = ITEM_TYPE_SELLABLE,
	[ITEM_RARE_BONE] = ITEM_TYPE_SELLABLE,
	[ITEM_PEARL_STRING] = ITEM_TYPE_SELLABLE,
	[ITEM_BIG_NUGGET] = ITEM_TYPE_SELLABLE,
	[ITEM_COMET_SHARD] = ITEM_TYPE_SELLABLE,
	[ITEM_BALM_MUSHROOM] = ITEM_TYPE_SELLABLE,
	[ITEM_ODD_KEYSTONE] = ITEM_TYPE_SELLABLE,
	[ITEM_BOTTLE_CAP] = ITEM_TYPE_SELLABLE,
	[ITEM_GOLD_BOTTLE_CAP] = ITEM_TYPE_SELLABLE,
	[ITEM_WISHING_PIECE] = ITEM_TYPE_SELLABLE,
	[ITEM_BLACK_APRICORN] = ITEM_TYPE_SELLABLE,
	[ITEM_BLUE_APRICORN] = ITEM_TYPE_SELLABLE,
	[ITEM_GREEN_APRICORN] = ITEM_TYPE_SELLABLE,
	[ITEM_PINK_APRICORN] = ITEM_TYPE_SELLABLE,
	[ITEM_RED_APRICORN] = ITEM_TYPE_SELLABLE,
	[ITEM_WHITE_APRICORN] = ITEM_TYPE_SELLABLE,
	[ITEM_YELLOW_APRICORN] = ITEM_TYPE_SELLABLE,
	[ITEM_RELIC_COPPER] = ITEM_TYPE_RELIC,
	[ITEM_RELIC_SILVER] = ITEM_TYPE_RELIC,
	[ITEM_RELIC_GOLD] = ITEM_TYPE_RELIC,
	[ITEM_RELIC_VASE] = ITEM_TYPE_RELIC,
	[ITEM_RELIC_BAND] = ITEM_TYPE_RELIC,
	[ITEM_RELIC_STATUE] = ITEM_TYPE_RELIC,
	[ITEM_RELIC_CROWN] = ITEM_TYPE_RELIC,

	[ITEM_RED_SHARD] = ITEM_TYPE_SHARD,
	[ITEM_BLUE_SHARD] = ITEM_TYPE_SHARD,
	[ITEM_YELLOW_SHARD] = ITEM_TYPE_SHARD,
	[ITEM_GREEN_SHARD] = ITEM_TYPE_SHARD,

	[ITEM_HELIX_FOSSIL] = ITEM_TYPE_FOSSIL,
	[ITEM_DOME_FOSSIL] = ITEM_TYPE_FOSSIL,
	[ITEM_OLD_AMBER] = ITEM_TYPE_FOSSIL,
	[ITEM_ROOT_FOSSIL] = ITEM_TYPE_FOSSIL,
	[ITEM_CLAW_FOSSIL] = ITEM_TYPE_FOSSIL,
	[ITEM_SKULL_FOSSIL] = ITEM_TYPE_FOSSIL,
	[ITEM_ARMOR_FOSSIL] = ITEM_TYPE_FOSSIL,
	[ITEM_COVER_FOSSIL] = ITEM_TYPE_FOSSIL,
	[ITEM_PLUME_FOSSIL] = ITEM_TYPE_FOSSIL,
	[ITEM_JAW_FOSSIL] = ITEM_TYPE_FOSSIL,
	[ITEM_SAIL_FOSSIL] = ITEM_TYPE_FOSSIL,
	[ITEM_FOSSILIZED_BIRD] = ITEM_TYPE_FOSSIL,
	[ITEM_FOSSILIZED_FISH] = ITEM_TYPE_FOSSIL,
	[ITEM_FOSSILIZED_DRAKE] = ITEM_TYPE_FOSSIL,
	[ITEM_FOSSILIZED_DINO] = ITEM_TYPE_FOSSIL,
	[ITEM_ORANGE_MAIL] = ITEM_TYPE_MAIL,
	[ITEM_HARBOR_MAIL] = ITEM_TYPE_MAIL,
	[ITEM_GLITTER_MAIL] = ITEM_TYPE_MAIL,
	[ITEM_MECH_MAIL] = ITEM_TYPE_MAIL,
	[ITEM_WOOD_MAIL] = ITEM_TYPE_MAIL,
	[ITEM_WAVE_MAIL] = ITEM_TYPE_MAIL,
	[ITEM_BEAD_MAIL] = ITEM_TYPE_MAIL,
	[ITEM_SHADOW_MAIL] = ITEM_TYPE_MAIL,
	[ITEM_TROPIC_MAIL] = ITEM_TYPE_MAIL,
	[ITEM_DREAM_MAIL] = ITEM_TYPE_MAIL,
	[ITEM_FAB_MAIL] = ITEM_TYPE_MAIL,
	[ITEM_RETRO_MAIL] = ITEM_TYPE_MAIL,

#ifdef UNBOUND
	[ITEM_ODDISH_LEAF] = ITEM_TYPE_STAT_BOOST_DRINK,
#endif
};

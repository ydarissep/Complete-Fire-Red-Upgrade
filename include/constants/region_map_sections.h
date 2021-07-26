#pragma once

#define MAPSEC_DYNAMIC                      0x57

u8 __attribute__((long_call)) GetCurrentRegionMapSectionId(void);

#ifndef UNBOUND //Modify this section
#define MAPSEC_PALLET_TOWN                  0x58
#define MAPSEC_VIRIDIAN_CITY                0x59
#define MAPSEC_PEWTER_CITY                  0x5A
#define MAPSEC_CERULEAN_CITY                0x5B
#define MAPSEC_LAVENDER_TOWN                0x5C
#define MAPSEC_VERMILION_CITY               0x5D
#define MAPSEC_CELADON_CITY                 0x5E
#define MAPSEC_FUCHSIA_CITY                 0x5F
#define MAPSEC_CINNABAR_ISLAND              0x60
#define MAPSEC_INDIGO_PLATEAU               0x61
#define MAPSEC_SAFFRON_CITY                 0x62
#define MAPSEC_ROUTE_4_FLYDUP               0x63
#define MAPSEC_ROUTE_10_FLYDUP              0x64
#define MAPSEC_ROUTE_1                      0x65
#define MAPSEC_ROUTE_2                      0x66
#define MAPSEC_ROUTE_3                      0x67
#define MAPSEC_ROUTE_4                      0x68
#define MAPSEC_ROUTE_5                      0x69
#define MAPSEC_ROUTE_6                      0x6A
#define MAPSEC_ROUTE_7                      0x6B
#define MAPSEC_ROUTE_8                      0x6C
#define MAPSEC_ROUTE_9                      0x6D
#define MAPSEC_ROUTE_10                     0x6E
#define MAPSEC_ROUTE_11                     0x6F
#define MAPSEC_ROUTE_12                     0x70
#define MAPSEC_ROUTE_13                     0x71
#define MAPSEC_ROUTE_14                     0x72
#define MAPSEC_ROUTE_15                     0x73
#define MAPSEC_ROUTE_16                     0x74
#define MAPSEC_ROUTE_17                     0x75
#define MAPSEC_ROUTE_18                     0x76
#define MAPSEC_ROUTE_19                     0x77
#define MAPSEC_ROUTE_20                     0x78
#define MAPSEC_ROUTE_21                     0x79
#define MAPSEC_ROUTE_22                     0x7A
#define MAPSEC_ROUTE_23                     0x7B
#define MAPSEC_ROUTE_24                     0x7C
#define MAPSEC_ROUTE_25                     0x7D
#define MAPSEC_VIRIDIAN_FOREST              0x7E
#define MAPSEC_MT_MOON                      0x7F
#define MAPSEC_S_S_ANNE                     0x80
#define MAPSEC_UNDERGROUND_PATH             0x81
#define MAPSEC_UNDERGROUND_PATH_2           0x82
#define MAPSEC_DIGLETTS_CAVE                0x83
#define MAPSEC_KANTO_VICTORY_ROAD           0x84
#define MAPSEC_ROCKET_HIDEOUT               0x85
#define MAPSEC_SILPH_CO                     0x86
#define MAPSEC_POKEMON_MANSION              0x87
#define MAPSEC_KANTO_SAFARI_ZONE            0x88
#define MAPSEC_POKEMON_LEAGUE               0x89
#define MAPSEC_ROCK_TUNNEL                  0x8A
#define MAPSEC_SEAFOAM_ISLANDS              0x8B
#define MAPSEC_POKEMON_TOWER                0x8C
#define MAPSEC_CERULEAN_CAVE                0x8D
#define MAPSEC_POWER_PLANT                  0x8E
#define MAPSEC_ONE_ISLAND                   0x8F
#define MAPSEC_TWO_ISLAND                   0x90
#define MAPSEC_THREE_ISLAND                 0x91
#define MAPSEC_FOUR_ISLAND                  0x92
#define MAPSEC_FIVE_ISLAND                  0x93
#define MAPSEC_SEVEN_ISLAND                 0x94
#define MAPSEC_SIX_ISLAND                   0x95
#define MAPSEC_KINDLE_ROAD                  0x96
#define MAPSEC_TREASURE_BEACH               0x97
#define MAPSEC_CAPE_BRINK                   0x98
#define MAPSEC_BOND_BRIDGE                  0x99
#define MAPSEC_THREE_ISLE_PORT              0x9A
#define MAPSEC_SEVII_ISLE_6                 0x9B
#define MAPSEC_SEVII_ISLE_7                 0x9C
#define MAPSEC_SEVII_ISLE_8                 0x9D
#define MAPSEC_SEVII_ISLE_9                 0x9E
#define MAPSEC_RESORT_GORGEOUS              0x9F
#define MAPSEC_WATER_LABYRINTH              0xA0
#define MAPSEC_FIVE_ISLE_MEADOW             0xA1
#define MAPSEC_MEMORIAL_PILLAR              0xA2
#define MAPSEC_OUTCAST_ISLAND               0xA3
#define MAPSEC_GREEN_PATH                   0xA4
#define MAPSEC_WATER_PATH                   0xA5
#define MAPSEC_RUIN_VALLEY                  0xA6
#define MAPSEC_TRAINER_TOWER                0xA7
#define MAPSEC_CANYON_ENTRANCE              0xA8
#define MAPSEC_SEVAULT_CANYON               0xA9
#define MAPSEC_TANOBY_RUINS                 0xAA
#define MAPSEC_SEVII_ISLE_22                0xAB
#define MAPSEC_SEVII_ISLE_23                0xAC
#define MAPSEC_SEVII_ISLE_24                0xAD
#define MAPSEC_NAVEL_ROCK                   0xAE
#define MAPSEC_MT_EMBER                     0xAF
#define MAPSEC_BERRY_FOREST                 0xB0
#define MAPSEC_ICEFALL_CAVE                 0xB1
#define MAPSEC_ROCKET_WAREHOUSE             0xB2
#define MAPSEC_TRAINER_TOWER_2              0xB3
#define MAPSEC_DOTTED_HOLE                  0xB4
#define MAPSEC_LOST_CAVE                    0xB5
#define MAPSEC_PATTERN_BUSH                 0xB6
#define MAPSEC_ALTERING_CAVE                0xB7
#define MAPSEC_TANOBY_CHAMBERS              0xB8
#define MAPSEC_THREE_ISLE_PATH              0xB9
#define MAPSEC_TANOBY_KEY                   0xBA
#define MAPSEC_BIRTH_ISLAND                 0xBB
#define MAPSEC_MONEAN_CHAMBER               0xBC
#define MAPSEC_LIPTOO_CHAMBER               0xBD
#define MAPSEC_WEEPTH_CHAMBER               0xBE
#define MAPSEC_DILFORD_CHAMBER              0xBF
#define MAPSEC_SCUFIB_CHAMBER               0xC0
#define MAPSEC_RIXY_CHAMBER                 0xC1
#define MAPSEC_VIAPOIS_CHAMBER              0xC2
#define MAPSEC_EMBER_SPA                    0xC3
#endif

#define MAPSEC_CELADON_DEPT                 0xC4
#define MAPSEC_NONE                         0xC5

#define METLOC_SPECIAL_EGG                  0xFD
#define METLOC_IN_GAME_TRADE                0xFE
#define METLOC_FATEFUL_ENCOUNTER            0xFF

#define KANTO_MAPSEC_COUNT (MAPSEC_CELADON_DEPT - MAPSEC_DYNAMIC)

#ifdef UNBOUND //For Pokemon Unbound

#define MAPSEC_SHADOW_BASE					0x85
#define MAPSEC_FROZEN_HEIGHTS				0x58
#define MAPSEC_ROUTE_1 						0x65
#define	MAPSEC_BELLIN_TOWN					0x59
#define MAPSEC_ICICLE_CAVE					0x8D
#define MAPSEC_ICY_HOLE						0x9D
#define MAPSEC_ROUTE_2 						0x66
#define MAPSEC_DRESCO_TOWN					0x5A
#define MAPSEC_ROUTE_3						0x67
#define MAPSEC_FLOWER_PARADISE 				0x88
#define MAPSEC_GRIM_WOODS 					0x7E
#define MAPSEC_ROUTE_4 						0x63
#define MAPSEC_CINDER_VOLCANO 				0x7F
#define MAPSEC_ROUTE_5 						0x69
#define MAPSEC_POKEMON_DAY_CARE				0x9B
#define MAPSEC_CRATER_TOWN					0x5B
#define MAPSEC_KBT_EXPRESSWAY				0x86
#define MAPSEC_VALLEY_CAVE 					0x83
#define MAPSEC_ROUTE_6 						0x6A
#define MAPSEC_ROUTE_7 						0x6B
#define MAPSEC_ROUTE_8 						0x6C
#define MAPSEC_FROST_MOUNTAIN				0x82
#define MAPSEC_BLIZZARD_CITY				0x5C
#define MAPSEC_FROZEN_FOREST				0x99
#define MAPSEC_FROZEN_TOMB					0xC2
#define MAPSEC_ROUTE_9						0x6D
#define MAPSEC_TEHL_TOWN					0x5D
#define MAPSEC_UNDERGROUND_PASS				0x81
#define MAPSEC_ROUTE_10						0x64
#define MAPSEC_CAVE_OF_BEING				0x9A
#define MAPSEC_AUBURN_WATERWAY	            0x8E
#define MAPSEC_LOST_TUNNEL					0x9C
#define MAPSEC_FALLSHORE_CITY				0x5E
#define MAPSEC_ROUTE_11						0x6F
#define MAPSEC_EPIDIMY_TOWN					0x5F
#define MAPSEC_THUNDERCAP_MOUNTAIN			0x8A
#define MAPSEC_TARMIGAN_TOWN				0x60
#define MAPSEC_TARMIGAN_MANSION				0x87
#define MAPSEC_FULLMOON_ISLAND				0xA3
#define MAPSEC_NEWMOON_ISLAND				0x98
#define MAPSEC_ROUTE_12						0x70
#define MAPSEC_DEHARA_CITY					0x62
#define MAPSEC_DEHARA_DEPT					0xC4
#define MAPSEC_RIFT_CAVE					0x8B
#define MAPSEC_RUINS_OF_VOID				0x68
#define MAPSEC_CUBE_SPACE					0x7D
#define MAPSEC_ROUTE_13						0x71
#define MAPSEC_ROUTE_14						0x72
#define MAPSEC_GREAT_DESERT					0x7B
#define MAPSEC_TOMB_OF_BORRIUS				0xC0
#define MAPSEC_DESERT_RUINS                 0xC1
#define MAPSEC_GURUN_TOWN					0x7A
#define MAPSEC_VIVILL_WOODS					0x8C
#define MAPSEC_VIVILL_TOWN					0x79
#define MAPSEC_VIVILL_WAREHOUSE				0x7C
#define MAPSEC_DISTORTION_WORLD				0x97
#define MAPSEC_ROUTE_15						0x73
#define MAPSEC_ROUTE_16						0x74
#define MAPSEC_ANTISIS_CITY					0x78
#define MAPSEC_ANTISIS_SEWERS				0x8F
#define MAPSEC_ROUTE_17						0x75
#define MAPSEC_SEAPORT_CITY					0x77
#define MAPSEC_SS_MARINE					0xBE
#define MAPSEC_BATTLE_FRONTIER	            0xA7
#define MAPSEC_BATTLE_TOWER					0xB3
#define MAPSEC_BATTLE_MINE					0xB2
#define MAPSEC_BATTLE_CIRCUS				0xB4
#define MAPSEC_POLDER_TOWN					0x90
#define MAPSEC_SAFARI_ZONE					0xA4
#define MAPSEC_COOTES_BOG					0xB5
#define MAPSEC_CRYSTAL_PEAK					0x9E
#define MAPSEC_MAGNOLIA_TOWN				0x91
#define MAPSEC_MAGNOLIA_FIELDS				0xB6
#define MAPSEC_REDWOOD_VILLAGE				0x92
#define MAPSEC_ROUTE_18                     0x76
#define MAPSEC_ISLAND_CAVE					0xC3
#define MAPSEC_VICTORY_ROAD                 0x84
#define MAPSEC_POKEMON_LEAGUE               0x89
#define MAPSEC_REDWOOD_FOREST               0xB7
#define MAPSEC_UNDERWATER					0xBD

#define MAPSEC_HIDDEN_GROTTO				0x80
#endif

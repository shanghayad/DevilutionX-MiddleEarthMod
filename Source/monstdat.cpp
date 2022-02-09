/**
 * @file monstdat.cpp
 *
 * Implementation of all monster data.
 */
#include "monstdat.h"
#include "items.h"

#include "monster.h"
#include "textdat.h"
#include "utils/language.h"

namespace devilution {

/** Contains the data related to each monster ID. */
const MonsterData MonstersData[] = {
	// clang-format off
	//               mName,                                  GraphicType,                        sndfile,                            TransFile,                         width, mImage, has_special, snd_special, has_trans, Frames[6],                  Rate[6],               mMinDLvl, mMaxDLvl, mLevel, mMinHP, mMaxHP, mAi,          mFlags                                                             , mInt, mHit, mAFNum, mMinDamage, mMaxDamage, mHit2, mAFNum2, mMinDamage2, mMaxDamage2, mArmorClass, mMonstClass         ,   mMagicRes                                                       , mMagicRes2                                                        , mSelFlag,     mTreasure,          mExp
	// TRANSLATORS: Monster Block start
{P_("monster", "Zombie"), "Monsters\Zombie\Zombie%c.CL2", "Monsters\Zombie\Zombie%c%i.WAV", nullptr, 128, 899, false, false, false, {11, 24, 12, 6, 16, 8}, {0, 0, 0, 0, 0, 0}, 0, 4, 1, 4, 7, AI_ZOMBIE, , 0, 0, 8, 2, 5, 0, 0, 0, 0, 5, MonsterClass::Undead, IMMUNE_MAGIC , IMMUNE_MAGIC , 0, 3, 54},
{P_("monster", "Ghoul"), "Monsters\Zombie\Zombie%c.CL2", "Monsters\Zombie\Zombie%c%i.WAV", "Monsters\Zombie\Bluered.TRN", 128, 799, false, false, true, {11, 24, 12, 6, 16, 0}, {0, 0, 0, 0, 0, 0}, 2, 4, 2, 7, 11, AI_ZOMBIE, , 1, 0, 8, 3, 10, 0, 0, 0, 0, 10, MonsterClass::Undead, IMMUNE_MAGIC | IMMUNE_NULL_40 , IMMUNE_MAGIC | IMMUNE_NULL_40 , 0, 3, 58},
{P_("monster", "Corpse"), "Monsters\Zombie\Zombie%c.CL2", "Monsters\Zombie\Zombie%c%i.WAV", "Monsters\Zombie\Grey.TRN", 128, 799, false, false, true, {11, 24, 12, 6, 16, 0}, {0, 0, 0, 0, 0, 0}, 2, 6, 4, 15, 25, AI_ZOMBIE, , 2, 5, 8, 5, 15, 0, 0, 0, 0, 15, MonsterClass::Undead, IMMUNE_MAGIC | IMMUNE_NULL_40 , RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_NULL_40 , 0, 3, 136},
{P_("monster", "Huge Spider"), "Monsters\spider\spider%c.CL2", "Monsters\worm\worm%c%i.wav", nullptr, 148, 1386, false, false, false, {12, 10, 15, 6, 20, 15}, {1, 0, 0, 0, 0, 0}, 16, 18, 18, 70, 100, AI_SKELSD, MFLAG_NOLIFESTEAL , 0, 70, 8, 10, 20, 0, 0, 0, 0, 50, MonsterClass::Animal, RESIST_LIGHTNING , IMMUNE_LIGHTNING , 0, 7, 1750},
{P_("monster", "Orcling"), "Monsters\FalSpear\Phall%c.CL2", "Monsters\FalSpear\Phall%c%i.WAV", "Monsters\Magma\Yellow.TRN", 128, 799, true, true, true, {11, 11, 13, 11, 18, 13}, {3, 0, 0, 0, 0, 0}, 0, 4, 1, 1, 4, AI_FALLEN, , 0, 0, 7, 1, 3, 0, 5, 0, 0, 0, MonsterClass::Animal, 0, 0, 0, 3, 46},
{P_("monster", "Lesser Orc"), "Monsters\FalSpear\Phall%c.CL2", "Monsters\FalSpear\Phall%c%i.WAV", "Monsters\Scav\ScavBr.TRN", 128, 799, true, true, true, {11, 11, 13, 11, 18, 13}, {3, 0, 0, 0, 0, 0}, 2, 6, 3, 4, 8, AI_FALLEN, , 2, 5, 7, 2, 5, 0, 5, 0, 0, 5, MonsterClass::Animal, 0, 0, 0, 3, 80},
{P_("monster", "allen Istar"), "Monsters\Mage\Mage%c.CL2", "Monsters\DarkMage\Dmag%c%i.WAV", "Monsters\Mega\Guard.TRN", 128, 1, true, false, true, {12, 1, 1, 6, 28, 20}, {0, 0, 0, 0, 0, 0}, 85, 85, 30, 1500, 1500, AI_COUNSLR, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 130, 1, 60, 60, 0, 0, 0, 0, 130, MonsterClass::Demon, IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_LIGHTNING , IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_LIGHTNING , 0, 7, 8000},
{P_("monster", "Uruk-Hai"), "Monsters\FalSpear\Phall%c.CL2", "Monsters\BigFall\Bfal%c%i.WAV", "Monsters\Snake\SnakR.TRN", 128, 799, true, true, true, {11, 11, 13, 11, 18, 13}, {3, 0, 0, 0, 0, 0}, 6, 10, 7, 20, 36, AI_SKELSD, , 3, 10, 7, 4, 8, 0, 5, 0, 0, 15, MonsterClass::Animal, IMMUNE_NULL_40 , RESIST_LIGHTNING | IMMUNE_NULL_40 , 0, 3, 255},
{P_("monster", "Skeleton"), "Monsters\SkelAxe\SklAx%c.CL2", "Monsters\SkelAxe\SklAx%c%i.WAV", "Monsters\Monsters\BLKJD.TRN", 128, 553, true, false, true, {12, 8, 13, 6, 17, 16}, {0, 0, 0, 0, 0, 0}, 1, 3, 1, 2, 4, AI_SKELSD, , 0, 0, 8, 1, 4, 0, 0, 0, 0, 0, MonsterClass::Undead, IMMUNE_MAGIC | IMMUNE_NULL_40 , IMMUNE_MAGIC | IMMUNE_NULL_40 , 0, 3, 64},
{P_("monster", "Cursed Guard"), "Monsters\SkelAxe\SklAx%c.CL2", "Monsters\SkelAxe\SklAx%c%i.WAV", "Monsters\Mage\Cnselgd.TRN", 128, 553, true, false, true, {12, 8, 13, 6, 17, 16}, {0, 0, 0, 0, 0, 0}, 2, 5, 2, 4, 7, AI_SKELSD, , 1, 5, 8, 3, 5, 0, 0, 0, 0, 0, MonsterClass::Undead, IMMUNE_MAGIC | IMMUNE_NULL_40 , IMMUNE_MAGIC | IMMUNE_NULL_40 , 0, 3, 68},
{P_("monster", "Lost Soul"), "Monsters\SkelAxe\SklAx%c.CL2", "Monsters\SkelAxe\SklAx%c%i.WAV", "Monsters\Scav\ScavBr.TRN", 128, 553, true, false, true, {12, 8, 13, 6, 17, 16}, {0, 0, 0, 0, 0, 0}, 2, 6, 4, 8, 12, AI_SKELSD, , 2, 10, 8, 3, 7, 0, 0, 0, 0, 5, MonsterClass::Undead, RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_NULL_40 , IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_NULL_40 , 0, 3, 154},
{P_("monster", "The Damned"), "Monsters\SkelAxe\SklAx%c.CL2", "Monsters\SkelAxe\SklAx%c%i.WAV", "Monsters\Acid\AcidB.TRN", 128, 553, true, false, true, {12, 8, 13, 6, 17, 16}, {0, 0, 0, 0, 0, 0}, 4, 8, 6, 12, 20, AI_SKELSD, , 3, 15, 8, 4, 9, 0, 0, 0, 0, 15, MonsterClass::Undead, RESIST_LIGHTNING | IMMUNE_MAGIC | IMMUNE_NULL_40 , RESIST_LIGHTNING | IMMUNE_MAGIC | IMMUNE_NULL_40 , 0, 3, 264},
{P_("monster", "Orcling"), "Monsters\FalSword\Fall%c.CL2", "Monsters\FalSword\Fall%c%i.WAV", "Monsters\Magma\Yellow.TRN", 128, 879, true, true, true, {12, 12, 13, 11, 14, 15}, {3, 0, 0, 0, 0, 0}, 0, 4, 1, 2, 5, AI_FALLEN, , 0, 0, 8, 1, 4, 0, 5, 0, 0, 10, MonsterClass::Animal, 0, 0, 0, 3, 52},
{P_("monster", "Lesser Orc"), "Monsters\FalSword\Fall%c.CL2", "Monsters\FalSword\Fall%c%i.WAV", "Monsters\Scav\ScavBr.TRN", 128, 879, true, true, true, {12, 12, 13, 11, 14, 15}, {3, 0, 0, 0, 0, 0}, 4, 8, 5, 12, 24, AI_FALLEN, , 1, 5, 8, 3, 7, 0, 5, 0, 0, 15, MonsterClass::Animal, 0, 0, 0, 3, 155},
{P_("monster", "Orc"), "Monsters\FalSword\Fall%c.CL2", "Monsters\FalSword\Fall%c%i.WAV", "Monsters\Mega\Vtexl.TRN", 128, 879, true, true, true, {12, 12, 13, 11, 14, 15}, {3, 0, 0, 0, 0, 0}, 6, 10, 9, 16, 30, AI_FALLEN, , 2, 15, 8, 4, 10, 0, 5, 0, 0, 20, MonsterClass::Animal, 0, RESIST_FIRE , 0, 3, 352},
{P_("monster", "Uruk-Hai"), "Monsters\FalSword\Fall%c.CL2", "Monsters\BigFall\Bfal%c%i.WAV", "Monsters\Snake\SnakR.TRN", 128, 879, true, true, true, {12, 12, 13, 11, 14, 15}, {3, 0, 0, 0, 0, 0}, 10, 14, 12, 40, 50, AI_SKELSD, , 3, 35, 8, 6, 14, 0, 5, 0, 0, 40, MonsterClass::Animal, IMMUNE_NULL_40 , RESIST_LIGHTNING | IMMUNE_NULL_40 , 0, 3, 850},
{P_("monster", "Wolf"), "Monsters\Acid\Acid%c.CL2", "Monsters\Wolf\Wolf%c%i.wav", "Monsters\Scav\ScavW.TRN", 128, 1000, true, false, true, {13, 8, 12, 8, 16, 12}, {0, 0, 0, 0, 0, 0}, 10, 14, 11, 50, 66, AI_SNAKE, MFLAG_CAN_OPEN_DOOR , 0, 50, 8, 8, 15, 0, 0, 0, 0, 40, MonsterClass::Animal, IMMUNE_NULL_40 , IMMUNE_MAGIC | IMMUNE_NULL_40 , 0, 3, 846},
{P_("monster", "Dire Wolf"), "Monsters\Acid\Acid%c.CL2", "Monsters\Wolf\Wolf%c%i.wav", "Monsters\Scav\ScavBr.TRN", 128, 1256, true, false, true, {13, 8, 12, 8, 16, 12}, {0, 0, 0, 0, 0, 0}, 14, 18, 15, 60, 80, AI_SNAKE, MFLAG_CAN_OPEN_DOOR , 1, 65, 8, 10, 20, 0, 0, 0, 0, 55, MonsterClass::Animal, RESIST_MAGIC | RESIST_FIRE | RESIST_LIGHTNING , RESIST_FIRE | RESIST_LIGHTNING | IMMUNE_MAGIC , 0, 3, 1248},
{P_("monster", "Dread Wolf"), "Monsters\Acid\Acid%c.CL2", "Monsters\Wolf\Wolf%c%i.wav", "Monsters\Monsters\bhka.trn", 128, 1256, true, false, true, {13, 8, 12, 8, 16, 12}, {0, 0, 0, 0, 0, 0}, 18, 20, 21, 80, 120, AI_SNAKE, MFLAG_CAN_OPEN_DOOR , 2, 80, 8, 12, 22, 0, 0, 0, 0, 60, MonsterClass::Animal, RESIST_MAGIC | IMMUNE_FIRE , RESIST_MAGIC | IMMUNE_FIRE , 0, 3, 2714},
{P_("monster", "Warg"), "Monsters\Acid\Acid%c.CL2", "Monsters\Wolf\Wolf%c%i.wav", "Monsters\Rhino\RhinoB.TRN", 128, 1512, true, false, true, {13, 6, 11, 6, 16, 12}, {0, 0, 0, 0, 0, 0}, 20, 24, 25, 120, 180, AI_SNAKE, MFLAG_CAN_OPEN_DOOR , 3, 110, 8, 15, 25, 0, 0, 0, 0, 70, MonsterClass::Animal, RESIST_MAGIC | IMMUNE_FIRE | IMMUNE_NULL_40 , IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_NULL_40 , 0, 3, 2940},
{P_("monster", "Skeleton"), "Monsters\SkelBow\SklBw%c.CL2", "Monsters\SkelBow\SklBw%c%i.WAV", "Monsters\Monsters\BLKJD.TRN", 128, 567, true, false, true, {9, 8, 16, 5, 16, 16}, {0, 0, 0, 0, 0, 0}, 2, 5, 3, 2, 4, AI_SKELBOW, , 0, 0, 12, 1, 2, 0, 0, 0, 0, 0, MonsterClass::Undead, IMMUNE_MAGIC | IMMUNE_NULL_40 , IMMUNE_MAGIC | IMMUNE_NULL_40 , 0, 3, 110},
{P_("monster", "Cursed Bow"), "Monsters\SkelBow\SklBw%c.CL2", "Monsters\SkelBow\SklBw%c%i.WAV", "Monsters\Mage\Cnselgd.TRN", 128, 567, true, false, true, {9, 8, 16, 5, 16, 16}, {0, 0, 0, 0, 0, 0}, 3, 7, 5, 8, 16, AI_SKELBOW, , 1, 5, 12, 1, 4, 0, 0, 0, 0, 0, MonsterClass::Undead, IMMUNE_MAGIC | IMMUNE_NULL_40 , IMMUNE_MAGIC | IMMUNE_NULL_40 , 0, 3, 210},
{P_("monster", "Lost Soul"), "Monsters\SkelBow\SklBw%c.CL2", "Monsters\SkelBow\SklBw%c%i.WAV", "Monsters\Scav\ScavBr.TRN", 128, 567, true, false, true, {9, 8, 16, 5, 16, 16}, {0, 0, 0, 0, 0, 0}, 5, 9, 7, 10, 24, AI_SKELBOW, , 2, 10, 12, 1, 6, 0, 0, 0, 0, 5, MonsterClass::Undead, RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_NULL_40 , IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_NULL_40 , 0, 3, 364},
{P_("monster", "The Damned"), "Monsters\SkelBow\SklBw%c.CL2", "Monsters\SkelBow\SklBw%c%i.WAV", "Monsters\Acid\AcidB.TRN", 128, 567, true, false, true, {9, 8, 16, 5, 16, 16}, {0, 0, 0, 0, 0, 0}, 7, 11, 9, 15, 45, AI_SKELBOW, , 3, 15, 12, 2, 9, 0, 0, 0, 0, 15, MonsterClass::Undead, RESIST_LIGHTNING | IMMUNE_MAGIC | IMMUNE_NULL_40 , RESIST_LIGHTNING | IMMUNE_MAGIC | IMMUNE_NULL_40 , 0, 3, 594},
{P_("monster", "Skeleton Lord"), "Monsters\SkelSd\SklSr%c.CL2", "Monsters\SkelSd\SklSr%c%i.WAV", "Monsters\Monsters\BLKJD.TRN", 128, 575, true, true, true, {13, 8, 12, 7, 15, 16}, {0, 0, 0, 0, 0, 0}, 1, 4, 2, 3, 6, AI_SKELSD, , 0, 0, 8, 2, 7, 0, 0, 0, 0, 10, MonsterClass::Undead, IMMUNE_MAGIC | IMMUNE_NULL_40 , IMMUNE_MAGIC | IMMUNE_NULL_40 , 0, 3, 90},
{P_("monster", "Cursed Lord"), "Monsters\SkelSd\SklSr%c.CL2", "Monsters\SkelSd\SklSr%c%i.WAV", "Monsters\Mage\Cnselgd.TRN", 128, 575, true, false, true, {13, 8, 12, 7, 15, 16}, {0, 0, 0, 0, 0, 0}, 2, 6, 4, 12, 20, AI_SKELSD, , 1, 10, 8, 3, 9, 0, 0, 0, 0, 5, MonsterClass::Undead, IMMUNE_MAGIC | IMMUNE_NULL_40 , IMMUNE_MAGIC | IMMUNE_NULL_40 , 0, 3, 200},
{P_("monster", "Lost Soul"), "Monsters\SkelSd\SklSr%c.CL2", "Monsters\SkelSd\SklSr%c%i.WAV", "Monsters\Scav\ScavBr.TRN", 128, 575, true, false, true, {13, 8, 12, 7, 15, 16}, {0, 0, 0, 0, 0, 0}, 4, 8, 6, 16, 30, AI_SKELSD, , 2, 15, 8, 4, 10, 0, 0, 0, 0, 15, MonsterClass::Undead, RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_NULL_40 , IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_NULL_40 , 0, 3, 393},
{P_("monster", "The Damned"), "Monsters\SkelSd\SklSr%c.CL2", "Monsters\SkelSd\SklSr%c%i.WAV", "Monsters\Acid\AcidB.TRN", 128, 575, true, false, true, {13, 8, 12, 7, 15, 16}, {0, 0, 0, 0, 0, 0}, 6, 10, 8, 35, 50, AI_SKELSD, MFLAG_SEARCH , 3, 20, 8, 5, 14, 0, 0, 0, 0, 30, MonsterClass::Undead, RESIST_LIGHTNING | IMMUNE_MAGIC | IMMUNE_NULL_40 , RESIST_LIGHTNING | IMMUNE_MAGIC | IMMUNE_NULL_40 , 0, 3, 604},
{P_("monster", "Warlock"), "Monsters\Mage\Mage%c.CL2", "Monsters\Mage\Mage%c%i.WAV", "Monsters\Mega\Balr.TRN", 128, 1204, true, false, true, {12, 1, 20, 8, 28, 20}, {0, 0, 0, 0, 0, 0}, 26, 30, 30, 145, 145, AI_COUNSLR, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 110, 8, 15, 25, 0, 0, 0, 0, 0, MonsterClass::Demon, RESIST_MAGIC | RESIST_FIRE | IMMUNE_LIGHTNING , RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_LIGHTNING , 0, 7, 4968},
{P_("monster", "Hidden"), "Monsters\Sneak\Sneak%c.CL2", "Monsters\Sneak\Sneak%c%i.WAV", nullptr, 128, 992, true, false, false, {16, 8, 12, 8, 24, 15}, {2, 0, 0, 0, 0, 0}, 3, 8, 5, 8, 24, AI_SNEAK, MFLAG_HIDDEN , 0, 15, 8, 3, 6, 0, 0, 0, 0, 25, MonsterClass::Demon, 0, IMMUNE_NULL_40 , 0, 3, 278},
{P_("monster", "Giant Spider"), "Monsters\spider\spider%c.CL2", "Monsters\worm\worm%c%i.wav", "Monsters\Gargoyle\GargB.TRN", 148, 1386, false, false, true, {12, 10, 15, 6, 20, 15}, {1, 0, 0, 0, 0, 0}, 20, 22, 22, 130, 150, AI_SKELSD, MFLAG_NOLIFESTEAL , 1, 95, 8, 15, 22, 0, 0, 0, 0, 70, MonsterClass::Animal, RESIST_MAGIC | RESIST_LIGHTNING , IMMUNE_MAGIC | IMMUNE_LIGHTNING , 0, 7, 2775},
{P_("monster", "Unseen"), "Monsters\Sneak\Sneak%c.CL2", "Monsters\Sneak\Sneak%c%i.WAV", "Monsters\Sneak\Sneakv3.TRN", 128, 992, true, false, true, {16, 8, 12, 8, 24, 15}, {2, 0, 0, 0, 0, 0}, 10, 14, 11, 35, 50, AI_SNEAK, MFLAG_HIDDEN | MFLAG_SEARCH , 2, 25, 8, 12, 20, 0, 0, 0, 0, 30, MonsterClass::Demon, RESIST_MAGIC | IMMUNE_NULL_40 , IMMUNE_MAGIC | IMMUNE_NULL_40 , 0, 3, 935},
{P_("monster", "Illusion Weaver"), "Monsters\Sneak\Sneak%c.CL2", "Monsters\Sneak\Sneak%c%i.WAV", "Monsters\Sneak\Sneakv1.TRN", 128, 992, true, false, true, {16, 8, 12, 8, 24, 15}, {2, 0, 0, 0, 0, 0}, 14, 18, 13, 40, 60, AI_SNEAK, MFLAG_HIDDEN | MFLAG_SEARCH , 3, 40, 8, 16, 24, 0, 0, 0, 0, 30, MonsterClass::Demon, RESIST_MAGIC | RESIST_FIRE , RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_NULL_40 , 0, 3, 1500},
{P_("monster", "Foul Corpse"), "Monsters\Zombie\Zombie%c.CL2", "Monsters\Zombie\Zombie%c%i.WAV", "Monsters\Fat\FatF.TRN", 128, 947, false, false, true, {11, 24, 12, 6, 16, 0}, {0, 0, 0, 0, 0, 0}, 0, 2, 1, 2, 5, AI_ZOMBIE, , 0, 0, 8, 1, 4, 0, 0, 0, 0, 3, MonsterClass::Undead, 0, 0, 0, 3, 50},
{P_("monster", "Flesh Clan"), "Monsters\GoatMace\Goat%c.CL2", "Monsters\GoatMace\Goat%c%i.WAV", nullptr, 128, 1030, true, true, false, {12, 8, 12, 6, 20, 12}, {2, 0, 0, 0, 1, 0}, 6, 10, 8, 30, 45, AI_GOATMC, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 0, 30, 8, 4, 10, 55, 7, 6, 15, 40, MonsterClass::Demon, 0, 0, 0, 3, 460},
{P_("monster", "Stone Clan"), "Monsters\GoatMace\Goat%c.CL2", "Monsters\GoatMace\Goat%c%i.WAV", "Monsters\GoatMace\Beige.TRN", 128, 1030, true, true, true, {12, 8, 12, 6, 20, 12}, {2, 0, 0, 0, 1, 0}, 8, 12, 10, 40, 55, AI_GOATMC, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 1, 40, 8, 6, 12, 60, 7, 9, 18, 40, MonsterClass::Demon, RESIST_MAGIC | IMMUNE_NULL_40 , IMMUNE_MAGIC | IMMUNE_NULL_40 , 0, 3, 685},
{P_("monster", "Fire Clan"), "Monsters\GoatMace\Goat%c.CL2", "Monsters\GoatMace\Goat%c%i.WAV", "Monsters\GoatMace\Red.TRN", 128, 1030, true, true, true, {12, 8, 12, 6, 20, 12}, {2, 0, 0, 0, 1, 0}, 10, 14, 12, 50, 65, AI_GOATMC, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 2, 50, 8, 8, 16, 80, 7, 12, 24, 45, MonsterClass::Demon, RESIST_FIRE , IMMUNE_FIRE , 0, 3, 906},
{P_("monster", "Night Clan"), "Monsters\GoatMace\Goat%c.CL2", "Monsters\GoatMace\Goat%c%i.WAV", "Monsters\GoatMace\Gray.TRN", 128, 1030, true, true, true, {12, 8, 12, 6, 20, 12}, {2, 0, 0, 0, 1, 0}, 12, 16, 14, 55, 70, AI_GOATMC, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 60, 8, 10, 20, 90, 7, 15, 30, 50, MonsterClass::Demon, RESIST_MAGIC | IMMUNE_NULL_40 , IMMUNE_MAGIC | IMMUNE_NULL_40 , 0, 3, 1190},
{P_("monster", "Fiend"), "Monsters\Bat\Bat%c.CL2", "Monsters\Bat\Bat%c%i.WAV", "Monsters\Bat\red.trn", 96, 900, false, false, true, {9, 13, 10, 9, 13, 0}, {0, 0, 0, 0, 0, 0}, 2, 4, 3, 3, 6, AI_BAT, , 0, 15, 5, 1, 6, 0, 0, 0, 0, 0, MonsterClass::Animal, 0, 0, 0, 6, 102},
{P_("monster", "Blink"), "Monsters\Bat\Bat%c.CL2", "Monsters\Bat\Bat%c%i.WAV", nullptr, 96, 900, false, false, false, {9, 13, 10, 9, 13, 0}, {0, 0, 0, 0, 0, 0}, 4, 8, 7, 12, 28, AI_BAT, , 1, 25, 5, 1, 8, 0, 0, 0, 0, 15, MonsterClass::Animal, 0, 0, 0, 6, 340},
{P_("monster", "Gloom"), "Monsters\Bat\Bat%c.CL2", "Monsters\Bat\Bat%c%i.WAV", "Monsters\Bat\grey.trn", 96, 900, false, false, true, {9, 13, 10, 9, 13, 0}, {0, 0, 0, 0, 0, 0}, 6, 10, 9, 28, 36, AI_BAT, MFLAG_SEARCH , 2, 50, 5, 4, 12, 0, 0, 0, 0, 35, MonsterClass::Animal, RESIST_MAGIC , RESIST_MAGIC , 0, 6, 509},
{P_("monster", "Familiar"), "Monsters\Bat\Bat%c.CL2", "Monsters\Bat\Bat%c%i.WAV", "Monsters\Bat\orange.trn", 96, 1000, false, false, true, {9, 13, 10, 9, 13, 0}, {0, 0, 0, 0, 0, 0}, 10, 14, 13, 20, 35, AI_BAT, MFLAG_SEARCH , 3, 30, 5, 4, 16, 0, 0, 0, 0, 35, MonsterClass::Demon, RESIST_MAGIC | IMMUNE_LIGHTNING , RESIST_MAGIC | IMMUNE_LIGHTNING , 0, 6, 448},
{P_("monster", "Flesh Clan"), "Monsters\GoatBow\GoatB%c.CL2", "Monsters\GoatBow\GoatB%c%i.WAV", nullptr, 128, 1040, false, false, false, {12, 8, 16, 6, 20, 0}, {3, 0, 0, 0, 0, 0}, 6, 10, 8, 20, 35, AI_GOATBOW, MFLAG_CAN_OPEN_DOOR , 0, 15, 13, 1, 7, 0, 0, 0, 0, 35, MonsterClass::Demon, 0, 0, 0, 3, 448},
{P_("monster", "Stone Clan"), "Monsters\GoatBow\GoatB%c.CL2", "Monsters\GoatBow\GoatB%c%i.WAV", "Monsters\GoatBow\Beige.TRN", 128, 1040, false, false, true, {12, 8, 16, 6, 20, 0}, {3, 0, 0, 0, 0, 0}, 8, 12, 10, 30, 40, AI_GOATBOW, MFLAG_CAN_OPEN_DOOR , 1, 20, 13, 2, 9, 0, 0, 0, 0, 35, MonsterClass::Demon, RESIST_MAGIC | IMMUNE_NULL_40 , IMMUNE_MAGIC | IMMUNE_NULL_40 , 0, 3, 645},
{P_("monster", "Mirkwood Witch"), "Monsters\Succ\Scbs%c.CL2", "Monsters\Succ\Scbs%c%i.WAV", "Monsters\Magma\Yellow.TRN", 128, 1200, false, false, true, {14, 8, 16, 7, 24, 0}, {0, 0, 0, 0, 0, 0}, 30, 30, 31, 175, 240, AI_SUCC, , 3, 120, 10, 29, 29, 0, 0, 0, 0, 90, MonsterClass::Demon, IMMUNE_FIRE | IMMUNE_LIGHTNING , IMMUNE_FIRE | IMMUNE_LIGHTNING , 0, 3, 5500},
{P_("monster", "Night Clan"), "Monsters\GoatBow\GoatB%c.CL2", "Monsters\GoatBow\GoatB%c%i.WAV", "Monsters\GoatBow\Gray.TRN", 128, 1040, false, false, true, {12, 8, 16, 6, 20, 0}, {3, 0, 0, 0, 0, 0}, 12, 16, 14, 50, 65, AI_GOATBOW, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 30, 13, 4, 13, 15, 0, 0, 0, 40, MonsterClass::Demon, RESIST_MAGIC | IMMUNE_NULL_40 , IMMUNE_MAGIC | IMMUNE_NULL_40 , 0, 3, 1092},
{P_("monster", "Poison Vermin"), "Monsters\Scav\Scav%c.CL2", "Monsters\Scav\Scav%c%i.WAV", nullptr, 128, 700, true, true, false, {12, 8, 12, 6, 20, 11}, {0, 0, 0, 0, 0, 0}, 4, 8, 8, 20, 35, AI_ACID, , 0, 15, 7, 4, 10, 25, 8, 0, 0, 30, MonsterClass::Animal, 0, RESIST_FIRE , 0, 3, 500},
{P_("monster", "Acid Crawler"), "Monsters\Scav\Scav%c.CL2", "Monsters\Scav\Scav%c%i.WAV", "Monsters\Monsters\bfds.trn", 128, 700, true, true, true, {12, 8, 12, 6, 20, 11}, {0, 0, 0, 0, 0, 0}, 8, 12, 10, 30, 40, AI_ACID, , 1, 25, 7, 6, 12, 25, 8, 0, 0, 40, MonsterClass::Animal, 0, RESIST_LIGHTNING , 0, 3, 700},
{P_("monster", "Acid Fiend"), "Monsters\Scav\Scav%c.CL2", "Monsters\Scav\Scav%c%i.WAV", "Monsters\Succ\Succbw.TRN", 128, 956, true, true, true, {12, 8, 12, 6, 20, 11}, {0, 0, 0, 0, 0, 0}, 12, 16, 14, 50, 70, AI_ACID, , 2, 35, 7, 9, 18, 35, 8, 0, 0, 45, MonsterClass::Animal, RESIST_MAGIC , IMMUNE_MAGIC , 0, 3, 1100},
{P_("monster", "Spitting Terror"), "Monsters\Scav\Scav%c.CL2", "Monsters\Scav\Scav%c%i.WAV", "Monsters\Succ\Succrw.TRN", 128, 1212, true, true, true, {12, 8, 12, 6, 20, 11}, {0, 0, 0, 0, 0, 0}, 16, 20, 19, 70, 100, AI_ACID, , 3, 55, 7, 12, 20, 40, 8, 0, 0, 55, MonsterClass::Animal, RESIST_MAGIC | IMMUNE_FIRE | IMMUNE_ACID, IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_ACID, 0, 3, 1900},
{P_("monster", "Skeleton King"), "Monsters\SKing\SKing%c.CL2", "Monsters\SKing\SKing%c%i.WAV", "Monsters\SkelAxe\White.TRN", 160, 1010, true, true, true, {8, 6, 16, 6, 16, 6}, {2, 0, 0, 0, 0, 2}, 6, 6, 16, 350, 350, AI_FAT, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 55, 8, 9, 18, 0, 0, 0, 0, 80, MonsterClass::Undead, RESIST_FIRE | RESIST_LIGHTNING | IMMUNE_MAGIC | IMMUNE_NULL_40 , IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_LIGHTNING | IMMUNE_NULL_40 , 32769, 7, 700},
{P_("monster", "Bert"), "Monsters\FatC\FatC%c.CL2", "Monsters\FatC\FatC%c%i.WAV", nullptr, 128, 980, false, false, false, {10, 8, 12, 6, 16, 0}, {1, 0, 0, 0, 0, 0}, 0, 0, 6, 400, 400, AI_CLEAVER, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 40, 8, 8, 15, 0, 0, 0, 0, 60, MonsterClass::Demon, RESIST_FIRE | RESIST_LIGHTNING , RESIST_MAGIC | IMMUNE_FIRE | IMMUNE_LIGHTNING , 32768, 3, 800},
{P_("monster", "Hill Troll"), "Monsters\Fat\Fat%c.CL2", "Monsters\Fat\Fat%c%i.WAV", "Monsters\GoatMace\Beige.TRN", 128, 1130, true, true, true, {8, 10, 15, 6, 16, 10}, {4, 0, 0, 0, 0, 0}, 16, 20, 18, 140, 170, AI_FAT, MFLAG_KNOCKBACK , 0, 80, 8, 10, 20, 90, 8, 20, 20, 70, MonsterClass::Animal, RESIST_FIRE , RESIST_MAGIC | RESIST_FIRE | RESIST_LIGHTNING , 0, 3, 1700},
{P_("monster", "Cave Troll"), "Monsters\Fat\Fat%c.CL2", "Monsters\Fat\Fat%c%i.WAV", "Monsters\Monsters\BLKJD.TRN", 128, 1386, true, true, true, {8, 10, 15, 6, 16, 10}, {4, 0, 0, 0, 0, 0}, 18, 22, 21, 180, 200, AI_FAT, MFLAG_KNOCKBACK | MFLAG_SEARCH , 1, 85, 8, 12, 22, 95, 8, 22, 22, 80, MonsterClass::Animal, RESIST_MAGIC | IMMUNE_FIRE , IMMUNE_MAGIC | IMMUNE_FIRE , 0, 3, 2100},
{P_("monster", "Mountain Troll"), "Monsters\Fat\Fat%c.CL2", "Monsters\Fat\Fat%c%i.WAV", "Monsters\Mage\Cnselg.TRN", 128, 1642, true, true, true, {8, 10, 14, 6, 16, 10}, {4, 0, 0, 0, 0, 0}, 22, 26, 24, 200, 230, AI_FAT, MFLAG_KNOCKBACK | MFLAG_SEARCH , 2, 100, 8, 14, 24, 110, 8, 24, 24, 90, MonsterClass::Animal, IMMUNE_MAGIC , RESIST_LIGHTNING | IMMUNE_MAGIC , 0, 3, 3200},
{P_("monster", "Black Troll"), "Monsters\Fat\Fat%c.CL2", "Monsters\Fat\Fat%c%i.WAV", "Monsters\Acid\AcidBlk.TRN", 128, 1642, true, true, true, {8, 10, 13, 6, 16, 10}, {4, 0, 0, 0, 0, 0}, 26, 28, 28, 220, 250, AI_FAT, MFLAG_KNOCKBACK | MFLAG_SEARCH , 3, 115, 8, 20, 30, 125, 8, 30, 30, 100, MonsterClass::Animal, RESIST_MAGIC | RESIST_FIRE | RESIST_LIGHTNING , RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_LIGHTNING , 0, 3, 4500},
{P_("monster", "Blood Clan"), "Monsters\GoatMace\Goat%c.CL2", "Monsters\GoatMace\Goat%c%i.WAV", "Monsters\Mega\Balr.TRN", 128, 1030, true, true, true, {12, 8, 10, 4, 20, 12}, {1, 0, 0, 0, 0, 0}, 14, 18, 20, 70, 100, AI_RHINO, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 60, 8, 12, 22, 90, 8, 20, 40, 65, MonsterClass::Demon, RESIST_MAGIC | IMMUNE_FIRE , IMMUNE_MAGIC | IMMUNE_FIRE , 0, 3, 2100},
{P_("monster", "Brood of Shelob"), "Monsters\spider\spider%c.CL2", "Monsters\worm\worm%c%i.wav", "Monsters\Monsters\bhka.trn", 148, 1807, false, false, true, {12, 10, 15, 6, 20, 15}, {1, 0, 0, 0, 0, 0}, 26, 30, 30, 300, 350, AI_SKELSD, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR | MFLAG_NOLIFESTEAL , 50, 120, 8, 40, 40, 0, 0, 0, 0, 115, MonsterClass::Animal, RESIST_FIRE | RESIST_LIGHTNING , RESIST_MAGIC | RESIST_FIRE | IMMUNE_LIGHTNING , 0, 7, 5000},
{P_("monster", "Olog-Hai"), "Monsters\byclps\byclps%c.CL2", "Monsters\byclps\biclop%c%i.WAV", "Monsters\Acid\AcidR.TRN", 180, 1295, false, false, false, {10, 11, 16, 6, 16, 0}, {0, 0, 0, 0, 0, 0}, 14, 18, 16, 130, 150, AI_SKELSD, , 1, 70, 8, 10, 15, 0, 0, 0, 0, 65, MonsterClass::Animal, RESIST_MAGIC | RESIST_FIRE | RESIST_LIGHTNING , RESIST_MAGIC | RESIST_FIRE | IMMUNE_LIGHTNING , 0, 3, 1300},
{P_("monster", "Cave Bat"), "Monsters\Bat\Bat%c.CL2", "Monsters\Bat\Bat%c%i.WAV", "Monsters\Succ\Succrw.TRN", 96, 1248, false, false, true, {9, 10, 10, 7, 13, 0}, {0, 0, 0, 0, 0, 0}, 16, 18, 15, 40, 45, AI_BAT, MFLAG_SEARCH , 3, 60, 5, 6, 18, 0, 0, 0, 0, 45, MonsterClass::Animal, RESIST_MAGIC | IMMUNE_FIRE | IMMUNE_NULL_40 , RESIST_MAGIC | RESIST_LIGHTNING | IMMUNE_FIRE | IMMUNE_NULL_40 , 0, 6, 900},
{P_("monster", "Doom Fire"), "Monsters\Demskel\Demskl%c.CL2", "Monsters\SKing\SKing%c%i.WAV", "Monsters\Scav\ScavBr.TRN", 128, 1807, true, true, true, {10, 8, 20, 6, 24, 16}, {3, 0, 0, 0, 0, 0}, 24, 26, 27, 170, 210, AI_MAGMA, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 16, 110, 8, 12, 20, 120, 8, 12, 18, 85, MonsterClass::Undead, IMMUNE_FIRE , RESIST_MAGIC | IMMUNE_FIRE , 0, 7, 3800},
{P_("monster", "Blood Stone"), "Monsters\Magma\Magma%c.CL2", "Monsters\Magma\Magma%c%i.WAV", "Monsters\Magma\Yellow.TRN", 128, 1680, true, true, true, {8, 10, 14, 7, 18, 18}, {2, 0, 0, 0, 1, 0}, 15, 19, 14, 55, 75, AI_MAGMA, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 1, 30, 4, 2, 12, 30, 14, 0, 0, 45, MonsterClass::Demon, IMMUNE_MAGIC | IMMUNE_FIRE , IMMUNE_MAGIC | IMMUNE_FIRE , 0, 7, 1309},
{P_("monster", "Hell Stone"), "Monsters\Magma\Magma%c.CL2", "Monsters\Magma\Magma%c%i.WAV", "Monsters\Magma\Blue.TRN", 128, 1680, true, true, true, {8, 10, 14, 7, 18, 18}, {2, 0, 0, 0, 1, 0}, 16, 20, 16, 60, 80, AI_MAGMA, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 2, 40, 4, 2, 20, 40, 14, 0, 0, 50, MonsterClass::Demon, IMMUNE_MAGIC | IMMUNE_FIRE , IMMUNE_MAGIC | IMMUNE_FIRE , 0, 7, 1680},
{P_("monster", "Lava Lord"), "Monsters\Magma\Magma%c.CL2", "Monsters\Magma\Magma%c%i.WAV", "Monsters\Magma\Wierd.TRN", 128, 1680, true, true, true, {8, 10, 14, 7, 18, 18}, {2, 0, 0, 0, 1, 0}, 17, 21, 18, 70, 85, AI_MAGMA, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 55, 4, 4, 24, 40, 14, 0, 0, 60, MonsterClass::Demon, IMMUNE_MAGIC | IMMUNE_FIRE , IMMUNE_MAGIC | IMMUNE_FIRE , 0, 7, 2124},
{P_("monster", "Southron Beast"), "Monsters\Rhino\Rhino%c.CL2", "Monsters\Rhino\Rhino%c%i.WAV", "Monsters\Scav\ScavBr.TRN", 160, 1630, true, true, true, {8, 8, 14, 6, 16, 6}, {2, 0, 0, 0, 0, 0}, 16, 20, 18, 80, 110, AI_RHINO, MFLAG_KNOCKBACK | MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 0, 80, 7, 10, 20, 95, 1, 20, 40, 60, MonsterClass::Animal, RESIST_FIRE , RESIST_MAGIC | RESIST_FIRE | RESIST_LIGHTNING , 0, 7, 1750},
{P_("monster", "Shadow"), "Monsters\Sneak\Sneak%c.CL2", "Monsters\Sneak\Sneak%c%i.WAV", "Monsters\Mega\Guard.TRN", 128, 1204, true, true, true, {16, 8, 12, 8, 24, 15}, {1, 0, 0, 0, 0, 0}, 18, 22, 20, 160, 190, AI_SNEAK, MFLAG_HIDDEN | MFLAG_SEARCH , 3, 65, 8, 19, 27, 0, 0, 0, 0, 50, MonsterClass::Demon, RESIST_FIRE | RESIST_LIGHTNING , RESIST_MAGIC | RESIST_FIRE | RESIST_LIGHTNING , 0, 3, 2000},
{P_("monster", "Tusk Beast"), "Monsters\Rhino\Rhino%c.CL2", "Monsters\Rhino\Rhino%c%i.WAV", "Monsters\Monsters\bsts.trn", 160, 1630, true, true, true, {8, 8, 14, 6, 16, 6}, {2, 0, 0, 0, 0, 0}, 18, 22, 22, 190, 210, AI_RHINO, MFLAG_KNOCKBACK | MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 2, 85, 7, 14, 22, 100, 1, 25, 45, 75, MonsterClass::Animal, RESIST_LIGHTNING | IMMUNE_MAGIC , RESIST_LIGHTNING | IMMUNE_MAGIC , 0, 7, 2700},
{P_("monster", "Mumakil"), "Monsters\Rhino\Rhino%c.CL2", "Monsters\Rhino\Rhino%c%i.WAV", "Monsters\Black\BlkKntBT.TRN", 160, 1807, true, true, true, {8, 8, 14, 6, 16, 6}, {2, 0, 0, 0, 0, 0}, 22, 26, 26, 210, 240, AI_RHINO, MFLAG_KNOCKBACK | MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 110, 7, 20, 25, 120, 1, 30, 50, 85, MonsterClass::Animal, RESIST_LIGHTNING | IMMUNE_MAGIC , RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_LIGHTNING , 0, 7, 3600},
{P_("monster", "Thunder Claw"), "Monsters\Thin\Thin%c.CL2", "Monsters\Thin\Thin%c%i.WAV", "Monsters\Mega\Balr.TRN", 160, 1204, true, true, true, {8, 7, 14, 4, 17, 1}, {2, 0, 0, 0, 0, 0}, 28, 30, 30, 175, 200, AI_STORM, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 110, 5, 20, 30, 110, 1, 8, 20, 80, MonsterClass::Demon, RESIST_FIRE | IMMUNE_LIGHTNING , RESIST_MAGIC | RESIST_FIRE | IMMUNE_LIGHTNING , 0, 7, 4200},
{P_("monster", "Necro Lord"), "Monsters\Demskel\Demskl%c.CL2", "Monsters\SKing\SKing%c%i.WAV", "Monsters\Bat\grey.trn", 128, 1204, false, false, true, {10, 8, 20, 6, 24, 16}, {3, 0, 0, 0, 0, 0}, 24, 26, 26, 150, 200, AI_SUCC, MFLAG_CAN_OPEN_DOOR , 2, 115, 8, 10, 15, 0, 0, 0, 0, 80, MonsterClass::Undead, RESIST_FIRE | RESIST_LIGHTNING , RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_LIGHTNING , 0, 7, 3750},
{P_("monster", "Wyrm"), "Monsters\Snake\Snake%c.CL2", "Monsters\Snake\Snake%c%i.WAV", nullptr, 160, 1780, true, true, false, {12, 11, 13, 5, 18, 16}, {2, 0, 0, 0, 1, 0}, 18, 20, 19, 80, 120, AI_GOATMC, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 0, 70, 8, 8, 18, 80, 8, 12, 23, 55, MonsterClass::Demon, IMMUNE_MAGIC , IMMUNE_MAGIC , 0, 7, 2300},
{P_("monster", "Ghost Knight of Erech"), "Monsters\Black\Black%c.CL2", "Monsters\Black\Black%c%i.WAV", "Monsters\Monsters\dsfm.trn", 160, 1807, false, false, true, {8, 6, 12, 2, 24, 0}, {1, 0, 0, 0, 0, 0}, 24, 26, 26, 100, 200, AI_SNAKE, MFLAG_KNOCKBACK | MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR | MFLAG_NOLIFESTEAL , 3, 133, 8, 1, 25, 0, 0, 0, 0, 85, MonsterClass::Undead, RESIST_MAGIC | RESIST_FIRE | IMMUNE_NULL_40 , RESIST_MAGIC | IMMUNE_FIRE | IMMUNE_NULL_40 , 0, 7, 3800},
{P_("monster", "Barrow Wight"), "Monsters\Zombie\Zombie%c.CL2", "Monsters\Zombie\Zombie%c%i.WAV", "Monsters\Rhino\RhinoB.TRN", 128, 799, false, false, true, {11, 18, 11, 5, 16, 0}, {3, 0, 0, 0, 0, 0}, 6, 10, 10, 15, 25, AI_ZOMBIE, , 3, 30, 8, 8, 24, 0, 0, 0, 0, 25, MonsterClass::Undead, IMMUNE_MAGIC | IMMUNE_NULL_40 , RESIST_LIGHTNING | IMMUNE_MAGIC | IMMUNE_NULL_40 , 0, 3, 500},
{P_("monster", "Brood of Ungoliant"), "Monsters\spider\spider%c.CL2", "Monsters\worm\worm%c%i.wav", "Monsters\SkelSd\Black.TRN", 148, 1807, false, false, true, {12, 10, 15, 4, 20, 0}, {1, 0, 0, 0, 0, 0}, 28, 30, 33, 350, 450, AI_SKELSD, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR | MFLAG_NOLIFESTEAL , 127, 130, 8, 50, 50, 0, 0, 0, 0, 135, MonsterClass::Animal, RESIST_MAGIC | RESIST_FIRE | IMMUNE_LIGHTNING , RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_LIGHTNING , 0, 7, 6000},
{P_("monster", "Witch Queen"), "Monsters\Succ\Scbs%c.CL2", "Monsters\Succ\Scbs%c%i.WAV", "Monsters\Scav\ScavW.TRN", 128, 2220, false, false, true, {14, 6, 10, 5, 24, 0}, {0, 0, 0, 0, 0, 0}, 26, 30, 34, 260, 280, AI_SUCC, , 0, 125, 10, 5, 30, 0, 0, 0, 0, 100, MonsterClass::Demon, RESIST_MAGIC | RESIST_LIGHTNING | IMMUNE_FIRE , IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_LIGHTNING , 0, 3, 8000},
{P_("monster", "Greater War Mumakil"), "Monsters\Rhino\Rhino%c.CL2", "Monsters\Rhino\Rhino%c%i.WAV", "Monsters\Monsters\skfr.trn", 160, 1807, true, true, true, {8, 6, 13, 3, 16, 3}, {1, 0, 0, 0, 0, 0}, 26, 30, 31, 250, 300, AI_STORM, MFLAG_KNOCKBACK | MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 125, 7, 33, 43, 125, 0, 40, 50, 115, MonsterClass::Animal, RESIST_FIRE | RESIST_LIGHTNING , RESIST_MAGIC | RESIST_FIRE | IMMUNE_LIGHTNING , 0, 7, 6000},
{P_("monster", "Werewolf"), "Monsters\Acid\Acid%c.CL2", "Monsters\Wolf\Wolf%c%i.wav", "Monsters\Mega\Guard.TRN", 128, 1807, true, false, true, {13, 6, 10, 4, 16, 12}, {0, 0, 0, 0, 0, 0}, 24, 26, 28, 175, 190, AI_SNAKE, MFLAG_CAN_OPEN_DOOR , 10, 120, 8, 20, 30, 0, 0, 0, 0, 85, MonsterClass::Animal, RESIST_MAGIC | RESIST_LIGHTNING | IMMUNE_FIRE | IMMUNE_NULL_40 , RESIST_LIGHTNING | IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_NULL_40 , 0, 3, 4300},
{P_("monster", "Wraith Claw"), "Monsters\Thin\Thin%c.CL2", "Monsters\Thin\Thin%c%i.WAV", "Monsters\Bat\grey.trn", 160, 1807, true, true, true, {8, 3, 16, 4, 17, 2}, {2, 0, 0, 0, 0, 0}, 26, 28, 29, 120, 220, AI_SKELSD, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 125, 5, 1, 30, 0, 0, 0, 0, 80, MonsterClass::Undead, RESIST_FIRE | RESIST_LIGHTNING , RESIST_MAGIC | RESIST_LIGHTNING | IMMUNE_FIRE , 0, 7, 4300},
{P_("monster", "Storm Lord"), "Monsters\Thin\Thin%c.CL2", "Monsters\Thin\Thin%c%i.WAV", "Monsters\Thin\Thinv2.TRN", 160, 1807, true, true, true, {8, 8, 18, 4, 17, 14}, {3, 0, 0, 0, 0, 0}, 20, 24, 22, 75, 135, AI_STORM, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 2, 75, 5, 12, 24, 65, 8, 4, 16, 35, MonsterClass::Demon, RESIST_MAGIC | IMMUNE_LIGHTNING , IMMUNE_MAGIC | IMMUNE_LIGHTNING , 0, 7, 2775},
{P_("monster", "Demon Claw"), "Monsters\Thin\Thin%c.CL2", "Monsters\Thin\Thin%c%i.WAV", "Monsters\Monsters\shcr.trn", 160, 1807, true, true, true, {8, 8, 15, 4, 17, 14}, {3, 0, 0, 0, 0, 0}, 24, 26, 26, 130, 180, AI_STORM, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 115, 5, 20, 28, 0, 8, 0, 0, 80, MonsterClass::Demon, RESIST_MAGIC | IMMUNE_LIGHTNING , IMMUNE_MAGIC | IMMUNE_LIGHTNING , 0, 7, 4000},
{P_("monster", "Nazgul"), "Monsters\Black\Black%c.CL2", "Monsters\Black\Black%c%i.WAV", "Monsters\Mega\Guard.TRN", 160, 2220, false, false, true, {8, 7, 13, 1, 24, 0}, {1, 0, 0, 0, 0, 0}, 28, 30, 34, 300, 300, AI_SKELSD, MFLAG_KNOCKBACK | MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR | MFLAG_NOLIFESTEAL , 127, 130, 8, 35, 45, 0, 0, 0, 0, 125, MonsterClass::Demon, RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_LIGHTNING , RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_LIGHTNING , 0, 7, 8000},
{P_("monster", "Blood Wing"), "Monsters\Gargoyle\Gargo%c.CL2", "Monsters\Gargoyle\Gargo%c%i.WAV", "Monsters\Snake\SnakR.TRN", 160, 1650, true, false, true, {14, 13, 13, 8, 18, 14}, {0, 0, 0, 0, 0, 2}, 12, 16, 13, 60, 90, AI_SKELSD, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR | MFLAG_NOLIFESTEAL , 0, 45, 7, 10, 16, 0, 0, 0, 0, 45, MonsterClass::Undead, RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_NULL_40 , IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_NULL_40 , 0, 6, 1205},
{P_("monster", "Vampire"), "Monsters\Gargoyle\Gargo%c.CL2", "Monsters\Gargoyle\Gargo%c%i.WAV", "Monsters\Monsters\dsfm.trn", 160, 1650, true, false, true, {14, 12, 12, 7, 18, 14}, {0, 0, 0, 0, 0, 2}, 16, 20, 19, 75, 125, AI_SKELSD, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR | MFLAG_NOLIFESTEAL , 1, 60, 7, 14, 22, 0, 0, 0, 0, 50, MonsterClass::Undead, RESIST_LIGHTNING | IMMUNE_MAGIC | IMMUNE_NULL_40 , IMMUNE_MAGIC | IMMUNE_LIGHTNING | IMMUNE_NULL_40 , 0, 6, 1873},
{P_("monster", "Greater Vampire"), "Monsters\Gargoyle\Gargo%c.CL2", "Monsters\Gargoyle\Gargo%c%i.WAV", "Monsters\Monsters\BLKJD.TRN", 160, 1650, true, false, true, {14, 10, 11, 6, 18, 14}, {0, 0, 0, 0, 0, 0}, 20, 22, 23, 90, 150, AI_SKELSD, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR | MFLAG_NOLIFESTEAL , 2, 85, 7, 16, 28, 0, 0, 0, 0, 60, MonsterClass::Undead, IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_NULL_40 , RESIST_LIGHTNING | IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_NULL_40 , 0, 6, 2278},
{P_("monster", "Melkoric Vampire"), "Monsters\Gargoyle\Gargo%c.CL2", "Monsters\Gargoyle\Gargo%c%i.WAV", "Monsters\FalSpear\Dark.TRN", 160, 1807, true, false, true, {14, 7, 10, 4, 18, 14}, {0, 0, 0, 0, 0, 0}, 26, 30, 30, 200, 220, AI_SNEAK, MFLAG_HIDDEN | MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR | MFLAG_NOLIFESTEAL , 3, 120, 7, 20, 40, 0, 0, 0, 0, 100, MonsterClass::Undead, IMMUNE_MAGIC | IMMUNE_LIGHTNING , RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_LIGHTNING | IMMUNE_NULL_40 , 0, 6, 5000},
{P_("monster", "Frost Demon"), "Monsters\Mega\Mega%c.CL2", "Monsters\Mega\Mega%c%i.WAV", "Monsters\Acid\AcidB.TRN", 160, 1807, true, true, true, {6, 6, 12, 1, 24, 1}, {2, 0, 0, 0, 2, 0}, 26, 30, 31, 240, 280, AI_STORM, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 130, 8, 30, 40, 130, 1, 30, 40, 115, MonsterClass::Demon, RESIST_MAGIC | IMMUNE_LIGHTNING , RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_LIGHTNING , 0, 7, 5500},
{P_("monster", "Lesser Demon"), "Monsters\Mega\Mega%c.CL2", "Monsters\Balrog\Mega%c%i.wav", "Monsters\SkelSd\White.TRN", 160, 1807, true, true, true, {6, 7, 14, 1, 24, 5}, {3, 0, 0, 0, 2, 0}, 20, 24, 22, 140, 160, AI_SKELSD, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 1, 100, 8, 14, 22, 0, 3, 0, 0, 75, MonsterClass::Demon, RESIST_MAGIC | IMMUNE_FIRE , RESIST_MAGIC | IMMUNE_FIRE , 0, 7, 2714},
{P_("monster", "Dark Fire"), "Monsters\Mega\Mega%c.CL2", "Monsters\Balrog\Mega%c%i.wav", "Monsters\Mega\Guard.TRN", 160, 1807, true, true, true, {6, 7, 13, 1, 24, 5}, {3, 0, 0, 0, 2, 0}, 24, 26, 24, 180, 200, AI_MEGA, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 2, 115, 8, 22, 28, 0, 3, 0, 0, 85, MonsterClass::Demon, RESIST_MAGIC | IMMUNE_FIRE , RESIST_MAGIC | RESIST_LIGHTNING | IMMUNE_FIRE , 0, 7, 3600},
{P_("monster", "Gerippe"), "Monsters\SkelSd\SklSr%c.CL2", "Monsters\SkelSd\SklSr%c%i.WAV", "Monsters\Scav\ScavW.TRN", 128, 575, true, true, true, {13, 8, 12, 7, 15, 16}, {0, 0, 0, 0, 0, 0}, 4, 8, 7, 20, 35, AI_SNEAK, MFLAG_HIDDEN | MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 20, 8, 5, 12, 0, 1, 0, 0, 22, MonsterClass::Undead, RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_NULL_40 , IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_NULL_40 , 0, 3, 500},
{P_("monster", "Cave Drake"), "Monsters\Snake\Snake%c.CL2", "Monsters\Snake\Snake%c%i.WAV", "Monsters\Zombie\Grey.TRN", 160, 1204, true, true, true, {12, 11, 13, 5, 18, 0}, {2, 0, 0, 0, 1, 0}, 20, 22, 22, 110, 160, AI_SNAKE, MFLAG_SEARCH , 1, 85, 8, 10, 22, 0, 0, 0, 0, 70, MonsterClass::Animal, IMMUNE_MAGIC , IMMUNE_MAGIC , 0, 7, 2800},
{P_("monster", "Black Numenorean"), "Monsters\Black\Black%c.CL2", "Monsters\Black\Black%c%i.WAV", "Monsters\Fat\Blue.TRN", 160, 1807, false, false, true, {8, 7, 12, 2, 24, 0}, {2, 0, 0, 0, 0, 0}, 26, 30, 30, 220, 220, AI_SKELSD, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 127, 8, 26, 38, 0, 0, 0, 0, 105, MonsterClass::Demon, RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_LIGHTNING , RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_LIGHTNING , 0, 7, 5210},
{P_("monster", "Ghost Drake"), "Monsters\Snake\Snake%c.CL2", "Monsters\Snake\Snake%c%i.WAV", "Monsters\Scav\ScavW.TRN", 160, 1295, true, true, true, {12, 9, 11, 4, 18, 16}, {2, 0, 0, 0, 1, 0}, 24, 26, 26, 140, 180, AI_SNEAK, MFLAG_HIDDEN | MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 2, 120, 8, 12, 20, 0, 0, 0, 0, 75, MonsterClass::Undead, RESIST_MAGIC | IMMUNE_LIGHTNING , RESIST_LIGHTNING | IMMUNE_MAGIC | IMMUNE_FIRE , 0, 7, 3600},
{P_("monster", "Storm Dragon"), "Monsters\Snake\Snake%c.CL2", "Monsters\Thin\Thin%c%i.WAV", "Monsters\Succ\Succb.TRN", 160, 1204, true, true, true, {12, 10, 13, 5, 18, 1}, {2, 0, 0, 0, 1, 0}, 26, 30, 30, 180, 210, AI_STORM, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 125, 8, 23, 32, 125, 1, 10, 20, 95, MonsterClass::Demon, RESIST_MAGIC | IMMUNE_LIGHTNING , RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_LIGHTNING , 0, 7, 5100},
{P_("monster", "Easterling"), "Monsters\Black\Black%c.CL2", "Monsters\Black\Black%c%i.WAV", "Monsters\Succ\Succb.TRN", 160, 1807, false, false, true, {8, 8, 15, 4, 24, 0}, {2, 0, 0, 0, 0, 0}, 24, 26, 25, 165, 165, AI_SKELSD, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 105, 8, 16, 22, 0, 0, 0, 0, 80, MonsterClass::Demon, RESIST_MAGIC | IMMUNE_LIGHTNING , RESIST_MAGIC | IMMUNE_LIGHTNING , 0, 7, 3360},
{P_("monster", "Variag"), "Monsters\Black\Black%c.CL2", "Monsters\Black\Black%c%i.WAV", "Monsters\Sneak\Sneakv3.TRN", 160, 1807, false, false, true, {8, 8, 14, 4, 24, 0}, {2, 0, 0, 0, 0, 0}, 24, 26, 27, 180, 180, AI_SKELSD, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 120, 8, 20, 27, 0, 0, 0, 0, 90, MonsterClass::Demon, RESIST_MAGIC | IMMUNE_FIRE , RESIST_MAGIC | IMMUNE_FIRE , 0, 7, 3650},
{P_("monster", "Haradrim"), "Monsters\Black\Black%c.CL2", "Monsters\Black\Black%c%i.WAV", "Monsters\Magma\Wierd.TRN", 160, 1807, false, false, true, {8, 7, 13, 3, 24, 0}, {2, 0, 0, 0, 0, 0}, 26, 28, 29, 200, 200, AI_SKELSD, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 125, 8, 22, 32, 0, 0, 0, 0, 95, MonsterClass::Demon, RESIST_LIGHTNING | IMMUNE_MAGIC | IMMUNE_FIRE , RESIST_LIGHTNING | IMMUNE_MAGIC | IMMUNE_FIRE , 0, 7, 4252},
{P_("monster", "Guardian Balrog"), "Monsters\Mega\Mega%c.CL2", "Monsters\Balrog\Mega%c%i.wav", "Monsters\Mega\Balr.TRN", 160, 1807, true, true, true, {6, 7, 12, 1, 24, 1}, {2, 0, 0, 0, 2, 0}, 28, 30, 30, 400, 400, AI_MEGA, MFLAG_KNOCKBACK | MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 133, 8, 40, 40, 0, 1, 0, 0, 135, MonsterClass::Demon, RESIST_MAGIC | RESIST_LIGHTNING | IMMUNE_FIRE , RESIST_MAGIC | RESIST_LIGHTNING | IMMUNE_FIRE , 0, 7, 7500},
{P_("monster", "Fallen Istar"), "Monsters\Mage\Mage%c.CL2", "Monsters\DarkMage\Dmag%c%i.WAV", "Monsters\Mega\Guard.TRN", 128, 2220, true, false, true, {12, 1, 15, 6, 28, 7}, {0, 0, 0, 0, 0, 0}, 26, 30, 34, 190, 190, AI_COUNSLR, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 130, 8, 30, 40, 130, 1, 30, 40, 95, MonsterClass::Demon, RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_LIGHTNING , RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_LIGHTNING , 0, 7, 8000},
{P_("monster", "Balrog"), "Monsters\Mega\Mega%c.CL2", "Monsters\Balrog\Mega%c%i.wav", "Monsters\monsters\tspo.trn", 160, 2220, true, true, true, {6, 6, 12, 1, 24, 1}, {2, 0, 0, 0, 2, 0}, 28, 28, 35, 300, 350, AI_MEGA, MFLAG_KNOCKBACK | MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR | MFLAG_NOLIFESTEAL , 15, 133, 8, 50, 60, 0, 1, 0, 0, 130, MonsterClass::Demon, RESIST_LIGHTNING | IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_NULL_40 , RESIST_LIGHTNING | IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_NULL_40 , 0, 7, 9000},
{P_("monster", "Fire Dragon"), "Monsters\Snake\Snake%c.CL2", "Monsters\Mega\Mega%c%i.WAV", "Monsters\Zombie\Bluered.TRN", 160, 2220, true, true, true, {12, 9, 12, 1, 18, 1}, {1, 0, 0, 0, 1, 0}, 26, 30, 34, 280, 360, AI_MEGA, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 8, 130, 8, 35, 48, 130, 1, 45, 45, 120, MonsterClass::Demon, RESIST_LIGHTNING | IMMUNE_MAGIC | IMMUNE_FIRE , RESIST_LIGHTNING | IMMUNE_MAGIC | IMMUNE_FIRE , 0, 7, 8000},
{P_("monster", "Greater Corpse"), "Monsters\Demskel\Demskl%c.CL2", "Monsters\SKing\SKing%c%i.WAV", "Monsters\Fat\FatB.TRN", 128, 1807, true, true, true, {10, 8, 16, 6, 24, 8}, {2, 0, 0, 0, 0, 0}, 26, 30, 30, 200, 225, AI_STORM, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 120, 8, 28, 32, 120, 8, 20, 20, 95, MonsterClass::Undead, RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_LIGHTNING , RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_LIGHTNING , 0, 7, 5000},
{P_("monster", "Succubus"), "Monsters\Succ\Scbs%c.CL2", "Monsters\Succ\Scbs%c%i.WAV", nullptr, 128, 1204, false, false, false, {14, 8, 16, 7, 24, 0}, {0, 0, 0, 0, 0, 0}, 22, 26, 24, 120, 150, AI_SUCC, MFLAG_CAN_OPEN_DOOR , 0, 90, 10, 1, 20, 0, 0, 0, 0, 60, MonsterClass::Demon, RESIST_MAGIC , RESIST_FIRE | IMMUNE_MAGIC , 0, 3, 3696},
{P_("monster", "Snow Witch"), "Monsters\Succ\Scbs%c.CL2", "Monsters\Succ\Scbs%c%i.WAV", "Monsters\Succ\Succb.TRN", 128, 1204, false, false, true, {14, 8, 16, 7, 24, 0}, {0, 0, 0, 0, 0, 0}, 24, 26, 26, 135, 175, AI_SUCC, MFLAG_CAN_OPEN_DOOR , 1, 100, 10, 1, 24, 0, 0, 0, 0, 65, MonsterClass::Demon, RESIST_LIGHTNING , RESIST_LIGHTNING | IMMUNE_MAGIC , 0, 3, 4084},
{P_("monster", "Hell Spawn"), "Monsters\Succ\Scbs%c.CL2", "Monsters\Succ\Scbs%c%i.WAV", "Monsters\Succ\Succrw.TRN", 128, 1204, false, false, true, {14, 8, 16, 7, 24, 0}, {0, 0, 0, 0, 0, 0}, 26, 30, 28, 150, 200, AI_SUCC, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 2, 110, 10, 1, 30, 0, 0, 0, 0, 75, MonsterClass::Demon, RESIST_MAGIC | IMMUNE_LIGHTNING , RESIST_LIGHTNING | IMMUNE_MAGIC | IMMUNE_FIRE , 0, 3, 4480},
{P_("monster", "Soul Burner"), "Monsters\Succ\Scbs%c.CL2", "Monsters\Succ\Scbs%c%i.WAV", "Monsters\Succ\Succbw.TRN", 128, 1204, false, false, true, {14, 8, 16, 7, 24, 0}, {0, 0, 0, 0, 0, 0}, 28, 30, 30, 140, 225, AI_SUCC, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 3, 115, 10, 1, 35, 0, 0, 0, 0, 85, MonsterClass::Demon, RESIST_MAGIC | RESIST_LIGHTNING | IMMUNE_FIRE , RESIST_MAGIC | IMMUNE_FIRE | IMMUNE_LIGHTNING , 0, 3, 4644},
{P_("monster", "Necromancer"), "Monsters\Mage\Mage%c.CL2", "Monsters\Mage\Mage%c%i.WAV", "Monsters\Bat\grey.trn", 128, 1204, true, false, true, {12, 1, 8, 8, 28, 20}, {0, 0, 0, 0, 0, 0}, 24, 26, 25, 70, 70, AI_COUNSLR, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 0, 80, 8, 6, 15, 80, 0, 0, 0, 0, MonsterClass::Undead, RESIST_MAGIC | RESIST_FIRE | RESIST_LIGHTNING , RESIST_MAGIC | RESIST_FIRE | RESIST_LIGHTNING , 0, 7, 4070},
{P_("monster", "Conjuror"), "Monsters\Mage\Mage%c.CL2", "Monsters\Mage\Mage%c%i.WAV", "Monsters\Magma\Wierd.TRN", 128, 1204, true, false, true, {12, 1, 20, 8, 28, 20}, {0, 0, 0, 0, 0, 0}, 24, 26, 27, 85, 85, AI_COUNSLR, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 1, 90, 8, 10, 24, 0, 0, 0, 0, 0, MonsterClass::Demon, RESIST_MAGIC | RESIST_LIGHTNING | IMMUNE_FIRE , RESIST_LIGHTNING | IMMUNE_MAGIC | IMMUNE_FIRE , 0, 7, 4478},
{P_("monster", "Sorcerer"), "Monsters\Mage\Mage%c.CL2", "Monsters\Mage\Mage%c%i.WAV", "Monsters\Scav\ScavBr.TRN", 128, 1204, true, false, true, {12, 1, 20, 8, 28, 20}, {0, 0, 0, 0, 0, 0}, 26, 30, 29, 120, 120, AI_COUNSLR, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 2, 100, 8, 14, 30, 0, 0, 0, 0, 0, MonsterClass::Demon, RESIST_MAGIC | RESIST_FIRE | IMMUNE_LIGHTNING , RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_LIGHTNING , 0, 7, 4929},
{P_("monster", "Cultist of Mordor"), "Monsters\Mage\Mage%c.CL2", "Monsters\Mage\Mage%c%i.WAV", "Monsters\Acid\AcidBlk.TRN", 128, 1807, true, false, true, {12, 1, 1, 8, 28, 20}, {0, 0, 0, 0, 0, 0}, 28, 30, 31, 160, 160, AI_COUNSLR, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 2, 120, 1, 30, 30, 120, 1, 30, 30, 0, MonsterClass::Undead, RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_LIGHTNING , RESIST_FIRE | IMMUNE_MAGIC | IMMUNE_LIGHTNING , 0, 7, 7000},
{P_("monster", "Golem"), "Monsters\Golem\Golem%c.CL2", "Monsters\Golem\Golm%c%i.WAV", nullptr, 96, 386, true, false, false, {0, 12, 12, 0, 12, 20}, {0, 0, 0, 0, 0, 0}, 0, 0, 12, 1, 1, AI_GOLUM, MFLAG_CAN_OPEN_DOOR , 0, 0, 7, 1, 1, 0, 0, 0, 0, 1, MonsterClass::Demon, RESIST_MAGIC | RESIST_FIRE | RESIST_LIGHTNING , RESIST_MAGIC | RESIST_FIRE | RESIST_LIGHTNING , 0, 0, 0},
{P_("monster", "Morgoth Bauglir"), "Monsters\Diablo\Diablo%c.CL2", "Monsters\Diablo\Diablo%c%i.WAV", "Monsters\Mega\Vtexl.TRN", 160, 1, true, true, true, {16, 6, 10, 1, 16, 11}, {0, 0, 0, 0, 0, 0}, 50, 50, 48, 2500, 2500, AI_DIABLO, MFLAG_KNOCKBACK | MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 5, 134, 4, 62, 62, 0, 9, 0, 0, 140, MonsterClass::Demon, RESIST_MAGIC | RESIST_LIGHTNING | IMMUNE_FIRE , RESIST_MAGIC | RESIST_LIGHTNING | IMMUNE_FIRE , 32768, 7, 31666},
{P_("monster", "Uruloki"), "Monsters\Snake\Snake%c.CL2", "Monsters\Mega\Mega%c%i.WAV", "Monsters\Zombie\Bluered.TRN", 160, 1, true, true, true, {12, 8, 11, 1, 18, 1}, {1, 0, 0, 0, 1, 0}, 85, 85, 30, 300, 300, AI_MEGA, MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR , 8, 130, 8, 35, 35, 130, 1, 35, 35, 130, MonsterClass::Demon, RESIST_MAGIC | RESIST_LIGHTNING | IMMUNE_FIRE , RESIST_MAGIC | RESIST_LIGHTNING | IMMUNE_FIRE , 0, 7, 5000},

/* MT_HELLBOAR*/ { P_("monster", "Hellboar"),                "Monsters\\Fork\\Fork%c.CL2",       "Monsters\\newsfx\\HBoar%c%i.WAV",   nullptr,                             188,    800, false,       false,       false,     { 10, 10, 15,  6, 16,  0 }, { 2, 1, 1, 1, 1, 1 },        32,       35,     23,     80,    100, AI_SKELSD,                   MFLAG_KNOCKBACK | MFLAG_SEARCH                      ,    2,   70,      7,         16,         24,     0,       0,           0,           0,          60, MonsterClass::Demon,    0                                                               ,                RESIST_FIRE | RESIST_LIGHTNING                     ,  3,                   0,          750 },
/* MT_STINGER */ { P_("monster", "Stinger"),                 "Monsters\\Scorp\\Scorp%c.CL2",     "Monsters\\newsfx\\Stingr%c%i.WAV",  nullptr,                              64,    305, false,       false,       false,     { 10, 10, 12,  6, 15,  0 }, { 2, 1, 1, 1, 1, 1 },        32,       35,     22,     30,     40, AI_SKELSD,    0                                                                  ,    3,   85,      8,          1,         20,     0,       0,           0,           0,          50, MonsterClass::Animal,   0                                                               ,                              RESIST_LIGHTNING                     ,  1,                   0,          500 },
/* MT_PSYCHORB*/ { P_("monster", "Psychorb"),                "Monsters\\Eye\\Eye%c.CL2",         "Monsters\\newsfx\\psyco%c%i.WAV",   nullptr,                             156,    800, false,       false,       false,     { 12, 13, 13,  7, 21,  0 }, { 2, 1, 1, 1, 1, 1 },        32,       35,     22,     20,     30, AI_PSYCHORB,  0                                                                  ,    3,   80,      8,         10,         10,     0,       0,           0,           0,          40, MonsterClass::Animal,   0                                                               ,                RESIST_FIRE                                        ,  6,                   0,          450 },
/* MT_ARACHNON*/ { P_("monster", "Arachnon"),                "Monsters\\Spider\\Spider%c.CL2",   "Monsters\\newsfx\\SLord%c%i.WAV",   nullptr,                             148,    800, false,       false,       false,     { 12, 10, 15,  6, 20,  0 }, { 2, 1, 1, 1, 1, 1 },        32,       35,     22,     60,     80, AI_SKELSD,                                     MFLAG_SEARCH                      ,    3,   50,      8,          5,         15,     0,       0,           0,           0,          50, MonsterClass::Animal,   0                                                               ,                              RESIST_LIGHTNING                     ,  7,                   0,          500 },
/* MT_FELLTWIN*/ { P_("monster", "Felltwin"),                "Monsters\\TSneak\\TSneak%c.CL2",   "Monsters\\newsfx\\FTwin%c%i.WAV",   nullptr,                             128,    800, false,       false,       false,     { 13, 13, 15, 11, 16,  0 }, { 2, 1, 1, 1, 1, 1 },        32,       35,     22,     50,     70, AI_SKELSD,                                     MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR,    3,   70,      8,         10,         18,     0,       0,           0,           0,          50, MonsterClass::Demon,                                                    IMMUNE_NULL_40  ,                RESIST_FIRE | RESIST_LIGHTNING | IMMUNE_NULL_40    ,  3,                   0,          600 },
/* MT_HORKSPWN*/ { P_("monster", "Hork Spawn"),              "Monsters\\Spawn\\Spawn%c.CL2",     "Monsters\\newsfx\\HSpawn%c%i.WAV",  nullptr,                             164,    520, false,       true,        false,     { 15, 12, 14, 11, 14,  0 }, { 1, 1, 1, 1, 1, 1 },        34,       37,     22,     30,     30, AI_SKELSD,    0                                                                  ,    3,   60,      8,         10,         25,     0,       0,           0,           0,          25, MonsterClass::Demon,    RESIST_MAGIC                                                    , RESIST_MAGIC                                                      ,  3,                   0,          250 },
/* MT_VENMTAIL*/ { P_("monster", "Venomtail"),               "Monsters\\WScorp\\WScorp%c.CL2",   "Monsters\\newsfx\\Stingr%c%i.WAV",  nullptr,                              86,    305, false,       false,       false,     { 10, 10, 12,  6, 15,  0 }, { 2, 1, 1, 1, 1, 1 },        36,       39,     24,     40,     50, AI_SKELSD,    0                                                                  ,    3,   85,      8,          1,         30,     0,       0,           0,           0,          60, MonsterClass::Animal,                                RESIST_LIGHTNING                   ,                              IMMUNE_LIGHTNING                     ,  1,                   0,         1000 },
/* MT_NECRMORB*/ { P_("monster", "Necromorb"),               "Monsters\\Eye2\\Eye2%c.CL2",       "Monsters\\newsfx\\Psyco%c%i.WAV",   nullptr,                             140,    800, false,       false,       false,     { 12, 13, 13,  7, 21,  0 }, { 2, 1, 1, 1, 1, 1 },        36,       39,     24,     30,     40, AI_NECROMORB, 0                                                                  ,    3,   80,      8,         20,         20,     0,       0,           0,           0,          50, MonsterClass::Animal,                  RESIST_FIRE                                      ,                IMMUNE_FIRE | RESIST_LIGHTNING                     ,  6,                   0,         1100 },
/* MT_SPIDLORD*/ { P_("monster", "Spider Lord"),             "Monsters\\bSpidr\\bSpidr%c.CL2",   "Monsters\\newsfx\\SLord%c%i.WAV",   nullptr,                             148,    800, true,        true,        false,     { 12, 10, 15,  6, 20, 10 }, { 2, 1, 1, 1, 1, 1 },        36,       39,     24,     80,    100, AI_ACID,                                       MFLAG_SEARCH                      ,    3,   60,      8,          8,         20,    75,       8,          10,          10,          60, MonsterClass::Animal,                                RESIST_LIGHTNING                   ,                RESIST_FIRE | IMMUNE_LIGHTNING                     ,  7,                   0,         1250 },
/* MT_LASHWORM*/ { P_("monster", "Lashworm"),                "Monsters\\Clasp\\Clasp%c.CL2",     "Monsters\\newsfx\\Lworm%c%i.WAV",   nullptr,                             176,    800, false,       false,       false,     { 10, 12, 15,  6, 16,  0 }, { 1, 1, 1, 1, 1, 1 },        36,       39,     20,     30,     30, AI_SKELSD,    0                                                                  ,    3,   90,      8,         12,         20,     0,       0,           0,           0,          50, MonsterClass::Animal,   0                                                               ,                RESIST_FIRE                                        ,  3,                   0,          600 },
/* MT_TORCHANT*/ { P_("monster", "Torchant"),                "Monsters\\AntWorm\\Worm%c.CL2",    "Monsters\\newsfx\\TchAnt%c%i.WAV",  nullptr,                             192,    800, false,       false,       false,     { 14, 12, 12,  6, 20,  0 }, { 2, 1, 1, 1, 1, 1 },        36,       39,     22,     60,     80, AI_TORCHANT,  0                                                                  ,    3,   75,      8,         20,         30,     0,       0,           0,           0,          70, MonsterClass::Animal,                  IMMUNE_FIRE                                      , RESIST_MAGIC | IMMUNE_FIRE | RESIST_LIGHTNING                     ,  7,                   0,         1250 },
/* MT_HORKDMN */ { P_("monster", "Hork Demon"),              "Monsters\\HorkD\\HorkD%c.CL2",     "Monsters\\newsfx\\HDemon%c%i.WAV",  nullptr,                             138,    800, true,        true,        false,     { 15,  8, 16,  6, 16,  9 }, { 2, 1, 1, 1, 1, 2 },        36,       37,     27,    120,    160, AI_SKELSD,    0                                                                  ,    3,   60,      8,         20,         35,    80,       8,           0,           0,          80, MonsterClass::Demon,                                 RESIST_LIGHTNING                   , RESIST_MAGIC |               IMMUNE_LIGHTNING                     ,  7,                   0,         2000 },
/* MT_DEFILER */ { P_("monster", "Hell Bug"),                "Monsters\\Hellbug\\Hellbg%c.CL2",  "Monsters\\newsfx\\Defile%c%i.WAV",  nullptr,                             198,    800, true,        true,        false,     {  8,  8, 14,  6, 14, 12 }, { 1, 1, 1, 1, 1, 1 },        38,       39,     30,    240,    240, AI_SKELSD,                                     MFLAG_SEARCH                      ,    3,  110,      8,         20,         30,    90,       8,          50,          60,          80, MonsterClass::Demon,    RESIST_MAGIC | RESIST_FIRE | IMMUNE_LIGHTNING                   , RESIST_MAGIC | IMMUNE_FIRE | IMMUNE_LIGHTNING                     ,  7,                   0,         5000 },
/* MT_GRAVEDIG*/ { P_("monster", "Gravedigger"),             "Monsters\\Gravdg\\Gravdg%c.CL2",   "Monsters\\newsfx\\GDiggr%c%i.WAV",  nullptr,                             124,    800, true,        true,        false,     { 24, 24, 12,  6, 16, 16 }, { 2, 1, 1, 1, 1, 1 },        40,       41,     26,    120,    240, AI_SCAV,                                                      MFLAG_CAN_OPEN_DOOR,    3,   80,      6,          2,         12,     0,       0,           0,           0,          20, MonsterClass::Undead,                                IMMUNE_LIGHTNING  | IMMUNE_NULL_40 , RESIST_MAGIC | RESIST_FIRE | IMMUNE_LIGHTNING | IMMUNE_NULL_40    ,  3,                   0,         2000 },
/* MT_TOMBRAT */ { P_("monster", "Tomb Rat"),                "Monsters\\Rat\\Rat%c.CL2",         "Monsters\\newsfx\\TmbRat%c%i.WAV",  nullptr,                             104,    550, false,       false,       false,     { 11,  8, 12,  6, 20,  0 }, { 2, 1, 1, 1, 1, 1 },        40,       43,     24,     80,    120, AI_SKELSD,    0                                                                  ,    3,  120,      8,         12,         25,     0,       0,           0,           0,          30, MonsterClass::Animal,   0                                                               ,                RESIST_FIRE | RESIST_LIGHTNING                     ,  3,                   0,         1800 },
/* MT_FIREBAT */ { P_("monster", "Firebat"),                 "Monsters\\Hellbat\\Helbat%c.CL2",  "Monsters\\newsfx\\HelBat%c%i.WAV",  nullptr,                              96,    550, false,       false,       false,     { 18, 16, 14,  6, 18, 11 }, { 2, 1, 1, 1, 1, 1 },        40,       43,     24,     60,     80, AI_FIREBAT,   0                                                                  ,    3,  100,      8,         15,         20,     0,       0,           0,           0,          70, MonsterClass::Animal,                  IMMUNE_FIRE                                      , RESIST_MAGIC | IMMUNE_FIRE | RESIST_LIGHTNING                     ,  7,                   0,         2400 },
/* MT_SKLWING */ { P_("monster", "Skullwing"),               "Monsters\\Demskel\\Demskl%c.CL2",  "Monsters\\newsfx\\SWing%c%i.WAV",   "Monsters\\Thin\\Thinv3.TRN",        128,   1740, true,        false,       false,     { 10,  8, 20,  6, 24, 16 }, { 3, 1, 1, 1, 1, 1 },        40,       43,     27,     70,     70, AI_SKELSD,    0                                                                  ,    0,   75,      7,         15,         20,    75,       9,          15,          20,          80, MonsterClass::Undead,                  RESIST_FIRE | RESIST_LIGHTNING | IMMUNE_NULL_40  ,                RESIST_FIRE | RESIST_LIGHTNING | IMMUNE_NULL_40    ,  7,                   0,         3000 },
/* MT_LICH    */ { P_("monster", "Lich"),                    "Monsters\\Lich\\Lich%c.CL2",       "Monsters\\newsfx\\Lich%c%i.WAV",    nullptr,                              96,    800, false,       true,        false,     { 12, 10, 10,  7, 21,  0 }, { 2, 1, 1, 1, 2, 1 },        40,       43,     25,     80,    100, AI_LICH,      0                                                                  ,    3,  100,      8,         15,         20,     0,       0,           0,           0,          60, MonsterClass::Undead,                                RESIST_LIGHTNING | IMMUNE_NULL_40  , RESIST_MAGIC | RESIST_FIRE | IMMUNE_LIGHTNING | IMMUNE_NULL_40    ,  3,                   0,         3000 },
/* MT_CRYPTDMN*/ { P_("monster", "Crypt Demon"),             "Monsters\\Bubba\\Bubba%c.CL2",     "Monsters\\newsfx\\Crypt%c%i.WAV",   nullptr,                             154,    800, false,       true,        false,     {  8, 18, 12,  8, 21,  0 }, { 3, 1, 1, 1, 1, 1 },        42,       45,     28,    200,    240, AI_SKELSD,    0                                                                  ,    3,  100,      8,         20,         40,     0,       0,           0,           0,          85, MonsterClass::Demon,    IMMUNE_MAGIC | RESIST_FIRE | RESIST_LIGHTNING                   , IMMUNE_MAGIC | IMMUNE_FIRE | RESIST_LIGHTNING                     ,  3,                   0,         3200 },
/* MT_HELLBAT */ { P_("monster", "Hellbat"),                 "Monsters\\Hellbat2\\bhelbt%c.CL2", "Monsters\\newsfx\\HelBat%c%i.WAV",  nullptr,                              96,    550, true,        false,       false,     { 18, 16, 14,  6, 18, 11 }, { 2, 1, 1, 1, 1, 1 },        44,       47,     29,    100,    140, AI_TORCHANT,  0                                                                  ,    3,  110,      8,         30,         30,     0,       0,           0,           0,          80, MonsterClass::Demon,    RESIST_MAGIC | IMMUNE_FIRE  | RESIST_LIGHTNING                  , RESIST_MAGIC | IMMUNE_FIRE | IMMUNE_LIGHTNING                     ,  7,                   0,         3600 },
/* MT_BONEDEMN*/ { P_("monster", "Bone Demon"),              "Monsters\\Demskel\\Demskl%c.CL2",  "Monsters\\newsfx\\SWing%c%i.WAV",   "Monsters\\Thin\\Thinv3.TRN",        128,   1740, true,        true,        false,     { 10,  8, 20,  6, 24, 16 }, { 3, 1, 1, 1, 1, 1 },        44,       47,     30,    240,    280, AI_BONEDEMON, 0                                                                  ,    0,  100,      8,         40,         50,   160,      12,          50,          50,          50, MonsterClass::Undead,                  IMMUNE_FIRE  | IMMUNE_LIGHTNING | IMMUNE_NULL_40 ,                IMMUNE_FIRE | IMMUNE_LIGHTNING | IMMUNE_NULL_40    ,  7,                   0,         5000 },
/* MT_ARCHLICH*/ { P_("monster", "Arch Lich"),               "Monsters\\Lich2\\Lich2%c.CL2",     "Monsters\\newsfx\\Lich%c%i.WAV",    nullptr,                             136,    800, false,       true,        false,     { 12, 10, 10,  7, 21,  0 }, { 2, 1, 1, 1, 2, 1 },        44,       47,     30,    180,    200, AI_ARCHLICH,  0                                                                  ,    3,  120,      8,         30,         30,     0,       0,           0,           0,          75, MonsterClass::Undead,   RESIST_MAGIC | RESIST_FIRE | IMMUNE_LIGHTNING  | IMMUNE_NULL_40 , IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_LIGHTNING | IMMUNE_NULL_40    ,  3,                   0,         4000 },
/* MT_BICLOPS */ { P_("monster", "Biclops"),                 "Monsters\\Byclps\\Byclps%c.CL2",   "Monsters\\newsfx\\Biclop%c%i.WAV",  nullptr,                             180,    800, false,       false,       false,     { 10, 11, 16,  6, 16,  0 }, { 2, 1, 1, 1, 2, 1 },        44,       47,     30,    200,    240, AI_SKELSD,                   MFLAG_KNOCKBACK |                MFLAG_CAN_OPEN_DOOR,    3,   90,      8,         40,         50,     0,       0,           0,           0,          80, MonsterClass::Demon,                                 RESIST_LIGHTNING                   ,                RESIST_FIRE | RESIST_LIGHTNING                     ,  3,                   0,         4000 },
/* MT_FLESTHNG*/ { P_("monster", "Flesh Thing"),             "Monsters\\Flesh\\Flesh%c.CL2",     "Monsters\\newsfx\\FleshT%c%i.WAV",  nullptr,                             164,    800, false,       true,        false,     { 15, 24, 15,  6, 16,  0 }, { 1, 1, 1, 1, 1, 1 },        44,       47,     28,    300,    400, AI_SKELSD,    0                                                                  ,    3,  150,      8,         12,         18,     0,       0,           0,           0,          70, MonsterClass::Demon,    RESIST_MAGIC | RESIST_FIRE | RESIST_LIGHTNING                   , RESIST_MAGIC | RESIST_FIRE | RESIST_LIGHTNING                     ,  3,                   0,         4000 },
/* MT_REAPER  */ { P_("monster", "Reaper"),                  "Monsters\\Reaper\\Reap%c.CL2",     "Monsters\\newsfx\\Reaper%c%i.WAV",  nullptr,                             180,    800, false,       false,       false,     { 12, 10, 14,  6, 16,  0 }, { 2, 1, 1, 1, 1, 1 },        44,       47,     30,    260,    300, AI_SKELSD,    0                                                                  ,    3,  120,      8,         30,         35,     0,       0,           0,           0,          90, MonsterClass::Demon,    IMMUNE_MAGIC | IMMUNE_FIRE  | RESIST_LIGHTNING                  , IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_LIGHTNING                     ,  3,                   0,         6000 },
// TRANSLATORS: Monster Block end
/* MT_NAKRUL  */ { P_("monster", "Na-Krul"),                 "Monsters\\Nkr\\Nkr%c.CL2",         "Monsters\\newsfx\\Nakrul%c%i.WAV",  nullptr,                             226,   1200, true,        true,        false,     {  2,  6, 16,  3, 16, 16 }, { 0, 0, 0, 0, 0, 0 },        60,       60,     40,   1332,   1332, AI_SKELSD,                   MFLAG_KNOCKBACK | MFLAG_SEARCH | MFLAG_CAN_OPEN_DOOR,    3,  150,      7,         40,         50,   150,      10,          40,          50,         125, MonsterClass::Demon,    IMMUNE_MAGIC | IMMUNE_FIRE  | RESIST_LIGHTNING | IMMUNE_NULL_40 , IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_LIGHTNING | IMMUNE_NULL_40    ,  7,                   0,        13333 },
	// clang-format on
};

/**
 * Map between .DUN file value and monster type enum
 */
const _monster_id MonstConvTbl[] = {
	MT_NZOMBIE,
	MT_BZOMBIE,
	MT_GZOMBIE,
	MT_YZOMBIE,
	MT_RFALLSP,
	MT_DFALLSP,
	MT_YFALLSP,
	MT_BFALLSP,
	MT_WSKELAX,
	MT_TSKELAX,
	MT_RSKELAX,
	MT_XSKELAX,
	MT_RFALLSD,
	MT_DFALLSD,
	MT_YFALLSD,
	MT_BFALLSD,
	MT_NSCAV,
	MT_BSCAV,
	MT_WSCAV,
	MT_YSCAV,
	MT_WSKELBW,
	MT_TSKELBW,
	MT_RSKELBW,
	MT_XSKELBW,
	MT_WSKELSD,
	MT_TSKELSD,
	MT_RSKELSD,
	MT_XSKELSD,
	MT_SNEAK,
	MT_STALKER,
	MT_UNSEEN,
	MT_ILLWEAV,
	MT_NGOATMC,
	MT_BGOATMC,
	MT_RGOATMC,
	MT_GGOATMC,
	MT_FIEND,
	MT_GLOOM,
	MT_BLINK,
	MT_FAMILIAR,
	MT_NGOATBW,
	MT_BGOATBW,
	MT_RGOATBW,
	MT_GGOATBW,
	MT_NACID,
	MT_RACID,
	MT_BACID,
	MT_XACID,
	MT_SKING,
	MT_FAT,
	MT_MUDMAN,
	MT_TOAD,
	MT_FLAYED,
	MT_WYRM,
	MT_CAVSLUG,
	MT_DEVOUR,
	MT_DVLWYRM,
	MT_NMAGMA,
	MT_YMAGMA,
	MT_BMAGMA,
	MT_WMAGMA,
	MT_HORNED,
	MT_MUDRUN,
	MT_FROSTC,
	MT_OBLORD,
	MT_BONEDMN,
	MT_REDDTH,
	MT_LTCHDMN,
	MT_UDEDBLRG,
	MT_INVALID,
	MT_INVALID,
	MT_INVALID,
	MT_INVALID,
	MT_INCIN,
	MT_FLAMLRD,
	MT_DOOMFIRE,
	MT_HELLBURN,
	MT_INVALID,
	MT_INVALID,
	MT_INVALID,
	MT_INVALID,
	MT_RSTORM,
	MT_STORM,
	MT_STORML,
	MT_MAEL,
	MT_WINGED,
	MT_GARGOYLE,
	MT_BLOODCLW,
	MT_DEATHW,
	MT_MEGA,
	MT_GUARD,
	MT_VTEXLRD,
	MT_BALROG,
	MT_NSNAKE,
	MT_RSNAKE,
	MT_GSNAKE,
	MT_BSNAKE,
	MT_NBLACK,
	MT_RTBLACK,
	MT_BTBLACK,
	MT_RBLACK,
	MT_UNRAV,
	MT_HOLOWONE,
	MT_PAINMSTR,
	MT_REALWEAV,
	MT_SUCCUBUS,
	MT_SNOWWICH,
	MT_HLSPWN,
	MT_SOLBRNR,
	MT_COUNSLR,
	MT_MAGISTR,
	MT_CABALIST,
	MT_ADVOCATE,
	MT_INVALID,
	MT_DIABLO,
	MT_INVALID,
	MT_GOLEM,
	MT_INVALID,
	MT_INVALID,
	MT_INVALID, // Monster from blood1.dun and blood2.dun
	MT_INVALID,
	MT_INVALID,
	MT_INVALID,
	MT_INVALID, // Snotspill from banner2.dun
	MT_INVALID,
	MT_INVALID,
	MT_BIGFALL,
	MT_DARKMAGE,
	MT_HELLBOAR,
	MT_STINGER,
	MT_PSYCHORB,
	MT_ARACHNON,
	MT_FELLTWIN,
	MT_HORKSPWN,
	MT_STINGER,
	MT_PSYCHORB,
	MT_ARACHNON,
	MT_LASHWORM,
	MT_TORCHANT,
	MT_HORKDMN,
	MT_DEFILER,
	MT_GRAVEDIG,
	MT_TOMBRAT,
	MT_FIREBAT,
	MT_SKLWING,
	MT_LICH,
	MT_CRYPTDMN,
	MT_FIREBAT,
	MT_SKLWING,
	MT_LICH,
	MT_BICLOPS,
	MT_FLESTHNG,
	MT_REAPER,
	MT_NAKRUL,
	MT_CLEAVER,
	MT_INVILORD,
	MT_LRDSAYTR,
};

/**
 * Define what version a monster type is available in
 */
const char MonstAvailTbl[] = {
	MAT_ALWAYS, // Zombie
	MAT_ALWAYS, // Ghoul
	MAT_ALWAYS, // Rotting Carcass
	MAT_ALWAYS, // Black Death
	MAT_ALWAYS, // Fallen One
	MAT_ALWAYS, // Carver
	MAT_ALWAYS, // Devil Kin
	MAT_ALWAYS, // Dark One
	MAT_ALWAYS, // Skeleton
	MAT_ALWAYS, // Corpse Axe
	MAT_ALWAYS, // Burning Dead
	MAT_ALWAYS, // Horror
	MAT_ALWAYS, // Fallen One
	MAT_ALWAYS, // Carver
	MAT_ALWAYS, // Devil Kin
	MAT_ALWAYS, // Dark One
	MAT_ALWAYS, // Scavenger
	MAT_ALWAYS, // Plague Eater
	MAT_ALWAYS, // Shadow Beast
	MAT_ALWAYS, // Bone Gasher
	MAT_ALWAYS, // Skeleton
	MAT_ALWAYS, // Corpse Bow
	MAT_ALWAYS, // Burning Dead
	MAT_ALWAYS, // Horror
	MAT_ALWAYS, // Skeleton Captain
	MAT_ALWAYS, // Corpse Captain
	MAT_ALWAYS, // Burning Dead Captain
	MAT_ALWAYS, // Horror Captain
	MAT_NEVER,  // Invisible Lord
	MAT_RETAIL, // Hidden
	MAT_RETAIL, // Stalker
	MAT_RETAIL, // Unseen
	MAT_RETAIL, // Illusion Weaver
	MAT_RETAIL, // Satyr Lord
	MAT_RETAIL, // Flesh Clan
	MAT_RETAIL, // Stone Clan
	MAT_RETAIL, // Fire Clan
	MAT_RETAIL, // Night Clan
	MAT_ALWAYS, // Fiend
	MAT_ALWAYS, // Blink
	MAT_ALWAYS, // Gloom
	MAT_ALWAYS, // Familiar
	MAT_RETAIL, // Flesh Clan
	MAT_RETAIL, // Stone Clan
	MAT_RETAIL, // Fire Clan
	MAT_RETAIL, // Night Clan
	MAT_RETAIL, // Acid Beast
	MAT_RETAIL, // Poison Spitter
	MAT_RETAIL, // Pit Beast
	MAT_RETAIL, // Lava Maw
	MAT_NEVER,  // Skeleton King
	MAT_NEVER,  // The Butcher
	MAT_RETAIL, // Overlord
	MAT_RETAIL, // Mud Man
	MAT_RETAIL, // Toad Demon
	MAT_RETAIL, // Flayed One
	MAT_NEVER,  // Wyrm
	MAT_NEVER,  // Cave Slug
	MAT_NEVER,  // Devil Wyrm
	MAT_NEVER,  // Devourer
	MAT_RETAIL, // Magma Demon
	MAT_RETAIL, // Blood Stone
	MAT_RETAIL, // Hell Stone
	MAT_RETAIL, // Lava Lord
	MAT_RETAIL, // Horned Demon
	MAT_RETAIL, // Mud Runner
	MAT_RETAIL, // Frost Charger
	MAT_RETAIL, // Obsidian Lord
	MAT_NEVER,  // Bone Demon (oldboned in Hellfire)
	MAT_NEVER,  // Red Death
	MAT_NEVER,  // Litch Demon
	MAT_NEVER,  // Undead Balrog
	MAT_NEVER,  // Incinerator
	MAT_NEVER,  // Flame Lord
	MAT_NEVER,  // Doom Fire
	MAT_NEVER,  // Hell Burner
	MAT_RETAIL, // Red Storm
	MAT_RETAIL, // Storm Rider
	MAT_RETAIL, // Storm Lord
	MAT_RETAIL, // Maelstorm
	MAT_RETAIL, // Devil Kin Brute
	MAT_RETAIL, // Winged-Demon
	MAT_RETAIL, // Gargoyle
	MAT_RETAIL, // Blood Claw
	MAT_RETAIL, // Death Wing
	MAT_RETAIL, // Slayer
	MAT_RETAIL, // Guardian
	MAT_RETAIL, // Vortex Lord
	MAT_RETAIL, // Balrog
	MAT_RETAIL, // Cave Viper
	MAT_RETAIL, // Fire Drake
	MAT_RETAIL, // Gold Viper
	MAT_RETAIL, // Azure Drake
	MAT_RETAIL, // Black Knight
	MAT_RETAIL, // Doom Guard
	MAT_RETAIL, // Steel Lord
	MAT_RETAIL, // Blood Knight
	MAT_RETAIL, // The Shredded
	MAT_NEVER,  // Hollow One
	MAT_NEVER,  // Pain Master
	MAT_NEVER,  // Reality Weaver
	MAT_RETAIL, // Succubus
	MAT_RETAIL, // Snow Witch
	MAT_RETAIL, // Hell Spawn
	MAT_RETAIL, // Soul Burner
	MAT_RETAIL, // Counselor
	MAT_RETAIL, // Magistrate
	MAT_RETAIL, // Cabalist
	MAT_RETAIL, // Advocate
	MAT_NEVER,  // Golem
	MAT_NEVER,  // The Dark Lord
	MAT_NEVER,  // The Arch-Litch Malignus
	MAT_RETAIL, // Hellboar
	MAT_RETAIL, // Stinger
	MAT_RETAIL, // Psychorb
	MAT_RETAIL, // Arachnon
	MAT_RETAIL, // Felltwin
	MAT_RETAIL, // Hork Spawn
	MAT_RETAIL, // Venomtail
	MAT_RETAIL, // Necromorb
	MAT_RETAIL, // Spider Lord
	MAT_RETAIL, // Lashworm
	MAT_RETAIL, // Torchant
	MAT_NEVER,  // Hork Demon
	MAT_NEVER,  // Hell Bug
	MAT_RETAIL, // Gravedigger
	MAT_RETAIL, // Tomb Rat
	MAT_RETAIL, // Firebat
	MAT_RETAIL, // Skullwing
	MAT_RETAIL, // Lich
	MAT_RETAIL, // Crypt Demon
	MAT_RETAIL, // Hellbat
	MAT_RETAIL, // Bone Demon
	MAT_RETAIL, // Arch Lich
	MAT_RETAIL, // Biclops
	MAT_RETAIL, // Flesh Thing
	MAT_RETAIL, // Reaper
	MAT_NEVER,  // Na-Krul
};
/** Contains the data related to each unique monster ID. */
const UniqueMonsterData UniqueMonstersData[] = {
	// clang-format off
	// mtype,       mName,                          mTrnName,    mlevel, mmaxhp, mAi,      mint, mMinDamage, mMaxDamage, mMagicRes,                                                    monsterPack, customHitpoints, customArmorClass, mtalkmsg
	// TRANSLATORS: Unique Monster Block start
	{  MT_NGOATMC,  P_("monster", "Gharbad the Weak"),         "BSDB",        4,    120, AI_GARBUD,   3,          8,         16,                              IMMUNE_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::None,        0,        0, TEXT_GARBUD1   },
	{  MT_SKING,    P_("monster", "Skeleton King"),            "GENRL",       0,    240, AI_SKELKING, 3,          6,         16, IMMUNE_MAGIC | RESIST_FIRE | RESIST_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::Independent, 0,        0, TEXT_NONE      },
	{  MT_COUNSLR,  P_("monster", "Zhar the Mad"),             "GENERAL",     8,    360, AI_ZHAR,     3,         16,         40, IMMUNE_MAGIC | RESIST_FIRE | RESIST_LIGHTNING                 ,  UniqueMonsterPack::None,        0,        0, TEXT_ZHAR1     },
	{  MT_BFALLSP,  P_("monster", "Snotspill"),                "BNG",         4,    220, AI_SNOTSPIL, 3,         10,         18,                              RESIST_LIGHTNING                 ,  UniqueMonsterPack::None,        0,        0, TEXT_BANNER10  },
	{  MT_ADVOCATE, P_("monster", "Arch-Bishop Lazarus"),      "GENERAL",     0,    600, AI_LAZARUS,  3,         30,         50, IMMUNE_MAGIC | RESIST_FIRE | RESIST_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::None,        0,        0, TEXT_VILE13    },
	{  MT_HLSPWN,   P_("monster", "Red Vex"),                  "REDV",        0,    400, AI_LAZHELP,  3,         30,         50, IMMUNE_MAGIC | RESIST_FIRE |                    IMMUNE_NULL_40,  UniqueMonsterPack::None,        0,        0, TEXT_VILE13    },
	{  MT_HLSPWN,   P_("monster", "Black Jade"),               "BLKJD",       0,    400, AI_LAZHELP,  3,         30,         50, IMMUNE_MAGIC |               RESIST_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::None,        0,        0, TEXT_VILE13    },
	{  MT_RBLACK,   P_("monster", "Lachdanan"),                "BHKA",       14,    500, AI_LACHDAN,  3,          0,          0, 0                                                             ,  UniqueMonsterPack::None,        0,        0, TEXT_VEIL9     },
	{  MT_BTBLACK,  P_("monster", "Warlord of Blood"),         "GENERAL",    13,    850, AI_WARLORD,  3,         35,         50, IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::None,        0,        0, TEXT_WARLRD9   },
	{  MT_CLEAVER,  P_("monster", "The Butcher"),              "GENRL",       0,    220, AI_CLEAVER,  3,          6,         12,                RESIST_FIRE | RESIST_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::None,        0,        0, TEXT_NONE      },
	{  MT_HORKDMN,  P_("monster", "Hork Demon"),               "GENRL",      19,    300, AI_HORKDMN,  3,         20,         35,                              RESIST_LIGHTNING                 ,  UniqueMonsterPack::None,        0,        0, TEXT_NONE      },
	{  MT_DEFILER,  P_("monster", "The Defiler"),              "GENRL",      20,    480, AI_SKELSD,   3,         30,         40, RESIST_MAGIC | RESIST_FIRE | IMMUNE_LIGHTNING                 ,  UniqueMonsterPack::None,        0,        0, TEXT_NONE      },
	{  MT_NAKRUL,   P_("monster", "Na-Krul"),                  "GENRL",       0,   1332, AI_SKELSD,   3,         40,         50, IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_TSKELAX,  P_("monster", "Bonehead Keenaxe"),         "BHKA",        2,     91, AI_SKELSD,   2,          4,         10, IMMUNE_MAGIC |                                  IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,   100,        0, TEXT_NONE      },
	{  MT_RFALLSD,  P_("monster", "Bladeskin the Slasher"),    "BSTS",        2,     51, AI_FALLEN,   0,          6,         18,                RESIST_FIRE                                    ,  UniqueMonsterPack::Leashed,     0,       45, TEXT_NONE      },
	{  MT_NZOMBIE,  P_("monster", "Soulpus"),                  "GENERAL",     2,    133, AI_ZOMBIE,   0,          4,          8,                RESIST_FIRE | RESIST_LIGHTNING                 ,  UniqueMonsterPack::None,        0,        0, TEXT_NONE      },
	{  MT_RFALLSP,  P_("monster", "Pukerat the Unclean"),      "PTU",         2,     77, AI_FALLEN,   3,          1,          5,                RESIST_FIRE                                    ,  UniqueMonsterPack::None,        0,        0, TEXT_NONE      },
	{  MT_WSKELAX,  P_("monster", "Boneripper"),               "BR",          2,     54, AI_BAT,      0,          6,         15, IMMUNE_MAGIC | IMMUNE_FIRE |                    IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_NZOMBIE,  P_("monster", "Rotfeast the Hungry"),      "ETH",         2,     85, AI_SKELSD,   3,          4,         12, IMMUNE_MAGIC |                                  IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_DFALLSD,  P_("monster", "Gutshank the Quick"),       "GTQ",         3,     66, AI_BAT,      2,          6,         16,                RESIST_FIRE                                    ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_TSKELSD,  P_("monster", "Brokenhead Bangshield"),    "BHBS",        3,    108, AI_SKELSD,   3,         12,         20, IMMUNE_MAGIC |               RESIST_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_YFALLSP,  P_("monster", "Bongo"),                    "BNG",         3,    178, AI_FALLEN,   3,          9,         21, 0                                                             ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_BZOMBIE,  P_("monster", "Rotcarnage"),               "RCRN",        3,    102, AI_ZOMBIE,   3,          9,         24, IMMUNE_MAGIC |               RESIST_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,       45, TEXT_NONE      },
	{  MT_NSCAV,    P_("monster", "Shadowbite"),               "SHBT",        2,     60, AI_SKELSD,   3,          3,         20,                IMMUNE_FIRE                                    ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_WSKELBW,  P_("monster", "Deadeye"),                  "DE",          2,     49, AI_GOATBOW,  0,          6,          9, IMMUNE_MAGIC | RESIST_FIRE |                    IMMUNE_NULL_40,  UniqueMonsterPack::None,        0,        0, TEXT_NONE      },
	{  MT_RSKELAX,  P_("monster", "Madeye the Dead"),          "MTD",         4,     75, AI_BAT,      0,          9,         21, IMMUNE_MAGIC | IMMUNE_FIRE                                    ,  UniqueMonsterPack::Leashed,     0,       30, TEXT_NONE      },
	{  MT_BSCAV,    P_("monster", "El Chupacabras"),           "GENERAL",     3,    120, AI_GOATMC,   0,         10,         18,                RESIST_FIRE                                    ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_TSKELBW,  P_("monster", "Skullfire"),                "SKFR",        3,    125, AI_GOATBOW,  1,          6,         10,                IMMUNE_FIRE                                    ,  UniqueMonsterPack::None,        0,        0, TEXT_NONE      },
	{  MT_SNEAK,    P_("monster", "Warpskull"),                "TSPO",        3,    117, AI_SNEAK,    2,          6,         18,                RESIST_FIRE | RESIST_LIGHTNING                 ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_GZOMBIE,  P_("monster", "Goretongue"),               "PMR",         3,    156, AI_SKELSD,   1,         15,         30, IMMUNE_MAGIC |                                  IMMUNE_NULL_40,  UniqueMonsterPack::None,        0,        0, TEXT_NONE      },
	{  MT_WSCAV,    P_("monster", "Pulsecrawler"),             "BHKA",        4,    150, AI_SCAV,     0,         16,         20,                IMMUNE_FIRE | RESIST_LIGHTNING                 ,  UniqueMonsterPack::Leashed,     0,       45, TEXT_NONE      },
	{  MT_BLINK,    P_("monster", "Moonbender"),               "GENERAL",     4,    135, AI_BAT,      0,          9,         27,                IMMUNE_FIRE                                    ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_BLINK,    P_("monster", "Wrathraven"),               "GENERAL",     5,    135, AI_BAT,      2,          9,         22,                IMMUNE_FIRE                                    ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_YSCAV,    P_("monster", "Spineeater"),               "GENERAL",     4,    180, AI_SCAV,     1,         18,         25,                              IMMUNE_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_RSKELBW,  P_("monster", "Blackash the Burning"),     "BASHTB",      4,    120, AI_GOATBOW,  0,          6,         16, IMMUNE_MAGIC | IMMUNE_FIRE                                    ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_BFALLSD,  P_("monster", "Shadowcrow"),               "GENERAL",     5,    270, AI_SNEAK,    2,         12,         25, 0                                                             ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_LRDSAYTR, P_("monster", "Blightstone the Weak"),     "BHKA",        4,    360, AI_SKELSD,   0,          4,         12, IMMUNE_MAGIC |               RESIST_LIGHTNING                 ,  UniqueMonsterPack::Leashed,    70,        0, TEXT_NONE      },
	{  MT_FAT,      P_("monster", "Bilefroth the Pit Master"), "BFTP",        6,    210, AI_BAT,      1,         16,         23, IMMUNE_MAGIC | IMMUNE_FIRE | RESIST_LIGHTNING                 ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_NGOATBW,  P_("monster", "Bloodskin Darkbow"),        "BSDB",        5,    207, AI_GOATBOW,  0,          3,         16,                RESIST_FIRE | RESIST_LIGHTNING                 ,  UniqueMonsterPack::Leashed,     0,       55, TEXT_NONE      },
	{  MT_GLOOM,    P_("monster", "Foulwing"),                 "DB",          5,    246, AI_RHINO,    3,         12,         28,                RESIST_FIRE                                    ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_XSKELSD,  P_("monster", "Shadowdrinker"),            "SHDR",        5,    300, AI_SNEAK,    1,         18,         26, IMMUNE_MAGIC | RESIST_FIRE | RESIST_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::None,        0,       45, TEXT_NONE      },
	{  MT_UNSEEN,   P_("monster", "Hazeshifter"),              "BHKA",        5,    285, AI_SNEAK,    3,         18,         30,                              IMMUNE_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_NACID,    P_("monster", "Deathspit"),                "BFDS",        6,    303, AI_ACIDUNIQ, 0,         12,         32,                RESIST_FIRE | RESIST_LIGHTNING                 ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_RGOATMC,  P_("monster", "Bloodgutter"),              "BGBL",        6,    315, AI_BAT,      1,         24,         34,                IMMUNE_FIRE                                    ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_BGOATMC,  P_("monster", "Deathshade Fleshmaul"),     "DSFM",        6,    276, AI_RHINO,    0,         12,         24, IMMUNE_MAGIC | RESIST_FIRE                                    ,  UniqueMonsterPack::None,        0,       65, TEXT_NONE      },
	{  MT_WYRM,     P_("monster", "Warmaggot the Mad"),        "GENERAL",     6,    246, AI_BAT,      3,         15,         30,                              RESIST_LIGHTNING                 ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_STORM,    P_("monster", "Glasskull the Jagged"),     "BHKA",        7,    354, AI_STORM,    0,         18,         30, IMMUNE_MAGIC | IMMUNE_FIRE |                    IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_RGOATBW,  P_("monster", "Blightfire"),               "BLF",         7,    321, AI_SUCC,     2,         13,         21,                IMMUNE_FIRE                                    ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_GARGOYLE, P_("monster", "Nightwing the Cold"),       "GENERAL",     7,    342, AI_BAT,      1,         18,         26, IMMUNE_MAGIC |               RESIST_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_GGOATBW,  P_("monster", "Gorestone"),                "GENERAL",     7,    303, AI_GOATBOW,  1,         15,         28,                              RESIST_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,    70,        0, TEXT_NONE      },
	{  MT_BMAGMA,   P_("monster", "Bronzefist Firestone"),     "GENERAL",     8,    360, AI_MAGMA,    0,         30,         36, IMMUNE_MAGIC | RESIST_FIRE                                    ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_INCIN,    P_("monster", "Wrathfire the Doomed"),     "WFTD",        8,    270, AI_SKELSD,   2,         20,         30, IMMUNE_MAGIC | RESIST_FIRE |  RESIST_LIGHTNING                ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_NMAGMA,   P_("monster", "Firewound the Grim"),       "BHKA",        8,    303, AI_MAGMA,    0,         18,         22, IMMUNE_MAGIC | RESIST_FIRE                                    ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_MUDMAN,   P_("monster", "Baron Sludge"),             "BSM",         8,    315, AI_SNEAK,    3,         25,         34, IMMUNE_MAGIC | RESIST_FIRE | RESIST_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,       75, TEXT_NONE      },
	{  MT_GGOATMC,  P_("monster", "Blighthorn Steelmace"),     "BHSM",        7,    250, AI_RHINO,    0,         20,         28,                              RESIST_LIGHTNING                 ,  UniqueMonsterPack::Leashed,     0,       45, TEXT_NONE      },
	{  MT_RACID,    P_("monster", "Chaoshowler"),              "GENERAL",     8,    240, AI_ACIDUNIQ, 0,         12,         20, 0                                                             ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_REDDTH,   P_("monster", "Doomgrin the Rotting"),     "GENERAL",     8,    405, AI_STORM,    3,         25,         50, IMMUNE_MAGIC | RESIST_FIRE | RESIST_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_FLAMLRD,  P_("monster", "Madburner"),                "GENERAL",     9,    270, AI_STORM,    0,         20,         40, IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_LIGHTNING                 ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_LTCHDMN,  P_("monster", "Bonesaw the Litch"),        "GENERAL",     9,    495, AI_STORM,    2,         30,         55, IMMUNE_MAGIC | RESIST_FIRE | RESIST_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_MUDRUN,   P_("monster", "Breakspine"),               "GENERAL",     9,    351, AI_RHINO,    0,         25,         34,                RESIST_FIRE                                    ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_REDDTH,   P_("monster", "Devilskull Sharpbone"),     "GENERAL",     9,    444, AI_STORM,    1,         25,         40,                IMMUNE_FIRE                                    ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_STORM,    P_("monster", "Brokenstorm"),              "GENERAL",     9,    411, AI_STORM,    2,         25,         36,                              IMMUNE_LIGHTNING                 ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_RSTORM,   P_("monster", "Stormbane"),                "GENERAL",     9,    555, AI_STORM,    3,         30,         30,                              IMMUNE_LIGHTNING                 ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_TOAD,     P_("monster", "Oozedrool"),                "GENERAL",     9,    483, AI_FAT,      3,         25,         30,                              RESIST_LIGHTNING                 ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_BLOODCLW, P_("monster", "Goldblight of the Flame"),  "GENERAL",    10,    405, AI_GARG,     0,         15,         35, IMMUNE_MAGIC | IMMUNE_FIRE                                    ,  UniqueMonsterPack::Leashed,     0,       80, TEXT_NONE      },
	{  MT_OBLORD,   P_("monster", "Blackstorm"),               "GENERAL",    10,    525, AI_RHINO,    3,         20,         40, IMMUNE_MAGIC |               IMMUNE_LIGHTNING                 ,  UniqueMonsterPack::Leashed,     0,       90, TEXT_NONE      },
	{  MT_RACID,    P_("monster", "Plaguewrath"),              "GENERAL",    10,    450, AI_ACIDUNIQ, 2,         20,         30, IMMUNE_MAGIC | RESIST_FIRE |                    IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_RSTORM,   P_("monster", "The Flayer"),               "GENERAL",    10,    501, AI_STORM,    1,         20,         35, RESIST_MAGIC | RESIST_FIRE | IMMUNE_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_FROSTC,   P_("monster", "Bluehorn"),                 "GENERAL",    11,    477, AI_RHINO,    1,         25,         30, IMMUNE_MAGIC | RESIST_FIRE                                    ,  UniqueMonsterPack::Leashed,     0,       90, TEXT_NONE      },
	{  MT_HELLBURN, P_("monster", "Warpfire Hellspawn"),       "GENERAL",    11,    525, AI_FIREMAN,  3,         10,         40, RESIST_MAGIC | IMMUNE_FIRE                                    ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_NSNAKE,   P_("monster", "Fangspeir"),                "GENERAL",    11,    444, AI_SKELSD,   1,         15,         32,                IMMUNE_FIRE |                    IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_UDEDBLRG, P_("monster", "Festerskull"),              "GENERAL",    11,    600, AI_STORM,    2,         15,         30, IMMUNE_MAGIC |                                  IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_NBLACK,   P_("monster", "Lionskull the Bent"),       "GENERAL",    12,    525, AI_SKELSD,   2,         25,         25, IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_COUNSLR,  P_("monster", "Blacktongue"),              "GENERAL",    12,    360, AI_COUNSLR,  3,         15,         30,                RESIST_FIRE |                    IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_DEATHW,   P_("monster", "Viletouch"),                "GENERAL",    12,    525, AI_GARG,     3,         20,         40,                              IMMUNE_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_RSNAKE,   P_("monster", "Viperflame"),               "GENERAL",    12,    570, AI_SKELSD,   1,         25,         35,               IMMUNE_FIRE  | RESIST_LIGHTNING                 ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_BSNAKE,   P_("monster", "Fangskin"),                 "BHKA",       14,    681, AI_SKELSD,   2,         15,         50, IMMUNE_MAGIC |               RESIST_LIGHTNING                 ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_SUCCUBUS, P_("monster", "Witchfire the Unholy"),     "GENERAL",    12,    444, AI_SUCC,     3,         10,         20, IMMUNE_MAGIC | IMMUNE_FIRE | RESIST_LIGHTNING                 ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_BALROG,   P_("monster", "Blackskull"),               "BHKA",       13,    750, AI_SKELSD,   3,         25,         40, IMMUNE_MAGIC |               RESIST_LIGHTNING                 ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_UNRAV,    P_("monster", "Soulslash"),                "GENERAL",    12,    450, AI_SKELSD,   0,         25,         25, IMMUNE_MAGIC |                                  IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_VTEXLRD,  P_("monster", "Windspawn"),                "GENERAL",    12,    711, AI_SKELSD,   1,         35,         40, IMMUNE_MAGIC | IMMUNE_FIRE                                    ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_GSNAKE,   P_("monster", "Lord of the Pit"),          "GENERAL",    13,    762, AI_SKELSD,   2,         25,         42,                RESIST_FIRE |                    IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_RTBLACK,  P_("monster", "Rustweaver"),               "GENERAL",    13,    400, AI_SKELSD,   3,          1,         60, IMMUNE_MAGIC | IMMUNE_FIRE | IMMUNE_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::None,        0,        0, TEXT_NONE      },
	{  MT_HOLOWONE, P_("monster", "Howlingire the Shade"),     "GENERAL",    13,    450, AI_SKELSD,   2,         40,         75,                RESIST_FIRE | RESIST_LIGHTNING                 ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_MAEL,     P_("monster", "Doomcloud"),                "GENERAL",    13,    612, AI_STORM,    1,          1,         60,                RESIST_FIRE | IMMUNE_LIGHTNING                 ,  UniqueMonsterPack::None,        0,        0, TEXT_NONE      },
	{  MT_PAINMSTR, P_("monster", "Bloodmoon Soulfire"),       "GENERAL",    13,    684, AI_SKELSD,   1,         15,         40, IMMUNE_MAGIC | RESIST_FIRE | RESIST_LIGHTNING                 ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_SNOWWICH, P_("monster", "Witchmoon"),                "GENERAL",    13,    310, AI_SUCC,     3,         30,         40,                              RESIST_LIGHTNING                 ,  UniqueMonsterPack::None,        0,        0, TEXT_NONE      },
	{  MT_VTEXLRD,  P_("monster", "Gorefeast"),                "GENERAL",    13,    771, AI_SKELSD,   3,         20,         55,                RESIST_FIRE |                    IMMUNE_NULL_40,  UniqueMonsterPack::None,        0,        0, TEXT_NONE      },
	{  MT_RTBLACK,  P_("monster", "Graywar the Slayer"),       "GENERAL",    14,    672, AI_SKELSD,   1,         30,         50,                              RESIST_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::None,        0,        0, TEXT_NONE      },
	{  MT_MAGISTR,  P_("monster", "Dreadjudge"),               "GENERAL",    14,    540, AI_COUNSLR,  1,         30,         40, IMMUNE_MAGIC | RESIST_FIRE | RESIST_LIGHTNING                 ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_HLSPWN,   P_("monster", "Stareye the Witch"),        "GENERAL",    14,    726, AI_SUCC,     2,         30,         50,                IMMUNE_FIRE                                    ,  UniqueMonsterPack::None,        0,        0, TEXT_NONE      },
	{  MT_BTBLACK,  P_("monster", "Steelskull the Hunter"),    "GENERAL",    14,    831, AI_SKELSD,   3,         40,         50,                              RESIST_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::None,        0,        0, TEXT_NONE      },
	{  MT_RBLACK,   P_("monster", "Sir Gorash"),               "GENERAL",    16,   1050, AI_SKELSD,   1,         20,         60,                                                 IMMUNE_NULL_40,  UniqueMonsterPack::None,        0,        0, TEXT_NONE      },
	{  MT_CABALIST, P_("monster", "The Vizier"),               "GENERAL",    15,    850, AI_COUNSLR,  2,         25,         40,                IMMUNE_FIRE                                    ,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_REALWEAV, P_("monster", "Zamphir"),                  "GENERAL",    15,    891, AI_SKELSD,   2,         30,         50, IMMUNE_MAGIC | RESIST_FIRE | RESIST_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_HLSPWN,   P_("monster", "Bloodlust"),                "GENERAL",    15,    825, AI_SUCC,     1,         20,         55, IMMUNE_MAGIC |               IMMUNE_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::None,        0,        0, TEXT_NONE      },
	{  MT_HLSPWN,   P_("monster", "Webwidow"),                 "GENERAL",    16,    774, AI_SUCC,     1,         20,         50, IMMUNE_MAGIC | IMMUNE_FIRE |                    IMMUNE_NULL_40,  UniqueMonsterPack::None,        0,        0, TEXT_NONE      },
	{  MT_SOLBRNR,  P_("monster", "Fleshdancer"),              "GENERAL",    16,    999, AI_SUCC,     3,         30,         50, IMMUNE_MAGIC | RESIST_FIRE |                    IMMUNE_NULL_40,  UniqueMonsterPack::None,        0,        0, TEXT_NONE      },
	{  MT_OBLORD,   P_("monster", "Grimspike"),                "GENERAL",    19,    534, AI_SNEAK,    1,         25,         40, IMMUNE_MAGIC | RESIST_FIRE |                    IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
// TRANSLATORS: Unique Monster Block end
	{  MT_STORML,   P_("monster", "Doomlock"),                 "GENERAL",    28,    534, AI_SNEAK,    1,         35,         55, IMMUNE_MAGIC | RESIST_FIRE | RESIST_LIGHTNING | IMMUNE_NULL_40,  UniqueMonsterPack::Leashed,     0,        0, TEXT_NONE      },
	{  MT_INVALID,  nullptr,                        nullptr,       0,      0, AI_INVALID,  0,          0,          0, 0                                                             ,  UniqueMonsterPack::None,        0,        0, TEXT_NONE      },
	// clang-format on
};

} // namespace devilution

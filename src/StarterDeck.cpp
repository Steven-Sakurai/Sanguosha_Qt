#include "Lib.h"
#include "CardInfo.h"
#include "Slash.h"
#include "Dodge.h"
#include "Peach.h"
#include "Dismantle.h"
#include "Thievery.h"
#include "Divination.h"
#include "SouthernIntruder.h"
#include "RandomShot.h"
#include "Harvest.h"
#include "Friendship.h"
#include "Duel.h"
#include "WeaponGambit.h"
#include "TimeWalk.h"
#include "Lightning.h"
#include "CrossBow.h"
#include "CiXiongSword.h"
#include "IceSword.h"
#include "Spear.h"
#include "Axe.h"
#include "Halberd.h"
#include "QiLinBow.h"
#include "EightDiagram.h"
#include "RenWangShield.h"
#include "OffensiveHorse.h"
#include "DefensiveHorse.h"
class DaYuan : public OffensiveHorse
{
public:
    DaYuan() : OffensiveHorse("大宛") {}
};

class ChiTu : public OffensiveHorse
{
public:
    ChiTu() : OffensiveHorse("赤兔") {}
};

class ZiXing : public OffensiveHorse
{
public:
    ZiXing() : OffensiveHorse("紫骍") {}
};

class JueYing : public DefensiveHorse
{
public:
    JueYing() : DefensiveHorse("绝影") {}
};

class ZhuaHuangFeiDian : public DefensiveHorse
{
public:
    ZhuaHuangFeiDian() : DefensiveHorse("爪黄飞电") {}
};

class DiLu : public DefensiveHorse
{
public:
    DiLu() : DefensiveHorse("的卢") {}
};

void initStarterDeck(vector<CardInfo *> &cards)
{
    CardType *slash=game->getCardType<Slash>(),
            *dodge=game->getCardType<Dodge>(),
            *peach=game->getCardType<Peach>(),
            *dismantle=game->getCardType<Dismantle>(),
            *thievery=game->getCardType<Thievery>(),
            *divination=game->getCardType<Divination>(),
            *southernIntruder=game->getCardType<SouthernIntruder>(),
            *harvest=game->getCardType<Harvest>(),
            *duel=game->getCardType<Duel>(),
            *weaponGambit=game->getCardType<WeaponGambit>(),
            *timeWalk=game->getCardType<TimeWalk>(),
            *lightning=game->getCardType<Lightning>();
    cards.push_back(new CardInfo(slash,1,7));//1:黑桃,2:红桃,3:方块,4:梅花
    cards.push_back(new CardInfo(slash,1,8));
    cards.push_back(new CardInfo(slash,1,8));
    cards.push_back(new CardInfo(slash,1,9));
    cards.push_back(new CardInfo(slash,1,9));
    cards.push_back(new CardInfo(slash,1,10));
    cards.push_back(new CardInfo(slash,1,10));
    cards.push_back(new CardInfo(slash,2,10));
    cards.push_back(new CardInfo(slash,2,10));
    cards.push_back(new CardInfo(slash,2,11));
    cards.push_back(new CardInfo(slash,3,6));
    cards.push_back(new CardInfo(slash,3,7));
    cards.push_back(new CardInfo(slash,3,8));
    cards.push_back(new CardInfo(slash,3,9));
    cards.push_back(new CardInfo(slash,3,10));
    cards.push_back(new CardInfo(slash,3,13));
    cards.push_back(new CardInfo(slash,4,2));
    cards.push_back(new CardInfo(slash,4,3));
    cards.push_back(new CardInfo(slash,4,4));
    cards.push_back(new CardInfo(slash,4,5));
    cards.push_back(new CardInfo(slash,4,6));
    cards.push_back(new CardInfo(slash,4,7));
    cards.push_back(new CardInfo(slash,4,8));
    cards.push_back(new CardInfo(slash,4,8));
    cards.push_back(new CardInfo(slash,4,9));
    cards.push_back(new CardInfo(slash,4,9));
    cards.push_back(new CardInfo(slash,4,10));
    cards.push_back(new CardInfo(slash,4,10));
    cards.push_back(new CardInfo(slash,4,11));
    cards.push_back(new CardInfo(slash,4,11));
    cards.push_back(new CardInfo(dodge,2,2));
    cards.push_back(new CardInfo(dodge,2,2));
    cards.push_back(new CardInfo(dodge,2,13));
    cards.push_back(new CardInfo(dodge,3,2));
    cards.push_back(new CardInfo(dodge,3,2));
    cards.push_back(new CardInfo(dodge,3,3));
    cards.push_back(new CardInfo(dodge,3,4));
    cards.push_back(new CardInfo(dodge,3,5));
    cards.push_back(new CardInfo(dodge,3,6));
    cards.push_back(new CardInfo(dodge,3,7));
    cards.push_back(new CardInfo(dodge,3,8));
    cards.push_back(new CardInfo(dodge,3,9));
    cards.push_back(new CardInfo(dodge,3,10));
    cards.push_back(new CardInfo(dodge,3,11));
    cards.push_back(new CardInfo(dodge,3,11));
    cards.push_back(new CardInfo(peach,2,3));
    cards.push_back(new CardInfo(peach,2,4));
    cards.push_back(new CardInfo(peach,2,6));
    cards.push_back(new CardInfo(peach,2,7));
    cards.push_back(new CardInfo(peach,2,8));
    cards.push_back(new CardInfo(peach,2,9));
    cards.push_back(new CardInfo(peach,2,12));
    cards.push_back(new CardInfo(peach,3,12));
    cards.push_back(new CardInfo(game->getCardType<CrossBow>(),3,1));
    cards.push_back(new CardInfo(game->getCardType<CrossBow>(),4,1));
    cards.push_back(new CardInfo(game->getCardType<CiXiongSword>(),1,2));
    cards.push_back(new CardInfo(game->getCardType<IceSword>(),1,2));
    cards.push_back(new CardInfo(game->getCardType<Spear>(),1,12));
    cards.push_back(new CardInfo(game->getCardType<Axe>(),3,5));
    cards.push_back(new CardInfo(game->getCardType<Halberd>(),3,12));
    cards.push_back(new CardInfo(game->getCardType<QiLinBow>(),2,5));
    //cards.push_back(new CardInfo(game->getCardType<EightDiagram>(),1,2));
    //cards.push_back(new CardInfo(game->getCardType<EightDiagram>(),4,2));
    cards.push_back(new CardInfo(game->getCardType<RenWangShield>(),4,2));
    cards.push_back(new CardInfo(dismantle,1,3));
    cards.push_back(new CardInfo(dismantle,1,4));
    cards.push_back(new CardInfo(dismantle,1,12));
    cards.push_back(new CardInfo(dismantle,2,12));
    cards.push_back(new CardInfo(dismantle,4,3));
    cards.push_back(new CardInfo(dismantle,4,4));
    cards.push_back(new CardInfo(thievery,1,3));
    cards.push_back(new CardInfo(thievery,1,4));
    cards.push_back(new CardInfo(thievery,1,11));
    cards.push_back(new CardInfo(thievery,3,3));
    cards.push_back(new CardInfo(thievery,3,4));
    cards.push_back(new CardInfo(divination,2,7));
    cards.push_back(new CardInfo(divination,2,8));
    cards.push_back(new CardInfo(divination,2,9));
    cards.push_back(new CardInfo(divination,2,11));
    cards.push_back(new CardInfo(southernIntruder,1,7));
    cards.push_back(new CardInfo(southernIntruder,1,13));
    cards.push_back(new CardInfo(southernIntruder,4,7));
    cards.push_back(new CardInfo(game->getCardType<RandomShot>(),2,1));
    cards.push_back(new CardInfo(harvest,2,2));
    cards.push_back(new CardInfo(harvest,2,3));
    cards.push_back(new CardInfo(game->getCardType<Friendship>(),2,1));
    cards.push_back(new CardInfo(duel,1,1));
    cards.push_back(new CardInfo(duel,3,1));
    cards.push_back(new CardInfo(duel,4,1));
    cards.push_back(new CardInfo(weaponGambit,4,12));
    cards.push_back(new CardInfo(weaponGambit,4,13));
    //cards.push_back(new CardInfo(timeWalk,1,6));
    //cards.push_back(new CardInfo(timeWalk,2,6));
    //cards.push_back(new CardInfo(timeWalk,4,6));
    //cards.push_back(new CardInfo(lightning,1,1));
    //cards.push_back(new CardInfo(lightning,2,12));
    cards.push_back(new CardInfo(game->getCardType<DaYuan>(),1,13));
    cards.push_back(new CardInfo(game->getCardType<ChiTu>(),2,5));
    cards.push_back(new CardInfo(game->getCardType<ZiXing>(),3,13));
    cards.push_back(new CardInfo(game->getCardType<JueYing>(),1,5));
    cards.push_back(new CardInfo(game->getCardType<ZhuaHuangFeiDian>(),2,13));
    cards.push_back(new CardInfo(game->getCardType<DiLu>(),4,5));
}

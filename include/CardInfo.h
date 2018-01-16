/*
 * CardInfo.h
 * 
 */
#ifndef _CARDINFO_H
#define _CARDINFO_H

#include "Lib.h"
#include <QPixmap>

class CardType;
class Card;

class CardInfo
{
public:
    int suit,rank;
    CardType *name;

    static string rankString[14],suitString[7];
    CardInfo(CardType *n,int s,int r);//构造函数:卡牌类型,花色,点数
    CardInfo(CardType *n, vector<Card*> cards);//构造函数:转换类
    bool isBlack();//判断:黑色?
    bool isRed();//判断:红色?
    string toString();

    QPixmap picture;

    QPixmap equippicture;

    string cpfn;
};

#endif

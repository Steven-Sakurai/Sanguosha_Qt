#include "Lib.h"
#include "CardInfo.h"
#include "CardType.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <stdio.h>
#include <math.h>
#include <wchar.h>
#include <string.h>
#include <QPainter>

string CardInfo::rankString[14]={"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
string CardInfo::suitString[7]={"","黑桃","红桃","方块","梅花","黑色","红色"};


CardInfo::CardInfo(CardType *n,int s,int r)
{
    name=n;suit=s;rank=r;

    /*char _s_r_n[50];
    char _r[10];
    char whiteSpace[10] = ",";

    char _name[50];
    strcpy(_name,n->name.c_str());
    char _front[50] = ":/image/card_image/";
    char _behind[10] = ".png";

    sprintf(_s_r_n,"%d",s);
    sprintf(_r,"%d",r);

    strcat(_s_r_n,whiteSpace);
    strcat(_s_r_n,_r);
    //strcat(_s_r_n,_name);
    strcat(_s_r_n,_behind);
    strcat(_front,_s_r_n);

    picture = QPixmap(_front);*/

    char CardPixFileName[50]={0};
    char SuitPixFileName[50]={0};
    char NumberPixFileName[50]={0};
    char CardNum[50]={0};
    char SuitNum[50]={0};
    char Num[50]={0};
    char Tail[] = ".png";
    char CardFront[] = ":/image/card_image/";
    char SuitFront[] = ":/image/suit/";
    char BlackFront[] = ":/image/black/";
    char RedFront[] = ":/image/red/";
    strcpy(CardPixFileName,CardFront);
    strcpy(SuitPixFileName,SuitFront);
    if(suit==1||suit==4||suit==5)
    strcpy(NumberPixFileName,BlackFront);
    else if(suit==2||suit==3||suit==6)
    strcpy(NumberPixFileName,RedFront);


    if(name->name=="杀") cpfn="1";
       else if(name->name=="闪") cpfn="2";
       else if(name->name=="桃") cpfn="3";
       else if(name->name=="诸葛连弩") cpfn="4";
       else if(name->name=="雌雄双股剑") cpfn="5";
       else if(name->name=="寒冰剑") cpfn="6";
       else if(name->name=="丈八蛇矛") cpfn="7";
       else if(name->name=="贯石斧") cpfn="8";
       else if(name->name=="方天画戟") cpfn="9";
       else if(name->name=="麒麟弓") cpfn="10";
       else if(name->name=="八卦阵") cpfn="11";
       else if(name->name=="仁王盾") cpfn="12";
       else if(name->name=="过河拆桥") cpfn="13";
       else if(name->name=="顺手牵羊") cpfn="14";
       else if(name->name=="无中生有") cpfn="15";
       else if(name->name=="南蛮入侵") cpfn="16";
       else if(name->name=="万箭齐发") cpfn="17";
       else if(name->name=="五谷丰登") cpfn="18";
       else if(name->name=="桃园结义") cpfn="19";
       else if(name->name=="决斗") cpfn="20";
       else if(name->name=="借刀杀人") cpfn="21";
       else if(name->name=="乐不思蜀") cpfn="22";
       else if(name->name=="闪电") cpfn="23";
       else if(name->name=="紫骍") cpfn="24";
       else if(name->name=="爪黄飞电") cpfn="25";//
       else if(name->name=="绝影") cpfn="26";//
       else if(name->name=="骅骝") cpfn="27";//
       else if(name->name=="赤兔") cpfn="28";
       else if(name->name=="大宛") cpfn="29";
       else if(name->name=="的卢") cpfn="30";//

      CardNum[0]=cpfn[0];
      CardNum[1]=cpfn[1];

      strcat(CardPixFileName,CardNum);
      strcat(CardPixFileName,Tail);

      SuitNum[0]=suit+'0';

      if(rank>=10)
      {
          Num[0]='1';
          Num[1]=rank%10+'0';
      }
      else
          Num[0]=rank+'0';

      strcat(SuitPixFileName,SuitNum);
      strcat(SuitPixFileName,Tail);

      strcat(NumberPixFileName,Num);
      strcat(NumberPixFileName,Tail);

      QPixmap cardpix(CardPixFileName);
      QPixmap suitpix(SuitPixFileName);
      QPixmap numpix(NumberPixFileName);

      QPixmap totalpix(cardpix.width() ,cardpix.height() );

      QPainter painter(&totalpix);

      painter.drawPixmap(0,0,cardpix.width() ,cardpix.height() ,cardpix);
      painter.drawPixmap(15 ,35 ,0.15*suitpix.width() ,0.15*suitpix.height() ,suitpix);
      painter.drawPixmap(2,5,1.5*numpix.width(),1.5*numpix.height(),numpix);

      QPixmap finalpix(totalpix.width()*0.6*1.3,totalpix.height()*0.6*1.3);

      QPainter painter2(&finalpix);
      painter2.drawPixmap(0,0,totalpix.width()*0.6*1.3,totalpix.height()*0.6*1.3,totalpix);
//
      picture = finalpix ;

      /////////////////以上为设置卡牌图片

     char equipPixFileName[50]=":/equip/other image/equips/needed/";
     strcat(equipPixFileName,CardNum);
     strcat(equipPixFileName,Tail);

     equippicture = QPixmap(equipPixFileName);











}

CardInfo::CardInfo(CardType *n, vector<Card *> cards)
{
    name=n;suit=rank=0;
    if(!cards.empty())
    {
        CardInfo info0=cards[0]->getCardInfo();
        if(cards.size()==1)
        {
            suit=info0.suit;rank=info0.rank;
        }
        else if(info0.isBlack())
        {
            suit=5;//仅为黑色,无花色
            for(int k=1;k<cards.size();k++) if(!cards[k]->getCardInfo().isBlack()) {suit=0;break;}//无颜色
        }
        else
        {
            suit=6;
            for(int k=0;k<cards.size();k++) if(!cards[k]->getCardInfo().isRed()) {suit=0;break;}
        }
    }
}

bool CardInfo::isBlack()
{
    return suit==1||suit==4||suit==5;
}

bool CardInfo::isRed()
{
    return suit==2||suit==3||suit==6;
}

string CardInfo::toString()
{
    return suitString[suit]+rankString[rank]+"["+name->name+"]";
}

#include "Lib.h"
#include "Card.h"
#include <QPushButton>
#include <QPainter>
#include <QIcon>
#include "mainwindow.h"
#include "Game.h"

Card::Card(){}

Card::Card(CardInfo *c, Card *p)
{
	info=c;insert(p);


    //QPainter painter(cardButton);
    cardButton.setGeometry(0,0,this->info->picture.width(),this->info->picture.height());
    //cout<<this->info->name->name<<endl;
    //painter.drawPixmap(0,0,this->info->picture);
    cardButton.setIcon(QIcon(this->info->picture));
    cardButton.setIconSize(this->info->picture.size());
    //w->update();

    equipButton.setGeometry(0,0,this->info->equippicture.width(),this->info->equippicture.height());
    equipButton.setIcon(QIcon(this->info->equippicture));
    equipButton.setIconSize(this->info->picture.size());

    //cardButton.setEnabled(false);
    equipButton.setEnabled(false);
}

Card::~Card()
{
	if(info) delete info;
    erase();
}

CardInfo Card::getCardInfo()
{
    return *info;//TODO: Skills like 红颜
}

void Card::erase()
{
	zone->size--;prev->next=next;next->prev=prev;
    this->cardButton.close();
    if(zone->player==game->players[CGlobal::HumanPlayer]&&zone->name=="hand")
     {

        int j =0 ;
        //this->showCard(CGlobal::ww,rand()%500,rand()%500);
        for(Card * i = zone->next;i!=zone;i=i->next)
        {
            if(i==zone)
                break;

            i->showCard(CGlobal::ww,j*100+210,540);
            j++;
        }

        \
     }
    this->equipButton.close();

    if(zone->player!=game->players[CGlobal::HumanPlayer]&&zone->name=="hand")
    {
      int nnn=0;
        Card *n=zone->next;
        while(n!=zone)
        {
            nnn++;
            n=n->next;
        }

        char t[50]={0};

        sprintf(t,"%d",nnn);


        //CGlobal::cardnum[0]->setPlainText(QString(t));

      int j=0;
        for(Player * tempplayer = zone->player;tempplayer != game->players[CGlobal::HumanPlayer];tempplayer = tempplayer->nextPlayer)
        {
            j++;
        }

        int pos = j - 1;

        CGlobal::cardnum[pos]->setText(QString((char)(nnn+'0')));
    }
}

void Card::insert(Card *p)
{
	zone=p->zone;zone->size++;prev=p;next=p->next;p->next=next->prev=this;

    if(zone->player!=game->players[CGlobal::HumanPlayer]&&zone->name=="hand")
    {
      int nnn=0;
        Card *n=zone->next;
        while(n!=zone)
        {
            nnn++;
            n=n->next;
        }

        char t[50]={0};

        sprintf(t,"%d",nnn);


      //  CGlobal::cardnum[0]->setPlainText(QString(t));

       int j=0;
        for(Player * tempplayer = zone->player;tempplayer != game->players[CGlobal::HumanPlayer];tempplayer = tempplayer->nextPlayer)
        {
            j++;
        }

        int pos = j - 1;

        CGlobal::cardnum[pos]->setText(QString((char)(nnn+'0')));
    }

    if(zone->player==game->players[CGlobal::HumanPlayer]&&zone->name=="hand")
     {
        int j =0 ;
        //this->showCard(CGlobal::ww,rand()%500,rand()%500);
        for(Card * i = zone->next;i!=zone;i=i->next)
        {

            i->showCard(CGlobal::ww,j*100+210,540);
            j++;
        }
     }



    if(zone->player==game->players[CGlobal::HumanPlayer]&&zone->name=="equipArea")
    {
        this->equipButton.setGeometry(0,0,200,50);


        if((this->info->cpfn>="4"&&this->info->cpfn<="9")||this->info->cpfn=="10")
        {

            showEquip(CGlobal::ww,0,590);//武器牌
        }

        if(this->info->cpfn=="11"||this->info->cpfn=="12")
        {
            showEquip(CGlobal::ww,0,630);//防具
        }

        if((this->info->cpfn>="25"&&this->info->cpfn<="27")||this->info->cpfn=="30")
        {
            showEquip(CGlobal::ww,0,673);//+1
        }

        if(this->info->cpfn=="24"||this->info->cpfn=="28"||this->info->cpfn=="29")
        {
            showEquip(CGlobal::ww,0,718);//-1
        }
    }

    if(zone->player!=game->players[CGlobal::HumanPlayer]&&zone->name=="equipArea")
    {
        this->equipButton.setGeometry(0,0,155,10);

        int jjjjj=0;
        for(Player * tempplayer = zone->player;tempplayer != game->players[CGlobal::HumanPlayer];tempplayer = tempplayer->nextPlayer)
        {
            jjjjj++;
        }

        int pos = jjjjj- 1;

        if((this->info->cpfn>="4"&&this->info->cpfn<="9")||this->info->cpfn=="10")
        {

            showEquip(CGlobal::ww,CGlobal::otherplayerzonelabel[pos]->x(),CGlobal::otherplayerzonelabel[pos]->y()+122);//武器牌
        }

        if(this->info->cpfn=="11"||this->info->cpfn=="12")
        {
            showEquip(CGlobal::ww,CGlobal::otherplayerzonelabel[pos]->x(),CGlobal::otherplayerzonelabel[pos]->y()+138);//防具
        }

        if((this->info->cpfn>="25"&&this->info->cpfn<="27")||this->info->cpfn=="30")
        {
            showEquip(CGlobal::ww,CGlobal::otherplayerzonelabel[pos]->x(),CGlobal::otherplayerzonelabel[pos]->y()+152);//+1
        }

        if(this->info->cpfn=="24"||this->info->cpfn=="28"||this->info->cpfn=="29")
        {
            showEquip(CGlobal::ww,CGlobal::otherplayerzonelabel[pos]->x(),CGlobal::otherplayerzonelabel[pos]->y()+166);//-1

        }



    }

    if(zone->name=="resArea")
    {
        int j=0;
        for(Card * temp = zone->next;temp !=zone;temp=temp->next)
        {
            temp->showCard(CGlobal::ww,300+70*j,280);
            j++;
        }
    }

    if(zone->name=="discardPile")
    {
        int j=0;
        for(Card * temp = zone->next;temp !=zone;temp=temp->next)
        {
            j++;
            if(j%10==0)
            temp->showCard(CGlobal::ww,600-j,280-j);

        }
        zone->prev->showCard(CGlobal::ww,600-j,280-j);

    }



}

void Card::move(Card *p)
{
    if(p!=this) {erase();insert(p);}
}

bool Card::isVisibleTo(Player *p)
{
    bool res=zone->isVisibleTo(p);//TODO:face down
    pair<Card*, Player*> data=make_pair(this,p);
    game->applyStatics(visibilityValue,&res,&data);
    return res;
}

string Card::toString(Player *p)
{
    string res="";
    if(isVisibleTo(p)) res+=getPhysicalCardInfo().toString();
    else res+="hidden";
    res+="@";
    res+=zone->toString();
    return res;
}

void Card::showCard(MainWindow * w,int x,int y)
{

    this->cardButton.setParent(w);
    this->cardButton.setGeometry(x,y,this->cardButton.width(),this->cardButton.height());
    this->cardButton.show();

}

void Card::showEquip(MainWindow *w, int x, int y)
{
    this->equipButton.setParent(w);
    this->equipButton.setGeometry(x,y,this->equipButton.width(),this->equipButton.height());
    this->equipButton.show();
}



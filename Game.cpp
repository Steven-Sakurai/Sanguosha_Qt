#include "Game.h"
#include "MoveEvent.h"
#include "Cheat.h"
#include "YieldEvent.h"
#include "NeedUseEvent.h"
#include "NeedYieldEvent.h"
#include "PrimitiveMoveEvent.h"
#include <map>
#include <QDebug>
#include "mainwindow.h"
#include <string>
#include <QString>
#include "Player.h"
#include <QPainter>
Game *game;

void initStarterDeck(vector<CardInfo*> &cards);

Game::Game(const vector<ClientPlayer*> &clients, bool cheatMode ,MainWindow * w):
    deck("deck",NULL,false),discardPile("discardPile"),resArea("resArea")
{
    int lordId;
	try
    {   srand(clock());
        game=this;
        nPlayer=clients.size();//玩家数目


        CGlobal::HumanPlayer = rand()%nPlayer;




		int i,pc=0;
        vector<CardInfo*> cards;
        vector<Role> roles;//身份向量
        roles.push_back(Renegade);//在身份向量中添加内奸
        initStarterDeck(cards);//初始化牌堆
        random_shuffle(cards.begin(),cards.end());//洗牌堆
        roles.push_back(Lord);//在身份向量中添加主公
        for(i=0;i<(nPlayer-3)/2;i++) roles.push_back(Loyalist);//添加忠臣
        for(i=0;i<nPlayer/2;i++) roles.push_back(Rebel);//添加反贼
        random_shuffle(roles.begin(),roles.end());//洗身份
        for(i=0;i<nPlayer;i++)
        {
            ostringstream s;
            s<<"role:"<<roles[i];
            clients[i]->inform(s.str());//输出身份信息
        }
      //  int lordId;//主公位置

        for(i=0;i<nPlayer;i++) if(roles[i]==Lord) lordId=i;
        for(i=0;i<nPlayer;i++)
        {
            ostringstream s;
            s<<"lord:"<<lordId;
            clients[i]->inform(s.str());
        }//输出主公信息
        //TODO: choose generals
        for(i=0;i<nPlayer;i++)
        {
            players.push_back(new Player(clients[i],roles[i]));
            if(i>0) players[i-1]->nextPlayer=players[i];
        }//建立玩家向量,设定玩家间顺序关系
        players[nPlayer-1]->nextPlayer=players[0];
        curPlayer=lordId;//从主公开始回合
        CGlobal::CurrentTurn =  lordId;

        ///////显示序号

        CGlobal::humanplayernumber[CGlobal::HumanPlayer]->move(1225,725);
        CGlobal::humanplayernumber[CGlobal::HumanPlayer]->show();

        for(int i=0;i<nPlayer;i++)
        {
            if(i!=CGlobal::HumanPlayer)
            {
                CGlobal::otherplayernumber[i]->move(CGlobal::otherplayerzonelabel[(-i+nPlayer+CGlobal::HumanPlayer-1)%nPlayer]->x()+50,CGlobal::otherplayerzonelabel[(-i+nPlayer+CGlobal::HumanPlayer-1)%nPlayer]->y()-12);
                CGlobal::otherplayernumber[i]->show();
            }
        }









        //////////显示头像

        for(int i=0;i<nPlayer;i++)
        {
            if(i!=CGlobal::HumanPlayer)
            {
                CGlobal::otherplayergeneral[i] = new QLabel(CGlobal::ww);

                int j = rand()%25;

                QPixmap generalpixmap(123,90);
                QPainter generalpainter(&generalpixmap);
                generalpainter.drawPixmap(0,0,generalpixmap.width(),generalpixmap.height(),*CGlobal::generalpix[j]);

                CGlobal::otherplayergeneral[i]->setGeometry(CGlobal::otherplayerzonelabel[(CGlobal::HumanPlayer+nPlayer-1-i)%nPlayer]->x()+5,CGlobal::otherplayerzonelabel[(CGlobal::HumanPlayer+nPlayer-1-i)%nPlayer]->y()+27,generalpixmap.width(),generalpixmap.height());;
                CGlobal::otherplayergeneral[i]->setPixmap(generalpixmap);
                //CGlobal::otherplayergeneral[i]->setWindowFlags(Qt::WindowStaysOnTopHint);
                CGlobal::otherplayergeneral[i]->show();


            }
        }

        CGlobal::Humangeneral = new QLabel(CGlobal::ww);
        QPixmap humanpix(223,229);
        CGlobal::Humangeneral->setGeometry(1170,503,humanpix.width(),humanpix.height());
        QPainter humangeneralpainter(&humanpix);
        humangeneralpainter.drawPixmap(0,0,humanpix.width(),humanpix.height(),QPixmap(":/other/leilei.png"));
        CGlobal::Humangeneral->setPixmap(humanpix);
        CGlobal::Humangeneral->show();


        ///////显示主公和自己身份

        for(int i=0;i<6;i++)
        {
            CGlobal::roleslabel[i] = new QLabel(CGlobal::ww);
            CGlobal::roleslabel[i]->setGeometry(CGlobal::otherplayerzonelabel[i]->x(),CGlobal::otherplayerzonelabel[i]->y(),50,70);
        }
        CGlobal::roleslabel[7] = new QLabel(CGlobal::ww);
        CGlobal::roleslabel[7]->setGeometry(CGlobal::Humangeneral->x(),CGlobal::Humangeneral->y(),50,70);


        if(lordId!=CGlobal::HumanPlayer){
        QPixmap lordpix(CGlobal::roleslabel[0]->width(),CGlobal::roleslabel[0]->height());
        QPainter lordpainter(&lordpix);
        lordpainter.drawPixmap(0,0,CGlobal::roleslabel[0]->width(),CGlobal::roleslabel[0]->height(),*CGlobal::rolespix[0]);
        CGlobal::roleslabel[(-lordId+nPlayer+CGlobal::HumanPlayer-1)%nPlayer]->setPixmap(lordpix);
        //CGlobal::roleslabel[(-lordId+nPlayer+CGlobal::HumanPlayer-1)%nPlayer]->setWindowFlags(Qt::WindowStaysOnTopHint);
        CGlobal::roleslabel[(-lordId+nPlayer+CGlobal::HumanPlayer-1)%nPlayer]->show();
        }

        int Humanrole;
        if(players[CGlobal::HumanPlayer]->role==Lord)
            Humanrole=0;
        else if(players[CGlobal::HumanPlayer]->role==Loyalist)
            Humanrole=1;
        else if(players[CGlobal::HumanPlayer]->role==Rebel)
            Humanrole=2;
        else if(players[CGlobal::HumanPlayer]->role==Renegade)
            Humanrole=3;

        QPixmap humanrolepix(CGlobal::roleslabel[0]->width(),CGlobal::roleslabel[0]->height());
        QPainter humanrolepainter(&humanrolepix);
        humanrolepainter.drawPixmap(0,0,CGlobal::roleslabel[0]->width(),CGlobal::roleslabel[0]->height(),*CGlobal::rolespix[Humanrole]);
        CGlobal::roleslabel[7]->setPixmap(humanrolepix);
        CGlobal::roleslabel[7]->show();


        /////////

        if(nPlayer>=5)
        {
        players[lordId]->maxHp = 5;
        players[lordId]->hp = 5;
        }

       /* players[CGlobal::HumanPlayer]->maxHp = 1;
        players[CGlobal::HumanPlayer]->hp = 1;*/

        for(int i=0;i<players[CGlobal::HumanPlayer]->hp;i++)
        {
            switch(players[CGlobal::HumanPlayer]->hp)
            {
            case 1:CGlobal::HumanplayerHP[4-i]->setPixmap(*CGlobal::red);break;
            case 2:CGlobal::HumanplayerHP[4-i]->setPixmap(*CGlobal::orange);break;
            case 3:CGlobal::HumanplayerHP[4-i]->setPixmap(*CGlobal::yellow);break;
            case 4:CGlobal::HumanplayerHP[4-i]->setPixmap(*CGlobal::green);break;
            case 5:CGlobal::HumanplayerHP[4-i]->setPixmap(*CGlobal::deepgreen);break;
            }


            CGlobal::HumanplayerHP[4-i]->show();
        }

        for(int j=0;j<nPlayer;j++)
        {
            if(j!=CGlobal::HumanPlayer)
            {
                for(int i=0;i<5;i++)
                {
                    CGlobal::otherplayerHP[(-j+nPlayer+CGlobal::HumanPlayer-1)%nPlayer][i]->close();
                }

                for(int i=0;i<players[j]->hp;i++)
                {
                    switch(players[j]->hp)
                    {
                    case 1:CGlobal::otherplayerHP[(-j+nPlayer+CGlobal::HumanPlayer-1)%nPlayer][4-i]->setPixmap(*CGlobal::smallred);break;
                    case 2:CGlobal::otherplayerHP[(-j+nPlayer+CGlobal::HumanPlayer-1)%nPlayer][4-i]->setPixmap(*CGlobal::smallorange);break;
                    case 3:CGlobal::otherplayerHP[(-j+nPlayer+CGlobal::HumanPlayer-1)%nPlayer][4-i]->setPixmap(*CGlobal::smallyellow);break;
                    case 4:CGlobal::otherplayerHP[(-j+nPlayer+CGlobal::HumanPlayer-1)%nPlayer][4-i]->setPixmap(*CGlobal::smallgreen);break;
                    case 5:CGlobal::otherplayerHP[(-j+nPlayer+CGlobal::HumanPlayer-1)%nPlayer][4-i]->setPixmap(*CGlobal::smalldeepgreen);break;
                    }


                    CGlobal::otherplayerHP[(-j+nPlayer+CGlobal::HumanPlayer-1)%nPlayer][4-i]->show();
                }
            }
        }

        if(curPlayer != CGlobal::HumanPlayer) {

        int x, y;
        switch ((- curPlayer + CGlobal::HumanPlayer + nPlayer - 1) % nPlayer) {


        case 0:x=50;y=250;break;
        case 1:x=150;y=40;break;
        case 2:x=325;y=40;break;
        case 3:x=500;y=40;break;
        case 4:x=675;y=40;break;
        case 5:x=850;y=40;break;
        case 6:x=950;y=250;break;
        }

       /* QPixmap current(CGlobal::otherplayerzonelabel[0]->width(),CGlobal::otherplayerzonelabel[0]->height()/2);
        QPainter curpainter(&current);
        curpainter.drawPixmap(0,0,current.width(),current.height(),QPixmap(":/image/dashboardSelected.png"));*/

        /*QPixmap current(CGlobal::otherplayerzonelabel[0]->width()+10,CGlobal::otherplayerzonelabel[0]->height()+10);
        QPainter curpainter(&current);
        QBrush brush(QColor(0,0,255),Qt::Dense4Pattern);

        curpainter.setBrush(brush);
        curpainter.drawRect(QRect(0,0,current.width(),current.height()));*/

        QPixmap current(QPixmap(":/image/dashboardSelected.png"));

        CGlobal::Cur[curPlayer] = new QLabel(CGlobal::ww);
        CGlobal::Cur[curPlayer]->setGeometry(x-5,y-10,current.width(),current.height());
        CGlobal::Cur[curPlayer]->setPixmap(current);
        CGlobal::Cur[curPlayer]->setWindowFlags(Qt::WindowStaysOnTopHint);
        CGlobal::Cur[curPlayer]->show();

    }



        //TODO: register triggers
        if(cheatMode) for(i=0;i<nPlayer;i++)
        {
            Player *p=players[i];
            (new Cheat(p))->init();
        }
        handleTiming(revealGeneral,NULL);//设定阶段:亮将
        handleTiming(initHandCard,NULL);//设定阶段:摸起始手牌
        for(i=0;i<nPlayer;i++) for(int j=0;j<4;j++) players[i]->hand.push_back(cards[pc++]);//摸起始手牌
        for(i=0;i<nPlayer;i++)//输出起始手牌信息
		{
			Player *p=players[i];
            string s="init_hand:";
            for(Card* n=p->hand.next;n!=&p->hand;n=n->next) s+=n->getPhysicalCardInfo().toString()+";";

            if(i==CGlobal::HumanPlayer)
            {
                int nnn=0;
                for(Card* n=p->hand.next;n!=&p->hand;n=n->next)
                {
                   n->showCard(w,(nnn++)*100+210,540);//显示起始手牌

                }
            }
            else
            {
                int nnn=0;
                Card *n=p->hand.next;
                while(n!=&p->hand)
                {
                    nnn++;
                    n=n->next;
                }

                CGlobal::cardnum[(-i+nPlayer+CGlobal::HumanPlayer-1)%nPlayer]->setPlainText(QString((char)(nnn+'0')));


            }

            p->inform(s);
		}
        while(pc<cards.size()) deck.push_back(cards[pc++]);//构建牌堆
        handleTiming(gameStart,NULL);//阶段:游戏开始
		while(1)
		{

            int x,y;


            (new TurnEvent(players[curPlayer]))->happen();//回合

                        CGlobal::CurrentTurn = (CGlobal::CurrentTurn + 1) % nPlayer;

            
            //TODO: extra turns
            do {





                if(CGlobal::Cur[curPlayer] != 0)
                {CGlobal::Cur[curPlayer]->close();}

                curPlayer=(curPlayer+1)%nPlayer;

                if(curPlayer != CGlobal::HumanPlayer) {
                switch ((- curPlayer + CGlobal::HumanPlayer + nPlayer - 1) % nPlayer) {
                case 0:x=50;y=250;break;
                case 1:x=150;y=40;break;
                case 2:x=325;y=40;break;
                case 3:x=500;y=40;break;
                case 4:x=675;y=40;break;
                case 5:x=850;y=40;break;
                case 6:x=950;y=250;break;
                }

                /*QPixmap current(CGlobal::otherplayerzonelabel[0]->width(),CGlobal::otherplayerzonelabel[0]->height()/2);
                QPainter curpainter(&current);
                curpainter.drawPixmap(0,0,current.width(),current.height(),QPixmap(":/image/dashboardSelected.png"));*/

                /*QPixmap current(CGlobal::otherplayerzonelabel[0]->width()+10,CGlobal::otherplayerzonelabel[0]->height()+10);
                QPainter curpainter(&current);
                QBrush brush(QColor(0,0,255),Qt::Dense4Pattern);

                curpainter.setBrush(brush);
                curpainter.drawRect(QRect(0,0,current.width(),current.height()));*/

                QPixmap current(":/image/dashboardSelected.png");

                CGlobal::Cur[curPlayer] = new QLabel(CGlobal::ww);
                CGlobal::Cur[curPlayer]->setGeometry(x-5,y-10,current.width(),current.height());
                CGlobal::Cur[curPlayer]->setPixmap(current);
                CGlobal::Cur[curPlayer]->setWindowFlags(Qt::WindowStaysOnTopHint);
                CGlobal::Cur[curPlayer]->show();
            }
                else
                {

                }
            }while(!players[curPlayer]->alive);//切换至下一个玩家的回合
		}
	}
    catch(GameOverException &e)//捕捉游戏结束条件
	{
        //cout<<"Game is over!\nResult: "<<e.result<<"\n";
        //std::string a = "Game is over! \n Result: " + std::string(e.result) + "\n";
        //CGlobal::QOUT(a);
        int alive = 0, a = 0, i = 0;
        for(i = 0; i < nPlayer; ++i)
        {
            if(players[i]->alive) {
                alive++;
                a = i;
            }
        }


        if(players[lordId]->alive)
        {
            CGlobal::QOUT("\n THE LORD WINS ! \n");
            CGlobal::lordwin->show();
        }

        else if(alive == 1 && players[a]->role == Renegade)
        {
            CGlobal::QOUT("\n The Renegade wins !!!!!!!!!!! \n");
            CGlobal::renegadewin->show();
        }
        else
        {
            CGlobal::QOUT("\n Rebels Win ! \n");
            CGlobal::rebelwin->show();

        }

        for(int i=0;i<game->nPlayer;i++)
        {
            if(i!=CGlobal::HumanPlayer){
                int irole;
            if(game->players[i]->role==Lord)
                irole=0;
            else if(game->players[i]->role==Loyalist)
                irole=1;
            else if(game->players[i]->role==Rebel)
                irole=2;
            else if(game->players[i]->role==Renegade)
                irole=3;
            CGlobal::roleslabel[(-i+game->nPlayer+CGlobal::HumanPlayer-1)%game->nPlayer] = new QLabel(CGlobal::ww);
            CGlobal::roleslabel[(-i+game->nPlayer+CGlobal::HumanPlayer-1)%game->nPlayer]->setGeometry(CGlobal::otherplayerzonelabel[(-i+game->nPlayer+CGlobal::HumanPlayer-1)%game->nPlayer]->x(),CGlobal::otherplayerzonelabel[(-i+game->nPlayer+CGlobal::HumanPlayer-1)%game->nPlayer]->y(),50,70);
            QPixmap ipix(CGlobal::roleslabel[0]->width(),CGlobal::roleslabel[0]->height());
            QPainter ipainter(&ipix);
            ipainter.drawPixmap(0,0,CGlobal::roleslabel[0]->width(),CGlobal::roleslabel[0]->height(),*CGlobal::rolespix[irole]);
            CGlobal::roleslabel[(-i+game->nPlayer+CGlobal::HumanPlayer-1)%game->nPlayer]->setPixmap(ipix);
            //CGlobal::roleslabel[(-lordId+nPlayer+CGlobal::HumanPlayer-1)%nPlayer]->setWindowFlags(Qt::WindowStaysOnTopHint);
            CGlobal::roleslabel[(-i+game->nPlayer+CGlobal::HumanPlayer-1)%game->nPlayer]->show();
            }
        }

       // CGlobal::startbutton->setGeometry(600,100,300,100);

        delete this;
	}
}

Game::~Game()
{
	int i;
	for(i=0;i<nPlayer;i++) delete players[i];
    for(i=0;i<timeline.size();i++) delete timeline[i];
    for(i=0;i<cardTypes.size();i++) delete cardTypes[i];
}
///////////////////////////
void Game::handleTiming(Timing t,Event *e,int i)
{
    if(i<0) i=curPlayer;
    for(;i<curPlayer+nPlayer;i++)
	{
		Player *p=players[i%nPlayer];
        if(t==doMainPhase&&p!=dynamic_cast<PhaseEvent*>(e)->player) continue;
        for(int j=0;j<3;j++)
        {
            if(t==doMainPhase&&j<2) continue;
            map<Trigger*,vector<void*> > triggerDone;
            triggerDone.clear();
            do
            {
                vector<pair<Trigger*,void*> > triggers;
                vector<Card*> cards;
                vector<Card*> yields;
                vector<pair<Transform*,CardType*> > transforms_use, transforms_yield;
                vector<string> choices;
                triggers.clear();
                cards.clear();
                choices.clear();
                transforms_use.clear();
                transforms_yield.clear();
                bool cancelable=true,autoable=true;
                int k;
                for(int j2=0;j2<3;j2++)
                {
                    if(j2!=j&&t!=doMainPhase) continue;
                    for(k=0;k<p->triggerTable[t][j2].size();k++)
                    {
                        Trigger *tr=p->triggerTable[t][j2][k];
                        vector<void*> t=tr->getTrigger(e,triggerDone[tr]);
                        if(!t.empty())
                        {
                            for(int l=0;l<t.size();l++)
                            {
                                triggers.push_back(make_pair(tr,t[l]));
                                choices.push_back(tr->toString(e,t[l]));
                            }
                            if(tr->isMandatory) cancelable=false;
                        }
                    }
                }
                if(j==2)
                {
                    for(Card *c=p->hand.next;c!=&p->hand;c=c->next) if(p->canUse(c,t,e))
                    {
                        cards.push_back(c);
                        choices.push_back(c->getPhysicalCardInfo().toString());
                    }
                    NeedUseEvent *need=dynamic_cast<NeedUseEvent*>(e);
                    for(k=0;k<cardTypes.size();k++)
                    {
                        CardType *type=cardTypes[k];
                        if(type->legalToUse(t,e,p)||need&&need->player==p&&need->filter->filter(CardInfo(type,0,0)))
                        {
                            autoable=false;
                            for(int kk=0;kk<p->transformTable[type].size();kk++)
                            {
                                Transform *trans=p->transformTable[type][kk];
                                if(trans->canTransform(type,e,transformUse))
                                {
                                    transforms_use.push_back(make_pair(trans,type));
                                    choices.push_back(trans->toString(type));
                                }
                            }
                        }
                    }
                    NeedYieldEvent *need2;
                    if(t==needYield&&(need2=dynamic_cast<NeedYieldEvent*>(e))->player==p)
                    {
                        autoable=false;
                        for(Card *c=p->hand.next;c!=&p->hand;c=c->next) if(p->canYield(c,e))
                        {
                            yields.push_back(c);
                            choices.push_back(c->getPhysicalCardInfo().toString());
                        }
                        for(k=0;k<cardTypes.size();k++)
                        {
                            CardType *type=cardTypes[k];
                            if(need2->filter->filter(CardInfo(type,0,0))) //TODO: potential oddballs like "need yield a red slash"
                            {
                                for(int kk=0;kk<p->transformTable[type].size();kk++)
                                {
                                    Transform *trans=p->transformTable[type][kk];
                                    if(trans->canTransform(type,e,transformYield))
                                    {
                                        transforms_yield.push_back(make_pair(trans,type));
                                        choices.push_back(trans->toString(type));
                                    }
                                }
                            }
                        }
                    }
                }
                if(cancelable) choices.push_back("取消");
                int x=0;
                if(!autoable||choices.size()>1)
                {
                    ostringstream s;
                    s<<"response:"<<t<<":";
                    if(e) s<<e->toString(p);
                    x=p->getChoice(s.str(),choices);
                }
                if(x<triggers.size())
                {
                    pair<Trigger*,void*> tr=triggers[x];
                    if(tr.first->trigger(e,tr.second)) triggerDone[tr.first].push_back(tr.second);
                }
                else if((x-=triggers.size())<cards.size())
                {
                    Card *c=cards[x];
                    (new PreUseStruct(p,c,t,e))->use();
                }
                else if((x-=cards.size())<transforms_use.size())
                {
                    pair<Transform*,CardType*> trans=transforms_use[x];
                    vector<Card*> c=trans.first->chooseCards(trans.second,e);
                    if(!c.empty()) (new PreUseStruct(p,c,CardInfo(trans.second,c),t,e,trans.first))->use();
                }
                else if((x-=transforms_use.size())<yields.size())
                {
                    Card *c=yields[x];
                    (new YieldEvent(p,c,e))->happen();
                }
                else if((x-=yields.size())<transforms_yield.size())
                {
                    pair<Transform*,CardType*> trans=transforms_yield[x];
                    vector<Card*> c=trans.first->chooseCards(trans.second,e);
                    if(!c.empty()) (new YieldEvent(p,c,CardInfo(trans.second,c),e,trans.first))->happen();
                }
                else break;
                if(!e->curTiming)
                {
                    e->curTiming=nTimings;
                    throw DisturbedException(i);
                }
            }
            while(1);
        }
    }
}

void Game::applyStatics(StaticValue sv, void *value, void *data)
{
    for(int i=0;i<3;i++) for(int j=0;j<staticTable[sv][i].size();j++) staticTable[sv][i][j]->apply(value,data);
}

void Game::doPrimitive(PrimitiveEvent *pe)
{
	game->timeline.push_back(pe);
    for(int i=0;i<nPlayer;i++) players[i]->inform(pe->toString(players[i]));
    pe->happen();
}

void Game::shuffle()
{
	vector<Card*> cards;
    vector<MoveStruct*> d;
    for(Card *c=discardPile.next;c!=&discardPile;c=c->next)
    {
        cards.push_back(c);
        d.push_back(new MoveStruct(c,&deck));
    }
    (new MoveEvent(d))->happen();
    d.clear();
    random_shuffle(cards.begin(),cards.end());
	for(int i=0;i<cards.size();i++) d.push_back(new MoveStruct(cards[i],&deck));
    doPrimitive(new PrimitiveMoveEvent(d));
}

vector<Card*> Game::getTopCards(int n)
{
	vector<Card*> res;
	if(deck.size<n)
    {
		if(deck.size+discardPile.size<n)
		{
            throw GameOverException();
		}
		else shuffle();
    }
	Card* c=deck.next;
	for(int i=0;i<n;i++)
	{
		res.push_back(c);
		c=c->next;
	}
	return res;
}

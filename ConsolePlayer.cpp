#include "ConsolePlayer.h"
#include <QDebug>
#include "mainwindow.h"
#include <QInputDialog>
#include <QApplication>
#include <cstdlib>
#include <unistd.h>
#include <unistd.h>
#include <QString>
#include <string>
#include <QCoreApplication>
#include <QTimer>
#include <QPainter>
#include <vector>



string ConsolePlayer::roleString[4]={"主公","忠臣","反贼","内奸"};
string ConsolePlayer::natureString[3]={"","雷属性","火属性"};




ConsolePlayer::ConsolePlayer(string n)
{
    name=n;
}

string ConsolePlayer::parseZone(string s)
{
    if(s=="deck") return "牌堆";
    if(s=="resArea") return "处理区";
    if(s=="discardPile") return "弃牌堆";
    int i=s.find_first_of(':');
    string head=s.substr(0,i),tail=s.substr(i+1);
    if(head=="hand") return tail+"的手牌";
    if(head=="equipArea") return tail+"的装备区";
    if(head=="judgeArea") return tail+"的判定区";
    if(head=="onGeneral") return tail+"武将牌上";
    if(head=="byGeneral") return tail+"武将牌旁";
    return s;
}

void ConsolePlayer::inform(string message)
{
    QCoreApplication::processEvents();
    if(message.length())
    {



        //cout<<"["<<name<<"] ";

        //CGlobal::ww->textedit->setGeometry(300, 300, 300, 300);


        CGlobal::CurrentPlayer = name[7]-'0';

        std::string a = "[" + name + "]" + " : ";

        if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(a);
        QCoreApplication::processEvents();

        int i=message.find_first_of(':');
        string head=message.substr(0,i),tail=message.substr(i+1);
        if(head=="role")
        {
            std::string a = "Your Role: " + roleString[atoi(tail.c_str())] + '\n';
            //cout << a << endl;
            if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(a);
            QCoreApplication::processEvents();
        }
        else if(head=="lord") 
        {
        //cout<<"主公是玩家"<<tail;
        std::string a = "主公是 Player" + tail + '\n';
        if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(a);
        QCoreApplication::processEvents();
        }
        else if(head=="init_")
        {
            //cout<<"你的起始手牌是";
            std::string a = "你的起始手牌是 ";
            if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(a);
            QCoreApplication::processEvents();
            while((i=tail.find_first_of(';'))!=string::npos)
            {
                //cout<<tail.substr(0,i);
                std::string a = tail.substr(0, i);
                if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(a);
                QCoreApplication::processEvents();
                tail=tail.substr(i+1);
                if(!tail.empty()) {
                    //cout<<"，";
                    std::string a = ", ";
                    if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(a);
                    QCoreApplication::processEvents();
                }
                if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("\n");
                QCoreApplication::processEvents();
            }
        }
        else if(head=="move")
        {
            while((i=tail.find_first_of(';'))!=string::npos)
            {

                int j=tail.find_first_of('-'),k=tail.find_first_of('@');
                string card=tail.substr(0,k),src=tail.substr(k+1,j-k-1),dest=tail.substr(j+1,i-j-1);
                if(card=="hidden") card="一张牌";
                //cout<<parseZone(src)<<"的"<<card<<"移动到"<<parseZone(dest);
                std::string a = parseZone(src) + "的" + card + "移动到" + parseZone(dest);
                if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(a);
                QCoreApplication::processEvents();
                tail=tail.substr(i+1);
                if(!tail.empty()) {

                    //cout<<"，";
                    if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(", ");
                    QCoreApplication::processEvents();
                }
                if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("\n");
                QCoreApplication::processEvents();
            }
        }
        else if(head=="damage")
        {
            i=tail.find_first_of(':');
            string source=tail.substr(0,i);
            tail=tail.substr(i+1);
            i=tail.find_first_of(':');
            string player=tail.substr(0,i);
            tail=tail.substr(i+1);
            i=tail.find_first_of(':');
            int value=atoi(tail.substr(0,i).c_str()),nature=atoi(tail.substr(i+1).c_str());
            if(source.empty()) {
                //cout<<player<<"受到";
                if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("受到");
                QCoreApplication::processEvents();
            }
            else {
                //cout<<source<<"对"<<player<<"造成";
                std::string a = source + "对" + player + "造成";
                if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(a);
                QCoreApplication::processEvents();
            }
                //cout<<value<<"点"<<natureString[nature]<<"伤害";
           if(CGlobal::CurrentPlayer == CGlobal ::HumanPlayer) CGlobal::ww->textedit->insertPlainText(QString::number(value));
            std::string c = "点" + natureString[nature] + "伤害";
            if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(c);
            QCoreApplication::processEvents();
        }
        else if(head=="hp")
        {
            i=tail.find_first_of(':');
            string player=tail.substr(0,i);
            tail=tail.substr(i+1);
            //cout<<player<<"的体力："<<tail;
            if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(player + "体力" + tail + "\n");


                    for(int i=0;i<5;i++)
                        CGlobal::HumanplayerHP[i]->close();


                    for(int i=0;i<game->players[CGlobal::HumanPlayer]->hp;i++)
                    {
                        switch(game->players[CGlobal::HumanPlayer]->hp)
                        {
                        case 1:CGlobal::HumanplayerHP[4-i]->setPixmap(*CGlobal::red);break;
                        case 2:CGlobal::HumanplayerHP[4-i]->setPixmap(*CGlobal::orange);break;
                        case 3:CGlobal::HumanplayerHP[4-i]->setPixmap(*CGlobal::yellow);break;
                        case 4:CGlobal::HumanplayerHP[4-i]->setPixmap(*CGlobal::green);break;
                        case 5:CGlobal::HumanplayerHP[4-i]->setPixmap(*CGlobal::deepgreen);break;
                        }

                        CGlobal::HumanplayerHP[4-i]->show();
                    }

                    for(int j=0;j<game->nPlayer;j++)
                    {
                        if(j!=CGlobal::HumanPlayer)
                        {
                            for(int i=0;i<5;i++)
                            {
                                CGlobal::otherplayerHP[(-j+game->nPlayer+CGlobal::HumanPlayer-1)%game->nPlayer][i]->close();
                            }

                            for(int i=0;i<game->players[j]->hp;i++)
                            {
                                switch(game->players[j]->hp)
                                {
                                case 1:CGlobal::otherplayerHP[(-j+game->nPlayer+CGlobal::HumanPlayer-1)%game->nPlayer][4-i]->setPixmap(*CGlobal::smallred);break;
                                case 2:CGlobal::otherplayerHP[(-j+game->nPlayer+CGlobal::HumanPlayer-1)%game->nPlayer][4-i]->setPixmap(*CGlobal::smallorange);break;
                                case 3:CGlobal::otherplayerHP[(-j+game->nPlayer+CGlobal::HumanPlayer-1)%game->nPlayer][4-i]->setPixmap(*CGlobal::smallyellow);break;
                                case 4:CGlobal::otherplayerHP[(-j+game->nPlayer+CGlobal::HumanPlayer-1)%game->nPlayer][4-i]->setPixmap(*CGlobal::smallgreen);break;
                                case 5:CGlobal::otherplayerHP[(-j+game->nPlayer+CGlobal::HumanPlayer-1)%game->nPlayer][4-i]->setPixmap(*CGlobal::smalldeepgreen);break;
                                }


                                CGlobal::otherplayerHP[(-j+game->nPlayer+CGlobal::HumanPlayer-1)%game->nPlayer][4-i]->show();
                            }
                        }
                    }




            QCoreApplication::processEvents();
        }
        else if(head=="dying")
        {
            //cout<<tail<<"进入濒死状态";
            if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(tail + "进入濒死状态\n");
            QCoreApplication::processEvents();
        }
        else if(head=="death")
        {
            //cout<<tail<<"死亡";

            if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(tail + "死亡\n");
            QCoreApplication::processEvents();



            int dead = tail[7] - '0';

            if(dead!=CGlobal::HumanPlayer)
          {

            int x, y;
            switch ((- dead + CGlobal::HumanPlayer + game->nPlayer - 1) % game->nPlayer) {
            case 0:x=50;y=250;break;
            case 1:x=150;y=40;break;
            case 2:x=325;y=40;break;
            case 3:x=500;y=40;break;
            case 4:x=675;y=40;break;
            case 5:x=850;y=40;break;
            case 6:x=950;y=250;break;
            }

            QPixmap dead1(":/other/other image/unknown.png");
            CGlobal::Dead = new QLabel(CGlobal::ww);
            CGlobal::Dead->setGeometry(x,y+50,dead1.width(),dead1.height());
            CGlobal::Dead->setPixmap(dead1);
            //CGlobal::Dead[i]->close();

            int deadrole;
            if(game->players[dead]->role==Lord)
                deadrole=0;
            else if(game->players[dead]->role==Loyalist)
                deadrole=1;
            else if(game->players[dead]->role==Rebel)
                deadrole=2;
            else if(game->players[dead]->role==Renegade)
                deadrole=3;
            CGlobal::roleslabel[(-dead+game->nPlayer+CGlobal::HumanPlayer-1)%game->nPlayer] = new QLabel(CGlobal::ww);
            CGlobal::roleslabel[(-dead+game->nPlayer+CGlobal::HumanPlayer-1)%game->nPlayer]->setGeometry(CGlobal::otherplayerzonelabel[(-dead+game->nPlayer+CGlobal::HumanPlayer-1)%game->nPlayer]->x(),CGlobal::otherplayerzonelabel[(-dead+game->nPlayer+CGlobal::HumanPlayer-1)%game->nPlayer]->y(),50,70);
            QPixmap deadpix(CGlobal::roleslabel[0]->width(),CGlobal::roleslabel[0]->height());
            QPainter deadpainter(&deadpix);
            deadpainter.drawPixmap(0,0,CGlobal::roleslabel[0]->width(),CGlobal::roleslabel[0]->height(),*CGlobal::rolespix[deadrole]);
            CGlobal::roleslabel[(-dead+game->nPlayer+CGlobal::HumanPlayer-1)%game->nPlayer]->setPixmap(deadpix);
            //CGlobal::roleslabel[(-lordId+nPlayer+CGlobal::HumanPlayer-1)%nPlayer]->setWindowFlags(Qt::WindowStaysOnTopHint);
            CGlobal::roleslabel[(-dead+game->nPlayer+CGlobal::HumanPlayer-1)%game->nPlayer]->show();


            CGlobal::Dead->show();





          }
            else if(dead==CGlobal::HumanPlayer)
          {
                QPixmap dead1(":/other/other image/unknown.png");
                CGlobal::Dead = new QLabel(CGlobal::ww);
                CGlobal::Dead->setGeometry(500,600,dead1.width(),dead1.height());
                CGlobal::Dead->setPixmap(dead1);
                //CGlobal::Dead[i]->close();

                CGlobal::Dead->show();
          }





            if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(tail + "死亡\n");
            QCoreApplication::processEvents();
        }
        else if(head=="death_role")
        {
            i=tail.find_first_of(':');
            //cout<<tail.substr(0,i)<<"的身份是"<<roleString[atoi(tail.substr(i+1).c_str())];
            if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(tail.substr(0, i) + "的身份是" + roleString[atoi(tail.substr(i+1).c_str())]);
            QCoreApplication::processEvents();
        }
        else if(head=="use"||head=="yield")
        {
            string action=head=="use"?"使用":"打出";
            i=tail.find_first_of(':');
            string player=tail.substr(0,i);
            tail=tail.substr(i+1);
            i=tail.find_first_of(':');
            string card=tail.substr(0,i);
            tail=tail.substr(i+1);
            i=card.find_first_of('<');
            if(i==string::npos) {
                if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(player + action + "了" + card);
                QCoreApplication::processEvents();
            } //cout<<player<<action<<"了"<<card;
            else
            {
                string info=card.substr(0,i),trans=card.substr(i+1);
                i=trans.find_first_of('<');
                string list=trans.substr(i+1);
                trans=trans.substr(0,i);
                //cout<<player<<"发动"<<trans<<"将";
                if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(player + "发动" + trans + "将\n");
                QCoreApplication::processEvents();
                while((i=list.find_first_of(';'))!=string::npos)
                {
                    //cout<<list.substr(0,i);
                    if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(list.substr(0, i));
                    QCoreApplication::processEvents();
                    list=list.substr(i+1);
                    if(!list.empty()) //cout<<"、";
                        if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("、");
                    QCoreApplication::processEvents();
                }
                //cout<<"当"<<info<<action;
                if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("当" + info + action + "\n");
                QCoreApplication::processEvents();
            }
            if(head=="use"&&!tail.empty())
            {
                //cout<<"，目标是";
                if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("，目标是");
                QCoreApplication::processEvents();
                while((i=tail.find_first_of(';'))!=string::npos)
                {
                    //cout<<tail.substr(0,i);
                    if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(tail.substr(0, i));
                    QCoreApplication::processEvents();
                    tail=tail.substr(i+1);

                    if(!tail.empty()) //cout<<"，";
                        if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(", ");
                    QCoreApplication::processEvents();
                }
            }
        }
        else if(head=="resolve")
        {
            i=tail.find_first_of(':');
            string player=tail.substr(0,i);
            tail=tail.substr(i+1);
            i=tail.find_first_of(':');
            string card=tail.substr(0,i);
            tail=tail.substr(i+1);
            if(!player.empty())
                //cout<<player<<"使用的";
                if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(player + "使用的");
            QCoreApplication::processEvents();
            //cout<<card;
            if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(card);
            QCoreApplication::processEvents();
            if(!tail.empty()) //cout<<"对"<<tail;
                if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("对" + tail);
            QCoreApplication::processEvents();
            //cout<<"结算";
            if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("结算");
            QCoreApplication::processEvents();
        }
        else if(head=="non-effective")
        {
            i=tail.find_first_of(':');
            tail=tail.substr(i+1);
            i=tail.find_first_of(':');
            string player=tail.substr(0,i);
            tail=tail.substr(i+1);
            i=tail.find_first_of(':');
            string card=tail.substr(0,i);
            tail=tail.substr(i+1);
            if(!player.empty()) //cout<<player<<"使用的";
                if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("使用的");
            QCoreApplication::processEvents();
            //cout<<card;
            if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(card);
            QCoreApplication::processEvents();
            if(!tail.empty()) //cout<<"对"<<tail;
                if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("对" + tail);
            QCoreApplication::processEvents();
            //cout<<"无效";
            if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("无效");
            QCoreApplication::processEvents();
        }
        else if(head=="error")
        {
            if(tail=="cannot_use") //cout<<"没有合理的目标！";
            {if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("没有合理的目标！ ");
            QCoreApplication::processEvents();}

            else if(tail=="illegal_target") //cout<<"目标不合法！";
                if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("目标不合法！");
            QCoreApplication::processEvents();
        }
        else //cout<<message;
            if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(message);
        QCoreApplication::processEvents();
        //cout<<endl;
            if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("\n");
            QCoreApplication::processEvents();
    }
}

int ConsolePlayer::getChoice(string reason, const vector<string> &choices)
{
	int res;
    //cout<<"["<<name<<"] ";
    CGlobal::CurrentPlayer = name[7]-'0';

    if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("[" + name + "]");

    QCoreApplication::processEvents();
    int i=reason.find_first_of(':');
    string head=reason.substr(0,i),tail=reason.substr(i+1);
    if(head=="response")
    {
        i=tail.find_first_of(':');
        int timing=atoi(tail.substr(0,i).c_str());
        string event=tail.substr(i+1);
        if(timing==12) //cout<<"出牌阶段，";
            if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("出牌阶段， ");
        QCoreApplication::processEvents();
        if(timing==21) //cout<<"牌生效前，";
            if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("牌生效前， ");
        QCoreApplication::processEvents();
        if(timing==34) //cout<<"处于濒死状态，";
            if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("处于濒死状态， ");
        QCoreApplication::processEvents();
        //cout<<"请响应：";
        if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("请响应：");
        QCoreApplication::processEvents();
    }
    else if(head=="card")
    {
        i=tail.find_first_of(':');
        string head2=tail.substr(0,i),tail2=tail.substr(i+1);
        if(head2=="discard")
        {
            if(tail2=="discard_phase") //cout<<"弃牌阶段，";
               { if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("弃牌阶段，");
            QCoreApplication::processEvents();}
            else //cout<<tail2<<"，";
                if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(tail2 + ", ");
                QCoreApplication::processEvents();
            //cout<<"请弃牌：";
            if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("请弃牌： ");
            QCoreApplication::processEvents();
        }
        else //cout<<"请选择牌：";
            if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("请选择牌： ");
        QCoreApplication::processEvents();
    }
    else if(head=="target")
    {
        //cout<<"请选择目标：";
        if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("请选择目标: ");
        QCoreApplication::processEvents();
    }
    else //cout<<reason;
        if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(reason);
    QCoreApplication::processEvents();
    //cout<<"\n";
    if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("\n");
    QCoreApplication::processEvents();
    for(int i=0;i<choices.size();i++)
    {
        //cout<<i<<". ";
        if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(QString::number(i,10).toStdString());
        QCoreApplication::processEvents();
        if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(". ");
        QCoreApplication::processEvents();
        if(head=="card")
        {
            int j=choices[i].find_first_of('@');
            std::string card=choices[i].substr(0,j);
            std::string zone=choices[i].substr(j+1);
            if(card=="cancel") {
                //cout<<zone;
                if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(zone);
                QCoreApplication::processEvents();
            }
            else
            {
                if(card=="hidden") card="一张牌";
                if(zone!="hand:"+name) //cout<<parseZone(zone)+"的";
                    if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(parseZone(zone) + "的");
                QCoreApplication::processEvents();
                //cout<<card;
                if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(card);
                QCoreApplication::processEvents();
            }
        }

        /*for(int i=0;i<choices.size();i++)
        {
            cout<<i<<". ";
            if(head=="card")
            {
                int j=choices[i].find_first_of('@');
                string card=choices[i].substr(0,j),zone=choices[i].substr(j+1);
                if(card=="cancel") cout<<zone;
                else
                {
                    if(card=="hidden") card="一张牌";
                    if(zone!="hand:"+name) cout<<parseZone(zone)+"的";
                    cout<<card;
                }
            }
            else cout<<choices[i];
            cout<<"\n";
        }*/

        else //cout<<choices[i];
        {
            if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT(choices[i]);
            QCoreApplication::processEvents();
        }
            //cout<<"\n";
        if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("\n");
        QCoreApplication::processEvents();
    }
    //cout<<"请选择数字：";
    if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("请选择数字： ");


    //cout.flush();



   /*while(1)
   {
       QCoreApplication::processEvents();
       int a;
       a=1+1;
       if(CGlobal::inputbutton_clicked==1)
           break;
   }

   res=CGlobal::inputtemp;
   CGlobal::inputbutton_clicked=0;*/

    if(CGlobal::CurrentPlayer == CGlobal::HumanPlayer&&CGlobal::AutoOrNot==0){

  CGlobal::ww->textinput->setFocus();
   for(int i=0;;i++)
    {  QCoreApplication::processEvents();
        int a;
        a=1+1;
        if(CGlobal::inputbutton_clicked==1||CGlobal::ww->textinput->toPlainText().toStdString()[CGlobal::ww->textinput->toPlainText().toStdString().length()-1]=='\n')
            break;

    }
   CGlobal::inputtemp=CGlobal::ww->textinput->toPlainText().toInt();
   CGlobal::ww->textinput->clear();
   CGlobal::ww->textedit->setFocus();
   CGlobal::ww->textedit->moveCursor(QTextCursor::End);

    res=CGlobal::inputtemp;}

    else
    {
        //sleep(1);
        int i=reason.find_first_of(':');
        string head=reason.substr(0,i),tail=reason.substr(i+1);
        if(CGlobal::CurrentPlayer != game->curPlayer)//////去掉了CurrentTurn
        {
           // if(choices[0] != "作弊(请勿轻易作弊!可能导致系统崩溃!)")
                res = 0;
        }

        else if(head == "target") {
            if(choices.size() != 0) {

            if(game->players[CGlobal::CurrentPlayer]->role == Lord || game->players[CGlobal::CurrentPlayer]->role == Loyalist)
            {
                vector <int> enemy;
                for(int i = 0; i < game->nPlayer; ++i)
                {
                    if(game->players[i]->role == Renegade || game->players[i]->role == Rebel)
                        enemy.push_back(i);
                }
                for(int j = 0; j < choices.size(); ++j)
                {
                    for(int k = 0; k < enemy.size(); ++k)
                    {
                        if(choices[j][7] - '0' == enemy[k])
                            res = j;
                    }
                }
                if(res == 0 || res == 1 || res == 2 || res == 3 || res == 4 || res == 5 || res == 6)
                    ;
                else
                    res = choices.size() - 1;
            }


            else if(game->players[CGlobal::CurrentPlayer]->role == Rebel)
            {
                vector <int> enemy;
                for(int i = 0; i < game->nPlayer; ++i)
                {
                    if(game->players[i]->role == Lord)
                        enemy.push_back(i);
                }
                for(int i = 0; i < game->nPlayer; ++i)
                {
                    if(game->players[i]->role == Loyalist)
                        enemy.push_back(i);
                }
                for(int j = 0; j < choices.size(); ++j)
                {
                    for(int k = 0; k < enemy.size(); ++k)
                    {
                        if(choices[j][7] - '0' == enemy[k])
                            res = j;
                    }
                }
                if(res == 0 || res == 1 || res == 2 || res == 3 || res == 4 || res == 5 || res == 6 || res == 7 )
                    ;
                else
                    res = choices.size() - 1;
            }

            else {
                res = rand() % (choices.size());
            }
        }
}



        else {
               /* int a = rand() % 100;

                if(a < 6 && choices[0] != "作弊(请勿轻易作弊!可能导致系统崩溃!)")
                    res = 0;
                else */
                    res = 1+rand()%(choices.size());
        }
     }

    CGlobal::inputbutton_clicked=0;

   /*sleep(3);
   res=1;*/

   /*bool *ok=new bool;
    int *temp=new int;
    *ok=0;
    *temp=QInputDialog::getInt(0,"","",0,0,1000,1,ok);
    if(*temp==999)
        exit(0);
    if(*ok)
        res=*temp;
    free(ok);
    free(temp);*/

    //cin>>res;

    //cin.clear();
    //cin.ignore(65535,'\n');
    if(res<0||res>=choices.size()) return choices.size()-1;
    return res;
}

vector<int> ConsolePlayer::getMultiChoice(string reason, const vector<string> &choices, int max, const vector<bool> &mandatory)
{
    vector<int> res;
    vector<bool> selected;
    vector<string> newChoices;
    int i,n=choices.size(),num=0;
    for(i=0;i<n;i++)
    {
        selected.push_back(mandatory[i]);
        if(mandatory[i]) {num++;newChoices.push_back("* "+choices[i]);}
        else newChoices.push_back(choices[i]);
    }
    newChoices.push_back("取消");
    if(num) newChoices.push_back("确定");
    if(max>=0&&num>max) return res;
    if(max>choices.size()) max=choices.size();
    if(num!=max)
    {
        if(max==1)
        {
            i=getChoice(reason,newChoices);
            if(i<n) res.push_back(i);
            return res;
        }
        while(1)
        {
            i=getChoice(reason,newChoices);
            if(i==n) return res;
            if(i==n+1) break;
            if(selected[i]) if(mandatory[i]) //cout<<"这一项必须选择！\n";
              {  if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("这一项必须选择！\n");
            QCoreApplication::processEvents();}
            else {selected[i]=false;newChoices[i]=choices[i];if(--num==0) newChoices.pop_back();}
            else if(num==max) //cout<<"已经达到个数上限！\n";
               { if(CGlobal::CurrentPlayer==CGlobal::HumanPlayer) CGlobal::QOUT("已经达到个数上限！\n");
            QCoreApplication::processEvents();}
            else {selected[i]=true;newChoices[i]="* "+choices[i];if(num++==0) newChoices.push_back("确定");}
        }
    }
    for(i=0;i<n;i++) if(selected[i]) res.push_back(i);
    return res;
}

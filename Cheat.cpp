#include "Lib.h"
#include "Cheat.h"
#include "DamageEvent.h"
#include <QDebug>
#include <QInputDialog>
#include <cstdlib>
#include <unistd.h>
#include "mainwindow.h"

Cheat::Cheat(Player *p) : Trigger(p)
{
    timings.push_back(doMainPhase);
}

vector<void *> Cheat::getTrigger(Event *e, vector<void*> past)
{
    return vector<void*>(1,(void*)NULL);
}

bool Cheat::trigger(Event *e, void* index)
{
    vector<string> choices;
    int i,v;
    for(i=0;i<game->nPlayer;i++) choices.push_back(game->players[i]->toString());
    i=player->getChoice("choose a player to damage",choices);
    //cout<<"How many damage? ";
    CGlobal::QOUT("How many damage? ");
    //cout.flush();

   /*bool *ok=new bool;
    int *temp=new int;
    *ok=0;
    *temp=QInputDialog::getInt(0,"","",0,0,1000,1,ok);
    if(*temp==999)
        exit(0);
    if(*ok)
        v=*temp;
    free(ok);
    free(temp);*/
   CGlobal::ww->textinput->setFocus();
   for(int i=0;;i++)
    {
        int a;
        a=1+1;

        if(CGlobal::inputbutton_clicked==1)
            break;

    }
   CGlobal::ww->textedit->setFocus();
   CGlobal::ww->textedit->moveCursor(QTextCursor::End);

    v=CGlobal::inputtemp;
    CGlobal::inputbutton_clicked=0;

    /*while(1)
    {
        sleep(1);
        if(CGlobal::inputbutton_clicked==1)
            break;
    }

    v=CGlobal::inputtemp;
    CGlobal::inputbutton_clicked=0;*/




    (new DamageEvent(game->players[i],player,v))->happen();
    return true;
}

string Cheat::toString(Event *e, void *index)
{
    return "作弊(请勿轻易作弊!可能导致系统崩溃!)";
}

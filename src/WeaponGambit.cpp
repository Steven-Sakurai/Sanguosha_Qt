#include "Lib.h"
#include "WeaponGambit.h"
#include "NeedUseEvent.h"
#include "Slash.h"

bool WeaponGambit::legalityCheck(Player *target, PreUseStruct *d)
{
    if(target==d->player) return false;
    return target->getEquip(Weapon);
}

WeaponGambit::WeaponGambit() : NonEquipCard("借刀杀人",Trick)
{
}

void WeaponGambit::resolve(TargetStruct *target, UseStruct *d)
{
    Player *user=d->data->player,*tar=target->player,*tar2=(Player*)target->tag;
    if(!(new NeedUseEvent(tar,new NameFilter<Slash>(),vector<Player*>(1,tar2)))->happen_success())
        if(Card* weapon=tar->getEquip(Weapon))
            (new MoveEvent(vector<MoveStruct*>(1,new MoveStruct(weapon,&user->hand))))->happen();
}

bool WeaponGambit::extraChoice(UseStruct *d)
{
    //TODO
    vector<Player*> choices;
    vector<string> choiceStrings;
    for(int i=0;i<d->targets.size();i++)
    {
        TargetStruct *target=d->targets[i];
        choices.clear();choiceStrings.clear();
        int j;
        CardType *slash=game->getCardType<Slash>();
        for(j=game->curPlayer;j<game->curPlayer+game->nPlayer;j++)
        {
            Player *p=game->players[j%game->nPlayer];
            if(slash->isLegalTarget(p,target->player))
            {
                choices.push_back(p);
                choiceStrings.push_back(p->toString());
            }
        }
        choiceStrings.push_back("取消");
        j=d->data->player->getChoice("请选择杀的目标：",choiceStrings);
        if(j>=choices.size()) return false;
        target->tag=choices[j];
    }
    return true;
}

string WeaponGambit::tagToString(void *tag)
{
    return "（杀"+((Player*)tag)->toString()+"）";
}

#include "Lib.h"
#include "UseStruct.h"
#include "CardType.h"

UseStruct::UseStruct(PreUseStruct *d, const vector<Player *> &tar, bool sp)
{
    data=d;isSpecial=sp;
    for(int i=0;i<tar.size();i++) targets.push_back(new TargetStruct(tar[i]));
}

UseStruct::~UseStruct()
{
    delete data;
    for(int i=0;i<targets.size();i++) delete targets[i];
}

bool UseStruct::isLegal()
{
    if(!data->isLegal()) return false;
    CardType* name=data->info.name;
    int maxTargets=data->getMaxTargets();
    if(targets.size()>maxTargets) return false;
    if(targets.empty()&&maxTargets>0) return false;
    int i;
    for(i=0;i<targets.size();i++) if(!name->isLegalTarget(targets[i]->player,data)) return false;
    for(int j=0;j<game->nPlayer;j++)
    {
        Player *p=game->players[j];
        if(name->isMandatoryTarget(p,data))
        {
            for(i=0;i<targets.size()&&targets[i]->player!=p;i++);
            if(i==targets.size()) return false;
        }
    }
    return true;//TODO: Strange prohibit skills
}

#include "Lib.h"
#include "Friendship.h"
#include "RecoverEvent.h"
#include "ResolveEvent.h"

bool Friendship::legalityCheck(Player *target, PreUseStruct *d)
{
    return true;
}

Friendship::Friendship() : NonEquipCard("桃园结义",Trick)
{
    maxTargets=game->nPlayer;
}

void Friendship::resolve(TargetStruct *target, UseStruct *d)
{
    (new RecoverEvent(target->player))->happen();
}

bool Friendship::isMandatoryTarget(Player *target, PreUseStruct *d)
{
    return isLegalTarget(target,d);
}

vector<SkillEffect *> Friendship::getUseSkill(UseStruct *d)
{
    return vector<SkillEffect*>(1,new FriendshipEffectiveness(d));
}

FriendshipEffectiveness::FriendshipEffectiveness(UseStruct *d)
{
    use=d;influence=useEffectiveness;
}

void FriendshipEffectiveness::apply(void *value, void *data)
{
    bool *v=(bool*)value;
    ResolveEvent *d=(ResolveEvent*)data;
    if(d->data==use&&!d->target->player->getLostHp()) *v=false;
}

#include "Lib.h"
#include "MoveVisibilityEffect.h"
#include "PrimitiveMoveEvent.h"

MoveVisibilityEffect::MoveVisibilityEffect(MoveEvent *e)
{
    event=e;influence=visibilityValue;trying=false;
}

void MoveVisibilityEffect::apply(void *value, void *data)
{
    if(trying) return;
    bool *v=(bool*)value;
    pair<Card*,Player*> *d=(pair<Card*,Player*> *)data;
    Card *c=d->first;
    Player *p=d->second;
    vector<MoveStruct*> testData;
    for(int i=0;i<event->data.size();i++) testData.push_back(new MoveStruct(*event->data[i]));
    PrimitiveMoveEvent testMove(testData);
    testMove.happen();
    trying=true;
    if(c->isVisibleTo(p)) *v=true;
    trying=false;
    testMove.undo();
}

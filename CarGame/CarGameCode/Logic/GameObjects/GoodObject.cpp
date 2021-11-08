#include "GoodObject.h"
#include "../Game.h"
// TODO: add includes

void  GoodObject::onEnter() {
    instances += 1;
   game-> instancesPW(instances);
};

void  GoodObject::onDelete() {
    instances -= 1;
    game->instancesPW(instances);
};

void GoodObject::reset() {
    instances = 0;
};

bool GoodObject::toDelete() {
    return !alive || game->isRebased(this);
 
}

int GoodObject::instances = 0;
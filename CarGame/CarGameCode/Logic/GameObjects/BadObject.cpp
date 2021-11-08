#include "BadObject.h"
#include "../Game.h"
// TODO: add includes

void  BadObject::onEnter() {
    instances += 1;
    game->instancesrocks(instances);
};

void  BadObject::onDelete() {
    instances -= 1;
    game->instancesrocks(instances);
};

void BadObject::reset() {
    instances = 0;
};

bool BadObject::toDelete() {
    return !alive || game->isRebased(this);
}

int BadObject::instances = 0;
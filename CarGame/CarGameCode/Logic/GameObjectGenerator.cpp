#include "GameObjectGenerator.h"


Point2D<int> GameObjectGenerator::generateRandomPosition(Game* game, GameObject* o) {
    Point2D<int> temp;
    int y = rand() % (game->getWindowHeight() - (game->ROCKS_HEIGHT / 2));
    int x = (rand() % game->getroadlenght()+300);
    return Point2D<int>(x, y);
}

void GameObjectGenerator::addInRandomPosition(Game* game, GameObject* o) {
    Point2D<int> temp =generateRandomPosition( game,  o);
    o->setPosition(temp.getX(),temp.getY());
    o->setDimension(game->ROCKS_WIDTH,game->ROCKS_HEIGHT);
    if(!game->hasCollision(o))
     game->add(o);
   
}



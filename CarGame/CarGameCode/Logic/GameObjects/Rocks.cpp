#include "Rocks.h"
#include "../Game.h"

Rocks::Rocks(Game *game): BadObject(game)
{
}
void Rocks::draw() {
    drawTexture(game->getTexture(rockTexture));   
};

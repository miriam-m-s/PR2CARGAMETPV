#include "PowerUp.h"
#include "../Game.h"
PowerUp::PowerUp(Game* game) :GoodObject(game)
{

}
void PowerUp::draw()
{
	drawTexture(game->getTexture(powerupTexture));
}

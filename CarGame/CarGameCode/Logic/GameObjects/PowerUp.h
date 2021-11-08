#pragma once
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GoodObject.h";


class PowerUp: public GoodObject {
public:
    PowerUp(Game* game);
    void draw();
    void update() {};

};

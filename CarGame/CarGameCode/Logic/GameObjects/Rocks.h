#pragma once
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "BadObject.h";

class Rocks : public BadObject {
public:
    Rocks(Game* game);
    void draw() ;
    void update() {};
   
};






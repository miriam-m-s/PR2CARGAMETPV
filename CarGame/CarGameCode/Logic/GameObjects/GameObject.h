#pragma once
#ifndef CARGAME_GAMEOBJECT_H
#define CARGAME_GAMEOBJECT_H

// TODO: add includes
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "Collider.h"
class Game;

class GameObject :public Collider {

    Point2D<double> pos;
    int w, h;

protected:
    Game* game;
    Texture* texture;

    void drawTexture(Texture* texture);
public:

    GameObject(Game* game);
    virtual ~GameObject() {};

    virtual void draw() = 0;
    //virtual void drawDebug();
    virtual void update() = 0;

    virtual bool toDelete() { return false; }
    virtual void onEnter() {};
    virtual void onDelete() {};

    void setPosition(double x, double y);
    void setDimension(double width, double height);

    int getWidth() { return w; };
    int getHeight() { return h; };

    int getX() { return pos.getX(); };
    int getY() { return pos.getY(); };
    virtual SDL_Rect getCollider();
    //virtual SDL_Rect getCenter();

    bool collide(SDL_Rect other);
};
#endif //CARGAME_GAMEOBJECT_H



#include "GameObjectContainer.h"
#include "GameObjects/GameObject.h"
#include "GameObjects/Collider.h"

void GameObjectContainer::update()
{
    for (int i = 0; i < gameObjects.size(); i++) {
        if (gameObjects[i]->toDelete()) {
            gameObjects[i]->onDelete();
            delete(gameObjects[i]);
            cout << "holanueh";
            gameObjects.erase(gameObjects.begin() + i);
        }
    }
}

void GameObjectContainer::draw()
{
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->draw();
	}
}


void GameObjectContainer::add(GameObject* gameObject) {
    gameObjects.push_back(gameObject);
    gameObject->onEnter();
}

bool GameObjectContainer::hasCollision(GameObject* g) {
    for (auto o : gameObjects) {
        if(SDL_HasIntersection(&o->getCollider(), &g->getCollider()))
            return true;
    }
    return false;
}

vector<Collider*> GameObjectContainer::getCollisions(GameObject* g)
{
    vector<Collider*>colisiones;
    for (int i = 0; i < gameObjects.size(); i++) {
        if (SDL_HasIntersection(&gameObjects[i]->getCollider(), &g->getCollider())) {
           colisiones.push_back(gameObjects[i]);
        }
    }
    return colisiones;
}

void GameObjectContainer::removeDead() {
  /*for (int i = 0; i < gameObjects.size(); i++) {
        if (gameObjects[i]->getX() < 0 || gameObjects[i]->getX() < car->getX() - car->getWidth()) {
            delete(gameObjects[i]);
            roc.erase(roc.begin() + i);
            numrocks--;
        }
    }*/
  for (int i = 0; i < gameObjects.size(); i++)
  {
      if (gameObjects[i] != nullptr)
          delete(gameObjects[i]);
     gameObjects.erase(gameObjects.begin() + i);
  }
}


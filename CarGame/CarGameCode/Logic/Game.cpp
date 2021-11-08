//
// Created by eys on 20/8/21.
//ERES MUY GUAPO GRACIAS

#include "Game.h"

Game::Game(string name, int width, int height, int roadLength) {
    this->name = name;
    this->roadLength = roadLength;
    this->width = width;
    this->height = height;
    doExit = false;
    //letra
    font = new Font("../Images/Monospace.ttf", 12);
}

void Game::startGame() {
    car = new Car(this);
    car->setDimension(100, 50);
    metafin = new Meta(this);
    metafin->setDimension(50, getWindowHeight());
    metafin->setPosition(roadLength ,height/2);
    car->setPosition(car->getWidth(), height / 2);
    gameObjects = new GameObjectContainer();
    srand(time(NULL));
    GameObjectGenerator::generate(this, 15,5);

}

string Game::getGameName() {
    return name;
}    
void Game:: subir(bool s) {
  if(car!=nullptr)
    car->moveup(s);
}
void Game:: bajar(bool b) {
    if (car != nullptr)
    car->movedown(b);
}
void Game:: acelerar(bool a) {
    if (car != nullptr)
    car->acelerate(a);
}
void Game:: frenar(bool f) {
    if (car != nullptr)
    car->frenar(f);
}
Game::~Game() {
    if(car!=nullptr)
    delete car;
    if (metafin != nullptr)
    delete metafin;
    gameObjects->removeDead();
    if (textureContainer != nullptr)
    delete(textureContainer);
    if(font!=nullptr)
    delete font;
    cout << "[DEBUG] deleting game" << endl;
}

void Game::update(){    
  
    car->update();  
    gameObjects->update();
    if (car->getX() > roadLength)ganar = true;
}

void Game::Colisiones() {
    //int i = 0; bool chocar = false;
    ////COLISION ROCAS
    //while (i < roc.size() && !chocar) {
    //    if (SDL_HasIntersection(&roc[i]->getCollider(), &car->getCollider()))
    //    {
    //        car->Chocar();
    //        if (car->Vidas() == 0) perder = true;
    //        roc[i]->setPosition(0, -3000);
    //        chocar = true;
    //    }
    //    i++;
    //}
    ////COLISON DE META
    //if (SDL_HasIntersection(&metafin->getCollider(), &car->getCollider())) ganar = true;
}

void Game::reiniciar() {
    //INICIALIZAR EL TIEMPO
    timegame = SDL_GetTicks();
    delete(car);
    delete(metafin);
    perder = false;
    ganar = false;
    gameObjects->removeDead();
    startGame();
}
bool Game::Ganar() {
    
    return ganar;
}
bool Game::Perder() {

    return perder;
}
void Game::instancesPW(int s)
{
    vidas = s;
}
void Game::Menu() {
    int x = (getWindowWidth() / 2)-120;
    int y = (getWindowHeight() / 2)-80;
    string s = "Welcome to Super Cars ";
    renderText(s, x, y);
     x = (getWindowWidth() / 2) - 120;
     y = (getWindowHeight() / 2)-60;
    s = "Level:0 ";
    renderText(s, x, y);
    x = (getWindowWidth() / 2) - 120;
    y = (getWindowHeight() / 2) -40;
    s = "Press space to start";
    renderText(s, x, y);
}
void Game::draw(){ 
        car->draw();
        drawInfo();
        gameObjects->draw();
    metafin->draw();
}

bool Game::isRebased(GameObject *o)
{
    if ( o->getX() < car->getX() - car->getWidth()) return true; 
    return false;
}



void Game::add(GameObject* o)
{
    gameObjects->add(o);
}

bool Game::hasCollision(GameObject* o)
{
    return gameObjects->hasCollision(o);
}

void Game::drawInfo() {
    int x = font->getSize() / 2;
    int y = font->getSize() / 2;
    distance = roadLength - car->getX();
    timefinal = SDL_GetTicks() - timegame;

    SDL_Rect rect = {0, 0, getWindowWidth(),
                     int(font->getSize() * 1.8)};
    Box(rect, BLACK).render(renderer);
    
    string s = "Pos: " + to_string(int(car->getX())) + " "
        + to_string(int(car->getY())) + "   Distance: " + to_string(int(distance))
        + "    Speed: " + to_string(float(car->Velocidad())) + "   Power: " + to_string(car->Vidas()) + "     Time: " + to_string(int(timefinal))
        + "    Obstacles: "+ to_string(vidas)+ " :"+to_string(numrocks);
    renderText(s, x, y);
}
void Game::Interfazfinal() {
    if (perder) {
        int x = (getWindowWidth() / 2) - 20;
        int y = (getWindowHeight() / 2) - 60;
        string s = "GAME OVER! ";
        renderText(s, x, y);
    }
    else {
        int x = (getWindowWidth() / 2) - 20;
        int y = (getWindowHeight() / 2) - 60;
        string s = "Congratulations!";
        renderText(s, x, y);
        x = (getWindowWidth() / 2) - 20;
        y = (getWindowHeight() / 2) - 40;
        s = "User wins";
        renderText(s, x, y);
        x = (getWindowWidth() / 2) - 20;
        y = (getWindowHeight() / 2) - 20;
        s = "Time : " + to_string(int(timefinal)) + "ms";
        renderText(s, x, y);
    }
}
void Game::instancesrocks(int l) {
    numrocks = l;
}

void Game::setUserExit() {
    doExit = true;
}

bool Game::isUserExit() {
    return doExit;
}

int Game::getWindowWidth(){
    return width;
}

int Game::getWindowHeight() {
    return height;
}

SDL_Renderer *Game::getRenderer() {
    return renderer;
}

void Game::setRenderer(SDL_Renderer *_renderer) {
    renderer = _renderer;
}

void Game::loadTextures() {
    if(renderer == nullptr)
        throw string("Renderer is null");

    textureContainer = new TextureContainer(renderer);
}

void Game::renderText(string text, int x, int y, SDL_Color color){
    font->render(renderer, text.c_str(), x, y, color);
}



bool Game::doQuit() {
    return isUserExit();
}

Texture *Game::getTexture(TextureName name) {
    return textureContainer->getTexture(name);
}

Point2D<int> Game::getOrigin() {
    return {int(-(car->getX() - car->getWidth())), 0};
}   
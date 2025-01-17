#include "demo/game.h"

int main(int argc, char** argv) { 
    game::GameApp gameApp;

    app::init(&gameApp);
    app::update();
    app::release();

    return 0;
}
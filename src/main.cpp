#include "demo/game.h"
#include "demo/triangle/triangle.h"

int main(int argc, char** argv) { 
    //game::GameApp gameApp;
    game::GameApp gameApp;
    triangle::TriangleApp triangleApp;


    app::IApplication* application = &gameApp;

    if(argc > 1) {
        if(std::string(argv[1]) == "triangle") {
            application = &triangleApp;
        }
    }

    app::init(application);
    app::update();
    app::release();

    return 0;
}
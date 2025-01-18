#include "demo/game.h"
#include "demo/triangle/triangle.h"
#include "demo/color_triangle/color_triangle.h"

int main(int argc, char** argv) { 
    //game::GameApp gameApp;
    game::GameApp gameApp;
    triangle::TriangleApp triangleApp;
    color_triangle::ColorTriangleApp colorTriangleApp;


    app::IApplication* application = &gameApp;

    if(argc > 1) {
        if(std::string(argv[1]) == "triangle") {
            application = &triangleApp;
        } else if(std::string(argv[1]) == "color-triangle") {
            application = &colorTriangleApp;
        }
    }

    app::init(application);
    app::update();
    app::release();

    return 0;
}
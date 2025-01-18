#include "demo/game.h"
#include "demo/triangle/triangle.h"
#include "demo/color_triangle/color_triangle.h"
#include "demo/index_buffer/index_buffer.h"

int main(int argc, char** argv) { 
    //game::GameApp gameApp;
    game::GameApp gameApp;
    triangle::TriangleApp triangleApp;
    color_triangle::ColorTriangleApp colorTriangleApp;
    index_buffer::IndexBufferApp indexBufferApp;

    app::IApplication* application = &gameApp;

    if(argc > 1) {
        if(std::string(argv[1]) == "triangle") {
            application = &triangleApp;
        } else if(std::string(argv[1]) == "color-triangle") {
            application = &colorTriangleApp;
        } else if(std::string(argv[1]) == "index-buffer") {
            application = &indexBufferApp;
        }
    }

    app::init(application);
    app::update();
    app::release();

    return 0;
}
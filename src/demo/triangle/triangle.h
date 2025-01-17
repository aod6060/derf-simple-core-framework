#ifndef TRAINGLE_H
#define TRAINGLE_H



#include "../../core/sys.h"


namespace triangle {
    struct TriangleApp : public app::IApplication {

        glw::Shader vertexShader;
        glw::Shader fragmentShader;
        glw::Program program;

        glw::VertexBuffer vertexBuffer;
        
        virtual void init();
        virtual void handleEvent(SDL_Event* e);
        virtual void update(float delta);
        virtual void render();
        virtual void release();

        virtual void reloadInit();
        virtual void reloadRelease();
    };
}
#endif
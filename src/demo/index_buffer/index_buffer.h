#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H



#include "../../core/sys.h"


namespace index_buffer {
    struct IndexBufferApp : public app::IApplication {

        glw::Shader vertexShader;
        glw::Shader fragmentShader;
        glw::Program program;

        glw::VertexBuffer vertexBuffer;
        glw::VertexBuffer colorBuffer;
        
        glw::IndexBuffer indexBuffer;
        
        float yrot = 0.0f;
        
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
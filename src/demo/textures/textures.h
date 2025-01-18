#ifndef TEXTURES_H
#define TEXTURES_H



#include "../../core/sys.h"


namespace textures {
    struct TexturesApp : public app::IApplication {

        glw::Shader vertexShader;
        glw::Shader fragmentShader;
        glw::Program program;

        glw::VertexBuffer vertexBuffer;
        glw::VertexBuffer colorBuffer;
        glw::VertexBuffer texCoordBuffer;

        glw::IndexBuffer indexBuffer;
        
        glw::Texture2D logoTexture;
        
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
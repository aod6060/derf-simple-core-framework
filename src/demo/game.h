#ifndef GAME_H
#define GAME_H

#include "../core/sys.h"



namespace game {
    struct GameApp : public app::IApplication {
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
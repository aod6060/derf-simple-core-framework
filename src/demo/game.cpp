#include "game.h"




namespace game {

    void GameApp::init() {
        glEnable(GL_DEPTH_TEST);
    }

    void GameApp::handleEvent(SDL_Event* e) {

    }

    void GameApp::update(float delta) {

    }

    void GameApp::render() {
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        glDisable(GL_DEPTH_TEST);
        igw::bind();

        if(config::drawConfigSystem()) {
            return;
        }

        glEnable(GL_DEPTH_TEST);

        igw::unbind();
    }

    void GameApp::release() {

    }

    void GameApp::reloadInit() {
    }

    void GameApp::reloadRelease() {
    }
    
}
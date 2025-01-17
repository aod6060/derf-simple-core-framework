#include "triangle.h"


namespace triangle {

    
    void TriangleApp::init() {
        glEnable(GL_DEPTH_TEST);


    }

    void TriangleApp::handleEvent(SDL_Event* e) {

    }

    void TriangleApp::update(float delta) {

    }

    void TriangleApp::render() {
        glClearColor(0.0, 181.0 / 255.0, 226.0 / 255.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        
    }

    void TriangleApp::release() {

    }

    void TriangleApp::reloadInit() {

    }

    void TriangleApp::reloadRelease() {

    }

}
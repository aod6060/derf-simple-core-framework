#include "triangle.h"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/trigonometric.hpp"


namespace triangle {


    void TriangleApp::init() {
        glEnable(GL_DEPTH_TEST);

        this->vertexShader.init(GL_VERTEX_SHADER, "data/shaders/triangle/triangle.vert.glsl");
        this->fragmentShader.init(GL_FRAGMENT_SHADER, "data/shaders/triangle/triangle.frag.glsl");

        this->program.init({&this->vertexShader, &this->fragmentShader});

        this->program.vertexArray.createAttrib("vertices", 0);

        this->program.bind();
        this->program.uniform.createUniform("proj");
        this->program.uniform.createUniform("view");
        this->program.uniform.createUniform("model");

        this->program.vertexArray.bind();
        this->program.vertexArray.enable("vertices");
        this->program.vertexArray.unbind();

        this->program.unbind();

        this->vertexBuffer.init();

        this->vertexBuffer.add3(0.0f, 1.0f, 0.0f);
        this->vertexBuffer.add3(1.0f, -1.0f, 0.0f);
        this->vertexBuffer.add3(-1.0f, -1.0f, 0.0f);

        this->vertexBuffer.update();

    }

    void TriangleApp::handleEvent(SDL_Event* e) {

    }

    void TriangleApp::update(float delta) {
        this->yrot += 32.0f * delta;

        if(this->yrot > 360.0f) {
            this->yrot -= 360.0f;
        }
    }

    void TriangleApp::render() {
        glClearColor(0.0, 181.0 / 255.0, 226.0 / 255.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        this->program.bind();

        this->program.uniform.setMatrix4("proj", glm::perspective(glm::radians(45.0f), app::getAspect(), 1.0f, 1024.0f));
        this->program.uniform.setMatrix4("view", glm::mat4(1.0f));
        this->program.uniform.setMatrix4("model", 
            glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -5.0f)) *
            glm::rotate(glm::mat4(1.0f), glm::radians(this->yrot), glm::vec3(0.0f, 1.0f, 0.0f))
        );

        this->program.vertexArray.bind();

        this->vertexBuffer.bind();
        this->program.vertexArray.pointer("vertices", 3, GL_FLOAT);
        this->vertexBuffer.unbind();

        glDrawArrays(GL_TRIANGLES, 0, this->vertexBuffer.count() / 3);

        this->program.vertexArray.unbind();

        this->program.unbind();
    }

    void TriangleApp::release() {
        this->vertexBuffer.release();
        this->program.release();
        this->vertexShader.release();
        this->fragmentShader.release();
    }

    void TriangleApp::reloadInit() {

    }

    void TriangleApp::reloadRelease() {

    }

}
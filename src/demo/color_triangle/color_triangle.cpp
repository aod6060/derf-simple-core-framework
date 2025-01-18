#include "color_triangle.h"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/trigonometric.hpp"


namespace color_triangle {


    void ColorTriangleApp::init() {
        glEnable(GL_DEPTH_TEST);

        this->vertexShader.init(GL_VERTEX_SHADER, "data/shaders/color_triangle/color_triangle.vert.glsl");
        this->fragmentShader.init(GL_FRAGMENT_SHADER, "data/shaders/color_triangle/color_triangle.frag.glsl");

        this->program.init({&this->vertexShader, &this->fragmentShader});

        this->program.vertexArray.createAttrib("vertices", 0);
        this->program.vertexArray.createAttrib("colors", 1);

        this->program.bind();
        this->program.uniform.createUniform("proj");
        this->program.uniform.createUniform("view");
        this->program.uniform.createUniform("model");

        this->program.vertexArray.bind();
        this->program.vertexArray.enable("vertices");
        this->program.vertexArray.enable("colors");
        this->program.vertexArray.unbind();

        this->program.unbind();

        this->vertexBuffer.init();

        this->vertexBuffer.add3(0.0f, 1.0f, 0.0f);
        this->vertexBuffer.add3(1.0f, -1.0f, 0.0f);
        this->vertexBuffer.add3(-1.0f, -1.0f, 0.0f);

        this->vertexBuffer.update();


        this->colorBuffer.init();

        this->colorBuffer.add4(1.0f, 0.0f, 0.0f, 1.0f);
        this->colorBuffer.add4(0.0f, 1.0f, 0.0f, 1.0f);
        this->colorBuffer.add4(0.0f, 0.0f, 1.0f, 1.0f);

        this->colorBuffer.update();
    }

    void ColorTriangleApp::handleEvent(SDL_Event* e) {

    }

    void ColorTriangleApp::update(float delta) {
        this->yrot += 32.0f * delta;

        if(this->yrot > 360.0f) {
            this->yrot -= 360.0f;
        }
    }

    void ColorTriangleApp::render() {
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

        this->colorBuffer.bind();
        this->program.vertexArray.pointer("colors", 4, GL_FLOAT);
        this->colorBuffer.unbind();

        glDrawArrays(GL_TRIANGLES, 0, this->vertexBuffer.count() / 3);

        this->program.vertexArray.unbind();

        this->program.unbind();
    }

    void ColorTriangleApp::release() {
        this->colorBuffer.release();
        this->vertexBuffer.release();
        this->program.release();
        this->vertexShader.release();
        this->fragmentShader.release();
    }

    void ColorTriangleApp::reloadInit() {

    }

    void ColorTriangleApp::reloadRelease() {

    }

}
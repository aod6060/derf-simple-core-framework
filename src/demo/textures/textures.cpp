#include "textures.h"


namespace textures {


    void TexturesApp::init() {
        glEnable(GL_DEPTH_TEST);

        this->vertexShader.init(GL_VERTEX_SHADER, "data/shaders/textures/textures.vert.glsl");
        this->fragmentShader.init(GL_FRAGMENT_SHADER, "data/shaders/textures/textures.frag.glsl");

        this->program.init({&this->vertexShader, &this->fragmentShader});

        this->program.vertexArray.createAttrib("vertices", 0);
        this->program.vertexArray.createAttrib("colors", 1);
        this->program.vertexArray.createAttrib("texCoords", 2);

        this->program.bind();
        this->program.uniform.createUniform("proj");
        this->program.uniform.createUniform("view");
        this->program.uniform.createUniform("model");
        this->program.uniform.createUniform("tex0");
        this->program.uniform.set1i("tex0", 0);

        this->program.vertexArray.bind();
        this->program.vertexArray.enable("vertices");
        this->program.vertexArray.enable("colors");
        this->program.vertexArray.enable("texCoords");
        this->program.vertexArray.unbind();

        this->program.unbind();

        this->vertexBuffer.init();

        this->vertexBuffer.add3(-1.0, 1.0, 0.0);
        this->vertexBuffer.add3(1.0, 1.0, 0.0);
        this->vertexBuffer.add3(-1.0, -1.0, 0.0);
        this->vertexBuffer.add3(1.0, -1.0, 0.0);

        this->vertexBuffer.update();


        this->colorBuffer.init();

        this->colorBuffer.add4(1.0f, 0.0f, 0.0f, 1.0f);
        this->colorBuffer.add4(0.0f, 1.0f, 0.0f, 1.0f);
        this->colorBuffer.add4(0.0f, 0.0f, 1.0f, 1.0f);
        this->colorBuffer.add4(1.0f, 1.0f, 0.0f, 1.0f);
        this->colorBuffer.update();

        this->texCoordBuffer.init();

        this->texCoordBuffer.add2(0.0f, 0.0f);
        this->texCoordBuffer.add2(1.0f, 0.0f);
        this->texCoordBuffer.add2(0.0f, 1.0f);
        this->texCoordBuffer.add2(1.0f, 1.0f);

        this->texCoordBuffer.update();

        this->indexBuffer.init();

        this->indexBuffer.add3(0, 1, 2);
        this->indexBuffer.add3(2, 1, 3);

        this->indexBuffer.update();

        glw::Texture2D::createTexture2DFromFile(&this->logoTexture, "data/textures/logo.png");

    }

    void TexturesApp::handleEvent(SDL_Event* e) {

    }

    void TexturesApp::update(float delta) {
        this->yrot += 32.0f * delta;

        if(this->yrot > 360.0f) {
            this->yrot -= 360.0f;
        }
    }

    void TexturesApp::render() {
        glClearColor(0.0, 181.0 / 255.0, 226.0 / 255.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        this->program.bind();

        this->program.uniform.setMatrix4("proj", glm::perspective(glm::radians(45.0f), app::getAspect(), 1.0f, 1024.0f));
        this->program.uniform.setMatrix4("view", glm::mat4(1.0f));
        this->program.uniform.setMatrix4("model", 
            glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -5.0f)) *
            glm::rotate(glm::mat4(1.0f), glm::radians(this->yrot), glm::vec3(0.0f, 1.0f, 0.0f))
        );

        this->logoTexture.bind(GL_TEXTURE0);

        this->program.vertexArray.bind();

        this->vertexBuffer.bind();
        this->program.vertexArray.pointer("vertices", 3, GL_FLOAT);
        this->vertexBuffer.unbind();

        this->colorBuffer.bind();
        this->program.vertexArray.pointer("colors", 4, GL_FLOAT);
        this->colorBuffer.unbind();

        this->texCoordBuffer.bind();
        this->program.vertexArray.pointer("texCoords", 2, GL_FLOAT);
        this->texCoordBuffer.unbind();

        //glDrawArrays(GL_TRIANGLES, 0, this->vertexBuffer.count() / 3);

        this->indexBuffer.bind();
        glDrawElements(GL_TRIANGLES, this->indexBuffer.count(), GL_UNSIGNED_INT, nullptr);
        this->indexBuffer.unbind();

        this->program.vertexArray.unbind();
        
        this->logoTexture.unbind(GL_TEXTURE0);

        this->program.unbind();
    }

    void TexturesApp::release() {
        this->logoTexture.release();
        this->texCoordBuffer.release();
        this->indexBuffer.release();
        this->texCoordBuffer.release();
        this->colorBuffer.release();
        this->vertexBuffer.release();
        this->program.release();
        this->vertexShader.release();
        this->fragmentShader.release();
    }

    void TexturesApp::reloadInit() {

    }

    void TexturesApp::reloadRelease() {

    }

}
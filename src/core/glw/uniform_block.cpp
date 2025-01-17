#include "../sys.h"


namespace glw {
    void UniformBlock::init(Program* program) {
        this->program = program;
    }

    void UniformBlock::release() {
        this->program = nullptr;
    }

    void UniformBlock::createUniformBlock(std::string name, uint32_t index) {
        this->uniformBlocks[name] = glGetUniformBlockIndex(program->id, name.c_str());
        glUniformBlockBinding(this->program->id, this->uniformBlocks.at(name), index);
    }

}
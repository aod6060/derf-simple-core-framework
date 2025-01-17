#include "../sys.h"
#include <ft2build.h>
#include <vector>
#include FT_FREETYPE_H



namespace render {
    namespace font {

        FT_Library library;

        std::map<std::string, FontFace> fontFaces;

        glw::Texture2D texture;

        void init() {
            // Initialize font api...
            if(FT_Init_FreeType(&library)) {
                std::cout << "ERROR:FREETYPE: Counld not init FreeType Library\n";
                return;
            }

            texture.init();

            texture.bind(GL_TEXTURE0);
            texture.texParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            texture.texParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            texture.unbind(GL_TEXTURE0);
        }

        void release() {
            texture.release();

            std::map<std::string, FontFace>::iterator it;

            for(it = fontFaces.begin(); it != fontFaces.end(); it++) {
                it->second.release();
            }

            FT_Done_FreeType(library);
        }

        void Font::init(std::string path, int32_t size) {
            this->fontFace.init(library, path, size);
        }

        void Font::update(std::string message, std::vector<FontColor>& pixels, FontColor color) {
            std::vector<uint8_t> buffer;

            int32_t width;
            int32_t height;

            this->fontFace.getSize(message, &width, &height);

            this->fontFace.createBuffer(message, &buffer);

            pixels.resize(width * height);

            for(int32_t y = 0; y < height; y++) {
                for(int32_t x = 0; x < width; x++) {
                    int32_t index = y * width + x;
                    pixels[index].r = color.r;
                    pixels[index].g = color.g;
                    pixels[index].b = color.b;
                    pixels[index].a = buffer[index];
                }
            }
        }

        void Font::getSize(std::string message, int32_t* w, int32_t* h) {

        }
        
        void Font::release() {
            this->fontFace.release();
        }
    }
}
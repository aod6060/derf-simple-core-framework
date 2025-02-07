#ifndef FONT_H
#define FONT_H


#define GLEW_NO_GLU
#include <GL/glew.h>
#include <string>
#include <vector>
#include <freetype/freetype.h>

namespace render {
    namespace font {

        void init();
        void release();

        struct FontColor {
            uint8_t r;
            uint8_t g;
            uint8_t b;
            uint8_t a;
        };

        struct FontGlyph {
            int32_t startX;
            int32_t startY;
            int32_t width;
            int32_t height;
            std::vector<uint8_t> data;
        };

        struct FontFace {
            FT_Face face;
            std::string font_face_path;
            int32_t size;
            int32_t glyph_space;
            int32_t space;
            int32_t tab;
            int32_t max_glyph_size;
            int32_t glyph_offset;
            std::vector<FontGlyph> glyphs;

            void init(FT_Library library, std::string path, int32_t size);

            void release();

            void getSize(std::string message, int32_t* width, int32_t* height);

            void createBuffer(std::string message, std::vector<uint8_t>* buffer);
        };

        struct Font {
            FontFace fontFace;

            void init(std::string path, int32_t size);

            void update(std::string message, std::vector<FontColor>& pixels, FontColor color);

            void getSize(std::string message, int32_t* w, int32_t* h);

            void release();
        };
    }
}

#endif
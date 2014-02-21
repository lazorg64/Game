#ifndef TEXTURE_BUFFER_H
#define TEXTURE_BUFFER_H
#include "texture.h"
class texture_buffer
{
    public:
    vector<texture*> textures;

    texture_buffer();
    GLuint getTexture(string input);
    void putTexture(texture * input);
};

#endif // TEXTURE_BUFFER_H

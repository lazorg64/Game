#ifndef TEXTURE_BUFFER_H
#define TEXTURE_BUFFER_H
#include "texture.h"
class texture_buffer
{
    vector<texture*> textures;
public:
    texture_buffer();
    QImage * getTexture(string input);
    void putTexture(texture * input);
};

#endif // TEXTURE_BUFFER_H

#include "texture_buffer.h"

texture_buffer::texture_buffer()
{
}

GLuint texture_buffer::getTexture(string input)
{
    foreach(texture * element,textures)
    {
        if(element->getName()==input)
            return element->getTexId();
    }
    cerr << "Texture "<<input<<" not found" << endl;
    return 0;
}

void texture_buffer::putTexture(texture * input)
{
    textures.push_back(input);
}


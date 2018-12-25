//
// Created by benjamin on 22.12.18.
//

#ifndef OPENGL_TEXTURE_H
#define OPENGL_TEXTURE_H

#include "Renderer.h"

class Texture {
private:
    unsigned int m_RendererID;
    std::string m_FilePath;
    unsigned char *m_LocalBuffer;
    int m_Width, m_Height, m_BPP;
public:
    Texture(const std::string &path);

    virtual ~Texture();

    void Bind(unsigned int slot = 0) const;

    void Unbind() const;

    int GetWidth() const;

    int GetHeight() const;

    int GetBPP() const;

};


#endif //OPENGL_TEXTURE_H

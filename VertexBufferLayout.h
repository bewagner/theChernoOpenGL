#pragma once
#include <vector>
#include <GL/glew.h>
#include "Renderer.h"       
struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int GetSizeOfType(unsigned int type)
    {

        switch (type)
        {
        case GL_FLOAT:
            return 4;
        case GL_UNSIGNED_INT:
            return 4;
        case GL_UNSIGNED_BYTE:
            return 1;
        }
        ASSERT(false);
        return 0;
        
    }
};


class VertexBufferLayout
{
private:
    unsigned int m_Stride;
    std::vector<VertexBufferElement> m_Elements;

public:
    VertexBufferLayout() :
            m_Stride(0) { }

    void AddFloat(unsigned int count)        { Push(GL_FLOAT, count, GL_FALSE);        }
    void AddUnsignedInt(unsigned int count)  { Push(GL_UNSIGNED_INT, count, GL_FALSE); }
    void AddUnsignedByte(unsigned int count) { Push(GL_UNSIGNED_BYTE, count, GL_TRUE); }

    inline const std::vector<VertexBufferElement> GetElements() const { return m_Elements; };
    inline unsigned int GetStride() const { return m_Stride; };

private:
    void Push(unsigned int type, unsigned int count, unsigned char normalized)
    {
        struct VertexBufferElement vbe = {type, count, normalized};
        m_Elements.push_back(vbe);
        m_Stride += count * VertexBufferElement::GetSizeOfType(type);
    };
};
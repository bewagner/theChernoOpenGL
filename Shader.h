//
// Created by benjamin on 21.12.18.
//

#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H

#include <unordered_map>
#include <string>
#include <ext.hpp>

struct ShaderProgramSource {
    std::string VertexSource;
    std::string FragmentSource;
};

class Shader {
private:
    std::string m_FilePath;
    unsigned int m_RendererID;
    std::unordered_map<std::string, int> m_UniformLocationCache;

public:
    explicit Shader(const std::string &filepath);

    virtual ~Shader();

    void Bind() const;

    void Unbind() const;

    void SetUniform1i(const std::string &name, int value);

    void SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3);

    void SetUniformMat4f(const std::string &name, const glm::mat4 value);

private:
    int GetUniformLocation(const std::string &name);

    unsigned int CompileShader(unsigned int type, const std::string &source);

    unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader);

    ShaderProgramSource ParseShader(const std::string &file);
};


#endif //OPENGL_SHADER_H

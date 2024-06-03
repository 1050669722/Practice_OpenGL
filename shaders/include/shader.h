//
// Created by liu on 2024/6/3.
//

#ifndef PRACTICE_OPENGL_SHADER_H
#define PRACTICE_OPENGL_SHADER_H

class Shader
{
public:
    // constructor generates the shader on the fly
    // ------------------------------------------------------------------------
    Shader(const char* vertexPath, const char* fragmentPath);
    void use() const;
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;

    unsigned int getId() const;
    void setId(unsigned int id);

private:
    static void checkCompileErrors(unsigned int id, const std::string& type);

    unsigned int m_id;
};

#endif //PRACTICE_OPENGL_SHADER_H

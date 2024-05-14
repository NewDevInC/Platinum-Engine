//
// Created by blade-wolf on 14.5.2024.
//

#include "Shader.hpp"

std::string get_file_contents(const char* filename){
    std::ifstream in(filename, std::ios::binary);
    if(in){
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return contents;
    }
    throw errno;
}

Shader::Shader(const char* vertexSourceFile, const char* fragmentSourceFile) {
    const char* vertexShaderSource = get_file_contents(vertexSourceFile).c_str();
    const char* fragmentShaderSource = get_file_contents(fragmentSourceFile).c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    this->ID = glCreateProgram();
    glAttachShader(this->ID, vertexShader);
    glAttachShader(this->ID, fragmentShader);
    glLinkProgram(this->ID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::activateShader() {
    glUseProgram(this->ID);
}

void Shader::deleteShader() {
    glDeleteProgram(this->ID);
}

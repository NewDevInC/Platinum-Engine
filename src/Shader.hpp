//
// Created by blade-wolf on 14.5.2024.
//


#pragma once


#include <glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>


std::string get_file_contents(const char* filename);


class Shader {
private:
    GLuint ID;

public:
    Shader(const char* vertexSourceFile, const char* fragmentSourceFile);

    void activateShader();
    void deleteShader();


};

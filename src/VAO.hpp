//
// Created by blade-wolf on 13.5.2024.
//


#pragma once

#include <glad.h>
#include <glmIncludes.hpp>
#include <VBO.hpp>


class VAO {
private:
    GLuint ID = NULL;
public:
    VAO();

    void linkAttrib(VBO* VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
    void bindVAO();
    void unbindVAO();
    void deleteVAO();

};

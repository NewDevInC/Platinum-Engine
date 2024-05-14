//
// Created by blade-wolf on 13.5.2024.
//

#include "VAO.hpp"

VAO::VAO() {
    glGenVertexArrays(1, &this->ID);
}

void VAO::linkAttrib(VBO* VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset) {

    VBO->bindVBO();
    glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(layout);
    VBO->unbindVBO();

}

void VAO::bindVAO() {
    glBindVertexArray(this->ID);
}

void VAO::unbindVAO() {
    glBindVertexArray(0);
}

void VAO::deleteVAO() {
    glDeleteVertexArrays(1, &this->ID);
}

//
// Created by blade-wolf on 14.5.2024.
//

#include "EBO.hpp"

EBO::EBO(std::vector<GLuint> &indices) {
    glGenBuffers(1, &this->ID);
    this->bindEBO();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

}

void EBO::bindEBO() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ID);
}

void EBO::unbindEBO() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::deleteEBO() {
    glDeleteBuffers(1, &this->ID);

}

//
// Created by blade-wolf on 13.5.2024.
//

#include "VBO.hpp"


VBO::VBO(std::vector<Vertex>& vertices) {
    glGenBuffers(1, &this->ID);
    this->bindVBO();
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

}

void VBO::bindVBO() {
    glBindBuffer(GL_ARRAY_BUFFER, this->ID);
}

void VBO::unbindVBO() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::deleteVBO() {
    glDeleteBuffers(1, &this->ID);
}



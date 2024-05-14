//
// Created by blade-wolf on 14.5.2024.
//

#include "Mesh.hpp"

Mesh::Mesh(std::vector<Vertex> &vertices, Shader* shader) {
    this->vertices = vertices;
    this->shader = shader;


    this->VAO.bindVAO();
    auto* VBO = new class VBO(this->vertices);
    this->VAO.linkAttrib(VBO, 0, 3, GL_FLOAT, sizeof(Vertex), nullptr);
    this->VAO.linkAttrib(VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3*sizeof(float)));
    this->VAO.unbindVAO();
    VBO->unbindVBO();
}

void Mesh::Draw() {
    this->shader->activateShader();
    this->VAO.bindVAO();
    glDrawArrays(GL_TRIANGLES, 0, 3);

}

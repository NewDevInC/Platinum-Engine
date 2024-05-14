//
// Created by blade-wolf on 14.5.2024.
//

#include "Mesh.hpp"

#include <utility>

Mesh::Mesh(std::vector<Vertex> &vertices, std::vector<GLuint> &indices, Shader *shader) {
    this->vertices = vertices;
    this->indices = indices;
    this->shader = shader;

    this->VBO = new class VBO(this->vertices);
    this->EBO = new class EBO(this->indices);


    this->VAO.bindVAO();
    this->VBO->bindVBO();
    this->EBO->bindEBO();


    this->VAO.linkAttrib(this->VBO, 0, 3, GL_FLOAT, sizeof(Vertex), nullptr);
    this->VAO.linkAttrib(this->VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void *) (3 * sizeof(float)));
    this->VAO.unbindVAO();
    this->VBO->unbindVBO();
    this->EBO->unbindEBO();
}

void Mesh::Draw() {
    this->shader->activateShader();
    this->VAO.bindVAO();
    glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, nullptr);

}

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

    auto model = glm::mat4(1.0f);
    auto view = glm::mat4(1.0f);
    auto projection = glm::mat4(1.0f);

    view = glm::translate(view, glm::vec3(0.0f, -0.5f, -2.0f));
    projection = glm::perspective(glm::radians(90.0f), float(640) / float(640), 0.1f, 100.0f);

    Uint64 currentTime = SDL_GetTicks64();
    if (currentTime - this->previousTime >= 1) {
        this->rotation += 0.5f;
        this->previousTime = currentTime;
    };

    model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));

    glUniformMatrix4fv(2, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(3, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(4, 1, GL_FALSE, glm::value_ptr(projection));

    this->VAO.bindVAO();

    glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, nullptr);

}

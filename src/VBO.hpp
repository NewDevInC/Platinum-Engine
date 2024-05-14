//
// Created by blade-wolf on 13.5.2024.
//


#pragma once

#include <glad.h>
#include <glmIncludes.hpp>
#include <vector>

struct Vertex {
    glm::vec3 position;
    glm::vec3 color;
};

class VBO {
private:
    GLuint ID = NULL;
public:
    VBO(std::vector<Vertex>& vertices);

    void bindVBO();
    void unbindVBO();
    void deleteVBO();
};

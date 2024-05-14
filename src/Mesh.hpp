//
// Created by blade-wolf on 14.5.2024.
//


#pragma once

#include <glad.h>
#include <vector>
#include <glmIncludes.hpp>
#include <VAO.hpp>
#include <Shader.hpp>

class Mesh {
private:
    std::vector<Vertex> vertices;
    Shader* shader;
    VAO VAO;

public:
    explicit Mesh(std::vector<Vertex> &vertices, Shader* shader);
    void Draw();

};

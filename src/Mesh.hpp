//
// Created by blade-wolf on 14.5.2024.
//


#pragma once

#include <glad.h>
#include <vector>
#include <glmIncludes.hpp>
#include <VAO.hpp>
#include <VBO.hpp>
#include <EBO.hpp>
#include <SDL.h>
#include <Shader.hpp>

class Mesh {
private:
    std::vector<Vertex> vertices;
    std::vector <GLuint> indices;
    Shader* shader;
    VAO VAO;
    VBO *VBO;
    EBO *EBO;
    Uint64 previousTime = 0;
    float rotation = 0.0f;

public:
    Mesh(std::vector <Vertex> &vertices, std::vector <GLuint> &indices, Shader *shader);
    void Draw();

};

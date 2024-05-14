//
// Created by blade-wolf on 13.5.2024.
//


#pragma once

#include <glad.h>
#include <SDL.h>
#include <glmIncludes.hpp>

#include <VBO.hpp>
#include <VAO.hpp>
#include <Shader.hpp>
#include <Mesh.hpp>



class SilverRenderer {
private:
    std::vector<Mesh *> meshStack;
public:
    SilverRenderer();
    void updateScreen(SDL_Window* _window, int width, int height);
    void pushToMeshStack(Mesh* &mesh);


};

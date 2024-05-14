//
// Created by blade-wolf on 13.5.2024.
//

#pragma once


#include <iostream>
#include <cstdlib>
#include <cstdio>

#include <glad.h>
#include <SDL.h>

#include <SilverRenderer.hpp>

class PlatinumEngine{

private:
    SDL_Window *_window = nullptr;
    SDL_GLContext _context = nullptr;
    SilverRenderer* _silverRender = nullptr;
public:
    SDL_Event event;
    int width = 640, height = 640;
    const char* title = "Window";
    bool shouldClose;

    PlatinumEngine(int width, int height, const char* title);

    void updateScreen();
    void addMesh(Mesh* mesh);

    void HandleEvents();

    void PlatinumEngineTerminate();
};
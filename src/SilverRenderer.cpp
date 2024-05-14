//
// Created by blade-wolf on 13.5.2024.
//

#include "SilverRenderer.hpp"



SilverRenderer::SilverRenderer() {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

}

void SilverRenderer::updateScreen(SDL_Window* _window, int width, int height) {
    glViewport(0,0, width, height);

    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    for (auto mesh: this->meshStack)
        mesh.Draw();


    SDL_GL_SwapWindow(_window);
}

void SilverRenderer::pushToMeshStack(Mesh* &mesh) {
    this->meshStack.push_back(*mesh);

}




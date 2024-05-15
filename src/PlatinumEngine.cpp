//
// Created by blade-wolf on 13.5.2024.
//

#include "PlatinumEngine.hpp"

PlatinumEngine::PlatinumEngine(int width, int height, const char* title) {
    if (SDL_Init(SDL_INIT_EVERYTHING)){
        std::cout << "SDL2 failed to init!" << std::endl;
        exit(-1);
    }

    this->width = width;
    this->height = height;
    if(strcmp(title, "") != 0){
        this->title = title;
    }

    this->_silverRender = new SilverRenderer();

    this->_window = SDL_CreateWindow(this->title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->width, this->height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    if (!this->_window){
        std::cout << "SDL2 failed to create a window!" << std::endl;
        exit(-2);
    }

    this->_context = SDL_GL_CreateContext(this->_window);

    gladLoadGLLoader(SDL_GL_GetProcAddress);

    if(!this->_context){
        std::cout << "SDL2 failed to create a GL context!" << std::endl;
        exit(-3);
    }

    this->shouldClose = false;

}
void PlatinumEngine::updateScreen(){
    this->_silverRender->updateScreen(this->_window, this->width, this->height);


}
void PlatinumEngine::addMesh(Mesh *mesh) {
    this->_silverRender->pushToMeshStack(mesh);
}


void PlatinumEngine::HandleEvents() {
    SDL_PollEvent(&this->event);
    switch (event.type) {
        case SDL_QUIT:
            shouldClose =! shouldClose;
            break;
        default:
            break;
    }
}

void PlatinumEngine::PlatinumEngineTerminate() {
    SDL_DestroyWindow(this->_window);

    SDL_Quit();
}



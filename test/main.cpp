
#include <src/PlatinumEngine.hpp>


PlatinumEngine* pEngine = nullptr;

int main(int argc, char *argv[]) {

    pEngine = new PlatinumEngine(640, 640, "");

    Vertex vertices[] = {
            Vertex{glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(0.0f, 1.0f, 1.0f)},
            Vertex{glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)},
            Vertex{glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
            Vertex{glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f)}
    };

    std::vector<Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));

    GLuint indices[] = {
            0, 1, 3,
            1, 2, 3
    };

    std::vector<GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));

    auto* shaderProgram = new Shader("./default.vert", "./default.frag");

    auto *Mesh = new class Mesh(verts, ind, shaderProgram);
    pEngine->addMesh(Mesh);



    while (!pEngine->shouldClose){
        pEngine->HandleEvents();
        pEngine->updateScreen();
    }

    pEngine->PlatinumEngineTerminate();

    delete pEngine;

    shaderProgram->deleteShader();

    delete shaderProgram;


    return 0;

}

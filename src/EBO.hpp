//
// Created by blade-wolf on 14.5.2024.
//


#pragma once

#include <glad.h>
#include <glmIncludes.hpp>
#include <vector>


class EBO {
private:
    GLuint ID = NULL;
public:
    EBO(std::vector <GLuint> &indices);

    void bindEBO();

    void unbindEBO();

    void deleteEBO();


};

//
// Created by benjamin on 23.12.18.
//

#ifndef OPENGL_HELPERS_H
#define OPENGL_HELPERS_H

#include <string>
#include <sys/stat.h>

inline bool exists(const std::string &name) {
    struct stat buffer{};
    return (stat(name.c_str(), &buffer) == 0);
}


#endif //OPENGL_HELPERS_H

#include <iostream>

#include "header.h"
#include "another.h"

#include <SDL2/SDL.h>

extern "C" {
    #include <libavformat/avformat.h>
    #include <libavutil/frame.h>
}

int main() {
    std::cout << "Hello world!" << std::endl;

    do_thing();
    another();
    SDL_Init(SDL_INIT_VIDEO);
    auto window = SDL_CreateWindow("hah", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);
    if (window == nullptr) {
        std::cout << SDL_GetError();
    }
    auto frame = av_frame_alloc();
    std::cout << "initted";
    return 0;
}
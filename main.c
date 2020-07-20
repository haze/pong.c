#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL.h>

int main(void) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "Failed to initialize SDL2\n%s\n", SDL_GetError());
    return EXIT_FAILURE;
  }

  SDL_Window *window = SDL_CreateWindow("pong", 
      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
      640, 480, 
      SDL_WINDOW_OPENGL);

  if (window == NULL) {
    fprintf(stderr, "Failed to create SDL2 Window\n%s\n", SDL_GetError());
    return EXIT_FAILURE;
  }
  
  SDL_Event e;
  bool should_quit = false;
  while (!should_quit){
      while (SDL_PollEvent(&e)){
          if (e.type == SDL_QUIT){
              should_quit = true;
          }
      }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
  return EXIT_SUCCESS;
}

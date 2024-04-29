#include <SDL.h>
#include <stdio.h>

// Déclaration de la position du joueur
int playerX = 100;
int playerY = 300;

// Déclaration de la vitesse du joueur
int playerDx = 3;
int playerDy = 3;

int StateUp = 0;
int StateDown = 0;
int StateLeft = 0;
int StateRight = 0;

void KeyDownCheck(SDL_Event event)
{
    if (event.key.keysym.sym == SDLK_UP)
    {
        StateUp = 1;
        StateDown = 0;
        StateRight = 0;
        StateLeft = 0;
    }
    if (event.key.keysym.sym == SDLK_DOWN)
    {
        StateDown = 1;
        StateUp = 0;
        StateRight = 0;
        StateLeft = 0;
    }
    if (event.key.keysym.sym == SDLK_RIGHT)
    {
        StateRight = 1;
        StateDown = 0;
        StateUp = 0;
        StateLeft = 0;
    }
    if (event.key.keysym.sym == SDLK_LEFT)
    {
        StateLeft = 1;
        StateDown = 0;
        StateRight = 0;
        StateUp = 0;
    }
}




void SnakeManager()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {


        if (event.type == SDL_KEYDOWN)
        {
            KeyDownCheck(event);
        }  
    }
}

void UpdatePos()
{
    if (playerY <= 10)
    {
        StateUp = 0;
    }

    if (playerY >= 600 - 40)
    {
        StateDown = 0;
    }

    if (playerX <= 0)
    {
        StateLeft = 0;
    }

    if (playerX >= 1200 - 40)
    {
        StateRight = 0;
    }

    playerX += playerDx * (StateRight - StateLeft);
    playerY += playerDy * (StateDown - StateUp);

}
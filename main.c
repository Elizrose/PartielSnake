#include <stdio.h>
#include <SDL.h>
#include "WindowManager.h"
#include "setSnake.h"
#include "movement.h"
#include "Spawner.h"

void Jeu()
{
    Snake = setSnake(playerX, playerY, 40, 40);
    SnakeManager();
    SDL_RenderPresent(renderer);
    ClearScreen();
    UpdatePos();
}

int main()
{
    Initializer();
    while (1)
    {
        while (1 > 0)
        {
            srand(time(NULL));
            ClearScreen();
            Jeu();
            compteurFrame += 1;

            SDL_Delay(10);
        }
        
        ClearScreen();
    }
    return 0;
}
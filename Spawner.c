#include <stdio.h>
#include <SDL.h>
#include "WindowManager.h"
#include "setSnake.h"
#include "movement.h"


int compteurFrame = 0;


void spawn(){
	if (compteurFrame % 5000 == 0)
	{
        setApple();
	}
}

void setApple()
{
    int posX = (rand() % (1200));
    int posY = (rand() % (600));

    SDL_Rect rect = {posX, posY, 40, 40};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rect);

}
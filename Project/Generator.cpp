#include "Generator.h"
#include <Windows.h>


Generator::Generator()
{
}

Generator::~Generator()
{
	
}

void Generator::initWinRen()
{
	mainWindow = SDL_CreateWindow("Seth's Sorter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winSize, winSize, SDL_WINDOW_OPENGL);
	mainRender = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
}



void Generator::generateRects(int hieght[], int size)
{

	for (int i = 0; i < size; i++)		
	{
		bars[i].x = i * 20;			/*   The info fore each bar */
		bars[i].y = 600;
		bars[i].w = 20;
		bars[i].h = hieght[i] * (-1);
	}

	
	
}


void Generator::redrawScreen(int i)
{
	SDL_SetRenderDrawColor(mainRender, 0, 0, 0, 0);

	SDL_RenderClear(mainRender);
	SDL_SetRenderDrawColor(mainRender, 200, 0, 0, 0);

	SDL_RenderDrawRects(mainRender, bars, 30);
	SDL_RenderFillRects(mainRender, bars, 30);

	SDL_SetRenderDrawColor(mainRender, 255, 255, 255, 0);
	SDL_RenderDrawRect(mainRender, bars + i);
	SDL_RenderFillRect(mainRender, bars + i);
	
	SDL_RenderPresent(mainRender);
}
#include <SDL.h>
#include <stdio.h>
#include <random>
#include <ctime>
#include "Generator.h"
#include <Windows.h>

void appLoop(Generator gfxDisplay, int values[]);

void sort(Generator gfxDisplay);

int main(int argc, char *args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	Generator gfxDisplay;

	srand(time(0));						/*    Creates the values    */
	int values[30];						/*    for the bars to       */
	for (int i = 0; i < 30; i++)		/*    appear on the screen  */
	{									/*    for how tall they are */
		values[i] = rand() % 600;		/*                          */
	}									/*                          */

	//initiate the window and renderer
	gfxDisplay.initWinRen();
	
	//initiate loop
	appLoop(gfxDisplay, values);


	

	return 0;
}

void appLoop(Generator gfxDisplay, int values[])
{
	//Generate rectangles
	gfxDisplay.generateRects(values, 30);
	SDL_Event e;	

	bool quit = false;	

	//once x = 1 no more sorting is done and we can exit
	int x = 0;
	while (!quit)			
	{
		SDL_PollEvent(&e);
		if (e.type == (SDL_QUIT))
		{
			quit = true;
			SDL_Quit();
		}
		


		if (x == 0)
		{
			sort(gfxDisplay);
		}
		
		x++;
	}
}


void sort(Generator gfxDisplay)
{
	for (int element = 30 - 1; element >= 0; element--)
	{
		for (int start = 1; start <= element; start++)
		{
			if (gfxDisplay.bars[start - 1].h > gfxDisplay.bars[start].h)
			{
				int temp = gfxDisplay.bars[start - 1].h;
				gfxDisplay.bars[start - 1].h = gfxDisplay.bars[start].h;
				gfxDisplay.bars[start].h = temp;
				gfxDisplay.redrawScreen(element);
			}
			Sleep(10);
			
		}
	}
}
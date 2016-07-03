#ifndef GENERATOR_H
#define GENERATOR_H

#include <SDL.h>
#include <stdio.h>

typedef short int s_int;

class Generator
{
public:
	Generator();
	~Generator();
	void initWinRen();
	void generateRects(int hieght[], int size);
	void redrawScreen(int i);
	SDL_Renderer * mainRender;
	SDL_Window * mainWindow;
	SDL_Rect bars[30];

private:
	
	
	s_int winSize = 600;
};

#endif
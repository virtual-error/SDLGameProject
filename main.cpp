#include "SDL.h"
#include <iostream>
using namespace std;
//Screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
//Rendering window
SDL_Window* gWindow = NULL;
//Surface contained by window
SDL_Surface* gScreenSurface = NULL;
//Loaded image and show on screen
SDL_Surface* gHelloWorld = NULL;


bool init();
bool loadMedia();
void close();

int main(int args, char * argsv[])
{
	//Rendering window
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;

	//Init SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initiliaze! SDL ERROR: "<<SDL_GetError();

	}
	else
	{
		//Create Window
		window = SDL_CreateWindow("Title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			cout << "Window could not be created! SDL ERROR: "<<SDL_GetError();
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);
			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			//Update the surface
			SDL_UpdateWindowSurface(window);
			//wait
			SDL_Delay(2000);
			//Destroy window
			SDL_DestroyWindow(window);
			//Quit SDL subsystems
			SDL_Quit();
		}
	}
	return 0;
}
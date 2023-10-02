#include "Screen.hpp"

Screen::Screen()
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(640 * 2, 480 * 2, 0, &window, &renderer);
	SDL_RenderSetScale(renderer, 2, 2);
}

void Screen::pixel(float x, float y)
{
	points.emplace_back(x, y);
}

void Screen::show()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for (auto& p : points)
	{
		SDL_RenderDrawPoint(renderer, p.x, p.y);
	}
	SDL_RenderPresent(renderer);
}

void Screen::clear()
{
	points.clear();
}

void Screen::input()
{
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			SDL_Quit();
			exit(0);
		}
	}
}
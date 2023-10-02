#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SDL.h>
#include <vector>

class Screen
{
private:
	struct FPoint
	{
		float x;
		float y;

		FPoint(float a, float b)
			: x(a), y(b) {}
	};
	SDL_Event e;
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::vector<FPoint> points;

public:
	Screen();

	void pixel(float, float);
	void show();
	void clear();
	void input();

};



#endif


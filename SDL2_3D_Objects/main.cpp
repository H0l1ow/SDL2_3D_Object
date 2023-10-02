#include <iostream>
#include "Screen.hpp"
#include "Functions.hpp"
#undef main


int main()
{

	Screen screen;

	vec3 position{ 0,0,0 };
	std::vector<vec3> points
	{
		{100,100,100}, {200,100,100}, {200,200,100}, {100,200,100},

		{100,100,200}, {200,100,200}, {200,200,200}, {100,200,200}	
	};

	std::vector<connection> conn
	{
		{0,4}, {1,5}, {2,6}, {3,7},

		{0,1}, {1,2}, {2,3}, {3,0},

		{4,5}, {5,6}, {6,7}, {7,4}

		/*{0,2}, {1,3}, {4,6}, {5,7},

		{0,7}, {4,3}, {1,6}, {5,2},

		{4,1}, {0,5}, {3,6}, {2,7},

		{4,2}, {1,7}, {3,5}, {6,0}*/

	};

	center(points, position);

	/*for (auto& p : conn)
	{
		std::cout << p.a << " " << p.b << std::endl;
	}*/

	while (true)
	{
		for (auto& p : points)
		{
			p.x -= position.x;
			p.y -= position.y;
			p.z -= position.z;

			rotate(p, 0.004, 0.002, 0.008);

			p.x += position.x;
			p.y += position.y;
			p.z += position.z;
		}
		for (auto& c : conn)
		{
			test_line(screen, points[c.a].x, points[c.a].y, 
							  points[c.b].x, points[c.b].y);
		}



		for (auto& p : points)
		{
			screen.pixel(p.x, p.y);
		}
		screen.show();
		screen.clear();


		screen.input();
		SDL_Delay(30);
	}



	return 0;
}
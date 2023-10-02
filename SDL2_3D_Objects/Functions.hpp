#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "Screen.hpp"


struct vec3{ float x; float y; float z; };
struct connection { int a; int b; };

void rotate(vec3&, float, float, float); 
void center(std::vector<vec3>&, vec3&);
void test_line(Screen&, float, float, float, float);





#endif // !FUNCTIONS_HPP

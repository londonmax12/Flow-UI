#include "Platform/Window.h"

#include <stdio.h>

Flow::Window* Flow::Window::CreateWindow() {
	printf("Hello From Windows!");
	return new Window();
}
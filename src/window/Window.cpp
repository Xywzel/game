#include "Window.h"

#include <GLFW/glfw3.h>

#include "logger/LogMacros.h"
#include "input/Input.h"

namespace window
{
	void errorCallback(int /*error*/, const char* description)
	{
		LOG_ERROR("GLFW: %s", description);
	}

	Window::Window()
	{
		// We want output about possible errors
		glfwSetErrorCallback(errorCallback);

		// Setting the initialisation hints
		//glfwInitHint(GLFW_JOYSTICK_HAT_BUTTONS, GLFW_TRUE);
		//glfwInitHint(GLFW_COCOA_CHRIR_RESOURCES, GLFW_TRUE);
		//glfwInitHint(GLFW_COCOA_MENUBAR, GLFW_TRUE);

		// Actual initialisation, which might fail
		if (!glfwInit())
			return;

		window = glfwCreateWindow(640, 480, "Title", NULL, NULL);
		glfwMakeContextCurrent(window);

	}

	Window::~Window()
	{
		if (window)
			glfwDestroyWindow(window);
		glfwTerminate();
	}

	bool Window::shouldClose()
	{
		glfwPollEvents();
		return glfwWindowShouldClose(window);
	}
}

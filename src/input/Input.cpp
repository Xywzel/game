#include "Input.h"

#include <GLFW/glfw3.h>

#include "input/InputEvent.h"
#include "input/InputState.h"
#include "input/InputEventQueue.h"
#include "window/Window.h"
#include "logger/LogMacros.h"

namespace input
{
	struct Input
	{
		InputState state;
		InputEventQueue queue;
	};

	Input& getInput()
	{
		static Input input;
		return input;
	}

	void keyCallback(GLFWwindow* /*window*/, int key, int scancode, int action, int mods)
	{
		string::String str = string::format("KeyCallback: key %d, scancode %d, action %d, mods %d\n", key, scancode, action, mods);
		logger::log(logger::Level::Info, str);

		Input& input = getInput();
		if (action == GLFW_PRESS || action == GLFW_REPEAT)
			input.state.keys[key].pressed = true;
		if (action == GLFW_RELEASE)
			input.state.keys[key].pressed = false;
	}

	void pathDropCallback(GLFWwindow* /*window*/, int pathCount, const char* paths[])
	{
		LOG_INFO("DropCallback: pathCount %d\n", pathCount);
		for (int i = 0; i < pathCount; ++i)
		{
			LOG_INFO("Path %d: %s", i, paths[i]);
		}
	}

	void scrollCallback(GLFWwindow* /*window*/, double xoffset, double yoffset)
	{
		LOG_INFO("ScrollCallback: xoffset %f, yoffset %f \n", xoffset, yoffset);
	}

	void cursorEnterCallback(GLFWwindow* /*window*/, int entered)
	{
		LOG_INFO("CursorEnteredCallback: entered %d", entered);
	}

	void cursorPosCallback(GLFWwindow* /*window*/, double xpos, double ypos)
	{
		LOG_INFO("CursorPosCallback: xpos %f, ypos %f", xpos, ypos);
	}

	void mouseButtonCallback(GLFWwindow* /*window*/, int button, int action, int mods)
	{
		LOG_INFO("MouseButtonCallback: button %d, action %d, mods %d", button, action, mods);
	}

	void joystickCallback(int jid, int event)
	{
		LOG_INFO("JoystickCallback: jid %d, event %d", jid, event);

	}


	void registerCallbacks(window::Window& window)
	{
		glfwSetKeyCallback(window.getPtr(), keyCallback);
		glfwSetMouseButtonCallback(window.getPtr(), mouseButtonCallback);
		glfwSetCursorPosCallback(window.getPtr(), cursorPosCallback);
		glfwSetCursorEnterCallback(window.getPtr(), cursorEnterCallback);
		glfwSetScrollCallback(window.getPtr(), scrollCallback);
		glfwSetDropCallback(window.getPtr(), pathDropCallback);
		glfwSetJoystickCallback(joystickCallback);
	}

	void pollEvents()
	{
		glfwPollEvents();
	}

	const InputState& getInputState()
	{
		return getInput().state;
	}

	InputEventQueue getInputEvents()
	{
		return getInput().queue;
	}
}

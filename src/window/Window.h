#pragma once

struct GLFWwindow;

namespace window
{
	class Window
	{
		public:
			Window();
			~Window();
			bool shouldClose();
			GLFWwindow* getPtr();
		private:
			GLFWwindow* window = nullptr;
	};
}

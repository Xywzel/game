#pragma once

namespace container
{
	template <typename T>
	class Vector
	{
		public:
			Vector();
			Vector(int size);

			void pushBack(const T& element);
			T popBack();

		private:
			T* data;
			int length;
	}
}

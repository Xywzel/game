#include "types.h"

namespace Input
{
	enum class Key
	{
		Mouse1,
		Mouse2,
	};

	enum class ControllerType
	{
		Mouse,
		Keyboard
	};

	typedef unsigned int ControllerId;

	enum class EventType
	{
		Pressed,
		Released,
		Repeated,
		ValueChange, // This is used for mouse movement and controller stick tilt changes
	};

	struct InputEvent
	{
		// When the event was recived
		uint64_t timestamp;
		
		// Where the event game from
		ControllerType controllerType;
		ControllerId controllerId;

	};
}

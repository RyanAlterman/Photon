#pragma once

#include "KeyCodes.h"
#include <glm/glm.hpp>

namespace Photon
{
	class Input
	{
	public:
		// TODO: Add documentation comments to Input members
		static bool IsKeyDown(KeyCode keycode);
		static bool IsMouseButtonDown(MouseButton button);

		static glm::vec2 GetMousePosition();

		static void SetCursorMode(CursorMode mode);

	protected:
	private:
	};
}

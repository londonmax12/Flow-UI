#pragma once

#include <stdlib.h>

namespace Flow {
	class Window {
	public:
		static Window* CreatePlatformWindow();

		void Update();
		void Shutdown() {
			if (mWindowData) {
				free(mWindowData);
				mWindowData = nullptr;
			}
		}
	private:
		void* mWindowData = nullptr;
	};
}
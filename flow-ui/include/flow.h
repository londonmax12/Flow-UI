#pragma once

#include "Platform/Window.h"

namespace Flow {
	class FlowInstance
	{
	public:
		FlowInstance() = default;
		~FlowInstance();

		bool Init();
		void Update();
		void Shutdown();

	private:
		Window* mWindow = nullptr;
	};
}
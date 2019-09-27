#pragma once

#include "Core.h"

namespace Vin {

	class VIN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}
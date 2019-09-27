#pragma once

#ifdef VIN_PLATFORM_WINDOWS

extern Vin::Application* Vin::CreateApplication();

int main()
{	
	Vin::Log::Init();
	VIN_ENGINE_ERROR("Initialized vin engine!");
	VIN_INFO("Hello from the {0}", "application");

	auto application = Vin::CreateApplication();
	application->Run();
	delete application;
}

#endif // VIN_PLATFORM_WINDOWS

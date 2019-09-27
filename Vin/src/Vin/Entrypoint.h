#pragma once

#ifdef VIN_PLATFORM_WINDOWS

extern Vin::Application* Vin::CreateApplication();

int main()
{
	auto application = Vin::CreateApplication();
	application->Run();
	delete application;
}

#endif // VIN_PLATFORM_WINDOWS

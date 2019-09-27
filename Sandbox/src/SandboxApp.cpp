#include <Vin.h>

class Sandbox : public Vin::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Vin::Application* Vin::CreateApplication()
{
	return new Sandbox;
}
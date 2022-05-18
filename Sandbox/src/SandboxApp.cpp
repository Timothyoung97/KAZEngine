#include <KAZEngine.h>

class Sandbox : public KAZEngine::Application 
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{
	
	}
};

KAZEngine::Application* KAZEngine::CreateApplication()
{
	return new Sandbox();
}
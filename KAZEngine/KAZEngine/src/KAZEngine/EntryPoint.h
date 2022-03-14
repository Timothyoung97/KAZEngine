#pragma once

#ifdef KE_PLATFORM_WINDOWS

extern KAZEngine::Application* KAZEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = KAZEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif

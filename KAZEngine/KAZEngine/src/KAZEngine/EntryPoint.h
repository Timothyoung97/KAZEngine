#pragma once

#ifdef KAZENGINE_PLATFORM_WINDOWS

extern KAZEngine::Application* KAZEngine::CreateApplication();

int main(int argc, char** argv)
{

	KAZEngine::Log::Init();
	KAZENGINE_CORE_WARN("Initializing Logging System!");
	int a = 100;
	KAZENGINE_INFO("Welcome to KAZEngine! Var={0}", a);

	auto app = KAZEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif

#include "kepch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace KAZEngine
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			KAZENGINE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			KAZENGINE_TRACE(e);
		}
		while (true);
	}
}
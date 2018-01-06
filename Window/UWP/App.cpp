#include "App.h"

using namespace Windows::ApplicationModel::Core;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Core;
using namespace Windows::Foundation;
using namespace Windows::Graphics::Display;

void App::Initialize(Windows::ApplicationModel::Core::CoreApplicationView ^applicationView)
{	
	applicationView->Activated += ref new TypedEventHandler<CoreApplicationView^, IActivatedEventArgs^>(this, &App::OnActivated);
}

void App::SetWindow(Windows::UI::Core::CoreWindow ^window)
{	
	window->VisibilityChanged += ref new TypedEventHandler<CoreWindow^, VisibilityChangedEventArgs^>(this, &App::OnVisibilityChanged);
}

void App::Load(Platform::String ^entryPoint)
{
}

void App::Run()
{
	while (true)
	{
		if (mWindowVisible)
		{
			CoreWindow::GetForCurrentThread()->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessAllIfPresent);
		}
		else
		{
			CoreWindow::GetForCurrentThread()->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessOneAndAllPending);
		}
	}
}

void App::Uninitialize()
{
}

void App::OnActivated(Windows::ApplicationModel::Core::CoreApplicationView^ applicationView, Windows::ApplicationModel::Activation::IActivatedEventArgs^ args)
{
	// El método Run() no iniciará hasta que sea activado el CoreWindow
	// Si no se activa, si inicia el método Run(), pero no se muestra nada. 
	CoreWindow::GetForCurrentThread()->Activate();
}

void App::OnVisibilityChanged(Windows::UI::Core::CoreWindow^ sender, Windows::UI::Core::VisibilityChangedEventArgs^ args)
{
	mWindowVisible = args->Visible;
}
#include "FactoryView.h"
#include "App.h"

Windows::ApplicationModel::Core::IFrameworkView ^ FactoryView::CreateView()
{
	return ref new App();
}

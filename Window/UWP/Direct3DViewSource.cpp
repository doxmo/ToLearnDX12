#include "Direct3DViewSource.h"
#include "App.h"

Windows::ApplicationModel::Core::IFrameworkView ^ Direct3DViewSource::CreateView()
{
	return ref new App();
}

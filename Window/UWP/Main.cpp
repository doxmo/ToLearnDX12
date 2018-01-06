#include "FactoryView.h"

using namespace Windows::ApplicationModel::Core;

// La función main solo se usa para inicializar la clase IFrameworkView.
[Platform::MTAThread]
int main(Platform::Array<Platform::String^>^)
{
	auto factoryView = ref new FactoryView();
	CoreApplication::Run(factoryView);
	
	return EXIT_SUCCESS;
}
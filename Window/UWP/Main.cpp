#include "Direct3DViewSource.h"

using namespace Windows::ApplicationModel::Core;

// La función main solo se usa para inicializar la clase IFrameworkView.
[Platform::MTAThread]
int main(Platform::Array<Platform::String^>^)
{
	auto direct3DApplicationSource = ref new Direct3DViewSource();
	CoreApplication::Run(direct3DApplicationSource);
	return 0;
}
#pragma once

ref class Direct3DViewSource sealed : Windows::ApplicationModel::Core::IFrameworkViewSource
{
public :
	// Inherited via IFrameworkViewSource
	virtual Windows::ApplicationModel::Core::IFrameworkView ^ CreateView();
};
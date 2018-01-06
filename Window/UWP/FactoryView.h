#pragma once

ref class FactoryView sealed : Windows::ApplicationModel::Core::IFrameworkViewSource
{
public :
	// Heredada de IFrameworkViewSource
	virtual Windows::ApplicationModel::Core::IFrameworkView ^ CreateView();
};
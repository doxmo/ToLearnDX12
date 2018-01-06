#pragma once

ref class App sealed : public Windows::ApplicationModel::Core::IFrameworkView
{
public:
	
	// Heredado a trav�s de la interfaz IFrameworkView
	virtual void Initialize(Windows::ApplicationModel::Core::CoreApplicationView ^applicationView);
	virtual void SetWindow(Windows::UI::Core::CoreWindow ^window);
	virtual void Load(Platform::String ^entryPoint);
	virtual void Run();
	virtual void Uninitialize();

protected:
	// Manejadores de evento del ciclo de la aplicaci�n.
	void OnActivated(Windows::ApplicationModel::Core::CoreApplicationView^ applicationView, Windows::ApplicationModel::Activation::IActivatedEventArgs^ args);

	// Manejadores de evento de la ventana.
	void OnVisibilityChanged(Windows::UI::Core::CoreWindow^ sender, Windows::UI::Core::VisibilityChangedEventArgs^ args);

private:

	bool mWindowVisible = true;
};
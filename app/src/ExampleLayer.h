#include "corelib/Application.h"
#include "corelib/Layer.h"

class ExampleLayer : public ABC_Name::Layer {
public:
	void OnAttach() override;
	void OnUIRender() override;
	void OnDetach() override;

private:
	bool collapsingHeader1{ false };
};

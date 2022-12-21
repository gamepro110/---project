#include "ExampleLayer.h"
#include "testLayer.h"

#include "corelib/Application.h"
#include "corelib/Log.h"
#include "corelib/EntryPoint.h"

#if defined(ABC_DEBUG)
class DemoLayer : public ABC_Name::Layer {
public:	
	void OnAttach() override {}
	void OnUIRender() override {
		ImGui::ShowDemoWindow(&showDemo);
	}
	void OnDetach() override {}
private:
	bool showDemo = true;
};
#endif

ABC_Name::Application* ABC_Name::CreateApplication(int argc, char** argv) {
	ABC_Name::AppSpecs spec;
	spec.Name = "...name...";

	ABC_INFO("Starting App");
	ABC_Name::Application* app = new ABC_Name::Application(spec);
	
	app->PushLayer<ExampleLayer>();
	app->PushLayer<TestLayer>();
	
	#if defined(ABC_DEBUG)
	app->PushLayer<DemoLayer>();
	#endif
	
	app->SetMenubarCallback(
		[app]() {
			if (ImGui::BeginMenu("File")) {
				if (ImGui::MenuItem("Close")) {
					app->Close();
				}
				ImGui::EndMenu();
			}
		}
	);
	
	return app;
}
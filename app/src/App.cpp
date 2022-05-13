#include "Application.h"
#include "Log.h"
#include "EntryPoint.h"

class ExampleLayer : public ABC_Name::Layer {
public:
	void OnAttach() override {
	}

	void OnUIRender() override {
		ImGui::Begin("Example");
		
		if (ImGui::CollapsingHeader("foldout example", collapsingHeader1)) {
			ImGui::Text("what did u expect to find...?");
		}

		ImGui::Text("Example text");
		ImGui::End();
	}

	void OnDetach() override {
	}

private:
	bool collapsingHeader1{ false };
};

ABC_Name::Application* ABC_Name::CreateApplication(int argc, char** argv) {
	ABC_Name::AppSpecs spec;
	spec.Name = "...name...";

	ABC_INFO("Starting App");
	ABC_Name::Application* app = new ABC_Name::Application(spec);
	
	app->PushLayer<ExampleLayer>();
	
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
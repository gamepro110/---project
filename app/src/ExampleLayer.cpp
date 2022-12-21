#include "ExampleLayer.h"

void ExampleLayer::OnAttach() {
}

void ExampleLayer::OnUIRender() {
	ImGui::Begin("Example");
		
	if (ImGui::CollapsingHeader("foldout example", collapsingHeader1)) {
		ImGui::Text("what did u expect to find...?");
	}

	ImGui::Text("Example text");
	ImGui::End();
}

void ExampleLayer::OnDetach() {
}

#include "testLayer.h"

#include <ctime>
#include <iostream>

void TestLayer::OnAttach() {
    std::srand(std::time(0));
    int i1 = std::rand() % 10;
    int i2 = std::rand() % 10;

    for (int i = 0; i < (i1 * i2); i++) {
        list.emplace_back(rand());
    }
}

void TestLayer::OnUIRender() {
    ImGui::Begin("Test list");
    {
        ImGui::Text("%s", std::string("list.size(" + std::to_string(list.size()) + ")").c_str());

        for (const auto& item : list) {
            ImGui::Text("%s", std::to_string(item).c_str());
        }
    }
    ImGui::End();
}

void TestLayer::OnDetach() {
    list.clear();
}

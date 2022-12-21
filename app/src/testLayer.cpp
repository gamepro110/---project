#include "testLayer.h"

#include <ctime>
#include <iostream>

void TestLayer::OnAttach() {
    std::srand(std::time(0));
    int i1 = std::rand() % 10;
    int i2 = std::rand() % 10;

    std::cout << ">>> i1(" << i1 << ") i2(" << i2 << ")\n";
    
    for (int i = 0; i < (i1 * i2); i++) {
        list.emplace_back(rand());
    }
}

void TestLayer::OnUIRender() {
    ImGui::Begin("Test list");
    {
        sprintf(txt, "items in List: %d\n", list.size());
        ImGui::Text(txt);
        
        for (const auto& item : list) {
            ImGui::Text(std::to_string(item).c_str());
        }
    }
    ImGui::End();
}

void TestLayer::OnDetach() {
    list.clear();
}

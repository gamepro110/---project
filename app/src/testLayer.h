#include "corelib/Application.h"

#include <vector>

class TestLayer : public ABC_Name::Layer {
public:
    void OnAttach() override;
    void OnUIRender() override;
    void OnDetach() override;
    
private:
    std::vector<int> list{};
    char txt[300];
};

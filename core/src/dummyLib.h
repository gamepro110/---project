#pragma once

#include <thread>
#include <string>
#include <sstream>

class DummyLib {
public:
    DummyLib();
    ~DummyLib();

public:
    int& GetNum();

private:
    int num;
};

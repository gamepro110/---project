#include "dummyLib.h"

DummyLib::DummyLib() :
    num(0)
{
}

DummyLib::~DummyLib() {
}

int& DummyLib::GetNum() {
    return num;
}

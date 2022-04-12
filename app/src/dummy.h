#pragma once

#include "dummyLib.h"

#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <fstream>

//void* operator new(size_t size)
//{
//	std::cout << "allocating " << size << " bytes\n";
//
//	return malloc(size);
//}
//
//void operator delete(void* memory, size_t size)
//{
//	std::cout << "freeing " << size << " bytes\n";
//
//	free(memory);
//}

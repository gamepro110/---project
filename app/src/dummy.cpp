#include "dummy.h"

#if defined(ABC_WINDOWS)
#elif defined(ABC_LINUX)
#endif

int program() {
	{
		std::unique_ptr<DummyLib> dum = std::make_unique<DummyLib>();
	}

	std::cout << "dummy app" << std::endl;

	return 0;
}

int main(){
	return program();
}

int WinMain(){
	return program();
}

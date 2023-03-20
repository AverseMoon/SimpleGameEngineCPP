#include <SimpleGameEngine.hpp>
using namespace SGE_CORE;
using namespace SGE_GRAPHICS;
using namespace SGE_NODES;
using namespace SGE_UTIL;

int main() {
	Window win = Window(Vec2(50,50));
	NODETYPE myRect = Rectangle();
	win.AddChild(myRect);
	win.Run();
	return 0;
}
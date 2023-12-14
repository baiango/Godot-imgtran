#include "import.hpp"


void Imgtran::_bind_methods() {
	ClassDB::bind_method(D_METHOD("add", "a", "b"), &Imgtran::add);
}

int Imgtran::add(int a, int b) {
	return a + b;
}

#include "import.hpp"


void Imgtran::_bind_methods() {
	ClassDB::bind_method(D_METHOD("add", "a", "b"), &Imgtran::add);
	ClassDB::bind_method(D_METHOD("square", "x"), &Imgtran::square);
}

int Imgtran::add(int a, int b) {
	return a + b;
}

double Imgtran::square(double x) {
	return square_(&x);
}

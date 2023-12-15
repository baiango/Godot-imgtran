#include "import.hpp"

void Imgtran::_bind_methods() {
	ClassDB::bind_method(D_METHOD("add", "a", "b"), &Imgtran::add);
	ClassDB::bind_method(D_METHOD("square", "x"), &Imgtran::square);
	ClassDB::bind_method(D_METHOD("dct_2d", "gray_image"), &Imgtran::dct_2d);
	ClassDB::bind_method(D_METHOD("idct_2d", "dct_coefficients"), &Imgtran::idct_2d);
}

int Imgtran::add(int a, int b) {
	return a + b;
}

double Imgtran::square(double x) {
	return sqrt(x);
}

PackedFloat32Array Imgtran::dct_2d(const PackedFloat32Array &gray_image) {
	return INJECTABLE Transform::dct_2d(gray_image);
}

PackedFloat32Array Imgtran::idct_2d(const PackedFloat32Array &dct_coefficients) {
	return INJECTABLE Transform::idct_2d(dct_coefficients);
}

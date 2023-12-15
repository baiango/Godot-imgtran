#pragma once


using namespace godot;

class Imgtran : public Object {
private:
	// Godot class constructor
	GDCLASS(Imgtran, Object);

protected:
	// Godot binding function
	static void _bind_methods();

public:
	// Your functions
	int add(int a, int b);
	double square(double x);
	PackedFloat32Array dct_2d(PackedFloat32Array gray_image);
	PackedFloat32Array idct_2d(const PackedFloat32Array& dct_coefficients);
};

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
	double addf(double a, double b);
	double square(double x);
};

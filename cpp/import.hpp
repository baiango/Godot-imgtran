#pragma once
// Include headers in hpp files
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/core/class_db.hpp>


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
};

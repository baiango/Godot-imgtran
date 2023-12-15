#pragma once
#include <godot_cpp/variant/packed_float32_array.hpp>
#include <godot_cpp/core/math.hpp>
#include "../macros.hpp"
using namespace godot;

namespace Transform {
	PackedFloat32Array dct_2d(const PackedFloat32Array &gray_image);
	PackedFloat32Array idct_2d(const PackedFloat32Array &dct_coefficients);
}

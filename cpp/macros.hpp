#pragma once
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// It's used to hint to people that it's possible to inject a function into it.
#define INJECTABLE

// "I promise that the pointer will not overlap with the compiler.
// The 'restrict' keyword will skip loading one of the variables in the code.
// This is best served for first-time pointer comers."
#define __restrict__ restrict

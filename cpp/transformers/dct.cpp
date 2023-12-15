#include "dct.hpp"


PackedFloat32Array Transform::dct_2d(const PackedFloat32Array &gray_image) {
	size_t n = sqrt(gray_image.size());
	PackedFloat32Array dct_coefficients;
	dct_coefficients.resize(gray_image.size());

	for (size_t u = 0; u < n; ++u) {
		for (size_t v = 0; v < n; ++v) {
			float dct_sum = 0.0f;
			float cu = (u == 0) ? sqrt(1.0f / n) : sqrt(2.0f / n);
			float cv = (v == 0) ? sqrt(1.0f / n) : sqrt(2.0f / n);

			for (size_t x = 0; x < n; ++x) {
				for (size_t y = 0; y < n; ++y) {
					float pixel = gray_image[x * n + y];
					float cos1 = cos(M_PI / n * (x + 0.5) * u);
					float cos2 = cos(M_PI / n * (y + 0.5) * v);
					dct_sum += pixel * cos1 * cos2;
				}
			}

			dct_coefficients[u * n + v] = dct_sum * cu * cv;
		}
	}

	return dct_coefficients;
}


PackedFloat32Array Transform::idct_2d(const PackedFloat32Array &dct_coefficients) {
	size_t n = sqrt(dct_coefficients.size());
	PackedFloat32Array reconstructed_image;
	reconstructed_image.resize(dct_coefficients.size());

	for (size_t x = 0; x < n; ++x) {
		for (size_t y = 0; y < n; ++y) {
			float sum = 0.0f;

			for (size_t u = 0; u < n; ++u) {
				for (size_t v = 0; v < n; ++v) {
					float alpha_u = (u == 0) ? sqrt(1.0f / n) : sqrt(2.0f / n);
					float alpha_v = (v == 0) ? sqrt(1.0f / n) : sqrt(2.0f / n);

					sum += alpha_u * alpha_v * dct_coefficients[u + v * n] *
						   cos(M_PI / n * (x + 0.5) * u) *
						   cos(M_PI / n * (y + 0.5) * v);
				}
			}

			reconstructed_image[x + y * n] = sum;
		}
	}

	return reconstructed_image;
}

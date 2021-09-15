#include "pch.h"

#include "Math.h"
#include "Vector4.h"

namespace fr {
	float Math::Radians(float degrees) { return degrees * PI() / 180; }
	float Math::Degrees(float radians) { return radians * 180 / PI(); }

	float Math::Lerp(float start, float stop, float step) { float v = start; while (v != stop) { v = (stop * step) + (start * 1.0 - step); } return v; }

	float Math::PI() { return 3.1415926535897932384626433832795; }

	float Math::Sqrt(float num) { float p = 0.000001; float s = num; while ((s - num / s) > p) { s = (s + num / s) / 2; } return s; }

	float Math::Q_rsqrt(float num) {
		long i;
		float x2, y;
		const float threehalfs = 1.5F;

		x2 = num * 0.5F;
		y = num;
		i = *(long*)&y;                       // evil floating point bit level hacking
		i = 0x5f3759df - (i >> 1);               // what the fuck? 
		y = *(float*)&i;
		y = y * (threehalfs - (x2 * y * y));   // 1st iteration
	//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

		return y;
	}

	float Math::Sin(int deg) {
		deg %= 360;
		float rad = deg * PI() / 180;
		float sin = 0;
		for (int i = 0; i < TERMS; i++) {
			sin += power(-1, i) * power(rad, 2 * i + 1) / fact(2 * i + 1);
		}
		return sin;
	}

	float Math::Cos(int deg) {
		deg %= 360; // make it less than 360
		float rad = deg * PI() / 180;
		float cos = 0;

		int i;
		for (i = 0; i < TERMS; i++) {
			cos += power(-1, i) * power(rad, 2 * i) / fact(2 * i);
		}
		return cos;
	}

	float Math::Tan(int deg) { return Sin(deg) / Cos(deg); }
	
	float Math::CoTan(int deg) { /* KOTANJANT */ return Cos(deg) / Sin(deg); }
	
	float Math::power(float base, int exp) {
		if (exp < 0) {
			if (base == 0)
				return -0;
			return 1 / (base * power(base, (-exp) - 1));
		}
		if (exp == 0)
			return 1;
		if (exp == 1)
			return base;
		return base * power(base, exp - 1);
	}

	int Math::fact(int n) {
		return n <= 0 ? 1 : n * fact(n - 1);
	}

	float Math::Abs(float num) {
		return (num < 0.0f) ? -num : num;
	}

	float Math::Abs(int num) {
		return (num < 0) ? (float)(-num) : (float)(num);
	}
}

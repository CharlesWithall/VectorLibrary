#pragma once
#pragma once

#include <cfloat>
#include <math.h>
#include <xmmintrin.h>
#include <pmmintrin.h>

class Vector4SIMD
{
public:
	Vector4SIMD() {};
	Vector4SIMD(const float aX, const float aY, const float aZ, const float aW) : myValue(_mm_setr_ps(aX, aY, aZ, aW)) {};
	Vector4SIMD(const __m128& aValue) : myValue(aValue) {}

	// Simple Arithmetic
	inline Vector4SIMD operator+(const Vector4SIMD& anRHS) const
	{
		return _mm_add_ps(myValue, anRHS.myValue);
	}

	inline Vector4SIMD operator-(const Vector4SIMD& anRHS) const
	{
		return _mm_sub_ps(myValue, anRHS.myValue);
	}

	inline Vector4SIMD operator*(const Vector4SIMD& anRHS) const
	{
		return _mm_mul_ps(myValue, anRHS.myValue);
	}

	inline Vector4SIMD operator/(const Vector4SIMD& anRHS) const
	{
		return _mm_div_ps(myValue, anRHS.myValue);
	}

	inline Vector4SIMD operator*(const float anRHS) const
	{
		return _mm_mul_ps(myValue, _mm_setr_ps(anRHS, anRHS, anRHS, anRHS));
	}

	inline Vector4SIMD operator/(const float anRHS) const
	{
		return _mm_div_ps(myValue, _mm_setr_ps(anRHS, anRHS, anRHS, anRHS));
	}

	// Simple Assignment Arithmetic
	inline Vector4SIMD& operator+=(const Vector4SIMD& anRHS)
	{
		myValue = _mm_add_ps(myValue, anRHS.myValue);
		return *this;
	}

	inline Vector4SIMD& operator-=(const Vector4SIMD& anRHS)
	{
		myValue = _mm_sub_ps(myValue, anRHS.myValue);
		return *this;
	}

	inline Vector4SIMD& operator*=(const Vector4SIMD& anRHS)
	{
		myValue = _mm_mul_ps(myValue, anRHS.myValue);
		return *this;
	}

	inline Vector4SIMD& operator/=(const Vector4SIMD& anRHS)
	{
		myValue = _mm_div_ps(myValue, anRHS.myValue);
		return *this;
	}

	inline Vector4SIMD& operator*=(const float anRHS)
	{
		myValue = _mm_mul_ps(myValue, _mm_setr_ps(anRHS, anRHS, anRHS, anRHS));
		return *this;
	}

	inline Vector4SIMD& operator/=(const float anRHS)
	{
		myValue = _mm_div_ps(myValue, _mm_setr_ps(anRHS, anRHS, anRHS, anRHS));
		return *this;
	}

	// Relational Operators
	inline bool operator==(const Vector4SIMD& anRHS) const
	{
		__m128i comparison = _mm_castps_si128(_mm_cmpneq_ps(myValue, anRHS.myValue));
		uint16_t intConversion = _mm_movemask_epi8(comparison);
		return intConversion == 0;
	}

	inline bool operator!=(const Vector4SIMD& anRHS) const
	{
		__m128i comparison = _mm_castps_si128(_mm_cmpneq_ps(myValue, anRHS.myValue));
		uint16_t intConversion = _mm_movemask_epi8(comparison);
		return intConversion != 0;
	}

	// Distances
	float Magnitude() const
	{
		return sqrt(Magnitude2());
	}

	float Magnitude2() const
	{
		__m128 result;
		__m128 value = _mm_mul_ps(myValue, myValue);
		result = _mm_hadd_ps(value, value);
		result = _mm_hadd_ps(result, result);
		return _mm_cvtss_f32(result);
	}

	float Distance(const Vector4SIMD& anRHS) const
	{
		Vector4SIMD diff = anRHS - *this;
		return diff.Magnitude();
	}

	float Distance2(const Vector4SIMD& anRHS) const
	{
		Vector4SIMD diff = anRHS - *this;
		return diff.Magnitude2();
	}

	Vector4SIMD Scale(const float& aScale)
	{
		return (Normalise() * aScale);
	}

	// Products
	float Dot(const Vector4SIMD& anRHS) const
	{
		__m128 result;
		__m128 value = _mm_mul_ps(myValue, anRHS.myValue);
		result = _mm_hadd_ps(value, value);
		result = _mm_hadd_ps(result, result);
		return _mm_cvtss_f32(result);
	}

	Vector4SIMD Cross(const Vector4SIMD& anRHS) const
	{
		return _mm_sub_ps(
			_mm_mul_ps(_mm_shuffle_ps(myValue, myValue, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(anRHS.myValue, anRHS.myValue, _MM_SHUFFLE(3, 1, 0, 2))),
			_mm_mul_ps(_mm_shuffle_ps(myValue, myValue, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(anRHS.myValue, anRHS.myValue, _MM_SHUFFLE(3, 0, 2, 1)))
		);
	}

	// Angles
	float Theta(const Vector4SIMD& anRHS) const
	{
		const float numerator = Dot(anRHS);
		const float denominator = Magnitude() * anRHS.Magnitude();
		return acos(numerator / denominator);
	}

	// Normalise
	Vector4SIMD Normalise()
	{
		return *this / this->Magnitude();
	}

	// Members
	__m128 myValue;
};
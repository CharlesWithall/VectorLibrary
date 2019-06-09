#pragma once
#pragma once

#include <math.h>

class Vector4
{
public:
	Vector4() : x(0), y(0), z(0), w(0) {};
	Vector4(const float anX, const float aY, const float aZ, const float aW) : x(anX), y(aY), z(aZ), w(aW) {};

	// Simple Arithmetic
	inline Vector4 operator+(const Vector4& anRHS) const
	{
		return Vector4(x + anRHS.x, y + anRHS.y, z + anRHS.z, w + anRHS.w);
	}

	inline Vector4 operator-(const Vector4& anRHS) const
	{
		Vector4 result;
		result.x = x - anRHS.x;
		result.y = y - anRHS.y;
		result.z = z - anRHS.z;
		result.w = w - anRHS.w;
		return result;
	}

	inline Vector4 operator*(const Vector4& anRHS) const
	{
		Vector4 result;
		result.x = x * anRHS.x;
		result.y = y * anRHS.y;
		result.z = z * anRHS.z;
		result.w = w * anRHS.w;
		return result;
	}

	inline Vector4 operator/(const Vector4& anRHS) const
	{
		Vector4 result;
		result.x = x / anRHS.x;
		result.y = y / anRHS.y;
		result.z = z / anRHS.z;
		result.w = w / anRHS.w;
		return result;
	}

	inline Vector4 operator*(const float anRHS) const
	{
		Vector4 result;
		result.x = x * anRHS;
		result.y = y * anRHS;
		result.z = z * anRHS;
		result.w = w * anRHS;
		return result;
	}

	inline Vector4 operator/(const float anRHS) const
	{
		Vector4 result;
		result.x = x / anRHS;
		result.y = y / anRHS;
		result.z = z / anRHS;
		result.w = w / anRHS;
		return result;
	}

	// Simple Assignment Arithmetic
	inline Vector4& operator+=(const Vector4& anRHS)
	{
		x += anRHS.x;
		y += anRHS.y;
		z += anRHS.z;
		w += anRHS.w;
		return *this;
	}

	inline Vector4& operator-=(const Vector4& anRHS)
	{
		x -= anRHS.x;
		y -= anRHS.y;
		z -= anRHS.z;
		w -= anRHS.w;
		return *this;
	}

	inline Vector4& operator*=(const Vector4& anRHS)
	{
		x *= anRHS.x;
		y *= anRHS.y;
		z *= anRHS.z;
		w *= anRHS.w;
		return *this;
	}

	inline Vector4& operator/=(const Vector4& anRHS)
	{
		x /= anRHS.x;
		y /= anRHS.y;
		z /= anRHS.z;
		w /= anRHS.w;
		return *this;
	}

	inline Vector4& operator*=(const float anRHS)
	{
		x *= anRHS;
		y *= anRHS;
		z *= anRHS;
		w *= anRHS;
		return *this;
	}

	inline Vector4& operator/=(const float anRHS)
	{
		x /= anRHS;
		y /= anRHS;
		z /= anRHS;
		w /= anRHS;
		return *this;
	}

	// Relational Operators
	inline bool operator==(const Vector4& anRHS) const
	{
		return (x == anRHS.x && y == anRHS.y && z == anRHS.z && w == anRHS.w);
	}

	inline bool operator!=(const Vector4& anRHS) const
	{
		return (x != anRHS.x || y != anRHS.y || z != anRHS.z || w != anRHS.w);
	}

	// Distances
	float Magnitude() const
	{
		return sqrt((x*x) + (y*y) + (z*z) + (w*w));
	}

	float Magnitude2() const
	{
		return (x*x) + (y*y) + (z*z) + (w*w);
	}

	float Distance(const Vector4& anRHS) const
	{
		Vector4 diff = anRHS - *this;
		return diff.Magnitude();
	}

	float Distance2(const Vector4& anRHS) const
	{
		Vector4 diff = anRHS - *this;
		return diff.Magnitude2();
	}

	Vector4 Scale(const float& aScale)
	{
		return (Normalise() * aScale);
	}

	// Products
	float Dot(const Vector4& anRHS) const
	{
		return (x * anRHS.x) + (y * anRHS.y) + (z * anRHS.z) + (w * anRHS.w);
	}

	Vector4 Cross(const Vector4& anRHS) const
	{
		return Vector4((y * anRHS.z) - (z * anRHS.y), (z * anRHS.x) - (x * anRHS.z), (x * anRHS.y) - (y * anRHS.x), w);
	}

	// Angles
	float Theta(const Vector4& anRHS) const
	{
		const float numerator = Dot(anRHS);
		const float denominator = Magnitude() * anRHS.Magnitude();
		return acos(numerator / denominator);
	}

	// Normalise
	Vector4 Normalise()
	{
		return *this / this->Magnitude();
	}

	// Members
	float x, y, z, w;
};
#pragma once

// Git Hub
// Write unit tests to test class
// Allow for all numeric types float/int/double etc.
// Allow for multiple dimensions
// Rewrite with intrinsics

#include <math.h>

class Vector2
{
public:
	Vector2() : x(0), y(0) {};
	Vector2(const double anX, const double aY) : x(anX), y(aY) {};

	// Simple Arithmetic
	Vector2 operator+(const Vector2& anRHS) const
	{
		Vector2 result;
		result.x = x + anRHS.x;
		result.y = y + anRHS.y;
		return result;
	}

	Vector2 operator-(const Vector2& anRHS) const
	{
		Vector2 result;
		result.x = x - anRHS.x;
		result.y = y - anRHS.y;
		return result;
	}

	Vector2 operator*(const Vector2& anRHS) const
	{
		Vector2 result;
		result.x = x * anRHS.x;
		result.y = y * anRHS.y;
		return result;
	}

	Vector2 operator/(const Vector2& anRHS) const
	{
		Vector2 result;
		result.x = x / anRHS.x;
		result.y = y / anRHS.y;
		return result;
	}

	Vector2 operator*(const double anRHS) const
	{
		Vector2 result;
		result.x = x * anRHS;
		result.y = y * anRHS;
		return result;
	}

	Vector2 operator/(const double anRHS) const
	{
		Vector2 result;
		result.x = x / anRHS;
		result.y = y / anRHS;
		return result;
	}

	// Simple Assignment Arithmetic
	Vector2& operator+=(const Vector2& anRHS)
	{
		x += anRHS.x;
		y += anRHS.y;
		return *this;
	}

	Vector2& operator-=(const Vector2& anRHS)
	{
		x -= anRHS.x;
		y -= anRHS.y;
		return *this;
	}

	Vector2& operator*=(const Vector2& anRHS)
	{
		x *= anRHS.x;
		y *= anRHS.y;
		return *this;
	}

	Vector2& operator/=(const Vector2& anRHS)
	{
		x /= anRHS.x;
		y /= anRHS.y;
		return *this;
	}

	Vector2& operator*=(const double anRHS)
	{
		x *= anRHS;
		y *= anRHS;
		return *this;
	}

	Vector2& operator/=(const double anRHS)
	{
		x /= anRHS;
		y /= anRHS;
		return *this;
	}

	// Relational Operators
	bool operator==(const Vector2& anRHS) const
	{
		return (x == anRHS.x && y == anRHS.y);
	}

	bool operator!=(const Vector2& anRHS) const
	{
		return (x != anRHS.x || y != anRHS.y);
	}

	// Distances
	double Length() const
	{
		return sqrt((x*x) + (y*y));
	}

	double Length2() const
	{
		return (x*x) + (y*y);
	}

	double Distance(const Vector2& anRHS) const
	{
		Vector2 diff = anRHS - *this;
		return diff.Length();
	}

	double Distance2(const Vector2& anRHS) const
	{
		Vector2 diff = anRHS - *this;
		return diff.Length2();
	}

	// Products
	double Dot(const Vector2& anRHS) const
	{
		return (x * anRHS.x) + (y * anRHS.y);
	}

	// Angles
	double Theta(const Vector2& anRHS) const
	{
		const double numerator = Dot(anRHS);
		const double denominator = Length() * anRHS.Length();
		return acos(numerator / denominator);
	}

	// Normalise
	Vector2 Normalise()
	{
		return *this / this->Length();
	}

	// Members
	double x, y;
};
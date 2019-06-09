#include "stdafx.h"
#include "CppUnitTest.h"
#include "../VectorLibraryDemo/Vector2.h"
#include "../VectorLibraryDemo/Vector4.h"
#include "../VectorLibraryDemo/Vector4SIMD.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {

			template<>
			static std::wstring ToString<Vector2>(const Vector2& vector)
			{
				return L"String representing vector2.";
			}

			template<>
			static std::wstring ToString<Vector4>(const Vector4& vector)
			{
				return L"String representing vector4.";
			}

			template<>
			static std::wstring ToString<Vector4SIMD>(const Vector4SIMD& vector)
			{
				return L"String representing vector4SIMD.";
			}
		}
	}
}

namespace VectorTest
{		
	TEST_CLASS(Vector2UnitTests)
	{
	public:
		
		TEST_METHOD(Addition)
		{
			// Arrange
			Vector2 firstVector = Vector2(1, 2);
			Vector2 secondVector = Vector2(3, 4);

			// Act
			const Vector2 simpleResult = firstVector + secondVector;
			const Vector2 assignmentResult = firstVector += secondVector;

			// Assert
			const Vector2 answer = Vector2(4, 6);
			Assert::AreEqual(simpleResult, answer);
			Assert::AreEqual(assignmentResult, answer);
			Assert::AreEqual(firstVector, answer);
			Assert::AreNotEqual(secondVector, answer);
		}

		TEST_METHOD(Subtraction)
		{
			// Arrange
			Vector2 firstVector = Vector2(1, 2);
			Vector2 secondVector = Vector2(3, 4);

			// Act
			const Vector2 simpleResult = secondVector - firstVector;
			const Vector2 assignmentResult = secondVector -= firstVector;

			// Assert
			const Vector2 answer = Vector2(2, 2);
			Assert::AreEqual(simpleResult, answer);
			Assert::AreEqual(assignmentResult, answer);
			Assert::AreEqual(secondVector, answer);
			Assert::AreNotEqual(firstVector, answer);
		}

		TEST_METHOD(MultiplicationWithVector)
		{
			// Arrange
			Vector2 firstVector = Vector2(1, 2);
			Vector2 secondVector = Vector2(3, 4);

			// Act
			const Vector2 simpleResult = firstVector * secondVector;
			const Vector2 assignmentResult = firstVector *= secondVector;

			// Assert
			const Vector2 answer = Vector2(3, 8);
			Assert::AreEqual(simpleResult, answer);
			Assert::AreEqual(assignmentResult, answer);
			Assert::AreEqual(firstVector, answer);
			Assert::AreNotEqual(secondVector, answer);
		}

		TEST_METHOD(MultiplicationWithNumeric)
		{
			// Arrange
			Vector2 vector = Vector2(1, 2);
			double numeric = 6.0;

			// Act
			const Vector2 simpleResult = vector * numeric;
			const Vector2 assignmentResult = vector *= numeric;

			// Assert
			const Vector2 answer = Vector2(6, 12);
			Assert::AreEqual(simpleResult, answer);
			Assert::AreEqual(assignmentResult, answer);
			Assert::AreEqual(vector, answer);
		}

		TEST_METHOD(DivisionWithVector)
		{
			// Arrange
			Vector2 firstVector = Vector2(1, 2);
			Vector2 secondVector = Vector2(3, 4);

			// Act
			const Vector2 simpleResult = secondVector / firstVector;
			const Vector2 assignmentResult = secondVector /= firstVector;

			// Assert
			const Vector2 answer = Vector2(3, 2);
			Assert::AreEqual(simpleResult, answer);
			Assert::AreEqual(assignmentResult, answer);
			Assert::AreEqual(secondVector, answer);
			Assert::AreNotEqual(firstVector, answer);
		}

		TEST_METHOD(DivisionWithNumeric)
		{
			// Arrange
			Vector2 vector = Vector2(15, 25);
			double numeric = 5.0;

			// Act
			const Vector2 simpleResult = vector / numeric;
			const Vector2 assignmentResult = vector /= numeric;

			// Assert
			const Vector2 answer = Vector2(3, 5);
			Assert::AreEqual(simpleResult, answer);
			Assert::AreEqual(assignmentResult, answer);
			Assert::AreEqual(vector, answer);
		}

		TEST_METHOD(Length)
		{
			// Arrange
			Vector2 firstVector = Vector2(3, 4);
			Vector2 secondVector = Vector2(5, 12);

			// Act
			const double firstResult = firstVector.Length();
			const double secondResult = secondVector.Length();
			const double firstResult2 = firstVector.Length2();
			const double secondResult2 = secondVector.Length2();

			// Assert
			Assert::AreEqual(firstResult, 5.0);
			Assert::AreEqual(secondResult, 13.0);
			Assert::AreEqual(firstResult2, 25.0);
			Assert::AreEqual(secondResult2, 169.0);
		}

		TEST_METHOD(Distance)
		{
			// Arrange
			Vector2 firstVector = Vector2(3, 4);
			Vector2 secondVector = Vector2(7, 7);

			// Act
			const double firstResult = firstVector.Distance(secondVector);
			const double secondResult = firstVector.Distance2(secondVector);

			const double reverse1Result = secondVector.Distance(firstVector);
			const double reverse2Result = secondVector.Distance2(firstVector);

			// Assert
			Assert::AreEqual(firstResult, 5.0);
			Assert::AreEqual(secondResult, 25.0);
			Assert::AreEqual(reverse1Result, 5.0);
			Assert::AreEqual(reverse2Result, 25.0);
		}

		TEST_METHOD(Dot)
		{
			// Arrange
			Vector2 firstVector = Vector2(2, 5);
			Vector2 secondVector = Vector2(3, 6);

			Vector2 firstVector2 = Vector2(-12, -3);
			Vector2 secondVector2 = Vector2(9, -6);

			// Act
			const double firstResult = firstVector.Dot(secondVector);
			const double secondResult = firstVector2.Dot(secondVector2);

			// Assert
			Assert::AreEqual(firstResult, 36.0);
			Assert::AreEqual(secondResult, -90.0);
		}

		TEST_METHOD(Normalise)
		{
			// Arrange
			Vector2 firstVector = Vector2(2, 5);
			Vector2 secondVector = Vector2(-12, -3);

			// Act
			const double firstResult = firstVector.Normalise().Length();
			const double secondResult = secondVector.Normalise().Length();

			// Assert
			Assert::AreEqual(firstResult, 1.0);
			Assert::AreEqual(secondResult, 1.0);
		}
	};

	TEST_CLASS(Vector4UnitTests)
	{
	public:

		TEST_METHOD(Addition)
		{
			// Arrange
			Vector4 firstVector = Vector4(1, 2, 6, 4);
			Vector4 secondVector = Vector4(3, 4, -1, -13);

			// Act
			const Vector4 simpleResult = firstVector + secondVector;
			const Vector4 assignmentResult = firstVector += secondVector;

			// Assert
			const Vector4 answer = Vector4(4, 6, 5, -9);
			Assert::AreEqual(simpleResult, answer);
			Assert::AreEqual(assignmentResult, answer);
			Assert::AreEqual(firstVector, answer);
			Assert::AreNotEqual(secondVector, answer);
		}

		TEST_METHOD(Subtraction)
		{
			// Arrange
			Vector4 firstVector = Vector4(1, 2, 6, 4);
			Vector4 secondVector = Vector4(3, 4, -1, -13);

			// Act
			const Vector4 simpleResult = secondVector - firstVector;
			const Vector4 assignmentResult = secondVector -= firstVector;

			// Assert
			const Vector4 answer = Vector4(2, 2, -7, -17);
			Assert::AreEqual(simpleResult, answer);
			Assert::AreEqual(assignmentResult, answer);
			Assert::AreEqual(secondVector, answer);
			Assert::AreNotEqual(firstVector, answer);
		}

		TEST_METHOD(MultiplicationWithVector)
		{
			// Arrange
			Vector4 firstVector = Vector4(1, 2, 6, 4);
			Vector4 secondVector = Vector4(3, 4, -1, -13);

			// Act
			const Vector4 simpleResult = firstVector * secondVector;
			const Vector4 assignmentResult = firstVector *= secondVector;

			// Assert
			const Vector4 answer = Vector4(3, 8, -6, -52);
			Assert::AreEqual(simpleResult, answer);
			Assert::AreEqual(assignmentResult, answer);
			Assert::AreEqual(firstVector, answer);
			Assert::AreNotEqual(secondVector, answer);
		}

		TEST_METHOD(MultiplicationWithNumeric)
		{
			// Arrange
			Vector4 vector = Vector4(1, 2, 6, 4);
			float numeric = 6.0;

			// Act
			const Vector4 simpleResult = vector * numeric;
			const Vector4 assignmentResult = vector *= numeric;

			// Assert
			const Vector4 answer = Vector4(6, 12, 36, 24);
			Assert::AreEqual(simpleResult, answer);
			Assert::AreEqual(assignmentResult, answer);
			Assert::AreEqual(vector, answer);
		}

		TEST_METHOD(DivisionWithVector)
		{
			// Arrange
			Vector4 firstVector = Vector4(1, 2, -1, 4);
			Vector4 secondVector = Vector4(3, 4, 6, -16);

			// Act
			const Vector4 simpleResult = secondVector / firstVector;
			const Vector4 assignmentResult = secondVector /= firstVector;

			// Assert
			const Vector4 answer = Vector4(3, 2, -6, -4);
			Assert::AreEqual(simpleResult, answer);
			Assert::AreEqual(assignmentResult, answer);
			Assert::AreEqual(secondVector, answer);
			Assert::AreNotEqual(firstVector, answer);
		}

		TEST_METHOD(DivisionWithNumeric)
		{
			// Arrange
			Vector4 vector = Vector4(15, 25, 125, -10);
			float numeric = 5.0;

			// Act
			const Vector4 simpleResult = vector / numeric;
			const Vector4 assignmentResult = vector /= numeric;

			// Assert
			const Vector4 answer = Vector4(3, 5, 25, -2);
			Assert::AreEqual(simpleResult, answer);
			Assert::AreEqual(assignmentResult, answer);
			Assert::AreEqual(vector, answer);
		}

		TEST_METHOD(Length)
		{
			// Arrange
			Vector4 firstVector = Vector4(3, 4, 5, 12);
			Vector4 secondVector = Vector4(5, 12, -8 ,0);

			// Act
			const float firstResult = firstVector.Magnitude();
			const float secondResult = secondVector.Magnitude();
			const float firstResult2 = firstVector.Magnitude2();
			const float secondResult2 = secondVector.Magnitude2();

			// Assert
			Assert::AreEqual(round(firstResult * firstResult), 194.f);
			Assert::AreEqual(round(secondResult * secondResult), 233.f);
			Assert::AreEqual(firstResult2, 194.f);
			Assert::AreEqual(secondResult2, 233.f);
		}

		TEST_METHOD(Distance)
		{
			// Arrange
			Vector4 firstVector = Vector4(3, 4, 5, 12);
			Vector4 secondVector = Vector4(5, 12, -8, 0);

			// Act
			const float firstResult = firstVector.Distance(secondVector);
			const float secondResult = firstVector.Distance2(secondVector);

			const float reverse1Result = secondVector.Distance(firstVector);
			const float reverse2Result = secondVector.Distance2(firstVector);

			// Assert
			Assert::AreEqual(round(firstResult * firstResult), 381.f);
			Assert::AreEqual(secondResult, 381.f);
			Assert::AreEqual(round(reverse1Result * reverse1Result), 381.f);
			Assert::AreEqual(reverse2Result, 381.f);
		}

		TEST_METHOD(Dot)
		{
			// Arrange
			Vector4 firstVector = Vector4(3, 4, 5, 12);
			Vector4 secondVector = Vector4(5, 12, -8, 0);

			Vector4 firstVector2 = Vector4(-1, 4, 10, -13);
			Vector4 secondVector2 = Vector4(2, -5, 8, 4);

			// Act
			const float firstResult = firstVector.Dot(secondVector);
			const float secondResult = firstVector2.Dot(secondVector2);

			// Assert
			Assert::AreEqual(firstResult, 23.f);
			Assert::AreEqual(secondResult, 6.f);
		}

		TEST_METHOD(Cross)
		{
			// Arrange
			Vector4 firstVector = Vector4(2, 3, 4, 0);
			Vector4 secondVector = Vector4(5, 6, 7, 0);

			// Act
			Vector4 result = firstVector.Cross(secondVector);

			// Assert
			Assert::AreEqual(result, Vector4(-3, 6, -3, 0));
		}
		
		TEST_METHOD(Normalise)
		{
			// Arrange
			Vector4 firstVector = Vector4(3, 4, 5, 12);
			Vector4 secondVector = Vector4(5, 12, -8, 0);

			// Act
			const float firstResult = firstVector.Normalise().Magnitude();
			const float secondResult = secondVector.Normalise().Magnitude();

			// Assert
			Assert::AreEqual((int)firstResult, 1);
			Assert::AreEqual((int)secondResult, 1);
		}
	};

	TEST_CLASS(Vector4SIMDUnitTests)
	{
	public:

		TEST_METHOD(Addition)
		{
			// Arrange
			Vector4SIMD firstVector = Vector4SIMD(1, 2, 6, 4);
			Vector4SIMD secondVector = Vector4SIMD(3, 4, -1, -13);

			// Act
			const Vector4SIMD simpleResult = firstVector + secondVector;
			const Vector4SIMD assignmentResult = firstVector += secondVector;

			// Assert
			const Vector4SIMD answer = Vector4SIMD(4, 6, 5, -9);
			Assert::AreEqual(simpleResult, answer);
			Assert::AreEqual(assignmentResult, answer);
			Assert::AreEqual(firstVector, answer);
			Assert::AreNotEqual(secondVector, answer);
		}

		TEST_METHOD(Subtraction)
		{
			// Arrange
			Vector4SIMD firstVector = Vector4SIMD(1, 2, 6, 4);
			Vector4SIMD secondVector = Vector4SIMD(3, 4, -1, -13);

			// Act
			const Vector4SIMD simpleResult = secondVector - firstVector;
			const Vector4SIMD assignmentResult = secondVector -= firstVector;

			// Assert
			const Vector4SIMD answer = Vector4SIMD(2, 2, -7, -17);
			Assert::AreEqual(simpleResult, answer);
			Assert::AreEqual(assignmentResult, answer);
			Assert::AreEqual(secondVector, answer);
			Assert::AreNotEqual(firstVector, answer);
		}

		TEST_METHOD(MultiplicationWithVector)
		{
			// Arrange
			Vector4SIMD firstVector = Vector4SIMD(1, 2, 6, 4);
			Vector4SIMD secondVector = Vector4SIMD(3, 4, -1, -13);

			// Act
			const Vector4SIMD simpleResult = firstVector * secondVector;
			const Vector4SIMD assignmentResult = firstVector *= secondVector;

			// Assert
			const Vector4SIMD answer = Vector4SIMD(3, 8, -6, -52);
			Assert::AreEqual(simpleResult, answer);
			Assert::AreEqual(assignmentResult, answer);
			Assert::AreEqual(firstVector, answer);
			Assert::AreNotEqual(secondVector, answer);
		}

		TEST_METHOD(MultiplicationWithNumeric)
		{
			// Arrange
			Vector4SIMD vector = Vector4SIMD(1, 2, 6, 4);
			float numeric = 6.0;

			// Act
			const Vector4SIMD simpleResult = vector * numeric;
			const Vector4SIMD assignmentResult = vector *= numeric;

			// Assert
			const Vector4SIMD answer = Vector4SIMD(6, 12, 36, 24);
			Assert::AreEqual(simpleResult, answer);
			Assert::AreEqual(assignmentResult, answer);
			Assert::AreEqual(vector, answer);
		}

		TEST_METHOD(DivisionWithVector)
		{
			// Arrange
			Vector4SIMD firstVector = Vector4SIMD(1, 2, -1, 4);
			Vector4SIMD secondVector = Vector4SIMD(3, 4, 6, -16);

			// Act
			const Vector4SIMD simpleResult = secondVector / firstVector;
			const Vector4SIMD assignmentResult = secondVector /= firstVector;

			// Assert
			const Vector4SIMD answer = Vector4SIMD(3, 2, -6, -4);
			Assert::AreEqual(simpleResult, answer);
			Assert::AreEqual(assignmentResult, answer);
			Assert::AreEqual(secondVector, answer);
			Assert::AreNotEqual(firstVector, answer);
		}

		TEST_METHOD(DivisionWithNumeric)
		{
			// Arrange
			Vector4SIMD vector = Vector4SIMD(15, 25, 125, -10);
			float numeric = 5.0;

			// Act
			const Vector4SIMD simpleResult = vector / numeric;
			const Vector4SIMD assignmentResult = vector /= numeric;

			// Assert
			const Vector4SIMD answer = Vector4SIMD(3, 5, 25, -2);
			Assert::AreEqual(simpleResult, answer);
			Assert::AreEqual(assignmentResult, answer);
			Assert::AreEqual(vector, answer);
		}

		TEST_METHOD(Length)
		{
			// Arrange
			Vector4SIMD firstVector = Vector4SIMD(3, 4, 5, 12);
			Vector4SIMD secondVector = Vector4SIMD(5, 12, -8, 0);

			// Act
			const float firstResult = firstVector.Magnitude();
			const float secondResult = secondVector.Magnitude();
			const float firstResult2 = firstVector.Magnitude2();
			const float secondResult2 = secondVector.Magnitude2();

			// Assert
			Assert::AreEqual(round(firstResult * firstResult), 194.f);
			Assert::AreEqual(round(secondResult * secondResult), 233.f);
			Assert::AreEqual(firstResult2, 194.f);
			Assert::AreEqual(secondResult2, 233.f);
		}

		TEST_METHOD(Distance)
		{
			// Arrange
			Vector4SIMD firstVector = Vector4SIMD(3, 4, 5, 12);
			Vector4SIMD secondVector = Vector4SIMD(5, 12, -8, 0);

			// Act
			const float firstResult = firstVector.Distance(secondVector);
			const float secondResult = firstVector.Distance2(secondVector);

			const float reverse1Result = secondVector.Distance(firstVector);
			const float reverse2Result = secondVector.Distance2(firstVector);

			// Assert
			Assert::AreEqual(round(firstResult * firstResult), 381.f);
			Assert::AreEqual(secondResult, 381.f);
			Assert::AreEqual(round(reverse1Result * reverse1Result), 381.f);
			Assert::AreEqual(reverse2Result, 381.f);
		}

		TEST_METHOD(Dot)
		{
			// Arrange
			Vector4SIMD firstVector = Vector4SIMD(3, 4, 5, 12);
			Vector4SIMD secondVector = Vector4SIMD(5, 12, -8, 0);

			Vector4SIMD firstVector2 = Vector4SIMD(-1, 4, 10, -13);
			Vector4SIMD secondVector2 = Vector4SIMD(2, -5, 8, 4);

			// Act
			const float firstResult = firstVector.Dot(secondVector);
			const float secondResult = firstVector2.Dot(secondVector2);

			// Assert
			Assert::AreEqual(firstResult, 23.f);
			Assert::AreEqual(secondResult, 6.f);
		}

		TEST_METHOD(Cross)
		{
			// Arrange
			Vector4SIMD firstVector = Vector4SIMD(2, 3, 4, 0);
			Vector4SIMD secondVector = Vector4SIMD(5, 6, 7, 0);

			// Act
			Vector4SIMD result = firstVector.Cross(secondVector);

			// Assert
			Assert::AreEqual(result, Vector4SIMD(-3, 6, -3, 0));
		}

		TEST_METHOD(Normalise)
		{
			// Arrange
			Vector4SIMD firstVector = Vector4SIMD(3, 4, 5, 12);
			Vector4SIMD secondVector = Vector4SIMD(5, 12, -8, 0);

			// Act
			const float firstResult = firstVector.Normalise().Magnitude();
			const float secondResult = secondVector.Normalise().Magnitude();

			// Assert
			Assert::AreEqual(round(firstResult), 1.f);
			Assert::AreEqual(round(secondResult), 1.f);
		}
	};
}
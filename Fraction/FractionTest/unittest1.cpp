#include "stdafx.h"
#include "CppUnitTest.h"
#include <cassert>
#include "..\Fraction\Fraction.h"
#include "..\Fraction\Fraction.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FractionTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestAdd)
		{
			Fraction testFraction1(1, 2);
			Fraction testFraction2(1, 3);
			Fraction testFraction3(5, 6);

			Assert::IsTrue((testFraction3 == (testFraction1 + testFraction2)));
		}

		TEST_METHOD(TestSubtract)
		{
			Fraction testFraction1(1, 2);
			Fraction testFraction2(1, 3);
			Fraction testFraction3(1, 6);

			Assert::IsTrue((testFraction3 == (testFraction1 - testFraction2)));
		}

		TEST_METHOD(TestMultiply)
		{
			Fraction testFraction1(1, 2);
			Fraction testFraction2(1, 3);
			Fraction testFraction3(1, 6);

			Assert::IsTrue((testFraction3 == (testFraction1 * testFraction2)));
		}

		TEST_METHOD(TestDivide)
		{
			Fraction testFraction1(1, 2);
			Fraction testFraction2(1, 3);
			Fraction testFraction3(3, 2);

			Assert::IsTrue((testFraction3 == (testFraction1 / testFraction2)));
		}

		TEST_METHOD(TestEvaluate)
		{
			Fraction testFraction1(5, -10);
			double testResult = -0.5;

			Assert::IsTrue(testResult == testFraction1.Evaluate());
		}

	};
}
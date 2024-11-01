#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 6.4 r/lab 6.4 r.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64rec
{
    TEST_CLASS(UnitTest64rec)
    {
    public:

        TEST_METHOD(TestProductNegatives)
        {
            const int SIZE = 5;
            double arr[SIZE] = { -2.0, 3.5, -4.0, 5.0, 6.0 };


            double expectedProduct = 22.5;


            double result = sumAfterFirstNegative(arr, SIZE, 0, 2, 2);
            Assert::AreEqual(expectedProduct, result);
        }
    };
}
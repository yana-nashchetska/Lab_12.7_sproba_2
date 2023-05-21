#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My127unitspr2
{
	TEST_CLASS(My127unitspr2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			list<string> stringList = { "a", "b", "c", "d", "e" };
			list<int> indexList = { 2, 4 };

			removeElements(stringList, indexList);

			list<string> expectedList = { "a", "c", "e" };
			Assert::IsTrue(stringList == expectedList);
		}
	};
}


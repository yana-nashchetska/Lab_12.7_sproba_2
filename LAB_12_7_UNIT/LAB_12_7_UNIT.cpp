#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.7_sproba_2/Lab_12.7_spr2.cpp"
#include <list>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LAB127UNIT
{
	struct ExpectedResult
	{
		std::list<std::string> elements;
	};


	TEST_CLASS(LAB127UNIT)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			NumberNode* numberList = nullptr;
			StringNode* stringList = nullptr;

			addStringNode(stringList, "a");
			addStringNode(stringList, "b");
			addStringNode(stringList, "c");
			addStringNode(stringList, "d");
			addStringNode(stringList, "e");
			addStringNode(stringList, "f");
			addStringNode(stringList, "g");
			addStringNode(stringList, "h");
			addStringNode(stringList, "j");
			addStringNode(stringList, "k");


			addNumberNode(numberList, 1);
			addNumberNode(numberList, 5);
			addNumberNode(numberList, 8);


			
			ExpectedResult expected;
			expected.elements = { "b", "c", "d", "f", "g", "j", "k" };

			deleteStringNodes(stringList, numberList);
			int index = 0;
			for (const auto& expectedElement : expected.elements) {
				std::wstring errorMessage = L"Element mismatch at index " + std::to_wstring(index);
				Assert::AreEqual(expectedElement, stringList->data, errorMessage.c_str());
				stringList = stringList->next;
				index++;
			}

		}
		
	};
}

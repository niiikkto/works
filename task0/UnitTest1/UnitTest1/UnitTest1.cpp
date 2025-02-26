#include "pch.h"
#include "CppUnitTest.h"
#include "../../TreasureHunt/TreasureHunt/Character.h"
#include "../../TreasureHunt/TreasureHunt/Enemy.h"
#include "../../TreasureHunt/TreasureHunt/Player.h"
#include "../../TreasureHunt/TreasureHunt/Character.cpp"
#include "../../TreasureHunt/TreasureHunt/Enemy.cpp"
#include "../../TreasureHunt/TreasureHunt/Player.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestPlayerCreation)
		{
			Player player("Jerry", 100, 15, 5);
			Assert::AreEqual(std::string("Jerry"), player.getName());
			Assert::AreEqual(100, player.getHealth());
			Assert::AreEqual(15, player.getStrength());
			Assert::AreEqual(5, player.getLevel());
		}
		TEST_METHOD(Test)
		{

		}
	};
}

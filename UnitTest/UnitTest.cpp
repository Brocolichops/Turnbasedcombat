#include "pch.h"
#include "CppUnitTest.h"
#include "game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTestClass)
	{
	public:
		
		TEST_METHOD(AttackBoundary)
		{
			int hp = 10;
			Assert::AreEqual(0, attack(20, &hp, false), L"Attack() function failed");
		};
		TEST_METHOD(AttackNoCrit) {
			int hp = 100;
			Assert::AreEqual(90, attack(10, &hp, false), L"Attack() function failed");
		}
		TEST_METHOD(AttackWithCrit) {
			int hp = 100;
			bool crit = true;
			Assert::AreEqual(80, attack(10, &hp, crit), L"Attack() function failed");
		}
		TEST_METHOD(BlockBoundary) {
			int playerHp = 5;
			Assert::AreEqual(0, block(&playerHp, 10, false), L"Block() function failed");
		}
		TEST_METHOD(BlockNoDodge) {
			int playerHp = 100;
			bool dodge = false;
			Assert::AreEqual(90, block(&playerHp, 10, dodge), L"Block() function failed");
		}
		TEST_METHOD(BlockWithDodge) {
			int playerHp = 100;
			bool dodge = true;
			Assert::AreEqual(100, block(&playerHp, 10, dodge), L"Block() function failed");
		}
		TEST_METHOD(UseItem1) {
			int index = 1;
			int hp = 100;
			int ap = 10;
			char *inventory[] = {"Healing Potion", "Attack Boost"};
			Assert::AreEqual(STR_HEALINGPOTION, useItem(inventory, index, &hp, &ap), true);
		}
		TEST_METHOD(UseItem2) {
			int index = 2;
			int hp = 100;
			int ap = 10;
			char* inventory[] = { "Healing Potion", "Attack Boost" };
			Assert::AreEqual(STR_ATTACKBOOST, useItem(inventory, index, &hp, &ap), true);
		}
		TEST_METHOD(UseItemInvalid) {
			int index = -1;
			int hp = 100;
			int ap = 10;
			char* inventory[] = { "Healing Potion", "Attack Boost" };
			Assert::AreEqual(NULL, useItem(inventory, index, &hp, &ap), true);
		}
		TEST_METHOD(checkWinnerPlayer) {
			int playerHp = 100;
			int enemyHp = 0;
			Assert::AreEqual('p', checkWinner(playerHp, enemyHp), L"checkWinner() failed");
		}
		TEST_METHOD(checkWinnerEnemy) {
			int playerHp = 0;
			int enemyHp = 100;
			Assert::AreEqual('e', checkWinner(playerHp, enemyHp), L"checkWinner() failed");
		}
		TEST_METHOD(checkWinnerdraw) {
			int playerHp = 0;
			int enemyHp = 0;
			Assert::AreEqual('d', checkWinner(playerHp, enemyHp), L"checkWinner() failed");

		}
			
	};
}

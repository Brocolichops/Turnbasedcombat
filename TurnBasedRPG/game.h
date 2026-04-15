
#ifdef __cplusplus
extern "C" {
#endif

	int attack(int playerAp, int* enemyHp, bool crit);
	int block(int* playerHp, int enemyAp, bool dodge);
	const char* useItem(char* playerInventory[], int index, int* playerHp, int* playerAp);
	char checkWinner(int playerHp, int enemyHp);
#define STR_HEALINGPOTION "Healing Potion"
#define STR_ATTACKBOOST "Attack Boost"

#ifdef __cplusplus
}
#endif


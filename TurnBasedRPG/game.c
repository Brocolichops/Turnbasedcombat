#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int attack(int playerAp, int* enemyHp, bool crit);
int block(int* playerHp, int enemyAp, bool dodge);
const char* useItem(char* playerInventory[], int index, int* playerHp, int* playerAp);	
char checkWinner(int playerHp, int enemyHp);
void displayIntro();
void showStats(int playerHp, int playerAp);


int main() {

	srand(time(NULL)); //Seeding random with current time

	int pixelHp = 100; //Player HP variable
	int* pixelHpPtr = &pixelHp;
	int pixelAp = 10; //Player Attack Power variable
	int* pixelApPtr = &pixelAp;

	
	int enemyHp = 100; //Enemy HP variable
	int* enemyHpPtr = &enemyHp;
	int enemyAp = 20; //Enemy Attack Power variable

	char pixelInventory[2][30] = { "Healing Potion", "Attack Boost" }; //Player inventory

	bool playing = true; //Variable to control if the game is running

	//Displaying rules and to the user before the game starts
	displayIntro();
	showStats(pixelHp, pixelAp);

	while (playing) {
		int playerChoice;
		int attackBoost = 0;
		
		printf("\n1. Attack\n2. Block\n3. UseItem\n4. Show Stats\nEnter your choice: ");

		scanf_s("%d", &playerChoice);
		
		bool crit;
		int critChance = rand() % 4;
		crit = critChance == 1 ? true : false;

		bool dodge;
		int dodgeChance = rand() % 2;
		dodge = dodgeChance == 1 ? true : false;

		int index;
		switch (playerChoice){
		case 1:
			attack(pixelAp, enemyHpPtr, crit);
			if (crit) {
				printf("YOU DEALT CRITICAL DAMAGE! HIT THE ENEMY FOR 20");
				
			}
			else {
				printf("YOU HIT THE ENEMY FOR %d!", pixelAp);
			}
			printf("\nThe enemy is attacking....");
			Sleep(1000);
			printf("THE ENEMY HIT YOU FOR 10!");
			attack(enemyAp, pixelHpPtr, false);
			break;
		case 2:
			block(pixelHpPtr, enemyAp, dodge);
			
			break;
		case 3:
			
			printf("\n1. Healing Potion (+25 HP)\n2. Attack Boost (2X AP, lasts 1 turn)\nEnter your choice: ");
			scanf_s("%d", &index);
			useItem(pixelInventory, index, pixelHpPtr, pixelApPtr);
			
			if (index == 2) {
				showStats(pixelHp, pixelAp);
				continue;
			};
			break;
		default:
			continue;
		}
		if (pixelAp == 20) pixelAp = 10;
		printf("\nPIXEL");
		showStats(pixelHp, pixelAp);

		printf("\nENEMY");
		showStats(enemyHp, enemyAp);

		char winner = checkWinner(pixelHp, enemyHp);

		if (winner == 'p') {
			printf("\n\tGAME OVER! YOU WIN!");
			playing = false;
		}
		else if (winner == 'e') {
			printf("\n\tGAME OVER! YOU LOSE!");
			playing = false;
		}
		else if (winner == 'd') {
			printf("\n\tGAME OVER! DRAW!");
			playing = false;
		}
		else {
			continue;
		}
		
		
	}

	return 0;
}

void displayIntro() {
	printf("WELCOME TO THE GAME!\n");
	printf("OBJECTIVE: Defeat the enemy.\n");
	printf("Rules: \n");
	printf("\t#1. You must enter inputs in NUMBERS only.\n");
	printf("\t#2. During your turn, you will be presented with three options. Enter the number of the respective option you would like to use.\n");
	printf("\t#3. Enjoy!\n");
}

void showStats(int hp, int ap) {

	printf("\n-----------------STATS-----------------\n");
	printf("\tHP: %d\t\tAP: %d\n", hp, ap);
	printf("---------------------------------------\n");
};

int attack(int playerAp, int* enemyHp, bool crit) {

	if (crit) playerAp *= 2;
	*enemyHp -= playerAp;
	*enemyHp = *enemyHp < 0 ? 0 : *enemyHp;
	return *enemyHp;

};

char checkWinner(int playerHp, int enemyHp) {
	if (enemyHp == 0 && playerHp == 0) {
		return 'd';
	}
	else if (enemyHp <= 0) {
		return 'p';
	}
	else if (playerHp <= 0) {
		return 'e';
	}
	else {
		return 'c';
	}
}
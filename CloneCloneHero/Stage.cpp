#include "Stage.h"
#include "MChord.h"

//Constructor
Stage::Stage() {
	for (int i = 0; i < LONGUEUR_STG; i++) {
		for (int j = 0; j < LARGEUR_STG; j++) {
			theStage[i][j] = ' ';
		}
	}
	points = 0;
	combo = 0;
}
//Destructor
Stage::~Stage() {

}

void Stage::nextNote(Chart* chart) {
	
	push();
	if (!chart->isEmpty()) {
		MChord c = chart->unqueueChord();

		char note;
		switch (c.getType())
		{
		case 0:
			note = '0';
			break;
		case 1:
			note = 'O';
			break;
		case 2:
			note = '@';
			break;
		}
		cout << c.getType() << endl;
		switch (c.getNotes())
		{
		case 0:
			for (int i = 0; i < LARGEUR_STG; i++) {
				theStage[0][i] = '-';
			}
			break;
		case 1:
			theStage[0][0] = note;
			theStage[0][1] = ' ';
			theStage[0][2] = ' ';
			theStage[0][3] = ' ';
			theStage[0][4] = ' ';
			break;
		case 2:
			theStage[0][0] = ' ';
			theStage[0][1] = note;
			theStage[0][2] = ' ';
			theStage[0][3] = ' ';
			theStage[0][4] = ' ';
			break;
		case 3:
			theStage[0][0] = note;
			theStage[0][1] = note;
			theStage[0][2] = ' ';
			theStage[0][3] = ' ';
			theStage[0][4] = ' ';
			break;
		case 4:
			theStage[0][0] = ' ';
			theStage[0][1] = ' ';
			theStage[0][2] = note;
			theStage[0][3] = ' ';
			theStage[0][4] = ' ';
			break;
		case 5:
			theStage[0][0] = note;
			theStage[0][1] = ' ';
			theStage[0][2] = note;
			theStage[0][3] = ' ';
			theStage[0][4] = ' ';
			break;
		case 6:
			theStage[0][0] = ' ';
			theStage[0][1] = note;
			theStage[0][2] = note;
			theStage[0][3] = ' ';
			theStage[0][4] = ' ';
			break;
		case 7:
			theStage[0][0] = note;
			theStage[0][1] = note;
			theStage[0][2] = note;
			theStage[0][3] = ' ';
			theStage[0][4] = ' ';
			break;
		case 8:
			theStage[0][0] = ' ';
			theStage[0][1] = ' ';
			theStage[0][2] = ' ';
			theStage[0][3] = note;
			theStage[0][4] = ' ';
			break;
		case 9:
			theStage[0][0] = note;
			theStage[0][1] = ' ';
			theStage[0][2] = ' ';
			theStage[0][3] = note;
			theStage[0][4] = ' ';
			break;
		case 10:
			theStage[0][0] = ' ';
			theStage[0][1] = note;
			theStage[0][2] = ' ';
			theStage[0][3] = note;
			theStage[0][4] = ' ';
			break;
		case 11:
			theStage[0][0] = note;
			theStage[0][1] = note;
			theStage[0][2] = ' ';
			theStage[0][3] = note;
			theStage[0][4] = ' ';
			break;
		case 12:
			theStage[0][0] = ' ';
			theStage[0][1] = ' ';
			theStage[0][2] = note;
			theStage[0][3] = note;
			theStage[0][4] = ' ';
			break;
		case 13:
			theStage[0][0] = note;
			theStage[0][1] = ' ';
			theStage[0][2] = note;
			theStage[0][3] = note;
			theStage[0][4] = ' ';
			break;
		case 14:
			theStage[0][0] = ' ';
			theStage[0][1] = note;
			theStage[0][2] = note;
			theStage[0][3] = note;
			theStage[0][4] = ' ';
			break;
		case 15:
			theStage[0][0] = note;
			theStage[0][1] = note;
			theStage[0][2] = note;
			theStage[0][3] = note;
			theStage[0][4] = ' ';
			break;
		case 16:
			theStage[0][0] = ' ';
			theStage[0][1] = ' ';
			theStage[0][2] = ' ';
			theStage[0][3] = ' ';
			theStage[0][4] = note;
			break;
		case 17:
			theStage[0][0] = note;
			theStage[0][1] = ' ';
			theStage[0][2] = ' ';
			theStage[0][3] = ' ';
			theStage[0][4] = note;
			break;
		case 18:
			theStage[0][0] = ' ';
			theStage[0][1] = note;
			theStage[0][2] = ' ';
			theStage[0][3] = ' ';
			theStage[0][4] = note;
			break;
		case 19:
			theStage[0][0] = note;
			theStage[0][1] = note;
			theStage[0][2] = ' ';
			theStage[0][3] = ' ';
			theStage[0][4] = note;
			break;
		case 20:
			theStage[0][0] = ' ';
			theStage[0][1] = ' ';
			theStage[0][2] = note;
			theStage[0][3] = ' ';
			theStage[0][4] = note;
			break;
		case 21:
			theStage[0][0] = note;
			theStage[0][1] = ' ';
			theStage[0][2] = note;
			theStage[0][3] = ' ';
			theStage[0][4] = note;
			break;
		case 22:
			theStage[0][0] = ' ';
			theStage[0][1] = note;
			theStage[0][2] = note;
			theStage[0][3] = ' ';
			theStage[0][4] = note;
			break;
		case 23:
			theStage[0][0] = note;
			theStage[0][1] = note;
			theStage[0][2] = note;
			theStage[0][3] = ' ';
			theStage[0][4] = note;
			break;
		case 24:
			theStage[0][0] = ' ';
			theStage[0][1] = ' ';
			theStage[0][2] = ' ';
			theStage[0][3] = note;
			theStage[0][4] = note;
			break;
		case 25:
			theStage[0][0] = note;
			theStage[0][1] = ' ';
			theStage[0][2] = ' ';
			theStage[0][3] = note;
			theStage[0][4] = note;
			break;
		case 26:
			theStage[0][0] = ' ';
			theStage[0][1] = note;
			theStage[0][2] = ' ';
			theStage[0][3] = note;
			theStage[0][4] = note;
			break;
		case 27:
			theStage[0][0] = note;
			theStage[0][1] = note;
			theStage[0][2] = ' ';
			theStage[0][3] = note;
			theStage[0][4] = note;
			break;
		case 28:
			theStage[0][0] = ' ';
			theStage[0][1] = ' ';
			theStage[0][2] = note;
			theStage[0][3] = note;
			theStage[0][4] = note;
			break;
		case 29:
			theStage[0][0] = note;
			theStage[0][1] = ' ';
			theStage[0][2] = note;
			theStage[0][3] = note;
			theStage[0][4] = note;
			break;
		case 30:
			theStage[0][0] = ' ';
			theStage[0][1] = note;
			theStage[0][2] = note;
			theStage[0][3] = note;
			theStage[0][4] = note;
			break;
		case 31:
			theStage[0][0] = note;
			theStage[0][1] = note;
			theStage[0][2] = note;
			theStage[0][3] = note;
			theStage[0][4] = note;
			break;

		default:
			break;
		}
		cout << c.getNotes() << endl;
	}
	else {
	theStage[0][0] = ' ';
	theStage[0][1] = ' ';
	theStage[0][2] = ' ';
	theStage[0][3] = ' ';
	theStage[0][4] = ' ';
	}
}

void Stage::push() {
	for (int i = LONGUEUR_STG - 1; i > 0; i--) {
		for (int j = 0; j < LARGEUR_STG; j++) {
			theStage[i][j] = theStage[i - 1][j];
		}
	}
}

void Stage::afficher() {
	/*
		defeault = 7
		GRN = 2
		RED = 4
		YLW = 14
		BLE = 1
		ORG = 6

		GRNB = 47
		REDB = 79
		YLWB = 224
		BLEB = 31
		ORGB = 111

		WHTB = 240
	*/
	system("CLS");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < LONGUEUR_STG - 1; i++) {
		SetConsoleTextAttribute(h, DEFAULT_COLOR);
		cout << '|';
		
		
		SetConsoleTextAttribute(h, GRN);
		cout << theStage[i][0] << ' ';
		//cout << "allllloooooooo";

		SetConsoleTextAttribute(h, RED);
		cout << theStage[i][1] << ' ';

		SetConsoleTextAttribute(h, YLW);
		cout << theStage[i][2] << ' ';

		SetConsoleTextAttribute(h, BLE);
		cout << theStage[i][3] << ' ';

		SetConsoleTextAttribute(h, ORG);
		cout << theStage[i][4];

		SetConsoleTextAttribute(h, DEFAULT_COLOR);
		cout << '|' << endl;
	}
}

//Points counter fonctions
int Stage::getPoints() {
	return(points);
}

void Stage::addPoints(int x) {
	points += x;
}

//Combo counter fonctions
int Stage::getCombo() {
	return(combo);
}

void Stage::addCombo(int x) {
	combo += x;
}

void Stage::resetCombo() {
	combo = 0;
}
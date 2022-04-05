#include "Stage.h"

using namespace std;

Stage::Stage() {
	for (int i = 0; i < LONGUEUR_STG; i++) {
		for (int j = 0; j < LARGEUR_STG; j++) {
			theStage[i][j] = ' ';
		}
	}
	clock_t start = clock();

	points = 0;
	combo = 0;
	emptyLines = 0;
	int buffer[10] = { 0,0,0,0,0,0,0,0,0,0 };
	inputs = buffer;
}

Stage::~Stage() {

}

void Stage::play(Chart* chart)
{
	float length = chart->getLength();

	while ((clock() - start) * 1000 / CLOCKS_PER_SEC <= length)
	{
		inputs = communication.fetch();
		display();
		update(chart);
	}
}

void Stage::update(Chart* chart)
{
	push();

	if (!chart->isEmpty() && (clock() - start) * 1000 / CLOCKS_PER_SEC >= chart->nextChord().getDelay())
	{
		MChord c = chart->unqueueChord();
		char note;

		switch (c.getType())
		{
		case 0:
			note = '0';
			break;
		case 1:
			note = '@';
			break;
		case 2:
			note = 'O';
			break;
		}
		switch (c.getNotes())
		{
		case 0:
			for (int i = 0; i < LARGEUR_STG; i++)
			{
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
	if (theStage[LONGUEUR_STG - 1][0] != ' ' || theStage[LONGUEUR_STG - 1][1] != ' ' || theStage[LONGUEUR_STG - 1][2] != ' ' || theStage[LONGUEUR_STG - 1][3] != ' ' || theStage[LONGUEUR_STG - 1][4] != ' ') {
		resetCombo();
	}
	for (int i = LONGUEUR_STG - 1; i > 0; i--) {
		for (int j = 0; j < LARGEUR_STG; j++) {
			theStage[i][j] = theStage[i - 1][j];
		}
	}
}

void clrscr()
{
	COORD cursorPosition;	cursorPosition.X = 0;	cursorPosition.Y = 0;	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void Stage::display() {
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
	clrscr();
	keyDetection();
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < LONGUEUR_STG - 1; i++) {
		SetConsoleTextAttribute(h, DEFAULT_COLOR);
		cout << '|';
		
		
		SetConsoleTextAttribute(h, GRN);
		cout << theStage[i][0] << ' ';

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


	SetConsoleTextAttribute(h, DEFAULT_COLOR);
	cout << '|';

	if (inputs[0] != 0) {
		SetConsoleTextAttribute(h, GRNB);
	}
	else {
		SetConsoleTextAttribute(h, WHTB);
	}
	cout << theStage[LONGUEUR_STG - 1][0];

	SetConsoleTextAttribute(h, DEFAULT_COLOR);
	cout << 'X';

	if (inputs[1] != 0) {
		SetConsoleTextAttribute(h, REDB);
	}
	else {
		SetConsoleTextAttribute(h, WHTB);
	}
	cout << theStage[LONGUEUR_STG - 1][1];

	SetConsoleTextAttribute(h, DEFAULT_COLOR);
	cout << 'X';

	if (inputs[2] != 0) {
		SetConsoleTextAttribute(h, YLWB);
	}
	else {
		SetConsoleTextAttribute(h, WHTB);
	}
	cout << theStage[LONGUEUR_STG - 1][2];

	SetConsoleTextAttribute(h, DEFAULT_COLOR);
	cout << 'X';

	if (inputs[3] != 0) {
		SetConsoleTextAttribute(h, BLEB);
	}
	else {
		SetConsoleTextAttribute(h, WHTB);
	}
	cout << theStage[LONGUEUR_STG - 1][3];

	SetConsoleTextAttribute(h, DEFAULT_COLOR);
	cout << 'X';

	if (inputs[4] != 0) {
		SetConsoleTextAttribute(h, ORGB);
	}
	else {
		SetConsoleTextAttribute(h, WHTB);
	}
	cout << theStage[LONGUEUR_STG - 1][4];

	SetConsoleTextAttribute(h, DEFAULT_COLOR);
	cout << '|' << endl;

	cout << "\nCombo: " << combo << "   Points: " << points << endl;
}

char Stage::getGRN() {
	return(theStage[LONGUEUR_STG - 1][0]);
}

char Stage::getRED() {
	return(theStage[LONGUEUR_STG - 1][1]);
}

char Stage::getYLW() {
	return(theStage[LONGUEUR_STG - 1][2]);
}

char Stage::getBLE() {
	return(theStage[LONGUEUR_STG - 1][3]);
}

char Stage::getORG() {
	return(theStage[LONGUEUR_STG - 1][4]);
}

void Stage::resetKey(int i) {
	if (i >= 0 && i < 5) {
		theStage[LONGUEUR_STG - 1][i] = ' ';
	}
}

void Stage::keyDetection() {
	//Strum only
	if (getGRN() == '-' && getRED() == '-' && getYLW() == '-' && getBLE() == '-' && getORG() == '-' && (inputs[6] > 300 || inputs[6] < -300)) {
		resetKey(0);
		resetKey(1);
		resetKey(2);
		resetKey(3);
		resetKey(4);

		addCombo(1);
		addPoints(1);
	}

	//0 Keys
	if (getGRN() == '0' && inputs[0] != 0 && (inputs[6] > 300 || inputs[6] < -300)) {
		resetKey(0);

		addCombo(1);
		addPoints(1);
	}
	if (getRED() == '0' && inputs[1] != 0 && (inputs[6] > 300 || inputs[6] < -300)) {
		resetKey(1);

		addCombo(1);
		addPoints(1);
	}
	if (getYLW() == '0' && inputs[2] != 0 && (inputs[6] > 300 || inputs[6] < -300)) {
		resetKey(2);

		addCombo(1);
		addPoints(1);
	}
	if (getBLE() == '0' && inputs[3] != 0 && (inputs[6] > 300 || inputs[6] < -300)) {
		resetKey(3);

		addCombo(1);
		addPoints(1);
	}
	if (getORG() == '0' && inputs[4] != 0 && (inputs[6] > 300 || inputs[6] < -300)) {
		resetKey(4);

		addCombo(1);
		addPoints(1);
	}

	//O Keys
	if (getGRN() == '@' && inputs[0] == 1) {
		resetKey(0);

		addCombo(1);
		addPoints(1);
	}
	if (getRED() == '@' && inputs[1] == 1) {
		resetKey(1);

		addCombo(1);
		addPoints(1);
	}
	if (getYLW() == '@' && inputs[2] == 1) {
		resetKey(2);

		addCombo(1);
		addPoints(1);
	}
	if (getBLE() == '@' && inputs[3] == 1) {
		resetKey(3);

		addCombo(1);
		addPoints(1);
	}
	if (getORG() == '@' && inputs[4] == 1) {
		resetKey(4);

		addCombo(1);
		addPoints(1);
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
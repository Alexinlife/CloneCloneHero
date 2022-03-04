#include "Stage.h"

using namespace std;

Stage::Stage() {
	for (int i = 0; i < LONGUEUR_STG; i++) {
		for (int j = 0; j < LARGEUR_STG; j++) {
			theStage[i][j] = ' ';
		}
	}
	points = 0;
	combo = 0;
	emptyLines = 0;
}

Stage::~Stage() {

}

void Stage::play(Chart* chart)
{
	clock_t start = clock();
	float spb = 60 / chart->getTempo();
	float length = chart->getLength();

	while ((clock() - start) / CLOCKS_PER_SEC <= length /* + 20 */)
	{
		if (fmod((float)(clock() - (float)start) / CLOCKS_PER_SEC, spb / 4) == 0)
		{
			inputs = communication.fetch();
			cycle();
			nextChord(chart);
		}
	}
}

void Stage::nextChord(Chart* chart)
{
	push();

	if (emptyLines != 0)
	{
		emptyLines -= 1 / (float)chart->getBeats();
	}

	if (!chart->isEmpty() && emptyLines == 0)
	{
		MChord c = chart->unqueueChord();
		char note;
		if (!chart->isEmpty())
		{
			emptyLines = chart->nextChord().getDelay();
		}

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

void Stage::cycle() {
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

	if (!inputs[0]) {
		SetConsoleTextAttribute(h, GRNB);
	}
	else {
		SetConsoleTextAttribute(h, WHTB);
	}
	cout << theStage[LONGUEUR_STG - 1][0];

	SetConsoleTextAttribute(h, DEFAULT_COLOR);
	cout << 'X';

	if (!inputs[1]) {
		SetConsoleTextAttribute(h, REDB);
	}
	else {
		SetConsoleTextAttribute(h, WHTB);
	}
	cout << theStage[LONGUEUR_STG - 1][1];

	SetConsoleTextAttribute(h, DEFAULT_COLOR);
	cout << 'X';

	if (!inputs[2]) {
		SetConsoleTextAttribute(h, YLWB);
	}
	else {
		SetConsoleTextAttribute(h, WHTB);
	}
	cout << theStage[LONGUEUR_STG - 1][2];

	SetConsoleTextAttribute(h, DEFAULT_COLOR);
	cout << 'X';

	if (!inputs[3]) {
		SetConsoleTextAttribute(h, BLEB);
	}
	else {
		SetConsoleTextAttribute(h, WHTB);
	}
	cout << theStage[LONGUEUR_STG - 1][3];

	SetConsoleTextAttribute(h, DEFAULT_COLOR);
	cout << 'X';

	if (!inputs[4]) {
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
	if (getGRN() == '0' && !inputs[0] && (inputs[6] > 300 || inputs[6] < -300)) {
		resetKey(0);

		addCombo(1);
		addPoints(1);
	}
	if (getRED() == '0' && !inputs[1] && (inputs[6] > 300 || inputs[6] < -300)) {
		resetKey(1);

		addCombo(1);
		addPoints(1);
	}
	if (getYLW() == '0' && !inputs[2] && (inputs[6] > 300 || inputs[6] < -300)) {
		resetKey(2);

		addCombo(1);
		addPoints(1);
	}
	if (getBLE() == '0' && !inputs[3] && (inputs[6] > 300 || inputs[6] < -300)) {
		resetKey(3);

		addCombo(1);
		addPoints(1);
	}
	if (getORG() == '0' && !inputs[4] && (inputs[6] > 300 || inputs[6] < -300)) {
		resetKey(4);

		addCombo(1);
		addPoints(1);
	}

	//O Keys
	if (getGRN() == 'O' && !inputs[0]) {
		resetKey(0);

		addCombo(1);
		addPoints(1);
	}
	if (getRED() == 'O' && !inputs[1]) {
		resetKey(1);

		addCombo(1);
		addPoints(1);
	}
	if (getYLW() == 'O' && !inputs[2]) {
		resetKey(2);

		addCombo(1);
		addPoints(1);
	}
	if (getBLE() == 'O' && !inputs[3]) {
		resetKey(3);

		addCombo(1);
		addPoints(1);
	}
	if (getORG() == 'O' && !inputs[4]) {
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
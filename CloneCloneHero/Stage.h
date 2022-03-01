#include "Chart.h"
#include "MChord.h"
#include <iostream>
#include <Windows.h>

using namespace std;

const int DEFAULT_COLOR = 7;
const int GRN = 2;
const int RED = 4;
const int YLW = 14;
const int BLE = 1;
const int ORG = 6;

const int GRNB = 47;
const int REDB = 79;
const int YLWB = 224;
const int BLEB = 31;
const int ORGB = 111;

const int WHTB = 240;

const int LONGUEUR_STG = 30;
const int LARGEUR_STG = 5;


#ifndef STAGE_H
#define STAGE_H

class Stage
{
public:
	//Constructor
	Stage();
	//Destructor
	~Stage();

	void nextNote(Chart* c);

	void push();

	void afficher();

	//Points counter fonctions
	int getPoints();
	void addPoints(int x);

	//Combo counter fonctions
	int getCombo();
	void addCombo(int x);
	void resetCombo();


private:
	char theStage[LONGUEUR_STG][LARGEUR_STG];
	int points;
	int combo;
};

#endif

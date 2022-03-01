#include "Chart.h"
#include "Chord.h"
#include <iostream>
#include <Windows.h>

using namespace std;

const int colors[] = { FOREGROUND_GREEN | FOREGROUND_INTENSITY,//green
					FOREGROUND_RED | FOREGROUND_INTENSITY,//red
					FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY, //yellow
					FOREGROUND_BLUE | FOREGROUND_INTENSITY, //blue
					FOREGROUND_RED | FOREGROUND_BLUE };//purple


#define DFT "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YLW "\e[0;33m"
#define BLU "\e[0;34m"
#define ORG "\e[0;35m"
#define REDB "\e[0;41m"
#define GRNB "\e[0;42m"
#define YLWB "\e[0;43m"
#define BLUB "\e[0;44m"
#define ORGB "\e[0;45m"
#define WTHB "\e[0;7m"

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

	void nextNote(Chord c);

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

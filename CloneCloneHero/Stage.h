#include "Chart.h"

using namespace std;

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

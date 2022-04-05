#include "Chart.h"
#include "MChord.h"
#include <iostream>
#include <math.h>
#include <chrono>
#include <Windows.h>
#include "Communication.h"

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


#define T_GRN 0x31
#define T_RED 0x32
#define T_YLW 0x33
#define T_BLE 0x34
#define T_ORG 0x35
#define T_STRUM 0x08

#ifndef STAGE_H
#define STAGE_H

class Stage
{
public:
	//Constructor
	Stage();
	//Destructor
	~Stage();

	void play(Chart* chart);

	void update(Chart* chart);

	void push();

	void display();

	char getGRN();
	char getRED();
	char getYLW();
	char getBLE();
	char getORG();

	void resetKey(int i);

	void keyDetection();

	//Points counter fonctions
	int getPoints();
	void addPoints(int x);

	//Combo counter fonctions
	int getCombo();
	void addCombo(int x);
	void resetCombo();


private:
	Communication communication;
	clock_t start;
	char theStage[LONGUEUR_STG][LARGEUR_STG];
	int* inputs;
	int points;
	int combo;
	float emptyLines;
};

#endif

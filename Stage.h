#include "Chart.h"
#include "Communication.h"
#include "Editor.h"
#include "MChord.h"
#include <iostream>
#include <math.h>
#include <chrono>
#include <QObject>
#include <QThread>

using namespace std;


#define T_GRN 0x31
#define T_RED 0x32
#define T_YLW 0x33
#define T_BLE 0x34
#define T_ORG 0x35
#define T_STRUM 0x08

#ifndef STAGE_H
#define STAGE_H

class Stage: public QObject
{
    Q_OBJECT

public slots:
    void getValues();

signals:
	void valuesChanged(int *values);

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
    Editor editor;
    Chart* chart;
	clock_t start;
    // list<list<QMNote*>> theStage;
	int* inputs;
	int points;
	int combo;
	int bestCombo;
	int sp;
	bool spEnabled;
	float emptyLines;
	clock_t lastBeat;
};

#endif

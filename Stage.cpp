#include "Stage.h"

using namespace std;

Stage::Stage() {
	clock_t start = clock();
	points = 0;
	combo = 0;
	bestCombo = 0;
	sp = 0;
	spEnabled = false;
	emptyLines = 0;
	int buffer[10] = { 0,0,0,0,0,0,0,0,0,0 };
    inputs = buffer;

    chart = new Chart;
    // *chart = editor.test();
}

Stage::~Stage()
{
}

void Stage::getValues()
{
    int values[3] = { 500, 500, 500 };
    
    emit valuesChanged(values);
}

void Stage::play(Chart* chart)
{
	float length = chart->getLength();
	int spCountdown = 0;
	int timeInSec = 0;

    if ((clock() - start) * 1000 / CLOCKS_PER_SEC <= length)
	{
        inputs = communication.fetch(sp);
		update(chart);
		timeInSec = (clock() - start) / CLOCKS_PER_SEC;
		if (sp == 10)
		{
			spEnabled = true;
		}
		else if (sp == 0)
		{
			spEnabled = false;
		}
		if (timeInSec % 1 == 0 && spEnabled && timeInSec != spCountdown)
		{
			spCountdown = timeInSec;
			sp--;
		}
	}
}

void Stage::update(Chart* chart)
{
    push();

    if (!chart->isEmpty() && (clock() - start) * 1000 / CLOCKS_PER_SEC >= chart->nextChord().getDelay())
    {

        // MChord c = chart->unqueueChord();

        /* switch (c.getNotes())
        {
        case 0:
            theStage.push_back({new QMNote(NULL, 0, 3)});
            break;
        case 1:
            theStage.push_back({new QMNote(NULL, 0, c.getType())});
            break;
        case 2:
            theStage.push_back({new QMNote(NULL, 1, c.getType())});
            break;
        case 3:
            theStage.push_back({new QMNote(NULL, 0, c.getType()), new QMNote(NULL, 1, c.getType())});
            break;
        case 4:
            theStage.push_back({new QMNote(NULL, 2, c.getType())});
            break;
        case 5:
            theStage.push_back({new QMNote(NULL, 0, c.getType()), new QMNote(NULL, 2, c.getType())});
            break;
        case 6:
            theStage.push_back({new QMNote(NULL, 1, c.getType()), new QMNote(NULL, 2, c.getType())});
            break;
        case 7:
            theStage.push_back({new QMNote(NULL, 0, c.getType()), new QMNote(NULL, 1, c.getType()), new QMNote(NULL, 2, c.getType())});
            break;
        case 8:
            theStage.push_back({new QMNote(NULL, 3, c.getType())});
            break;
        case 9:
            theStage.push_back({new QMNote(NULL, 0, c.getType()), new QMNote(NULL, 3, c.getType())});
            break;
        case 10:
            theStage.push_back({new QMNote(NULL, 1, c.getType()), new QMNote(NULL, 3, c.getType())});
            break;
        case 11:
            theStage.push_back({new QMNote(NULL, 0, c.getType()), new QMNote(NULL, 1, c.getType()), new QMNote(NULL, 3, c.getType())});
            break;
        case 12:
            theStage.push_back({new QMNote(NULL, 2, c.getType()), new QMNote(NULL, 3, c.getType())});
            break;
        case 13:
            theStage.push_back({new QMNote(NULL, 0, c.getType()), new QMNote(NULL, 2, c.getType()), new QMNote(NULL, 3, c.getType())});
            break;
        case 14:
            theStage.push_back({new QMNote(NULL, 1, c.getType()), new QMNote(NULL, 2, c.getType()), new QMNote(NULL, 3, c.getType())});
            break;
        case 15:
            theStage.push_back({new QMNote(NULL, 0, c.getType()), new QMNote(NULL, 1, c.getType()), new QMNote(NULL, 2, c.getType()), new QMNote(NULL, 3, c.getType())});
            break;
        case 16:
            theStage.push_back({new QMNote(NULL, 4, c.getType())});
            break;
        case 17:
            theStage.push_back({new QMNote(NULL, 0, c.getType()), new QMNote(NULL, 4, c.getType())});
            break;
        case 18:
            theStage.push_back({new QMNote(NULL, 1, c.getType()), new QMNote(NULL, 4, c.getType())});
            break;
        case 19:
            theStage.push_back({new QMNote(NULL, 0, c.getType()), new QMNote(NULL, 1, c.getType()), new QMNote(NULL, 4, c.getType())});
            break;
        case 20:
            theStage.push_back({new QMNote(NULL, 2, c.getType()), new QMNote(NULL, 4, c.getType())});
            break;
        case 21:
            theStage.push_back({new QMNote(NULL, 0, c.getType()), new QMNote(NULL, 2, c.getType()), new QMNote(NULL, 4, c.getType())});
            break;
        case 22:
            theStage.push_back({new QMNote(NULL, 1, c.getType()), new QMNote(NULL, 2, c.getType()), new QMNote(NULL, 4, c.getType())});
            break;
        case 23:
            theStage.push_back({new QMNote(NULL, 0, c.getType()), new QMNote(NULL, 1, c.getType()), new QMNote(NULL, 2, c.getType()), new QMNote(NULL, 4, c.getType())});
            break;
        case 24:
            theStage.push_back({new QMNote(NULL, 3, c.getType()), new QMNote(NULL, 4, c.getType())});
            break;
        case 25:
            theStage.push_back({new QMNote(NULL, 0, c.getType()), new QMNote(NULL, 3, c.getType()), new QMNote(NULL, 4, c.getType())});
            break;
        case 26:
            theStage.push_back({new QMNote(NULL, 1, c.getType()), new QMNote(NULL, 3, c.getType()), new QMNote(NULL, 4, c.getType())});
            break;
        case 27:
            theStage.push_back({new QMNote(NULL, 0, c.getType()), new QMNote(NULL, 1, c.getType()), new QMNote(NULL, 3, c.getType()), new QMNote(NULL, 4, c.getType())});
            break;
        case 28:
            theStage.push_back({new QMNote(NULL, 2, c.getType()), new QMNote(NULL, 3, c.getType()), new QMNote(NULL, 4, c.getType())});
            break;
        case 29:
            theStage.push_back({new QMNote(NULL, 0, c.getType()), new QMNote(NULL, 2, c.getType()), new QMNote(NULL, 3, c.getType()), new QMNote(NULL, 4, c.getType())});
            break;
        case 30:
            theStage.push_back({new QMNote(NULL, 1, c.getType()), new QMNote(NULL, 2, c.getType()), new QMNote(NULL, 3, c.getType()), new QMNote(NULL, 4, c.getType())});
            break;
        case 31:
            theStage.push_back({new QMNote(NULL, 0, c.getType()), new QMNote(NULL, 1, c.getType()), new QMNote(NULL, 2, c.getType()), new QMNote(NULL, 3, c.getType()), new QMNote(NULL, 4, c.getType())});
            break;
        } */
    }
}

void Stage::push() {

    /* list<QMNote*> copy;
    list<QMNote*> transfer;
    QMNote *cursor;

    for (int i = 0; i > theStage.size(); i++)
    {
        copy = theStage.front();

        while (!copy.empty())
        {
            cursor = new QMNote(NULL, copy.front()->getColor(), copy.front()->getType());
            cursor->setAge(cursor->getAge() + 1);
            copy.pop_front();
            transfer.push_back(cursor);
            delete cursor;
        }
        theStage.pop_front();
        theStage.push_back(transfer);
        transfer.clear();
    } */
}

void Stage::display() {

    // keyDetection();


}

/* void Stage::resetKey(int i) {
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
} */

//Points counter fonctions
int Stage::getPoints() {
	return(points);
}

void Stage::addPoints(int x) {
	points += x;
	if (points % 5 == 0)
	{
		sp++;
	}
	if (spEnabled)
	{
		points += x;
	}
}

//Combo counter fonctions
int Stage::getCombo() {
	return(combo);
}

void Stage::addCombo(int x) {
	combo += x;
}

void Stage::resetCombo() {
	if (bestCombo < combo)
	{
		bestCombo = combo;
	}
	combo = 0;
}

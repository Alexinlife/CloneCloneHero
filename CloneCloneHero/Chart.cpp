#include "Chart.h"

Chart::Chart()
{

}

Chart::Chart(int notes, int type, int delay, float sustain)
{

}

Chart::~Chart()
{

}

void Chart::addChord(int notes, int type, float delay, float sustain)
{
	Chord newChord(notes, type, delay, sustain);
	chords.push(newChord);
}

void Chart::copyBeat(int index)
{

}

void Chart::copyMeasure(int index)
{

}

void Chart::copyPart(float begin, float end)
{

}

string Chart::toString()
{

}

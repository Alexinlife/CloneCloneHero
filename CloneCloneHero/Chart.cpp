#include "Chart.h"

Chart::Chart()
{
	beats = 4;
	measures = 4;
	tempo = 120;
}

Chart::Chart(const Chart& copyChart)
{
	beats = copyChart.beats;
	measures = copyChart.measures;
	tempo = copyChart.tempo;
	chords = copyChart.chords;
}

Chart::~Chart()
{

}

Chart& Chart::operator=(Chart c)
{
	beats = c.beats;
	measures = c.measures;
	tempo = c.tempo;
	chords = c.chords;

	return *this;
}

void Chart::pushChord(int notes, int type, float delay, float sustain)
{
	MChord newChord(notes, type, delay, sustain);
	chords.push(newChord);
}

MChord Chart::nextChord()
{
	return chords.front();
}

MChord Chart::unqueueChord()
{
	MChord unqueued = nextChord();
	chords.pop();
	return unqueued;
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
	return("");
}

bool Chart::isEmpty()
{
	return chords.empty();
}

void Chart::setSignature(int b, int m)
{
	beats = b;
	measures = m;
}

void Chart::setTempo(float t)
{
	tempo = t;
}

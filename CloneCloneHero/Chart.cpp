#include "Chart.h"

Chart::Chart()
{
	beats = 4;
	measures = 4;
	tempo = 120;
}

Chart::Chart(int notes, int type, int delay, float sustain)
{

}

Chart::~Chart()
{

}

void Chart::pushChord(int notes, int type, float delay, float sustain)
{
	Chord newChord(notes, type, delay, sustain);
	chords.push(newChord);
}

Chord Chart::nextChord()
{
	return chords.front();
}

Chord Chart::unqueueChord()
{
	Chord unqueued = nextChord();
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

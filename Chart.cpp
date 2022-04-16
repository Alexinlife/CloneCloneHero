#include "Chart.h"

Chart::Chart()
{
	length = 0;
}

Chart::Chart(const Chart& copyChart)
{
	length = copyChart.length;
	chords = copyChart.chords;
}

Chart::~Chart()
{

}

Chart& Chart::operator=(Chart c)
{
	length = c.length;
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

MChord& Chart::lastChord()
{
	return chords.back();
}

MChord Chart::unqueueChord()
{
	MChord unqueued = nextChord();
	chords.pop();
	return unqueued;
}

bool Chart::isEmpty()
{
	return chords.empty();
}

float Chart::getLength()
{
	return length;
}

void Chart::setLength(int ms)
{
	if (ms > 0)
	{
		length = ms;
	}
}

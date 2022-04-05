#include "MChord.h";

MChord::MChord()
{
	notes = 0; // open note
	type = 3;  // open note
	delay = 0; // no delay
	sustain = 0;
}

MChord::MChord(int n, int t, float d, float s)
{
	notes = 0; // open note
	type = 3;  // open note
	delay = 0; // no delay

	if (n >= 0 && n <= 31)
	{
		notes = n;
	}
	if (d >= 0)
	{
		delay = d;
	}
	if (t >= 0 && t <= 2)
	{
		type = t;
	}
	sustain = s;
}



MChord::~MChord()
{

}

const int MChord::getNotes()
{
	return notes;
}

void MChord::setNotes(int n)
{
	if (n >= 0 && n <= 31)
	{
		notes = n;
	}
}

const int MChord::getType()
{
	return type;
}

const float MChord::getDelay()
{
	return delay;
}

const float MChord::getSustain()
{
	return sustain;
}

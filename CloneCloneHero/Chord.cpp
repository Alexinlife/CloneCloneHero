#include "Chord.h";

Chord::Chord()
{
	notes = 0; // open note
	type = 3;  // open note
	delay = 0; // no delay
	sustain = 0;
}

Chord::Chord(int n, int t, float d, float s)
{
	notes = 0; // open note
	type = 3;  // open note
	delay = 0; // no delay

	if (n >= 0 && n <= 31) {
		notes = n;
	}
	if (d >= 0) {
		delay = d;
	}
	if (t >= 0 && t <= 2) {
		type = t;
	}
	sustain = s;
}

Chord::~Chord()
{

}

const string Chord::getNotes()
{
	string note;
	switch (type)
	{
	case 0:
		note = '0';
		break;
	case 1:
		note = 'O';
		break;
	case 2:
		note = '@';
		break;
	}
	switch (notes)
	{
	case 0:
		return "| - - - - - |";
		break;
	case 1:
		return "| " + note + "         |";
		break;
	case 2:
		return "|   " + note + "       |";
		break;
	case 3:
		return "| " + note + " " + note + "       |";
		break;
	case 4:
		return "|     " + note + "     |";
		break;
	case 5:
		return "| " + note + "   " + note + "     |";
		break;
	case 6:
		return "|   " + note + " " + note + "     |";
		break;
	case 7:
		return "| " + note + " " + note + " " + note + "     |";
		break;
	case 8:
		return "|       " + note + "   |";
		break;
	case 9:
		return "| " + note + "     " + note + "   |";
		break;
	case 10:
		return "|   " + note + "   " + note + "   |";
		break;
	case 11:
		return "| " + note + " " + note + "   " + note + "   |";
		break;
	case 12:
		return "|     " + note + " " + note + "   |";
		break;
	case 13:
		return "| " + note + "   " + note + " " + note + "   |";
		break;
	case 14:
		return "|   " + note + " " + note + " " + note + "   |";
		break;
	case 15:
		return "| " + note + " " + note + " " + note + " " + note + "   |";
		break;
	case 16:
		return "|         " + note + " |";
		break;
	case 17:
		return "| " + note + "       " + note + " |";
		break;
	case 18:
		return "|   " + note + "     " + note + " |";
		break;
	case 19:
		return "| " + note + " " + note + "     " + note + " |";
		break;
	case 20:
		return "|     " + note + "   " + note + " |";
		break;
	case 21:
		return "| " + note + "   " + note + "   " + note + " |";
		break;
	case 22:
		return "|   " + note + " " + note + "   " + note + " |";
		break;
	case 23:
		return "| " + note + " " + note + " " + note + "   " + note + " |";
		break;
	case 24:
		return "|       " + note + " " + note + " |";
		break;
	case 25:
		return "| " + note + "     " + note + " " + note + " |";
		break;
	case 26:
		return "|   " + note + "   " + note + " " + note + " |";
		break;
	case 27:
		return "| " + note + " " + note + "   " + note + " " + note + " |";
		break;
	case 28:
		return "|     " + note + " " + note + " " + note + " |";
		break;
	case 29:
		return "| " + note + "   " + note + " " + note + " " + note + " |";
		break;
	case 30:
		return "|   " + note + " " + note + " " + note + " " + note + " |";
		break;
	case 31:
		return "| " + note + " " + note + " " + note + " " + note + " " + note + " |";
		break;
	}
}

const float Chord::getDelay()
{
	return delay;
}

const float Chord::getSustain()
{
	return sustain;
}

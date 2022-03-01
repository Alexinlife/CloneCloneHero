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



MChord::~MChord()
{

}

/*const string MChord::getNotes()
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
		// | - - - - - |
		break;
	case 1:
		return "| " + note + "         |";
		// | 0         |
		break;
	case 2:
		return "|   " + note + "       |";
		// |   0       |
		break;
	case 3:
		return "| " + note + " " + note + "       |";
		// | 0 0       |
		break;
	case 4:
		return "|     " + note + "     |";
		// |     0     |
		break;
	case 5:
		return "| " + note + "   " + note + "     |";
		// | 0   0     |
		break;
	case 6:
		return "|   " + note + " " + note + "     |";
		// |   0 0     |
		break;
	case 7:
		return "| " + note + " " + note + " " + note + "     |";
		// | 0 0 0     |
		break;
	case 8:
		return "|       " + note + "   |";
		// |       0   |
		break;
	case 9:
		return "| " + note + "     " + note + "   |";
		// | 0     0   |
		break;
	case 10:
		return "|   " + note + "   " + note + "   |";
		// |   0   0   |
		break;
	case 11:
		return "| " + note + " " + note + "   " + note + "   |";
		// | 0 0   0   |
		break;
	case 12:
		return "|     " + note + " " + note + "   |";
		// |     0 0   |
		break;
	case 13:
		return "| " + note + "   " + note + " " + note + "   |";
		// | 0   0 0   |
		break;
	case 14:
		return "|   " + note + " " + note + " " + note + "   |";
		// |   0 0 0   |
		break;
	case 15:
		return "| " + note + " " + note + " " + note + " " + note + "   |";
		// | 0 0 0 0   |
		break;
	case 16:
		return "|         " + note + " |";
		// |         0 |
		break;
	case 17:
		return "| " + note + "       " + note + " |";
		// | 0       0 |
		break;
	case 18:
		return "|   " + note + "     " + note + " |";
		// |   0     0 |
		break;
	case 19:
		return "| " + note + " " + note + "     " + note + " |";
		// | 0 0     0 |
		break;
	case 20:
		return "|     " + note + "   " + note + " |";
		// |     0   0 |
		break;
	case 21:
		return "| " + note + "   " + note + "   " + note + " |";
		// | 0   0   0 |
		break;
	case 22:
		return "|   " + note + " " + note + "   " + note + " |";
		// |   0 0   0 |
		break;
	case 23:
		return "| " + note + " " + note + " " + note + "   " + note + " |";
		// | 0 0 0   0 |
		break;
	case 24:
		return "|       " + note + " " + note + " |";
		// |       0 0 |
		break;
	case 25:
		return "| " + note + "     " + note + " " + note + " |";
		// | 0     0 0 |
		break;
	case 26:
		return "|   " + note + "   " + note + " " + note + " |";
		// |   0   0 0 |
		break;
	case 27:
		return "| " + note + " " + note + "   " + note + " " + note + " |";
		// | 0 0   0 0 |
		break;
	case 28:
		return "|     " + note + " " + note + " " + note + " |";
		// |     0 0 0 |
		break;
	case 29:
		return "| " + note + "   " + note + " " + note + " " + note + " |";
		// | 0   0 0 0 |
		break;
	case 30:
		return "|   " + note + " " + note + " " + note + " " + note + " |";
		// |   0 0 0 0 |
		break;
	case 31:
		return "| " + note + " " + note + " " + note + " " + note + " " + note + " |";
		// | 0 0 0 0 0 |
		break;
	}
}*/

const int MChord::getNotes()
{
	return notes;
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

#include "Editor.h"

Editor::Editor()
{

}

Editor::~Editor()
{

}

void Editor::readSongFile(string path)
{
	ifstream songFile(path);

	int col = 0;

	int delay;
	char type;
	int note;
	int sustain;

	bool open = false;

	for (string value; getline(songFile, value, ' '); )
	{
		switch (col)
		{
			case 0:
			case 4:
				col = 0;

				if (value != "")
				{
                    delay = stoi(value) * 2.80;
				}
				break;
			case 1:
				type = stoi(value);

				if (type == 3)
				{
					open = true;
				}
				break;
			case 2:
				switch (stoi(value))
				{
					case 0:
						note = 1;
						break;
					case 1:
						note = 2;
						break;
					case 2:
						note = 4;
						break;
					case 3:
						note = 8;
						break;
					case 4:
						note = 16;
						break;
				}

				if (open)
				{
					note = 0;
					open = false;
				}
				break;
			case 3:
				sustain = stoi(value);
				break;
		}

		if (++col == 4)
		{
			if (!chart.isEmpty() && chart.lastChord().getDelay() == delay)
			{
				chart.lastChord().setNotes(chart.lastChord().getNotes() + note);
			}
			else
			{
				chart.pushChord(note, type, delay, sustain);
			}
		}
	}

	chart.setLength(chart.lastChord().getDelay() + 10000);

	songFile.close();
}

Chart Editor::test()
{
	/*chart.setSignature(4, 4);
	chart.setTempo(120);
	chart.setLength(1000);

	chart.pushChord(31, 0, 200, 0);

	chart.pushChord(31, 0, 300, 0);

	chart.pushChord(12, 0, 400, 0);

	chart.pushChord(6, 0, 500, 0);

	chart.pushChord(16, 0, 600, 0);*/

    readSongFile("C:/Users/alexi/Documents/CloneCloneHero/songs/imjustakid/imjustakid.txt");

	return chart;
}

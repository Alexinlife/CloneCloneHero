#include "Editor.h"

Editor::Editor()
{

}

Editor::~Editor()
{

}

Chart Editor::test()
{
	Chart chart;
	chart.setSignature(4, 4);
	chart.setTempo(120);

	chart.pushChord(0, 0, 0, 0);
	chart.pushChord(0, 0, 0, 1);
	chart.pushChord(0, 0, 0, 2);
	chart.pushChord(0, 0, 0, 3);

	chart.pushChord(24, 0, 0, 4);
	chart.pushChord(24, 0, 0, 4.25);

	chart.pushChord(12, 0, 0, 5);
	chart.pushChord(12, 0, 0, 5.25);

	chart.pushChord(2, 0, 0, 6);

	return chart;
}
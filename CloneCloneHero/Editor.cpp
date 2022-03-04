#include "Editor.h"

Editor::Editor()
{

}

Editor::~Editor()
{

}

Chart Editor::test()
{
	chart.setSignature(4, 4);
	chart.setTempo(120);

	chart.pushChord(31, 0, 0, 0);
	chart.pushChord(0, 0, 1, 0);
	chart.pushChord(0, 0, 1, 0);
	chart.pushChord(0, 0, 1, 0);

	chart.pushChord(31, 0, 1, 0);
	chart.pushChord(0, 0, 1, 0);
	chart.pushChord(0, 0, 1, 0);
	chart.pushChord(0, 0, 1, 0);


	chart.pushChord(12, 0, 1, 0);
	chart.pushChord(12, 0, .25, 0);

	chart.pushChord(6, 0, .75, 0);
	chart.pushChord(6, 0, .25, 0);

	chart.pushChord(1, 0, 1, 0);


	chart.pushChord(12, 0, 2, 0);
	chart.pushChord(12, 0, .25, 0);

	chart.pushChord(6, 0, .75, 0);
	chart.pushChord(6, 0, .25, 0);

	chart.pushChord(16, 0, 1, 0);

	return chart;
}
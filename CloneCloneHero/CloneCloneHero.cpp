#include "Stage.h"
#include "Editor.h"

using namespace std;

/**
 ** Auteur: Alex Lajeunesse
 **/
int main()
{
	MChord chord(31, 0, 0, 0);
	cout << chord.getNotes() << "  " << chord.getType() << endl;  
	Stage stage;
	cout << "1" << endl;
	system("PAUSE");
	//Editor editor;
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
	cout << "2" << endl;
	system("PAUSE");
	//Chart chart;
	cout << "3" << endl;
	system("PAUSE");
	//chart = editor.test();
	cout << "4" << endl;
	system("PAUSE");
	chart.nextChord();
	cout << "5" << endl;
	system("PAUSE");
	stage.nextNote(&chart);
	cout << "6" << endl;
	system("PAUSE");
	stage.afficher();
	cout << "7" << endl;
	system("PAUSE");
	while (1) {
		stage.afficher();
		system("PAUSE");
		stage.nextNote(&chart);
	}

	return 0;
}

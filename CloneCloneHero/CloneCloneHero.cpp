#include "Stage.h"
#include "Editor.h"

using namespace std;

int main() {
    Stage stage;
    Editor editor;
    Chart* chart = new Chart;
    *chart = editor.test();
    stage.play(chart);


    return 0;
}
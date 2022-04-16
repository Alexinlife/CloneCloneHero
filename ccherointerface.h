#ifndef CCHEROINTERFACE_H
#define CCHEROINTERFACE_H

#include <QAction>
#include <QApplication>
#include <QDialog>
#include <QDir>
#include <QLabel>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QProgressBar>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QStatusBar>
#include <QThread>
#include <QtCore>
#include <QtMultimedia>
#include "QMNote.h"
#include "Stage.h"

class CCHeroInterface : public QMainWindow
{
    Q_OBJECT
        QThread backend;

public slots:
    void setValues(int* values);
    void handleHelp();
    void handlePause();
    void handleNextSong();
    void handlePrevSong();

signals:
    void needValues();

public:
    CCHeroInterface(QWidget *parent = nullptr);
    ~CCHeroInterface();

private:
    QDir dir;

    QMediaPlaylist* playlist;

    QLabel* scoreLabel;
    QLabel* bestComboLabel;
    QLabel* comboLabel;
    QLabel* pauseLabel;
    QProgressBar* starPowerPB;

    QGraphicsScene* chartScene;
    QGraphicsScene* noteBarScene;

    QTimer* timer;
    QGraphicsView* chartView;
    QGraphicsView* noteBarView;

    int score;
    int bestCombo;
    int combo;

    int pauseState;
    int songCursor;
};
#endif // CCHEROINTERFACE_H

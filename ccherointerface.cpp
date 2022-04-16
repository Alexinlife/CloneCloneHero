#include "ccherointerface.h"

CCHeroInterface::CCHeroInterface(QWidget *parent)
    : QMainWindow(parent)
{
    // media playlist
    playlist = new QMediaPlaylist;
    playlist->addMedia(QUrl::fromLocalFile(dir.relativeFilePath("songs/imjustakid/song.mp3")));
    playlist->addMedia(QUrl::fromLocalFile(dir.relativeFilePath("songs/billytalent/fallenleaves/song.mp3")));
    playlist->addMedia(QUrl::fromLocalFile(dir.relativeFilePath("songs/billytalent/runningacrossthetracks/song.mp3")));

    // media player
    QMediaPlayer* player = new QMediaPlayer(this);
    player->setPlaylist(playlist);
    player->setVolume(10);
    player->play();

    // icons for menu bar
    QPixmap runpix(dir.relativeFilePath("icons/PlayPause.png"));
    QPixmap nextpix(dir.relativeFilePath("icons/NextSong.png"));
    QPixmap previouspix(dir.relativeFilePath("icons/PreviousSong.png"));
    QPixmap quitpix(dir.relativeFilePath("icons/Quit.png"));
    QPixmap restartpix(dir.relativeFilePath("icons/Restart.png"));
    QPixmap helppix(dir.relativeFilePath("icons/Help.png"));

    // set actions for menu bar
    QAction* run = new QAction(runpix, "&Jouer/Pause", this);
    QAction* next = new QAction(nextpix, "&Chanson suivante", this);
    QAction* previous = new QAction(previouspix, "&Chanson precedente", this);
    QAction* quit = new QAction(quitpix, "&Quitter", this);
    QAction* restart = new QAction(restartpix, "&Recommencer", this);
    QAction* help = new QAction(helppix, "&Aide", this);

    // set menu shortcuts
    quit->setShortcut(tr("CTRL+Q"));
    restart->setShortcut(tr("CTRL+R"));
    help->setShortcut(tr("CTRL+H"));
    run->setShortcut(tr("CTRL+P"));
    next->setShortcut(tr("CTRL+N"));
    previous->setShortcut(tr("CTRL+B"));

    // bind actions to menu bar
    QMenu* gameMenu = menuBar()->addMenu("&Jeu");
    gameMenu->addAction(run);
    gameMenu->addAction(restart);
    gameMenu->addSeparator();
    gameMenu->addAction(next);
    gameMenu->addAction(previous);
    gameMenu->addSeparator();
    gameMenu->addAction(quit);
    QMenu* helpMenu = menuBar()->addMenu("&Aide");
    helpMenu->addAction(help);

    // connections
    connect(quit, &QAction::triggered, qApp, &QApplication::quit);
    connect(help, &QAction::triggered, this, &CCHeroInterface::handleHelp);
    connect(run, &QAction::triggered, this, &CCHeroInterface::handlePause);
    connect(next, &QAction::triggered, this, &CCHeroInterface::handleNextSong);
    connect(previous, &QAction::triggered, this, &CCHeroInterface::handlePrevSong);

    // initiate label for score
    scoreLabel = new QLabel(this);
    scoreLabel->move(1750, 100);
    scoreLabel->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);

    // initiate label for bestCombo
    bestComboLabel = new QLabel(this);
    bestComboLabel->move(1750, 300);
    bestComboLabel->setFixedWidth(125);
    bestComboLabel->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);

    // initiate label for combo
    comboLabel = new QLabel(this);
    comboLabel->move(1750, 500);
    comboLabel->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);

    // initiate label for pause
    pauseLabel = new QLabel(this);
    pauseLabel->move(1750, 800);

    // initiate progress bar for starPowerPB
    starPowerPB = new QProgressBar(this);
    starPowerPB->setRange(0, 10);
    starPowerPB->setValue(5);
    statusBar()->addPermanentWidget(starPowerPB);

    // initiate scenes and views for game window
    chartScene = new QGraphicsScene(this);
    noteBarScene = new QGraphicsScene(this);
    chartView = new QGraphicsView(this->centralWidget());
    noteBarView = new QGraphicsView(this->centralWidget());

    // enable antialiasing for views
    this->chartView->setRenderHint(QPainter::Antialiasing);
    this->noteBarView->setRenderHint(QPainter::Antialiasing);

    chartScene->setBackgroundBrush(Qt::black);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), chartScene, SLOT(advance()));
    timer->start(1);

    chartView->setScene(chartScene);
    chartView->setGeometry(QRect(0, -1300, 1720, 2380));
    chartView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    chartView->show();

    noteBarView->setScene(noteBarScene);
    noteBarView->setGeometry(QRect(0, 770, 1720, 200));
    noteBarView->setStyleSheet("background: transparent");
    noteBarView->show();

    QMNote* note1 = new QMNote(NULL, 0, 0);
    QMNote* note2 = new QMNote(NULL, 1, 1);
    QMNote* note3 = new QMNote(NULL, 2, 2);
    QMNote* note4 = new QMNote(NULL, 3, 3);
    QMNote* note5 = new QMNote(NULL, 4, 2);

    list<QMNote*> liste;
    liste.push_back(note1);
    liste.push_back(note2);
    liste.push_back(note3);
    liste.push_back(note4);
    liste.push_back(note5);

    while (!liste.empty())
    {
        QMNote* cursor = liste.front();
        chartScene->addItem(cursor);
        liste.pop_front();
    }

    for (int i = 0; i < 5; i++)
    {
        QMNote* noteBar = new QMNote(NULL, i, 4);
        noteBarScene->addItem(noteBar);
    }

    pauseState = 0;
    songCursor = 0;

    // set up and show window
    this->showMaximized();
    this->setWindowTitle("CloneCloneHero");
    this->show();

    // create backend operation and configure thread
    Stage* stage = new Stage;
    stage->moveToThread(&backend);
    connect(stage, &Stage::valuesChanged, this, &CCHeroInterface::setValues);
    connect(this, &CCHeroInterface::needValues, stage, &Stage::getValues);
    backend.start();
    emit needValues();
}

CCHeroInterface::~CCHeroInterface()
{
    backend.quit();
    backend.wait();
}

void CCHeroInterface::setValues(int* values)
{
    score = values[0];
    bestCombo = values[1];
    combo = values[2];
    scoreLabel->setText(QString::fromStdString("Score : " + to_string(score)));
    bestComboLabel->setText(QString::fromStdString("Meilleur combo : " + to_string(bestCombo)));
    comboLabel->setText(QString::fromStdString("Combo : " + to_string(combo)));
    this->update();
}

void CCHeroInterface::handleHelp()
{
    QDialog* dlg2 = new QDialog(this);
    QLabel* HelpMessage = new QLabel(dlg2);
    QFont f("Arial", 15);
    dlg2->setFont(f);
    HelpMessage->setSizePolicy(QSizePolicy::Policy(40), QSizePolicy::Policy(40));
    HelpMessage->setText("COMMENT JOUER : \n\nAppuyez sur les touches de couleur de la manette en même temps que\nl'affichage de l'interface grahique.\n"
        "\nLes notes défilent du haut vers le bas de l'écran.\n"
        "\nÀ la droite de l'écran se trouvent les informations de la chanson actuelle qui jouent,\n"
        "soit le score total, le meilleur combo ainsi que le combo actuel."
        "\n\nLe score augmente selon le nombre de notes réussies. Les points associés aux notes\n"
        "sont influencés par la barre de Star Power qui peut doubler les points.\n\n"
        "Cette barre se charge et est utilisable après 50 notes réussies.\n"
        "Pour utiliser le Star Power, veuillez secouer légèrement la manette vers le haut\n\n"
        "Le menu situé en haut à gauche de l'interface vous permet de pauser le jeu,\n"
        "de recommencer la chanson, de changer la chanson ainsi que de quitter le jeu.");
    dlg2->resize(800, 460);
    dlg2->setAttribute(Qt::WA_DeleteOnClose);
    dlg2->setWindowTitle(QStringLiteral("Aide"));
    dlg2->show();
}

void CCHeroInterface::handlePause()
{
    if (this->pauseState == 0)
    {
        pauseLabel->setText("PAUSE");
        this->pauseLabel->show();
        this->pauseState = 1;
    }
    else
    {
        this->pauseLabel->setText("");
        this->pauseState = 0;
    }
}

void CCHeroInterface::handleNextSong()
{
    if (this->songCursor < playlist->mediaCount() - 1)
    {
        this->songCursor += 1;
        playlist->setCurrentIndex(songCursor);
    }
    else
    {
        this->songCursor = 0;
        playlist->setCurrentIndex(songCursor);
    }
}

void CCHeroInterface::handlePrevSong()
{
    if (songCursor == 0)
    {
        songCursor = playlist->mediaCount() - 1;
        playlist->setCurrentIndex(songCursor);
    }
    else
    {
        songCursor -= 1;
        playlist->setCurrentIndex(songCursor);
    }
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    vw = new QVideoWidget(this);
    vw->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    vw->setAspectRatioMode(Qt::AspectRatioMode::KeepAspectRatio);
    vw->setAutoFillBackground(true);
    player -> setVideoOutput(vw);
    this -> setCentralWidget(vw);

 //   setGeometry(100, 100, 300, 300);

    slider = new QSlider(this);
    bar = new QProgressBar(this);

    slider -> setOrientation(Qt::Horizontal);

    ui -> statusBar->addPermanentWidget(slider);
    ui -> statusBar->addPermanentWidget(bar);

    connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
    connect(slider,&QSlider::sliderMoved, player,&QMediaPlayer::setPosition);


    connect(player,&QMediaPlayer::durationChanged,bar,&QProgressBar::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,bar,&QProgressBar::setValue);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_File_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File (*.avi, *.mpg, *.mp4");
    on_actionStop_triggered();

    player ->setMedia(QUrl::fromLocalFile(filename));
    on_actionPlay_triggered();
}

void MainWindow::on_actionPlay_triggered()
{
    player->metaDataAvailableChanged(true);
    player ->play();

    ui->statusBar->showMessage("Playing");
}
void MainWindow::on_actionPause_triggered()
{
//    aspectRatioMode = vw->aspectRatioMode();
    player ->pause();
    ui->statusBar->showMessage("Paused");
}

void MainWindow::on_actionStop_triggered()
{
//    aspectRatioMode = vw->aspectRatioMode();
    player ->stop();
    ui->statusBar->showMessage("Stopped ");
}

void MainWindow::on_actionrewind_triggered()
{
//    player ->
}

void MainWindow::on_actionforward_triggered()
{

}

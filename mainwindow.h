#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_File_triggered();

    void on_actionPlay_triggered();

    void on_actionPause_triggered();

    void on_actionStop_triggered();

    void on_actionrewind_triggered();

    void on_actionforward_triggered();

private:
    Ui::MainWindow *ui;
    QSize sizeHint;
    QMediaPlayer* player;
    QVideoWidget* vw;
    QProgressBar* bar;
    QSlider * slider;
};

#endif // MAINWINDOW_H

#include "include/widgets/MainWindow.hpp"

#include "../frontend/ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   QObject::connect(ui->addMusictoCollectButton, &QPushButton::clicked, this, [this] { emit this->addNewCollection(); });
}

void MainWindow::addCollectionWidget(QWidget* collection) { ui->MusicCollectionLayout->addWidget(collection); }
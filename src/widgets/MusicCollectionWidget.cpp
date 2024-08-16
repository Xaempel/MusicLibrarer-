#include "../include/widgets/MusicCollectionWidget.hpp"

#include "../frontend/ui_MusicCollectionWidget.h"

MusicCollectionWidget::MusicCollectionWidget(QWidget* parent, const QString collectioName)
    : QFrame(parent)
    , ui(new Ui::MusicCollectionWidget)
{
   ui->setupUi(this);
   ui->CollectionTitle->setText(collectioName);
}

void MusicCollectionWidget::mousePressEvent(QMouseEvent* event)
{
   emit collectionwasClicked();
}
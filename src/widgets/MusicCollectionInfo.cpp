#include "../include/widgets/MusicCollectionInfo.hpp"

#include "../frontend/ui_MusicCollectionInfo.h"

MusicCollectionInfo::MusicCollectionInfo(QWidget* parent)
    : QFrame(parent),
    ui(new Ui::MusicCollectionInfo)
{
    ui->setupUi(this);
}
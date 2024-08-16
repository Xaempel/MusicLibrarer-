#include "../include/widgets/MusicCollectionWizard.hpp"

#include "../frontend/ui_MusicCollectionWizard.h"

MusicCollectionWizard::MusicCollectionWizard(QWidget* parent)
    : QWizard(parent)
    , ui(new Ui::MusicCollectionWizard)
{
   ui->setupUi(this);
}

DataWizard MusicCollectionWizard::getDatafromWizard()
{
   DataWizard userInput;
   userInput.collectioName    = ui->CollectionNameInput->text();
   userInput.collectionGenre  = ui->MusicCollectionGenreInput->text();
   userInput.typeofCollection = static_cast<CollectionType>(ui->TypeofCollectionComboBox->currentIndex());
   return userInput;
}
#include "../include/DepedencyManager.hpp"

#include "../include/widgets/MusicCollectionWidget.hpp"
#include "../include/widgets/MusicCollectionWizard.hpp"

#include <QMessageBox>

DepedencyManager::DepedencyManager()
{
   QObject::connect(&mainWindow, &MainWindow::addNewCollection, this, &DepedencyManager::addMusicCollection);
}

void DepedencyManager::startApp()
{
   mainWindow.showFullScreen();
}

void DepedencyManager::addMusicCollection()
{
   MusicCollectionWizard musicCollectionWizard;
   int wizardResult = musicCollectionWizard.exec();

   if (wizardResult == QDialog::Accepted) {
      auto datafromWizard = musicCollectionWizard.getDatafromWizard();

      if (datafromWizard.collectioName.size() == 0 or datafromWizard.collectionGenre.size() == 0) {
         QMessageBox::warning(nullptr, "Music Collection Warning", "You don't gave a need music collection data");
      }
      else {
         MusicCollectionWidget* musicCollectionWidget {new MusicCollectionWidget(nullptr, datafromWizard.collectioName)};
         mainWindow.addCollectionWidget(musicCollectionWidget);
      }
   }
}
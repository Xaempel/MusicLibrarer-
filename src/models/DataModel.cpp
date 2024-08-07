#include "../../include/models/DataModel.hpp"

using namespace DataUtils;

QVariantList DataModel::load(const QString fileName, const QString dataSectionName)
{
   QVariantList datatoReturn {};
   try {
      if (!QFile::exists(fileName)) {
         throw std::runtime_error("there is no file with the given name DataModel::load");
      }

      QFile file(fileName);

      if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
         throw std::runtime_error("file " + fileName.toStdString() + " is not open");
      }

      initJsonObjects(file, dataSectionName);

      if (!object.contains(dataSectionName)) {
         throw std::runtime_error("the wrong section name was specified in the function deleteDatafromFile");
      }

      datatoReturn = object[dataSectionName].toArray().toVariantList();

      saveFile(file);
      return datatoReturn;
   }
   catch (const std::exception& e) {
      qWarning() << "Something in the load method went wrong: " << e.what();
      return datatoReturn;
   }
}

void DataModel::remove(const QString fileName, const QString dataSectionName, const int IndexofDataDelete)
{
   try {
      QFile file(fileName);
      if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
         throw std::runtime_error("file " + fileName.toStdString() + " is not open");
      }
      if (!object.contains(dataSectionName)) {
         throw std::runtime_error("the wrong section name was specified in the function deleteDatafromFile");
      }
      initJsonObjects(file, dataSectionName);

      datatoSave.removeAt(IndexofDataDelete);
      object[dataSectionName] = datatoSave;
      document.setObject(object);
      saveFile(file);
   }
   catch (const std::exception& e) {
      qWarning() << "Something in the load method went wrong: " << e.what();
   }
}

void DataModel::initJsonObjects(QFile& file, const QString dataSectionName)
{
   document   = QJsonDocument::fromJson(file.readAll());
   object     = document.object();
   datatoSave = object[dataSectionName].toArray();
}

void DataModel::saveFile(QFile& file)
{
   file.resize(0);
   file.seek(0);
   file.write(document.toJson());
   file.close();
}
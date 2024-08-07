/******************************************************************************
**                                                                            **
**  Copyright (C) [2024] [Xaempel]                                            **
**                                                                            **
**  This file is part of [MusicLibrarer].                                     **
**  [MusicLibrarer] is free software: you can redistribute it and/or          **
**  modify it under the terms of the GNU General Public License as published  **
**  by the Free Software Foundation, either version 2 of the License, or any  **
**  later version.                                                            **
**                                                                            **
**  [MusicLibrarer] is distributed in the hope that it will be                **
**  useful, but WITHOUT ANY WARRANTY; without even the implied warranty of    **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             **
**  GNU General Public License for more details.                              **
**                                                                            **
**  You should have received a copy of the GNU General Public License along   **
**  with [MusicLibrarer].  If not, see <https://www.gnu.org/licenses/>.       **
**                                                                            **
**  This project uses the Qt framework, which is licensed under the GNU       **
**  General Public License (GPL) version 2 or later. The full text of the     **
**  GPL license can be found in the LICENSE file.                             **
**                                                                            **
**  Qt is a cross-platform application framework maintained by The Qt Company.**
**  You can find more information about Qt and its licensing at               **
**  https://www.qt.io/.                                                       **
**                                                                            **
******************************************************************************/
#pragma once

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

namespace DataUtils {

   /// @brief The DataModel have basic data operation save, load, remove.
   class DataModel {
      public:
      /// @brief The save method save data in file
      template <typename... DataPack>
      bool save(QString fileName, QString dataSectionName, DataPack... dp)
      {
         QFile file(fileName);
         if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
            throw std::runtime_error("file " + fileName.toStdString() + " is not open");
         }

         initJsonObjects(file, dataSectionName);

         (datatoSave.append(dp), ...);

         object[dataSectionName] = datatoSave;
         document.setObject(object);

         saveFile(file);
         return true;
      }

      /// @brief The load method load data from file
      [[nodiscard]] QVariantList load(const QString fileName, const QString dataSectionName);

      /// @brief The remove method remove data from file based on IndexofDataDelete var
      void remove(const QString fileName, const QString dataSectionName, int IndexofDataDelete);

      private:
      void initJsonObjects(QFile& file, const QString dataSectionName);
      void saveFile(QFile& file);

      QJsonDocument document {};
      QJsonObject object {};
      QJsonArray datatoSave {};
   };

}
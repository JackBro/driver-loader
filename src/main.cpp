/*
    This file is part of driver-loader
    Copyright (C) 2017 @maldevel

    driver-loader - Load a Windows Kernel Driver.
    https://github.com/maldevel/driver-loader

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    For more see the file 'LICENSE' for copying permission.
*/

#include "mainwindow.h"
#include "dlcommon.h"
#include "dlservices.h"

#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[]) {
    Common::init();

    QApplication a(argc, argv);

    if (Services::init() == false) {
        QMessageBox msgBox;
        msgBox.setText("Can't connect to service control manager.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        QApplication::quit();

        return 1;
    } else {
        MainWindow w;
        w.show();

        return a.exec();
    }
}

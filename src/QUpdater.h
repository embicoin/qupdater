/******************************************************************************
    qupdater.h: description
    Copyright (C) 2011-2012 Wang Bin <wbsecg1@gmail.com>
    
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
******************************************************************************/

#ifndef QUPDATER_H
#define QUPDATER_H

#include <QtCore/QObject>
#include <QtCore/QUrl>
#include "QUpdater_Global.h"

class UpdateConfigDialog;
class UpdateCreatorDialog;
class EZProgressDialog;
class Q_EXPORT QUpdater : public QObject
{
    Q_OBJECT
public:
    QUpdater(QObject* parent = 0); //load schedue in cfg. if not found, fetch version file on serve. timer.singalShot(0)
    ~QUpdater();

    void setAppName(const QString& name); //used to close app
    QString appName() const;
    //void setAppPid()
    bool fetchVersionFromServer(const QUrl& url);
    void checkVersion();
    bool hasNewVersion();
    bool fetchUpdateFromServer(const QUrl& url);
    void checkAppRunning();
    bool isAppRunning() const;
    bool killRunningApp();
    bool installUpdate();

signals:
    void newVersionAvailabe(); //then show a dialog and let user choose an option
    void fetchVersionFailed();
    void killRunningAppFailed();
    void updateFinished(); //parameter ok

private:
    UpdateConfigDialog *mConfigDialog;
    UpdateCreatorDialog *mCreatorDialog;
    EZProgressDialog *mProgressDialog;
};

#endif //QUPDATER_H


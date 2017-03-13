/*  This file is part of the KDE libraries
 *  Copyright 2013 Kevin Ottens <ervin+bluesystems@kde.org>
 *  Copyright 2013 Aleix Pol Gonzalez <aleixpol@blue-systems.com>
 *  Copyright 2014 Lukáš Tinkl <ltinkl@redhat.com>
 *
 *  This library is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation; either version 2 of the License or ( at
 *  your option ) version 3 or, at the discretion of KDE e.V. ( which shall
 *  act as a proxy as in section 14 of the GPLv3 ), any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this library; see the file COPYING.LIB.  If not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA 02110-1301, USA.
 */

#include "kdeplatformtheme.h"
#include "kfontsettingsdata.h"
#include "khintssettings.h"
#include "kiconengine.h"
#include "kiconloader.h"

#include <qpa/qplatformthemefactory_p.h>
#include <QCoreApplication>
#include <QFileInfo>
#include <QFont>
#include <QList>
#include <QMimeDatabase>
#include <QMimeType>
#include <QPixmap>
#include <QString>
#include <QVariant>

KdePlatformTheme::KdePlatformTheme() : QPlatformTheme()
{
    loadSettings();
    QCoreApplication::setAttribute(Qt::AA_DontUseNativeMenuBar, false);
}

KdePlatformTheme::~KdePlatformTheme()
{
    delete m_fontsData;
    delete m_hints;
}

QIcon KdePlatformTheme::fileIcon(const QFileInfo &fileInfo, QPlatformTheme::IconOptions iconOptions) const
{
    if (iconOptions.testFlag(DontUseCustomDirectoryIcons) && fileInfo.isDir()) {
        return QIcon::fromTheme(QLatin1String("inode-directory"));
    }

    return KIconLoader::global()->loadMimeTypeIcon(
        QMimeDatabase().mimeTypeForFile(fileInfo).iconName(), KIconLoader::Desktop);
}

const QFont *KdePlatformTheme::font(Font type) const
{
    KFontSettingsData::FontTypes fdtype;
    switch (type) {
    case SystemFont:
        fdtype = KFontSettingsData::GeneralFont; break;
    case MenuFont:
    case MenuBarFont:
    case MenuItemFont:
        fdtype = KFontSettingsData::MenuFont; break;
    case MessageBoxFont:
    case LabelFont:
    case TipLabelFont:
    case StatusBarFont:
    case PushButtonFont:
    case ItemViewFont:
    case ListViewFont:
    case HeaderViewFont:
    case ListBoxFont:
    case ComboMenuItemFont:
    case ComboLineEditFont:
        fdtype = KFontSettingsData::GeneralFont; break;
    case TitleBarFont:
    case MdiSubWindowTitleFont:
    case DockWidgetTitleFont:
        fdtype = KFontSettingsData::WindowTitleFont; break;
    case SmallFont:
    case MiniFont:
        fdtype = KFontSettingsData::SmallestReadableFont; break;
    case FixedFont:
        fdtype = KFontSettingsData::FixedFont; break;
    case ToolButtonFont:
        fdtype = KFontSettingsData::ToolbarFont; break;
    default:
        fdtype = KFontSettingsData::GeneralFont; break;
    }

    return m_fontsData->font(fdtype);
}

void KdePlatformTheme::loadSettings()
{
    m_fontsData = new KFontSettingsData;
    m_hints = new KHintsSettings;
}

QPlatformMenuBar *KdePlatformTheme::createPlatformMenuBar() const
{
    return QPlatformTheme::createPlatformMenuBar();
}

bool KdePlatformTheme::usePlatformNativeDialog(QPlatformTheme::DialogType type) const
{
    return QPlatformTheme::usePlatformNativeDialog(type);
}

QPlatformDialogHelper *KdePlatformTheme::createPlatformDialogHelper(QPlatformTheme::DialogType type) const
{
    return QPlatformTheme::createPlatformDialogHelper(type);
}

QPlatformSystemTrayIcon *KdePlatformTheme::createPlatformSystemTrayIcon() const
{
    return QPlatformTheme::createPlatformSystemTrayIcon();
}

const QPalette *KdePlatformTheme::palette(QPlatformTheme::Palette type) const
{
    QPalette *palette = m_hints->palette(type);
    return palette ? palette : QPlatformTheme::palette(type);
}

QVariant KdePlatformTheme::themeHint(QPlatformTheme::ThemeHint hintType) const
{
    QVariant hint = m_hints->hint(hintType);
    return hint.isValid() ? hint : QPlatformTheme::themeHint(hintType);
}

QIconEngine *KdePlatformTheme::createIconEngine(const QString &iconName) const
{
    return new KIconEngine(iconName, KIconLoader::global());
}

QList<QKeySequence> KdePlatformTheme::keyBindings(QKeySequence::StandardKey key) const
{
    return QPlatformTheme::keyBindings(key);
}

QString KdePlatformTheme::standardButtonText(int button) const
{
    return QPlatformTheme::standardButtonText(button);
}

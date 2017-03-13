/*  This file is part of the KDE libraries
 *  Copyright 2013 Kevin Ottens <ervin+bluesystems@kde.org>
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

#ifndef KDEPLATFORMTHEME_H
#define KDEPLATFORMTHEME_H

#include <qpa/qplatformtheme.h>

#include "khintssettings.h"

class KFontSettingsData;
class QFont;
class QKeySequence;
class QSizeF;
class QString;

class KdePlatformTheme : public QPlatformTheme
{
public:
    KdePlatformTheme();
    ~KdePlatformTheme();

    const QFont *font(Font type) const Q_DECL_OVERRIDE;

private:
    void loadSettings();

    KFontSettingsData *m_fontsData;
    KHintsSettings *m_hints;

    // QPlatformTheme interface
public:
    virtual QPlatformMenuItem *createPlatformMenuItem() const Q_DECL_OVERRIDE;
    virtual QPlatformMenu *createPlatformMenu() const Q_DECL_OVERRIDE;
    virtual QPlatformMenuBar *createPlatformMenuBar() const Q_DECL_OVERRIDE;
    virtual void showPlatformMenuBar() Q_DECL_OVERRIDE;
    virtual bool usePlatformNativeDialog(DialogType type) const Q_DECL_OVERRIDE;
    virtual QPlatformDialogHelper *createPlatformDialogHelper(DialogType type) const Q_DECL_OVERRIDE;
    virtual QPlatformSystemTrayIcon *createPlatformSystemTrayIcon() const Q_DECL_OVERRIDE;
    virtual const QPalette *palette(Palette type) const Q_DECL_OVERRIDE;
    virtual QVariant themeHint(ThemeHint hint) const Q_DECL_OVERRIDE;
    virtual QPixmap standardPixmap(StandardPixmap sp, const QSizeF &size) const Q_DECL_OVERRIDE;
    virtual QPixmap fileIconPixmap(const QFileInfo &fileInfo, const QSizeF &size, QPlatformTheme::IconOptions iconOptions) const Q_DECL_OVERRIDE;
    virtual QIconEngine *createIconEngine(const QString &iconName) const Q_DECL_OVERRIDE;
    virtual QList<QKeySequence> keyBindings(QKeySequence::StandardKey key) const Q_DECL_OVERRIDE;
    virtual QString standardButtonText(int button) const Q_DECL_OVERRIDE;
};

#endif // KDEPLATFORMTHEME_H

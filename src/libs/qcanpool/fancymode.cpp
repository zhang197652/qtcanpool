/***************************************************************************
 **
 **  Copyright (C) 2018-2020 MaMinJie <canpool@163.com>
 **  Contact: https://github.com/canpool
 **
 **  GNU Lesser General Public License Usage
 **  Alternatively, this file may be used under the terms of the GNU Lesser
 **  General Public License version 3 as published by the Free Software
 **  Foundation and appearing in the file LICENSE.LGPL3 included in the
 **  packaging of this file. Please review the following information to
 **  ensure the GNU Lesser General Public License version 3 requirements
 **  will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
 **
 **  GNU General Public License Usage
 **  Alternatively, this file may be used under the terms of the GNU
 **  General Public License version 2.0 or (at your option) the GNU General
 **  Public license version 3 or any later version approved by the KDE Free
 **  Qt Foundation. The licenses are as published by the Free Software
 **  Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
 **  included in the packaging of this file. Please review the following
 **  information to ensure the GNU General Public License requirements will
 **  be met: https://www.gnu.org/licenses/gpl-2.0.html and
 **  https://www.gnu.org/licenses/gpl-3.0.html.
 **
****************************************************************************/
#include "fancymode.h"

QCANPOOL_USE_NAMESPACE

FancyMode::FancyMode(QObject *parent)
    : QObject(parent),
      m_isEnabled(true)
{
}

FancyMode::~FancyMode()
{
    if (m_menu) {
        delete m_menu;
    }
    if (m_widget) {
        delete m_widget;
    }
}

void FancyMode::setEnabled(bool enabled)
{
    if (m_isEnabled == enabled) {
        return;
    }
    m_isEnabled = enabled;
    emit enabledStateChanged(m_isEnabled);
}

bool FancyMode::isEnabled() const
{
    return m_isEnabled;
}

QWidget *FancyMode::widget()
{
    if (!m_widget) {
        m_widget = new QWidget();
    }
    return m_widget;
}

/* === This file is part of Calamares - <https://github.com/calamares> ===
 *
 *   Copyright 2018, Caio Jordão Carvalho <caiojcarvalho@gmail.com>
 *
 *   Calamares is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Calamares is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Calamares. If not, see <http://www.gnu.org/licenses/>.
 */

#include "CreateVolumeGroupDialog.h"

#include <kpmcore/core/device.h>
#include <kpmcore/core/lvmdevice.h>

#include <QComboBox>
#include <QLineEdit>
#include <QSpinBox>

CreateVolumeGroupDialog::CreateVolumeGroupDialog( QString& vgName,
                                                  QVector< const Partition* >& selectedPVs,
                                                  QVector< const Partition* > pvList,
                                                  qint32& peSize,
                                                  QWidget* parent )
    : VolumeGroupBaseDialog( vgName, pvList, peSize, parent )
    , m_selectedPVs( selectedPVs )
{
    setWindowTitle( "Create Volume Group" );

    vgType()->setEnabled( false );
}

void
CreateVolumeGroupDialog::accept()
{
    QString& name = vgNameValue();
    name = vgName()->text();

    m_selectedPVs << checkedItems();

    qint32& pe = peSizeValue();
    pe = peSize()->value();

    QDialog::accept();
}

/* byte_view_tab.h
 *
 * $Id$
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef BYTE_VIEW_TAB_H
#define BYTE_VIEW_TAB_H

#include "config.h"

#include <epan/packet.h>
#include <epan/proto.h>
#include <epan/tvbuff.h>

#include "cfile.h"

#include <QTabWidget>
#include <QTreeWidget>

class ByteViewTab : public QTabWidget
{
    Q_OBJECT
public:
    explicit ByteViewTab(QWidget *parent = 0);
    void addTab(const char *name = "", tvbuff_t *tvb = NULL, proto_tree *tree = NULL, QTreeWidget *protoTree = NULL, packet_char_enc encoding = PACKET_CHAR_ENC_CHAR_ASCII);
    void clear();

private:
    void setTabsVisible();
    capture_file *cap_file_;

protected:
    void tabInserted(int index);
    void tabRemoved(int index);

signals:

public slots:
    void protoTreeItemChanged(QTreeWidgetItem *current);
    void setCaptureFile(capture_file *cf);
};

#endif // BYTE_VIEW_TAB_H

/*
 * Editor modelines
 *
 * Local Variables:
 * c-basic-offset: 4
 * tab-width: 8
 * indent-tabs-mode: nil
 * End:
 *
 * ex: set shiftwidth=4 tabstop=8 expandtab:
 * :indentSize=4:tabSize=8:noTabs=true:
 */

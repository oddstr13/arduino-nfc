/*
 * NfcTagsIntfTypeV.cpp
 *
 * Copyright (c) Thomas Buhot. All right reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "tags/NfcTagsIntf.h"

// state definition
enum {
    TAGS_INTF_TV_STATE_NONE = 0
};

// state strings
const char *nfcTagsIntfTypeV[] = {
    "TAGS_INTF_TV_STATE_NONE"
};

// event definition
enum {
    TAGS_INTF_TV_ID_NONE
};

NfcTagsIntfTypeV::NfcTagsIntfTypeV(NfcLog& log, NfcNci& nci) :
    NfcTagsIntf(log, nci)
{
    _state = TAGS_INTF_TV_STATE_NONE;
}

uint8_t NfcTagsIntfTypeV::getType(void)
{
    return TAGS_TYPE_V;
}

uint8_t NfcTagsIntfTypeV::getNfcidLen(void)
{
    return 8;
}

uint8_t* NfcTagsIntfTypeV::getNfcidBuf(void)
{
    uint8_t *buf = NULL;

    if(_p_rf != NULL) {
        buf = ((tNCI_RF_INTF *)_p_rf)->specific.params.poll_v.nfcid;
    }

    return buf;
}

uint8_t NfcTagsIntfTypeV::cmdDump(void)
{
    _log.d("NfcTagsIntfTypeV: %s state = %s\n", __func__, nfcTagsIntfTypeV[_state]);

    // FIXME: not implemented yet
    return TAGS_STATUS_REJECTED;
}

uint8_t NfcTagsIntfTypeV::handleDump(void)
{
    _log.d("NfcTagsIntfTypeV: %s state = %s\n", __func__, nfcTagsIntfTypeV[_state]);

    // FIXME: not implemented yet
    return TAGS_STATUS_REJECTED;
}

void NfcTagsIntfTypeV::handleData(uint8_t status, uint16_t id, void *data)
{
    _log.d("NfcTagsIntfTypeV: %s status = %d id = %d\n", __func__, status, id);

    // FIXME: not implemented yet
}

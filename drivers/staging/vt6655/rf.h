/*
 * Copyright (c) 1996, 2003 VIA Networking Technologies, Inc.
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 *
 * File: rf.h
 *
 * Purpose:
 *
 * Author: Jerry Chen
 *
 * Date: Feb. 19, 2004
 *
 */


#ifndef __RF_H__
#define __RF_H__

#if !defined(__TTYPE_H__)
#include "ttype.h"
#endif
#if !defined(__DEVICE_H__)
#include "device.h"
#endif
/*---------------------  Export Definitions -------------------------*/
//
// Baseband RF pair definition in eeprom (Bits 6..0)
//
#define RF_RFMD2959             0x01
#define RF_MAXIMAG              0x02
#define RF_AIROHA               0x03

//#define RF_GCT5103              0x04
#define RF_UW2451               0x05
#define RF_MAXIMG               0x06
#define RF_MAXIM2829            0x07 // RobertYu: 20041118
#define RF_UW2452               0x08 // RobertYu: 20041210
#define RF_AIROHA7230           0x0a // RobertYu: 20050104
#define RF_UW2453               0x0b

#define RF_VT3226               0x09
#define RF_AL2230S              0x0e

#define RF_NOTHING              0x7E
#define RF_EMU                  0x80
#define RF_MASK                 0x7F

#define ZONE_FCC                0
#define ZONE_MKK1               1
#define ZONE_ETSI               2
#define ZONE_IC                 3
#define ZONE_SPAIN              4
#define ZONE_FRANCE             5
#define ZONE_MKK                6
#define ZONE_ISRAEL             7

//[20050104] CB_MAXIM2829_CHANNEL_5G_HIGH, CB_UW2452_CHANNEL_5G_HIGH: 40==>41
#define CB_MAXIM2829_CHANNEL_5G_HIGH    41 //Index41: channel = 100, Tf = 5500MHz, set the (A3:A0=0101) D6=1
#define CB_UW2452_CHANNEL_5G_HIGH       41 //[20041210] Index41: channel = 100, Tf = 5500MHz, change VCO2->VCO3


/*---------------------  Export Classes  ----------------------------*/

/*---------------------  Export Variables  --------------------------*/

/*---------------------  Export Functions  --------------------------*/
#ifdef __cplusplus
extern "C" {                            /* Assume C declarations for C++ */
#endif /* __cplusplus */

BOOL IFRFbWriteEmbeded(DWORD_PTR dwIoBase, DWORD dwData);
BOOL RFbSelectChannel(DWORD_PTR dwIoBase, BYTE byRFType, BYTE byChannel);
BOOL RFbInit (
    IN  PSDevice  pDevice
    );
BOOL RFvWriteWakeProgSyn(DWORD_PTR dwIoBase, BYTE byRFType, UINT uChannel);
BOOL RFbSetPower(PSDevice pDevice, UINT uRATE, UINT uCH);
BOOL RFbRawSetPower(
    IN  PSDevice  pDevice,
    IN  BYTE      byPwr,
    IN  UINT      uRATE
    );

VOID
RFvRSSITodBm(
    IN  PSDevice pDevice,
    IN  BYTE     byCurrRSSI,
    OUT PLONG    pldBm
    );

//{{ RobertYu: 20050104
BOOL RFbAL7230SelectChannelPostProcess(DWORD_PTR dwIoBase, BYTE byOldChannel, BYTE byNewChannel);
//}} RobertYu

#ifdef __cplusplus
}                                       /* End of extern "C" { */
#endif /* __cplusplus */


#endif // __RF_H__




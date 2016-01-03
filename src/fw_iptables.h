/********************************************************************\
 * This program is free software; you can redistribute it and/or    *
 * modify it under the terms of the GNU General Public License as   *
 * published by the Free Software Foundation; either version 2 of   *
 * the License, or (at your option) any later version.              *
 *                                                                  *
 * This program is distributed in the hope that it will be useful,  *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of   *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    *
 * GNU General Public License for more details.                     *
 *                                                                  *
 * You should have received a copy of the GNU General Public License*
 * along with this program; if not, contact:                        *
 *                                                                  *
 * Free Software Foundation           Voice:  +1-617-542-5942       *
 * 59 Temple Place - Suite 330        Fax:    +1-617-542-2652       *
 * Boston, MA  02111-1307,  USA       gnu@gnu.org                   *
 *                                                                  *
\********************************************************************/

/* $Id: fw_iptables.h 1375 2008-09-30 10:20:06Z wichert $ */
/** @file fw_iptables.h
    @brief Firewall iptables functions
    @author Copyright (C) 2004 Philippe April <papril777@yahoo.com>
*/

#ifndef _FW_IPTABLES_H_
#define _FW_IPTABLES_H_

#include "firewall.h"

/*@{*/ 
/**Iptable table names used by WifiDog */
#define TABLE_WIFIDOG_OUTGOING  "WD_$ID$_Out"
#define TABLE_WIFIDOG_WIFI_TO_INTERNET "WD_$ID$_W2I"
#define TABLE_WIFIDOG_WIFI_TO_ROUTER "WD_$ID$_W2R"
#define TABLE_WIFIDOG_INCOMING  "WD_$ID$_In"
#define TABLE_WIFIDOG_AUTHSERVERS "WD_$ID$_Auth"
#define TABLE_WIFIDOG_GLOBAL  "WD_$ID$_Glob"
#define TABLE_WIFIDOG_VALIDATE  "WD_$ID$_Valid"
#define TABLE_WIFIDOG_KNOWN     "WD_$ID$_Kwn"
#define TABLE_WIFIDOG_UNKNOWN   "WD_$ID$_Unkwn"
#define TABLE_WIFIDOG_LOCKED    "WD_$ID$_Lock"
#define TABLE_WIFIDOG_TRUSTED    "WD_$ID$_Trust"
/*@}*/ 

/** Used by iptables_fw_access to select if the client should be granted of denied access */
typedef enum fw_access_t_ {
    FW_ACCESS_ALLOW,
    FW_ACCESS_DENY
} fw_access_t;

/** @brief Initialize the firewall */
int iptables_fw_init(void);

/** @brief Initializes the authservers table */
void iptables_fw_set_authservers(void);

/** @brief Clears the authservers table */
void iptables_fw_clear_authservers(void);

/** @brief Destroy the firewall */
int iptables_fw_destroy(void);

/** @brief Helper function for iptables_fw_destroy */
int iptables_fw_destroy_mention( const char * table, const char * chain, const char * mention);

/** @brief Define the access of a specific client */
int iptables_fw_access(fw_access_t type, const char *ip, const char *mac, int tag);

/** @brief All counters in the client list */
int iptables_fw_counters_update(void);

#endif /* _IPTABLES_H_ */

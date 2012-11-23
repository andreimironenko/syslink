/** 
 *  @file   NameServerRemote.h
 *
 *  @brief      Defines for Remote NameServer transport.
 *
 *              This file contains defines used by specific implementations of
 *              remote NameServer transports.
 *
 *
 */
/* 
 *  ============================================================================
 *
 *  Copyright (c) 2008-2012, Texas Instruments Incorporated
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *  
 *  *  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  
 *  *  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  
 *  *  Neither the name of Texas Instruments Incorporated nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *  
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 *  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 *  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 *  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 *  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *  Contact information for paper mail:
 *  Texas Instruments
 *  Post Office Box 655303
 *  Dallas, Texas 75265
 *  Contact information: 
 *  http://www-k.ext.ti.com/sc/technical-support/product-information-centers.htm?
 *  DCMP=TIHomeTracking&HQS=Other+OT+home_d_contact
 *  ============================================================================
 *  
 */



#ifndef NAMESERVERREMOTE_H_0x9EC4
#define NAMESERVERREMOTE_H_0x9EC4


/* Osal & Utility headers */

/* Module headers */


#if defined (__cplusplus)
extern "C" {
#endif


/* =============================================================================
 * Macros & Defines
 * =============================================================================
 */


/* =============================================================================
 * Struct & Enums
 * =============================================================================
 */
/*!
 *  @brief  Handle to the Generic NameServer remote driver.
 */
typedef struct NameServerRemote_Object * NameServerRemote_Handle;

/*!
 *  @brief  Object for Generic NameServer remote driver.
 */
typedef struct NameServerRemote_Object NameServerRemote_Object;

/*! @brief Type for function pointer to get data from remote nameserver
 *  @param      obj             Remote driver object.
 *  @param      instanceName    Nameserver instance name.
 *  @param      name            Name of the entry.
 *  @param      value           Pointer to the value.
 *  @param      valueLen        Length of value.
 *  @param      reserved        Reserved.
 */
typedef UInt32 (*NameServerRemote_GetFxn) (NameServerRemote_Object * obj,
                                           String                    instName,
                                           String                    name,
                                           Ptr                       value,
                                           UInt32 *                  valueLen,
                                           Ptr                       reserved);

/* =============================================================================
 * APIs
 * =============================================================================
 */
/* Function get data from remote name server */
Int
NameServerRemote_get (NameServerRemote_Object * obj,
                      String                    instanceName,
                      String                    name,
                      Ptr                       value,
                      UInt32 *                  valueLen,
                      Ptr                       reserved);


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */

#endif /* NAMESERVERREMOTE_H_0x9EC4 */

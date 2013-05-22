/** 
 *  @file   ClientNotifyMgr_errBase.h
 *
 *  @brief      Header file that defines status codes for ClientNotifyMgr
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



#ifndef CLIENTNOTIFYMGR_ERRBASE_H
#define CLIENTNOTIFYMGR_ERRBASE_H

#if defined (__cplusplus)
extern "C" {
#endif

/*!
 *  @brief  Module ID for ClientNotifyMgr.
 */
#define ClientNotifyMgr_MODULEID                    (0xbe91)

/*!
 *  @brief  Indicates module has been already destroyed.
 */
#define ClientNotifyMgr_S_ALREADYDESTROYED           2
/*!
 *  @brief  Indicates module is already setup.
 */
#define ClientNotifyMgr_S_ALREADYSETUP               1

/*!
 *  @brief  Operation successful.
 */
#define ClientNotifyMgr_S_SUCCESS                    0

/*********************** ClientNotifyMgr Failure Codes *********************************/
/* General Failure */
#define ClientNotifyMgr_E_FAIL                      -1
/* Invalid arguments are passed to  ClientNotifyMgr API  */
#define ClientNotifyMgr_E_INVALIDARG                -2
/* ClientNotifyMgr instance  not found  */
#define ClientNotifyMgr_E_NOTFOUND                  -3
/* ClientNotifyMgr instance  already exists  */
#define ClientNotifyMgr_E_INST_EXISTS               -4

/* Failed to allocate memory  */
#define ClientNotifyMgr_E_MEMORY                    -5

/* Name server create failed for the module  */
#define ClientNotifyMgr_E_CREATE_NAMESERVER         -6

#define ClientNotifyMgr_E_CREATE_GATE               -7

#define ClientNotifyMgr_E_OPEN_GATE                 -8

#define ClientNotifyMgr_E_CREATE_INST               -9

#define ClientNotifyMgr_E_MAX_CLIENTS               -10

#define ClientNotifyMgr_E_ACCESSDENIED              -11
/* Module is not in initialized state   */
#define ClientNotifyMgr_E_INVALIDSTATE              -12

#define ClientNotifyMgr_E_OSFAILURE                 -13
/* Invalid instance id.Id of the instance is more than the maxInstances limit */
#define ClientNotifyMgr_E_INVALIDINSTID             -14

/* MaxInstances limit is reached */
#define ClientNotifyMgr_E_MAXINSTANCES              -15

#if defined (__cplusplus)
}
#endif

#endif

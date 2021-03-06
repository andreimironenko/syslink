/*
 *  @file   SysLinkSamplesAppOS.c
 *
 *  @brief      OS-specific file for common sample features library
 *
 *
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


/* OS-specific headers */
#include <stdio.h>
#include <stdlib.h>

/* Standard headers */
#include <ti/syslink/Std.h>

/* OSAL & Utils headers */
#include <ti/syslink/utils/Trace.h>
#include <ti/syslink/utils/OsalPrint.h>
#include <ti/syslink/SysLink.h>

#include <ti/syslink/samples/hlos/common/SysLinkSamplesOS.h>

#if defined (__cplusplus)
extern "C" {
#endif /* defined (__cplusplus) */


/*!
 *  @brief  Old trace mask
 */
UInt32  SysLinkSamples_oldTraceMask = 0;


/** ============================================================================
 *  Functions
 *  ============================================================================
 */
/*!
 *  @brief  Function to execute the OS-specific startup for common SysLink
 *          sample application features
 */
Void SysLinkSamples_osStartup (Void)
{
    Char *  trace              = FALSE;
    Bool    enableTrace        = FALSE;
    Char *  traceEnter         = FALSE;
    Bool    enableTraceEnter   = FALSE;
    Char *  traceFailure       = FALSE;
    Bool    enableTraceFailure = FALSE;
    Char *  traceClass         = NULL;
    UInt32  enableTraceClass   = 0;
    UInt32  traceMask          = 0;

    trace = getenv ("TRACE");
    /* Enable/disable levels of tracing. */
    if (trace != NULL) {
        enableTrace = strtol (trace, NULL, 16);
        if ((enableTrace != 0) && (enableTrace != 1)) {
            Osal_printf ("Error! Only 0/1 supported for TRACE\n") ;
        }
        else if (enableTrace == TRUE) {
            Osal_printf ("Trace enabled\n");
            traceMask = GT_TraceState_Enable;
        }
        else if (enableTrace == FALSE) {
            Osal_printf ("Trace disabled\n");
            traceMask = GT_TraceState_Disable;
        }
    }

    traceEnter = getenv ("TRACEENTER");
    if (traceEnter != NULL) {
        enableTraceEnter = strtol (traceEnter, NULL, 16);
        if (    (enableTraceEnter != 0)
            &&  (enableTraceEnter != 1)) {
            Osal_printf ("Error! Only 0/1 supported for TRACEENTER\n") ;
        }
        else if (enableTraceEnter == TRUE) {
            Osal_printf ("Trace entry/leave prints enabled\n");
            traceMask |= GT_TraceEnter_Enable;
        }
    }

    traceFailure = getenv ("TRACEFAILURE");
    if (traceFailure != NULL) {
        enableTraceFailure = strtol (traceFailure, NULL, 16);
        if (    (enableTraceFailure != 0)
            &&  (enableTraceFailure != 1)) {
            Osal_printf ("Error! Only 0/1 supported for TRACEENTER\n") ;
        }
        else if (enableTraceFailure == TRUE) {
            Osal_printf ("Trace SetFailureReason enabled\n") ;
            traceMask |= GT_TraceSetFailure_Enable;
        }
    }

    traceClass = getenv ("TRACECLASS");
    if (traceClass != NULL) {
        enableTraceClass = strtol (traceClass, NULL, 16);
        if (    (enableTraceClass != 1)
            &&  (enableTraceClass != 2)
            &&  (enableTraceClass != 3)) {
            Osal_printf ("Error! Only 1/2/3 supported for TRACECLASS\n") ;
        }
        else {
            Osal_printf ("Trace class %s\n", traceClass) ;
            enableTraceClass =
                            enableTraceClass << (32 - GT_TRACECLASS_SHIFT);
            traceMask |= enableTraceClass;
        }
    }

    /* Set the desired trace value. */
    SysLinkSamples_oldTraceMask = GT_setTrace (traceMask, GT_TraceType_User);
}


/*!
 *  @brief  Function to execute the OS-specific shutdown for common SysLink
 *          sample application features
 */
Void SysLinkSamples_osShutdown (Void)
{
    UInt32      oldMask;

    /* Restore the trace value. */
    oldMask = GT_setTrace (SysLinkSamples_oldTraceMask, GT_TraceType_User);
}


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */

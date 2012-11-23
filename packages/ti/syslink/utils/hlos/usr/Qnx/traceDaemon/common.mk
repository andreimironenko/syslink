#   
#   @file   common.mk
#
#   @brief  QNX common makefile
#
#
#   ============================================================================
#
#   Copyright (c) 2008-2012, Texas Instruments Incorporated
#
#   Redistribution and use in source and binary forms, with or without
#   modification, are permitted provided that the following conditions
#   are met:
#   
#   *  Redistributions of source code must retain the above copyright
#      notice, this list of conditions and the following disclaimer.
#   
#   *  Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in the
#      documentation and/or other materials provided with the distribution.
#   
#   *  Neither the name of Texas Instruments Incorporated nor the names of
#      its contributors may be used to endorse or promote products derived
#      from this software without specific prior written permission.
#   
#   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
#   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
#   THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
#   PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
#   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
#   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
#   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
#   OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
#   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
#   OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
#   EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#   Contact information for paper mail:
#   Texas Instruments
#   Post Office Box 655303
#   Dallas, Texas 75265
#   Contact information: 
#   http://www-k.ext.ti.com/sc/technical-support/product-information-centers.htm?
#   DCMP=TIHomeTracking&HQS=Other+OT+home_d_contact
#   ============================================================================
#   
ifndef QCONFIG
QCONFIG=qconfig.mk
endif
include $(QCONFIG)

define PINFO
PINFO DESCRIPTION=Trace daemon
endef

NAME = syslink_trace_daemon
INSTALLDIR = bin

#####AUTO-GENERATED by packaging script... do not checkin#####
   INSTALL_ROOT_nto = $(PROJECT_ROOT)/../../../../../../install
   USE_INSTALL_ROOT=1
##############################################################

EXTRA_INCVPATH += $(SYSLINK_ROOT)

CCOPTS+=-g
CCOPTS+= -O0

LDFLAGS += -M

EXTRA_LIBVPATH += $(SYSLINK_ROOT)/ti/syslink/utils/hlos/usr/Qnx/lib/arm/a.le.v7

LIBS=syslink_client

include $(MKFILES_ROOT)/qtargets.mk

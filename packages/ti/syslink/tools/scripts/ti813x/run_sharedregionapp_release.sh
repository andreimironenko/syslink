#!/bin/sh
#   
#   @file   run_sharedregionapp_release.sh
#
#   @brief  Script to run the release samples
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
mapfile=""

if [[ $# -gt 0 ]]; then
    mapfile=$1
fi

# Run the sample application using the slaveloader method (preferred)
echo "======== Running app using slaveloader ========"
./slaveloader_release startup VIDEO-M3 ./sharedregion_ti81xx_videom3.xem3 $mapfile
./slaveloader_release startup VPSS-M3 ./sharedregion_ti81xx_vpssm3.xem3 $mapfile
./sharedregionapp_release 0x8FD00000
./slaveloader_release shutdown VIDEO-M3 $mapfile
./slaveloader_release shutdown VPSS-M3 $mapfile

# Run the samples application using the optional arguments method to
# load, run, and stop the slave processor
echo "======== Running app using arguments ========"
./sharedregionapp_release 0x8FD00000 2 VIDEO-M3 ./sharedregion_ti81xx_videom3.xem3 VPSS-M3 ./sharedregion_ti81xx_vpssm3.xem3 $mapfile
echo "======== Running app using arguments ========"
./sharedregionapp_release 0x8FD00000 1 VIDEO-M3 ./sharedregion_ti81xx_videom3.xem3 $mapfile
echo "======== Running app using arguments ========"
./sharedregionapp_release 0x8FD00000 1 VPSS-M3 ./sharedregion_ti81xx_vpssm3.xem3 $mapfile

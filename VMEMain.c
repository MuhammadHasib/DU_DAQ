/*
    -----------------------------------------------------------------------------

                   --- CAEN SpA - Computing Systems Division --- 

    -----------------------------------------------------------------------------

    Name		:	CAENVMEDemoMain.c

    Project		:	CaenVmeDemo

    Description :	Example program for V1718 & V2718 control.

    Date		:	November 2004
    Release		:	1.0
    Author		:	C.Landi

    Date		:	August 2006
    Release		:	1.1
    Author		:	NDA
    Description :	64 bit porting (CAENVMElib rev >= 2.5)


    -----------------------------------------------------------------------------

    Edited By: Muhammad Hasib     (09-JAN-2014)           University of delhi
    -----------------------------------------------------------------------------
*/


#include <stdlib.h>
#include <stdio.h>
//#include <stdint.h>
#include <stdarg.h>

#include "CAENVMElib.h"
#include "console.h"

extern  void CaenVmeManual(long, short) ; 

// Main program

int main(int argc, void *argv[]) 

{
CVBoardTypes  VMEBoard;
short         Link=0;
short         Device;
int32_t       BHandle;

// Initialize the Board

if( CAENVME_Init(VMEBoard, Link, Device, &BHandle) != cvSuccess ) 
    {
    printf("\n\n Error opening the device\n");
    exit(1);
    }


con_init() ;

// CAENVME_SetFIFOMode(BHandle,1) ;
	
CaenVmeManual(BHandle,1) ;

con_end() ;

CAENVME_End(BHandle);
}


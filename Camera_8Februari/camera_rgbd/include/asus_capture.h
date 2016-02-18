/* Copyright 2012 The MathWorks, Inc. */
#ifndef ASUS_CAPTURE_H
#define ASUS_CAPTURE_H

#if defined(MATLAB_MEX_FILE)
/* This will be compiled by MATLAB to create the Simulink block:            */


/* Model Start function*/
#define asusInit() 

/* Model Step function*/
#define asusCapture(depth) 

/* Model Terminate function*/
#define asusTerminate() 

#else

#include "wrapper.h"
/* This will be called by the target compiler:    */

 /*Following prototype mapping is done in the code generation*/

#endif /*MATLAB_MEX_FILE*/
#endif /*ASUS_CAPTURE_H*/
 

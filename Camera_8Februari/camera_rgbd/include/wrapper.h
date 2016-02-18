/* Copyright 2012 The MathWorks, Inc. */
#ifndef _wrapper_H_
#define _wrapper_H_
#include "rtwtypes.h"

#if defined(_RUNONTARGETHARDWARE_BUILD_)

extern void asusInit();
extern void asusCapture(uint16_T* depth);
extern void asusTerminate();

#else
/* Used in rapid accelerator mode */
#define asusInit()
#define asusCapture(depth)
#define asusTerminate()
#endif
    
#endif /* _wrapper_H_ */
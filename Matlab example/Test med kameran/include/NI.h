#ifndef NI_H
#define NI_H
#ifdef __cplusplus
extern "C"{
    typedef unsigned short uint16_T;
    void captureNI(uint16_T *depth);
    void initNI();
    void terminateNI();
}
#endif /* __cplusplus */
#endif /* _NI_H_ */
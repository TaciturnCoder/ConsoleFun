/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class ConsoleFunJNI_ConsoleFun */

#ifndef _Included_ConsoleFunJNI_ConsoleFun
#define _Included_ConsoleFunJNI_ConsoleFun
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     ConsoleFunJNI_ConsoleFun
 * Method:    gotorc
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_ConsoleFunJNI_ConsoleFun_gotorc
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     ConsoleFunJNI_ConsoleFun
 * Method:    setcolor
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_ConsoleFunJNI_ConsoleFun_setcolor
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     ConsoleFunJNI_ConsoleFun
 * Method:    emptyrect
 * Signature: (IILConsoleFunJNI/cfopts;)V
 */
JNIEXPORT void JNICALL Java_ConsoleFunJNI_ConsoleFun_emptyrect
  (JNIEnv *, jclass, jint, jint, jobject);

/*
 * Class:     ConsoleFunJNI_ConsoleFun
 * Method:    filledrect
 * Signature: (IILConsoleFunJNI/cfopts;)V
 */
JNIEXPORT void JNICALL Java_ConsoleFunJNI_ConsoleFun_filledrect
  (JNIEnv *, jclass, jint, jint, jobject);

#ifdef __cplusplus
}
#endif
#endif
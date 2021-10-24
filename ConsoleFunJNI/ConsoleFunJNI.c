
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#include <jni.h>
#include "../ConsoleFun.h"
#include "./ConsoleFunJNI_ConsoleFun.h"

cfopts jobject_to_cfopts(JNIEnv *, jobject);

JNIEXPORT jobject JNICALL Java_ConsoleFunJNI_ConsoleFun_getopts(JNIEnv *env, jclass class)
{
    cfopts opts = ConsoleFun_getopts();

    jclass _cfopts = (*env)->FindClass(env, "ConsoleFunJNI/cfopts");

    printf("%d", _cfopts == NULL);

    jmethodID constructor = (*env)->GetMethodID(env, _cfopts, "<init>", "()V");
    jobject newObj = (*env)->NewObject(env, _cfopts, constructor);

    jfieldID _rows = (*env)->GetFieldID(env, _cfopts, "rows", "I");
    jfieldID _cols = (*env)->GetFieldID(env, _cfopts, "cols", "I");
    jfieldID _fg = (*env)->GetFieldID(env, _cfopts, "fg", "I");
    jfieldID _bg = (*env)->GetFieldID(env, _cfopts, "bg", "I");

    (*env)->SetIntField(env, newObj, _rows, opts.rows);
    (*env)->SetIntField(env, newObj, _cols, opts.cols);
    (*env)->SetIntField(env, newObj, _fg, opts.fg);
    (*env)->SetIntField(env, newObj, _bg, opts.bg);

    return newObj;
}

JNIEXPORT void JNICALL Java_ConsoleFunJNI_ConsoleFun_gotorc(JNIEnv *env, jclass class, jint row, jint col)
{
    ConsoleFun_gotorc(row, col);
    return;
}

JNIEXPORT void JNICALL Java_ConsoleFunJNI_ConsoleFun_setcolor(JNIEnv *env, jclass class, jint fg, jint bg)
{
#ifdef __linux__
    if (fg == 1 || fg == 3)
        fg += 3;
    else if (fg == 4 || fg == 6)
        fg -= 3;

    if (bg == 1 || bg == 3)
        bg += 3;
    else if (bg == 4 || bg == 6)
        bg -= 3;
#endif

    ConsoleFun_setcolor(fg, bg);
    return;
}

JNIEXPORT void JNICALL Java_ConsoleFunJNI_ConsoleFun_emptyrect(JNIEnv *env, jclass class, jint row, jint col, jobject opts)
{
    cfopts options = jobject_to_cfopts(env, opts);
    ConsoleFun_emptyrect(row, col, options);
    return;
}

JNIEXPORT void JNICALL Java_ConsoleFunJNI_ConsoleFun_filledrect(JNIEnv *env, jclass class, jint row, jint col, jobject opts)
{
    cfopts options = jobject_to_cfopts(env, opts);
    ConsoleFun_filledrect(row, col, options);
    return;
}

cfopts jobject_to_cfopts(JNIEnv *env, jobject obj)
{
    cfopts opts;

    jclass _cfopts = (*env)->GetObjectClass(env, obj);

    jfieldID _rows = (*env)->GetFieldID(env, _cfopts, "rows", "I");
    jfieldID _cols = (*env)->GetFieldID(env, _cfopts, "cols", "I");
    jfieldID _fg = (*env)->GetFieldID(env, _cfopts, "fg", "I");
    jfieldID _bg = (*env)->GetFieldID(env, _cfopts, "bg", "I");

    jint rows = (*env)->GetIntField(env, obj, _rows);
    jint cols = (*env)->GetIntField(env, obj, _cols);
    jint fg = (*env)->GetIntField(env, obj, _fg);
    jint bg = (*env)->GetIntField(env, obj, _bg);

    opts.rows = rows;
    opts.cols = cols;
    opts.fg = fg;
    opts.bg = bg;

    return opts;
}
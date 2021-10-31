
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#include <jni.h>
#include "../Headers/ConsoleFun.h"
#include "./ConsoleFunJNI_ConsoleFun.h"

/*CFOpts _CFOpts2CFOpts(JNIEnv *, jobject);*/

JNIEXPORT jobject JNICALL Java_ConsoleFunJNI_ConsoleFun_GetOpts(JNIEnv *_Env, jclass _Class)
{
    CFOpts Options = ConsoleFun.GetOpts();

    jclass _CFOpts = (*_Env)->FindClass(_Env, "ConsoleFunJNI/CFOpts");

    jmethodID _Constructor = (*_Env)->GetMethodID(_Env, _CFOpts, "<init>", "()V");
    jobject _Options = (*_Env)->NewObject(_Env, _CFOpts, _Constructor);

    jfieldID _Row = (*_Env)->GetFieldID(_Env, _CFOpts, "Row", "I");
    jfieldID _Col = (*_Env)->GetFieldID(_Env, _CFOpts, "Col", "I");
    jfieldID _Rows = (*_Env)->GetFieldID(_Env, _CFOpts, "Rows", "I");
    jfieldID _Cols = (*_Env)->GetFieldID(_Env, _CFOpts, "Cols", "I");
    jfieldID _FG = (*_Env)->GetFieldID(_Env, _CFOpts, "FG", "I");
    jfieldID _BG = (*_Env)->GetFieldID(_Env, _CFOpts, "BG", "I");

    (*_Env)->SetIntField(_Env, _Options, _Row, Options.Row);
    (*_Env)->SetIntField(_Env, _Options, _Col, Options.Col);
    (*_Env)->SetIntField(_Env, _Options, _Rows, Options.Rows);
    (*_Env)->SetIntField(_Env, _Options, _Cols, Options.Cols);
    (*_Env)->SetIntField(_Env, _Options, _FG, Options.FG);
    (*_Env)->SetIntField(_Env, _Options, _BG, Options.BG);

    return _Options;
}

JNIEXPORT jchar JNICALL Java_ConsoleFunJNI_ConsoleFun_GetCh(JNIEnv *_Env, jclass _Class)
{
    return ConsoleFun.GetCh();
}

JNIEXPORT void JNICALL Java_ConsoleFunJNI_ConsoleFun_GotoRC(JNIEnv *_Env, jclass _Class, jint Row, jint Col)
{
    ConsoleFun.GotoRC(Row, Col);
    return;
}

JNIEXPORT void JNICALL Java_ConsoleFunJNI_ConsoleFun_SetColor(JNIEnv *_Env, jclass _Class, jint FG, jint BG)
{
#ifdef __linux__
    if (FG == 1 || FG == 3)
        FG += 3;
    else if (FG == 4 || FG == 6)
        FG -= 3;

    if (BG == 1 || BG == 3)
        BG += 3;
    else if (BG == 4 || BG == 6)
        BG -= 3;
#endif

    ConsoleFun.SetColor(FG, BG);
    return;
}

/*CFOpts _CFOpts2CFOpts(JNIEnv *_Env, jobject _Options)
{
    CFOpts Options;

    jclass _CFOpts = (*_Env)->GetObjectClass(_Env, _Options);

    jfieldID _Row = (*_Env)->GetFieldID(_Env, _CFOpts, "Row", "I");
    jfieldID _Col = (*_Env)->GetFieldID(_Env, _CFOpts, "Col", "I");
    jfieldID _Rows = (*_Env)->GetFieldID(_Env, _CFOpts, "Rows", "I");
    jfieldID _Cols = (*_Env)->GetFieldID(_Env, _CFOpts, "Cols", "I");
    jfieldID _FG = (*_Env)->GetFieldID(_Env, _CFOpts, "FG", "I");
    jfieldID _BG = (*_Env)->GetFieldID(_Env, _CFOpts, "BG", "I");

    jint Row = (*_Env)->GetIntField(_Env, _Options, _Row);
    jint Col = (*_Env)->GetIntField(_Env, _Options, _Col);
    jint Rows = (*_Env)->GetIntField(_Env, _Options, _Rows);
    jint Cols = (*_Env)->GetIntField(_Env, _Options, _Cols);
    jint FG = (*_Env)->GetIntField(_Env, _Options, _FG);
    jint BG = (*_Env)->GetIntField(_Env, _Options, _BG);

    Options.Rows = Row;
    Options.Cols = Col;
    Options.Rows = Rows;
    Options.Cols = Cols;
    Options.FG = FG;
    Options.BG = BG;

    return Options;
}*/
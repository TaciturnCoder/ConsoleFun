
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
#include "./ConsoleFunJNI_ConsoleFun_Native.h"

/*CFOpts _CFOpts2CFOpts(JNIEnv *, jobject);*/
jobject CFOpts2_CFOpts(JNIEnv *, CFOpts);

JNIEXPORT jchar JNICALL Java_ConsoleFunJNI_ConsoleFun_00024Native_GetCh(JNIEnv *_Env, jclass _Class)
{
    ConsoleFun.Init();
    return ConsoleFun.Native.GetCh();
}

JNIEXPORT jobject JNICALL Java_ConsoleFunJNI_ConsoleFun_00024Native_GetOpts(JNIEnv *_Env, jclass _Class)
{
    ConsoleFun.Init();
    CFOpts Options = ConsoleFun.Native.GetOpts();
    jobject _Options = CFOpts2_CFOpts(_Env, Options);
    return _Options;
}

JNIEXPORT void JNICALL Java_ConsoleFunJNI_ConsoleFun_00024Native_GotoRC(JNIEnv *_Env, jclass _Class, jint _Row, jint _Col)
{
    ConsoleFun.Init();
    ConsoleFun.Native.GotoRC(_Row, _Col);
    return;
}

JNIEXPORT void JNICALL Java_ConsoleFunJNI_ConsoleFun_00024Native_SetColor(JNIEnv *_Env, jclass _Class, jint _FG, jint _BG)
{
    ConsoleFun.Init();
#ifdef __linux__
    if (_FG == 1 || _FG == 3)
        _FG += 3;
    else if (_FG == 4 || _FG == 6)
        _FG -= 3;

    if (_BG == 1 || _BG == 3)
        _BG += 3;
    else if (_BG == 4 || _BG == 6)
        _BG -= 3;
#elif _WIN32
#endif

    ConsoleFun.Native.SetColor(_FG, _BG);
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

jobject CFOpts2_CFOpts(JNIEnv *_Env, CFOpts Options)
{
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
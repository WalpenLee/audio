#include <jni.h>
#include <string>
#include "nim_audio.h"
JNIEXPORT jboolean JNICALL
Java_com_example_hzliwangpeng_nim_1audio_1test_1aos_MainActivity_nim_1audio_1init_1module(
        JNIEnv *env, jobject instance, jstring user_data_parent_path_) {
    const char *user_data_parent_path = env->GetStringUTFChars(user_data_parent_path_, 0);
 //    nim_audio_init_module(user_data_parent_path);

    env->ReleaseStringUTFChars(user_data_parent_path_, user_data_parent_path);
}

JNIEXPORT jboolean JNICALL
Java_com_example_hzliwangpeng_nim_1audio_1test_1aos_MainActivity_nim_1audio_1uninit_1module(
        JNIEnv *env, jobject instance) {
 //   nim_audio_uninit_module();
}

JNIEXPORT jboolean JNICALL
Java_com_example_hzliwangpeng_nim_1audio_1test_1aos_MainActivity_nim_1audio_1play_1audio(
        JNIEnv *env, jobject instance, jstring file_path_, jint audio_format) {
    const char *file_path = env->GetStringUTFChars(file_path_, 0);
//    nim_audio_play_audio(file_path,"","",0, 0);
    env->ReleaseStringUTFChars(file_path_, file_path);
}

JNIEXPORT jboolean JNICALL
Java_com_example_hzliwangpeng_nim_1audio_1test_1aos_MainActivity_nim_1audio_1stop_1play_1audio(
        JNIEnv *env, jobject instance) {
 //   nim_audio_stop_play_audio();
}

JNIEXPORT jboolean JNICALL
Java_com_example_hzliwangpeng_nim_1audio_1test_1aos_MainActivity_nim_1audio_1start_1capture(
        JNIEnv *env, jobject instance, jint audio_format) {

   // nim_audio_start_capture("","",audio_format,20,20,"", 0);
}

JNIEXPORT jboolean JNICALL
Java_com_example_hzliwangpeng_nim_1audio_1test_1aos_MainActivity_nim_1audio_1stop_1capture(
        JNIEnv *env, jobject instance) {
   // nim_audio_stop_capture();
}

JNIEXPORT jboolean JNICALL
Java_com_example_hzliwangpeng_nim_1audio_1test_1aos_MainActivity_nim_1audio_1cancel_1audio(
        JNIEnv *env, jobject instance, jstring file_path_) {
    const char *file_path = env->GetStringUTFChars(file_path_, 0);
   // nim_audio_cancel_audio(file_path);
    env->ReleaseStringUTFChars(file_path_, file_path);
}

extern "C"
jstring
Java_com_example_hzliwangpeng_nim_1audio_1test_1aos_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}






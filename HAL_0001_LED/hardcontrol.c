
#include <jni.h>  /* /usr/lib/jvm/java-1.7.0-openjdk-amd64/include/ */
#include <stdio.h>
#include <stdlib.h>
#include <android/log.h> /* liblog */

//__android_log_print(ANDROID_LOG_DEBUG, "JNIDemo", "native add ...");

 
#if 0
typedef struct {
    char *name;          /* Java里调用的函数名 */
    char *signature;    /* JNI字段描述符, 用来表示Java里调用的函数的参数和返回值类型 呵呵*/
    void *fnPtr;          /* C语言实现的本地函数 */
} JNINativeMethod;
#endif

jint ledOpen(JNIEnv *env, jobject cls)
{
    __android_log_print(ANDROID_LOG_DEBUG, "LEDDemo", "native ledOpen ...");
    return 0;
}
void ledClose(JNIEnv *env, jobject cls)
{
    __android_log_print(ANDROID_LOG_DEBUG, "LEDDemo", "native ledClose ...");

}

jint ledCtrl(JNIEnv *env, jobject cls, jint which, jint status)
{
    __android_log_print(ANDROID_LOG_DEBUG, "LEDDemo", "native ledCtrl: %d, %d", which, status);

    return 0;
}

static const JNINativeMethod methods[] = {
    {"ledOpen", "()I", (void *)ledOpen},
        {"ledClose", "()V", (void *)ledClose},
            {"ledCtrl", "(II)I", (void *)ledCtrl},
};




/* System.loadLibrary */
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *jvm, void *reserved)
{
    JNIEnv *env;
    jclass cls;

    if ((*jvm)->GetEnv(jvm, (void **)&env, JNI_VERSION_1_4)) {
        return JNI_ERR; /* JNI version not supported */
    }
    cls = (*env)->FindClass(env, "com/zpj/hardlibrary/HardControl");
    if (cls == NULL) {
        return JNI_ERR;
    }

    /* 2. map java hello <-->c c_hello */
    if ((*env)->RegisterNatives(env, cls, methods, sizeof(methods)/sizeof(methods[0])) < 0)
        return JNI_ERR;

    return JNI_VERSION_1_4;
}


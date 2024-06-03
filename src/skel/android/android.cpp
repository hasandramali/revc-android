#include <jni.h>
#include <unistd.h>
#include <SDL_main.h>
#include <android/log.h>
#define JNI_WRAPPER extern "C" __attribute__ ((visibility("default")))

extern void InitCrashHandler();

extern "C" JNIEXPORT void JNICALL
Java_com_sh0zer_revc_LauncherActivity_setenv(JNIEnv *env, jobject obj, jstring value)
{
    __android_log_print(ANDROID_LOG_DEBUG,"NIGGER", "Java_com_sh0zer_LauncherActivity_setenv %s",env->GetStringUTFChars(value, NULL));
    setenv("GAMEFILES", env->GetStringUTFChars(value, NULL), 1);
}

JNI_WRAPPER int LaunchAndroid(){
    InitCrashHandler();
    __android_log_print(ANDROID_LOG_DEBUG, "REVC", "TRYING TO START");
    int argc = 0;
    char *argv[1] = { nullptr };
    int result = SDL_main(argc, argv);
    return result;
}

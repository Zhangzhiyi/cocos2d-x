
#include "com_qeeplay_frameworks_LuaJavaBridge.h"

#include <android/log.h>

#include "LuaJavaBridge.h"

#define  LOG_TAG    "LuaJavaBridge_java"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

extern "C" {

JNIEXPORT jint JNICALL Java_com_qeeplay_frameworks_LuaJavaBridge_callLuaFunctionWithString
  (JNIEnv *env, jclass cls, jint functionId, jstring value)
{
    const char *value_ = env->GetStringUTFChars(value, 0);
    int ret = LuaJavaBridge::callLuaFunctionById(functionId, value_);
    env->ReleaseStringUTFChars(value, value_);
    return ret;
}

JNIEXPORT jint JNICALL Java_com_qeeplay_frameworks_LuaJavaBridge_callLuaGlobalFunctionWithString
  (JNIEnv *env, jclass cls, jstring luaFunctionName, jstring value)
{
    const char *luaFunctionName_ = env->GetStringUTFChars(luaFunctionName, 0);
    const char *value_ = env->GetStringUTFChars(value, 0);
    int ret = LuaJavaBridge::callLuaGlobalFunction(luaFunctionName_, value_);
    env->ReleaseStringUTFChars(luaFunctionName, luaFunctionName_);
    env->ReleaseStringUTFChars(value, value_);
    return ret;
}
JNIEXPORT jint JNICALL Java_com_qeeplay_frameworks_LuaJavaBridge_callLuaGlobalFunctionWithRaw
  (JNIEnv *env, jclass cls, jstring luaFunctionName, jbyteArray value)
{
    const char *luaFunctionName_ = env->GetStringUTFChars(luaFunctionName, 0);
    const char *value_ = (const char*)env->GetByteArrayElements(value, 0);
	for(int i = 0 ; i < strlen(value_); ++i)
	{
		LOGD("value %02d, %d", i, value_[i]);
	}
	LOGD("value_len=%d", env->GetArrayLength(value));
    int ret = LuaJavaBridge::callLuaGlobalFunction(luaFunctionName_, value_, env->GetArrayLength(value));
    env->ReleaseStringUTFChars(luaFunctionName, luaFunctionName_);
	env->ReleaseByteArrayElements(value, (jbyte*)value_, 0);
    return ret;
}

JNIEXPORT jint JNICALL Java_com_qeeplay_frameworks_LuaJavaBridge_retainLuaFunction
  (JNIEnv *env, jclass cls, jint luaFunctionId)
{
    return LuaJavaBridge::retainLuaFunctionById(luaFunctionId);
}

JNIEXPORT jint JNICALL Java_com_qeeplay_frameworks_LuaJavaBridge_releaseLuaFunction
  (JNIEnv *env, jclass cls, jint luaFunctionId)
{
    return LuaJavaBridge::releaseLuaFunctionById(luaFunctionId);
}

} // extern "C"


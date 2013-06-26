
package com.qeeplay.frameworks;

public class LuaJavaBridge
{
	
	/**cocos2d-x 在 Android 上以两个线程来运行，分别是负责图像渲染的 GL 线程和负责 Android 系统用户界面的 UI 线程。

	在 cocos2d-x 启动后，Lua 代码将由 GL 线程调用，因此从 Lua 中调用的 Java 方法如果涉及到系统用户界面的显示、
	更新操作，那么就必须让这部分代码切换到 UI 线程上去运行。
	反之亦然，从 Java 调用 Lua 代码时，需要让这个调用在 GL 线程上执行，否则 Lua 代码虽然执行了，但会无法更新 
	cocos2d-x 内部状态。**/
	
    public static native int callLuaFunctionWithString(int luaFunctionId, String value);
    public static native int callLuaGlobalFunctionWithString(String luaFunctionName, String value);
    public static native int callLuaGlobalFunctionWithRaw(String luaFunctionName, byte[] raw);
    public static native int retainLuaFunction(int luaFunctionId);
    public static native int releaseLuaFunction(int luaFunctionId);
}

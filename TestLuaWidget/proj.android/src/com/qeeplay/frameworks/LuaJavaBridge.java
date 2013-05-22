
package com.qeeplay.frameworks;

public class LuaJavaBridge
{
	
	/**cocos2d-x �� Android ���������߳������У��ֱ��Ǹ���ͼ����Ⱦ�� GL �̺߳͸��� Android ϵͳ�û������ UI �̡߳�

	�� cocos2d-x ������Lua ���뽫�� GL �̵߳��ã���˴� Lua �е��õ� Java ��������漰��ϵͳ�û��������ʾ��
	���²�������ô�ͱ������ⲿ�ִ����л��� UI �߳���ȥ���С�
	��֮��Ȼ���� Java ���� Lua ����ʱ����Ҫ����������� GL �߳���ִ�У����� Lua ������Ȼִ���ˣ������޷����� 
	cocos2d-x �ڲ�״̬��**/
	
    public static native int callLuaFunctionWithString(int luaFunctionId, String value);
    public static native int callLuaGlobalFunctionWithString(String luaFunctionName, String value);
    public static native int callLuaGlobalFunctionWithRaw(String luaFunctionName, byte[] raw);
    public static native int retainLuaFunction(int luaFunctionId);
    public static native int releaseLuaFunction(int luaFunctionId);
}

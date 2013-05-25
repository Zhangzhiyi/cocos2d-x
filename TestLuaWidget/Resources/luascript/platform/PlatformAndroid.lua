-- android平台
local luaj = require "luascript/luaj"
local CLASS_NAME= "org/cocos2dx/hellolua/HelloLua"
local PlatformAndroid = class("PlatformAndroid", PlatformBase)

function PlatformAndroid:ctor()
	PlatformAndroid.super.ctor(self)
	
	-- 测试调用java方法
	local args = {
	  123,
	  123.4,
	  true,
	  false,
	  "kao"
	}
	local sig = "(IFZZLjava/lang/String;)Ljava/lang/String;"
	local ok, result = luaj.callStaticMethod(CLASS_NAME, "testLuaCallJava", args, sig)
	if ok == true then
		CCLuaLog(result)
	end		
	
	local function javaCallbackLua(callback)
		CCLuaLog(callback)
	end
	local args2 = {
		javaCallbackLua,--将function传递到Java层,function当作int型参数传递
		123,
		"kao",
		true
	}
	local sig2 = "(IILjava/lang/String;Z)V"
	local ok2 = luaj.callStaticMethod(CLASS_NAME, "testLuaCallJava2", args2, sig2)
	if ok2 == true then
		CCLuaLog("call testLuaCallJava2 successful!")
	end
end
function PlatformAndroid:test()
	CCLuaLog("PlatformAndroid")
end
return PlatformAndroid
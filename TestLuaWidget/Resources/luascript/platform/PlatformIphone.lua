local PlatformIphone = class("PlatformIphone", PlatformBase)

function PlatformIphone:ctor()
	PlatformIphone.super.ctor(self)
end
function PlatformIphone:test()
	CCLuaLog("PlatformIphone")
end
return PlatformIphone
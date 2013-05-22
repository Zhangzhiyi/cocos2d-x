local PlatformWin = class("PlatformWin", PlatformBase)

function PlatformWin:ctor()
	PlatformWin.super.ctor(self)
	
end
function PlatformWin:test()
	CCLuaLog("PlatformWin")
end

return PlatformWin
require "luascript/functions"
require "luascript/UITools"
require "luascript/VisibleRect"
require "luascript/platform/PlatformBase"
require "luascript/widget/CCNodeExtend"
require "luascript/widget/ContainerWidget"
require "luascript/scene/StandardSceneMan"
require "luascript/dialog/DialogLayerMan"
require "luascript/widget/CheckBox"
require "luascript/widget/CheckBoxGroup"
require "luascript/widget/ImageButton"
require "luascript/widget/TextButton"
require "luascript/widget/ProgressBar"
require "luascript/widget/ScrollView"
require "luascript/widget/TableView"
require "luascript/widget/StyleLabelGroup"
require "luascript/widget/Spinner"
require "luascript/platform/PlatformBase"
require "luascript/platform/PlatformAndroid"
require "luascript/platform/PlatformIphone"
require "luascript/platform/PlatformWin"

-- for CCLuaEngine traceback
function __G__TRACKBACK__(msg)
    print("----------------------------------------")
    print("LUA ERROR: " .. tostring(msg) .. "\n")
    print(debug.traceback())
    print("----------------------------------------")
end
Global = {}
function Global.CreateTestSceneMan()
    return (require "luascript/scene/TestSceneMan").new()
end
local function main()
    -- avoid memory leak
    collectgarbage("setpause", 100)
    collectgarbage("setstepmul", 5000)
	
	local url = "http://httpbin.org/ip"
	local function callback(event)
		local request = event.request
		if request:getErrorCode() == 0 and request:getResponseStatusCode() == 200 then
			local length = request:getResponseDataLength()
			local result = request:getResponseDataLua()
			CCLuaLog(result)
		end
	end
	local request = CCHTTPRequest:createWithUrlLua(callback, url, kCCHTTPRequestMethodGET);
	request:start()
	
	CCSpriteFrameCache:sharedSpriteFrameCache():addSpriteFramesWithFile("base.plist")
	
	local testSceneMan = Global.CreateTestSceneMan()
	testSceneMan:run()
end	
xpcall(main, __G__TRACKBACK__)

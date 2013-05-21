require "functions"
require "UITools"
require "VisibleRect"
require "platform/PlatformBase"
require "widget/CCNodeExtend"
require "widget/ContainerWidget"
require "scene/StandardSceneMan"
require "dialog/DialogLayerMan"
require "widget/CheckBox"
require "widget/CheckBoxGroup"
require "widget/ImageButton"
require "widget/TextButton"
require "widget/ProgressBar"
require "widget/ScrollView"
require "widget/TableView"
require "widget/StyleLabelGroup"
require "widget/Spinner"
require "platform/PlatformBase"
require "platform/PlatformAndroid"
require "platform/PlatformIphone"
require "platform/PlatformWin"

-- for CCLuaEngine traceback
function __G__TRACKBACK__(msg)
    print("----------------------------------------")
    print("LUA ERROR: " .. tostring(msg) .. "\n")
    print(debug.traceback())
    print("----------------------------------------")
end
Global = {}
function Global.CreateTestSceneMan()
    return (require "scene/TestSceneMan").new()
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

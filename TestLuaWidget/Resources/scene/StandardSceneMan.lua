StandardSceneMan = class("StandardSceneMan")
--构造函数
function StandardSceneMan:ctor()
	
	self._mainScene = CCScene:create()
	self._mainLayer = CCLayer:create()--CCLayerColor:create( ccc4(0,0,255, 255) )
	self._mainScene:addChild( self._mainLayer )
    local function handler(event)
        if event == "enter" then
            self:onEnterMainScene()
        elseif event == "exit" then
            self:onExitMainScene()
        end
    end
    self._mainScene:registerScriptHandler(handler)
	
	local function keyPadHandler(event)	
		if "backClicked" == event then	
			CCLuaLog("back")
		    self:onKeyBackClicked()
		end
	end		
	self._mainLayer:registerScriptKeypadHandler( keyPadHandler )
	self._mainLayer:setKeypadEnabled(true)
	self._dialogList = {}	
	self._nDialogPriority = kDialogHandlerPriority
end

function StandardSceneMan:LOGD( ... )
    LOGD( self.classname, ... )
end

--主场景进入
function StandardSceneMan:onEnterMainScene()
	CCDirector:sharedDirector():purgeCachedData()
    local function tick()
            self:update()
    end
    self._updateEntry = CCDirector:sharedDirector():getScheduler():scheduleScriptFunc(tick, 0, false)
end
--主场景退出
function StandardSceneMan:onExitMainScene()
	if self._updateEntry then
	    CCDirector:sharedDirector():getScheduler():unscheduleScriptEntry(self._updateEntry)
		self._updateEntry = nil
	end
end

function StandardSceneMan:getMainScene()
	return self._mainScene
end

function StandardSceneMan:run()
    CCDirector:sharedDirector():runWithScene(self._mainScene)
end
function StandardSceneMan:replace()
    CCDirector:sharedDirector():replaceScene(self._mainScene)
end
--每帧更新
function StandardSceneMan:update()
   
end

function StandardSceneMan:keyBackCloseLastDialog()
	if #self._dialogList > 0 then
		local dialog = self._dialogList[#self._dialogList]
		dialog:onKeyBackClicked()
		return true
	end
	return false
end	
-- 返回键响应
function StandardSceneMan:onKeyBackClicked()
	if not self:keyBackCloseLastDialog() then
		CCDirector:sharedDirector():endToLua()
		--[[local function func1()
			self._mainScene:runAction(CCSequence:createWithTwoActions(
			CCDelayTime:create(0.2),
			CCCallFuncN:create(function()
				CCDirector:sharedDirector():endToLua()
			end)
			))
		end
		self.dialog = Global.createAlertDialog(self, {strMessage = GameLangs.dialog_exitGame:getLang(), isHasBtn1 = true, func1 = func1, isHasBtn2 = true})--]]
	end
end
-- 获得对话框的最新优先级
function StandardSceneMan:getNewDialogPriority()
	if #self._dialogList > 0 then
		self._nDialogPriority = self._nDialogPriority - 1
	else
		self._nDialogPriority = kDialogHandlerPriority
	end

	return self._nDialogPriority
end
function StandardSceneMan:reorderDialog(dialog)
	for i,v in ipairs(self._dialogList) do
		if v == dialog then		
			v:setLayerTouchPriority(kCCMenuHandlerPriority - 1)
			self._mainScene:reorderChild(v._mainLayer, INT_MAX)
		else 
			v:setLayerTouchPriority(kCCMenuHandlerPriority)
			self._mainScene:reorderChild(v._mainLayer, INT_MAX - 1)
		end
	end
end
-- 注册对话框
function StandardSceneMan:registerDialog( dialog )
	table.insert( self._dialogList, dialog)
end
-- 注销对话框
function StandardSceneMan:unregisterDialog( dialog )
    local idx = 0
    for i,v in ipairs(self._dialogList) do
        if v == dialog then
            idx = i
            break
        end
    end
    if idx > 0 then
	    table.remove(self._dialogList, idx)
	end
end	

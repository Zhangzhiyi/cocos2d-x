kDialogHandlerPriority = kCCMenuHandlerPriority - 1
DialogLayerMan = class("DialogLayerMan")
-- 设置ccmenu的优先级比对话框优先级要高
function DialogLayerMan.setSuperDialogPriority( ccmenu, nPriority )
	nPriority = nPriority or kDialogHandlerPriority -1
    ccmenu:registerScriptHandler(
	    function ( event )
	        if event.name == "enter" then
	            ccmenu._updateEntry = CCDirector:sharedDirector():getScheduler():scheduleScriptFunc(
                    function()
                        ccmenu:setHandlerPriority(nPriority)
                        if ccmenu._updateEntry ~= nil then
                            CCDirector:sharedDirector():getScheduler():unscheduleScriptEntry(ccmenu._updateEntry)
                            ccmenu._updateEntry = nil
                        end
                    end
                    , 0, false)
	            --ccmenu:setHandlerPriority(kDialogHandlerPriority-1)
	        elseif event.name == "exit" then
	            if ccmenu._updateEntry ~= nil then
                    CCDirector:sharedDirector():getScheduler():unscheduleScriptEntry(ccmenu._updateEntry)
                end
	        end
    	end
    )
end
function DialogLayerMan:createSuperMenu()
	local menu = CCMenu:create()
	DialogLayerMan.setSuperDialogPriority(menu, self._menuPriority)
	return menu
end
function DialogLayerMan:ctor( standardSceneMan, strTitle, bAutoFadeIn)
	--self._mainLayer = CCLayer:create()--CCLayerColor:create(ccc4(0,0,0,0))-- CCLayer:create()	
	self._mainLayer = ClipLayer:create()
	self._mainLayer:ignoreAnchorPointForPosition(false)
	self._mainLayer:setAnchorPoint(CCPointZero)
	
	self._strTitle = strTitle or "DialogLayerMan"
	if bAutoFadeIn == nil then
		bAutoFadeIn = true
	end
	if bAutoFadeIn then
		self._mainLayer:runAction( CCFadeTo:create( 0.3, 166 ) )
	end
	self._standardSceneMan = standardSceneMan
	
    local function handler ( event )
        if event == "enter" then
            self:onEnterLayer()
        elseif event == "exit" then
            self:onExitLayer()
        end
    end
	self._mainLayer:registerScriptHandler( handler)	
		
	self._standardSceneMan._mainScene:addChild( self._mainLayer, INT_MAX )	
end
function DialogLayerMan:setPosition(point)
	self._mainLayer:setPosition(point)
end
function DialogLayerMan:registerScriptTouchHandler(bMultiTouches, nTouchPriority, bSwallows)
	--self._menuPriority = self._standardSceneMan:getNewDialogPriority() - 1
	local function onTouch(eventType, x, y)
        if eventType == "began" then
            return self:onTouchBegan(x, y)
        elseif eventType == "moved" then
            return self:onTouchMoved(x, y)
        elseif  eventType == "ended" then
            return self:onTouchEnded(x, y)
		elseif eventType == "cancelled" then						
			return self:onTouchCancelled(x, y)
        end
    end		
	self._mainLayer:registerScriptTouchHandler( onTouch, bMultiTouches, nTouchPriority, bSwallows)
	self._mainLayer:setTouchEnabled(true)
end
function DialogLayerMan:unregisterScriptTouchHandler()
	self._mainLayer:setTouchEnabled(false)
	self._mainLayer:unregisterScriptTouchHandler()
end
--改变触摸优先级，重新注册
function DialogLayerMan:setLayerTouchPriority(nTouchPriority)
	self:unregisterScriptTouchHandler()
	self:registerScriptTouchHandler(false, nTouchPriority, true)
end	
function DialogLayerMan:isTouchInside(x, y)
	local bBox = self._mainLayer:getViewRect()
	local touchLocation = self._mainLayer:convertToWorldSpace(self._mainLayer:convertToNodeSpace(ccp(x, y)))
	local bInside = bBox:containsPoint(touchLocation)
	return bInside
end
function DialogLayerMan:onTouchBegan(x, y)
	
	local bInside = self:isTouchInside(x, y)
	if bInside then
	    CCLuaLog(self._strTitle .. ":onTouchBegan")
		self._standardSceneMan:reorderDialog(self)
	end		
	return bInside
end
function DialogLayerMan:onTouchMoved(x, y)

end
function DialogLayerMan:onTouchEnded(x, y)

end
function DialogLayerMan:onTouchCancelled(x, y)

end
function DialogLayerMan:onEnterLayer()
	self._standardSceneMan:registerDialog( self )
	--注册触摸事件
	self:registerScriptTouchHandler(false, kDialogHandlerPriority, true)
	
end
function DialogLayerMan:onExitLayer()
	self._standardSceneMan:unregisterDialog( self )
end
function DialogLayerMan:close()
	self._mainLayer:removeFromParentAndCleanup( true )
end
function DialogLayerMan:onKeyBackClicked()
	self:close()
	return true
end

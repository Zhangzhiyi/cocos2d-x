CCNodeExtend = class("CCNodeExtend")

--[[
	控件容器类
					key					描述  						类型
	options	= 	{
					isEnabled			是否可用						booleans
				}					
--]]
function CCNodeExtend:ctor(options)
	self._node = CCNode:create()
    self._layer = CCLayer:create()
    self._node:addChild(self._layer)
	--设置默认锚点为(0.5， 0.5)
	--[[当CCNode没有设置ContentSize的时候,默认的ContentSize是(0, 0),
	当ContentSize是(0, 0)的时候，改变锚点是没有效果的，这种情况可以将CCNode看成是一个点--]]
	self:setAnchorPoint(CCPoint05)	
	
	--enable默认为true
	--注意：self._bEnabled = options.isEnabled or true ,当options.isEnabled为false的时候，还是返回true，错误
	if options then
		if options.isEnabled ~= nil then
			self._bEnabled = options.isEnabled
		else 
			self._bEnabled = true
		end	
	else 
		self._bEnabled = true
	end
	
end

function CCNodeExtend:registerScriptHandler(handler)
	if not handler then
		handler = function(event)
			if event == "enter" then
				self:onEnter()
			elseif event == "exit" then
				self:onExit()
			elseif event == "enterTransitionFinish" then
				self:onEnterTransitionFinish()
			elseif event == "exitTransitionStart" then
				self:onExitTransitionStart()		
			end
		end
	end
	self._node:registerScriptHandler(handler)
end
function CCNodeExtend:unregisterScriptHandler()
	self._node:unregisterScriptHandler()
end
function CCNodeExtend:setTouchEnabled(bTouch)
	self._layer:setTouchEnabled(bTouch)
end
function CCNodeExtend:isTouchEnabled()
	self._layer:isTouchEnabled()
end
function CCNodeExtend:setTouchPriority(nPriority)
	if self:isTouchEnabled() then
		self._layer:setTouchPriority(nPriority)
	end		
end
function CCNodeExtend:registerScriptTouchHandler(nTouchPriority, bSwallowsTouches)
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
	self._layer:registerScriptTouchHandler(onTouch, false, nTouchPriority, bSwallowsTouches)
end
function CCNodeExtend:addChild(child, zOrder)
	if zOrder then
		self._layer:addChild(child, zOrder)
	else 
		self._layer:addChild(child)
	end				
end
--[[function CCNodeExtend:addChild(child, zOrder)		
	self._layer:addChild(child, zOrder)
end--]]
function CCNodeExtend:setEnabled(bEnabled)
    if self._bEnabled ~= bEnabled then
        self._bEnabled = bEnabled	
    end
end
function CCNodeExtend:isEnabled()
	return self._bEnabled
end
function CCNodeExtend:isVisible()
	return self._node:isVisible()
end
function CCNodeExtend:setVisible(bVisible)
	self._node:setVisible(bVisible)
end
function CCNodeExtend:boundingBox()
	return self._node:boundingBox()
end	
function CCNodeExtend:setContentSize(size)
	self._layer:setContentSize(size)
	self._node:setContentSize(size)
end
function CCNodeExtend:getContentSize()
	return self._node:getContentSize()
end
function CCNodeExtend:setAnchorPoint(point)
	self._node:setAnchorPoint(point)
end
--[[function CCNodeExtend:setPosition(x,y)
	self._node:setPosition(ccp(x, y))
end--]]
function CCNodeExtend:setPosition(point)
	self._node:setPosition(point)
end
function CCNodeExtend:setScale(nScale)
	self._node:setScale(nScale)
end
function CCNodeExtend:getScale()
	return self._node:getScale()
end
function CCNodeExtend:setScaleX(nScaleX)
	self._node:setScaleX(nScaleX)
end
function CCNodeExtend:getScaleX()
	self._node:getScaleX()
end
function CCNodeExtend:setScaleY(nScaleY)
	self._node:setScaleY(nScaleY)
end	
function CCNodeExtend:getScaleY()
	self._node:getScaleY()
end
function CCNodeExtend:removeFromParentAndCleanup(bCleanup)
    self._node:removeFromParentAndCleanup(bCleanup)
end
function CCNodeExtend:onEnter()

end
function CCNodeExtend:onExit()

end
function CCNodeExtend:onEnterTransitionFinish()

end
function CCNodeExtend:onExitTransitionStart()

end
function CCNodeExtend:isTouchInside(x, y)
	local touchLocation = ccp( x,y )
    --CCLuaLog(string.format("x:%0.2f, y:%0.2f", x, y))
    touchLocation = self._node:getParent():convertToNodeSpace(touchLocation)
    --CCLuaLog(string.format("convert x:%0.2f, y:%0.2f", touchLocation.x, touchLocation.y))
    local bBox = self:boundingBox();
    --CCLuaLog(string.format("bbox x:%0.2f, y:%0.2f, width:%d, height:%d", bBox.origin.x, bBox.origin.y, bBox.size.width, bBox.size.height))
    local bInside = bBox:containsPoint(touchLocation)
    return bInside
end
function CCNodeExtend:onTouchBegan(x, y)
		
end
function CCNodeExtend:onTouchMoved(x, y)

end
function CCNodeExtend:onTouchEnded(x, y)

end
function CCNodeExtend:onTouchCancelled(x, y)

end
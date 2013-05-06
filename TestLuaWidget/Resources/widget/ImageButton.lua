ImageButton = class("ImageButton", CCNodeExtend)
function ImageButton:ctor(options)
	ImageButton.super.ctor(self)
	
	self._normalSpriteFrame = options.normalSfName and spriteFrameByName(options.normalSfName)
	self._pressedSpriteFrame = options.pressedSfName and spriteFrameByName(options.pressedSfName)
	self._disabledSpriteFrame = options.disabledSfName and spriteFrameByName(options.disabledSfName)
	
	self._bEnabled = options.isEnabled	or true
	self._bPressed = options.isPressed or false
	self._clickFunc = options.onClickEvent
	self._sprite = CCSprite:create()
	
	self:updateState()
	self._sprite:setPosition(self._sprite:getContentSize().width/2, self._sprite:getContentSize().height/2)
	self:addChild(self._sprite)
	
	self._nWidth = self._sprite:getContentSize().width
	self._nHeight = self._sprite:getContentSize().height
	self:setContentSize(CCSize(self._nWidth, self._nHeight))			
	self._nTouchPriority = options.nTouchPriority or -129
    self:registerScriptTouchHandler(self._nTouchPriority, true)
	self:setTouchEnabled(true)
	
end
function ImageButton:updateState()
	if self._bEnabled then
		if self._bPressed then
			self._sprite:setDisplayFrame(self._pressedSpriteFrame)
		else 
			self._sprite:setDisplayFrame(self._normalSpriteFrame)
		end
	else
		if	self._disabledSpriteFrame then 
			self._sprite:setDisplayFrame(self._disabledSpriteFrame)
		end
	end
end
function ImageButton:isEnabled()
	return self._bEnabled
end	
function ImageButton:setEnabled(bEnabled)
	if self._bEnabled ~= bEnabled then
		self._bEnabled = bEnabled
		self:updateState()
	end
end
function ImageButton:isPressed()
	return self._bPressed
end
function ImageButton:setPressed(bPressed)
	if self._bPressed ~= bPressed then
		self._bPressed = bPressed
		self:updateState()
	end
end
function ImageButton:onTouchBegan(x, y)
	if ((not self._bEnabled) or (not self:isVisible()) or (not self:isTouchInside(x, y)))then
		return false
	end
    --CCLuaLog("onTouchBegan isTouchInside")
	self:setPressed(true)
	return true
end
function ImageButton:onTouchMoved(x, y)

end
function ImageButton:onTouchEnded(x, y)
	self:setPressed(false)
    if self:isTouchInside(x, y) then
        --CCLuaLog("onTouchEnded isTouchInside")
		if self._clickFunc then
			self._clickFunc()
		end	
    end
end
function ImageButton:onTouchCanelled(x, y)
	self:setPressed(false)	
	
end
ImageButton = class("ImageButton", CCNodeExtend)
--[[
		图片按钮
					key				描述  							类型
	options = {	
				bEnabled			是否可用						booleans
				normalSfName		正常状态SpriteFrameName			string
				pressedSfName		按下状态SpriteFrameName			string
				disabledSfName		不可用状态SpriteFrameName		string				
				onClickEvent		点击后的回调方法				function
				nTouchPriority		触摸事件优先级					number
			  }
				
--]]
function ImageButton:ctor(options)
	ImageButton.super.ctor(self, options)
	
	self._normalSpriteFrame = options.normalSfName and spriteFrameByName(options.normalSfName)
	self._pressedSpriteFrame = options.pressedSfName and spriteFrameByName(options.pressedSfName)
	self._disabledSpriteFrame = options.disabledSfName and spriteFrameByName(options.disabledSfName)
			
	self._bPressed = false
	
	self._clickFunc = options.onClickEvent
	self._sprite = CCSprite:create()
	
	self:updateState()
	self._sprite:setPosition(self._sprite:getContentSize().width/2, self._sprite:getContentSize().height/2)
	self:addChild(self._sprite)
	
	self._nWidth = self._sprite:getContentSize().width
	self._nHeight = self._sprite:getContentSize().height
	self:setContentSize(CCSize(self._nWidth, self._nHeight))			
	self._nTouchPriority = options.nTouchPriority or 0
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
function ImageButton:setEnabled(bEnabled)
	ImageButton.super.setEnabled(bEnabled)
	self:updateState()
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
	if ((not self:isEnabled()) or (not self:isVisible()) or (not self:getAbsoluteVisible()) or (not self:isTouchInside(x, y)))then
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
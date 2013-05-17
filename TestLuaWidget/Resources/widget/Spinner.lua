Spinner = class("Spinner", CCNodeExtend)

function Spinner:ctor(options)
	Spinner.super.ctor(self)
	self._normalSpriteFrame = options.normalSfName and spriteFrameByName(options.normalSfName)
	self._pressedSpriteFrame = options.pressedSfName and spriteFrameByName(options.pressedSfName)
	self._disabledSpriteFrame = options.disabledSfName and spriteFrameByName(options.disabledSfName)	
	
	self._sprite = CCSprite:create()
	self._sprite:setDisplayFrame(self._normalSpriteFrame)
	self._sprite:setPosition(self._sprite:getContentSize().width/2, self._sprite:getContentSize().height/2)
	self:addChild(self._sprite)
	
	self._nWidth = self._sprite:getContentSize().width
	self._nHeight = self._sprite:getContentSize().height
	self:setContentSize(CCSize(self._nWidth, self._nHeight))			
	self._nTouchPriority = options.nTouchPriority or 0
    self:registerScriptTouchHandler(self._nTouchPriority, true)
	self:setTouchEnabled(true)
end
function Spinner:onTouchBegan(x, y)
	if ((not self:isEnabled()) or (not self:isVisible()) or (not self:isTouchInside(x, y)))then
		return false
	end		
	local point = self._sprite:convertToNodeSpace(ccp(x, y))
	local x = point.x
	local y = point.y
	if x >= 145 and x <= 180 then
		self._sprite:setDisplayFrame(self._pressedSpriteFrame)
	end
	return true
end
function Spinner:onTouchMoved(x, y)
	
	
end
function Spinner:onTouchEnded(x, y)
    self._sprite:setDisplayFrame(self._normalSpriteFrame)
	
end

Spinner = class("Spinner", CCNodeExtend)

function Spinner:ctor(options)
	Spinner.super.ctor(self)
	self._normalSpriteFrame = options.normalSfName and spriteFrameByName(options.normalSfName)
	self._pressedSpriteFrame = options.pressedSfName and spriteFrameByName(options.pressedSfName)
	self._disabledSpriteFrame = options.disabledSfName and spriteFrameByName(options.disabledSfName)
	
	
end
function Spinner:onTouchBegan(x, y)
	if ((not self._bEnabled) or (not self:isVisible()) or (not self:isTouchInside(x, y)))then
		return false
	end		
	return true
end
function Spinner:onTouchMoved(x, y)
	
	
end
function Spinner:onTouchEnded(x, y)
    
	
end

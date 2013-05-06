ProgressBar = class("ProgressBar", CCNodeExtend)

function ProgressBar:ctor(options)
	ProgressBar.super.ctor(self)
	
	self._bgSprite = CCSprite:createWithSpriteFrameName(options.backgroundSprite)
	self._progressSprite = CCSprite:createWithSpriteFrameName(options.progressSprite)
	
	self._bgSprite:setPosition(self._bgSprite:getContentSize().width/2, self._bgSprite:getContentSize().height/2)
	self._progressSprite:setPosition(self._bgSprite:getPosition())
	--self._progressSprite:setPosition(5, self._bgSprite:getPositionY())	
	--self._progressSprite:setAnchorPoint(ccp(0, 0.5))
	self:addChild(self._bgSprite)
	self:addChild(self._progressSprite)	
	self:setAnchorPoint(CCPoint05)
	local maxRect = self:CCRectUnion(self._bgSprite:boundingBox(), self._progressSprite:boundingBox())
	self:setContentSize(maxRect.size)
	
	self._nProgressWidth = self._progressSprite:getContentSize().width
	self._nProgressPx = self._progressSprite:getPositionX()
	
	self._nPercent = options.nPercent or 0
	self:setPercent(self._nPercent)
end	
function ProgressBar:CCRectUnion(bgRect, progressRect)
	local x = math.min(bgRect:getMinX(), progressRect:getMinX())
	local y = math.min(bgRect:getMinY(), progressRect:getMinY())
	local width = math.max(bgRect:getMaxX(), progressRect:getMaxY())
	local height = math.max(bgRect:getMaxY(), progressRect:getMaxY())
	return CCRect(x, y, width, height)
end
function ProgressBar:setPercent(percent)
	
	assert(percent, "percent is nil")
	assert(type(percent) == "number", "percent is not number")
	local rect = self._progressSprite:getTextureRect();
	local percentWidth = self._nProgressWidth * percent
	rect = CCRect(rect.origin.x , rect.origin.y, percentWidth, rect.size.height)
	self._progressSprite:setTextureRect(rect, self._progressSprite:isTextureRectRotated(), rect.size)
	
	local anchorX = self._progressSprite:getAnchorPoint().x
	self._progressSprite:setPosition(ccp(self._nProgressPx - ((self._nProgressWidth - percentWidth) * anchorX), self._progressSprite:getPositionY()))
	
	self._nPercent = percent
end
function ProgressBar:getPercent()
	return self._nPercent
end



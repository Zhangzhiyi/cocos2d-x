ProgressBar = class("ProgressBar", CCNodeExtend)
--[[
	�������ؼ���
					key					����  						����
	optiongs = 	{
					backgroundSprite	����SpriteFrameName			string
					progressSprite		������SpriteFrameName		string
					percent				Ĭ�ϵĽ���ֵ(0 ~ 1)			number
				}
--]]
function ProgressBar:ctor(options)
	ProgressBar.super.ctor(self, options)
	
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
	
	self._nPercent = options.percent or 0
	self:setPercent(self._nPercent)
end	
function ProgressBar:CCRectUnion(bgRect, progressRect)
	local x = math.min(bgRect:getMinX(), progressRect:getMinX())
	local y = math.min(bgRect:getMinY(), progressRect:getMinY())
	local width = math.max(bgRect:getMaxX(), progressRect:getMaxY())
	local height = math.max(bgRect:getMaxY(), progressRect:getMaxY())
	return CCRect(x, y, width, height)
end

function ProgressBar:getPercent()
	return self._nPercent
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
function ProgressBar:setPercentDuration(nPercent, nDuration)
	self._nDuration = nDuration or 1.2
	self._nElapsed = 0
	self._nTargetPercent = nPercent
	self._nDiffPercent = nPercent - self._nPercent
	local function tick(dt)
		self:updatePercent(dt)
	end
	if self._updateEntry then
		CCDirector:sharedDirector():getScheduler():unscheduleScriptEntry(self._updateEntry)
		self._updateEntry = nil
	end
	self._updateEntry = CCDirector:sharedDirector():getScheduler():scheduleScriptFunc(tick, 0, false)
end
function ProgressBar:updatePercent(dt)
	self._nElapsed = self._nElapsed + dt
	
	if self._nElapsed >= self._nDuration then
		if self._updateEntry then
			CCDirector:sharedDirector():getScheduler():unscheduleScriptEntry(self._updateEntry)
			self._updateEntry = nil
		end
		self:setPercent(self._nTargetPercent)
	end
		
	local percent = self._nDiffPercent * (dt/self._nDuration) + self._nPercent
	self:setPercent(percent)
end


ScrollView = class("ScrollView", ContainerWidget)
--[[
	可滑动容器类
						key					描述  							类型
	optiongs = 	{	
					nDirection			滑动方向(默认为垂直方向)			number
					viewSize			可视部分窗口大小					CCSize
					bBounceable			是否有弹性效果						booleans
					nTouchPriority		触摸事件优先级						number
				}
--]]

ScrollView.DIRECTION_VERTICAL   = 1
ScrollView.DIRECTION_HORIZONTAL = 2
function ScrollView:ctor(options)
	ScrollView.super.ctor(self)
	self._nDirection = options.nDirection or ScrollView.DIRECTION_VERTICAL		
	self._viewSize = options.viewSize or VisibleRect._winSize
	self:setViewSize(self._viewSize)
	self._nTouchPriority = options.nTouchPriority or -200
	self:registerScriptTouchHandler(self._nTouchPriority, true)
	self:setTouchEnabled(true)
	
	self._container = options.container or CCLayer:create()
	self._container:ignoreAnchorPointForPosition(false)
	self._container:setAnchorPoint(CCPointZero)
	self._container:setPosition(CCPointZero)
	self:addChild(self._container)	
	
	if options.bBounceable ~= nil then
		self._bBounceable = options.bBounceable
	else 
		self._bBounceable = true
	end
		
end
function ScrollView:getContainer()
	return self._container
end
function ScrollView:setContainer(container)
	if not self._container then
		return
	end
	self._container:removeAllChildrenWithCleanup(true)
	self._container:removeFromParentAndCleanup(true)
	self._container = nil
	
	self._container = container	
	self._container:ignoreAnchorPointForPosition(false)
	self._container:setAnchorPoint(CCPointZero)
	self._container:setPosition(CCPointZero)
	self:addChild(self._container)
		
end

function ScrollView:setContainerContentSize(size)
	if self._container then
		self._container:setContentSize(size)
	end
end
function ScrollView:setBounceable(bBounceable)
	self._bBounceable = bBounceable
end
function ScrollView:getBounceable()
	return self._bBounceable
end
function ScrollView:updateInset()
	local INSET_RATIO = 0.2
	self._maxInset = self:maxContainerOffset()
	self._maxInset = ccp(self._maxInset.x + self._viewSize.width * INSET_RATIO,
			self._maxInset.y + self._viewSize.height * INSET_RATIO)	
	self._minInset = self:minContainerOffset()
	self._minInset = ccp(self._minInset.x - self._viewSize.width * INSET_RATIO,
			self._minInset.y - self._viewSize.height * INSET_RATIO)
end
function ScrollView:isTouchMoved()
	return self._bTouchMoved
end
function ScrollView:onTouchBegan(x, y)
	if ((not self:isVisible()) or (not self:isTouchInside(x, y)))then
		return false
	end
	self._bTouchMoved = false
	self._touchPoint = self._layer:convertToNodeSpace(ccp(x, y))
	return true
end
function ScrollView:onTouchMoved(x, y)
	
	local movePoint = self._layer:convertToNodeSpace(ccp(x, y))
	local distancePoint = ccpSub(movePoint, self._touchPoint)
	local distance = 0
	if self._nDirection == ScrollView.DIRECTION_VERTICAL then
		distancePoint = ccp(0, distancePoint.y)
		distance = distancePoint.y
	elseif self._nDirection == ScrollView.DIRECTION_HORIZONTAL then
		distancePoint = ccp(distancePoint.x ,0)
		distance = distancePoint.x
	end
		
	if not self._bTouchMoved and math.abs(distance) < 10 then
		return
	end
	
	if not self._bTouchMoved then
		distancePoint = CCPointZero
	end
	self._bTouchMoved = true
	self._touchPoint = movePoint
	if self:isTouchInside(x, y) then
		local newX = self._container:getPositionX() + distancePoint.x
		local newY = self._container:getPositionY() + distancePoint.y
		self:setContentOffset(ccp(newX, newY))
	end		
end
function ScrollView:onTouchEnded(x, y)
	if self._bBounceable then
		local miniOffset = self:minContainerOffset()
		local maxOffset = self:maxContainerOffset()
		--local curPos = self._container:getPosition()		
		local curPosX = self._container:getPositionX()
		local curPosY = self._container:getPositionY()
		if self._nDirection == ScrollView.DIRECTION_VERTICAL then
			curPosY = math.min(curPosY, maxOffset.y)
			curPosY = math.max(curPosY, miniOffset.y)
		elseif self._nDirection == ScrollView.DIRECTION_HORIZONTAL then
			curPosX = math.max(curPosX, miniOffset.x)
			curPosX = math.min(curPosX, maxOffset.x)
		end
		if (self._container:getPositionX() ~= curPosX) or (self._container:getPositionY() ~= curPosY) then
			local move = CCMoveTo:create(0.15, ccp(curPosX, curPosY))
			self._container:runAction(move)
		end
	end
	self._bTouchMoved = false
end
function ScrollView:onTouchCancelled(x, y)
	self._bTouchMoved = false
end
function ScrollView:setContentOffset(pointOffset)
	if not self._bBounceable then
		local miniOffset = self:minContainerOffset()
		local maxOffset = self:maxContainerOffset()
		pointOffset.x = math.max(miniOffset.x, math.min(maxOffset.x, pointOffset.x))
		pointOffset.y = math.max(miniOffset.y, math.min(maxOffset.y, pointOffset.y))
	end
		
	self._container:setPosition(pointOffset)
end
function ScrollView:getContentOffset()
	return self._container:getPosition()
end
function ScrollView:maxContainerOffset()
	return ccp(0, 0)
end
function ScrollView:minContainerOffset()
	return ccp(self._viewSize.width - self._container:getContentSize().width, self._viewSize.height - self._container:getContentSize().height)
end

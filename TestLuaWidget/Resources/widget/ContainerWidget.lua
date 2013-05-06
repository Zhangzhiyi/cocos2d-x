ContainerWidget = class ("ContainerWidget", CCNodeExtend)

function ContainerWidget:ctor()
	ContainerWidget.super.ctor(self)
	self._layer:removeFromParentAndCleanup(true)
	self._layer = nil
	self._layer = ClipLayer:create()
	self._node:addChild(self._layer)
	
end

function ContainerWidget:isTouchInside(x, y)
	local bBox = self._layer:getViewRect()
	local touchLocation = self._layer:convertToWorldSpace(self._layer:convertToNodeSpace(ccp(x, y)))
	local bInside = bBox:containsPoint(touchLocation)
	return bInside
end
function ContainerWidget:setViewSize(viewSize)
	self._layer:setViewSize(viewSize)
	self:setContentSize(viewSize)
end
function ContainerWidget:getViewSize()
	return self._layer:getViewSize()
end
function ContainerWidget:setClipingAble(bClip)
	self._layer:setClipingAble(bClip)
end
function ContainerWidget:getClipingAble()
	self._layer:getClipingAble()
end
function ContainerWidget:getViewRect()
	return self._layer:getViewRect()
end
function ContainerWidget:alignItemsVertically(nPadding)
	nPadding = nPadding or 5
	local nTotalHeight = nPadding
	local array = self._layer:getChildren()
	local maxWidth = 0
	if array then
		for i = 0, array:count() - 1 do
			local child = array:objectAtIndex(i)
			child = tolua.cast(child, "CCNode")
			if child then
				local width = child:getContentSize().width
				if width > maxWidth then
					maxWidth = width
				end
				nTotalHeight = nTotalHeight + child:getContentSize().height + nPadding
			end
		end
	end
	local nItemHeight = 0
	if array then
		for i = 0, array:count() - 1 do
			local child = array:objectAtIndex(i)
			child = tolua.cast(child, "CCNode")
			if child then
				child:setAnchorPoint(ccp(0, 1))
				child:setPosition(0, nTotalHeight - (i + 1) * nPadding - nItemHeight)
				nItemHeight = nItemHeight + child:getContentSize().height
			end
		end
	end
	self:setContentSize(CCSize(maxWidth, nTotalHeight))		
end

function ContainerWidget:alignItemsHorizontally()
	nPadding = nPadding or 5
	local nTotalWidth = nPadding
	local array = self._layer:getChildren()
	local maxHeight = 0
	if array then
		for i = 0, array:count() - 1 do
			local child = array:objectAtIndex(i)
			child = tolua.cast(child, "CCNode")
			if child then
				local height = child:getContentSize().height
				if height > maxHeight then
					maxHeight = height
				end
				nTotalWidth = nTotalWidth + child:getContentSize().Width + nPadding
			end
		end
	end
	local nItemWidth = 0
	if array then
		for i = 0, array:count() - 1 do
			local child = array:objectAtIndex(i)
			child = tolua.cast(child, "CCNode")
			if child then
				child:setAnchorPoint(ccp(0, 0))
				child:setPosition((i + 1) * nPadding + nItemWidth, 0)
				nItemWidth = nItemWidth + child:getContentSize().Width
			end
		end
	end
	self:setContentSize(CCSize(nTotalWidth, height))			
end
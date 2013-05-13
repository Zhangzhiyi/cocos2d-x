TableView = class("TableView", ScrollView)

function TableView:ctor(options)
	TableView.super.ctor(self, options)
	
	self._cells = {} --存储所有cell的表
	self._cellPosition = {} --存储每一个cell的位置表
	self._touchCell = nil --存储触摸选中的cell	
end
function TableView:updateCellPositions()
	tableForClear(self._cellPosition)
	local cellsCount = self:numberOfCells()
	if cellsCount and cellsCount > 0 then
		local currentPos = 0
		local cellSize = nil
		for i = 1, cellsCount do
			self._cellPosition[i] = currentPos
			cellSize = self:cellSizeForIndex(i)
			if self._nDirection == ScrollView.DIRECTION_VERTICAL then
				currentPos = currentPos + cellSize.height
			elseif self._nDirection == ScrollView.DIRECTION_HORIZONTAL then
				currentPos = currentPos + cellSize.width
			end
		end
		self._cellPosition[cellsCount + 1] = currentPos
	end
end
function TableView:updateContentSize()
	local size = CCSize(0, 0)
	local cellsCount = self:numberOfCells()
	if cellsCount and cellsCount > 0 then
		local maxPosition = self._cellPosition[cellsCount + 1]
		if self._nDirection == ScrollView.DIRECTION_VERTICAL then
			size = CCSize(self._viewSize.width, maxPosition)
		elseif self._nDirection == ScrollView.DIRECTION_HORIZONTAL then
			size = CCSize(maxPosition, self._viewSize.height)
		end
	end
	self._container:setContentSize(size)
	if self._nDirection == ScrollView.DIRECTION_VERTICAL then
		self:setContentOffset(ccp(0, self:minContainerOffset().y))	
	elseif self._nDirection == ScrollView.DIRECTION_HORIZONTAL then
		self:setContentOffset(ccp(0, 0))
	end
end
function TableView:updateCellAtIndex(index)
	local cell = self:tableCellAtIndex(index)
	self:setCellPositionForIndex(cell, index)
	self._container:addChild(cell)
	table.insert(self._cells, cell)
	
end
function TableView:checkNodeVisibleInParent()
	for k,v in ipairs(self._cells) do
		if v then
			local bVisible = self:isNodeVisible(v)
			v:setVisible(bVisible)
		end
		
		--[[local child = array:objectAtIndex(i)
		child = tolua.cast(child, "CCNode")
		if child then
			local bVisible = self:isNodeVisible(child)
			child:setVisible(bVisible)
		end--]]
	end
end
function TableView:setCellPositionForIndex(cell, index)
	local cellSize = self:cellSizeForIndex(index)
	cell:setAnchorPoint(CCPointZero)
	local offsetPoint 
	if self._nDirection == ScrollView.DIRECTION_VERTICAL then
		offsetPoint = ccp(0, self._cellPosition[index])
		offsetPoint.y = self._container:getContentSize().height	- offsetPoint.y - cellSize.height
	elseif self._nDirection == ScrollView.DIRECTION_HORIZONTAL then
		offsetPoint = ccp(self._cellPosition[index], 0)	
	end
	cell:setPosition(offsetPoint)
end
function TableView:indexFromOffset(offset)
	local low = 1
	local hight = self:numberOfCells()
	local search = nil
	if self._nDirection == ScrollView.DIRECTION_VERTICAL then
		offset.y = self._container:getContentSize().height - offset.y 
		search = offset.y
	elseif self._nDirection == ScrollView.DIRECTION_HORIZONTAL then
		search = offset.x
	end
	local index = self:halfFindIndex(hight, low, search)
	if index ~= -1 then
		
	end
	return index
end
function TableView:halfFindIndex(hight, low, search) --二分查找
	while (hight >= low) do
		local mid = low + math.floor((hight - low)/2)
		local cellStart = self._cellPosition[mid]
		local cellEnd = self._cellPosition[mid + 1]
		if search >= cellStart and search <= cellEnd then
			return mid			
		elseif search < cellStart then
			hight = mid - 1	
		elseif search > cellEnd then
			low = mid + 1
		end
	end
	return -1
end	
function TableView:numberOfCells()
	return 20
end
function TableView:cellSizeForIndex(index)
	return CCSize(60, 60)
end
function TableView:tableCellAtIndex(index)
	local cell = CCSprite:create("Icon.png")
	return cell
end
function TableView:cellAtIndex(index)
	if self._cells then
		return self._cells[index]
	end
end
function TableView:reloadData()
	tableForClear(self._cells)
	self:updateCellPositions()
	self:updateContentSize()
	local cellsCount = self:numberOfCells()
	for i = 1, cellsCount do
		self:updateCellAtIndex(i)
	end
	--self:checkNodeVisibleInParent() --卡死，要优化
end
function TableView:onTouchBegan(x, y)
	if (not self:isVisible()) or (not self:isTouchInside(x, y))then
		return
	end
	local touchResult = TableView.super.onTouchBegan(self, x, y)
	local point = self:getContainer():convertToNodeSpace(ccp(x, y))
	local index = self:indexFromOffset(point)		
	if index ~= -1 then
		CCLuaLog("touch:" .. index)
		self._touchCell = self:cellAtIndex(index)
	end
	return touchResult
end
function TableView:onTouchMoved(x, y)
	TableView.super.onTouchMoved(self, x, y)
	--self:checkNodeVisibleInParent() -- 卡死了
end
function TableView:onTouchEnded(x, y)
	if not self:isVisible() then
		return
	end
	
	TableView.super.onTouchEnded(self, x, y)
end
function TableView:onTouchCancelled(x, y)

end
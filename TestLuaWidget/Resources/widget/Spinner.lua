Spinner = class("Spinner", CCNodeExtend)
--[[
	下拉列表控件类
	
--]]
function Spinner:ctor(options)
	Spinner.super.ctor(self, options)
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
	self._nTouchPriority = options.touchPriority or 0
    self:registerScriptTouchHandler(self._nTouchPriority, true)
	self:setTouchEnabled(true)
	
	self._values = options.values
	self._nSelect = self._nSelect or 1
	
	self._selectLabel = CCLabelTTF:create(self._values[self._nSelect], DEFAULT_TTF_FONT, DEFAULT_TTF_FONT_SIZE)
	self._selectLabel:setAnchorPoint(ccp(0, 0.5))
	self._selectLabel:setPosition(ccp(10, self._nHeight/2))
	self:addChild(self._selectLabel)
	
	self._valueChangeFunc = options.onValueChangeEvent
	
	local function numberOfCells()
		return #self._values
	end
	local function cellSizeForIndex(index)
		return CCSize(self._nWidth, 30)	
	end
	local function tableCellAtIndex(index)
		local cell = CCLabelTTF:create(self._values[index], DEFAULT_TTF_FONT, DEFAULT_TTF_FONT_SIZE)
		return cell
	end
	local function tableCellHighlight(cell)
		--cell:setOpacity(125)
		cell:setScale(1.15)
	end
	local function tableCellUnhighlight(cell)
		--cell:setOpacity(255)
		cell:setScale(1)
	end
	local function tableCellTouched(index, cell)
		--CCLuaLog("touch:" .. index)
		self._nSelect = index
		self:setSelectLabel(self._values[self._nSelect])
		if self._valueChangeFunc then
			self._valueChangeFunc(index, self._values[index])
		end
		self:showSelectLayer(false)
	end
	self._tableView = TableView.new({viewSize = CCSize(self._nWidth, 100), numberOfCellsFunc = numberOfCells, 
									 cellSizeForIndexFunc = cellSizeForIndex, tableCellAtIndexFunc = tableCellAtIndex,
									 tableCellHighlightFunc = tableCellHighlight,
									 tableCellUnhighlightFunc = tableCellUnhighlight,
									 tableCellTouchedFunc = tableCellTouched,
									 bounceable = false})
	self._tableView:setAnchorPoint(ccp(0, 1))
	self._tableView:reloadData()								
	self._node:addChild(self._tableView._node)
	
	self._bShowSelect = options.showSelect or false
	self._tableView:setVisible(self._bShowSelect)
end
function Spinner:showSelectLayer(show)
	if self._bShowSelect ~= show then
		self._bShowSelect = show
		self._tableView:setVisible(show)
	end
end
function Spinner:isShowSelect()
	return self._bShowSelect
end
function Spinner:setSelectLabel(text)
	self._selectLabel:setString(text)
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
	if not self:isTouchInside(x, y) then
		return
	end
	local point = self._sprite:convertToNodeSpace(ccp(x, y))
	local x = point.x
	local y = point.y
	if x >= 145 and x <= 180 then
		self:showSelectLayer(not self._bShowSelect)
	end
end

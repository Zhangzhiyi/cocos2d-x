CheckBox = class("CheckBox", CCNodeExtend)
--[[   
		开关按钮控件
							key				描述  									类型
	optiongs = 	{
					onEnSfName				选中状态可用的SpriteFrameName			string
					offEnSfName				没选中状态可用的SpriteFrameName			string
					onDisSfName				选中状态不可用的SpriteFrameName			string
					offDisSfName			没选中状态不可用的SpriteFrameName		string
					bChecked				默认是否选中状态						booleans
					onCheckEvent			状态改变的回调方法						function
					nTouchPriority			触摸事件优先级							number
				}
	
 --]]
function CheckBox:ctor(options)
	CheckBox.super.ctor(self, options)
    self._onEnSpriteFrame = spriteFrameByName(options.onEnSfName)
    self._offEnSpriteFrame = spriteFrameByName(options.offEnSfName)    
    self._onDisSpriteFrame = spriteFrameByName(options.onDisSfName)
    self._offDisSpriteFrame = spriteFrameByName(options.offDisSfName) 
  	
    self._bChecked = options.bChecked or false
	
	self._checkedFunc = options.onCheckEvent
    self._label = CCLabelTTF:create(options.strMsg, DEFAULT_TTF_FONT, DEFAULT_TTF_FONT_SIZE)
    self._sprite = CCSprite:create()       
    self:updateState()
    		
    --要注意的是self._sprite和self._label要在self._layer坐标系内，不要再负数坐标了，否则判断碰撞不准
    self._sprite:setPosition(self._sprite:getContentSize().width/2, self._sprite:getContentSize().height/2)
    self._layer:addChild(self._sprite)
    self._label:setAnchorPoint(ccp(0, 0.5))
    self._label:setPosition(self._sprite:getPositionX() + self._sprite:getContentSize().width/2, self._sprite:getPositionY())
    self._layer:addChild(self._label)
    
    self._nWidth = self._sprite:getContentSize().width + self._label:getContentSize().width
    if self._sprite:getContentSize().height >= self._label:getContentSize().height then
        self._nHeight = self._sprite:getContentSize().height
    else
        self._nHeight = self._label:getContentSize().height
    end		
	self:setContentSize(CCSize(self._nWidth, self._nHeight))	
    	
    self._nTouchPriority = options.nTouchPriority or 0
    self:registerScriptTouchHandler(self._nTouchPriority, true)
	self:setTouchEnabled(true)
    

end
function CheckBox:setEnabled(bEnabled)
	CheckBox.super.setEnabled(bEnabled)
	self:updateState()
end
function CheckBox:setChecked(bChecked)
    if self._bChecked ~= bChecked then
        self._bChecked = bChecked
        self:updateState()
		if self._checkedFunc then
			self._checkedFunc(bChecked)
		end
		if self._bChecked and self._nCheckId then
			if self._checkedGroupCallback then
				self._checkedGroupCallback(self._nCheckId)
			end
		end
    end
end
function CheckBox:isChecked()
	return self._bChecked
end
function CheckBox:updateState()
    if self._bEnabled and self._bChecked then
        self._sprite:setDisplayFrame(self._onEnSpriteFrame)
    elseif self._bEnabled and (not self._bChecked)then
        self._sprite:setDisplayFrame(self._offEnSpriteFrame)
    elseif (not self._bEnabled) and self._bChecked then
        self._sprite:setDisplayFrame(self._onDisSpriteFrame)
    elseif (not self._bEnabled) and (not self._bChecked) then
        self._sprite:setDisplayFrame(self._offDisSpriteFrame)
    end        
end
function CheckBox:toggle()
	return self:setChecked(not self._bChecked)
end
function CheckBox:onTouchBegan(x, y)
	if ((not self:isEnabled()) or (not self:isVisible()) or (not self:isTouchInside(x, y)))then
		return false
	end		
	return true
end
function CheckBox:onTouchMoved(x, y)

end
function CheckBox:onTouchEnded(x, y)
    if self:isTouchInside(x, y) then	
        self:toggle()
    end
end
function CheckBox:setCheckId(nCheckId)
	self._nCheckId = nCheckId
end
function CheckBox:setOnCheckedChangeCallback(checkBoxGroup, checkedGroupCallback)
	self._checkBoxGroup = checkBoxGroup
	self._checkedGroupCallback = checkedGroupCallback
end
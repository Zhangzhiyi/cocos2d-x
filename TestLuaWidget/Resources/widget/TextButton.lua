TextButton = class("TextButton", CCNodeExtend)

function TextButton:ctor(options)
	TextButton.super.ctor(self)
	
	self._nFontSize = options.fontSize or DEFAULT_TTF_FONT_SIZE
	self._strFontName = options.fontName or DEFAULT_TTF_FONT
	self._strLabel = options.strLabel or ""
	self._labelTTF = CCLabelTTF:create(self._strLabel, self._strFontName, self._nFontSize)
	if options.color then
		self._labelTTF:setColor(options.color)
	end
	self._bEnabled = options.isEnabled	or true
	
	self._labelTTF:setPosition(self._labelTTF:getContentSize().width/2, self._labelTTF:getContentSize().height/2)
	self:addChild(self._labelTTF)
	
	self._nWidth = self._labelTTF:getContentSize().width
	self._nHeight = self._labelTTF:getContentSize().height
	self:setContentSize(CCSize(self._nWidth, self._nHeight))		
	self._nTouchPriority = options.nTouchPriority or 0
    self:registerScriptTouchHandler(self._nTouchPriority, true)
	self:setTouchEnabled(true)
	
	self._clickFunc = options.onClickEvent
	self._nScale = 1.15
end

function TextButton:setString(strMsg)
	self._labelTTF:setString(strMsg)
end

function TextButton:setColor(color)
	self._labelTTF:setColor(options.color)
end

function TextButton:setFontName(strFont)
	self._labelTTF:setFontName(strFont)
end

function TextButton:setFontSize(nFontSize)
	self._labelTTF:setFontSize(nFontSize)
end
function TextButton:isEnabled()
	return self._bEnabled
end	
function TextButton:setEnabled(bEnabled)
	if self._bEnabled ~= bEnabled then
		self._bEnabled = bEnabled		
	end
end
function TextButton:onTouchBegan(x, y)
	if ((not self._bEnabled) or (not self:isVisible()) or (not self:isTouchInside(x, y)))then
		return false
	end
	self._labelTTF:setScale(self._nScale)
	return true
end
function TextButton:onTouchMoved(x, y)
	if self:isTouchInside(x, y) then
       self._labelTTF:setScale(self._nScale)
	else 
		self._labelTTF:setScale(1)
    end
end
function TextButton:onTouchEnded(x, y)
    if self:isTouchInside(x, y) then
		self._labelTTF:setScale(1)
		if self._clickFunc then
			self._clickFunc()
		end			
    end
end
function TextButton:onTouchCanelled(x, y)	
	self._labelTTF:setScale(1)
end	
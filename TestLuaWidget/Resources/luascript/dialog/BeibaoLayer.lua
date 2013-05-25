local BeibaoLayer = class("BeibaoLayer", DialogLayerMan)

function BeibaoLayer:ctor(options)
	BeibaoLayer.super.ctor(self, options)
	
	local background = CCSprite:createWithSpriteFrameName("background1.png")
	background:setAnchorPoint(CCPointZero)	
	self:addChild(background)
	self:setViewSize(background:getContentSize())
	
	local function haoyouClickFunc()
		CCLuaLog("ClickEvent")
		self:setVisible(false)
	end
	local haoyouBtn = ImageButton.new({normalSfName = "haoyou1.png", pressedSfName = "haoyou2.png", onClickEvent = haoyouClickFunc, nTouchPriority = -300})
	haoyouBtn:setPosition(ccp(background:getContentSize().width/2, background:getContentSize().height/2))
	background:addChild(haoyouBtn._node)
end

return BeibaoLayer
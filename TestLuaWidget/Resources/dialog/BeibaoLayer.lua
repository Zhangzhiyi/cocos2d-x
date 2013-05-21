local BeibaoLayer = class("BeibaoLayer", DialogLayerMan)

function BeibaoLayer:ctor(standardSceneMan)
	BeibaoLayer.super.ctor(self, standardSceneMan, "BeibaoLayer")
	local background = CCSprite:createWithSpriteFrameName("background1.png")
	background:setAnchorPoint(CCPointZero)	
	self._mainLayer:addChild(background)
	self._mainLayer:setViewSize(background:getContentSize())
	
	local function haoyouClickFunc()
		print("ClickEvent")
	end
	local haoyouBtn = ImageButton.new({normalSfName = "haoyou1.png", pressedSfName = "haoyou2.png", clickEvent = haoyouClickFunc})
	haoyouBtn:setPosition(ccp(background:getContentSize().width/2, background:getContentSize().height/2))
	self._mainLayer:addChild(haoyouBtn._node)
end

return BeibaoLayer
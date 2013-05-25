 local jinengLayer = class("jinengLayer", DialogLayerMan)

function jinengLayer:ctor(options)
	jinengLayer.super.ctor(self, options)
	local background = CCSprite:createWithSpriteFrameName("background2.png")
	background:setAnchorPoint(CCPointZero)	
	self:addChild(background)
	self:setViewSize(background:getContentSize())
end

return jinengLayer
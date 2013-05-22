 local jinengLayer = class("jinengLayer", DialogLayerMan)

function jinengLayer:ctor(standardSceneMan)
	jinengLayer.super.ctor(self, standardSceneMan, "jinengLayer")
	local background = CCSprite:createWithSpriteFrameName("background2.png")
	background:setAnchorPoint(CCPointZero)	
	self._mainLayer:addChild(background)
	self._mainLayer:setViewSize(background:getContentSize())
end

return jinengLayer
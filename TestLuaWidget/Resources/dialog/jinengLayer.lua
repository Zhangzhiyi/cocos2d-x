 local jinengLayer = class("jinengLayer", DialogLayerMan)

function jinengLayer:ctor(standardSceneMan)
	jinengLayer.super.ctor(self, standardSceneMan, "jinengLayer")
	local background = CCSprite:createWithSpriteFrameName("background2.png")
	background:setAnchorPoint(CCPointZero)
	--background:setPosition(VisibleRect.center())
	self._mainLayer:addChild(background)
	self._mainLayer:setViewSize(CCSize(480, 320))
end

return jinengLayer
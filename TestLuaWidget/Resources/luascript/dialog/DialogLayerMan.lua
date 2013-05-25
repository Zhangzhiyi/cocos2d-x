kDialogHandlerPriority = kCCMenuHandlerPriority - 1
DialogLayerMan = class("DialogLayerMan", ContainerWidget)
--[[
						key					描述  						类型
	options	= 	{
					bEnabled				是否可用					booleans
					
					bClipingAble			是否能够剪切部分可见		booleans
					viewSize				剪切部分大小				CCSize
					
					standardSceneMan		附属场景类					StandardSceneMan
					bAutoFadeIn				是否运行渐现动画			booleans
					strDialogTitle			描述						string	
				}
--]]
function DialogLayerMan:ctor(options)
	
	DialogLayerMan.super.ctor(self, options)
	self._standardSceneMan = options.standardSceneMan
	self._strDialogTitle = options.strDialogTitle or "DialogLayerMan"
	if bAutoFadeIn == nil then
		bAutoFadeIn = true
	end
	if bAutoFadeIn then
		self:runAction( CCFadeTo:create( 0.3, 166 ) )
	end
			
	self:registerScriptHandler()	
	self._standardSceneMan._mainScene:addChild(self._node, INT_MAX )	
end
function DialogLayerMan:onEnter()
	self._standardSceneMan:registerDialog( self )
	--注册触摸事件
	self:registerScriptTouchHandler(kDialogHandlerPriority, true)
	self:setTouchEnabled(true)
	
end
function DialogLayerMan:onExit()
	self._standardSceneMan:unregisterDialog( self )
end					
function DialogLayerMan:onTouchBegan(x, y)
	
	local bInside = self:isTouchInside(x, y)
	if bInside then
	    CCLuaLog(self._strDialogTitle .. ":onTouchBegan")
		self._standardSceneMan:reorderDialog(self)
	end		
	return bInside
end
function DialogLayerMan:onTouchMoved(x, y)

end
function DialogLayerMan:onTouchEnded(x, y)

end
function DialogLayerMan:onTouchCancelled(x, y)

end
function DialogLayerMan:close()
	self:removeFromParentAndCleanup(true)
end
function DialogLayerMan:onKeyBackClicked()
	self:close()
	return true
end

VisibleRect = {}
VisibleRect._visibleSize = CCDirector:sharedDirector():getVisibleSize()
VisibleRect._origin = CCDirector:sharedDirector():getVisibleOrigin()


function VisibleRect.getVisibleRect()
	return CCRect(VisibleRect._origin.x, VisibleRect._origin.y, VisibleRect._visibleSize.width, VisibleRect._visibleSize.height)
end	
function VisibleRect.left()
    return ccp(VisibleRect._origin.x, VisibleRect._origin.y + VisibleRect._visibleSize.height/2)
end
function VisibleRect.right()
    return ccp(VisibleRect._origin.x + VisibleRect._visibleSize.width, VisibleRect._origin.y + VisibleRect._visibleSize.height/2)
end
function VisibleRect.top()
    return ccp(VisibleRect._origin.x + VisibleRect._visibleSize.width/2, VisibleRect._origin.y + VisibleRect._visibleSize.height)
end
function VisibleRect.bottom()
    return ccp(VisibleRect._origin.x + VisibleRect._visibleSize.width/2, VisibleRect._origin.y)
end
function VisibleRect.center()
    return ccp(VisibleRect._origin.x + VisibleRect._visibleSize.width/2, VisibleRect._origin.y + VisibleRect._visibleSize.height/2)
end
function VisibleRect.leftTop()
    return ccp(VisibleRect._origin.x , VisibleRect._origin.y + VisibleRect._visibleSize.height)
end
function VisibleRect.rightTop()
    return ccp(VisibleRect._origin.x + VisibleRect._visibleSize.width, VisibleRect._origin.y + VisibleRect._visibleSize.height)
end
function VisibleRect.leftBottom()
    return ccp(VisibleRect._origin.x , VisibleRect._origin.y)
end
function VisibleRect.rightBottom()
    return ccp(VisibleRect._origin.x + VisibleRect._visibleSize.width, VisibleRect._origin.y)
end
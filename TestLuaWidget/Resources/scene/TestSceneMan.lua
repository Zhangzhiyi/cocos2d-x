local TestSceneMan = class("TestSceneMan", StandardSceneMan)

function TestSceneMan:ctor()
	TestSceneMan.super.ctor(self)
	
	
	local function onCheckCallback(bChecked)
		if bChecked then
			CCLuaLog("checked")
		else 
			CCLuaLog("not checked")
		end
	end
    local checkBox = CheckBox.new({onEnSfName = "duoxuan.png", 
                                   offEnSfName = "duoxuankong.png", 
                                   onDisSfName = "duoxuan_h.png", 
                                   offDisSfName = "duoxuankong_h.png",
                                   strMsg = "123456789",
                                   isEnabled = true,
                                   isOn = true,
								   onCheckEvent = onCheckCallback})
    checkBox:setPosition(ccp(VisibleRect.center().x - 100, VisibleRect.center().y))								
    self._mainLayer:addChild(checkBox._node)
	local function clickFunc()
		CCLuaLog("ClickEvent")
	end		
    local button = ImageButton.new({normalSfName = "gong1.png", pressedSfName = "gong2.png", disabledSfName = "gong1a.png", onClickEvent = clickFunc})
	button:setPosition(VisibleRect.center())	
	button:setScale(2)
	self._mainLayer:addChild(button._node)
	
	local function beibaoCilckFunc()
		self.dialog = (require "dialog/BeibaoLayer").new(self)
		self.dialog:setPosition(ccp(100, 100))
	end
	local beibaoBtn = ImageButton.new({normalSfName = "beibao1.png", pressedSfName = "beibao2.png", onClickEvent = beibaoCilckFunc})
	beibaoBtn:setPosition(ccp(100, 100))
	self._mainLayer:addChild(beibaoBtn._node)
	
	local function jinengCilckFunc()
		self.dialog = (require "dialog/jinengLayer").new(self)
		self.dialog:setPosition(ccp(200, 200))
	end
	local jinengBtn = ImageButton.new({normalSfName = "jineng1.png", pressedSfName = "jineng2.png", onClickEvent = jinengCilckFunc})
	jinengBtn:setPosition(ccp(700, 200))
	self._mainLayer:addChild(jinengBtn._node)
	
	local loading = ProgressBar.new({backgroundSprite = "jindutiaodi.png", progressSprite = "jindutiao.png"})
	loading:setPosition(ccp(500, 100))
	self._mainLayer:addChild(loading._node)
	loading:setPercent(0.75)
	
	local checkBox1 = CheckBox.new({onEnSfName = "xuanzhong.png", 
									 offEnSfName = "xuanzhongkong.png", 
                                     onDisSfName = "xuanzhong_h.png", 
                                     offDisSfName = "xuanzhongkong_h.png",
                                     strMsg = "11111111111"							
								    })									
	local checkBox2 = CheckBox.new({onEnSfName = "xuanzhong.png", 
									 offEnSfName = "xuanzhongkong.png", 
                                     onDisSfName = "xuanzhong_h.png", 
                                     offDisSfName = "xuanzhongkong_h.png",
                                     strMsg = "22222222222"							
								    })										
	local checkBoxGroup = CheckBoxGroup.new({
												group = {checkBox1, checkBox2}
											})
	checkBoxGroup:setPosition(ccp(200, 380))
	local groupWidth = checkBoxGroup:getContentSize().width
	local groupHeight = checkBoxGroup:getContentSize().height											
	self._mainLayer:addChild(checkBoxGroup._node)
	checkBoxGroup:alignItemsVertically()	
	
    local container = ContainerWidget.new()	
	for i = 1, 10 do
		local cell = CCSprite:create("Icon.png")
		container:addChild(cell)
	end
	container:alignItemsVertically(5)
	local scrollView = ScrollView.new({viewSize = CCSize(100, 200)})
	scrollView:setPosition(ccp(600, 300))
	scrollView:setContainer(container._node)
	self._mainLayer:addChild(scrollView._node)
			
end
return TestSceneMan
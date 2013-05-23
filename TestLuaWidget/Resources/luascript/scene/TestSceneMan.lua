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
    checkBox:setPosition(ccp(VisibleRect.center().x - 180, VisibleRect.center().y))								
    self._mainLayer:addChild(checkBox._node)
	local function clickFunc()
		CCLuaLog("ClickEvent")
	end		
	
    local button = ImageButton.new({normalSfName = "gong1.png", pressedSfName = "gong2.png", disabledSfName = "gong1a.png", onClickEvent = clickFunc})
	button:setPosition(VisibleRect.center())	
	button:setScale(2)
	self._mainLayer:addChild(button._node)
	local function update()
		CCLuaLog("update")		
	end
	--button:scheduleUpdateWithPriorityLua(update, 0)
	
	local textButton = TextButton.new({strLabel = "TextButton", onClickEvent = clickFunc, fontColor = ccORANGE})
	textButton:setPosition(ccp(VisibleRect.center().x, 150))
	self._mainLayer:addChild(textButton._node)
	
	local function beibaoCilckFunc()
		self.dialog = (require "luascript/dialog/BeibaoLayer").new(self)
		self.dialog:setPosition(ccp(100, 100))
	end
	local beibaoBtn = ImageButton.new({normalSfName = "beibao1.png", pressedSfName = "beibao2.png", onClickEvent = beibaoCilckFunc})
	beibaoBtn:setPosition(ccp(100, 100))
	self._mainLayer:addChild(beibaoBtn._node)
	
	local function jinengCilckFunc()
		self.dialog = (require "luascript/dialog/jinengLayer").new(self)
		self.dialog:setPosition(ccp(200, 200))
	end
	local jinengBtn = ImageButton.new({normalSfName = "jineng1.png", pressedSfName = "jineng2.png", onClickEvent = jinengCilckFunc})
	jinengBtn:setPosition(ccp(700, 200))
	self._mainLayer:addChild(jinengBtn._node)
	
	local loading = ProgressBar.new({backgroundSprite = "jindutiaodi.png", progressSprite = "jindutiao.png"})
	loading:setPosition(ccp(500, 100))
	self._mainLayer:addChild(loading._node)
	--loading:setPercent(0.75)
	loading:setPercentDuration(1, 10)
	
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
	scrollView:setContentOffset(ccp(0, scrollView:minContainerOffset().y))
	self._mainLayer:addChild(scrollView._node)
	
	local function numberOfCells()
		return 20
	end
	local function cellSizeForIndex(index)
		return CCSize(60, 60)	
	end
	local function tableCellAtIndex(index)
		local cell = CCSprite:create("Icon.png")
		return cell
	end
	local function tableCellHighlight(cell)
		cell:setOpacity(125)
	end
	local function tableCellUnhighlight(cell)
		cell:setOpacity(255)
	end
	local function tableCellTouched(index, cell)
		CCLuaLog("touch:" .. index)
	end
	local tableView = TableView.new({viewSize = CCSize(100, 200), numberOfCellsFunc = numberOfCells, 
									 cellSizeForIndexFunc = cellSizeForIndex, tableCellAtIndexFunc = tableCellAtIndex,
									 tableCellHighlightFunc = tableCellHighlight,
									 tableCellUnhighlightFunc = tableCellUnhighlight,
									 tableCellTouchedFunc = tableCellTouched})
	tableView:setPosition(ccp(700, 300))
	tableView:reloadData()
	self._mainLayer:addChild(tableView._node)
	
	local styleLabel = StyleLabel:create("HelloWorld!", "Helvetica", 24)
	local function styleLabelClick()
		CCLuaLog("HelloWorld")
	end
	styleLabel:setPerformClickEnable(true)
	styleLabel:registerScriptClickHandler(styleLabelClick)
	styleLabel:setPosition(ccp(700, 430))
	self._mainLayer:addChild(styleLabel)
	
	local function labelClick()
		CCLuaLog("zhangzhiyi")
	end	
	local styleLabelTable = {styleLabels = 
									{{strLabel = "My Name is:", fontName = "Helvetica", nFontSize = 20, bDrawBottomLine = false},
									 {strLabel = "zhangzhiyi", fontName = "Helvetica", nFontSize = 20, fontColor = ccc3(255,0,0), lineColor = ccc4f(255,0,0,255), bDrawBottomLine = true, bPerformClickEnable = true, styleLabelClickFunc = labelClick}}}
	local styleLabelGroup = StyleLabelGroup.new(styleLabelTable)
	styleLabelGroup:setPosition(ccp(300, 430))
	self._mainLayer:addChild(styleLabelGroup._node)
	
	local function valueChangeFunc(index, value)
		CCLuaLog("index:" .. index .. " value:" .. value)
	end
	local spinner = Spinner.new({normalSfName = "xiala2_n.png", pressedSfName = "xiala2_p.png", values = {11111111111, 2222222222, 3333333333}, onValueChangeEvent = valueChangeFunc})
	spinner:setPosition(ccp(100, 320))
	self._mainLayer:addChild(spinner._node)
	
	local slider = CCControlSlider:create(CCSprite:createWithSpriteFrameName("sliderTrack.png"), CCSprite:createWithSpriteFrameName("sliderProgress.png"), CCSprite:createWithSpriteFrameName("sliderThumb.png"))
	slider:setMinimumValue(0)
	slider:setMaximumValue(100)
	slider:setPosition(ccp(400, 50))
	self._mainLayer:addChild(slider)
end
return TestSceneMan
StyleLabelGroup = class("StyleLabelGroup", ContainerWidget)
--[[
	富文本控件
  styleLabels = { key        				描述          				类型
				{strLabel          			显示的文字      			string,
				 fontName     				字体名字        			string,
				 nFontSize     				字体大小  	  				number,
				 fontColor					字体颜色					ccColor3B,
				 bDrawBottomLine			是否画下划线				booleans,
				 nLineWidth              	下划线宽度      			number,				
				 lineColor					下划线颜色					ccColor4F,
				 bPerformClickEnable      	是否可以点击   				booleans,
				 styleLabelClickFunc     	点击回调方法   				Function,
				 }
			}
--]]
function StyleLabelGroup:ctor(options)
	StyleLabelGroup.super.ctor(self)
	self._styleLabels = options.styleLabels or {}
	
	for k,v in ipairs(self._styleLabels) do
		local styleLabel = StyleLabel:create(v.strLabel, v.fontName, v.nFontSize)
		if v.fontColor then
			styleLabel:setColor(v.fontColor)
		end
		styleLabel:setDrawBottomLine(v.bDrawBottomLine)
		if v.lineColor then
			styleLabel:setLineColor(v.lineColor)
		end
		if v.lineWidth then
			styleLabel:setLineWidth(v.nLineWidth)
		end
		if v.bPerformClickEnable then
			styleLabel:setPerformClickEnable(v.bPerformClickEnable)
			styleLabel:registerScriptClickHandler(v.styleLabelClickFunc)
		end
		self:addChild(styleLabel)
	end	
	self:alignItemsHorizontally(0)
end
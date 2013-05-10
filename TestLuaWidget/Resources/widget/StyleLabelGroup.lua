StyleLabelGroup = class("StyleLabelGroup", ContainerWidget)
--[[
  styleLabels = { key        			介绍          	类型
				{str          			显示的文字      string,
				 fontName     			字体名字        string,
				 fontSize     			字体大小  	  	number,
				 fontColor				字体颜色		ccColor3B,
				 drawBottomLine			是否画下划线	booleans,
				 lineWidth              下划线宽度      number,				
				 lineColor				下划线颜色		ccColor4F,
				 performClickEnable      是否可以点击   booleans,
				 styleLabelClickFunc     点击回调方法   Function,
				 }
			}
--]]
function StyleLabelGroup:ctor(options)
	StyleLabelGroup.super.ctor(self)
	self._styleLabels = options.styleLabels or {}
	
	for k,v in ipairs(self._styleLabels) do
		local styleLabel = CCStyleLabel:create(v.str, v.fontName, v.fontSize)
		if v.fontColor then
			styleLabel:setColor(v.fontColor)
		end
		styleLabel:setDrawBottomLine(v.drawBottomLine)
		if v.lineColor then
			styleLabel:setLineColor(v.lineColor)
		end
		if v.lineWidth then
			styleLabel:setLineWidth(v.lineWidth)
		end
		if v.performClickEnable then
			styleLabel:setPerformClickEnable(v.performClickEnable)
			styleLabel:registerScriptClickHandler(v.styleLabelClickFunc)
		end
		self:addChild(styleLabel)
	end	
	self:alignItemsHorizontally(0)
end
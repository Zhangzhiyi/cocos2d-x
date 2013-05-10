StyleLabelGroup = class("StyleLabelGroup", ContainerWidget)
--[[
  styleLabels = { key        			����          	����
				{str          			��ʾ������      string,
				 fontName     			��������        string,
				 fontSize     			�����С  	  	number,
				 fontColor				������ɫ		ccColor3B,
				 drawBottomLine			�Ƿ��»���	booleans,
				 lineWidth              �»��߿��      number,				
				 lineColor				�»�����ɫ		ccColor4F,
				 performClickEnable      �Ƿ���Ե��   booleans,
				 styleLabelClickFunc     ����ص�����   Function,
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
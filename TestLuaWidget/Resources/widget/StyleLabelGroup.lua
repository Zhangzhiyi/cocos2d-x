StyleLabelGroup = class("StyleLabelGroup", ContainerWidget)
--[[
	���ı��ؼ�
  styleLabels = { key        				����          				����
				{strLabel          			��ʾ������      			string,
				 fontName     				��������        			string,
				 nFontSize     				�����С  	  				number,
				 fontColor					������ɫ					ccColor3B,
				 bDrawBottomLine			�Ƿ��»���				booleans,
				 nLineWidth              	�»��߿��      			number,				
				 lineColor					�»�����ɫ					ccColor4F,
				 bPerformClickEnable      	�Ƿ���Ե��   				booleans,
				 styleLabelClickFunc     	����ص�����   				Function,
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
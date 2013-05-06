CheckBoxGroup = class("CheckBoxGroup", ContainerWidget)

function CheckBoxGroup:ctor(options)
	CheckBoxGroup.super.ctor(self)
	
	self._checkBoxGroup = options.group or {}
	self._nCheckId = options.nCheckId
	self._checkedChangeFunc = options.onCheckedChangeEvent
	for k, v in ipairs(self._checkBoxGroup) do
		self:addChild(v._node)
		v:setCheckId(k)
		local function onCheckedChange(checkId)
			self:onCheckedChangeCallback(checkId)
		end
		v:setOnCheckedChangeCallback(self, onCheckedChange)
	end
	
end
function CheckBoxGroup:onCheckedChangeCallback(checkId)
	if self._nCheckId then
		self._checkBoxGroup[self._nCheckId]:setChecked(false)
	end		
	self._nCheckId = checkId	
	CCLuaLog("checkId" .. checkId)
	if self._checkedChangeFunc then
		self._checkedChangeFunc(checkId)
	end
end
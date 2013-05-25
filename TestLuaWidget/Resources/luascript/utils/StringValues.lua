StringValues = {}


local StringValue = class("StringValue")
function StringValue:ctor(options)
	self._stringValue = options.stringValue
end
function StringValue:getString()
	return Global.getStrDependLanguage(self._stringValue)
end
local function createStringValue(values)
	return StringValue.new({stringValue = values})
end

StringValues.AppName = createStringValue({"English", "ÖÐÎÄ"})
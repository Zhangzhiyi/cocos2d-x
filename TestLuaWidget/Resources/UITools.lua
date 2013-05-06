UITools = {}
DEFAULT_TTF_FONT      = "Arial"
DEFAULT_TTF_FONT_SIZE = 24
CCPointZero = ccp(0,0)
CCPoint05 = ccp(0.5,0.5)
ccWHITE=ccc3(255,255,255);
ccYELLOW=ccc3(255,255,0);
ccBLUE=ccc3(0,0,255);
ccGREEN=ccc3(0,255,0);
ccRED=ccc3(255,0,0);
ccMAGENTA=ccc3(255,0,255);
ccBLACK=ccc3(0,0,0);
ccORANGE=ccc3(255,127,0);
ccGRAY=ccc3(166,166,166);
ccHalfBlack=ccc3(127,127,127)
INT_MAX = 2147483647
cc4BLACK=ccc4(0, 0, 0, 255)
cc4ORANGE=ccc4(255,127,0, 255);
cc4GREEN=ccc4(0,255,0, 255);
INT_MAX = 2147483647
kCCMenuHandlerPriority = -120


function spriteFrameByName(pszName)
   return CCSpriteFrameCache:sharedSpriteFrameCache():spriteFrameByName(pszName)
end

function tableForClear(t)
	if t then
		for k,v in ipairs(t) do
			t[k] = nil
		end
	end
end


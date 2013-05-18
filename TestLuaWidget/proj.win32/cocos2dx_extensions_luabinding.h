
#ifndef __COCOS2DX_EXTENSIONS_LUABINDING_H_
#define __COCOS2DX_EXTENSIONS_LUABINDING_H_

extern "C" {
#include "tolua++.h"
#include "tolua_fix.h"
}

#include <map>
#include <string>
#include "tolua_fix.h"
#include "cocos2d.h"
#include "cocos-ext.h"
#include "CCLuaEngine.h"

USING_NS_CC;
USING_NS_CC_EXT;

TOLUA_API int luaopen_cocos2dx_extensions_luabinding(lua_State* tolua_S);

#endif // __COCOS2DX_EXTENSIONS_LUABINDING_H_
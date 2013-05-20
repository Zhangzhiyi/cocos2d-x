
#ifndef __COCOS2DX_NETWORK_LUABINDING_H_
#define __COCOS2DX_NETWORK_LUABINDING_H_

extern "C" {
#include "tolua++.h"
#include "tolua_fix.h"
}

#include <map>
#include <string>
#include "tolua_fix.h"
#include "cocos2d.h"
#include "CCLuaEngine.h"

USING_NS_CC;

TOLUA_API int luaopen_cocos2dx_network_luabinding(lua_State* tolua_S);

#endif // __COCOS2DX_NETWORK_LUABINDING_H_
/*
** Lua binding: cocos2dx_cliplayer_luabinding
** Generated automatically by tolua++-1.0.92 on 05/20/13 16:24:38.
*/

/****************************************************************************
 Copyright (c) 2011 cocos2d-x.org

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

/* Exported function */
TOLUA_API int  tolua_cocos2dx_cliplayer_luabinding_open (lua_State* tolua_S);

#include "cocos2dx_cliplayer_luabinding.h"
#include "CCStyleLabel.h"
/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_CCRect (lua_State* tolua_S)
{
 CCRect* self = (CCRect*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCSize (lua_State* tolua_S)
{
 CCSize* self = (CCSize*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_ClipLayer (lua_State* tolua_S)
{
 ClipLayer* self = (ClipLayer*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"CCRect");
 tolua_usertype(tolua_S,"ClipLayer");
 tolua_usertype(tolua_S,"CCLayer");
 tolua_usertype(tolua_S,"CCSize");
}

/* method: new of class  ClipLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_cliplayer_luabinding_ClipLayer_new00
static int tolua_cocos2dx_cliplayer_luabinding_ClipLayer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ClipLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ClipLayer* tolua_ret = (ClipLayer*)  Mtolua_new((ClipLayer)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"ClipLayer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ClipLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_cliplayer_luabinding_ClipLayer_new00_local
static int tolua_cocos2dx_cliplayer_luabinding_ClipLayer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ClipLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ClipLayer* tolua_ret = (ClipLayer*)  Mtolua_new((ClipLayer)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"ClipLayer");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  ClipLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_cliplayer_luabinding_ClipLayer_delete00
static int tolua_cocos2dx_cliplayer_luabinding_ClipLayer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ClipLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ClipLayer* self = (ClipLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  ClipLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_cliplayer_luabinding_ClipLayer_create00
static int tolua_cocos2dx_cliplayer_luabinding_ClipLayer_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ClipLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ClipLayer* tolua_ret = (ClipLayer*)  ClipLayer::create();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"ClipLayer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  ClipLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_cliplayer_luabinding_ClipLayer_create01
static int tolua_cocos2dx_cliplayer_luabinding_ClipLayer_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ClipLayer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const CCSize* viewSize = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
  {
   ClipLayer* tolua_ret = (ClipLayer*)  ClipLayer::create(*viewSize);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"ClipLayer");
  }
 }
 return 1;
tolua_lerror:
 return tolua_cocos2dx_cliplayer_luabinding_ClipLayer_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getViewSize of class  ClipLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_cliplayer_luabinding_ClipLayer_getViewSize00
static int tolua_cocos2dx_cliplayer_luabinding_ClipLayer_getViewSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ClipLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ClipLayer* self = (ClipLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getViewSize'", NULL);
#endif
  {
   CCSize tolua_ret = (CCSize)  self->getViewSize();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCSize)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCSize));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getViewSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setViewSize of class  ClipLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_cliplayer_luabinding_ClipLayer_setViewSize00
static int tolua_cocos2dx_cliplayer_luabinding_ClipLayer_setViewSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ClipLayer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ClipLayer* self = (ClipLayer*)  tolua_tousertype(tolua_S,1,0);
  const CCSize* viewSize = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setViewSize'", NULL);
#endif
  {
   self->setViewSize(*viewSize);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setViewSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getViewRect of class  ClipLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_cliplayer_luabinding_ClipLayer_getViewRect00
static int tolua_cocos2dx_cliplayer_luabinding_ClipLayer_getViewRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ClipLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ClipLayer* self = (ClipLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getViewRect'", NULL);
#endif
  {
   CCRect tolua_ret = (CCRect)  self->getViewRect();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCRect)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCRect));
     tolua_pushusertype(tolua_S,tolua_obj,"CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getViewRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getClipingRect of class  ClipLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_cliplayer_luabinding_ClipLayer_getClipingRect00
static int tolua_cocos2dx_cliplayer_luabinding_ClipLayer_getClipingRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ClipLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ClipLayer* self = (ClipLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getClipingRect'", NULL);
#endif
  {
   CCRect tolua_ret = (CCRect)  self->getClipingRect();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCRect)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCRect));
     tolua_pushusertype(tolua_S,tolua_obj,"CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getClipingRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setClipingRect of class  ClipLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_cliplayer_luabinding_ClipLayer_setClipingRect00
static int tolua_cocos2dx_cliplayer_luabinding_ClipLayer_setClipingRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ClipLayer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCRect",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ClipLayer* self = (ClipLayer*)  tolua_tousertype(tolua_S,1,0);
  const CCRect* clipingRect = ((const CCRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setClipingRect'", NULL);
#endif
  {
   self->setClipingRect(*clipingRect);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setClipingRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getClipingAble of class  ClipLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_cliplayer_luabinding_ClipLayer_getClipingAble00
static int tolua_cocos2dx_cliplayer_luabinding_ClipLayer_getClipingAble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ClipLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ClipLayer* self = (ClipLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getClipingAble'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getClipingAble();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getClipingAble'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setClipingAble of class  ClipLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_cliplayer_luabinding_ClipLayer_setClipingAble00
static int tolua_cocos2dx_cliplayer_luabinding_ClipLayer_setClipingAble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ClipLayer",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ClipLayer* self = (ClipLayer*)  tolua_tousertype(tolua_S,1,0);
  bool clipingAble = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setClipingAble'", NULL);
#endif
  {
   self->setClipingAble(clipingAble);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setClipingAble'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_cocos2dx_cliplayer_luabinding_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"ClipLayer","ClipLayer","CCLayer",tolua_collect_ClipLayer);
  #else
  tolua_cclass(tolua_S,"ClipLayer","ClipLayer","CCLayer",NULL);
  #endif
  tolua_beginmodule(tolua_S,"ClipLayer");
   tolua_function(tolua_S,"new",tolua_cocos2dx_cliplayer_luabinding_ClipLayer_new00);
   tolua_function(tolua_S,"new_local",tolua_cocos2dx_cliplayer_luabinding_ClipLayer_new00_local);
   tolua_function(tolua_S,".call",tolua_cocos2dx_cliplayer_luabinding_ClipLayer_new00_local);
   tolua_function(tolua_S,"delete",tolua_cocos2dx_cliplayer_luabinding_ClipLayer_delete00);
   tolua_function(tolua_S,"create",tolua_cocos2dx_cliplayer_luabinding_ClipLayer_create00);
   tolua_function(tolua_S,"create",tolua_cocos2dx_cliplayer_luabinding_ClipLayer_create01);
   tolua_function(tolua_S,"getViewSize",tolua_cocos2dx_cliplayer_luabinding_ClipLayer_getViewSize00);
   tolua_function(tolua_S,"setViewSize",tolua_cocos2dx_cliplayer_luabinding_ClipLayer_setViewSize00);
   tolua_function(tolua_S,"getViewRect",tolua_cocos2dx_cliplayer_luabinding_ClipLayer_getViewRect00);
   tolua_function(tolua_S,"getClipingRect",tolua_cocos2dx_cliplayer_luabinding_ClipLayer_getClipingRect00);
   tolua_function(tolua_S,"setClipingRect",tolua_cocos2dx_cliplayer_luabinding_ClipLayer_setClipingRect00);
   tolua_function(tolua_S,"getClipingAble",tolua_cocos2dx_cliplayer_luabinding_ClipLayer_getClipingAble00);
   tolua_function(tolua_S,"setClipingAble",tolua_cocos2dx_cliplayer_luabinding_ClipLayer_setClipingAble00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_cocos2dx_cliplayer_luabinding (lua_State* tolua_S) {
 return tolua_cocos2dx_cliplayer_luabinding_open(tolua_S);
};
#endif


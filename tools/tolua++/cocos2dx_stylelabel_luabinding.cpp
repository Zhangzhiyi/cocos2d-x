/*
** Lua binding: cocos2dx_stylelabel_luabinding
** Generated automatically by tolua++-1.0.92 on 05/20/13 16:46:03.
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
TOLUA_API int  tolua_cocos2dx_stylelabel_luabinding_open (lua_State* tolua_S);

#include "cocos2dx_stylelabel_luabinding.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_LUA_FUNCTION (lua_State* tolua_S)
{
 LUA_FUNCTION* self = (LUA_FUNCTION*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_ccColor4F (lua_State* tolua_S)
{
 ccColor4F* self = (ccColor4F*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_StyleLabel (lua_State* tolua_S)
{
 StyleLabel* self = (StyleLabel*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"StyleLabel");
 tolua_usertype(tolua_S,"ccColor4F");
 
 tolua_usertype(tolua_S,"CCLabelTTF");
}

/* method: new of class  StyleLabel */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_stylelabel_luabinding_StyleLabel_new00
static int tolua_cocos2dx_stylelabel_luabinding_StyleLabel_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"StyleLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   StyleLabel* tolua_ret = (StyleLabel*)  Mtolua_new((StyleLabel)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"StyleLabel");
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

/* method: new_local of class  StyleLabel */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_stylelabel_luabinding_StyleLabel_new00_local
static int tolua_cocos2dx_stylelabel_luabinding_StyleLabel_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"StyleLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   StyleLabel* tolua_ret = (StyleLabel*)  Mtolua_new((StyleLabel)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"StyleLabel");
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

/* method: delete of class  StyleLabel */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_stylelabel_luabinding_StyleLabel_delete00
static int tolua_cocos2dx_stylelabel_luabinding_StyleLabel_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StyleLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StyleLabel* self = (StyleLabel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: create of class  StyleLabel */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_stylelabel_luabinding_StyleLabel_create00
static int tolua_cocos2dx_stylelabel_luabinding_StyleLabel_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"StyleLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   StyleLabel* tolua_ret = (StyleLabel*)  StyleLabel::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"StyleLabel");
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

/* method: create of class  StyleLabel */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_stylelabel_luabinding_StyleLabel_create01
static int tolua_cocos2dx_stylelabel_luabinding_StyleLabel_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"StyleLabel",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* fontName = ((const char*)  tolua_tostring(tolua_S,3,0));
  float fontSize = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   StyleLabel* tolua_ret = (StyleLabel*)  StyleLabel::create(str,fontName,fontSize);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"StyleLabel");
  }
 }
 return 1;
tolua_lerror:
 return tolua_cocos2dx_stylelabel_luabinding_StyleLabel_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPerformClickEvent of class  StyleLabel */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_stylelabel_luabinding_StyleLabel_setPerformClickEvent00
static int tolua_cocos2dx_stylelabel_luabinding_StyleLabel_setPerformClickEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StyleLabel",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StyleLabel* self = (StyleLabel*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPerformClickEvent'", NULL);
#endif
  {
   self->setPerformClickEvent(enable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPerformClickEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isTouchEnabled of class  StyleLabel */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_stylelabel_luabinding_StyleLabel_isTouchEnabled00
static int tolua_cocos2dx_stylelabel_luabinding_StyleLabel_isTouchEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StyleLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StyleLabel* self = (StyleLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isTouchEnabled'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isTouchEnabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isTouchEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTouchEnabled of class  StyleLabel */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_stylelabel_luabinding_StyleLabel_setTouchEnabled00
static int tolua_cocos2dx_stylelabel_luabinding_StyleLabel_setTouchEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StyleLabel",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StyleLabel* self = (StyleLabel*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTouchEnabled'", NULL);
#endif
  {
   self->setTouchEnabled(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTouchEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTouchPriority of class  StyleLabel */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_stylelabel_luabinding_StyleLabel_setTouchPriority00
static int tolua_cocos2dx_stylelabel_luabinding_StyleLabel_setTouchPriority00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StyleLabel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StyleLabel* self = (StyleLabel*)  tolua_tousertype(tolua_S,1,0);
  int priority = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTouchPriority'", NULL);
#endif
  {
   self->setTouchPriority(priority);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTouchPriority'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTouchPriority of class  StyleLabel */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_stylelabel_luabinding_StyleLabel_getTouchPriority00
static int tolua_cocos2dx_stylelabel_luabinding_StyleLabel_getTouchPriority00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StyleLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StyleLabel* self = (StyleLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTouchPriority'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getTouchPriority();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTouchPriority'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDrawBottomLine of class  StyleLabel */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_stylelabel_luabinding_StyleLabel_setDrawBottomLine00
static int tolua_cocos2dx_stylelabel_luabinding_StyleLabel_setDrawBottomLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StyleLabel",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StyleLabel* self = (StyleLabel*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDrawBottomLine'", NULL);
#endif
  {
   self->setDrawBottomLine(enable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDrawBottomLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isDrawBottomLine of class  StyleLabel */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_stylelabel_luabinding_StyleLabel_isDrawBottomLine00
static int tolua_cocos2dx_stylelabel_luabinding_StyleLabel_isDrawBottomLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StyleLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StyleLabel* self = (StyleLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isDrawBottomLine'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isDrawBottomLine();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isDrawBottomLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLineWidth of class  StyleLabel */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_stylelabel_luabinding_StyleLabel_setLineWidth00
static int tolua_cocos2dx_stylelabel_luabinding_StyleLabel_setLineWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StyleLabel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StyleLabel* self = (StyleLabel*)  tolua_tousertype(tolua_S,1,0);
  float lineWidth = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLineWidth'", NULL);
#endif
  {
   self->setLineWidth(lineWidth);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLineWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLineWidth of class  StyleLabel */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_stylelabel_luabinding_StyleLabel_getLineWidth00
static int tolua_cocos2dx_stylelabel_luabinding_StyleLabel_getLineWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StyleLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StyleLabel* self = (StyleLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLineWidth'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getLineWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLineWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLineColor of class  StyleLabel */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_stylelabel_luabinding_StyleLabel_setLineColor00
static int tolua_cocos2dx_stylelabel_luabinding_StyleLabel_setLineColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StyleLabel",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ccColor4F",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StyleLabel* self = (StyleLabel*)  tolua_tousertype(tolua_S,1,0);
  ccColor4F lineColor = *((ccColor4F*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLineColor'", NULL);
#endif
  {
   self->setLineColor(lineColor);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLineColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLineColor of class  StyleLabel */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_stylelabel_luabinding_StyleLabel_getLineColor00
static int tolua_cocos2dx_stylelabel_luabinding_StyleLabel_getLineColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StyleLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StyleLabel* self = (StyleLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLineColor'", NULL);
#endif
  {
   ccColor4F tolua_ret = (ccColor4F)  self->getLineColor();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((ccColor4F)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"ccColor4F");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(ccColor4F));
     tolua_pushusertype(tolua_S,tolua_obj,"ccColor4F");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLineColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerScriptClickHandler of class  StyleLabel */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_stylelabel_luabinding_StyleLabel_registerScriptClickHandler00
static int tolua_cocos2dx_stylelabel_luabinding_StyleLabel_registerScriptClickHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StyleLabel",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StyleLabel* self = (StyleLabel*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION nHandler = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerScriptClickHandler'", NULL);
#endif
  {
   self->registerScriptClickHandler(nHandler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerScriptClickHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unregisterScriptClickHandler of class  StyleLabel */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_stylelabel_luabinding_StyleLabel_unregisterScriptClickHandler00
static int tolua_cocos2dx_stylelabel_luabinding_StyleLabel_unregisterScriptClickHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StyleLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StyleLabel* self = (StyleLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unregisterScriptClickHandler'", NULL);
#endif
  {
   self->unregisterScriptClickHandler();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unregisterScriptClickHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScriptClickHandler of class  StyleLabel */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_stylelabel_luabinding_StyleLabel_getScriptClickHandler00
static int tolua_cocos2dx_stylelabel_luabinding_StyleLabel_getScriptClickHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StyleLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StyleLabel* self = (StyleLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScriptClickHandler'", NULL);
#endif
  {
   LUA_FUNCTION tolua_ret = (LUA_FUNCTION)  self->getScriptClickHandler();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((LUA_FUNCTION)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"LUA_FUNCTION");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(LUA_FUNCTION));
     tolua_pushusertype(tolua_S,tolua_obj,"LUA_FUNCTION");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScriptClickHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_cocos2dx_stylelabel_luabinding_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"StyleLabel","StyleLabel","CCLabelTTF",tolua_collect_StyleLabel);
  #else
  tolua_cclass(tolua_S,"StyleLabel","StyleLabel","CCLabelTTF",NULL);
  #endif
  tolua_beginmodule(tolua_S,"StyleLabel");
   tolua_function(tolua_S,"new",tolua_cocos2dx_stylelabel_luabinding_StyleLabel_new00);
   tolua_function(tolua_S,"new_local",tolua_cocos2dx_stylelabel_luabinding_StyleLabel_new00_local);
   tolua_function(tolua_S,".call",tolua_cocos2dx_stylelabel_luabinding_StyleLabel_new00_local);
   tolua_function(tolua_S,"delete",tolua_cocos2dx_stylelabel_luabinding_StyleLabel_delete00);
   tolua_function(tolua_S,"create",tolua_cocos2dx_stylelabel_luabinding_StyleLabel_create00);
   tolua_function(tolua_S,"create",tolua_cocos2dx_stylelabel_luabinding_StyleLabel_create01);
   tolua_function(tolua_S,"setPerformClickEvent",tolua_cocos2dx_stylelabel_luabinding_StyleLabel_setPerformClickEvent00);
   tolua_function(tolua_S,"isTouchEnabled",tolua_cocos2dx_stylelabel_luabinding_StyleLabel_isTouchEnabled00);
   tolua_function(tolua_S,"setTouchEnabled",tolua_cocos2dx_stylelabel_luabinding_StyleLabel_setTouchEnabled00);
   tolua_function(tolua_S,"setTouchPriority",tolua_cocos2dx_stylelabel_luabinding_StyleLabel_setTouchPriority00);
   tolua_function(tolua_S,"getTouchPriority",tolua_cocos2dx_stylelabel_luabinding_StyleLabel_getTouchPriority00);
   tolua_function(tolua_S,"setDrawBottomLine",tolua_cocos2dx_stylelabel_luabinding_StyleLabel_setDrawBottomLine00);
   tolua_function(tolua_S,"isDrawBottomLine",tolua_cocos2dx_stylelabel_luabinding_StyleLabel_isDrawBottomLine00);
   tolua_function(tolua_S,"setLineWidth",tolua_cocos2dx_stylelabel_luabinding_StyleLabel_setLineWidth00);
   tolua_function(tolua_S,"getLineWidth",tolua_cocos2dx_stylelabel_luabinding_StyleLabel_getLineWidth00);
   tolua_function(tolua_S,"setLineColor",tolua_cocos2dx_stylelabel_luabinding_StyleLabel_setLineColor00);
   tolua_function(tolua_S,"getLineColor",tolua_cocos2dx_stylelabel_luabinding_StyleLabel_getLineColor00);
   tolua_function(tolua_S,"registerScriptClickHandler",tolua_cocos2dx_stylelabel_luabinding_StyleLabel_registerScriptClickHandler00);
   tolua_function(tolua_S,"unregisterScriptClickHandler",tolua_cocos2dx_stylelabel_luabinding_StyleLabel_unregisterScriptClickHandler00);
   tolua_function(tolua_S,"getScriptClickHandler",tolua_cocos2dx_stylelabel_luabinding_StyleLabel_getScriptClickHandler00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_cocos2dx_stylelabel_luabinding (lua_State* tolua_S) {
 return tolua_cocos2dx_stylelabel_luabinding_open(tolua_S);
};
#endif


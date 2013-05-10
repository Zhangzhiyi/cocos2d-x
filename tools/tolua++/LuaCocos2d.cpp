/*
** Lua binding: Cocos2d2
** Generated automatically by tolua++-1.0.92 on 05/10/13 15:51:46.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Cocos2d2_open (lua_State* tolua_S);

#include "LuaCocos2d.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_CCStyleLabel (lua_State* tolua_S)
{
 CCStyleLabel* self = (CCStyleLabel*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_ccColor4F (lua_State* tolua_S)
{
 ccColor4F* self = (ccColor4F*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
#ifndef Mtolua_typeid
#define Mtolua_typeid(L,TI,T)
#endif
 tolua_usertype(tolua_S,"CCStyleLabel");
 Mtolua_typeid(tolua_S,typeid(CCStyleLabel), "CCStyleLabel");
 tolua_usertype(tolua_S,"ccColor4F");
 Mtolua_typeid(tolua_S,typeid(ccColor4F), "ccColor4F");
 tolua_usertype(tolua_S,"CCLabelTTF");
 Mtolua_typeid(tolua_S,typeid(CCLabelTTF), "CCLabelTTF");
}

/* method: new of class  CCStyleLabel */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCStyleLabel_new00
static int tolua_Cocos2d2_CCStyleLabel_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCStyleLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCStyleLabel* tolua_ret = (CCStyleLabel*)  Mtolua_new((CCStyleLabel)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCStyleLabel");
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

/* method: new_local of class  CCStyleLabel */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCStyleLabel_new00_local
static int tolua_Cocos2d2_CCStyleLabel_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCStyleLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCStyleLabel* tolua_ret = (CCStyleLabel*)  Mtolua_new((CCStyleLabel)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCStyleLabel");
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

/* method: delete of class  CCStyleLabel */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCStyleLabel_delete00
static int tolua_Cocos2d2_CCStyleLabel_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStyleLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStyleLabel* self = (CCStyleLabel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: create of class  CCStyleLabel */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCStyleLabel_create00
static int tolua_Cocos2d2_CCStyleLabel_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCStyleLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCStyleLabel* tolua_ret = (CCStyleLabel*)  CCStyleLabel::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCStyleLabel");
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

/* method: create of class  CCStyleLabel */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCStyleLabel_create01
static int tolua_Cocos2d2_CCStyleLabel_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCStyleLabel",0,&tolua_err) ||
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
   CCStyleLabel* tolua_ret = (CCStyleLabel*)  CCStyleLabel::create(str,fontName,fontSize);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCStyleLabel");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Cocos2d2_CCStyleLabel_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPerformClickEvent of class  CCStyleLabel */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCStyleLabel_setPerformClickEvent00
static int tolua_Cocos2d2_CCStyleLabel_setPerformClickEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStyleLabel",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStyleLabel* self = (CCStyleLabel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: isTouchEnabled of class  CCStyleLabel */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCStyleLabel_isTouchEnabled00
static int tolua_Cocos2d2_CCStyleLabel_isTouchEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStyleLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStyleLabel* self = (CCStyleLabel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setTouchEnabled of class  CCStyleLabel */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCStyleLabel_setTouchEnabled00
static int tolua_Cocos2d2_CCStyleLabel_setTouchEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStyleLabel",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStyleLabel* self = (CCStyleLabel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setTouchPriority of class  CCStyleLabel */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCStyleLabel_setTouchPriority00
static int tolua_Cocos2d2_CCStyleLabel_setTouchPriority00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStyleLabel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStyleLabel* self = (CCStyleLabel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getTouchPriority of class  CCStyleLabel */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCStyleLabel_getTouchPriority00
static int tolua_Cocos2d2_CCStyleLabel_getTouchPriority00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStyleLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStyleLabel* self = (CCStyleLabel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setDrawBottomLine of class  CCStyleLabel */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCStyleLabel_setDrawBottomLine00
static int tolua_Cocos2d2_CCStyleLabel_setDrawBottomLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStyleLabel",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStyleLabel* self = (CCStyleLabel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: isDrawBottomLine of class  CCStyleLabel */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCStyleLabel_isDrawBottomLine00
static int tolua_Cocos2d2_CCStyleLabel_isDrawBottomLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStyleLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStyleLabel* self = (CCStyleLabel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setLineWidth of class  CCStyleLabel */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCStyleLabel_setLineWidth00
static int tolua_Cocos2d2_CCStyleLabel_setLineWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStyleLabel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStyleLabel* self = (CCStyleLabel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getLineWidth of class  CCStyleLabel */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCStyleLabel_getLineWidth00
static int tolua_Cocos2d2_CCStyleLabel_getLineWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStyleLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStyleLabel* self = (CCStyleLabel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setLineColor of class  CCStyleLabel */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCStyleLabel_setLineColor00
static int tolua_Cocos2d2_CCStyleLabel_setLineColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStyleLabel",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ccColor4F",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStyleLabel* self = (CCStyleLabel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getLineColor of class  CCStyleLabel */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCStyleLabel_getLineColor00
static int tolua_Cocos2d2_CCStyleLabel_getLineColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStyleLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStyleLabel* self = (CCStyleLabel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: registerScriptClickHandler of class  CCStyleLabel */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCStyleLabel_registerScriptClickHandler00
static int tolua_Cocos2d2_CCStyleLabel_registerScriptClickHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStyleLabel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStyleLabel* self = (CCStyleLabel*)  tolua_tousertype(tolua_S,1,0);
  int nHandler = ((int)  tolua_tonumber(tolua_S,2,0));
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

/* method: unregisterScriptClickHandler of class  CCStyleLabel */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCStyleLabel_unregisterScriptClickHandler00
static int tolua_Cocos2d2_CCStyleLabel_unregisterScriptClickHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStyleLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStyleLabel* self = (CCStyleLabel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getScriptClickHandler of class  CCStyleLabel */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCStyleLabel_getScriptClickHandler00
static int tolua_Cocos2d2_CCStyleLabel_getScriptClickHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStyleLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStyleLabel* self = (CCStyleLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScriptClickHandler'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getScriptClickHandler();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
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
TOLUA_API int tolua_Cocos2d2_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCStyleLabel","CCStyleLabel","CCLabelTTF",tolua_collect_CCStyleLabel);
  #else
  tolua_cclass(tolua_S,"CCStyleLabel","CCStyleLabel","CCLabelTTF",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCStyleLabel");
   tolua_function(tolua_S,"new",tolua_Cocos2d2_CCStyleLabel_new00);
   tolua_function(tolua_S,"new_local",tolua_Cocos2d2_CCStyleLabel_new00_local);
   tolua_function(tolua_S,".call",tolua_Cocos2d2_CCStyleLabel_new00_local);
   tolua_function(tolua_S,"delete",tolua_Cocos2d2_CCStyleLabel_delete00);
   tolua_function(tolua_S,"create",tolua_Cocos2d2_CCStyleLabel_create00);
   tolua_function(tolua_S,"create",tolua_Cocos2d2_CCStyleLabel_create01);
   tolua_function(tolua_S,"setPerformClickEvent",tolua_Cocos2d2_CCStyleLabel_setPerformClickEvent00);
   tolua_function(tolua_S,"isTouchEnabled",tolua_Cocos2d2_CCStyleLabel_isTouchEnabled00);
   tolua_function(tolua_S,"setTouchEnabled",tolua_Cocos2d2_CCStyleLabel_setTouchEnabled00);
   tolua_function(tolua_S,"setTouchPriority",tolua_Cocos2d2_CCStyleLabel_setTouchPriority00);
   tolua_function(tolua_S,"getTouchPriority",tolua_Cocos2d2_CCStyleLabel_getTouchPriority00);
   tolua_function(tolua_S,"setDrawBottomLine",tolua_Cocos2d2_CCStyleLabel_setDrawBottomLine00);
   tolua_function(tolua_S,"isDrawBottomLine",tolua_Cocos2d2_CCStyleLabel_isDrawBottomLine00);
   tolua_function(tolua_S,"setLineWidth",tolua_Cocos2d2_CCStyleLabel_setLineWidth00);
   tolua_function(tolua_S,"getLineWidth",tolua_Cocos2d2_CCStyleLabel_getLineWidth00);
   tolua_function(tolua_S,"setLineColor",tolua_Cocos2d2_CCStyleLabel_setLineColor00);
   tolua_function(tolua_S,"getLineColor",tolua_Cocos2d2_CCStyleLabel_getLineColor00);
   tolua_function(tolua_S,"registerScriptClickHandler",tolua_Cocos2d2_CCStyleLabel_registerScriptClickHandler00);
   tolua_function(tolua_S,"unregisterScriptClickHandler",tolua_Cocos2d2_CCStyleLabel_unregisterScriptClickHandler00);
   tolua_function(tolua_S,"getScriptClickHandler",tolua_Cocos2d2_CCStyleLabel_getScriptClickHandler00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Cocos2d2 (lua_State* tolua_S) {
 return tolua_Cocos2d2_open(tolua_S);
};
#endif


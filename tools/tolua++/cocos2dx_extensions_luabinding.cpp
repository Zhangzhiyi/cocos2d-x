/*
** Lua binding: Cocos2d2
** Generated automatically by tolua++-1.0.92 on 05/18/13 11:27:47.
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

static int tolua_collect_CCPoint (lua_State* tolua_S)
{
 CCPoint* self = (CCPoint*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CCControlSlider (lua_State* tolua_S)
{
 CCControlSlider* self = (CCControlSlider*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CCControlSwitch (lua_State* tolua_S)
{
 CCControlSwitch* self = (CCControlSwitch*) tolua_tousertype(tolua_S,1,0);
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
 tolua_usertype(tolua_S,"CCPoint");
 Mtolua_typeid(tolua_S,typeid(CCPoint), "CCPoint");
 tolua_usertype(tolua_S,"CCLayerRGBA");
 Mtolua_typeid(tolua_S,typeid(CCLayerRGBA), "CCLayerRGBA");
 tolua_usertype(tolua_S,"CCControlSlider");
 Mtolua_typeid(tolua_S,typeid(CCControlSlider), "CCControlSlider");
 tolua_usertype(tolua_S,"CCTouch");
 Mtolua_typeid(tolua_S,typeid(CCTouch), "CCTouch");
 tolua_usertype(tolua_S,"CCLabelTTF");
 Mtolua_typeid(tolua_S,typeid(CCLabelTTF), "CCLabelTTF");
 tolua_usertype(tolua_S,"CCControl");
 Mtolua_typeid(tolua_S,typeid(CCControl), "CCControl");
 tolua_usertype(tolua_S,"CCSprite");
 Mtolua_typeid(tolua_S,typeid(CCSprite), "CCSprite");
 tolua_usertype(tolua_S,"CCControlSwitch");
 Mtolua_typeid(tolua_S,typeid(CCControlSwitch), "CCControlSwitch");
}

/* method: getState of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControl_getState00
static int tolua_Cocos2d2_CCControl_getState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCControl* self = (const CCControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getState'", NULL);
#endif
  {
   unsigned int tolua_ret = ( unsigned int)  self->getState();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEnabled of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControl_setEnabled00
static int tolua_Cocos2d2_CCControl_setEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
  bool bEnabled = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEnabled'", NULL);
#endif
  {
   self->setEnabled(bEnabled);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isEnabled of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControl_isEnabled00
static int tolua_Cocos2d2_CCControl_isEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isEnabled'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isEnabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSelected of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControl_setSelected00
static int tolua_Cocos2d2_CCControl_setSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
  bool bSelected = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSelected'", NULL);
#endif
  {
   self->setSelected(bSelected);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isSelected of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControl_isSelected00
static int tolua_Cocos2d2_CCControl_isSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isSelected'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isSelected();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setHighlighted of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControl_setHighlighted00
static int tolua_Cocos2d2_CCControl_setHighlighted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
  bool bHighlighted = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setHighlighted'", NULL);
#endif
  {
   self->setHighlighted(bHighlighted);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setHighlighted'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isHighlighted of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControl_isHighlighted00
static int tolua_Cocos2d2_CCControl_isHighlighted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isHighlighted'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isHighlighted();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isHighlighted'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasVisibleParents of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControl_hasVisibleParents00
static int tolua_Cocos2d2_CCControl_hasVisibleParents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasVisibleParents'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasVisibleParents();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasVisibleParents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: needsLayout of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControl_needsLayout00
static int tolua_Cocos2d2_CCControl_needsLayout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'needsLayout'", NULL);
#endif
  {
   self->needsLayout();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'needsLayout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isOpacityModifyRGB of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControl_isOpacityModifyRGB00
static int tolua_Cocos2d2_CCControl_isOpacityModifyRGB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isOpacityModifyRGB'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isOpacityModifyRGB();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isOpacityModifyRGB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOpacityModifyRGB of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControl_setOpacityModifyRGB00
static int tolua_Cocos2d2_CCControl_setOpacityModifyRGB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
  bool bOpacityModifyRGB = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOpacityModifyRGB'", NULL);
#endif
  {
   self->setOpacityModifyRGB(bOpacityModifyRGB);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOpacityModifyRGB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendActionsForControlEvents of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControl_sendActionsForControlEvents00
static int tolua_Cocos2d2_CCControl_sendActionsForControlEvents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
  unsigned int controlEvents = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendActionsForControlEvents'", NULL);
#endif
  {
   self->sendActionsForControlEvents(controlEvents);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendActionsForControlEvents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTouchLocation of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControl_getTouchLocation00
static int tolua_Cocos2d2_CCControl_getTouchLocation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTouchLocation'", NULL);
#endif
  {
   CCPoint tolua_ret = (CCPoint)  self->getTouchLocation(touch);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTouchLocation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isTouchInside of class  CCControl */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControl_isTouchInside00
static int tolua_Cocos2d2_CCControl_isTouchInside00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControl",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControl* self = (CCControl*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isTouchInside'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isTouchInside(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isTouchInside'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCControlSwitch */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSwitch_new00
static int tolua_Cocos2d2_CCControlSwitch_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCControlSwitch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCControlSwitch* tolua_ret = (CCControlSwitch*)  Mtolua_new((CCControlSwitch)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCControlSwitch");
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

/* method: new_local of class  CCControlSwitch */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSwitch_new00_local
static int tolua_Cocos2d2_CCControlSwitch_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCControlSwitch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCControlSwitch* tolua_ret = (CCControlSwitch*)  Mtolua_new((CCControlSwitch)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCControlSwitch");
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

/* method: delete of class  CCControlSwitch */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSwitch_delete00
static int tolua_Cocos2d2_CCControlSwitch_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSwitch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSwitch* self = (CCControlSwitch*)  tolua_tousertype(tolua_S,1,0);
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

/* method: initWithMaskSprite of class  CCControlSwitch */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSwitch_initWithMaskSprite00
static int tolua_Cocos2d2_CCControlSwitch_initWithMaskSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSwitch",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"CCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"CCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSwitch* self = (CCControlSwitch*)  tolua_tousertype(tolua_S,1,0);
  CCSprite* maskSprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0));
  CCSprite* onSprite = ((CCSprite*)  tolua_tousertype(tolua_S,3,0));
  CCSprite* offSprite = ((CCSprite*)  tolua_tousertype(tolua_S,4,0));
  CCSprite* thumbSprite = ((CCSprite*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithMaskSprite'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithMaskSprite(maskSprite,onSprite,offSprite,thumbSprite);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithMaskSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCControlSwitch */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSwitch_create00
static int tolua_Cocos2d2_CCControlSwitch_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCControlSwitch",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"CCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"CCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSprite* maskSprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0));
  CCSprite* onSprite = ((CCSprite*)  tolua_tousertype(tolua_S,3,0));
  CCSprite* offSprite = ((CCSprite*)  tolua_tousertype(tolua_S,4,0));
  CCSprite* thumbSprite = ((CCSprite*)  tolua_tousertype(tolua_S,5,0));
  {
   CCControlSwitch* tolua_ret = (CCControlSwitch*)  CCControlSwitch::create(maskSprite,onSprite,offSprite,thumbSprite);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCControlSwitch");
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

/* method: initWithMaskSprite of class  CCControlSwitch */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSwitch_initWithMaskSprite01
static int tolua_Cocos2d2_CCControlSwitch_initWithMaskSprite01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSwitch",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"CCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"CCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,6,"CCLabelTTF",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,7,"CCLabelTTF",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CCControlSwitch* self = (CCControlSwitch*)  tolua_tousertype(tolua_S,1,0);
  CCSprite* maskSprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0));
  CCSprite* onSprite = ((CCSprite*)  tolua_tousertype(tolua_S,3,0));
  CCSprite* offSprite = ((CCSprite*)  tolua_tousertype(tolua_S,4,0));
  CCSprite* thumbSprite = ((CCSprite*)  tolua_tousertype(tolua_S,5,0));
  CCLabelTTF* onLabel = ((CCLabelTTF*)  tolua_tousertype(tolua_S,6,0));
  CCLabelTTF* offLabel = ((CCLabelTTF*)  tolua_tousertype(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithMaskSprite'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithMaskSprite(maskSprite,onSprite,offSprite,thumbSprite,onLabel,offLabel);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_Cocos2d2_CCControlSwitch_initWithMaskSprite00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCControlSwitch */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSwitch_create01
static int tolua_Cocos2d2_CCControlSwitch_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCControlSwitch",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"CCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"CCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,6,"CCLabelTTF",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,7,"CCLabelTTF",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CCSprite* maskSprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0));
  CCSprite* onSprite = ((CCSprite*)  tolua_tousertype(tolua_S,3,0));
  CCSprite* offSprite = ((CCSprite*)  tolua_tousertype(tolua_S,4,0));
  CCSprite* thumbSprite = ((CCSprite*)  tolua_tousertype(tolua_S,5,0));
  CCLabelTTF* onLabel = ((CCLabelTTF*)  tolua_tousertype(tolua_S,6,0));
  CCLabelTTF* offLabel = ((CCLabelTTF*)  tolua_tousertype(tolua_S,7,0));
  {
   CCControlSwitch* tolua_ret = (CCControlSwitch*)  CCControlSwitch::create(maskSprite,onSprite,offSprite,thumbSprite,onLabel,offLabel);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCControlSwitch");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Cocos2d2_CCControlSwitch_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOn of class  CCControlSwitch */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSwitch_setOn00
static int tolua_Cocos2d2_CCControlSwitch_setOn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSwitch",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSwitch* self = (CCControlSwitch*)  tolua_tousertype(tolua_S,1,0);
  bool isOn = ((bool)  tolua_toboolean(tolua_S,2,0));
  bool animated = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOn'", NULL);
#endif
  {
   self->setOn(isOn,animated);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOn of class  CCControlSwitch */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSwitch_setOn01
static int tolua_Cocos2d2_CCControlSwitch_setOn01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSwitch",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CCControlSwitch* self = (CCControlSwitch*)  tolua_tousertype(tolua_S,1,0);
  bool isOn = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOn'", NULL);
#endif
  {
   self->setOn(isOn);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Cocos2d2_CCControlSwitch_setOn00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: isOn of class  CCControlSwitch */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSwitch_isOn00
static int tolua_Cocos2d2_CCControlSwitch_isOn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSwitch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSwitch* self = (CCControlSwitch*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isOn'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isOn();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isOn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasMoved of class  CCControlSwitch */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSwitch_hasMoved00
static int tolua_Cocos2d2_CCControlSwitch_hasMoved00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSwitch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSwitch* self = (CCControlSwitch*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasMoved'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasMoved();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasMoved'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEnabled of class  CCControlSwitch */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSwitch_setEnabled00
static int tolua_Cocos2d2_CCControlSwitch_setEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSwitch",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSwitch* self = (CCControlSwitch*)  tolua_tousertype(tolua_S,1,0);
  bool enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEnabled'", NULL);
#endif
  {
   self->setEnabled(enabled);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: locationFromTouch of class  CCControlSwitch */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSwitch_locationFromTouch00
static int tolua_Cocos2d2_CCControlSwitch_locationFromTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSwitch",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSwitch* self = (CCControlSwitch*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'locationFromTouch'", NULL);
#endif
  {
   CCPoint tolua_ret = (CCPoint)  self->locationFromTouch(touch);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'locationFromTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getValue of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_getValue00
static int tolua_Cocos2d2_CCControlSlider_getValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCControlSlider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCControlSlider* self = (const CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getValue'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setValue of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_setValue00
static int tolua_Cocos2d2_CCControlSlider_setValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSlider* self = (CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
  float val = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setValue'", NULL);
#endif
  {
   self->setValue(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMinimumValue of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_getMinimumValue00
static int tolua_Cocos2d2_CCControlSlider_getMinimumValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCControlSlider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCControlSlider* self = (const CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMinimumValue'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getMinimumValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMinimumValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMinimumValue of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_setMinimumValue00
static int tolua_Cocos2d2_CCControlSlider_setMinimumValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSlider* self = (CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
  float val = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMinimumValue'", NULL);
#endif
  {
   self->setMinimumValue(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMinimumValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMaximumValue of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_getMaximumValue00
static int tolua_Cocos2d2_CCControlSlider_getMaximumValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCControlSlider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCControlSlider* self = (const CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMaximumValue'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getMaximumValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMaximumValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMaximumValue of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_setMaximumValue00
static int tolua_Cocos2d2_CCControlSlider_setMaximumValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSlider* self = (CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
  float val = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMaximumValue'", NULL);
#endif
  {
   self->setMaximumValue(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMaximumValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEnabled of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_setEnabled00
static int tolua_Cocos2d2_CCControlSlider_setEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSlider* self = (CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
  bool enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEnabled'", NULL);
#endif
  {
   self->setEnabled(enabled);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isTouchInside of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_isTouchInside00
static int tolua_Cocos2d2_CCControlSlider_isTouchInside00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSlider* self = (CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isTouchInside'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isTouchInside(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isTouchInside'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: locationFromTouch of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_locationFromTouch00
static int tolua_Cocos2d2_CCControlSlider_locationFromTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSlider* self = (CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'locationFromTouch'", NULL);
#endif
  {
   CCPoint tolua_ret = (CCPoint)  self->locationFromTouch(touch);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'locationFromTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMinimumAllowedValue of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_setMinimumAllowedValue00
static int tolua_Cocos2d2_CCControlSlider_setMinimumAllowedValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSlider* self = (CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMinimumAllowedValue'", NULL);
#endif
  {
   self->setMinimumAllowedValue(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMinimumAllowedValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMinimumAllowedValue of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_getMinimumAllowedValue00
static int tolua_Cocos2d2_CCControlSlider_getMinimumAllowedValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCControlSlider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCControlSlider* self = (const CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMinimumAllowedValue'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getMinimumAllowedValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMinimumAllowedValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMaximumAllowedValue of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_setMaximumAllowedValue00
static int tolua_Cocos2d2_CCControlSlider_setMaximumAllowedValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSlider* self = (CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMaximumAllowedValue'", NULL);
#endif
  {
   self->setMaximumAllowedValue(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMaximumAllowedValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMaximumAllowedValue of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_getMaximumAllowedValue00
static int tolua_Cocos2d2_CCControlSlider_getMaximumAllowedValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCControlSlider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCControlSlider* self = (const CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMaximumAllowedValue'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getMaximumAllowedValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMaximumAllowedValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setThumbSprite of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_setThumbSprite00
static int tolua_Cocos2d2_CCControlSlider_setThumbSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSlider* self = (CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
  CCSprite* sprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setThumbSprite'", NULL);
#endif
  {
   self->setThumbSprite(sprite);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setThumbSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getThumbSprite of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_getThumbSprite00
static int tolua_Cocos2d2_CCControlSlider_getThumbSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCControlSlider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCControlSlider* self = (const CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getThumbSprite'", NULL);
#endif
  {
   CCSprite* tolua_ret = (CCSprite*)  self->getThumbSprite();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getThumbSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setProgressSprite of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_setProgressSprite00
static int tolua_Cocos2d2_CCControlSlider_setProgressSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSlider* self = (CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
  CCSprite* sprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setProgressSprite'", NULL);
#endif
  {
   self->setProgressSprite(sprite);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setProgressSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getProgressSprite of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_getProgressSprite00
static int tolua_Cocos2d2_CCControlSlider_getProgressSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCControlSlider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCControlSlider* self = (const CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getProgressSprite'", NULL);
#endif
  {
   CCSprite* tolua_ret = (CCSprite*)  self->getProgressSprite();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getProgressSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBackgroundSprite of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_setBackgroundSprite00
static int tolua_Cocos2d2_CCControlSlider_setBackgroundSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSlider* self = (CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
  CCSprite* sprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBackgroundSprite'", NULL);
#endif
  {
   self->setBackgroundSprite(sprite);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBackgroundSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBackgroundSprite of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_getBackgroundSprite00
static int tolua_Cocos2d2_CCControlSlider_getBackgroundSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCControlSlider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCControlSlider* self = (const CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBackgroundSprite'", NULL);
#endif
  {
   CCSprite* tolua_ret = (CCSprite*)  self->getBackgroundSprite();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBackgroundSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_new00
static int tolua_Cocos2d2_CCControlSlider_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCControlSlider* tolua_ret = (CCControlSlider*)  Mtolua_new((CCControlSlider)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCControlSlider");
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

/* method: new_local of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_new00_local
static int tolua_Cocos2d2_CCControlSlider_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCControlSlider* tolua_ret = (CCControlSlider*)  Mtolua_new((CCControlSlider)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCControlSlider");
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

/* method: delete of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_delete00
static int tolua_Cocos2d2_CCControlSlider_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSlider* self = (CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
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

/* method: initWithSprites of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_initWithSprites00
static int tolua_Cocos2d2_CCControlSlider_initWithSprites00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"CCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSlider* self = (CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
  CCSprite* backgroundSprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0));
  CCSprite* progressSprite = ((CCSprite*)  tolua_tousertype(tolua_S,3,0));
  CCSprite* thumbSprite = ((CCSprite*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithSprites'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithSprites(backgroundSprite,progressSprite,thumbSprite);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithSprites'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_create00
static int tolua_Cocos2d2_CCControlSlider_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* bgFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* progressFile = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* thumbFile = ((const char*)  tolua_tostring(tolua_S,4,0));
  {
   CCControlSlider* tolua_ret = (CCControlSlider*)  CCControlSlider::create(bgFile,progressFile,thumbFile);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCControlSlider");
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

/* method: create of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_create01
static int tolua_Cocos2d2_CCControlSlider_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"CCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CCSprite* backgroundSprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0));
  CCSprite* pogressSprite = ((CCSprite*)  tolua_tousertype(tolua_S,3,0));
  CCSprite* thumbSprite = ((CCSprite*)  tolua_tousertype(tolua_S,4,0));
  {
   CCControlSlider* tolua_ret = (CCControlSlider*)  CCControlSlider::create(backgroundSprite,pogressSprite,thumbSprite);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCControlSlider");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Cocos2d2_CCControlSlider_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: needsLayout of class  CCControlSlider */
#ifndef TOLUA_DISABLE_tolua_Cocos2d2_CCControlSlider_needsLayout00
static int tolua_Cocos2d2_CCControlSlider_needsLayout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCControlSlider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCControlSlider* self = (CCControlSlider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'needsLayout'", NULL);
#endif
  {
   self->needsLayout();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'needsLayout'.",&tolua_err);
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
  tolua_constant(tolua_S,"CCControlEventTouchDown",CCControlEventTouchDown);
  tolua_constant(tolua_S,"CCControlEventTouchDragInside",CCControlEventTouchDragInside);
  tolua_constant(tolua_S,"CCControlEventTouchDragOutside",CCControlEventTouchDragOutside);
  tolua_constant(tolua_S,"CCControlEventTouchDragEnter",CCControlEventTouchDragEnter);
  tolua_constant(tolua_S,"CCControlEventTouchDragExit",CCControlEventTouchDragExit);
  tolua_constant(tolua_S,"CCControlEventTouchUpInside",CCControlEventTouchUpInside);
  tolua_constant(tolua_S,"CCControlEventTouchUpOutside",CCControlEventTouchUpOutside);
  tolua_constant(tolua_S,"CCControlEventTouchCancel",CCControlEventTouchCancel);
  tolua_constant(tolua_S,"CCControlEventValueChanged",CCControlEventValueChanged);
  tolua_constant(tolua_S,"CCControlStateNormal",CCControlStateNormal);
  tolua_constant(tolua_S,"CCControlStateHighlighted",CCControlStateHighlighted);
  tolua_constant(tolua_S,"CCControlStateDisabled",CCControlStateDisabled);
  tolua_constant(tolua_S,"CCControlStateSelected",CCControlStateSelected);
  tolua_cclass(tolua_S,"CCControl","CCControl","CCLayerRGBA",NULL);
  tolua_beginmodule(tolua_S,"CCControl");
   tolua_function(tolua_S,"getState",tolua_Cocos2d2_CCControl_getState00);
   tolua_function(tolua_S,"setEnabled",tolua_Cocos2d2_CCControl_setEnabled00);
   tolua_function(tolua_S,"isEnabled",tolua_Cocos2d2_CCControl_isEnabled00);
   tolua_function(tolua_S,"setSelected",tolua_Cocos2d2_CCControl_setSelected00);
   tolua_function(tolua_S,"isSelected",tolua_Cocos2d2_CCControl_isSelected00);
   tolua_function(tolua_S,"setHighlighted",tolua_Cocos2d2_CCControl_setHighlighted00);
   tolua_function(tolua_S,"isHighlighted",tolua_Cocos2d2_CCControl_isHighlighted00);
   tolua_function(tolua_S,"hasVisibleParents",tolua_Cocos2d2_CCControl_hasVisibleParents00);
   tolua_function(tolua_S,"needsLayout",tolua_Cocos2d2_CCControl_needsLayout00);
   tolua_function(tolua_S,"isOpacityModifyRGB",tolua_Cocos2d2_CCControl_isOpacityModifyRGB00);
   tolua_function(tolua_S,"setOpacityModifyRGB",tolua_Cocos2d2_CCControl_setOpacityModifyRGB00);
   tolua_function(tolua_S,"sendActionsForControlEvents",tolua_Cocos2d2_CCControl_sendActionsForControlEvents00);
   tolua_function(tolua_S,"getTouchLocation",tolua_Cocos2d2_CCControl_getTouchLocation00);
   tolua_function(tolua_S,"isTouchInside",tolua_Cocos2d2_CCControl_isTouchInside00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCControlSwitch","CCControlSwitch","CCControl",tolua_collect_CCControlSwitch);
  #else
  tolua_cclass(tolua_S,"CCControlSwitch","CCControlSwitch","CCControl",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCControlSwitch");
   tolua_function(tolua_S,"new",tolua_Cocos2d2_CCControlSwitch_new00);
   tolua_function(tolua_S,"new_local",tolua_Cocos2d2_CCControlSwitch_new00_local);
   tolua_function(tolua_S,".call",tolua_Cocos2d2_CCControlSwitch_new00_local);
   tolua_function(tolua_S,"delete",tolua_Cocos2d2_CCControlSwitch_delete00);
   tolua_function(tolua_S,"initWithMaskSprite",tolua_Cocos2d2_CCControlSwitch_initWithMaskSprite00);
   tolua_function(tolua_S,"create",tolua_Cocos2d2_CCControlSwitch_create00);
   tolua_function(tolua_S,"initWithMaskSprite",tolua_Cocos2d2_CCControlSwitch_initWithMaskSprite01);
   tolua_function(tolua_S,"create",tolua_Cocos2d2_CCControlSwitch_create01);
   tolua_function(tolua_S,"setOn",tolua_Cocos2d2_CCControlSwitch_setOn00);
   tolua_function(tolua_S,"setOn",tolua_Cocos2d2_CCControlSwitch_setOn01);
   tolua_function(tolua_S,"isOn",tolua_Cocos2d2_CCControlSwitch_isOn00);
   tolua_function(tolua_S,"hasMoved",tolua_Cocos2d2_CCControlSwitch_hasMoved00);
   tolua_function(tolua_S,"setEnabled",tolua_Cocos2d2_CCControlSwitch_setEnabled00);
   tolua_function(tolua_S,"locationFromTouch",tolua_Cocos2d2_CCControlSwitch_locationFromTouch00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCControlSlider","CCControlSlider","CCControl",tolua_collect_CCControlSlider);
  #else
  tolua_cclass(tolua_S,"CCControlSlider","CCControlSlider","CCControl",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCControlSlider");
   tolua_function(tolua_S,"getValue",tolua_Cocos2d2_CCControlSlider_getValue00);
   tolua_function(tolua_S,"setValue",tolua_Cocos2d2_CCControlSlider_setValue00);
   tolua_function(tolua_S,"getMinimumValue",tolua_Cocos2d2_CCControlSlider_getMinimumValue00);
   tolua_function(tolua_S,"setMinimumValue",tolua_Cocos2d2_CCControlSlider_setMinimumValue00);
   tolua_function(tolua_S,"getMaximumValue",tolua_Cocos2d2_CCControlSlider_getMaximumValue00);
   tolua_function(tolua_S,"setMaximumValue",tolua_Cocos2d2_CCControlSlider_setMaximumValue00);
   tolua_function(tolua_S,"setEnabled",tolua_Cocos2d2_CCControlSlider_setEnabled00);
   tolua_function(tolua_S,"isTouchInside",tolua_Cocos2d2_CCControlSlider_isTouchInside00);
   tolua_function(tolua_S,"locationFromTouch",tolua_Cocos2d2_CCControlSlider_locationFromTouch00);
   tolua_function(tolua_S,"setMinimumAllowedValue",tolua_Cocos2d2_CCControlSlider_setMinimumAllowedValue00);
   tolua_function(tolua_S,"getMinimumAllowedValue",tolua_Cocos2d2_CCControlSlider_getMinimumAllowedValue00);
   tolua_function(tolua_S,"setMaximumAllowedValue",tolua_Cocos2d2_CCControlSlider_setMaximumAllowedValue00);
   tolua_function(tolua_S,"getMaximumAllowedValue",tolua_Cocos2d2_CCControlSlider_getMaximumAllowedValue00);
   tolua_function(tolua_S,"setThumbSprite",tolua_Cocos2d2_CCControlSlider_setThumbSprite00);
   tolua_function(tolua_S,"getThumbSprite",tolua_Cocos2d2_CCControlSlider_getThumbSprite00);
   tolua_function(tolua_S,"setProgressSprite",tolua_Cocos2d2_CCControlSlider_setProgressSprite00);
   tolua_function(tolua_S,"getProgressSprite",tolua_Cocos2d2_CCControlSlider_getProgressSprite00);
   tolua_function(tolua_S,"setBackgroundSprite",tolua_Cocos2d2_CCControlSlider_setBackgroundSprite00);
   tolua_function(tolua_S,"getBackgroundSprite",tolua_Cocos2d2_CCControlSlider_getBackgroundSprite00);
   tolua_function(tolua_S,"new",tolua_Cocos2d2_CCControlSlider_new00);
   tolua_function(tolua_S,"new_local",tolua_Cocos2d2_CCControlSlider_new00_local);
   tolua_function(tolua_S,".call",tolua_Cocos2d2_CCControlSlider_new00_local);
   tolua_function(tolua_S,"delete",tolua_Cocos2d2_CCControlSlider_delete00);
   tolua_function(tolua_S,"initWithSprites",tolua_Cocos2d2_CCControlSlider_initWithSprites00);
   tolua_function(tolua_S,"create",tolua_Cocos2d2_CCControlSlider_create00);
   tolua_function(tolua_S,"create",tolua_Cocos2d2_CCControlSlider_create01);
   tolua_function(tolua_S,"needsLayout",tolua_Cocos2d2_CCControlSlider_needsLayout00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Cocos2d2 (lua_State* tolua_S) {
 return tolua_Cocos2d2_open(tolua_S);
};
#endif


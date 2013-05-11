#ifndef OBJ_ANIMAL_H
#define OBJ_ANIMAL_H

#include "Obj_Unit.h"
#include "Animal.h"
#include "cocoa/CCArray.h"

typedef void (cocos2d::CCObject::*MoveEndCallBackFunc)(cocos2d::CCObject* pTarget);

class Obj_Animal: public Obj_Unit
{
public:
	Obj_Animal();
	virtual ~Obj_Animal();
	static Obj_Animal* create();
	virtual bool init();
	virtual void initPart(int skinid, int part /* = PART_BODY */);

	static OBJ_DIR getDirection(float sx, float sy,float ex, float ey);

	virtual bool touchCatch(cocos2d::CCPoint& point);

	virtual void doAttack(Obj_Unit* pUnit);

	virtual void update(float dt);
	void updateMove(float dt);
	virtual void onMoving();
	virtual void onMoveEnd();
public:
	virtual void setPath(cocos2d::CCArray* pPath,MoveEndCallBackFunc callback = NULL, cocos2d::CCObject* pTarget = NULL);
	virtual void setPath(cocos2d::CCPoint* pPath,MoveEndCallBackFunc callback = NULL, cocos2d::CCObject* pTarget = NULL);
	CC_SYNTHESIZE(int,m_moveSpeed,MoveSpeed);
	virtual void setAction(OBJ_ACTION action /* = ACTION_STAND */);

	Animal* getAnimal(){return m_pAnimal;}

	CC_SYNTHESIZE_RETAIN(Obj_Unit*,m_pTargetAnimal,TargetAnimal);
private:
	Animal* m_pAnimal;

	//走路相关
protected:
	virtual void generalRunValue();
	cocos2d::CCArray* m_pPath;
	cocos2d::CCPoint* _pEndTarget;
	bool _isMoving;
	OBJ_DIR _nowDir;
	float _endX;
	float _endY;
	float _speedX;
	float _speedY;
	float _totalTime;
	MoveEndCallBackFunc _endCallback;
	cocos2d::CCObject* _endTarget;
};
#endif
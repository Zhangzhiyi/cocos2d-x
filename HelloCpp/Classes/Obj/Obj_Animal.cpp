#include "Obj_Animal.h"
#include "Animal_One.h"
#include "Scene/MapScene.h"

USING_NS_CC;

OBJ_DIR Obj_Animal::getDirection(float sx, float sy,float ex, float ey)
{
	OBJ_DIR result = DIR_TOP;
	float x1  = ex - sx;
	float y1 = ey - sy;
	double angle = atan2(y1,x1) * 180 / PI;
	if(angle >= -112.5f && angle < -67.5f)
		result = DIR_TOP;
	else if(angle >= -67.5f && angle < -22.5f)
		result = DIR_TOP_RIGHT;
	else if(angle >= -22.5f && angle < 22.5f)
		result = DIR_RIGHT;
	else if(angle >= 22.5f && angle < 67.5f)
		result = DIR_BOTTOM_RIGHT;
	else if(angle >= 67.5f && angle < 112.5f)
		result = DIR_BOTTOM;
	else if(angle >= 112.5f &&  angle < 157.5f)
		result = DIR_BOTTOM_LEFT;
	else if(angle >= 157.5f || angle <-157.5f)
		result = DIR_LEFT;
	else if(angle >= -157.5f && angle < -112.5f)
		result = DIR_TOP_LEFT;

	return result;
}

Obj_Animal::Obj_Animal()
{
	m_pAnimal = NULL;
	m_pTargetAnimal = NULL;
	_endX = _endY = _speedX = _speedY = _totalTime = 0.0f;
	_nowDir = DIR_BOTTOM;
	_isMoving = false;
	_pEndTarget = NULL;
	_endCallback = NULL;
	_endTarget = NULL;
	m_pPath = CCArray::create();
	m_pPath->retain();
}

Obj_Animal::~Obj_Animal()
{
	CC_SAFE_RELEASE(m_pPath);
	CC_SAFE_RELEASE(m_pTargetAnimal);
}

bool Obj_Animal::init()
{
	Obj_Unit::init();
	m_pAnimal = Animal_One::create(this);
	this->setAction(ACTION_ATTACK);
	this->setDir(DIR_BOTTOM_LEFT);
	this->setMoveSpeed(300);
	m_pAnimal->retain();
	return true;
}

void Obj_Animal::initPart(int skinid, int part )
{
	if(m_pAnimal != NULL)
		m_pAnimal->initPart(skinid,(ANIMAL_PART)part);
}

bool Obj_Animal::touchCatch(cocos2d::CCPoint& point)
{
	CCPoint heroPoint = convertToNodeSpace(point);

	CCSprite* pAnimal = dynamic_cast<CCSprite*>(m_pAnimal);

	if(pAnimal != NULL)
	{
		CCPoint offsetPoint = pAnimal->getOffsetPosition();
		CCRect rect = pAnimal->getTextureRect();

		CCPoint anchorPoint = pAnimal->getAnchorPoint();
		CCSize size = pAnimal->getContentSize();
		
		if(pAnimal->getScaleX() == 1.0f)
		{
			CCRect myRect(offsetPoint.x - size.width * anchorPoint.x, offsetPoint.y - size.height * anchorPoint.y,
				rect.size.width,rect.size.height);
			return myRect.containsPoint(heroPoint);
		}
		else if(pAnimal->getScaleX() == -1.0f)
		{
			CCRect myRect(size.width * anchorPoint.x - rect.size.width - offsetPoint.x, offsetPoint.y - size.height * anchorPoint.y,
				rect.size.width,rect.size.height);
			return myRect.containsPoint(heroPoint);
		}
	}

	return false;
}

Obj_Animal* Obj_Animal::create()
{
	Obj_Animal* pResult = new Obj_Animal();
	pResult->init();
	pResult->autorelease();
	return pResult;
}

void Obj_Animal::update(float dt)
{
	if(m_pAnimal != NULL)
		m_pAnimal->update(dt,m_action,m_dir);
	if(_isMoving)
		updateMove(dt);
}

void Obj_Animal::setPath(cocos2d::CCArray* pPath,MoveEndCallBackFunc callback /* = NULL */, cocos2d::CCObject* pTarget /* = NULL */)
{
	m_pPath->removeAllObjects();
	m_pPath->addObjectsFromArray(pPath);
	_endCallback = callback;
	_endTarget = pTarget;
	if(pTarget != NULL)
		pTarget->retain();
	if(m_pPath->count() > 0)
		generalRunValue();
}

void Obj_Animal::setPath(cocos2d::CCPoint* pPath,MoveEndCallBackFunc callback /* = NULL */, cocos2d::CCObject* pTarget /* = NULL */)
{
	m_pPath->removeAllObjects();
	m_pPath->addObject(pPath);
	_endCallback = callback;
	_endTarget = pTarget;
	if(pTarget != NULL)
		pTarget->retain();
	if(m_pPath->count() > 0)
		generalRunValue();
}

void Obj_Animal::generalRunValue()
{
	_isMoving = true;
	if(_pEndTarget != NULL)
	{
		_pEndTarget->release();
		_pEndTarget = NULL;
	}

	_pEndTarget = dynamic_cast<CCPoint*>(m_pPath->objectAtIndex(0));
	if(_pEndTarget)
	{
		_pEndTarget->retain();
		m_pPath->removeObjectAtIndex(0);
		_endX = _pEndTarget->x;
		_endY = _pEndTarget->y;
		float distance = sqrt((_endX - getPositionX()) * (_endX - getPositionX()) + (_endY - getPositionY()) * (_endY - getPositionY()));
		//如果距离小于1.0
		/*if(distance < 1.0f)
		{
			if(m_pPath->count() > 0) generalRunValue();
			else
			{
				_isMoving = false;
				if(this->m_action != ACTION_SIT)
					this->setAction(ACTION_STAND);
			}
			return;
		}*/
		
		m_dir= getDirection(getPositionX(),getPositionY(), _endX, _endY);
		_nowDir = m_dir;
		_totalTime = distance / m_moveSpeed;
		_speedX = (_endX - getPositionX()) / _totalTime;
		_speedY = (_endY - getPositionY()) / _totalTime;
		this->setAction(ACTION_RUN);
	}
}

void Obj_Animal::updateMove(float dt)
{
	if(_totalTime <= dt)
	{
		this->setPosition(_endX,_endY);
		if(m_pPath->count() > 0)
			generalRunValue();
		else
			_isMoving = false;
	}
	else
	{
		float currentX = this->getPositionX();
		float currentY = this->getPositionY();
		currentX +=dt*_speedX;
		currentY +=dt*_speedY;
		this->setPosition(currentX,currentY);
		_totalTime -= dt;
	}

	onMoving();

	if(m_dir != _nowDir)
		setDir(_nowDir);

	if(_isMoving == false)
		this->setAction(ACTION_STAND);

}

void Obj_Animal::setAction(OBJ_ACTION action )
{
	if(m_action == action) return;
	if(m_action != ACTION_STAND && action == ACTION_HIT)
		return;
	if(m_action == ACTION_RUN && action != ACTION_RUN)
	{
		Obj_Unit::setAction(action);
		onMoveEnd();
		if(_endCallback != NULL && _endTarget != NULL)
		{
			CCObject* pTemp = _endTarget;
			MoveEndCallBackFunc tempCallback = _endCallback;
			_endTarget = NULL;
			_endCallback = NULL;
			(pTemp->*tempCallback)(this);
			pTemp->release();
		}
	}
	else
	{
		Obj_Unit::setAction(action);
	}

	if(m_pAnimal != NULL)
		m_pAnimal->reset();
}

void Obj_Animal::onMoveEnd()
{
	if(m_pTargetAnimal != NULL)
		doAttack(m_pTargetAnimal);
}


void Obj_Animal::onMoving()
{
	if(this == MapScene::sharedMapScene()->getHero())
		MapScene::sharedMapScene()->center(getPositionX(),getPositionY());
}

void Obj_Animal::doAttack(Obj_Unit *pUnit)
{
	setTargetAnimal(pUnit);
	float dis = sqrt((pUnit->getPositionX() - this->getPositionX()) *(pUnit->getPositionX() - this->getPositionX()) + (pUnit->getPositionY() - this->getPositionY()) * (pUnit->getPositionY() - this->getPositionY()));
	if(dis < 200)
	{
		this->setDir(getDirection(getPositionX(),getPositionY(),pUnit->getPositionX(),pUnit->getPositionY()));
		this->setAction(ACTION_ATTACK);
		pUnit->setDir(getDirection(pUnit->getPositionX(),pUnit->getPositionY(),getPositionX(),getPositionY()));
		pUnit->setAction(ACTION_HIT);
		pUnit->addEffect("jingganglianhuanzhan",0,0,1);
		setTargetAnimal(NULL);
	}
	else
	{
		float destX = getPositionX() + (dis - 199) / dis * (pUnit->getPositionX() - getPositionX());
		float destY = getPositionY() + (dis - 199) / dis * (pUnit->getPositionY() - getPositionY());
		CCPoint* dest = new CCPoint(destX,destY);
		dest->autorelease();
		this->setPath(dest);
	}
}
#ifndef MAP_NODE_H
#define MAP_NODE_H
#include "base_nodes/CCNode.h"

//主要是重新实现了CCNode的children排序功能
class MapNode : public cocos2d::CCNode
{
public:
	MapNode();
	~MapNode();

	virtual void sortAllChildren();
	
	static MapNode* create();
private:
	//如果p1应该在前，返回true，否则返回false
	bool sortFunc(cocos2d::CCNode* p1,cocos2d::CCNode* p2);
	unsigned int m_sortIndex;
};


#endif
#ifndef MAP_NODE_H
#define MAP_NODE_H
#include "base_nodes/CCNode.h"

//��Ҫ������ʵ����CCNode��children������
class MapNode : public cocos2d::CCNode
{
public:
	MapNode();
	~MapNode();

	virtual void sortAllChildren();
	
	static MapNode* create();
private:
	//���p1Ӧ����ǰ������true�����򷵻�false
	bool sortFunc(cocos2d::CCNode* p1,cocos2d::CCNode* p2);
	unsigned int m_sortIndex;
};


#endif
#include "MapNode.h"
#include "Obj/Obj_Unit.h"

USING_NS_CC;

MapNode::MapNode() : m_sortIndex(0)
{

}

MapNode::~MapNode()
{

}

MapNode* MapNode::create()
{
	MapNode* pResult = new MapNode();
	pResult->autorelease();
	return pResult;
}

void MapNode::sortAllChildren()
{
	m_sortIndex++;
	if (m_sortIndex % 10 == 0)
	{
		int i,j,length = m_pChildren->data->num;
		CCNode ** x = (CCNode**)m_pChildren->data->arr;
		CCNode *tempItem;

		// insertion sort
		for(i=1; i<length; i++)
		{
			tempItem = x[i];
			j = i-1;

			while(j>=0 && sortFunc(tempItem,x[j]))
			{
				x[j+1] = x[j];
				j = j-1;
			}
			x[j+1] = tempItem;
		}
	}
}

bool MapNode::sortFunc(cocos2d::CCNode* p1,cocos2d::CCNode* p2)
{
	if(p1->getPositionY() < p2->getPositionY())
		return true;
	return false;
}
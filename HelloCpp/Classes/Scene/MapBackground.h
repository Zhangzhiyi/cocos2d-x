#ifndef MAP_BACKGROUND_H
#define MAP_BACKGROUD_H

#include "cocos2d.h"

#define MAP_CELL_WIDTH 300
#define MAP_CELL_HEIGHT 300

USING_NS_CC;


extern void setSpriteTexture(CCSprite* pSprite, CCTexture2D* pTexture);
extern void setSpriteTexture(CCSprite* pSprite, const char* pFileName);

class MapBackground : public CCNode
{
public:
	MapBackground();
	~MapBackground();

	static MapBackground* sharedMapBackground();

public:
	void center(float x, float y);

	CC_SYNTHESIZE(int,m_cellsNum,CellsNum);
	CC_SYNTHESIZE(int, m_cellsWidth, CellsWidth);
	CC_SYNTHESIZE(int, m_cellsHeight, CellsHeight);
	CC_SYNTHESIZE(CCSize, m_winSize,WinSize);

	void setMapSize(int width, int height);

	int getMapWidth(){return m_mapWidth;}
	int getMapHeight(){return m_mapHeight;}
public:
	virtual bool init();
private:
	CCArray* m_pArray;
	int m_mapWidth;
	int m_mapHeight;
	int m_mapCellsWidth;
	int m_mapCellsHeight;
};

#endif
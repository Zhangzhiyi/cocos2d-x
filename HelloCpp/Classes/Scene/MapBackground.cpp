#include "MapBackground.h"
#include "cocoa/CCArray.h"
#include "CCDirector.h"
#include "sprite_nodes/CCSprite.h"
#include "support/CCPointExtension.h"
#include "textures/CCTextureCache.h"
#include "textures/CCTexture2D.h"

static MapBackground* m_gMapBackground = 0;

void setSpriteTexture(CCSprite* pSprite, CCTexture2D* pTexture)
{
	CCRect rect = CCRectZero;
	if(pTexture != 0)
		rect.size = pTexture->getContentSize();

	pSprite->setTexture(pTexture);
	pSprite->setTextureRect(rect,false,rect.size);
}

void setSpriteTexture(CCSprite* pSprite, const char* pFileName)
{
	CCTexture2D* pTexture = CCTextureCache::sharedTextureCache()->addImage(pFileName);
	setSpriteTexture(pSprite,pTexture);
}

MapBackground::MapBackground()
{
	m_pArray = 0;
	m_mapHeight = m_mapWidth=m_mapCellsWidth = m_mapCellsHeight = 0;
}

MapBackground::~MapBackground()
{
	CC_SAFE_RELEASE(m_pArray);
}

MapBackground* MapBackground::sharedMapBackground()
{
	if(m_gMapBackground == 0)
	{
		m_gMapBackground = new MapBackground();
		m_gMapBackground->init();
	}

	return m_gMapBackground;
}

bool MapBackground::init()
{
	 m_winSize = CCDirector::sharedDirector()->getWinSize();
	m_cellsWidth = (int)m_winSize.width % MAP_CELL_WIDTH ? (int)m_winSize.width / MAP_CELL_WIDTH + 2 : (int)m_winSize.width / MAP_CELL_WIDTH + 1;
	m_cellsHeight = (int)m_winSize.height % MAP_CELL_HEIGHT ? (int)m_winSize.height / MAP_CELL_HEIGHT + 2 : (int)m_winSize.height / MAP_CELL_WIDTH + 1;
	m_pArray = CCArray::createWithCapacity(m_cellsWidth * m_cellsHeight);
	m_pArray->retain();

	m_cellsNum = m_cellsWidth * m_cellsHeight;
	char buffer[15] = {0};
	for(int i = 0; i < m_cellsHeight; i++)
	{
		for(int j = 0; j < m_cellsWidth; j++)
		{
			sprintf(buffer,"%d_%d.jpg",i,j);
			CCSprite* cell = CCSprite::create(buffer);
			cell->setScaleY(-1.0f);
			cell->setAnchorPoint(ccp(0,1));
			cell->setPosition(ccp(j*MAP_CELL_WIDTH,i*MAP_CELL_HEIGHT));
			this->addChild(cell);
			m_pArray->addObject(cell);	
		}
	}

	this->setScaleY(-1);
	this->setPositionY(m_winSize.height);
	return true;
}

void MapBackground::setMapSize(int width, int height)
{
	m_mapWidth = width;
	m_mapHeight = height;
	m_mapCellsWidth = m_mapWidth % MAP_CELL_WIDTH ? 
		m_mapWidth / MAP_CELL_WIDTH + 1 : m_mapWidth / MAP_CELL_WIDTH;
	m_mapCellsHeight = m_mapHeight % MAP_CELL_HEIGHT ?
		m_mapHeight / MAP_CELL_HEIGHT + 1 : m_mapHeight / MAP_CELL_HEIGHT;
	
	char buffer[15] = {0};
	for(int i = 0; i < m_mapCellsHeight; i++)
	{
		for(int j = 0; j < m_mapCellsWidth; j++)
		{
			sprintf(buffer,"%d_%d.jpg",i,j);
			CCTextureCache::sharedTextureCache()->addImage(buffer);
		}
	}
}

void MapBackground::center(float heroX, float heroY)
{
	int mapX = m_winSize.width / 2 - heroX;
	int mapY = m_winSize.height / 2 + heroY;

	//超屏检测
	if(mapX > 0) mapX = 0;
	else if(mapX < m_winSize.width - m_mapWidth) mapX = m_winSize.width - m_mapWidth;

	if(mapY < m_winSize.height) mapY = m_winSize.height;
	else if(mapY >m_mapHeight) mapY = m_mapHeight;
	
	//currentX，Y、代表背景的X、Y值，indexX，indexY代表背景开始的cell index
	int currentX = mapX % MAP_CELL_WIDTH;
	int currentY = int(mapY - m_winSize.height) % MAP_CELL_HEIGHT + m_winSize.height;
	int indexX = -mapX / MAP_CELL_WIDTH;
	int indexY = (mapY - m_winSize.height) / MAP_CELL_HEIGHT;

	
	char buffer[15] = {0};
	int childIndex = 0;
	
	for(int i = indexY; i < indexY + m_cellsHeight; i++)
	{
		for(int j = indexX; j < indexX + m_cellsWidth; j++)
		{
			sprintf(buffer,"%d_%d.jpg",i,j);
			CCSprite* child = dynamic_cast<CCSprite*>(m_pArray->data->arr[childIndex++]);
			if(child != 0)
			{
				if(i < m_mapCellsHeight && j < m_mapCellsWidth)
					setSpriteTexture(child,buffer);
				else
					setSpriteTexture(child,(CCTexture2D*)0);
			}
		}
	}

	this->setPosition(currentX,currentY);
}


#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "Map.h"

namespace game_framework{

	static int map[32][32] = {
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{2,0,0,0,0,0,2,0,0,0,0,0,2,0,0,2,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,2}, //1
		{2,0,0,2,1,1,1,0,0,2,0,1,2,1,1,2,0,0,2,0,0,0,2,0,2,0,0,2,2,0,0,2},
		{2,0,1,2,0,0,2,2,2,2,1,1,2,2,2,2,0,0,0,2,2,2,0,0,0,0,0,0,2,0,0,2}, //3
		{2,0,1,2,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,1,2,2,2,0,0,0,2,0,0,2,2,2,2,0,0,2,2,2,2,2,2,2,0,0,2,2,2,0,2}, //5
		{2,0,1,2,0,0,1,1,1,2,1,1,1,1,1,1,0,0,0,0,0,2,0,0,0,0,0,2,2,2,0,2},
		{2,0,1,0,0,0,2,0,0,0,1,1,2,0,0,1,2,2,2,0,0,0,0,0,2,0,0,0,0,0,0,2}, //7



		{2,0,1,0,0,0,2,0,0,0,1,1,2,0,0,2,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,2},
		{2,0,1,2,2,2,2,1,1,2,2,2,2,0,0,2,0,0,0,0,0,0,0,0,2,0,0,0,2,2,2,2},//9
		{2,0,1,0,0,0,2,1,0,0,0,0,2,0,0,2,2,2,2,0,0,0,0,0,2,0,0,0,0,0,0,2},
		{2,0,1,2,1,1,1,1,0,2,0,1,1,1,1,1,0,0,0,0,0,2,0,0,0,0,0,2,2,2,0,2}, //11
		{2,0,1,2,2,2,1,0,0,2,0,0,2,2,2,2,0,0,2,2,2,2,2,2,2,0,0,2,2,2,0,2},
		{2,0,1,2,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,2,1,1,1,0,0,2,0,0,2,0,0,2,0,0,2,2,2,2,0,0,2,0,0,2,2,0,0,2},
		{2,0,0,0,0,0,2,0,0,0,0,0,2,0,0,2,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,2},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,2,2,2,2,2,2,2},



		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };


	Map::Map() 
	{

		Init();
		
		TRACE("-------%d,%d------\n", sx, sy);

	}
	void Map::LoadBitmap() {
		pic.LoadBitmap(IDB_BITMAP3);
		green.LoadBitmap(IDB_BITMAP4);
	}

	bool Map::isEmpty(int x, int y)
	{
		int temp = x, target_wid = 55;
		temp = x;
		x = y;
		y = temp;

		if( (map[x / 60][y / 60] != 2 && map[x / 60][(y + target_wid) / 60] != 2) && map[(x + target_wid) / 60][y / 60] != 2&& map[(x + target_wid) / 60][(y + target_wid )/ 60] != 2) { return 1; }
		else { return 0; }

	/*	int map_[10][6] = { {0,0,0,0,0,0}, {0,0,0,0,0,0},{0,0,0,0,0,0},
				{0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0},
	{0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,1,1,0,0,0},
		{0,0,0,0,0,0} };*/
		//int gx = x / 60; // 轉換為格座標(整數除法)
		//int gy = y / 60; // 轉換為格座標(整數除法)
		//return map[gx][gy] != 2; // 假設 2 代表障礙
	} 

	int Map::isPill(int x, int y) 
	{
		int temp = x, target_wid = 55;
		temp = x;
		x = y;
		y = temp;

		if (map[x / 60][y / 60] == 1) { return 1; }
		return 0;
	}
	void Map::Init() 
	{
		sx = sy = 0 ;

	}
	void Map::OnShow() 
	{
		pic.SetTopLeft(-sx, -sy);
		pic.ShowBitmap();

		for (int i = 0; i < 32; i++)
		{
			for (int j = 0; j < 32; j++)
			{
				if (map[i][j] == 2)
				{
					green.SetTopLeft(ScreenX(60 * j), ScreenY(60 * i));
					//green.ShowBitmap();
				}
			}
		}

	}
	int Map::ScreenX(int x) 
	{
		return x - sx;
	}
	int Map::ScreenY(int y)  // y為地圖y座標
	{
		return y - sy; //回傳螢幕的點座標

	}
	void Map::SetSX(int x) 
	{
		sx += x;
	}
	void Map::SetSY(int y) 
	{
		sy += y;
	}
}
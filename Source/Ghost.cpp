#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
//#include "audio.h"
#include "gamelib.h"
#include "CHero.h"
#include "Ghost.h"
#include "time.h"
#include "stdlib.h"
namespace game_framework {
	Ghost::Ghost() { Initialize(); }
	void Ghost::Initialize() 
	{
		const int X_POS = 900;
		const int Y_POS = 400;
		x = X_POS;
		y = Y_POS;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		oldState = 0;
	}

	int Ghost::GetX1()
	{
		return x;
	}

	int Ghost::GetY1()
	{
		return y;
	}

	int Ghost::GetX2()
	{
		return x + bmp.Width();
	}

	int Ghost::GetY2()
	{
		return y + bmp.Height();
	}

	bool Ghost::HitHero(CHero *hero)
	{
		return HitR(hero->GetX1(), hero->GetY1(),
			hero->GetX2(), hero->GetY2());
	}

	bool Ghost::HitR(int tx1, int ty1, int tx2, int ty2)
	{
		int x1 = x;				// 左上角x座標
		int y1 = y;				// 左上角y座標
		int x2 = x1 + bmp.Width();	// 右下角x座標
		int y2 = y1 + bmp.Height();	// 右下角y座標
									//
								
		return (tx2 >= x1 && tx1 <= x2 && ty2 >= y1 && ty1 <= y2);
	}

	void Ghost::LoadBitmap()
	{
		bmp.LoadBitmap(IDB_PINKY, RGB(255, 255, 255));
	}
	void Ghost::OnMove(Map *m) {
		srand(unsigned int(time(NULL)));
		int dir = rand() % 4+1;	
		TRACE("dir:%d\n", dir);
		switch (dir)
		{
		case 1: //left
			if (m->isEmpty(x - 20, y) && (oldState == 1||dir==1)&&oldState!=2) 
			{
				x -= 20;
				oldState = 1;
			}
			break;
		case 2:
			if (m->isEmpty(x + 20, y) && (oldState == 2||dir==2)&& oldState!=1) { x += 20; oldState = 2;
			}
			break;
		case 3:
			if (m->isEmpty(x, y + 20) && (oldState == 3||dir==3)&&oldState!=4) { y += 20; oldState = 3; }
			break;
		case 4:
			if (m->isEmpty(x, y - 20) && (oldState == 4||dir==4)&&oldState!=3) { y -= 20; oldState = 4; }
			break;
		default:
			break;
		}
	
	}
	void Ghost:: OnShow(Map *m) {
			bmp.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			bmp.ShowBitmap();
	}




	//
	void Pinky::OnMove(Map *m, CHero *hero) //to the same col
	{
		if (x - hero->GetX1()>0) //  
		{
			while (m->isEmpty(x - 10, y)) 
			{
				x -= 10;
			}
			while (m->isEmpty(x, y + 10)) { y += 10; }
			//OnMove(m, hero);
		}
		

		
	
	} //pinky不同移動方式
}
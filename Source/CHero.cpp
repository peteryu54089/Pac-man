#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
//#include "gamelib.h"
//#include "mygame.h"

#include "CHero.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CEraser: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	CHero::CHero()
	{
		Initialize();
	}


	void CHero::Initialize()
	{
		const int X_POS = 60;
		const int Y_POS = 60;
		x = X_POS;
		y = Y_POS;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		oldState = 0;
	}

	void CHero::LoadBitmap()
	{
		bmp1.LoadBitmap(IDB_BITMAP5, RGB(255, 255, 255));

	}

	void CHero::OnMove(Map *m)
	{
		const int STEP_SIZE = 10;
		//animation.OnMove();
		//oldState is the last moving direction
		if ((isMovingLeft || oldState == 1) &&x>0&&m->isEmpty(x-10,y) )  // isempty
		{
			x -= STEP_SIZE;
			if (m->ScreenX(x) < 80) {
				//TRACE("%d %d\n", x, m->ScreenX(x));
				m->SetSX(-STEP_SIZE);
			}
			oldState = 1;
			
		}
		if ((isMovingRight || oldState == 2) && m->isEmpty(x + STEP_SIZE, y)) {
			x += STEP_SIZE;

			//TRACE("::%d %d\n", x, m->ScreenX(x));
			if (m->ScreenX(x) > 500) {
				m->SetSX(STEP_SIZE);
			}
			oldState = 2;
		}
		if ((isMovingUp&&y>0 || oldState==3) && m->isEmpty(x, y-10)) {
			y -= STEP_SIZE;
			if (m->ScreenY(y) < 70) {
				m->SetSY(-STEP_SIZE);
			}
			oldState = 3;
		}
		if ((isMovingDown || oldState == 4) &&m->isEmpty(x, y + 10)) {
			y += STEP_SIZE;
			if (m->ScreenY(y) > 350) {
				m->SetSY(STEP_SIZE);
			}
			oldState = 4;
		}
	}

}
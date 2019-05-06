	/////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "CCharacter.h"
namespace game_framework {
	CCharacter::CCharacter()
	{
		Initialize();
	}

	int CCharacter::GetX1()
	{
		return x;
	}

	int CCharacter::GetY1()
	{
		return y;
	}

	int CCharacter::GetX2()
	{
		return x + bmp.Width();
	}

	int CCharacter::GetY2()
	{
		return y + bmp.Height();
	}

	void CCharacter::Initialize()
	{
//		const int X_POS = 60;
//		const int Y_POS = 60;
//		x = X_POS;
//		y = Y_POS;
//		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
	}

	void CCharacter::LoadBitmap()
	{
		//bmp.AddBitmap(IDB_BITMAP5, RGB(255, 255, 255));

	}

	void CCharacter::OnMove(Map *m)
	{
		const int STEP_SIZE = 10;
//		bmp.OnMove();
//		if (isMovingLeft&&x>0&&m->isEmpty(x-10,y))  // isempty
//		{
//		}
//		if (isMovingRight&&m->isEmpty(x+STEP_SIZE, y)) {
//			
//		}
//		if (isMovingUp&&y>0 && m->isEmpty(x, y-10)) {
//			
//		}
//		if (isMovingDown&&m->isEmpty(x, y+10)) {
//		}
	}

	void CCharacter::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void CCharacter::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void CCharacter::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void CCharacter::SetMovingUp(bool flag)
	{
		isMovingUp = flag;
	}

	void CCharacter::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void CCharacter::OnShow(Map *m)
	{
		bmp.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		bmp.OnShow();
	}
}
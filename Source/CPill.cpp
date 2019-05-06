#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CHero.h"
#include "CPill.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CBall: Ball class
	/////////////////////////////////////////////////////////////////////////////
	//pill
	CPill::CPill()
	{
		is_alive = true;
		x = y = dx = dy = index = delay_counter = 0;
	}

	bool CPill::HitEraser(CHero *eraser)
	{
		// �˴����l�Һc�����x�άO�_�I��y
		return HitRectangle(eraser->GetX1(), eraser->GetY1(),
			eraser->GetX2(), eraser->GetY2());
	}

	bool CPill::HitRectangle(int tx1, int ty1, int tx2, int ty2)
	{
		int x1 = x + dx;				// �y�����W��x�y��
		int y1 = y + dy;				// �y�����W��y�y��
		int x2 = x1 + bmp.Width();	// �y���k�U��x�y��
		int y2 = y1 + bmp.Height();	// �y���k�U��y�y��
									//
									// �˴��y���x�λP�ѼƯx�άO�_���涰
									//
		return (tx2 >= x1 && tx1 <= x2 && ty2 >= y1 && ty1 <= y2);
	}

	bool CPill::IsAlive()
	{
		return is_alive;
	}

	void CPill::LoadBitmap()
	{
		bmp.LoadBitmap(IDB_BITMAP6, RGB(255, 255, 255));			// ���J�y���ϧ�
		bmp_center.LoadBitmap(IDB_CENTER, RGB(0, 0, 0));	// ���J�y��ߪ��ϧ�
	}

	void CPill::OnMove()
	{
		if (!is_alive)
			return;
		delay_counter--;
		if (delay_counter < 0) {
			delay_counter = delay;
		//	//
		//	// �p��y�V����ߪ��첾�qdx, dy
		//	//
			const int STEPS = 18;
		//	static const int DIFFX[] = { 35, 32, 26, 17, 6, -6, -17, -26, -32, -34, -32, -26, -17, -6, 6, 17, 26, 32, };
		//	static const int DIFFY[] = { 0, 11, 22, 30, 34, 34, 30, 22, 11, 0, -11, -22, -30, -34, -34, -30, -22, -11, };
			index++;
			if (index >= STEPS)
				index = 0;
		//	dx = DIFFX[index];
		//	dy = DIFFY[index];
		}
	}

	void CPill::SetDelay(int d)
	{
		delay = d;
	}

	void CPill::SetIsAlive(bool alive)
	{
		is_alive = alive;
	}

	void CPill::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void CPill::OnShow(Map *m)
	{
		if (is_alive) {
			bmp.SetTopLeft(m->ScreenX(x + dx), m->ScreenY(y + dy));
			bmp.ShowBitmap();

			bmp_center.SetTopLeft(x, y);
			//bmp_center.ShowBitmap();
		}
	}
}
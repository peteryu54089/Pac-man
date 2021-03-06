#ifndef CCHARACTER_H__
#define  CCHARACTER_H__
#include "gamelib.h"

#include "Map.h"
namespace game_framework{
class CCharacter
{
public:
	CCharacter();
	int  GetX1();					// 擦子左上角 x 座標
	int  GetY1();					// 擦子左上角 y 座標
	int  GetX2();					// 擦子右下角 x 座標
	int  GetY2();					// 擦子右下角 y 座標
	virtual void Initialize();				// 設定擦子為初始值
	virtual void LoadBitmap();				// 載入圖形
	virtual void OnMove(Map *m);					// 移動擦子
	void OnShow(Map *m);					// 將擦子圖形貼到畫面
	void SetMovingDown(bool flag);	// 設定是否正在往下移動
	void SetMovingLeft(bool flag);	// 設定是否正在往左移動
	void SetMovingRight(bool flag); // 設定是否正在往右移動
	void SetMovingUp(bool flag);	// 設定是否正在往上移動
	void SetXY(int nx, int ny);		// 設定擦子左上角座標
protected:
	int x, y;					// 擦子左上角座標
	bool isMovingDown;			// 是否正在往下移動
	bool isMovingLeft;			// 是否正在往左移動
	bool isMovingRight;			// 是否正在往右移動
	bool isMovingUp;			// 是否正在往上移動
	CMovingBitmap bmp1;

};
}

#endif 
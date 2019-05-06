
#include "Map.h"
#include "CCharacter.h"
namespace game_framework {

	class Ghost{
	public:
		Ghost();
		void LoadBitmap();				// 載入圖形
		void SetXY(int nx, int ny);
		int  GetX1();					// 左上角 x 座標
		int  GetY1();					// 左上角 y 座標
		int  GetX2();					// 右下角 x 座標
		int  GetY2();					// 右下角 y 座標
		bool HitR(int, int, int, int);
		bool HitHero(CHero *hero);

		void Initialize();		
		void OnShow(Map *m);
		void OnMove(Map *m);

	protected:
		CMovingBitmap bmp;
		int x, y;					// 左上角座標
		bool isMovingDown;			// 是否正在往下移動
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isMovingUp;			// 是否正在往上移動
		int oldState;
		
	};

	//class Pinky : public Ghost {
	//public:
	//	//void LoadBitmap();
	//	void OnMove(Map *m, CHero *hero); //pinky不同移動方式
	//private:
	//	CMovingBitmap bmp;
	//	
	//};


}
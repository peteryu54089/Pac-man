#include "CCharacter.h"
#include "Map.h"


namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供可以用鍵盤或滑鼠控制的擦子
	// 看懂就可以改寫成自己的程式了
	/////////////////////////////////////////////////////////////////////////////

	class CHero : public CCharacter
	{
	public:
		CHero();
		void Initialize();				// 設定擦子為初始值
		void LoadBitmap();				// 載入圖形
		void OnMove(Map *m);					// 移動擦子
		//void OnShow(Map *m);					// 將擦子圖形貼到畫面
	protected:
		int oldState;
	};
}
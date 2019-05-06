
#include "Map.h"
#include "CCharacter.h"
namespace game_framework {

	class Ghost{
	public:
		Ghost();
		void LoadBitmap();				// ���J�ϧ�
		void SetXY(int nx, int ny);
		int  GetX1();					// ���W�� x �y��
		int  GetY1();					// ���W�� y �y��
		int  GetX2();					// �k�U�� x �y��
		int  GetY2();					// �k�U�� y �y��
		bool HitR(int, int, int, int);
		bool HitHero(CHero *hero);

		void Initialize();		
		void OnShow(Map *m);
		void OnMove(Map *m);

	protected:
		CMovingBitmap bmp;
		int x, y;					// ���W���y��
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		int oldState;
		
	};

	//class Pinky : public Ghost {
	//public:
	//	//void LoadBitmap();
	//	void OnMove(Map *m, CHero *hero); //pinky���P���ʤ覡
	//private:
	//	CMovingBitmap bmp;
	//	
	//};


}
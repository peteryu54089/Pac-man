#ifndef CCHARACTER_H__
#define  CCHARACTER_H__
#include "gamelib.h"

#include "Map.h"
namespace game_framework{
class CCharacter
{
public:
	CCharacter();
	int  GetX1();					// ���l���W�� x �y��
	int  GetY1();					// ���l���W�� y �y��
	int  GetX2();					// ���l�k�U�� x �y��
	int  GetY2();					// ���l�k�U�� y �y��
	virtual void Initialize();				// �]�w���l����l��
	virtual void LoadBitmap();				// ���J�ϧ�
	virtual void OnMove(Map *m);					// �������l
	void OnShow(Map *m);					// �N���l�ϧζK��e��
	void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
	void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
	void SetMovingRight(bool flag); // �]�w�O�_���b���k����
	void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
	void SetXY(int nx, int ny);		// �]�w���l���W���y��
protected:
	int x, y;					// ���l���W���y��
	bool isMovingDown;			// �O�_���b���U����
	bool isMovingLeft;			// �O�_���b��������
	bool isMovingRight;			// �O�_���b���k����
	bool isMovingUp;			// �O�_���b���W����
	CMovingBitmap bmp1;

};
}

#endif 
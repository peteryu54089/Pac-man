#include "CCharacter.h"
#include "Map.h"


namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������l
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////

	class CHero : public CCharacter
	{
	public:
		CHero();
		void Initialize();				// �]�w���l����l��
		void LoadBitmap();				// ���J�ϧ�
		void OnMove(Map *m);					// �������l
		//void OnShow(Map *m);					// �N���l�ϧζK��e��
	protected:
		int oldState;
	};
}
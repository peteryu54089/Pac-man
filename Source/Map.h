#pragma once
namespace game_framework{

	class Map {
	public:
		Map();
		void Init();
		void OnShow();
		void LoadBitmap();
		bool isEmpty(int x, int y);
		int isPill(int x, int y);
		int ScreenX(int x);
		int ScreenY(int y);
		void SetSX(int x);
		void SetSY(int y);

	private:
		//int map[10][6];//1600*720
		int sx, sy;
		CMovingBitmap pic, green;
	};

}
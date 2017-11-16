#include<math.h>;


class Unit
{
public:
	float  x;
	float y;
};

Unit player;

const int MONSTER_COUNT = 10;
Unit monster[MONSTER_COUNT];


//x2[0],y[0]第1隻怪物座標
//x2[1],y[1]第2隻怪物座標
//x2[2],y[2]第3隻怪物座標

//gameInit設定遊戲初始資料
void gameInit()
{
	
	player.x = 100;
	player.y = 100;

	
	for (int i = 0; i < MONSTER_COUNT; i++)
	{
		monster[i].x = i * 100;
		monster[i].y = i * 200;
	}


}



//gameWork計算遊戲的資料
void gameWork()
{

	//控制player的移動
	const int PLAYER_SPEED=20;
	int keyState = GetAsyncKeyState(VK_RIGHT);
	if (keyState < 0)
		player.x += PLAYER_SPEED;
	keyState = GetAsyncKeyState(VK_LEFT);
	if (keyState < 0)
		player.x -= PLAYER_SPEED;
	keyState = GetAsyncKeyState(VK_UP);
	if (keyState < 0)
		player.y -= PLAYER_SPEED;
	keyState = GetAsyncKeyState(VK_DOWN);
	if (keyState < 0)
		player.y += PLAYER_SPEED;



	for (int i = 0; i < MONSTER_COUNT; i++)
	{
		//走一步的距離為m,L兩點距離
		//向量  (x-x2)*m/L	,(y-y2)m/L
		float L = sqrt(float(player.x - monster[i].x)*(player.x - monster[i].x) 
									+ (player.y - monster[i].y)*(player.y - monster[i].y));
		float m = 5;

		if (m>L)//步伐>距離
		{
			//站到對方身上
			monster[i].x = player.x;
			monster[i].y = player.y;
		}
		else
		{
			monster[i].x = monster[i].x + (player.x - monster[i].x)*m / L;
			monster[i].y = monster[i].y + (player.y - monster[i].y)*m / L;
		}
		
	}


}




//gameDraw畫出遊戲的畫面
void gameDraw(HDC hdc)
{
	Ellipse(hdc, player.x - 50, player.y - 50, player.x + 50, player.y + 50);
	for (int i = 0; i < MONSTER_COUNT; i++)
	{
		Ellipse(hdc, monster[i].x - 50, monster[i].y - 50, monster[i].x + 50, monster[i].y + 50);
	}
	
}
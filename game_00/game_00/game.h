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


//x2[0],y[0]��1���Ǫ��y��
//x2[1],y[1]��2���Ǫ��y��
//x2[2],y[2]��3���Ǫ��y��

//gameInit�]�w�C����l���
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



//gameWork�p��C�������
void gameWork()
{

	//����player������
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
		//���@�B���Z����m,L���I�Z��
		//�V�q  (x-x2)*m/L	,(y-y2)m/L
		float L = sqrt(float(player.x - monster[i].x)*(player.x - monster[i].x) 
									+ (player.y - monster[i].y)*(player.y - monster[i].y));
		float m = 5;

		if (m>L)//�B��>�Z��
		{
			//�����設�W
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




//gameDraw�e�X�C�����e��
void gameDraw(HDC hdc)
{
	Ellipse(hdc, player.x - 50, player.y - 50, player.x + 50, player.y + 50);
	for (int i = 0; i < MONSTER_COUNT; i++)
	{
		Ellipse(hdc, monster[i].x - 50, monster[i].y - 50, monster[i].x + 50, monster[i].y + 50);
	}
	
}
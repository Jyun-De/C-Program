#include<math.h>;


int x;
int y;

int x2;
int y2;



//gameInit�]�w�C����l���
void gameInit()
{
	x = 200;
	y = 200;

	x2 = 400;
	y2 = 400;
}



//gameWork�p��C�������
void gameWork()
{

	//����player������
	const int PLAYER_SPEED=20;
	int keyState = GetAsyncKeyState(VK_RIGHT);
	if (keyState < 0)
		x += PLAYER_SPEED;
	keyState = GetAsyncKeyState(VK_LEFT);
	if (keyState < 0)
		x -= PLAYER_SPEED;
	keyState = GetAsyncKeyState(VK_UP);
	if (keyState < 0)
		y -= PLAYER_SPEED;
	keyState = GetAsyncKeyState(VK_DOWN);
	if (keyState < 0)
		y += PLAYER_SPEED;

	//���@�B���Z����m,L���I�Z��
	//�V�q  (x-x2)*m/L	,(y-y2)m/L
	int L =sqrt(float(x - x2)*(x - x2) + (y - y2)*(y - y2));
	int m = 10;

	x2 = x2+(x - x2)*m / L;
	y2 = y2+(y - y2)*m / L;



	//if (x2>x)//�Ǫ��b�D������
	//	x2--;
	//else
	//	x2++;	
	//if (y2>y)
	//	y2--;
	//else
	//	y2++;
}




//gameDraw�e�X�C�����e��
void gameDraw(HDC hdc)
{
	Ellipse(hdc, x - 50, y - 50, x + 50, y + 50);
	Ellipse(hdc, x2 - 50, y2 - 50, x2 + 50, y2 + 50);
}
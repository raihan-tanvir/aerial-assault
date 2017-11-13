#include "iGraphics.h"
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string>
using namespace std;
#define numberofenemy 5
int l;
#define screenHeight 800
#define screenWidth 800
#define gamePlayScreenPoint 100
#define backgroundDivision 8
boolean isGameStart = false;
boolean isGameOver = false;
boolean isRestart = false;
bool namemenu = false;
bool bul = false;
bool l1 = true, l2 = true, l3 = true, l4 = true, l5 = true, l6 = true, l7 = true, l8 = true;
int jetX = screenWidth / 2 - 40;
int jetY = 100;
int bulletX = jetX + 28;
int bulletY = jetY + 120;
bool isTriggered = false;
bool enemyDestroy = false;
bool scoreCountingOn = true;
int lives = 5;
bool lifeDecrementOn = false;
int score = 0;
int firingIndex = 0;
int level = 1;
bool menu = false;
char str[100], str1[100];
int stlen;
bool highscore = false;

struct bullets
{
	bool shot = false;
	int bx = jetX + 28;
	int  by = jetY + 120;
};
struct bullets bullet[10];
int laserindex = 0;

struct players
{
	char name[20];
	int playerScore;
}plyScore[12], temp;
FILE *fp;

char backgroundImage[backgroundDivision][15] = { "bg\\1.bmp", "bg\\2.bmp", "bg\\3.bmp", "bg\\4.bmp", "bg\\5.bmp", "bg\\6.bmp", "bg\\7.bmp","bg\\8.bmp"  };
struct backgroundStruct
{
	int bgX;
	int bgY;
};
backgroundStruct background[backgroundDivision];
void backgroundAxisSet()
{
	int sliceDistance = 100;
	for (int i = 0; i<backgroundDivision; i++)
	{
		background[i].bgX = 0;
		background[i].bgY = sliceDistance;
		sliceDistance += 100;
	}
}
void backgroundImageShow()
{
	for (int i = 0; i<backgroundDivision; i++)
	{
		iShowBMP(background[i].bgX, background[i].bgY,backgroundImage[i]);
	}
}
void backgroundMotion()
{
	for (int i = 0; i<backgroundDivision; i++)
	{
		background[i].bgY -= 5;

		if (background[i].bgY <= 0)
		{
			background[i].bgY = screenHeight;
		}
	}
}



char enemyImage[10][20] = { "enemy\\bug\\1.bmp", "enemy\\bug\\2.bmp", "enemy\\bug\\3.bmp", "enemy\\bug\\4.bmp", "enemy\\bug\\5.bmp"};
struct enemys{
	int enemy_x;
	int enemy_y;
	int enemy_number;
	bool enemy_show;
};
enemys a[numberofenemy];

void enemyAxisSet(){
	for (int i = 0; i < numberofenemy; i++)
	{
		a[i].enemy_x = rand() % screenWidth-40;
		a[i].enemy_y = screenHeight + rand() % 1000;
		a[i].enemy_number = rand() % numberofenemy;
		a[i].enemy_show = true;
	}
}
void enemyImageShow(){
	for (int i = 0; i < numberofenemy; i++)
	{
		if (a[i].enemy_show){
			iShowBMP2(a[i].enemy_x, a[i].enemy_y, enemyImage[a[i].enemy_number], 0);
		}
	}
}

void enemyMovementAndCollsion(){

	for (int i = 0; i < numberofenemy; i++)
	{
		a[i].enemy_y -= 8;
		if (a[i].enemy_y <= 0)
		{
			a[i].enemy_y = screenHeight + rand() % 1000;
		}
		a[i].enemy_number++;
		if (a[i].enemy_number >= numberofenemy)
		{
			a[i].enemy_number = 0;
		}

	}
	for (int j = 0,l=0; j < 10; j++){
		if (bullet[j].bx >= a[0].enemy_x && bullet[j].bx + 10 <= a[0].enemy_x + 45 && bullet[j].by >= a[0].enemy_y && bullet[j].by <= a[0].enemy_y + 107){
			
			if (scoreCountingOn){
				score = score + 1;
				l1 = false;
				scoreCountingOn = false;
			}
			bullet[l].shot = false;
			break;
			
		}
		else l++;
	}
	for (int j = 0,l=0; j < 10; j++){
		if (bullet[j].bx >= a[1].enemy_x && bullet[j].bx + 10 <= a[1].enemy_x + 45 && bullet[j].by >= a[1].enemy_y && bullet[j].by <= a[1].enemy_y + 107){
			a[1].enemy_show = false;
			

			if (scoreCountingOn){
				score = score + 1;
				l2 = false;
				scoreCountingOn = false;
			}
			bullet[l].shot = false;
			break;
		}
		else l++;
	}
	for (int j = 0,l=0; j < 10; j++){
		if (bullet[j].bx >= a[2].enemy_x && bullet[j].bx + 10 <= a[2].enemy_x + 45 && bullet[j].by >= a[2].enemy_y && bullet[j].by <= a[2].enemy_y + 107){
			a[2].enemy_show = false;
			

			if (scoreCountingOn){
				score = score + 1;
				l3 = false;
				scoreCountingOn = false;
			}
			bullet[l].shot = false;
			break;
		}
		else l++;
	}
		for (int j = 0,l=0; j < 10; j++){
			if (bullet[j].bx >= a[3].enemy_x && bullet[j].bx + 10 <= a[3].enemy_x + 45 && bullet[j].by >= a[3].enemy_y && bullet[j].by <= a[3].enemy_y + 107){
				a[3].enemy_show = false;
			

				if (scoreCountingOn){
					score = score + 1;
					l4 = false;
					scoreCountingOn = false;
				}
				bullet[l].shot = false;
				break;
			}
			else l++;
		}
			
		for (int j = 0,l=0; j < 10; j++){
			if (bullet[j].bx >= a[4].enemy_x && bullet[j].bx + 10 <= a[4].enemy_x + 45 && bullet[j].by >= a[4].enemy_y && bullet[j].by <= a[4].enemy_y + 107){
				
				if (scoreCountingOn){
					score = score + 1;
					l5 = false;
					scoreCountingOn = false;
				}
				bullet[l].shot = false;
				break;
			}
			else l++;
		}
	
	if (a[0].enemy_x >= jetX-40 && a[0].enemy_x  <= jetX + 77 && a[0].enemy_y >= jetY && a[0].enemy_y <= jetY + 109){
		if (l1){
			lives=lives-1;
			a[0].enemy_show = false;
			l1 = false;
		}
	}

	if (a[1].enemy_x >= jetX-40 && a[1].enemy_x  <= jetX + 77 && a[1].enemy_y >= jetY && a[1].enemy_y <= jetY + 109){
		if (l2){
			lives=lives-1;
			a[1].enemy_show = false;
			l2 = false;
		}
	}
	if (a[2].enemy_x >= jetX-40 && a[2].enemy_x <= jetX + 77 && a[2].enemy_y >= jetY && a[2].enemy_y <= jetY + 109){
		if (l3){
			lives=lives-1;
			a[2].enemy_show = false;
			l3 = false;
		}
	}
	if (a[3].enemy_x >= jetX-40 && a[3].enemy_x  <= jetX + 77 && a[3].enemy_y >= jetY && a[3].enemy_y <= jetY + 109){
		if (l4){
			lives=lives-1;
			a[3].enemy_show = false;
			l4 = false;
		}
	}
	if (a[4].enemy_x >= jetX-40 && a[4].enemy_x <= jetX + 77 && a[4].enemy_y >= jetY && a[4].enemy_y <= jetY + 109){
		if (l5){
			lives=lives-1;
			a[4].enemy_show = false;
			l5 = false;
		}
	}


}
void enemyRegeneration(){
	for (int i = 0; i < numberofenemy; i++){
		if (!a[i].enemy_show){
			a[i].enemy_show = true;
			a[i].enemy_x = rand() %screenWidth-40;
			a[i].enemy_y = 800 + rand() % 500;
			scoreCountingOn = true;
		}
	}
}

void check(){

	if (!l1){
		l1 = true;
	}
	if (!l2){
		l2 = true;
	}
	if (!l3){
		l3 = true;
	}
	if (!l4){
		l4 = true;
	}
	if (!l5){
		l5 = true;
	}	

}
void iDraw()
{

	iShowBMP(0, 0, "cover.bmp");
	iSetColor(255, 0, 0);
	iText(300, 156, "Press s to start", GLUT_BITMAP_TIMES_ROMAN_24);
	if (menu){
			iClear();
			iShowBMP(0, 0, "bk.bmp");
			iFilledRectangle(290, 590, 240, 80);
			iShowBMP2(300, 600, "play.bmp", 0);
			iShowBMP(290, 470, "hg.bmp");
			iSetColor(128, 128, 64);
			iFilledRectangle(290, 350, 240, 80);
			iShowBMP2(310, 360, "i.bmp", 0);
			iShowBMP(290, 240, "exit.bmp");
		
		
	}
	if (namemenu){
		iClear();
		iSetColor(255, 100, 90);
		iText(280, 200, "Click to enter your name");
		iSetColor(128, 128, 64);
		iText(300, 350," Name:");
		iRectangle(355, 343, 100, 20);
		iText(360, 346, str);
	}
	if (highscore){
		iClear();
		iShowBMP(200, 600, "highscore.bmp");
	}
	if (isGameStart){
		menu = false;
	
		if (lives >= 0){
			iClear();
			iShowBMP(0, 0, "bg\\0.bmp");
			backgroundImageShow();

			iShowBMP2(jetX, jetY, "player\\alpha1.bmp", 255);

			enemyImageShow();
		

			for (int i = 0; i < 10; i++){
				if (bullet[i].shot){
					iShowBMP2(bullet[i].bx, bullet[i].by+=7, "1.bmp", 0);
				}
			}


			char text1[100];
			char text2[100];
			sprintf(text1, "Score : %d", score);
			sprintf(text2, "Life : %d", lives);
			iText(700, 780, text1);
			iText(700, 760, text2);
		}
		if (lives <= 0){
			iClear();
			iShowBMP2(0, 0, "over.bmp", 0);
			iShowBMP(670, 100, "menu.bmp");
		}
	}

}
/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (menu){
			if (mx >= 290 && mx <= 530 && my >= 590 && my <= 680){
				
				namemenu = true;
			}
		}
		if (menu){
			if (mx >= 290 && mx <= 530 && my >= 470 && my <= 560){

				highscore = true;
			}
		}
		if (menu){
		if (mx >= 290 && mx <= 530 && my >= 240 && my <= 320){
			exit(0);
		}
		}
			if (mx >= 670 && mx <= 790 && my >= 100 && my <= 140){
				menu = true;
				isGameStart = false;
				lives = 5;
				score = 0;
			}
			if (namemenu){
				if (mx >= 355 && mx <= 455 && my >= 343 && my <= 363){
					iSetColor(20, 300, 100);
					iText(55, 260, str);
					
				}
			}
		
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here 
	}
}
/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{

	if (namemenu)                /*nam lekhar box e clicl krle mode=1 hobe*/
	{
		if (key == '\r')          /*nam lekhe enter tipar por egula hobe*/
		{
			isGameStart = true;
			namemenu = false;
			strcpy(str1, str);
			printf("%s\n", str1);
			for (int i = 0; i < stlen; i++)
				str[i] = 0;
			stlen = 0;           /*stlen 0 krse jate porer bar nam input krle abar index 0 thke input nei*/

		}
		else
		{
			str[stlen] = key;   /*index 0 theke nam er letter nea strt hbe*/
			stlen++;            /*prottek ltr input er jnno str er index baraite hbe*/
		}
	}
	if (key == 's')
	{
		menu = true;
	}

	if (key == 'x')
	{
		
		
		
	}
	if (key == ' ')
	{
		if (laserindex == 10)
			laserindex = 0;
		bullet[laserindex].bx = jetX + 28;
		bullet[laserindex].by = jetY + 120;
		bullet[laserindex++].shot = true;
	}
	if (key == 'p')
	{
		iPauseTimer(0);
	}
	if (key == 'r')
	{
		iResumeTimer(0);
	}
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_RIGHT)
	{
		if (jetX < screenWidth - 60)
			jetX += 8;
	}
	if (key == GLUT_KEY_LEFT)
	{
		if (jetX > 8)
			jetX -= 8;
	}
	if (key == GLUT_KEY_UP)
	{
		if (jetY < screenHeight - 64)
			jetY += 8;
	}
	if (key == GLUT_KEY_DOWN)
	{
		if (jetY > 8)
			jetY -= 8;
	}

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}

	
}

int main()
{	
	backgroundAxisSet();
	iSetTimer(25, backgroundMotion);

	enemyAxisSet();
	iSetTimer(50, enemyMovementAndCollsion);	
	iSetTimer(1000, enemyRegeneration);
	iSetTimer(8000, check);
	iInitialize(screenWidth, screenHeight, "Aerial Assault");
	return 0;
}
#include <iostream>
#include <conio.h>
#include <windows.h>


using namespace std;

bool gameover;
const int width =20 ;
const int height = 20;
// creat a dimension for the gameboard;

int x, y, fruitx, fruity, score;
int tailx[100], taily[100];
int ntail;
// number of tail
enum edirection {STOP= 0 , left, right, up, down};
edirection dir;


void setup()
{
	gameover = false;
	dir = STOP;
	x = width/2;
	y = height/2;
	fruitx = rand() % width;
	fruity = rand() % height;
	score = 0;
	// set the initials of the game
}

void draw()
{
	system ("cls");
	// clear the screen
	for (int i=0 ; i<width+2; i++)
	{
		cout <<"#";
	}
	cout <<endl;

	for (int i=0; i<height; i++)
	{
		for (int j=0; j<width; j++)
		{
			if (j==0||j==width-1)
			{
				cout <<"#";
			}
			
			if (i ==y&& j==x)
			{
				cout<<"O";
			}

			if (i==fruity&& j==fruitx)
			{
				cout<<"*";
			}
			else 
			{
				bool print = false;
				for (int k=0; k<ntail; k++)
				{
					
					if (tailx[k]==j && taily[k]==i)
					{
						cout <<"o";
						print = true;
					}

				}
				if (!print)
					{
						cout <<" ";
					}
				
			}
		}
		cout <<endl;
	}
//fixed the missing wall
	for (int i=0 ; i<width+2; i++)
	{
		cout <<"#";
	}
	cout <<endl;
	for (int i=0; i<width+2; i++)
	{
		cout <<"-";
	}
	cout <<endl;
	cour <<"score: "<<score <<endl;

}
void Input()
{
	if (_kbhit())
	{
		// return 1 if keyboard is hitted
		switch (_getch())
		{
			case 'a':
				dir = left;
				break;
			case 'd':
				dir = right;
				break;
			case 'w':
				dir = up;
				break;
			case 's':
				dir = down;
				break;
			case 'x':
				gameover= true;
				break;
		}
	}
}
void logic()
{
	int prevx = tailx[0];
	int prevy = taily[0];
	int prev2x, prev2y;
	tailx[0]=x;
	taily[0]=y;
	for (int i=1; i< ntail; i++)
	{
		prev2x = tailx[i];
		prev2y = taily[i];
		tailx[i] = prevx;
		taily[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;
	}
	switch (dir)
	{

		case left:
			x--;
			break;
		case right:
			x++;
			break;
		case up:
			y--;
			break;
		case down:
			y++;
			break;
		default:
			break;
	}
	if (x>width || x<0 || y> height || y< 0)
	{
		gameover =true;
	}
	// if (x>=width)
	// {
	// 	x=0;
	// }
	// else if (x<0)
	// {
	// 	x=width-1;
	// }
	// if (y>=height)
	// {
	// 	y=0;
	// }
	// else if (y<0)
	// {
	// 	y=height-1
	// }
	for (int i=0 ; i < ntail; i++)
	{
		if (tailx[i]==x &&taily[i]==y)
		{
			gameover = true;
		}
	}
	if (x== fruitx && y == fruity)
	{
		score= score +10;
		fruitx = rand() % width;
		fruity = rand() % height;
		// reset the location of fruit
		ntail++;
	}
}

int main ()
{
	setup();
	while (gameover==false)
	{
		draw();
		logic();
		logic();

		sleep(10); 
		// slows the game a little bit lower
	}


	return 0;
}

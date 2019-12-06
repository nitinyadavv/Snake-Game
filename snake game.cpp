#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define height 20
#define width 20
int x,y,foodx,foody,score,gameover,flag;
int tailx[100],taily[100];
int counttail=0;
void display();
void setup();
void input();
void logic();
int main()
{
	int m,n;
	char c;
	label5:
	setup();
	while(!gameover)
	{
	display();
	input();
	logic();
	for(m=0;m<10000;m++)
	{for(n=0;n<10000;n++){}}	
	}
	printf("\nPRESS Y TO START AGAIN");
	scanf("%c",&c);
	if(c=='y'||c=='Y')
	goto label5;
	return 0;
}
void display()
{
	int i,j,k;
	system("cls");
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			if(i==0||j==0||i==height-1||j==width-1)
			printf("#");
			else 
			{
				if(i==x&&j==y)
				printf("0");
				else if(i==foodx&&j==foody)
				printf("*");
				else
				{
					int ch=0;
					for(k=0;k<counttail;k++)
					{
						if(i==tailx[k]&&j==taily[k])
						{
							printf("o");
							ch=1;
						}		
			  	}
			  	if(ch==0)
					printf(" ");
				}
				
			}
		}
		printf("\n");
	}
	printf("YOUR SCORE=%d",score);
}
void setup()
{
	gameover=0;
	score=0;
	x=width/2;
	y=height/2;
	label1:
	foodx=rand()%width;
	if(foodx==0)
	goto label1;
	label2:
		foody=rand()%height;
		if(foody==0)
		goto label2;
}
void input()
{
	if(kbhit())
	{
		switch(getch())
		{
			case 'a':
				flag=1;
				break;
			case 's':
				flag=2;
				break;
			case 'w':
				flag=3;
				break;
			case 'z':
				flag=4;
				break;
			case 'x':
				gameover=1;
				break;
		}
	}
}
void logic()
{
	int i;
	int prevx=tailx[0];
	int prevy=taily[0];
	int prev2x,prev2y;
	tailx[0]=x;
	taily[0]=y;
	for(i=1;i<counttail;i++)
	{
		prev2x=tailx[i];
		prev2y=taily[i];
		tailx[i]=prevx;
		taily[i]=prevy;
		prevx=prev2x;
		prevy=prev2y;
	}
	
	switch(flag)
	{
		case 1:
			y--;
			break;
		case 2:
			y++;
			break;
		case 3:
			x--;
			break;
		case 4:
			x++;
			break;
		default:
			break;
	}
if(x<0||x>width||y<0||y>height)
gameover=1;
for(i=0;i<counttail;i++)
{
	if(x==tailx[i]&&y==taily[i])
	gameover=1;
}
if(x==foodx&&y==foody)
{
		label3:
	foodx=rand()%width;
	if(foodx==0)
	goto label3;
	label4:
		foody=rand()%height;
		if(foody==0)
		goto label4;
		score+=10;
		counttail++;
}
}


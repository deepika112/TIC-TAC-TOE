// tic_tac_toe
#include<iostream.h>
#include<process.h>
#include<conio.h>
int array[3][3];
void display_array()
{
       for(int i=0;i<3;i++)
       {
		cout<<"\n";
		for(int j=0;j<3;j++)
		{
			if(array[i][j]>=65&&array[i][j]<=90)
				cout<<char(array[i][j]);
			else
				cout<<array[i][j];
			if(j!=2)
				cout<<" | ";
		}
	}
}
void initialise_array()
{
	int temp =1;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			array[i][j]= temp;
			temp++;
		}
	}
	display_array();
}
void display_winner(int i, int j)
{
	if(array[i][j]==int('X'))
	{
		cout<<"\n Player 1 wins";
		exit(1);
	}
	if(array[i][j]==int('O'))
	{
		cout<<"\n Player 2 wins";
		exit(1);
	}
}
void check_for_win()
{
	if(array[0][0]==array[0][1]&&array[0][0]==array[0][2])
		display_winner(0,0);
	if(array[0][0]==array[1][0]&&array[0][0]==array[2][0])
		display_winner(0,0);
	if(array[0][0]==array[1][1]&&array[0][0]==array[2][2])
		display_winner(0,0);
	if(array[0][1]==array[1][1]&&array[0][1]==array[2][1])
		display_winner(0,1);
	if(array[0][2]==array[1][2]&&array[0][2]==array[2][2])
		display_winner(0,2);
	if(array[1][0]==array[1][1]&&array[1][0]==array[1][2])
		display_winner(1,0);
	if(array[2][0]==array[2][1]&&array[2][0]==array[2][2])
		display_winner(2,0);
	if(array[2][0]==array[1][1]&&array[2][0]==array[0][2])
		display_winner(2,0);
}
int enterXO_in_array(int pos,char x)
{
	int flag=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(array[i][j]==pos)
			{
				flag=1;
				array[i][j]=x;
				break;
			}
	if(flag==0)
	{
		return 0;
	}
	display_array();
	check_for_win();
	return 1;
}
int no_win()
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(array[i][j]!=88&&array[i][j]!=79)
				return 1;
	return 0;
}
void main()
{
	int temp1,pos,player=1,temp=1;
	clrscr();
	cout<<"\n Let's play tic_tac_toe\n";
	initialise_array();
	cout<<"\nPlayer1 : [X]\nPlayer2 : [O]";
	temp1=no_win();
	while(temp==1&&temp1==1)
	{
		cout<<"\n Player "<<player<<" turns";
		cout<<"\n Enter position number";
		cin>>pos;
		if(player==1)
		{
			temp=enterXO_in_array(pos,'X');
			if(temp==0)
			{
				cout<<"\n Enter Correct position";
				cin>>pos;
				temp=enterXO_in_array(pos,'X');
			}
			player++;
		}
		else
		{
			temp=enterXO_in_array(pos,'O');
			if(temp==0)
			{
				cout<<"\n Enter Correct position";
				cin>>pos;
				temp=enterXO_in_array(pos,'O');
			}
			player--;
		}
		temp1=no_win();
	}
	cout<<"\n Game Over";
	getch();
}


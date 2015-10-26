#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"movie.h"
# define auth 1234
void main()		//main function
	{start:
	home();
	int ch;
	scanf("%d",&ch);
	switch(ch)
		{case 1:ulogin(); break;
 		case 2:create(); break;
 		case 3:elogin(); break;
 		case 4:release(); break;
 		case 5:exit(0);
 		default:printf("\nwrong choice"); goto start;
	}
	goto start;
	}

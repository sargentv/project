#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
# define auth 1234
struct d{
	 int date;
	 int month;
	 char day[10];
  	 int year;
	};
struct p{
	struct d st;
	int time;
	int seats;
	float price;
	};
typedef struct{		//for entering new movie
	      char m_name[25];
	      int rating;
	      char m_type[10];
	      char theatre[25];
	      char actor_name[3][25];
	      int nos;
	      struct d r_date;
	      struct p x[21];		//only 3 shows in a day
	      }movie;
typedef struct{		//for booking tickets
	       float t_cost;
	       float c_charge;
	       int credit;
               long int bank_card;
               long int a_id;
               char cin[25];
               char mov[25];
               int s_no[100];
	       struct p q;		//show date, time, price
	      }book;
typedef struct{		//for user profile
	      long int a_id;		//account id
	      char pass[25];
	      char name[25];
	      char email[100];
	      int credits;	
	      long long int p_no;		//phone no.
	      }user;

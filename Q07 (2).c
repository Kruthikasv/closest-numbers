#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int leap_year(int year);
int number_of_days(int day,int month,int year);

#define MAX_LINE_SIZE 250
int days_in_month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(int argc, char *argv[]) 
{
  FILE *fp;
  FILE *fd;
  char *filename = argv[1];
  char line[MAX_LINE_SIZE];
  struct tm tm[250];
  time_t epoch;
  int i=0,j,k=0;
  int diff[250];
  int year[250];
  int month[250];
  int days[100];
  struct dob
  {
   int year;
  int month;
  int days;
  };
  struct dob d[10];
  struct dob *dob1;
  struct dob *dob2;

  if (argc != 2) 
    {
    printf("Usage: Q07 <inpfile>");

    }
		

  if ((fd= fopen("sample.txt", "r")) == NULL) 
    {
    printf("Error in opening file %s\n", filename);

    }
				
           while (fgets(line, MAX_LINE_SIZE, fd) != NULL) 
           {
             line[strnlen(line, MAX_LINE_SIZE) - 1] = '\0';
             if (strptime(line, "%Y-%m-%d", &tm[i]) != NULL)
             {
                epoch = mktime(&tm);
                printf("%s\n ", line);
           d[i].days=tm[i].tm_mday;
		d[i].year=1900+tm[i].tm_year;
		d[i].month=1+tm[i].tm_mon;
                i++;
              } 
             else 
                printf("Invalid date %s in input", line);
    
         
	

        }
				
		for(i=0;i<10;i++)
		{
			for(j=i+1;j<10;j++)
			{
				diff[k] = number_of_days(d[i].days,d[i].month,d[i].year)-number_of_days(d[j].days,d[j].month,d[j].year);
				
                                
				 int minDiff = 10000;
		                if (abs(diff[k]) <= minDiff)
				{
					minDiff=diff[k];
					  dob1=&d[i];
					 dob2=&d[j];
				}
				
		               k++;
			}
		}
	
 		printf("The closest pair is %d/%d/%d and %d/%d/%d\n",dob1->days,dob1->month,dob1->year,dob2->days,dob2->month,dob2->year);			
              
}


int leap_year(int year) {
    if(year%400==0) return 1;

    	else
         return 0;
}



    int number_of_days(int day,int month,int year) {
    int result = 0;
    int i;

    for(i=1900; i < year; i++) {
        if(leap_year(i))
            result=abs(result+366);
        else
            result=abs(result+365);
    }

    for(i=1; i <month; i++) {
        result =abs(result+ days_in_month[i]);

        if(leap_year(year) && i == 2) 
            result++;
    }

    result =abs(result+ day);
    return result;
}

   

    

   













#include<stdio.h>
#include<string.h>

int main()
 {    int i,j,ok=1,dem=0;
     char s[100],s2[100];

            printf("Nhap chuoi S1: ");

            gets(s);

            fflush(stdin);

            printf("Nhap chuoi S2: ");

            gets(s2);
           
		    

            for(i=0; i<strlen(s); i++)
			 {   if(s[i] == s2[0]) 
			 		{ ok = 1;
                         for(j=0; j<strlen(s2); j++)
						  {
                               if(s2[j] != s[i+j])
							    {  ok = 0;
                                      break;
                                 }
                         }
                     if(ok == 1)
                        dem++;
                     }
             }
             printf("\n chuoi s2 trong s1 la %d",dem);
}


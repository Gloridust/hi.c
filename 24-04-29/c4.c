#include<stdio.h>
#include<string.h>

int main(){
    char s[12]={'I',' ','L','O','V','E',' ','C','H','I','N','A'};
    int i,x;
    for ( i = 0; i < 12; i++)
    {
        printf("%c",s[i]);
    }
    printf("\n");
    printf("%s\n",s);
    printf("The length of s is:%ld",strlen(s));
    printf("\n");

    for ( i = 0; i < strlen(s); i++)
    {
        if (s[i]!=' ')
        {
            x++;
        }
        
    }
    x=(strlen(s)-x);
    printf("The length of s without space is:%ld",x);
    printf("\n");

    return 0;
}

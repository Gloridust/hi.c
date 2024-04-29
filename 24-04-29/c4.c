#include<stdio.h>
#include<string.h>

int main(){
    char s[12]={'I',' ','L','O','V','E',' ','C','H','I','N','A'};
    int i;
    for ( i = 0; i < 12; i++)
    {
        printf("%c",s[i]);
    }
    printf("\n");
    printf("%s",s);
    printf("\n");

    return 0;
}
#include<stdio.h>
#include<string.h>

int main()
{
    char a[256],b[256];
    printf("Please input the string:");
    gets(a);
    // printf("%s\n",a);

    int i=0;
    while (a[i]!='\0')
    {
        b[i]=a[i];
        i++;
    }
    b[i]='\0';
    puts(b);
    // printf("%s\n",b);
    return 0;
}

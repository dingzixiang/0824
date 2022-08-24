#include"function.h"

void main()
{
    int ch;
    welcome();
    while(1)
    {
        char x=0;
        menu();
        printf("请输入功能需要：");
        x=getchar();
            while ((ch = getchar()) != EOF && ch != '\n');
        switch (x)
        {
        case 49:
            add();
            break;
        case 50:
            view();
            break;
        case 51:
            search();          
            break;
        case 52:
           del();
            break;
        case 53:
           mod();
            break;   
        case 54:
            exit(0);         
        default:
            printf("错误输入,请重新输入\n");
            break;
        }
    }
}
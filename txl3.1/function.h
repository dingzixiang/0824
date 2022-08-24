#ifndef _FUNCTION_
#define _FUNCTION_
#include<stdio.h>
#include<stdlib.h>
typedef struct user{
    int id;
    char name[32];
    int age;
    char tel[12];
} PP;
#define MAX 1024
PP p[MAX];
static int o=0;
int ch;
size_t my_strlen(const char*s);//获取一个字符串的长度
int my_strcmp(const char*s1, const char*s2);//比较两个字符串的大小
void *my_strcpy(char*s1,const char*s2);//将字符串s2赋值到s1
void *my_strcat(char*s1,const char*s2);//将字符串s2追加到s1的尾部

void welcome();//欢迎
void menu();//菜单

void add();//添加信息
void view();//查看信息
void search();//搜索信息
void del();//删除信息
void mod();//修改信息
#endif
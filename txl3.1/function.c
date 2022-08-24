#include"function.h"
size_t my_strlen(const char*s)
{
        size_t len = 0; 
        while (*s++ != '\0')
          {
            len++;
            }   
            return len;
}     

int my_strcmp(const char*s1, const char*s2)
{
    while(*s1 != '\0'&&*s2!='\0')
    {
         if (*s1 > *s2)
        {
            return 1;
        }
        else if (*s2 > *s1)
        {
            return -1;
        }
        else
        {
            s1++;
            s2++;
        }
    }
        if(*s1 != '\0')
            return 1;
        else if(*s2 != '\0')
            return -1;
        else
            return 0;                 
}

void *my_strcpy(char*s1,const char*s2)
{
    while(*s2!='\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}

void *my_strcat(char*s1,const char*s2)
{
    while(*s1 != '\0')
    {
        s1++;
    }
    while(*s2 != '\0')
    {
        *s1=*s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}
void welcome()
{
    printf("****************************************************************\n");
    printf("\t\t欢迎\n");
    printf("****************************************************************\n");
}
void menu()
{
    printf("****************************************************************\n");
    printf("\t\t1.添加用户信息\t\t2.查看用户信息\n");
    printf("\t\t3.搜索用户信息\t\t4.删除用户信息\n");
    printf("\t\t5.修改用户信息\t\t6.退出系统\n");
    printf("****************************************************************\n");
}

void add()
{
    char a='0'; 
    char b[32]={0};
    char c[12]={0};
    int m=0,n=0;
    FILE *fp = fopen("./1.txt","a"); 
    if(NULL == fp) 
        { 
        perror("fopen"); 
        return ; 
        }
    printf("\t\t添加用户信息\n");
    printf("请输入添加信息的id,姓名,年龄,电话号码\n");
    do
    {
    printf("请输入添加的id:");
    scanf("%d", &m);
    p[o].id=m;
    getchar();
    printf("请输入添加的姓名:");
    gets(b);
    my_strcpy(p[o].name,b);
    printf("请输入添加的年龄:");
    scanf("%d", &n);
    getchar();
    p[o].age=n;
    printf("请输入添加的电话号码:");
    gets(c);
    my_strcpy(p[o].tel,c);
    if(fwrite(&p[o],sizeof(p[o]),1,fp)==-1)
    {
    perror("fwrite");
    return;
    }
    o++;
one:
    printf("是否继续添加y/n:\n");
    a=getchar();
    if(a=='y'||a=='Y')
    {continue;}
    else if(a=='n'||a=='N')
    {fclose(fp);break;}
    else
    {
        goto one;
    }
    } while (1);
        while ((ch = getchar()) != EOF && ch != '\n');
}
void view()
{
    printf("\t\t查看用户信息\n");
    int i,j,f,q,k;
    char s[12],t[32];
    o=0;
     FILE *fp = fopen("./1.txt","r"); 
    if(NULL == fp) 
        { 
        perror("fopen"); 
        return ; 
        }
        while(1)
        {
        if(0 == fread(&p[o],sizeof(p[o]),1,fp))
        { 
            if(feof(fp)) 
        { 
            printf("读到文件末尾\n"); 
        break; 
        }
        else 
        { 
            perror("fread"); 
        return ; 
        } 
        }
        o++;
        }
        if(o==0)
    {
    printf("通讯录为空\n");
    return ;
    }
    for(i=0;i<o-1;i++)
    {
        for(j=0;j<o-i-1;j++)
        {
            k=my_strcmp(p[j].name,p[j+1].name);
            if(k>0)
            {
                my_strcpy(t, p[j+1].name);
                my_strcpy(p[j+1].name,p[j].name);
                my_strcpy(p[j].name,t);
                //电话交换
                my_strcpy(s, p[j+1].tel);
                my_strcpy(p[j+1].tel,p[j].tel);
                my_strcpy(p[j].tel,s);
                //id交换
                f=p[j+1].id;
                p[j+1].id=p[j].id;
                p[j].id=f;
                //年龄交换
                f=p[j+1].age;
                p[j+1].age=p[j].age;
                p[j].age=f;
            }
        }
    }
    for(i=0;i<o;i++)
    {
        printf("第%d位ID=%d\t",i+1,p[i].id);
        printf("NAME=%s\t",p[i].name);
        printf("AGE=%d\t",p[i].age);
        printf("TEL=%s\n",p[i].tel);
    }    
    fclose(fp);
}
void search()
{
    char a,b[32];
    int m=0,i=0,n=0,j=0;
    printf("\t\t搜索用户信息\n");
        o=0;
     FILE *fp = fopen("./1.txt","r"); 
    if(NULL == fp) 
        { 
        perror("fopen"); 
        return ; 
        }
        while(1)
        {
        if(0 == fread(&p[o],sizeof(p[o]),1,fp))
        { 
            if(feof(fp)) 
        { 
            printf("读到文件末尾\n"); 
        break; 
        }
        else 
        { 
            perror("fread"); 
        return ; 
        } 
        }
        o++;
        }
        if(o==0)
    {
    printf("通讯录为空\n");
    return ;
    }
two:
    printf("请1选择ID搜索,按2选择用户名搜索:");
    a=getchar();
    if(a=='1')
    {
twoone:
    printf("请输ID:");
    scanf("%d", &m);
    getchar();
    for(i=0;i<=o;i++)
    {
        if(m==p[i].id)
        {
        printf("ID=%d\t",p[i].id);
        printf("NAME=%s\t",p[i].name);
        printf("AGE=%d\t",p[i].age);
        printf("TEL=%s\n",p[i].tel);   
        break;         
        }
    }
    if(i==o+1)
    {
    printf("查无此ID,请重新输入\n");
    goto twoone;
    }
    }
    else if(a=='2')
    {
twotwo:
    printf("请输姓名:");
        while ((ch = getchar()) != EOF && ch != '\n');
        gets(b);
    for(j=0;j<=o;j++)
    {
        n=my_strcmp(p[j].name,b);
        if(n==0)
        {
        printf("ID=%d\t",p[j].id);
        printf("NAME=%s\t",p[j].name);
        printf("AGE=%d\t",p[j].age);
        printf("TEL=%s\n",p[j].tel);     
        break;
        }
    }
    if(i==o+1)
    {
    printf("查无此姓名,请重新输入\n");
    goto twotwo;
    }    
    }
    else
    {
        printf("输入错误,请重新输入\n");
        goto two;
    }
    fclose(fp);
}
void del()
{
       char a,b[32];
    int m=0,i=0,n=0,j=0;
    printf("\t\t删除用户信息\n");
        o=0;
     FILE *fp = fopen("./1.txt","r"); 
    if(NULL == fp) 
        { 
        perror("fopen"); 
        return ; 
        }
        while(1)
        {
        if(0 == fread(&p[o],sizeof(p[o]),1,fp))
        { 
            if(feof(fp)) 
        { 
            printf("读到文件末尾\n"); 
        break; 
        }
        else 
        { 
            perror("fread"); 
        return ; 
        } 
        }
        o++;
        }
        if(o==0)
    {
    printf("通讯录为空\n");
    return ;
    }
    fclose(fp);
twoone:
    printf("请输要删除的ID:");
    scanf("%d", &m);
    getchar();
    for(i=0;i<=o;i++)
    {                                                                                                                           
        if(m==p[i].id)
        {
        printf("ID=%d\t",p[i].id);
        printf("NAME=%s\t",p[i].name);
        printf("AGE=%d\t",p[i].age);
        printf("TEL=%s\n",p[i].tel);
        printf("是否确认删除y/n:");
        a=getchar();
          while ((ch = getchar()) != EOF && ch != '\n');
              if(i==o+1)
    {
    printf("查无此ID,请重新输入\n");
    goto twoone;
    }
        if(a=='y'||a=='Y')
        {
    FILE *fp = fopen("./1.txt","w"); 
    if(NULL == fp) 
        { 
        perror("fopen"); 
        return ; 
        }
            for(j=i;j<o;j++)
            {
                p[j].id=p[j+1].id;
                p[j].age=p[j+1].age;
                my_strcpy(p[j].name,p[j+1].name);
                my_strcpy(p[j].tel,p[j+1].tel);
            }
            o--;
            while(o>0)
            {
            if(fwrite(&p[o-1],sizeof(p[o-1]),1,fp)==-1)
        {
        perror("fwrite");
        return;
        }
            o--;
            }
            fclose(fp);
            printf("删除完成\n");
            break;
        }
        else if(a=='n'||a=='N')
        {
            printf("取消删除\n");
            break;
        }
        }
    }
}
void mod()
{
       char a,c[32],d[12];
    int m=0,i=0,x,y;
    printf("\t\t修改用户信息\n");
        o=0;
    FILE *fp = fopen("./1.txt","r"); 
    if(NULL == fp) 
        { 
        perror("fopen"); 
        return ; 
        }
        while(1)
        {
        if(0 == fread(&p[o],sizeof(p[o]),1,fp))
        { 
            if(feof(fp)) 
        { 
            printf("读到文件末尾\n"); 
        break; 
        }
        else 
        { 
            perror("fread"); 
        return ; 
        } 
        }
        o++;
        }
        if(o==0)
    {
    printf("通讯录为空\n");
    return ;
    }
    fclose(fp);
twoone:
    printf("请输要修改信息的ID:");
    scanf("%d", &m);
    getchar();
    for(i=0;i<=o;i++)
    {                                                                                                                           
        if(m==p[i].id)
        {
        printf("ID=%d\t",p[i].id);
        printf("NAME=%s\t",p[i].name);
        printf("AGE=%d\t",p[i].age);
        printf("TEL=%s\n",p[i].tel);
        printf("是否确认修改y/n:");
        a=getchar();
            if(i==o+1)
    {
    printf("查无此ID,请重新输入\n");
    goto twoone;
    }    
        if(a=='y'||a=='Y')
        {
        FILE *fp = fopen("./1.txt","w"); 
        if(NULL == fp) 
            { 
            perror("fopen"); 
            return ; 
            }
            printf("请输入修改后的id:");
            scanf("%d", &x);
            p[i].id=x;
            getchar();
            printf("请输入修改后的姓名:");
            gets(c);
            my_strcpy(p[i].name,c);
            printf("请输入修改后的年龄:");
            scanf("%d", &y);
            getchar();
            p[i].age=y;
            printf("请输入修改后的电话号码:");
            gets(d);
            my_strcpy(p[i].tel,d);
            while(o>0)
            {
            if(fwrite(&p[o-1],sizeof(p[o-1]),1,fp)==-1)
        {
        perror("fwrite");
        return;
        }
        o--;
            }
            fclose(fp);
            printf("修改完成\n");
            break;
        }
        else if(a=='n'||a=='N')
        {
            printf("取消修改\n");
            break;
        }
        }
    }
}
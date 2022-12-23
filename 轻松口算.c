/*以下为项目说明
 软件名称：Caculate-Test-App
 面向的用户：小学生
 主要功能：训练口算
 用法说明：跟着菜单提示操作就行
 设计创新点：
 开发环境：Jetbrains Clion2022.2(采用MinGW编译器，版本w64 9.0 采用CMake 版本3.23.2)
          EasyX For Mingw 2022版库文件
 关于EasyX：
    easyx4mingw_20220606.zip
	├ include <folder>
	│	├ easyx.h 				// 头文件(提供了当前最新版本的接口)
	│	└ graphics.h			// 头文件(在 easyx.h 的基础上，保留了若干旧接口)
	├ lib32 <folder>
	│	└ libeasyx.a			// 针对 TDM-GCC 4.8.1 及以上版本的 32 位库文件
	├ lib64 <folder>
	│	└ libeasyx.a			// 针对 TDM-GCC 4.8.1 及以上版本的 64 位库文件
	└ lib-for-devcpp_5.4.0
		└ libeasyx.a			// 适用于 DevCpp 5.4.0 GCC MinGW 4.7.2 和 C-Free 5.0
 */

/*
 源码和成果展示可访问https://github.com/VincentCroft/Caculate-Test-App获取更多信息(请阅读README.md)
 并可以获取到已经构建好的程序
 */

//
// Created by VincentCroft on 2022/12/24.
//
#include <stdio.h>
#include <stdlib.h> //随机数，用到rand()函数
#include <time.h> //更改种子，统计时间用到clock()函数
#include <windows.h>
#include <string.h>

//全局变量
int a, b; //a,b分别是两个操作数
int c;//调整此参数以求出多少以内的计算题
int answer; //用户输入的答案
int value;//该题的正确答案
int right = 0; //恭喜你答对了！的题目数量
int number; //自定义出题个数
int op,set; //菜单选项
double begintime, endtime;//用于统计运行时间
char str[2];//用于拼接运算符号
char Title[20];//用于保存题目

void TitleSave(int a,int b)
{
    char str1[50];
    char str2[10];
    char str3[20];
    char str4[]={"="};
    char str5[]={"    Your Wrong Answer Is: "};
    char str6[20];
    itoa(a, str1, 10);
    itoa(b, str2, 10);
    itoa(answer, str6, 10);
    itoa(value, str3, 10);
    strcat(str1,str);
    strcat(str1,str2);
    strcat(str1,str4);
    strcat(str1,str3);
    strcat(str1,str5);
    strcat(str1,str6);
    strcpy(Title, str1);
}

void WrongSave(char Wrong[])
{
    FILE *fp;
    fp = fopen("E:\\Coding\\C\\Caculate Test App\\test.txt","r");
    if(fp!= NULL)          // 判断要创建的文件是否存在
    {
        fp=fopen("E:\\Coding\\C\\Caculate Test App\\test.txt","a+");
        fputs(Wrong, fp);
        fprintf(fp, "\r\n");
    }
    //  关闭流fp。刷新所有的缓冲区。
    fclose(fp);
}

int FileToSave()
{
    FILE *fp,*fp1;
    fp = fopen("E:\\Coding\\C\\Caculate Test App\\test.txt","r");
    if(fp!= NULL)          // 判断要创建的文件是否存在
    {
        printf("(文件存在,已经保存错题)\n");
    }
    else
    {
        //   如果文件不存在则创建文件
        printf("(文件不存在，将创建文件来初始化)\n");
        fp1 = fopen("E:\\Coding\\C\\Caculate Test App\\test.txt","w");
        //   创建文件,"w"该文件可写
        //  w:创建一个用于写入的空文件。如果文件名称与已存在的文件相同，则会删除已有文件的内容，文件被视为一个新的空文件。
        if(fp1==NULL)
        {
            //  文件没有创建则把一个描述性错误消息输出到标准错误 stderr    void perror(const char *str)
            perror("Error: ");
            return -1;
        }
    }
    fp=fopen("E:\\Coding\\C\\Caculate Test App\\test.txt","a+");
    fputs("-----Your Wrong Answer Sheet-----", fp);
    fprintf(fp, "\r\n");
    //  关闭流fp。刷新所有的缓冲区。
    fclose(fp);
    return 1;
}

void NemuPrint()
{
    // 打印菜单
    printf("==========菜单==========\n");
    printf("输入1. 出10道题           =\n");
    printf("输入2. 出100道题          =\n");
    printf("输入3. 出1000道题         =\n");
    printf("输入4. 自定义出题数目      =\n");
    printf("输入0. 退出程序           =\n");
    printf("=======================\n");
}

void SetPrint()
{
    // 打印难度档
    printf("=========难度选择========\n");
    printf("输入1. 出10以内的题目      =\n");
    printf("输入2. 出100以内的题目     =\n");
    printf("输入3. 出1000以内的题目    =\n");
    printf("=======================\n");
}

void Feedback()
{
    double n,m,x;
    n=number;
    m=right;
    x=(m/n)*100;
    printf("=======================\n");
    printf("本次测试一共有%d题，你答对了%d题\n",number,right);
    printf("你的正确率为%lf%%,你总共用时%lf秒\n",x,(endtime-begintime)/1000);
    if(x<50)            //该判断用于实现对作答情况进行反馈
    {
        if(x<25)
        {
            printf("(Tips:小朋友，再这样下去要被老师找去喝茶啦)\n");
        }
        else
            printf("(Tips:小朋友，你要加油啊)\n");
    }
    else
    {
        if(x>75)
        {
            printf("(Tips:小朋友，你实在是太棒啦)\n");
        }
        else
            printf("(Tips:小朋友，你还不错)\n");
    }
    printf("=======================\n");
}

// 加法题目
void Add()
{
    srand(time(NULL));
    a = rand() % (c + 1);
    b = rand() % (c + 1);
    printf("%d+%d=", a, b);
    scanf("%d", &answer);
    value=a+b;
    str[0]='+';
    TitleSave(a,b);
    if (a + b == answer)
    {
        printf("恭喜你答对了！\n");
        right++;
    }
    else
    {
        printf("很遗憾你答错了！\n");
        WrongSave(Title);
    }
}

// 减法题目
void Sub()
{
    srand(time(NULL));
    do
    {
        a = rand() % (c + 1);
        b = rand() % (c + 1);
    } while (a < b);
    printf("%d-%d=", a, b);
    scanf("%d", &answer);
    value=a-b;
    str[0]='-';
    TitleSave(a,b);
    if (a - b == answer)
    {
        printf("恭喜你答对了！\n");
        right++;
    }
    else
    {
        printf("很遗憾你答错了！\n");
        WrongSave(Title);
    }
}

//乘法题目
void Multiplication()
{
    srand(time(NULL));
    a = rand() % (c + 1);
    b = rand() % (c + 1);
    printf("%d*%d=", a, b);
    scanf("%d", &answer);
    value=a*b;
    str[0]='*';
    TitleSave(a,b);
    if (a * b == answer)
    {
        printf("恭喜你答对了！\n");
        right++;
    }
    else
    {
        printf("很遗憾你答错了！\n");
        WrongSave(Title);
    }
}

//除法题目
void Div()
{
    srand(time(NULL));
    do
    {
        a = rand() % (c + 1);
        b = rand() % (c + 1);
    } while (a < b || a % b != 0 || b == 0);
    printf("%d/%d=", a, b);
    scanf("%d", &answer);
    value=a/b;
    str[0]='/';
    TitleSave(a,b);
    if (a / b == answer)
    {
        printf("恭喜你答对了！\n");
        right++;
    }
    else
    {
        printf("很遗憾你答错了！\n");
        WrongSave(Title);
    }
}

//出题的，number是出题的个数
void Give(int number)
{
    printf("本次出题数量是%d题\n", number);
    begintime = clock();    //计时开始
    for (int i = 1; i <= number; i++)
    {
        switch (rand() % 4)
        {
            case 0:
                Add();
                break;
            case 1:
                Sub();
                break;
            case 2:
                Multiplication();
                break;
            case 3:
                Div();
                break;
        }
    }
    endtime = clock();    //计时结束
}

void result()// 输出结果
{
    while (1)
    {
        NemuPrint();
        printf("请输入功能所在的序号：");
        scanf("%d", &op);
        if(op == 0)
        {
            printf("感谢使用");
            break;
        }
        SetPrint();
        printf("请输入功能所在的序号：");
        scanf("%d", &set);
        switch (set)//难度调档
        {
            case 1:
                c=9;
                break;
            case 2:
                c=99;
                break;
            case 3:
                c=999;
                break;
        }
        printf("是否启用错题保存功能？(y/n):");
        char Justice;
        scanf("%s",&Justice);
        if(Justice=='y')
        {
            printf("=======保存功能启用========\n");
            FileToSave();
        }
        if(op == 0)
        {
            printf("感谢使用");
            break;
        }
        else
        {
            switch (op)
            {
                case 1:
                    number = 10;
                    Give(number);
                    break;
                case 2:
                    number = 100;
                    Give(number);
                    break;
                case 3:
                    number = 1000;
                    Give(number);
                    break;
                case 4:
                    printf("请输入你要出题的个数：");
                    scanf("%d", &number);
                    Give(number);
                    break;
            }
            Feedback();
            printf("\n");
            right = 0;
        }
    }
}

int main()
{
    result();
    system("pause");
    return 0;
}

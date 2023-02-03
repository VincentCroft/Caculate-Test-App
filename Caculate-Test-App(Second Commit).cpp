/*以下为项目说明
 软件名称：Caculate-Test-App
 面向的用户：小学生
 主要功能：训练口算
 用法说明：
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
#define c 1000//调整此参数以求出多少以内的计算题

//全局变量
int a, b; //a,b分别是两个操作数
int answer; //用户输入的答案
int right = 0; //恭喜你答对了！的题目数量
int number; //自定义出题个数
int op; //菜单选项
double begintime, endtime;//用于统计运行时间

void NemuPrint()
{
    // 打印菜单
    printf("==========菜单==========\n");
    printf("输入1. 出10道题           =\n");
    printf("输入2. 出20道题           =\n");
    printf("输入3. 出100道题          =\n");
    printf("输入4. 自定义出题数目      =\n");
    printf("输入0. 退出程序           =\n");
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
    if (a + b == answer)
    {
        printf("恭喜你答对了！\n");
        right++;
    } else {
        printf("很遗憾你答错了！\n");
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
    if (a - b == answer)
    {
        printf("恭喜你答对了！\n");
        right++;
    } else {
        printf("很遗憾你答错了！\n");
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
    if (a * b == answer)
    {
        printf("恭喜你答对了！\n");
        right++;
    } else {
        printf("很遗憾你答错了！\n");
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
    if (a / b == answer)
    {
        printf("恭喜你答对了！\n");
        right++;
    }
    else
    {
        printf("很遗憾你答错了！\n");
    }
}

//出题的，number是出题的个数
void Give(int number)
{
    printf("本次出题数量是%d题，请按回车键开始\n", number);
    getchar();
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

void function()// 输出结果
{
    while (1)
    {
        NemuPrint();
        printf("请输入功能所在的序号\n");
        scanf("%d", &op);
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
                    number = 20;
                    Give(number);
                    break;
                case 3:
                    number = 100;
                    Give(number);
                    break;
                case 4:
                    printf("请输入你要出题的个数：\n");
                    scanf("%d", &number);
                    Give(number);
                    break;
            }
            printf("本次测试一共有%d题，你答对了%d题，你总共用时%lf秒\n",number,right,(endtime-begintime)/1000);
            printf("是否重新测试?按0退出\n");
            scanf("%d", &op);
            if(op==0)
            {
                printf("感谢您的使用");
                break;
            } else right = 0;
        }
    }
}

int main()
{
    function();
    return 0;
}

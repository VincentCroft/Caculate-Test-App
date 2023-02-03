//
// Created by Vincent Croft on 2023/1/27.
//
#include <graphics.h>//图形界面
#include <stdio.h>
#include <stdlib.h> //随机数，用到rand()函数
#include <time.h> //更改种子，统计时间用到clock()函数
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#include <math.h>
#include <string.h>


//全局变量
int a, b; //a,b分别是两个操作数
int c;//调整此参数以求出多少以内的计算题
int answer; //用户输入的答案
int value;//该题的正确答案
int right = 0; //恭喜你答对了！的题目数量
int number; //自定义出题个数
int op,set; //菜单选项
int count=0;//用于统计WrongAnswerSheet
double begintime, endtime;//用于统计运行时间
char str[2];//用于拼接运算符号
char Title[40];//用于保存题目
char SavePlace[100];// 用于保存路径
char sheetcount[40];




void SheetCount()
{
    count++;
    char str1[5];
    char str2[]={"-----Your Wrong Answer Sheet"};
    char str3[]={"-----"};
    itoa(count, str1, 10);
    strcat(str2,str1);
    strcat(str2,str3);
    strcpy(sheetcount,str2);

}

void TitleSave(int a,int b)
{
    char str1[40];
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
    fp=fopen(SavePlace,"a+");
    fputs(Wrong, fp);
    fprintf(fp, "\r\n");
    //  关闭流fp。刷新所有的缓冲区。
    fclose(fp);
}

void FileToSave()
{
    FILE *fp,*fp1;
    char name[100];
    SheetCount();
    printf("请输入想要保存错题的路径“例如：E:\\test.txt”)：");
    scanf("%s",name);
    strcpy(SavePlace,name);
    fp = fopen(name,"r");
    if(fp!= NULL)          // 判断要创建的文件是否存在
    {
        printf("(文件存在,已经保存错题)\n");
    }
    else
    {
        //   如果文件不存在则创建文件
        printf("(文件不存在，将创建文件来初始化)\n");
        fp1 = fopen(name,"w");
        //   创建文件,"w"该文件可写
        //  w:创建一个用于写入的空文件。如果文件名称与已存在的文件相同，则会删除已有文件的内容，文件被视为一个新的空文件。
        if(fp1==NULL)
        {
            //  文件没有创建则把一个描述性错误消息输出到标准错误 stderr    void perror(const char *str)
            perror("Error: ");
        }
    }
    fp=fopen(name,"a+");
    fputs(sheetcount, fp);
    fprintf(fp, "\r\n");
    //  关闭流fp。刷新所有的缓冲区。
    fclose(fp);
}

// 加法题目
void Add()
{
    cleardevice();//每次显示左右键按下后清屏
    char AddStr1[10];
    char AddStr2[]{"+"};
    char AddStr3[10];
    char AddStr4[]={"="};
    srand(time(NULL));
    a = rand() % (c + 1);
    b = rand() % (c + 1);
    itoa(a, AddStr1, 10);
    itoa(b, AddStr3, 10);
    strcat(AddStr1,AddStr2);
    strcat(AddStr1,AddStr3);
    strcat(AddStr1,AddStr4);
    outtextxy(100, 60,AddStr1 );//printf("%d+%d=", a, b);
    scanf("%d", &answer);
    value=a+b;
    str[0]='+';
    TitleSave(a,b);
    if (a + b == answer)
    {
        outtextxy(100, 80,"恭喜你答对了！" );//printf("恭喜你答对了！\n");
        right++;
    }
    else
    {
        outtextxy(100, 80,"很遗憾你答错了！" );//printf("很遗憾你答错了！\n");
        WrongSave(Title);
    }
}

// 减法题目
void Sub()
{
    cleardevice();//每次显示左右键按下后清屏
    char SubStr1[10];
    char SubStr2[]{"-"};
    char SubStr3[10];
    char SubStr4[]={"="};
    srand(time(NULL));
    do
    {
        a = rand() % (c + 1);
        b = rand() % (c + 1);
    } while (a < b);
    itoa(a, SubStr1, 10);
    itoa(b, SubStr3, 10);
    strcat(SubStr1,SubStr2);
    strcat(SubStr1,SubStr3);
    strcat(SubStr1,SubStr4);
    outtextxy(100, 60,SubStr1 );//printf("%d-%d=", a, b);
    scanf("%d", &answer);
    value=a-b;
    str[0]='-';
    TitleSave(a,b);
    if (a - b == answer)
    {
        outtextxy(100, 80,"恭喜你答对了！" );//printf("恭喜你答对了！\n");
        right++;
    }
    else
    {
        outtextxy(100, 80,"很遗憾你答错了！" );//printf("很遗憾你答错了！\n");
        WrongSave(Title);
    }
}

//乘法题目
void Multiplication()
{
    cleardevice();//每次显示左右键按下后清屏
    char MulStr1[10];
    char MulStr2[]{"*"};
    char MulStr3[10];
    char MulStr4[]={"="};
    srand(time(NULL));
    a = rand() % (c + 1);
    b = rand() % (c + 1);
    itoa(a, MulStr1, 10);
    itoa(b, MulStr3, 10);
    strcat(MulStr1,MulStr2);
    strcat(MulStr1,MulStr3);
    strcat(MulStr1,MulStr4);
    outtextxy(100, 60,MulStr1 );//printf("%d*%d=", a, b);
    scanf("%d", &answer);
    value=a*b;
    str[0]='*';
    TitleSave(a,b);
    if (a * b == answer)
    {
        outtextxy(100, 80,"恭喜你答对了！" );//printf("恭喜你答对了！\n");
        right++;
    }
    else
    {
        outtextxy(100, 80,"很遗憾你答错了！" );//printf("很遗憾你答错了！\n");
        WrongSave(Title);
    }
}

//除法题目
void Div()
{
    cleardevice();//每次显示左右键按下后清屏
    char DivStr1[10];
    char DivStr2[]{"/"};
    char DivStr3[10];
    char DivStr4[]={"="};
    srand(time(NULL));
    do
    {
        a = rand() % (c + 1);
        b = rand() % (c + 1);
    } while (a < b || a % b != 0 || b == 0);
    itoa(a, DivStr1, 10);
    itoa(b, DivStr3, 10);
    strcat(DivStr1,DivStr2);
    strcat(DivStr1,DivStr3);
    strcat(DivStr1,DivStr4);
    outtextxy(100, 60,DivStr1 );//printf("%d/%d=", a, b);
    scanf("%d", &answer);
    value=a/b;
    str[0]='/';
    TitleSave(a,b);
    if (a / b == answer)
    {
        outtextxy(100, 80,"恭喜你答对了！" );//printf("恭喜你答对了！\n");
        right++;
    }
    else
    {
        outtextxy(100, 80,"很遗憾你答错了！" );//printf("很遗憾你答错了！\n");
        WrongSave(Title);
    }
}

int Setup()
{
    cleardevice();//每次显示左右键按下后清屏
    char Setup1[]={"  ==========难度选择========="};
    char Setup2[]={"  =  按键1. 出10以内的题目   ="};
    char Setup3[]={"  =  按键2. 出100以内的题目  ="};
    char Setup4[]={"  =  按键3. 出1000以内的题目 ="};
    char Setup5[]={"  =========================="};
    LOGFONT f;//字体样式指针
    gettextstyle(&f);					//获取字体样式
    _tcscpy(f.lfFaceName,_T("宋体"));	//设置字体为宋体
    f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿
    settextstyle(&f);                     // 设置字体样式
    settextcolor(BLACK);				//BLACK在graphic.h头文件里面被定义为黑色的颜色常量
    outtextxy(100, 40, Setup1);
    outtextxy(100, 60, Setup2);
    outtextxy(100, 80, Setup3);
    outtextxy(100, 100, Setup4);
    outtextxy(100, 160, Setup5);

    // 定义三个按钮的位置和大小
    int button_w = 50, button_h = 20, button_spacing = 10;
    int button1_x = 50, button1_y = 250;
    int button2_x = button1_x + button_w + button_spacing, button2_y = button1_y;
    int button3_x = button2_x + button_w + button_spacing, button3_y = button1_y;
    int button4_x = button3_x + button_w + button_spacing, button4_y = button1_y;

    // 绘制五个按钮
    fillrectangle(button2_x, button2_y, button2_x + button_w, button2_y + button_h);
    fillrectangle(button3_x, button3_y, button3_x + button_w, button3_y + button_h);
    fillrectangle(button4_x, button4_y, button4_x + button_w, button4_y + button_h);


    // 在按钮上写上文本
    settextcolor(WHITE); // 设置文本颜色为黑色
    settextstyle(12, 0, _T("微软雅黑")); // 设置文本样式
    outtextxy(button2_x + 15, button2_y + 5, _T("按钮1"));
    outtextxy(button3_x + 15, button3_y + 5, _T("按钮2"));
    outtextxy(button4_x + 15, button4_y + 5, _T("按钮3"));
    while (true)
    {
        // 获取鼠标点击位置
        MOUSEMSG msg = GetMouseMsg();//接收鼠标信息

        if (MouseHit())//按钮1
        {
            // 判断点击是否在按钮上
            switch (msg.uMsg)
            {//uMsg判断鼠标信息是什么信息(左键信息或者右键信息)
                case WM_LBUTTONDOWN://左键按下
                    if (msg.x > button2_x && msg.x < button2_x + button_w && msg.y > button2_y &&
                        msg.y < button2_y + button_h) {
                        cleardevice();//每次显示左右键按下后清屏
                        c=9;
                    }break;
                case WM_RBUTTONDOWN://右键按下
                    if (msg.x > button2_x && msg.x < button2_x + button_w && msg.y > button2_y &&
                        msg.y < button1_y + button_h) {
                        cleardevice();//每次显示左右键按下后清屏
                        c=9;
                    }
                    break;
            }
        }

        if (MouseHit())//按钮2
        {
            // 判断点击是否在按钮上
            switch (msg.uMsg)
            {//uMsg判断鼠标信息是什么信息(左键信息或者右键信息)
                case WM_LBUTTONDOWN://左键按下
                    if (msg.x > button3_x && msg.x < button3_x + button_w && msg.y > button3_y &&
                        msg.y < button1_y + button_h) {
                        cleardevice();//每次显示左右键按下后清屏
                        c=99;
                    }break;
                case WM_RBUTTONDOWN://右键按下
                    if (msg.x > button3_x && msg.x < button3_x + button_w && msg.y > button3_y &&
                        msg.y < button3_y + button_h) {
                        cleardevice();//每次显示左右键按下后清屏
                        c=99;
                    }break;
            }
        }

        if (MouseHit())//按钮3
        {
            // 判断点击是否在按钮上
            switch (msg.uMsg)
            {//uMsg判断鼠标信息是什么信息(左键信息或者右键信息)
                case WM_LBUTTONDOWN://左键按下
                    if (msg.x > button4_x && msg.x < button4_x + button_w && msg.y > button4_y &&
                        msg.y < button4_y + button_h) {
                        cleardevice();//每次显示左右键按下后清屏
                        c=999;
                    }break;
                case WM_RBUTTONDOWN://右键按下
                    if (msg.x > button4_x && msg.x < button4_x + button_w && msg.y > button4_y &&
                        msg.y < button4_y + button_h) {
                        cleardevice();//每次显示左右键按下后清屏
                        c=999;
                    }break;
            }
        }
        // 等待一段时间
        Sleep(10);
    }
}

//出题的，number是出题的个数
int Give(int number)
{
    char Chuti1[30]={"本次出题量为"};
    char Chuti2[10];
    char Chuti3[10];
    itoa(number, Chuti2, 10);
    strcat(Chuti1,Chuti2);
    strcat(Chuti1,Chuti3);
    LOGFONT f;//字体样式指针
    gettextstyle(&f);					//获取字体样式
    _tcscpy(f.lfFaceName,_T("宋体"));	//设置字体为宋体
    f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿
    settextstyle(&f);                     // 设置字体样式
    settextcolor(WHITE);				//BLACK在graphic.h头文件里面被定义为黑色的颜色常量
    outtextxy(100, 40, Chuti1);
    Setup();
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

void graph()//提供图形界面
{
    char Menu1[]={"===========菜单=========="};
    char Menu2[]={"=    按钮1. 出10道题    ="};
    char Menu3[]={"=    按钮2. 出100道题   ="};
    char Menu4[]={"=    按钮3. 出1000道题  ="};
    char Menu5[]={"= 按钮4. 自定义出题数目 ="};
    char Menu6[]={"=    按钮0. 退出程序    ="};
    char Menu7[]={"=========================="};
    short win_width,win_height;//定义窗口的宽度和高度
    win_width = 400;win_height = 400;//调整窗口大小
    initgraph(win_width,win_height);//初始化窗口（黑屏）
    setbkmode(TRANSPARENT);
    IMAGE img;//欢迎背景图片设置
    putimage(0,0,&img);
    loadimage(NULL, "E:\\Coding\\C\\GUI version\\Background.jpg");
    // 等待一段时间
    Sleep(10);
    LOGFONT f;//字体样式指针
    gettextstyle(&f);					//获取字体样式
    _tcscpy(f.lfFaceName,_T("宋体"));	//设置字体为宋体
    f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿
    settextstyle(&f);                     // 设置字体样式
    settextcolor(BLACK);				//BLACK在graphic.h头文件里面被定义为黑色的颜色常量
    outtextxy(100, 40, Menu1);
    outtextxy(100, 60, Menu2);
    outtextxy(100, 80, Menu3);
    outtextxy(100, 100, Menu4);
    outtextxy(100, 120, Menu5);
    outtextxy(100, 140, Menu6);
    outtextxy(100, 160, Menu7);
    setfillcolor(BLACK); // 设置填充颜色为白色

    // 定义五个按钮的位置和大小
    int button_w = 50, button_h = 20, button_spacing = 10;
    int button1_x = 50, button1_y = 250;
    int button2_x = button1_x + button_w + button_spacing, button2_y = button1_y;
    int button3_x = button2_x + button_w + button_spacing, button3_y = button1_y;
    int button4_x = button3_x + button_w + button_spacing, button4_y = button1_y;
    int button5_x = button4_x + button_w + button_spacing, button5_y = button1_y;

    // 绘制五个按钮
    fillrectangle(button1_x, button1_y, button1_x + button_w, button1_y + button_h); // 绘制矩形
    fillrectangle(button2_x, button2_y, button2_x + button_w, button2_y + button_h);
    fillrectangle(button3_x, button3_y, button3_x + button_w, button3_y + button_h);
    fillrectangle(button4_x, button4_y, button4_x + button_w, button4_y + button_h);
    fillrectangle(button5_x, button5_y, button5_x + button_w, button5_y + button_h);

    // 在按钮上写上文本
    settextcolor(WHITE); // 设置文本颜色为黑色
    settextstyle(12, 0, _T("微软雅黑")); // 设置文本样式
    outtextxy(button1_x + 15, button1_y + 5, _T("按钮1"));
    outtextxy(button2_x + 15, button2_y + 5, _T("按钮2"));
    outtextxy(button3_x + 15, button3_y + 5, _T("按钮3"));
    outtextxy(button4_x + 15, button4_y + 5, _T("按钮4"));
    outtextxy(button5_x + 15, button5_y + 5, _T("关闭程序"));
    while (true)
    {
        // 获取鼠标点击位置
        MOUSEMSG msg = GetMouseMsg();//接收鼠标信息

        //printf("坐标为（%d,%d）", msg.x, msg.y);//显示鼠标坐标（检验用）

        if (MouseHit())//按钮1
        {
            // 判断点击是否在按钮上
            switch (msg.uMsg)
            {//uMsg判断鼠标信息是什么信息(左键信息或者右键信息)
                case WM_LBUTTONDOWN://左键按下
                    if (msg.x > button1_x && msg.x < button1_x + button_w && msg.y > button1_y &&
                        msg.y < button1_y + button_h) {
                        cleardevice();//每次显示左右键按下后清屏
                        Give(10);
                    }break;
                case WM_RBUTTONDOWN://右键按下
                    if (msg.x > button1_x && msg.x < button1_x + button_w && msg.y > button1_y &&
                        msg.y < button1_y + button_h) {
                        cleardevice();//每次显示左右键按下后清屏
                        Give(10);
                    }break;
            }
        }

        if (MouseHit())//按钮2
        {
            // 判断点击是否在按钮上
            switch (msg.uMsg)
            {//uMsg判断鼠标信息是什么信息(左键信息或者右键信息)
                case WM_LBUTTONDOWN://左键按下
                    if (msg.x > button2_x && msg.x < button2_x + button_w && msg.y > button2_y &&
                        msg.y < button2_y + button_h) {
                        cleardevice();//每次显示左右键按下后清屏
                        Give(100);
                    }break;
                case WM_RBUTTONDOWN://右键按下
                    if (msg.x > button2_x && msg.x < button2_x + button_w && msg.y > button2_y &&
                        msg.y < button1_y + button_h) {
                        cleardevice();//每次显示左右键按下后清屏
                        Give(100);
                    }break;
            }
        }

        if (MouseHit())//按钮3
        {
            // 判断点击是否在按钮上
            switch (msg.uMsg)
            {//uMsg判断鼠标信息是什么信息(左键信息或者右键信息)
                case WM_LBUTTONDOWN://左键按下
                    if (msg.x > button3_x && msg.x < button3_x + button_w && msg.y > button3_y &&
                        msg.y < button1_y + button_h) {
                        cleardevice();//每次显示左右键按下后清屏
                        Give(1000);
                    }break;
                case WM_RBUTTONDOWN://右键按下
                    if (msg.x > button3_x && msg.x < button3_x + button_w && msg.y > button3_y &&
                        msg.y < button3_y + button_h) {
                        cleardevice();//每次显示左右键按下后清屏
                        Give(1000);
                    }break;
            }
        }

        if (MouseHit())//按钮4
        {
            int Chutishumu;
            // 判断点击是否在按钮上
            switch (msg.uMsg)
            {//uMsg判断鼠标信息是什么信息(左键信息或者右键信息)
                case WM_LBUTTONDOWN://左键按下
                    if (msg.x > button4_x && msg.x < button4_x + button_w && msg.y > button4_y &&
                        msg.y < button4_y + button_h) {
                        cleardevice();//每次显示左右键按下后清屏
                        outtextxy(100, 40, "想要出几道题目？");
                        scanf("%d",&Chutishumu);
                        Give(Chutishumu);
                    }break;
                case WM_RBUTTONDOWN://右键按下
                    if (msg.x > button4_x && msg.x < button4_x + button_w && msg.y > button4_y &&
                        msg.y < button4_y + button_h) {
                        cleardevice();//每次显示左右键按下后清屏
                        outtextxy(100, 40, "想要出几道题目？");
                        scanf("%d",&Chutishumu);
                        Give(Chutishumu);
                    }break;
            }
        }

        if (MouseHit())//关闭按钮
        {
            // 判断点击是否在按钮上
            switch (msg.uMsg)
            {//uMsg判断鼠标信息是什么信息(左键信息或者右键信息)
                case WM_LBUTTONDOWN://左键按下
                    if (msg.x > button5_x && msg.x < button5_x + button_w && msg.y > button5_y &&
                        msg.y < button5_y + button_h) {
                        // 点击在按钮上，关闭程序
                        HWND abc = GetHWnd();   //获取窗口句柄
                        SetWindowText(abc, "Caculate Test App");   //修改窗口标题
                        MessageBox(abc,  "难道你真的要离开我吗...呜呜...", "Vincent Croft", MB_OKCANCEL);  //设置对话框
                        closegraph();
                    }break;
                case WM_RBUTTONDOWN://右键按下
                    if (msg.x > button5_x && msg.x < button5_x + button_w && msg.y > button5_y &&
                        msg.y < button5_y + button_h) {
                        // 点击在按钮上，关闭程序
                        HWND abc = GetHWnd();   //获取窗口句柄
                        SetWindowText(abc, "Caculate Test App");   //修改窗口标题
                        MessageBox(abc,  "难道你真的要离开我吗...呜呜...", "Vincent Croft", MB_OKCANCEL);  //设置对话框
                        closegraph();
                    }break;
            }
        }
        // 等待一段时间
        Sleep(10);

    }

}

int main()
{

    mciSendString("open ./Karon.wav",NULL,0,NULL);  //打开音乐
    mciSendString("play ./Karon.wav",NULL,0,NULL);  //播放音乐
    mciSendString("stop ./Karon.wav",NULL,0,NULL);  //停止播放
    mciSendString("play ./Karon.wav repeat",NULL,0,NULL); //加上repeat后循环播放
//通过关键字alias 用BGM代替前面的文件路径
    mciSendString("open ./Karon.wav alias BGM",NULL,0,NULL);
    graph();
    system("pause");//暂停，为了显示
    return 0;
}




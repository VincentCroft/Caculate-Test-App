/*����Ϊ��Ŀ˵��
 ������ƣ�Caculate-Test-App
 ������û���Сѧ��
 ��Ҫ���ܣ�ѵ������
 �÷�˵�������Ų˵���ʾ��������
 ��ƴ��µ㣺����ѡ���Ƿ������Զ����湦�ܣ�����ѡ����Ᵽ��·���������Ѷȵ����������Զ�������������н�����������������
           �ܹ��Դ�������д������й��࣬����ͳ�ƿ�����ʱ����ȷ��
 ����������Jetbrains Clion2022.2(����MinGW���������汾w64 9.0 ����CMake �汾3.23.2)
          EasyX For Mingw 2022����ļ�
 ����EasyX��
    easyx4mingw_20220606.zip
	�� include <folder>
	��	�� easyx.h 				// ͷ�ļ�(�ṩ�˵�ǰ���°汾�Ľӿ�)
	��	�� graphics.h			// ͷ�ļ�(�� easyx.h �Ļ����ϣ����������ɾɽӿ�)
	�� lib32 <folder>
	��	�� libeasyx.a			// ��� TDM-GCC 4.8.1 �����ϰ汾�� 32 λ���ļ�
	�� lib64 <folder>
	��	�� libeasyx.a			// ��� TDM-GCC 4.8.1 �����ϰ汾�� 64 λ���ļ�
	�� lib-for-devcpp_5.4.0
		�� libeasyx.a			// ������ DevCpp 5.4.0 GCC MinGW 4.7.2 �� C-Free 5.0
 */

/*�˰汾Ϊ��GUI�棨��ʱ��
 GUI��Դ��ͳɹ�չʾ�ɷ���https://github.com/VincentCroft/Caculate-Test-App��ȡ������Ϣ(���Ķ�README.md)
 �����Ի�ȡ���Ѿ������õĳ���
 */

//
// Created by VincentCroft on 2022/12/24.
//
#include <graphics.h>//ͼ�ν���
#include <stdio.h>
#include <stdlib.h> //��������õ�rand()����
#include <time.h> //�������ӣ�ͳ��ʱ���õ�clock()����
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <string.h>

//ȫ�ֱ���
int a, b; //a,b�ֱ�������������
int c;//�����˲���������������ڵļ�����
int answer; //�û�����Ĵ�
int value;//�������ȷ��
int right = 0; //��ϲ�����ˣ�����Ŀ����
int number; //�Զ���������
int op,set; //�˵�ѡ��
int count=0;//����ͳ��WrongAnswerSheet
double begintime, endtime;//����ͳ������ʱ��
char str[2];//����ƴ���������
char Title[40];//���ڱ�����Ŀ
char SavePlace[100];// ���ڱ���·��
char sheetcount[40];

void graph()//�ṩͼ�ν���
{
    char Menu1[]={"===========�˵�=========="};
    char Menu2[]={"=    ����1. ��10����    ="};
    char Menu3[]={"=    ����2. ��100����   ="};
    char Menu4[]={"=    ����3. ��1000����  ="};
    char Menu5[]={"= ����4. �Զ��������Ŀ ="};
    char Menu6[]={"=    ����0. �˳�����    ="};
    char Menu7[]={"=========================="};
    short win_width,win_height;//���崰�ڵĿ�Ⱥ͸߶�
    win_width = 400;win_height = 400;//�������ڴ�С
    initgraph(win_width,win_height);//��ʼ�����ڣ�������
    LOGFONT f;//������ʽָ��
    gettextstyle(&f);					//��ȡ������ʽ
    _tcscpy(f.lfFaceName,_T("����"));	//��������Ϊ����
    f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����
    settextstyle(&f);                     // ����������ʽ
    settextcolor(WHITE);				//BLACK��graphic.hͷ�ļ����汻����Ϊ��ɫ����ɫ����
    outtextxy(100, 40, Menu1);
    outtextxy(100, 60, Menu2);
    outtextxy(100, 80, Menu3);
    outtextxy(100, 100, Menu4);
    outtextxy(100, 120, Menu5);
    outtextxy(100, 140, Menu6);
    outtextxy(100, 160, Menu7);

    setfillcolor(BLACK); // ���������ɫΪ��ɫ

    // ���������ť��λ�úʹ�С
    int button_w = 50, button_h = 20, button_spacing = 10;
    int button1_x = 50, button1_y = 250;
    int button2_x = button1_x + button_w + button_spacing, button2_y = button1_y;
    int button3_x = button2_x + button_w + button_spacing, button3_y = button1_y;
    int button4_x = button3_x + button_w + button_spacing, button4_y = button1_y;
    int button5_x = button4_x + button_w + button_spacing, button5_y = button1_y;

    // ���������ť
    fillrectangle(button1_x, button1_y, button1_x + button_w, button1_y + button_h); // ���ƾ���
    fillrectangle(button2_x, button2_y, button2_x + button_w, button2_y + button_h);
    fillrectangle(button3_x, button3_y, button3_x + button_w, button3_y + button_h);
    fillrectangle(button4_x, button4_y, button4_x + button_w, button4_y + button_h);
    fillrectangle(button5_x, button5_y, button5_x + button_w, button5_y + button_h);

    // �ڰ�ť��д���ı�
    settextcolor(WHITE); // �����ı���ɫΪ��ɫ
    settextstyle(12, 0, _T("΢���ź�")); // �����ı���ʽ
    outtextxy(button1_x + 15, button1_y + 5, _T("��ť1"));
    outtextxy(button2_x + 15, button2_y + 5, _T("��ť2"));
    outtextxy(button3_x + 15, button3_y + 5, _T("��ť3"));
    outtextxy(button4_x + 15, button4_y + 5, _T("��ť4"));
    outtextxy(button5_x + 15, button5_y + 5, _T("�رճ���"));
    while (true)
    {
        // ��ȡ�����λ��
        MOUSEMSG msg = GetMouseMsg();//���������Ϣ
        //printf("����Ϊ��%d,%d��", msg.x, msg.y);//��ʾ�������

        if (MouseHit())
        {
            // �жϵ���Ƿ��ڰ�ť��
            switch (msg.uMsg)
            {//uMsg�ж������Ϣ��ʲô��Ϣ(�����Ϣ�����Ҽ���Ϣ)
                case WM_LBUTTONDOWN:
                    if (msg.x > button5_x && msg.x < button5_x + button_w && msg.y > button5_y &&
                        msg.y < button5_y + button_h) {
                        // ����ڰ�ť�ϣ��رճ���
                        cleardevice();//ˢ��һ�£���ֹ������ɫ����
                        closegraph();
                    }break;
                case WM_RBUTTONDOWN://�Ҽ�����
                    if (msg.x > button5_x && msg.x < button5_x + button_w && msg.y > button5_y &&
                        msg.y < button5_y + button_h) {
                        // ����ڰ�ť�ϣ��رճ���
                        cleardevice();//ˢ��һ�£���ֹ������ɫ����
                        closegraph();
                    }break;
            }
        }
        // �ȴ�һ��ʱ��
        Sleep(1);
    }

    system("pause");//��ͣ��Ϊ����ʾ
    closegraph();
}

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
    //  �ر���fp��ˢ�����еĻ�������
    fclose(fp);
}

void FileToSave()
{
    FILE *fp,*fp1;
    char name[100];
    SheetCount();
    printf("��������Ҫ��������·�������磺E:\\test.txt��)��");
    scanf("%s",name);
    strcpy(SavePlace,name);
    fp = fopen(name,"r");
    if(fp!= NULL)          // �ж�Ҫ�������ļ��Ƿ����
    {
        printf("(�ļ�����,�Ѿ��������)\n");
    }
    else
    {
        //   ����ļ��������򴴽��ļ�
        printf("(�ļ������ڣ��������ļ�����ʼ��)\n");
        fp1 = fopen(name,"w");
        //   �����ļ�,"w"���ļ���д
        //  w:����һ������д��Ŀ��ļ�������ļ��������Ѵ��ڵ��ļ���ͬ�����ɾ�������ļ������ݣ��ļ�����Ϊһ���µĿ��ļ���
        if(fp1==NULL)
        {
            //  �ļ�û�д������һ�������Դ�����Ϣ�������׼���� stderr    void perror(const char *str)
            perror("Error: ");
        }
    }
    fp=fopen(name,"a+");
    fputs(sheetcount, fp);
    fprintf(fp, "\r\n");
    //  �ر���fp��ˢ�����еĻ�������
    fclose(fp);
}

void NemuPrint()
{
    // ��ӡ�˵�
    printf("==========�˵�==========\n");
    printf("����1. ��10����           =\n");
    printf("����2. ��100����          =\n");
    printf("����3. ��1000����         =\n");
    printf("����4. �Զ��������Ŀ      =\n");
    printf("����0. �˳�����           =\n");
    printf("=======================\n");
}

void SetPrint()
{
    // ��ӡ�Ѷȵ�
    printf("=========�Ѷ�ѡ��========\n");
    printf("����1. ��10���ڵ���Ŀ      =\n");
    printf("����2. ��100���ڵ���Ŀ     =\n");
    printf("����3. ��1000���ڵ���Ŀ    =\n");
    printf("=======================\n");
}

void Feedback()
{
    double n,m,x;
    n=number;
    m=right;
    x=(m/n)*100;
    printf("=======================\n");
    printf("���β���һ����%d�⣬������%d��\n",number,right);
    printf("�����ȷ��Ϊ%lf%%,���ܹ���ʱ%lf��\n",x,(endtime-begintime)/1000);
    if(x<50)            //���ж�����ʵ�ֶ�����������з���
    {
        if(x<25)
        {
            printf("(Tips:С���ѣ���������ȥҪ����ʦ��ȥ�Ȳ���)\n");
        }
        else
            printf("(Tips:С���ѣ���Ҫ���Ͱ�)\n");
    }
    else
    {
        if(x>75)
        {
            printf("(Tips:С���ѣ���ʵ����̫����)\n");
        }
        else
            printf("(Tips:С���ѣ��㻹����)\n");
    }
    printf("=======================\n");
}

// �ӷ���Ŀ
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
        printf("��ϲ�����ˣ�\n");
        right++;
    }
    else
    {
        printf("���ź������ˣ�\n");
        WrongSave(Title);
    }
}

// ������Ŀ
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
        printf("��ϲ�����ˣ�\n");
        right++;
    }
    else
    {
        printf("���ź������ˣ�\n");
        WrongSave(Title);
    }
}

//�˷���Ŀ
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
        printf("��ϲ�����ˣ�\n");
        right++;
    }
    else
    {
        printf("���ź������ˣ�\n");
        WrongSave(Title);
    }
}

//������Ŀ
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
        printf("��ϲ�����ˣ�\n");
        right++;
    }
    else
    {
        printf("���ź������ˣ�\n");
        WrongSave(Title);
    }
}

//����ģ�number�ǳ���ĸ���
void Give(int number)
{
    printf("���γ���������%d��\n", number);
    begintime = clock();    //��ʱ��ʼ
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
    endtime = clock();    //��ʱ����
}

void result()// ������
{
    while (1)
    {
        graph();
        printf("�����빦�����ڵ���ţ�");
        scanf("%d", &op);
        if(op == 0)
        {
            printf("��лʹ��");
            break;
        }
        SetPrint();
        printf("�����빦�����ڵ���ţ�");
        scanf("%d", &set);
        switch (set)//�Ѷȵ���
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
        printf("�Ƿ����ô��Ᵽ�湦�ܣ�(y/n):");
        char Justice;
        scanf("%s",&Justice);
        if(Justice=='y')
        {
            printf("=======���湦������========\n");
            FileToSave();
        }
        if(op == 0)
        {
            printf("��лʹ��");
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
                    printf("��������Ҫ����ĸ�����");
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
    return 0;
}

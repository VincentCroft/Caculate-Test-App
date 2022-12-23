/*����Ϊ��Ŀ˵��
 ������ƣ�Caculate-Test-App
 ������û���Сѧ��
 ��Ҫ���ܣ�ѵ������
 �÷�˵����
 ��ƴ��µ㣺
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

/*
 Դ��ͳɹ�չʾ�ɷ���https://github.com/VincentCroft/Caculate-Test-App��ȡ������Ϣ(���Ķ�README.md)
 �����Ի�ȡ���Ѿ������õĳ���
 */

//
// Created by VincentCroft on 2022/12/24.
//
#include <stdio.h>
#include <stdlib.h> //��������õ�rand()����
#include <time.h> //�������ӣ�ͳ��ʱ���õ�clock()����
#include <windows.h>
#define c 1000//�����˲���������������ڵļ�����

//ȫ�ֱ���
int a, b; //a,b�ֱ�������������
int answer; //�û�����Ĵ�
int right = 0; //��ϲ�����ˣ�����Ŀ����
int number; //�Զ���������
int op; //�˵�ѡ��
double begintime, endtime;//����ͳ������ʱ��

void NemuPrint()
{
    // ��ӡ�˵�
    printf("==========�˵�==========\n");
    printf("����1. ��10����           =\n");
    printf("����2. ��20����           =\n");
    printf("����3. ��100����          =\n");
    printf("����4. �Զ��������Ŀ      =\n");
    printf("����0. �˳�����           =\n");
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
    if (a + b == answer)
    {
        printf("��ϲ�����ˣ�\n");
        right++;
    } else {
        printf("���ź������ˣ�\n");
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
    if (a - b == answer)
    {
        printf("��ϲ�����ˣ�\n");
        right++;
    } else {
        printf("���ź������ˣ�\n");
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
    if (a * b == answer)
    {
        printf("��ϲ�����ˣ�\n");
        right++;
    } else {
        printf("���ź������ˣ�\n");
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
    if (a / b == answer)
    {
        printf("��ϲ�����ˣ�\n");
        right++;
    }
    else
    {
        printf("���ź������ˣ�\n");
    }
}

//����ģ�number�ǳ���ĸ���
void Give(int number)
{
    printf("���γ���������%d�⣬�밴�س�����ʼ\n", number);
    getchar();
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

void function()// ������
{
    while (1)
    {
        NemuPrint();
        printf("�����빦�����ڵ����\n");
        scanf("%d", &op);
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
                    number = 20;
                    Give(number);
                    break;
                case 3:
                    number = 100;
                    Give(number);
                    break;
                case 4:
                    printf("��������Ҫ����ĸ�����\n");
                    scanf("%d", &number);
                    Give(number);
                    break;
            }
            printf("���β���һ����%d�⣬������%d�⣬���ܹ���ʱ%lf��\n",number,right,(endtime-begintime)/1000);
            printf("�Ƿ����²���?��0�˳�\n");
            scanf("%d", &op);
            if(op==0)
            {
                printf("��л����ʹ��");
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

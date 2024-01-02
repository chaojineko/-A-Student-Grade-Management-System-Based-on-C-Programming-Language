/*1、学生成绩管理系统
（1）问题描述：要求以学生成绩管理业务为背景，设计一个“学生成绩管理系统”程序。
	对于学校来讲，学生成绩管理系统是不可缺少的组成部分，主要是对学生资料的录入、浏览、插入和删除等基本功能的实现。

（2）设计要求：编制一个学生成绩管理程序。设学生成绩以一个学生一条记录的形式存储，每个学生记录包含的信息有学号和各门功课的成绩。
	设每位学生学习高等数学、大学英语、数据结构与算法、计算机组成原理、概率论与数理统计和大学物理6门课程。

（3）数据结构：使用单链表作为实现该问题的数据结构。

（4）实现操作：程序设计一般由算法和数据结构两部分构成。管理学生的成绩适合用单链表，方便随时插入和删除学生记录，实现动态管理。
	一个学生作为一个结点，该结点类型为结构体，结构体中的域表示学生的属性。每个结点除了存放属性外，还存放指向后继结点的指针。

①定义单链表结点的结构体；      ②单链表的建立模块；
③插入模块；  ④删除模块；  ⑤输出模块；  ⑥主模块
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>

//菜单
void Menu() {
	printf("*************************************************\n");
	printf("*\t\t大学生成绩管理系统\t\t*\n");
	printf("*\t\t请选择功能\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.录入学生信息\t\t\t*\n");
	printf("*\t\t2.打印学生信息\t\t\t*\n");	
	printf("*\t\t3.统计所有学生人数\t\t*\n");
	printf("*\t\t4.查找学生信息\t\t\t*\n");
	printf("*\t\t5.修改学生信息\t\t\t*\n");
	printf("*\t\t6.删除学生信息\t\t\t*\n");
	printf("*\t\t0.退出系统\t\t\t*\n");
	printf("*************************************************\n");
}
//定义一个学生
typedef struct tagStudent {
	char szName[20];	//姓名
	char szSex[4];		//性别
	int  nAge;			//年龄
	long long nStuNo;		//学号
	int  nScore;		//成绩
	int hmath;			//高数	
	int clgen;			//大学英语
	int dsaa;			//数据结构
	int cs;				//计算机
	int prothy;			//概率论
	int clpy;			//大学物理
}Student;

//链表节点
typedef struct tagNode
{
	Student stu;			//学生信息
	struct tagNode* pNext;	//指向下一个节点
}Node;

//创建头节点
Node* g_pHead = NULL;		//指向头节点
//1.录入学生信息
void InputStudent() {
	//创建一个人，在堆中分配内存
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	//指针下一个指向空
	pNewNode->pNext = NULL;

	//查找链表的尾结点
	Node* p = g_pHead;
	while (g_pHead != NULL && p->pNext != NULL)
	{
		p = p->pNext;
	}

	//把节点插到链表的尾节点
	if (g_pHead == NULL) {
		g_pHead = pNewNode;
	}
	else {
		p->pNext = pNewNode;
	}

	//录入学生信息
	printf("请输入学生姓名：\n");
	scanf_s("%s", pNewNode->stu.szName, sizeof(pNewNode->stu.szName));
	printf("请输入性别：\n");
	scanf_s("%s", pNewNode->stu.szSex, sizeof(pNewNode->stu.szSex));
	printf("请输入学生年龄：\n");
	scanf_s("%d", &pNewNode->stu.nAge);
	printf("请输入学号：\n");
	scanf_s("%lld", &pNewNode->stu.nStuNo);// 用长整型格式说明符%lld打印学号
	printf("请输入成绩：\n");
	scanf_s("%d", &pNewNode->stu.nScore);
	printf("请输入高数成绩：\n");
	scanf_s("%d", &pNewNode->stu.hmath);
	printf("请输入大学英语成绩：\n");
	scanf_s("%d", &pNewNode->stu.clgen);
	printf("请输入数据结构成绩：\n");
	scanf_s("%d", &pNewNode->stu.dsaa);
	printf("请输入计算机成绩：\n");
	scanf_s("%d", &pNewNode->stu.cs);
	printf("请输入概率论成绩：\n");
	scanf_s("%d", &pNewNode->stu.prothy);
	printf("请输入大学物理成绩：\n");
	scanf_s("%d", &pNewNode->stu.clpy);

	printf("学生信息录入成功。\n\n");
	system("pause");
	system("cls");
}

//2.打印学生信息
void PrintStudent() {

	system("cls");
	//遍历链表
	Node* p = g_pHead;
	if (p == NULL) {
		printf("系统中暂无学生信息，请录入后再来打印查看。\n\n");
	}
	else {
		printf("*********************************************************************************\n");
		printf("*\t\t大学生成绩管理系统\t\t*\n");
		printf("*********************************************************************************\n");
		printf("*\t学号\t*\t姓名\t*\t性别\t*\t年龄\t*\t成绩\t*\t高数成绩\t*\t大学英语成绩\t*\t数据结构成绩\t*\t计算机成绩\t*\t概率论成绩\t*\t大学物理成绩\t\n");
		printf("*********************************************************************************\n");

		while (p != NULL)
		{
			printf("*\t%lld\t*\t%s\t*\t%s\t*\t%d\t*\t%d\t*%d\t*%d\t*%d\t*%d\t*%d\t*%d\t*\n",
				p->stu.nStuNo,
				p->stu.szName,
				p->stu.szSex,
				p->stu.nAge,
				p->stu.nScore,
				p->stu.hmath,
				p->stu.clgen,
				p->stu.dsaa,
				p->stu.cs,
				p->stu.prothy,
				p->stu.clpy
			);

			//下一个节点
			p = p->pNext;
			printf("*********************************************************************************\n");
		}
	}

	system("pause");
	system("cls");
}

//3.统计所有学生人数
void CountStudent() {
	int countStu = 0;

	//遍历链表
	Node* p = g_pHead;
	while (p != NULL)
	{
		countStu++;
		p = p->pNext;
	}
	printf("学生总人数：%d\n\n", countStu);

	system("pause");
	system("cls");
}

//4.查找学生信息
void FindStudent() {
	system("cls");
	long long stuNum;
	printf("请输入查找学生学号：");
	scanf_s("%lld", &stuNum);
	//遍历链表查找，查找到后进行信息显示
	Node* p = g_pHead;
	//对表头进行展示一次
	bool isShowHead = false;
	//记录是否有找到该学号的学生信息
	bool isFindStu = false;
	while (p != NULL)
	{
		if (stuNum == p->stu.nStuNo) {
			if (!isShowHead) {
				printf("*********************************************************************************\n");
				printf("*\t学号\t*\t姓名\t*\t性别\t*\t年龄\t*\t成绩\t*\t高数成绩\t*\t大学英语成绩\t*\t数据结构成绩\t*\t计算机成绩\t*\t概率论成绩\t*\t大学物理成绩\t\n");
				printf("*********************************************************************************\n");
				isShowHead = true;
			}
			printf("*\t%lld\t*\t%s\t*\t%s\t*\t%d\t*\t%d\t*%d\t*%d\t*%d\t*%d\t*%d\t*%d\t*\n",
				p->stu.nStuNo,
				p->stu.szName,
				p->stu.szSex,
				p->stu.nAge,
				p->stu.nScore,
				p->stu.hmath,
				p->stu.clgen,
				p->stu.dsaa,
				p->stu.cs,
				p->stu.prothy,
				p->stu.clpy
			);
			isFindStu = true;
			printf("*********************************************************************************\n");
		}
		p = p->pNext;
	}

	if (!isFindStu) {
		printf("学号输入有误，系统中暂无该学生信息。\n\n");
	}

	system("pause");
	system("cls");
}

//5.修改学生信息
void ChangeStudent() {
	long long stuNum;
	printf("请输入欲修改学生的学号：");
	scanf_s("%lld", &stuNum);
	//遍历链表查找，查找到后进行信息显示
	Node* p = g_pHead;
	//对表头进行展示一次
	bool isShowHead = false;
	//记录是否有找到该学号的学生信息
	bool isFindStu = false;
	while (p != NULL)
	{
		if (stuNum == p->stu.nStuNo) {
			if (!isShowHead) {
				printf("*********************************************************************************\n");
				printf("*\t学号\t*\t姓名\t*\t性别\t*\t年龄\t*\t成绩\t*\t高数成绩\t*\t大学英语成绩\t*\t数据结构成绩\t*\t计算机成绩\t*\t概率论成绩\t*\t大学物理成绩\t\n");
				printf("*********************************************************************************\n");
				isShowHead = true;
			}
			printf("*\t%lld\t*\t%s\t*\t%s\t*\t%d\t*\t%d\t*%d\t*%d\t*%d\t*%d\t*%d\t*%d\t*\n",
				p->stu.nStuNo,
				p->stu.szName,
				p->stu.szSex,
				p->stu.nAge,
				p->stu.nScore,
				p->stu.hmath,
				p->stu.clgen,
				p->stu.dsaa,
				p->stu.cs,
				p->stu.prothy,
				p->stu.clpy
			);
			//修改学生信息
			printf("请输入学生姓名：\n");
			scanf_s("%s", p->stu.szName, sizeof(p->stu.szName));
			printf("请输入性别：\n");
			scanf_s("%s", p->stu.szSex, sizeof(p->stu.szSex));
			printf("请输入学生年龄：\n");
			scanf_s("%d", &p->stu.nAge);
			printf("请输入学号：\n");
			scanf_s("%lld", &p->stu.nStuNo);
			printf("请输入成绩：\n");
			scanf_s("%d", &p->stu.nScore);
			printf("请输入高数成绩：\n");
			scanf_s("%d", &p->stu.hmath);
			printf("请输入大学英语成绩：\n");
			scanf_s("%d", &p->stu.clgen);
			printf("请输入数据结构成绩：\n");
			scanf_s("%d", &p->stu.dsaa);
			printf("请输入计算机成绩：\n");
			scanf_s("%d", &p->stu.cs);
			printf("请输入概率论成绩：\n");
			scanf_s("%d", &p->stu.prothy);
			printf("请输入大学物理成绩：\n");
			scanf_s("%d", &p->stu.clpy);
			isFindStu = true;
			printf("*********************************************************************************\n");
			printf("学生信息修改成功，请注意及时保存。\n\n");

			
		}
		p = p->pNext;
	}

	if (!isFindStu) {
		printf("学号输入有误，系统中暂无该学生信息，无法进行修改。\n\n");
	}

	system("pause");
	system("cls");
}

//6.删除学生信息
void DeleteStudent() {
	system("cls");
	long long stuNum;
	printf("请输入删除学生的学号：");
	scanf_s("%lld", &stuNum);
	//遍历链表查找，查找到后进行信息显示
	Node* p = g_pHead;
	//记录前一个节点，删除时方便操作
	Node* beforeNode = g_pHead;

	//对表头进行展示一次
	bool isShowHead = false;
	//记录是否有找到该学号的学生信息
	bool isFindStu = false;
	while (p != NULL)
	{
		if (stuNum == p->stu.nStuNo) {
			if (!isShowHead) {
				printf("*********************************************************************************\n");
				printf("*\t学号\t*\t姓名\t*\t性别\t*\t年龄\t*\t成绩\t*\t高数成绩\t*\t大学英语成绩\t*\t数据结构成绩\t*\t计算机成绩\t*\t概率论成绩\t*\t大学物理成绩\t\n");
				printf("*********************************************************************************\n");
				isShowHead = true;
			}
			printf("*\t%lld\t*\t%s\t*\t%s\t*\t%d\t*\t%d\t*%d\t*%d\t*%d\t*%d\t*%d\t*%d\t*\n",
				p->stu.nStuNo,
				p->stu.szName,
				p->stu.szSex,
				p->stu.nAge,
				p->stu.nScore,
				p->stu.hmath,
				p->stu.clgen,
				p->stu.dsaa,
				p->stu.cs,
				p->stu.prothy,
				p->stu.clpy
			);
			isFindStu = true;
			printf("*********************************************************************************\n");

			//删除节点为头节点
			if (p == g_pHead) {
				g_pHead = p->pNext;
			}
			//删除节点为尾节点
			else if (p->pNext == NULL) {
				p = beforeNode;
				p->pNext = NULL;
			}
			//删除节点为中间节点
			else {
				beforeNode->pNext = p->pNext;
			}
			printf("删除成功，请记得保存。\n\n");
		}
		beforeNode = p;
		p = p->pNext;
	}

	if (!isFindStu) {
		printf("学号输入有误，系统中暂无该学生信息，无法进行删除操作。\n\n");
	}

	system("pause");
	system("cls");
}

int main() {
	while (1)
	{
		//打印菜单
		Menu();
		//读取一个字符 整数,字符在内存中映射为ASCII码
		char ch = _getch();

		switch (ch)
		{
		case '1'://1.录入学生信息
			InputStudent();
			break;
		case '2'://2.打印学生信息
			PrintStudent();
			break;
		case '3'://3.统计所有学生人数
			CountStudent();
			break;
		case '4'://4.查找学生信息
			FindStudent();
			break;
		case '5'://5.修改学生信息
			ChangeStudent();
			break;
		case '6'://6.删除学生信息
			DeleteStudent();
			break;
		case '0'://0.退出系统
			return 0;
			break;
		default:
			printf("输入有误，没有该功能\n\n");
			system("pause");  //暂停
			system("cls");    //清屏
			break;
		}
	}

	return 0;
}

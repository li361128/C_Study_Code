#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef struct student
{
    int num;
    char name[10];
    int score;
}ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node,*pList;

pList Init_L()
{
    Node *L;
    L = (Node*)malloc(sizeof(Node));
    return L;
}

void AddStudent(pList L)
{
    ElemType e;
    printf("Please enter student information:\n");
    printf("Student ID\tname\tgrades\n");
    scanf("%d %s %d",&e.num,e.name,&e.score);

    Node *q;
    q = (Node*)malloc(sizeof(Node));
    q->data = e;
    q->next = NULL;
    Node *p = L;
    while(p->next)
    {
        p = p->next;
    }
    p->next = q;
    system("pause");
}

void SearchStudent_ID(pList L,int id)
{
    pList q = L->next;
    while(q && q->data.num != id)
    {
        q = q->next;
    }
    if(!q)
    {
        printf("The student is not found\n");
        return;
    }
    printf("Student ID: %d\tname: %s\tscore: %d\n",q->data.num,q->data.name,q->data.score);
}

void SearchStudent_Name(pList L,char name[])
{
    pList q = L->next;
    while(q &&  strcmp(q->data.name , name) != 0)
    {
        q = q->next;
    }
    if(!q)
    {
        printf("The student is not found\n");
        return;
    }
    printf("Student ID: %d\tname: %s\tscore: %d\n",q->data.num,q->data.name,q->data.score);
}

void SearchStudent(pList L)
{
    int tag = -1;
    while(1)
    {
        printf("if you want to check by looking for student ID,please input 0\n"
               "or you want to check by looking for student name,please input 1\n");
        scanf("%d", &tag);
        if(tag == 0)
        {
            printf("please input the student`s id\n");
            int Id;
            scanf("%d",&Id);
            SearchStudent_ID(L,Id);
            system("pause");
            return ;
        }
        if(tag == 1)
        {
            printf("please input the student`s name\n");
            char name_1[10];
            scanf("%s",name_1);
            SearchStudent_Name(L,name_1);
            system("pause"); 
            return ;
        }
        else
        {
            printf("The student is not found !\n"
                   "If you want to exit, input 0, or you want to input again\n");
            int tag_1 = -1;
            scanf("%d",&tag_1);
            if(tag_1 == 0) return;
        }
    }
}

void DisplayAllStudents(pList L)
{
    pList p = L->next;
    while (p)
    {
        printf("Student ID: %d\tName: %s\tScore: %d\n", p->data.num, p->data.name, p->data.score);
        p = p->next;
    }
    system("pause");
}


void Menu(){
    system("cls");
    printf("------------------------------------------\n");
    printf("      Student Management System     \n");
    printf("                                          \n");
    printf("    1. Add Student Information            \n");
    printf("    2. Search Student Information         \n");
    printf("    3. Display All Information            \n");
    printf("    0. Exit Management System             \n");
    printf("------------------------------------------\n");
    printf("                                          \n");
    printf("    Please input your choice: \n");
}


int main()
{
    Node *L;
    L = Init_L();
    int choice;

    while(1)
    {
        Menu();
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                AddStudent(L);
                break;
            case 2:
                SearchStudent(L);
                break;
            case 3:DisplayAllStudents(L);
                break;
            case 0:
                return 0;
        }
    }
    return OK;
}


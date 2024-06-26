//
/**
  ******************************************************************************
  * @file           : function_declaration.h
  * @author         : lct2023
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/2
  ******************************************************************************
  */
//

#include "function_declaration.h"


int main()
{
    //初始化pFlight，pFlight为全局变量。
    InitFlight();
    //用flight1中的数据创建初始航班链表，里面含有四个节点
    Create(flight1);

   while(1)
   {
   	   fflush(stdin); // 清空标准输入缓冲区
       SetUp();//菜单初始化
       cout << "请输入您的选择（0~7）:" << endl;
       int select;
       scanf("%d", &select);
       fflush(stdin); // 清空标准输入缓冲区
       system("CLS");
       switch (select)
       {
           case 1:
               cout << "1.录入航班信息 "<< endl;
               if(OK == InsertFlight())
                   cout <<"录入航班信息成功"<< endl;
               break;
           case 2:
               cout << "2.加载航班数据 "<< endl;
               PrintFilghtlist(pFlight);
               break;
           case 3:
               cout << "3.清除航班记录 "<< endl;
               if (OK == DeleteFlight()) 
			   {
                   printf("删除成功\n");
               } 
			   else 
			   {
                   printf("没有这个航班，删除失败！\n");
               }
               break;
           case 4:
               cout << "4.查询航班 "<< endl;
               SearchFlight();
               break;
           case 5:
               cout << "5.购票&退票 "<< endl;
               int choice5;
               printf("请输入您的选择，1表示购票，其他表示退票\n");
			   scanf("%d",&choice5);
			   
			   if(choice5 == 1)	BookTickets();
			   else 	ReturnTicket();
               
               break;
           case 6:
               cout << "6.查询旅客信息 "<< endl;
               Visit_Passenger_Information(pFlight);
               break;
           case 7:
                cout << "7.保存航班信息 "<< endl;
                if(OK ==  Log_Flight_Information(pFlight))
                {
                    cout << "保存航班信息成功！" << endl;
                }
                else
                {
                   cout << "保存航班信息失败！"<< endl;
                }
                break;
           case 0:
               GoodbyeFace();
               exit(0);
           default:
               cout << "输入错误，请重新输入！"<< endl;
               break;
       }
       system("PAUSE");
       system("CLS");
   }
    return 0;
}

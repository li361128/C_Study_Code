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
#include "function.cpp"

/**
  *  @function   SetUp
  *  @brief      菜单初始化
*/
void SetUp();


/**
 * 查询模块 打印info航班的基本信息
 * @param info
 */
void Display(Flight *info);


 /**
   *  @function   InitFlight
   *  @brief      初始化移pFlight为头结点的空航班链表,录入航班信息和增加航班后将航班结点插入该链表
 */
void InitFlight();


/**
 * @brief 初始化已订票乘客指针链表
 * @param cusLinkList 航班中乘员链表的头指针
 * @return 函数执行状态
 */
Status InitCusLinkList(CusLinkList &cusLinkList);


/**
 * @brief 初始化带头结点的链队列
 * @param q 链队的头结点
 */
Status InitQueue(LinkQueue &q);


/**
 * @brief 将flight1的6个航班用头插入法插入到pFlight的链表中
 * @param flight1 里面存有六个基本航班
 * @return 返回操作是否成功
 */
Status Create(PFlight flight1);


/**
 * @brief 增加航班时输入日期的辅助函数（1代表星期一，7代表星期日）
 * @param day1 传进来的1-7中的一个
 * @param day 数组类变量，可以返回回去给航班的日期变量
 * @return 返回操作状态，输入是否合法
 */
Status IputDay(int day1, char day[]);


/**
 * @brief 插入航班时遍历航班，防止航班ID重复（航班ID相当于主键）
 * @param flight 航班的头结点
 * @param flightCodeID  需要进行遍历查找航班号
 * @return  返回是否重复
 */
Status TraverseFlight(Flight *flight, char flightCodeID[]);


/**
  * @brief 将新的航班结点插入到航班链表中，
  * @return 返回操作是否成功
  */
Status InsertFlight();


/**
 * @brief 查询模块, 打印全部航班信息
 * @param pflight 传入的是航班链表的头指针
 */
void PrintFilghtlist(Flight *pflight);


/**
  * @brief 删除节点
  * @return 返回操作是否成功
  */
Status DeleteFlight();


/**
 *@brief 根据客户提出的起点，终点站名输出航线信息
 */
void SearchFlight();


/**
 * @brief 入队，增加排队等候的客户名单域
 * @param q 带头结点的链队列
 * @param name  等候客户的名字
 * @param amount    等候客户所需机票的数量
 * @param identification    等候客户的身份证号
 * @return  返回成功入队后的等候客户链的头结点
 */
LinkQueue Appendqueue(LinkQueue &q, char name[], int amount, char identification[]);


/**
 * @brief 根据自己输入的航班ID查询并以指针形式返回
 * @return  航班指针
 */
Flight *find();


/**
 * 订票成功之后，将乘客信息插入到对应航班的订成员名单域中（链表）
 * @param head 乘客名单域头指针
 * @param amount 该乘客订票的数量
 * @param name 乘客的姓名
 * @param rank 订票的等级
 * @return  乘客链表头指针
 */
CusLinkList insertlink(CusLinkList &head, int amount, char name[], char identification[], int rank);


/**
 * @brief 输出p节点的航班信息
 * @param p 航班节点
 */
void FlightInfo(Flight *p);


/**
 * @brief 查找是否有同一路线的航班
 * @param destination   目的地
 * @param pflight 原航班，用来判断和新搜到的航班是否一样
 * @return 找不到就返回FALSE，否则返回TRUE
 */
Status RecommendFlight(char startPoint[], char destination[], Flight *pflight);


/**
 * @brief 订票模块
 */
void BookTickets();


/**
 * @param Q   Q为候补订票客户的队列
 * @param NameAndNumAndIDAndID 候补客户的姓名和订票数目，出队时，将姓名和关键字和身份证返回
 * @return
 */
Status QueueDelete(LinkQueue &q, NameAndNumAndID &NameAndNumAndID);


/**
 * @brief 退票功能模块
 */
void ReturnTicket();


/**
  *  @function   Log_Flight_Information
  *  @brief      将航班信息存进文件"航班信息记录日志.txt"
  *  @param      pflight 航班头指针
  *  @return     函数执行状态
*/
Status Log_Flight_Information(Flight *pflight);

/**
  *  @function   Visit_Passenger_Information
  *  @brief      访问旅客信息
  *  @param      pflight 航班头指针
  *  @return     函数执行状态
*/
Status Visit_Passenger_Information(Flight *pflight);


/**
 * @brief 退出程序模块界面
 */
void GoodbyeFace();


#ifndef DATA_STRUCTURE_PRACTICE_FUNCTION_DECLARATION_H
#define DATA_STRUCTURE_PRACTICE_FUNCTION_DECLARATION_H

#endif //DATA_STRUCTURE_PRACTICE_FUNCTION_DECLARATION_H

//
/**
  * @file           : function.cpp
  * @author         : lct2023
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/2
  */
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <malloc.h>
#include <fstream>
#include <ctime>
#include <iomanip>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define FALSE -1
#define TRUE 1

using namespace std;

typedef int Status;

//航班日期枚举类，星期一到星期天
enum Week{
    Mon = 1, Tues = 2, Wed = 3, Thurs = 4, Fri = 5, Sat = 6, Sun = 7
};

//乘客节点
typedef struct CustomerNode
{
    char name[10];//客户姓名
    int clientTickets;//客户订票量
    char identification[20];//客户身份证号码
    int rank;//舱位等级
    CustomerNode *next;
} CustomerNode, *CusLinkList;

//候补队列中的节点
typedef struct WaitPassenger
{
    char name[10];//姓名
    char identification[20]; //身份证
    int preTickets;//预定的票量
    struct WaitPassenger *next;
} WaitQNode, *PWait;

//候补队列
typedef struct Queue
{
    PWait front;//等候替补客户名单域的头指针
    PWait rear;//等候替补客户名单域的尾指针
} LinkQueue;

//封装乘客的姓名和订票量和身份证
//用于候补客户出队时把关键字返回
typedef struct NameAndNumAndID
{
    char name[10];//姓名
    char identification[20]; //身份证号码
    int num;//订票量
} NameAndNumAndID;

//航班节点
typedef struct Flight
{
    char startPoint[20];//起点站名
    char destination[20];//终点站名
    char flightCodeID[20];//航班ID（相当于主键）
    char planeNum[20];//飞机号
    char day[20];//飞行日期（星期几）
    int totalTickets;//乘员定额(总票数)
    int left;//总余票量
    int leftEconomicTicket; //经济票剩余量
    int leftBusinessTicket; //商务票剩余量
    Flight *next;
    CusLinkList cusLinkList;//乘员名单域，指向乘员名单链表的头指针
    LinkQueue waitQueue1;//经济舱候补，等候替补的客户名单域，指向一个队列
    LinkQueue waitQueue2;//商务舱候补，等候替补的客户名单域，指向一个队列

} Flight, FlightNode, *PFlight;

//定义全局指针变量pFlight，航班链表的头指针
Flight *pFlight;

//五个基本航班
Flight flight1[5] = {
        {"北京", "郑州", "A1", "K1250", "星期日", 12, 12, 6},
        {"北京", "包头", "B2", "L6525", "星期三", 12, 12, 6},
        {"北京", "鹤岗", "C3", "K1010", "星期三", 12, 12, 6},
        {"北京", "上饶", "D4", "L6333", "星期二", 12, 12, 6},
        {"北京", "琼海", "E5", "K1210", "星期五", 12, 12, 6},
//        {"包头", "北京", "F6", "K9857", "星期六", 12, 12, 6}
};

// 冒泡排序函数，按照航班ID从小到大排序
void bubbleSort_PFlight(PFlight *head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; // 如果链表为空或者只有一个节点，不需要排序
    }

    Flight *end = NULL; // 用于标记已经排好序的部分

    while (end != *head) { // 外层循环控制排序的轮数
        Flight **prev = head; // 前一个节点的指针的指针
        Flight *current = *head; // 当前节点指针
        Flight *nextNode = current->next; // 下一个节点指针

        while (current->next != end) { // 内层循环进行一次完整的冒泡过程
            nextNode = current->next;
            if (strcmp(current->flightCodeID, nextNode->flightCodeID) > 0) { // 比较当前节点和下一个节点的航班ID
                // 交换节点的位置
                *prev = nextNode;
                current->next = nextNode->next;
                nextNode->next = current;

                // 交换指针
                Flight *temp = current;
                current = nextNode;
                nextNode = temp;
            }

            // 更新指针，继续下一次比较
            prev = &current->next;
            current = nextNode;
        }

        // 更新已排好序的部分
        end = current;
    }
}


/**
  *  @function   InitFlight
  *  @brief      初始化移pFlight为头结点的空航班链表,录入航班信息和增加航班后将航班结点插入该链表
*/
void InitFlight()
{
    pFlight = (Flight *) malloc(sizeof(Flight));//申请头结点的空间
    if (pFlight == NULL) exit(0);
    pFlight->next = NULL;//将头结点h的指针域置为空
}

/**
 * @brief 初始化已订票乘客指针链表
 * @param cusLinkList 航班中乘员链表的头指针
 * @return 函数执行状态
 */
Status InitCusLinkList(CusLinkList &cusLinkList)
{
    CusLinkList q = cusLinkList;
    cusLinkList = (CustomerNode *) malloc(sizeof(CustomerNode));
    cusLinkList->next = NULL;
}

/**
 * @brief 初始化带头结点的链队列
 * @param q 链队的头结点
 */
Status InitQueue(LinkQueue &q)
{
    WaitQNode *p;
    p = (WaitQNode *) malloc(sizeof(WaitQNode));
    if (p == NULL) {
        printf("内存不足\n");
        return ERROR;
    }

    p->next = NULL;
    q.front = q.rear = p;
    return OK;

}

/**
 * @brief 将flight1的6个航班用头插入法插入到pFlight的链表中
 * @param flight1 里面存有六个基本航班
 * @return 返回操作是否成功
 */
Status Create(PFlight flight1)
{
    Flight *p = pFlight, *q;
    for (int i = 0; i < 5; i++) {
        q = (Flight *) malloc(sizeof(Flight));
        if (q == NULL)
            return ERROR;
        strcpy(q->startPoint, flight1[i].startPoint);
        strcpy(q->destination, flight1[i].destination);
        strcpy(q->flightCodeID, flight1[i].flightCodeID);
        strcpy(q->planeNum, flight1[i].planeNum);
        strcpy(q->day, flight1[i].day);
        q->totalTickets = flight1[i].totalTickets;
        q->left = flight1[i].totalTickets;
        q->leftEconomicTicket = flight1[i].leftEconomicTicket;
        q->leftBusinessTicket = flight1[i].totalTickets - flight1[i].leftEconomicTicket;
        //初始化乘客链表
        InitCusLinkList(q->cusLinkList);

        InitQueue(q->waitQueue1);
        InitQueue(q->waitQueue2);

        q->next = p->next;
        p->next = q;

    }
    return OK;

}

/**
 * @brief 增加航班时输入日期的辅助函数（1代表星期一，7代表星期日）
 * @param day1 传进来的1-7中的一个
 * @param day 数组类变量，可以返回回去给航班的日期变量
 * @return 返回操作状态，输入是否合法
 */
Status IputDay(int day1, char *day)
{
    switch (day1) {
        case Mon:
            strcpy(day, "星期一");
            break;
        case Tues:
            strcpy(day, "星期二");
            break;
        case Wed:
            strcpy(day, "星期三");
            break;
        case Thurs:
            strcpy(day, "星期四");
            break;
        case Fri:
            strcpy(day, "星期五");
            break;
        case Sat:
            strcpy(day, "星期六");
            break;
        case Sun:
            strcpy(day, "星期日");
            break;
        default:
            return ERROR;
    }
    return OK;
}


/**
 * @brief 插入航班时遍历航班，防止航班ID重复（航班ID相当于主键）
 * @param flight 航班的头结点
 * @param flightCodeID  需要进行遍历查找航班号
 * @return  返回是否重复
 */
Status TraverseFlight(Flight *flight, char *flightCodeID)
{
    Flight *p = flight;
    while (p != NULL)
    {
        //当有航班ID重复时候，返回ERROR，
        if (!strcmp(flightCodeID, p->flightCodeID))
        {
            return ERROR;
        }

        p = p->next;
    }
    //输入的航班ID不重复
    return OK;

}


/**
  * @brief 将新的航班结点插入到航班链表中，
  * @return 返回操作是否成功
  */
Status InsertFlight()
{
    FlightNode *q;//定义q为新增加的航班结点的指针的形参
    Flight *p = pFlight;
    int mark = 1;

    while (mark != 0) {
        q = (FlightNode *) malloc(sizeof(FlightNode));
        if (q == NULL)
            return ERROR;

        printf("\t\t请依次输入以下内容\n");
        printf("\t\t请输入航班ID\n");
        scanf("%s", q->flightCodeID);
        Status status = TraverseFlight(pFlight, q->flightCodeID);
        if (status == ERROR) {
            printf("该航班ID已经存在，请重新输入航班ID\n");
            continue;
        }
        printf("\t\t请输入起点站名\n");
        scanf("%s", q->startPoint);
        printf("\t\t请输入终点站名\n");
        scanf("%s", q->destination);
        printf("\t\t请输入飞机号\n");
        scanf("%s", q->planeNum);
        printf("\t\t请输入飞行日期(1代表星期一,2代表星期二.....7代表星期日)\n");
        int day1;
        scanf("%d", &day1);
        while (ERROR == IputDay(day1, q->day)) {
            printf("请输入合法数据(1-7)\n");
            scanf("%d", &day1);
        };

        printf("\t\t请输入乘客定额\n");
        scanf("%d", &q->totalTickets);
        q->left = q->totalTickets;

        printf("\t\t请输入经济票数目（同时也决定了商务票的数目）\n");
        scanf("%d", &q->leftEconomicTicket);
        //商务票数目 = 总票数目 - 经济票数目
        q->leftBusinessTicket = q->totalTickets - q->leftEconomicTicket;
        InitCusLinkList(q->cusLinkList);
        //初始化
        InitQueue(q->waitQueue1);
        InitQueue(q->waitQueue2);

        q->next = p->next;
        p->next = q;

        printf("\t\t是否继续录入航班信息（任意数字继续，0表示停止）。\n");
        printf("\t\t请输入：");
        scanf("%d", &mark);
    }
    return OK;
}

/**
  *  @function   SetUp
  *  @brief      菜单初始化
*/
void SetUp()
{
	cout << endl << endl;
	std::cout << "          ##       /        ## ###### /       ####    ####      /         /      ######" << std::endl;  
    std::cout << "           ##     ///      ##  #      /       #       #  #     / /       / /     #     " << std::endl;  
    std::cout << "            ##   /// //   ##   #####  /       #       #  #    /   /     /   /    ##### " << std::endl;  
    std::cout << "             ## //   //  ##    #      /       #       #  #   /     /   /     /   #     " << std::endl;  
    std::cout << "              ///      ///     #      /       #       #  #  /       ///       /  #     " << std::endl;  
    std::cout << "               /        /      ###### ######  ####    #### /         /         / ######" << std::endl;  
  
    cout << endl << endl << endl;
    cout << "                     ☆☆☆☆☆☆☆☆☆☆☆☆☆ Airplane Servervice System ☆☆☆☆☆☆☆☆☆☆☆☆☆☆" << endl;
    cout << endl;
    cout << "                              ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
    cout << "                              ┃      欢迎使用航空客运订票系统      ┃\n";
    cout << "                              ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n";
    cout << "                              ┃ 1.录入航班信息    5.购票&退票      ┃\n";
    cout << "                              ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n";
    cout << "                              ┃ 2.加载航班数据    6.查询旅客信息   ┃\n";
    cout << "                              ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n";
    cout << "                              ┃ 3.清除航班记录    7.保存航班信息   ┃\n";
    cout << "                              ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n";
    cout << "                              ┃ 4.查询航班信息    0.退出系统       ┃\n";
    cout << "                              ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
}

/**
 * @brief 查询模块 打印info航班的基本信息
 * @param info 单个航班信息 
 */
void Display_flight_Infomation(Flight *info)
{
    //printf("起点站名\t终点站名\t航班ID\t飞机号\t飞行日期\t乘员定额\t余票量\t经济票剩余量\t商务票剩余量\n");
    printf("%8s\t%8s\t%3s\t%s\t%4s\t\t%3d\t%10d\t%10d\t%10d\n", info->startPoint, info->destination, info->flightCodeID,
           info->planeNum, info->day,
           info->totalTickets, info->left, info->leftEconomicTicket, info->leftBusinessTicket);
}


Status Log_Flight_Information(Flight *pflight) {
    fstream ifs;
    // 追加写入，在原来基础上加了ios::app
    ifs.open("航班信息记录日志.txt", ios::out | ios::app);

    if (!ifs.is_open()) {
        cout << "文件打开失败" << endl;
        return ERROR;
    }

    // 获取当前时间
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // 格式化时间信息
    char timeStr[50];
    snprintf(timeStr, sizeof(timeStr), "%04d-%02d-%02d %02d:%02d:%02d",
             1900 + ltm->tm_year,
             1 + ltm->tm_mon,
             ltm->tm_mday,
             ltm->tm_hour,
             ltm->tm_min,
             ltm->tm_sec);

    // 输入你想写入的内容
    ifs << "航班基本信息：" << endl;
    ifs << "保存时间: " << timeStr << endl;
    ifs << left << setw(12) << "起点站" << setw(12) << "终点站" << setw(10) << "航班ID"
        << setw(10) << "飞机号" << setw(10) << "飞行日期" << setw(12) << "乘员定额"
        << setw(8) << "余票量" << setw(12) << "经济票余量" << setw(14) << "商务票余量" << endl;

    Flight *info = pflight->next;

    bubbleSort_PFlight(&info);
    while (info) {
        ifs << left << setw(16) << info->startPoint
            << setw(14) << info->destination
            << setw(12) << info->flightCodeID
            << setw(12) << info->planeNum
            << setw(12) << info->day
            << setw(14) << info->totalTickets
            << setw(16) << info->left
            << setw(18) << info->leftEconomicTicket
            << setw(16) << info->leftBusinessTicket << endl;
        info = info->next;
    }

    ifs.close();
    return OK;
}


/**
 * @brief 查询模块, 打印全部航班信息
 * @param pflight 传入的是航班链表的头指针
 */
void PrintFilghtlist(Flight *pflight)
{
    Flight *p;
    //带头结点的头指针，所以从下一个指针还是遍历

    p = pflight->next;
    system("cls");

    // 对链表进行排序
    bubbleSort_PFlight(&p);

    printf("起点站名\t终点站名\t航班ID\t飞机号\t飞行日期\t乘员定额\t余票量\t经济票剩余量\t商务票剩余量\n");
    while (p != NULL) {
        //调用Display_flight_Infomation函数打印出每个航班节点的信息
        Display_flight_Infomation(p);
        p = p->next;
    }
    printf("\n\n");
}

/**
  * @brief 删除节点
  * @return 返回操作是否成功
  */
Status DeleteFlight() {
    char flightCodeID[20];
    printf("请输入一个航班ID\n");
    scanf("%s", flightCodeID);
    PFlight pre = pFlight;
    PFlight p = pre->next;

    while (p != NULL) {
        if (!strcmp(flightCodeID, p->flightCodeID)) {
            pre->next = p->next;
            free(p);
            return OK;
        }
        pre = p;
        p = p->next;
    }
    return ERROR;
}

/**
 *@brief 根据客户提出的起点，终点站名输出航线信息
 */
void SearchFlight() {
    char startPonit[10];
    char destination[10];
    int flag = 0;
    system("cls");
    printf("请输入起点站名:");
    scanf("%s", startPonit);
    printf("请输入终点站名:");
    scanf("%s", destination);
    struct Flight *p;
    p = pFlight->next;
    printf("起点站名\t终点站名\t航班ID\t飞机号\t飞行日期\t乘员定额\t余票量\t经济票剩余量\t商务票剩余量\n");

    while (p != NULL) {
        if ((strcmp(startPonit, p->startPoint) == 0) && (strcmp(destination, p->destination) == 0) ) {
            flag = 1;
            Display_flight_Infomation(p);
        }
        p = p->next;
    }
    printf("\n\n");

    if (flag == 0)
        printf("对不起，该航班未找到! \n");

}

/**
 * @brief 入队，增加排队等候的客户名单域
 * @param q 带头结点的链队列
 * @param name  等候客户的名字
 * @param amount    等候客户所需机票的数量
 * @param identification    等候客户的身份证号
 * @return  返回成功入队后的等候客户链的头结点
 */
LinkQueue Appendqueue(LinkQueue &q, char name[], int amount, char identification[])
{
    PWait new1;
    new1 = (PWait) malloc(sizeof(WaitQNode));
    strcpy(new1->name, name);
    strcpy(new1->identification, identification);
    new1->preTickets = amount;
    new1->next = NULL;

    q.rear->next = new1;
    q.rear = new1;

    return q;
}


/**
 * @brief 根据自己输入的航班ID查询并以指针形式返回
 * @return  航班指针
 */
Flight *find()
{
    char number[10];
    int i = 0;
    int loop;

    printf("请输入航班ID: ");
    scanf("%s", number);

    //头结点的下一个节点开始遍历
    Flight *p = pFlight->next;

    while (p != NULL) {
        if (!strcmp(number, p->flightCodeID))
            return p;

        p = p->next;
    }
    return NULL;
}

/**
 * 订票成功之后，将乘客信息插入到对应航班的订成员名单域中（链表）
 * @param head 乘客名单域头指针
 * @param amount 该乘客订票的数量
 * @param name 乘客的姓名
 * @param rank 订票的等级
 * @return  乘客链表头指针
 */
CusLinkList insertlink(CusLinkList &head, int amount, char name[], char identification[], int rank)
{
    //成员名单域新节点new1
    CusLinkList new1;
    new1 = (CustomerNode *) malloc(sizeof(CustomerNode));
    if (new1 == NULL)
    {
        printf("\n内存不足\n");
        return NULL;
    }
    //将传入乘客信息赋值给new1节点
    strcpy(new1->name, name);
    strcpy(new1->identification, identification);
    new1->clientTickets = amount;
    new1->rank = rank;

    //头插入法加入成员名单域
    new1->next = head->next;
    head->next = new1;

    return head;
}

/**
 * @brief 输出p节点的航班信息
 * @param p 航班节点
 */
void FlightInfo(Flight *p) {
    printf("起点站名\t终点站名\t航班ID\t飞机号\t飞行日期\t乘员定额\t余票量\t经济票剩余\t商务票剩余\n");
    Display_flight_Infomation(p);
    printf("\n\n");

}

/**
 * @brief 查找是否有同一路线的航班
 * @param destination   目的地
 * @param pflight 原航班，用来判断和新搜到的航班是否一样
 * @return 找不到就返回FALSE，否则返回TRUE
 */
Status RecommendFlight(char startPoint[], char destination[], Flight *pflight) {
    //标记变量，是否找到同一路线的航班
    int flag = 0;
    system("cls");
    struct Flight *p;
    p = pFlight->next;
    printf("寻找同一路线的航班\n");
    printf("起点站名\t终点站名\t航班ID\t飞机号\t飞行日期\t乘员定额\t余票量\t经济票剩余量\t商务票剩余量\n");

    while (p != NULL)
    {
        //路线相同，且不是同一个航班，标记flag = 1，表示找到
        if (strcmp(destination, p->destination) == 0 && strcmp(startPoint, p->startPoint) == 0 && p != pflight) {
            flag = 1;
            Display_flight_Infomation(p);
        }
        p = p->next;

    }
    printf("\n\n");

    //没有相同路线的航班
    if (flag == 0)
        return FALSE;
    return TRUE;
}


/**
 * @brief 订票模块
 */
void BookTickets()
{
    while(1)
    {
        struct Flight *info;
        int amount = 1, rank;
        int tickets; // 剩余的商务票数目或者经济票数目
        char name[10];
        char identification[20];
        int success = 0;

        system("cls");

        while (1)
        {
            // 调用查找航班函数，返回给 info
            info = find();
            if (info != NULL)
            {
                break;
            }
            printf("没有这个航班, 请重新输入\n");
        }

        printf("请正确输入您的票的舱位等级（1代表经济舱，其他代表商务舱）:");
        scanf("%d", &rank);
        if (rank == 1)
        {
            tickets = info->leftEconomicTicket;
        } else
        {
            tickets = info->leftBusinessTicket;
        }

        while (1) {
            printf("请正确输入你订票所需要的数量:");
            scanf("%d", &amount);
            if (amount > 0) {
                break;
            }
            printf("输入的数量不合法，请重新输入\n");
        }

        if (amount <= tickets)
        {
            printf("请输入您的姓名:");
            scanf("%s", name);
            printf("请输入您的身份证号码:");
            scanf("%s", identification);
            CusLinkList head = info->cusLinkList;
            // 订票成功，插入成员名单链表
            insertlink(head, amount, name, identification, rank);
	        for (int i = 0; i < amount; i++) {
	            printf("%s 的座位号是: %d\n", name, info->totalTickets - info->left + i + 1);
	        }
            info->left -= amount;


            if (rank == 1)
            {
                info->leftEconomicTicket -= amount;
            } else
            {
                info->leftBusinessTicket -= amount;
            }

            printf("\n祝您旅途愉快！欢迎再次光临\n");
            success = 1;
        }
        else
        {
            printf("该等级的票不足，订票失败，以下为该航班乘客信息, 希望对您的订票有所帮助\n");
            FlightInfo(info);
        }

        while (!success)
        {
            printf("是否改变订票计划？Y/N\n");
            char r;
            getchar(); // 清除缓冲区
            r = getchar();
            if (r == 'Y' || r == 'y')
            {
                // 改变计划，重新选择航班
                BookTickets();
                return;
            } else
            {
                printf("\n已经没有更多的票，您需要排队等候吗?(Y/N)\n");
                getchar(); // 清除缓冲区
                r = getchar();
                if (r == 'Y' || r == 'y')
                {
                    // 不改变计划，排队候票
                    printf("\n请输入您的姓名（排队订票客户）:");
                    scanf("%s", name);
                    printf("\n请输入您的身份证（排队订票客户）:");
                    scanf("%s", identification);
                    if (rank == 1)
                    {
                        // 进入经济舱排队队列
                        info->waitQueue1 = Appendqueue(info->waitQueue1, name, amount, identification);
                    } else
                    {
                        // 进入商务舱排队队列
                        info->waitQueue2 = Appendqueue(info->waitQueue2, name, amount, identification);
                    }
                    printf("\n排队成功!\n");
                    success = 1;
                } else
                {
                    printf("\n您选择不排队，谢谢使用！\n");
                    success = 1;
                }
            }
        }
        printf("是否继续购票，Y/N\n");
        char choice;
        cin>>choice;
        if(choice == 'N' || choice == 'n')
        {
            return;
        }
    }
}


/**
 * @param Q   Q为候补订票客户的队列
 * @param NameAndNumAndIDAndID 候补客户的姓名和订票数目，出队时，将姓名和关键字和身份证返回
 * @return
 */
Status QueueDelete(LinkQueue &q, NameAndNumAndID &NameAndNumAndID)
{
    WaitQNode *p;
    p = q.front->next;
    //带头结点的链表，当front指针和rear指针相等时，相当于队列为空，没有元素出队
    if (q.front == q.rear)
    {
        return ERROR;
    }
    //出队
    q.front->next = p->next;
    //出队到空时，rear = front
    if (q.front->next == NULL)
    {
        q.rear = q.front;
    }

    //返回出队元素的关键信息，包括候补客户的姓名和订票量
    NameAndNumAndID.num = p->preTickets;
    strcpy(NameAndNumAndID.name, p->name);
    strcpy(NameAndNumAndID.identification, p->identification);
    free(p);

    return OK;
}


/**
 * @brief 退票功能模块
 */
void ReturnTicket()
{
    struct Flight *info;
    int rank;
    CustomerNode *p1, *p2, *head;
    char cusname[10];
    char identification[20];
    system("cls");

    // 查找航班
    while (1)
    {
        info = find();
        if (info != NULL)
        {
            break;
        }
        printf("没有这个航班, 请重新输入\n");
    }

    head = info->cusLinkList;
    p1 = head->next;
    printf("请输入你的姓名: ");
    scanf("%s", cusname);
    printf("请输入你的身份证号码: ");
    scanf("%s", identification);

    // 搜索客户是否订票
    p2 = head;
    while (p1 != NULL)
    {
        if ((strcmp(cusname, p1->name) == 0) && (strcmp(identification, p1->identification) == 0))
        {
            break;
        }
        p2 = p1;
        p1 = p1->next;
    }

    if (p1 == NULL)
    {
        printf("对不起，你没有订过票或姓名和身份证不对应\n");
        return;
    }
    else
    {
        // 退票成功
        rank = p1->rank;
        p2->next = p1->next;
        info->left += p1->clientTickets;
        if (rank == 1)
        {
            info->leftEconomicTicket += p1->clientTickets;
        }
        else
        {
            info->leftBusinessTicket += p1->clientTickets;
        }
        printf("%s  成功退票！\n", p1->name);
        free(p1);
    }

    LinkQueue queue1 = info->waitQueue1;
    LinkQueue queue2 = info->waitQueue2;
    NameAndNumAndID nameAndNumAndID = {0, 0};

    if (rank == 1)
    {
        //cout<<"有经济舱退票，询问经济舱排队的客户" <<endl;
        // 有经济舱退票，询问经济舱排队的客户
        while (queue1.front->next != NULL && queue1.front->next->preTickets <= info->leftEconomicTicket) {
            // 从候补客户队列中，出队客户的姓名和订票量用NameAndNumAndID返回
            QueueDelete(info->waitQueue1, nameAndNumAndID);
            int y;
            printf("有经济舱票剩余 , 尊敬的%s ：\n", nameAndNumAndID.name);
            printf("是否确认订票（1确认订票， 其他数字拒绝订票）\n");
            scanf("%d", &y);

            if (y == 1)
            {
                // 排队订票成功
                for (int i = 0; i < nameAndNumAndID.num; i++)
                {
                    printf("排队订票成功  %s 的座位号是:%d\n", nameAndNumAndID.name, (info->left) - i);
                }
                // 剩余票减少
                info->left -= nameAndNumAndID.num;
                info->leftEconomicTicket -= nameAndNumAndID.num;
                // 乘员名单链表插入排队订票成功的客户
                info->cusLinkList = insertlink(info->cusLinkList, nameAndNumAndID.num, nameAndNumAndID.name,
                                               nameAndNumAndID.identification, rank);
            }
        }
    }
    else
    {
        //cout<<"有商务舱客户退票，询问商务舱排队的客户" <<endl;
        // 有商务舱客户退票，询问商务舱排队的客户
        while (queue2.front->next != NULL && queue2.front->next->preTickets <= info->leftBusinessTicket)
        {
            // 从候补客户队列中，出队客户的姓名和订票量用NameAndNumAndID返回
            QueueDelete(info->waitQueue2, nameAndNumAndID);
            int y;
            printf("有商务舱票剩余 , 尊敬的%s ：\n", nameAndNumAndID.name);
            printf("是否确认订票（1确认订票， 其他数字拒绝订票）\n");
            scanf("%d", &y);

            if (y == 1)
            {
                // 排队订票成功
                for (int i = 0; i < nameAndNumAndID.num; i++) {
                    printf("排队订票成功  %s 的座位号是:%d\n", nameAndNumAndID.name, (info->left) - i);
                }
                // 剩余票减少
                info->left -= nameAndNumAndID.num;
                info->leftBusinessTicket -= nameAndNumAndID.num;
                // 乘员名单链表插入排队订票成功的客户
                info->cusLinkList = insertlink(info->cusLinkList, nameAndNumAndID.num, nameAndNumAndID.name,
                                               nameAndNumAndID.identification, rank);
            }
        }
    }
}


// 冒泡排序函数，按照客户姓名从小到大排序
void bubbleSort_CusLinkList(CusLinkList head) {
    if (head == NULL || head->next == NULL) {
        return; // 如果链表为空或者只有头节点，不需要排序
    }

    CustomerNode *end = NULL; // 用于标记已经排好序的部分

    while (end != head->next) { // 外层循环控制排序的轮数
        CustomerNode *prev = head; // 前一个节点指针，初始为头节点
        CustomerNode *current = head->next; // 当前节点指针
        CustomerNode *nextNode = current->next; // 下一个节点指针

        while (nextNode != end) { // 内层循环进行一次完整的冒泡过程
            if (strcmp(current->name, nextNode->name) > 0) { // 比较当前节点和下一个节点的姓名
                // 交换节点的位置
                prev->next = nextNode;
                current->next = nextNode->next;
                nextNode->next = current;

                // 交换指针
                CustomerNode *temp = current;
                current = nextNode;
                nextNode = temp;
            }

            // 更新指针，继续下一次比较
            prev = current;
            current = nextNode;
            nextNode = nextNode->next;
        }

        // 更新已排好序的部分
        end = current;
    }
}


Status Visit_Passenger_Information(Flight *pflight)
{
    Flight *info = pflight->next;
    while (1)
    {
        // 调用查找航班函数，返回给 info
        info = find();
        if (info != NULL)
        {
            break;
        }
        printf("没有这个航班, 请重新输入\n");
    }

    CusLinkList head = info->cusLinkList->next;
    bubbleSort_CusLinkList(head);

    printf("客户姓名\t客户订票量\t身份证号码\t航班ID\t舱位等级\t飞行日期\t起点站名\t终点站名\n");
    while(head)
    {
        printf("%8s\t%8d\t%s\t%10s\t%6d\t   %11s\t   %9s\t     %8s\n", head->name, head->clientTickets, head->identification,
               info->flightCodeID, head->rank ,info->day ,info->startPoint,info->destination);
        head = head->next;
    }
    return OK;
}


/**
 * @brief 退出程序模块界面
 */
void GoodbyeFace()
{
    system("cls");
    printf("\n");
    printf("\n");
    printf("             ---------------------------------------------\n");
    printf("             |            感谢使用航空航班订票系统        |\n");
    printf("             |                                           |\n");
    printf("             |                    GoodBye！               \n");
    printf("             --------------------------------------------\n");

}


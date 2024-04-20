#include <stdio.h>

#include <string.h>

#include <stdlib.h>


#define STACK_INIT_SIZE    20     /*存储空间的初始分配量*/

#define STACK_INCREMENT    10     /*存储空间的分配增量*/

//#define CHAR_MAX 127

#define DBL_MAX 100

#define ERROR 0

#define OK 1


/*数据栈结构体定义，要求：

包括栈底指针，栈顶指针和当前分配的存储容量*/

typedef struct
{

    double *Dbase;

    double *Dtop;

    int Dstacksize;

} DataStack;


/*操作符结构体定义，要求包括栈底指针，栈顶指针和当前分配的存储容量*/

typedef struct
{

    char *Obase;

    char *Otop;

    int Ostacksize;

} OpStack;


/*静态二维优先级数组：static char OperationPreceder[7][7]   

定义操作符＋、－、＊、／、（、）、=的运算优先级*/

static char OperationPreceder[7][7] =

        {{'>', '>', '<', '<', '<', '>', '>'},

         {'>', '>', '<', '<', '<', '>', '>'},

         {'>', '>', '>', '>', '<', '>', '>'},

         {'>', '>', '>', '>', '<', '>', '>'},

         {'<', '<', '<', '<', '<', '=', 'x'},

         {'>', '>', '>', '>', 'x', '>', '>'},

         {'<', '<', '<', '<', '<', 'x', '='}

        };


/*函数接口定义为：int TransOPtoCD(char op_temp)   

* 输入参数：操作符x   

* 处理规则及返回值：将操作符转化为运算优先级静态表的坐标，并返回；   

* 输入参数非＋、－、＊、／、（、）、=，则返回－1*/

int TransOPtoCD(char op_temp)
{

    switch (op_temp)
    {

        case '+':
            return (0);

        case '-':
            return (1);

        case '*':
            return (2);

        case '/':
            return (3);

        case '(':
            return (4);

        case ')':
            return (5);

        case '=':
            return (6);

        default:
            return (-1);  /*当输入参数不是四则运算、括号、等号时，返回－1*/

    }


}


/*函数接口定义为：char Precede(char op1, char op2)   

* 输入参数：进行比较的运算符op1和op2；   

* 处理规则及返回值：将op1和op2转化为二维数组OperationPreceder的坐标，查找该坐标存储的符号，并作为返回值输出；   

* 如果无法找到坐标则返回0*/

char Precede(char op1, char op2)
{

    int x, y;

    x = y = -1;

    x = TransOPtoCD(op1);

    y = TransOPtoCD(op2);

    if (x != -1 && y != -1)
    {

        //    printf("%c\n", OperationPreceder[x][y]);       

        return OperationPreceder[x][y];

    } else

        return 0;

}


/*函数接口定义为：int checkch (char c)   

* 输入参数：表达式字符c；   

* 处理规则及返回值：判断字符c是数字还是操作符；   

* 如果c是数字返回1，如果是小数点返回2，如果是运算符返回3，否则为无效字符返回－1；   

* 假设：表达式中的所有云算数均为正数*/

int checkch(char c)
{

    if (c >= '0' && c <= '9')

        return 1;

    if (c == '.')

        return 2;

    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '=')

        return 3;

    else

        return 0;

}


/*函数接口定义为：double Operate(double x,double y, char op)；   

* 输入参数：运算数x，被运算数y，操作符op；   

* 处理规则及返回值：进行x op y运算，返回运算结果；默认返回0.0*/

double Operate(double x, double y, char op)
{

    switch (op)
    {

        case '+':

            return x + y;

        case '-':

            return x - y;

        case '*':

            return x * y;

        case '/':

            if (y != 0)

                return x / y;

            else

                printf("The divisor cannot be 0!\n");

            exit(-1);

        default:

            break;

    }

    return 0.0;

}


/*数据栈初始化函数定义，要求：   

* 函数接口定义为：int InitDataStack(DataStack *DS)   

* 输入参数：数据栈DS   

* 处理规则及返回值：从内存堆中申请STACK_INIT_SIZE个整型空间，将栈顶指针与栈底指针都指向初始地址，给Dstacksize赋值STACK_INIT_SIZE   

* 初始化成功返回1，否则返回0.*/

int InitDataStack(DataStack *DS)
{


    //根据注释, 将该函数补充完整
    DS->Dbase = (double*)malloc(sizeof(double));
    if(!DS->Dbase)	return ERROR;
    DS->Dtop = DS->Dbase;
	DS->Dstacksize =  STACK_INIT_SIZE;
	return OK;
	
	
}


/* 数据栈入栈函数定义，要求：   

* 函数接口定义为：int PushDataStack(DataStack *DS,int e)   

* 输入参数：待操作数据栈DS，插入数据e；   

* 处理规则及返回值：在栈顶指针位置存储e，并将栈顶指针位置后移，返回1；   

如果数据栈不存在或者数据栈上溢，返回错误（0）。*/

int PushDataStack(DataStack *DS, double e)
{
	if(!DS->Dbase)	return ERROR;//数据栈不存在
	if(DS->Dtop - DS->Dbase >= DS->Dstacksize)
	{//据栈上溢,重新分配内存 
		DS->Dbase = (double*)realloc(DS->Dbase,(DS->Dstacksize +STACK_INCREMENT ) * sizeof(double));
		if(!DS->Dbase)	return ERROR;
		DS->Dtop = DS->Dbase + DS->Dstacksize;
		DS->Dstacksize += STACK_INCREMENT;
	}
	*(DS->Dtop++) = e;
	return OK;
   // 根据注释, 将该函数补充完整


}


/*数据栈出栈函数定义，要求：   

* 函数接口定义为：int PopDataStack(DataStack *DS, int *e)   

* 输入参数：数据栈DS, 输出整型指针变量e；   

* 处理规则及返回值：将栈顶指针减1，将该地址存储的变量付给＊e，返回1；   

如果数据栈不存在或数据栈为空，返回0。*/

int PopDataStack(DataStack *DS, double *e)
{

    //根据注释, 将该函数补充完整
    if(!DS->Dbase)	return ERROR;
    *e = *--DS->Dtop;
	return OK; 

}


/*数据栈查看栈顶元素函数定义，要求：   

* 函数接口定义为：int GetDataTop(DataStack *DS)   

* 输入参数：数据栈DS, 记录栈顶元素变量e；   

* 处理规则及返回值：如果数据栈不存在或数据栈为空，返回DBL_MAX; 否则，返回栈顶元素。*/

double GetDataTop(DataStack *DS)
{


    //根据注释, 将该函数补充完整
	if(!DS->Dbase)	return DBL_MAX;
	return *(DS->Dtop - 1);
	
}


/*数据栈销毁函数定义，要求：   

* 函数接口定义为：int DestroyDataStack(DataStack *DS   

* 输入参数：数据栈DS   

* 处理规则及返回值：释放栈底指针所指空间，并将数据栈的栈底和栈顶指针置空，数据栈Dstacksize置为0。最后返回1*/

int DestroyDataStack(DataStack *DS)
{

    //根据注释, 将该函数补充完整
    free(DS->Dbase);
	DS->Dbase = NULL;
	DS->Dtop = NULL;
	DS->Dstacksize = 0;
	if(DS->Dbase)	return ERROR;
	return OK;

}


/*符号栈初始化函数定义，要求：   

* 函数接口定义为：int InitOpStack(OpStack *OS)   

* 输入参数：符号栈OS   

* 处理规则及返回值：从内存堆中申请STACK_INIT_SIZE个整型空间，将栈顶指针与栈底指针都指向初始地址，给Dstacksize赋值STACK_INIT_SIZE   

* 初始化成功返回1，否则返回0.*/

int InitOpStack(OpStack *OS)
{

    //根据注释, 将该函数补充完整
    OS->Obase = (char*)malloc(sizeof(char));
    if(!OS->Obase)	return ERROR;
    OS->Otop = OS->Obase;
    OS->Ostacksize = STACK_INIT_SIZE;
    return OK;

}


/* 符号栈入栈函数定义，要求：   

* 函数接口定义为：int PushOpStack(OpStack *OS,int e)   

* 输入参数：待操作符号栈DS，插入符号e；   

* 处理规则及返回值：在栈顶指针位置存储e，并将栈顶指针位置后移，返回1；   

如果符号栈不存在或者符号栈上溢，返回0。*/

int PushOpStack(OpStack *OS, char e)
{


//    根据注释, 将该函数补充完整
	if(!OS->Obase)	return OK;
	if(OS->Otop - OS->Obase >= OS->Ostacksize)	
	{
		OS->Obase = (char*)realloc(OS->Obase,(OS->Ostacksize + STACK_INCREMENT)*sizeof(char));
		
	}
	*OS->Otop++ = e;
}


/* 符号栈出栈函数定义，要求：   

* 函数接口定义为：int PopOpStack(OpStack *OS, int *e)   

* 输入参数：符号栈DS, 输出符号指针变量e；   

* 处理规则及返回值：将栈顶指针减1，将该地址存储的变量付给＊e，返回1；   

如果符号栈不存在或符号栈为空，返回0。*/

int PopOpStack(OpStack *OS, char *e)
{

    //根据注释, 将该函数补充完整
    if(!OS->Obase)	return ERROR;
    *e = *--OS->Otop;
    return OK;

}


/* 符号栈查看栈顶元素函数定义，要求：   

* 函数接口定义为：char GetOpTop(OpStack *OS)   

* 输入参数：数据栈DS, 记录栈顶元素变量e；   

* 处理规则及返回值：如果数据栈不存在或数据栈为空，返回CHAR_MAX; 否则，返回栈顶元素。*/

char GetOpTop(OpStack *OS)
{


    //根据注释, 将该函数补充完整
	if(!OS->Obase)	return ERROR;
	return *(OS->Otop - 1);

}


/* 符号栈销毁函数定义，要求：   

* 函数接口定义为：int DestroyOpStack(OpStack *OS)   

* 输入参数：符号栈DS   

* 处理规则及返回值：释放栈底指针所指空间，并将符号栈的栈底和栈顶指针置空，符号栈Dstacksize置为0。最后返回1*/

int DestroyOpStack(OpStack *OS)
{

    //根据注释, 将该函数补充完整
	free(OS->Obase);
	OS->Obase = NULL;
	OS->Otop = NULL;
	OS->Ostacksize = 0;
	if(OS->Obase)	return ERROR;
	return OK; 

}


int main()
{

    OpStack OPTR = {0};      /*运算符栈*/

    DataStack OPND = {0};    /*操作数栈*/

    char op = 0;             /*当前运算符*/

    double value = 0.0;        /*数字字符的组合结果*/

    double b = 0.0;         /*当前运算的操作数*/

    double a = 0.0;         /*当前运算的被操作数*/

    char expression[1001] = {0};          /*表达式缓存，表达式长度不大于1000个字符*/

    int i = 0;                            /*表达式缓存的当前读取位置*/



    /*数据栈初始化函数定义，要求：   

    * 函数接口定义为：int InitDataStack(DataStack *DS)   

    * 输入参数：数据栈DS   

    * 处理规则及返回值：从内存堆中申请STACK_INIT_SIZE个整型空间，将栈顶指针与栈底指针都指向初始地址，给Dstacksize赋值STACK_INIT_SIZE   

    * 初始化成功返回1，否则返回0.*/

    if (InitDataStack(&OPND) == 0)
    {

        printf("InitDataStack Wrong\n");

        return 1;

    }



    /*符号栈初始化函数定义，要求：   

    * 函数接口定义为：int InitOpStack(OpStack *OS)   

    * 输入参数：符号栈OS   

    * 处理规则及返回值：从内存堆中申请STACK_INIT_SIZE个整型空间，将栈顶指针与栈底指针都指向初始地址，给Dstacksize赋值STACK_INIT_SIZE   

    * 初始化成功返回1，否则返回0.*/

    if (InitOpStack(&OPTR) == 0)
    {

        printf("InitOpStack Wrong\n");

        return 1;

    }



    /*符号栈栈底压入'＝'*/

    PushOpStack(&OPTR, '=');

    /*提示输入表达式，以等号结束*/

    printf("Please input the expression:\n");

    /*从标准输入获得表达式存入数组expression*/

    gets(expression);

    /*防护代码：当用户遗漏＝时提示*/

    if (expression[strlen(expression) - 1] != '=')
    {

        printf("Error: Please make sure the expression is ended with '='!");

        return 0;

    }


    while (i < strlen(expression) - 1 || GetOpTop(&OPTR) != '=')
    {

        //防护无效输入       

        if (checkch(expression[i]) == 0)
        {

            printf("Error: Invalid Input!");

            return 0;

        }

        //当表达式当前字符是数字时，逐位读入并组合       

        if (checkch(expression[i]) == 1)
        {

            while (checkch(expression[i]) == 1)
            {

                value = 10 * value + expression[i] - '0';

                i++;

            }

            /*如果表达式当前字符是小数，小数点后的数字处理后与小数点之前的数字相加*/

            if (checkch(expression[i]) == 2)
            {

                int r = 10;

                i++;

                while (checkch(expression[i]) == 1)
                {

                    value += (double) (expression[i] - '0') / r;

                    r = 10 * r;

                    i++;

                }

            }

            //数字压入数字栈OPND        

            PushDataStack(&OPND, value);

            value = 0.0;

        }



        /*如果表达式当前字符是运算符，则需要判断当前运算符与符号栈栈顶运算符的优先级*/

        if (checkch(expression[i]) == 3)
        {


            switch (Precede(GetOpTop(&OPTR), expression[i]))
            {

                /*如果符号栈栈顶运算符的优先级 < 表达式当前字符，则将表达式当前字符压入符号栈*/

                case '<':

                    PushOpStack(&OPTR, expression[i]);

                    i++;

                    break;

                    /*如果符号栈栈顶运算符的优先级 = 表达式当前字符，删去该栈顶符号*/

                case '=':

                    PopOpStack(&OPTR, &op);

                    i++;

                    break;

                    /*如果符号栈栈顶运算符的优先级 > 表达式当前字符，则计算栈顶运算符子式*/

                case '>':

                    PopOpStack(&OPTR, &op);

                    PopDataStack(&OPND, &b);

                    PopDataStack(&OPND, &a);

                    PushDataStack(&OPND, Operate(a, b, op));  /*运算结果入数据栈*/

                    break;

                default:

                    break;

            }

        }

    }

    /*打印表达式计算结果*/

    printf("The result is:%.2f\n", GetDataTop(&OPND));

    /*主动释放数据栈和符号栈的空间*/

    DestroyDataStack(&OPND);

    DestroyOpStack(&OPTR);

    return 0;

} 

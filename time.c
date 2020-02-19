//计时操作【c语言】
/*
clock():捕捉从程序开始运行到clock()被调用时所耗费的时间。
时间单位是 clock tick ,即“时钟打点”
*/

//常数CLK_TCK: 机器时钟每秒所走的时钟打点数

#include <stdio.h>
#include <time.h>

clock_t start,stop;
//clock_t 是clock() 函数返回的变量类型

double duration;
//记录被测函数运行的时间，以秒为单位

int main()
{
	//不在测试范围的准备工作写在clock()调用之前
	start = clock();	//开始计时
	MyFunction();		//被测函数
	stop = clock();		//停止计时
	//计算运算时间并输出其值
	duration = ((double)(stop - start))/CLK_TCK;
	printf("%.2lf",duration);
	
	//其他不在测试范围的处理写在后面
	return 0;
}

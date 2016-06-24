#include "stdafx.h"
#include "Information database.h"
#include"iostream"
#include "fstream"
#define MAX 50
#pragma once


class opereat
{
	char barcode[MAX][10];//条形码 商品唯一标识 以字符串形式保存
	char name[MAX][10];   //商品名称
	char unit[MAX][4];
	float price[MAX];          //单价
	float discount[MAX];       //折扣价
	int number[MAX];         //单价商品数量
	float prices[MAX];   //一种商品总价钱价钱
	float discounts[MAX];
	float totalprice;
	float totaldiscout;
	int num;

public:
	opereat()
	{
		num=0;
		totalprice=0; 
		totaldiscout=0;
	}
	int search(Information &jia,char barcodex[10]);
	void input(Information &jia,char barcodex[10],int number);
	void output1();
	void output2();
	void total();
};
int opereat::search(Information &jia,char barcodex[10])
{
	return jia.search(barcodex);
}
void opereat::input(Information &jia,char barcodex[10],int numberx)
{
	jia.returninformation(barcodex,name[num],unit[num],price[num],discount[num]);
	strcpy(barcode[num],barcodex);
	prices[num]=price[num]*numberx;
	discounts[num]=discount[num]*numberx;
	number[num]=numberx;
	num++;
}
void opereat::output1()
{
	cout<<"************************commodity******************"<<endl;
	for(int i=0;i<num;i++)
	{
		cout<<"name：";
		printf("%s",name[i]);
		cout<<"   ";
		cout<<"quantity：";
	    cout<<number[i];
		printf("%s",unit[i]);
		cout<<"   ";
		cout<<"price：";
		cout<<price[i];
	    cout<<"(元)";
		cout<<"   ";
		cout<<"sum price：";
		cout<<prices[i];
		cout<<"(元)"<<endl;
	}
	cout<<"----------------------"<<endl;
	cout<<"total price：";
	cout<<totalprice<<" (元)"<<endl;
	num=0;
	totalprice=0; 
	totaldiscout=0;
}
void opereat::output2()
{
	cout<<"************************commodity******************"<<endl;
	for(int i=0;i<num;i++)
	{
		cout<<"name：";
		printf("%s",name[i]);
		cout<<"   ";
		cout<<"number：";
	    cout<<number[i];
		printf("%s",unit[i]);
		cout<<"   ";
		cout<<"price：";
		cout<<discount[i];
	    cout<<"(元)";
		cout<<"   ";
		cout<<"sum price：";
		cout<<discounts[i];
		cout<<"(元)"<<endl;
	}
	cout<<"----------------------"<<endl;
	cout<<"total price：";
	cout<<totaldiscout<<" (元)"<<endl;
	cout<<"save：";
	cout<<totalprice-totaldiscout<<" (元)"<<endl;
	num=0;
	totalprice=0; 
	totaldiscout=0;
}
void opereat::total()
{
	for(int i=0;i<num;i++)
	{
		totalprice+=prices[i];
		totaldiscout+=discounts[i];
	}
}

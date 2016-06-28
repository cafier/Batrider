#include "stdafx.h"
#include "Information database.h"
#include"iostream"
#include "fstream"
#include <time.h>
#include<stdlib.h>
#include <stdio.h> 

#define MAX 50
#pragma once


class opereat
{
	char barcode[MAX][10];//条形码 商品唯一标识 以字符串形式保存
	char name[MAX][10];   //商品名称
	char unit[MAX][4];
	float price[MAX];          //单价
	float discount[MAX];       //折扣价
	float discount1[MAX];       //折扣
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
		for(int i=0;i<MAX;i++)
		{
			prices[i]=discounts[i]=0;
			number[i]=0;
		}
	}
	int search(Information &jia,char barcodex[10]);
	void input(Information &jia,char barcodex[10],int number);
	void input(Information &jia,char barcodex[10]);//新增重载函数
	void output1();
	void output2();
	void outputpromotion();//新增促销销售
	void total();
    void Salesprocess(Information &jia);
	void addin(Information &inf);//新增输入单个条码卖贷过程
};
int opereat::search(Information &jia,char barcodex[10])
{
	return jia.search(barcodex);
}
void opereat::input(Information &jia,char barcodex[10],int numberx)
{
	jia.returninformation(barcodex,name[num],unit[num],price[num],discount1[num]);
	strcpy(barcode[num],barcodex);
	prices[num]=price[num]*numberx;
	discounts[num]=discount1[num]*numberx;
	number[num]=numberx;
	num++;
}
void opereat::input(Information &jia,char barcodex[10])
{
	int flag=0;
	jia.returninformation(barcodex,name[num],unit[num],price[num],discount[num]);
	for(int i=0;i<num;i++)
	{
		if(!strcmp(barcode[i],barcodex))
		{
			number[i]+=1;
			prices[i]+=price[i];
			discounts[i]+=discount[i];
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		strcpy(barcode[num],barcodex);
		prices[num]=price[num];
		discounts[num]=discount[num];
		number[num]=1;
		num++;
	}
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
		cout<<discount1[i];
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
void opereat::outputpromotion()
{
	cout<<endl;
	cout<<"************************商品购物清单******************"<<endl;
	cout<<"打印时间：";
	time_t t = time(0); 
    char tmp[64]; 
    strftime( tmp, sizeof(tmp), "%Y年%m月%d日 %X ",localtime(&t) ); 
    puts( tmp ); 
	
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
		cout<<"total：";
		cout<<prices[i];
		cout<<"(元)"<<endl;
	}
	cout<<"----------------------"<<endl;
	cout<<"sales promotion(three for two)  ："<<endl;
	totaldiscout=0;
	for(int i=0;i<num;i++)
	{
		if(number[i]>1)
		{
			cout<<"nanme：";
			printf("%s",name[i]);
			cout<<"   ";
			cout<<"quantity：";
			cout<<number[i]/2;
			printf("%s",unit[i]);
			cout<<"   ";
			totaldiscout+=price[i]*(number[i]/2);
			cout<<endl;
		}
	}
	cout<<"total：";
	cout<<totalprice<<" (元)"<<endl;
	cout<<"save money：";
	cout<<totaldiscout<<" (元)"<<endl;
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
void opereat::Salesprocess(Information &inf)
{
	char barcode[MAX];
	int numble;
	cout<<"please input shopping information（exit when code is0）"<<endl;
	do
	{
		cout<<"please input commodity code：";
		scanf("%s",barcode);
		if(!strcmp(barcode,"0"))
			break;
		if(!search(inf,barcode))
		{
			cout<<"can't find commodity ！"<<endl;
			continue;
		}
		cout<<"please input shopping quantity：";
		cin>>numble;
		input(inf,barcode,numble);
	}while(1);
	total();
}
void opereat:: addin(Information &inf)
{
	char barcode[MAX];
	int numble;
	cout<<"please input shopping information（exit when code is0）"<<endl;
	do
	{
		cout<<"please input commodity code：";
		scanf("%s",barcode);
		if(!strcmp(barcode,"0"))
			break;
		if(!search(inf,barcode))
		{
			cout<<"can't find commodity ！"<<endl;
			continue;
		}
		input(inf,barcode);
	}while(1);
	total();
}



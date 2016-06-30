#include "stdafx.h"
#include "Information database.h"
#include"iostream"
#include "fstream"
#include<stdlib.h>
#include <stdio.h> 
#include <time.h>

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
	float vipdiscount[MAX];    //会员优惠

	int number[MAX];         //单价商品数量
	int choose[MAX];         //结账方式,1时为买2赠1优惠活动（不参与打折与会员）
	
	float prices[MAX];   //
	float vipprices[MAX];
	float discounts[MAX];
	float vipdiscounts[MAX];

	float totalprice;
	float totalvipprice;
	float totaldiscout;
	float totalvipdiscount;

	int num;//商品的种类
public:	
	opereat()
	{
		num=0;
		totalprice=0;
		totalvipprice=0;
		totaldiscout=0;
		totalvipdiscount=0;
		for(int i=0;i<MAX;i++)
		{
			prices[i]=vipprices[i]=discounts[i]=vipdiscount[i]=0;
			number[i]=0;
		}

	}
	int search(Information &jia,char barcodex[10]);
	void input(Information &jia,char barcodex[10],int number);
	void input(Information &jia,char barcodex[10]);//新增重载函数
	void output1();   //正常销售时，非会员打印票据
	void vipoutput1();//正常销售时，会员打印票据
	void output2();   //打折赠品时，非会员打印票据
	void vipoutput2();//打折赠品时，会员打印票据
	void total();
    void Salesprocess(Information &jia);
	void addin(Information &inf);//新增输入单个条码卖贷过程
	float returnmoney(int i);
};
int opereat::search(Information &jia,char barcodex[10])
{
	return jia.search(barcodex);
}
void opereat::input(Information &jia,char barcodex[10],int numberx)
{
	jia.returninformation(barcodex,name[num],unit[num],price[num],discount[num],vipdiscount[num],choose[num]);
	strcpy(barcode[num],barcodex);


	prices[num]=price[num]*numberx;
	vipprices[num]=price[num]*vipdiscount[num]*numberx;
	discounts[num]=price[num]*discount[num]*numberx;
	vipdiscounts[num]=price[num]*discount[num]*numberx*vipdiscount[num];

	number[num]=numberx;
	num++;
}
void opereat::input(Information &jia,char barcodex[10])
{
	int flag=0;//标记符，当商品存在里为1；
	jia.returninformation(barcodex,name[num],unit[num],price[num],discount[num],vipdiscount[num],choose[num]);
	for(int i=0;i<num;i++)
	{
		if(!strcmp(barcode[i],barcodex))
		{
			number[i]+=1;
			prices[i]+=price[i];
			vipprices[i]=vipprices[i]+price[i]*vipdiscount[i];
			discounts[i]=discounts[i]+discount[i]*price[i];
			vipdiscounts[i]=vipdiscounts[i]+discount[i]*price[i]*vipdiscount[i];
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		strcpy(barcode[num],barcodex);
		prices[num]=price[num];
		vipprices[num]=price[num]*vipdiscount[num];
		discounts[num]=discount[num]*price[num];
		vipdiscounts[num]=discount[num]*price[num]*vipdiscount[num];

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

void opereat::vipoutput1()
{
	cout<<"---------------------------"<<endl;

	cout<<endl;cout<<"打印时间：";
	time_t t = time(0); 
    char tmp[64]; 
    strftime( tmp, sizeof(tmp), "%Y年%m月%d日 %X ",localtime(&t) ); 
    puts( tmp ); 
	

	cout<<"---------------------------"<<endl;
	
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
		cout<<price[i]*vipdiscount[i];
	    cout<<"(元)";
		cout<<"   ";
		cout<<"total：";
		cout<<prices[i]*vipdiscount[i];
		cout<<"(元)"<<endl;
	}
	cout<<"----------------------"<<endl;
	cout<<"total：";
	cout<<totalvipprice<<" (元)"<<endl;
	cout<<"save money：";
	cout<<totalprice-totalvipprice<<" (元)"<<endl;
	num=0;
	totalprice=0; 
	totalvipprice=0;
	totaldiscout=0;
	totalvipdiscount=0;
}

void opereat::output2()
{
	cout<<endl;
	cout<<"打印时间：";
	time_t t = time(0); 
    char tmp[64]; 
    strftime( tmp, sizeof(tmp), "%Y年%m月%d日 %X ",localtime(&t) ); 
    puts( tmp );

	totalvipdiscount=0;
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
		cout<<"sales promotion(three for two)：";
		if(!choose[i])
		{
			cout<<"N"<<"   ";
			cout<<"price：";
			cout<<discount[i]*price[i];
			cout<<"(元)";
			cout<<"   ";
			cout<<"total：";
			cout<<discounts[i];
			cout<<"(元)"<<endl;
		}
		else
		{
			cout<<"Y"<<"   ";
			cout<<"price：";
			cout<<price[i];
			cout<<"(元)";
			cout<<"   ";
			cout<<"total：";
			cout<<prices[i];
			cout<<"(元)"<<endl;
		}
	}
	cout<<"----------------------"<<endl;
	cout<<"sales promotion(three for two)"<<endl;
	for(int i=0;i<num;i++)
	{
		if(number[i]>1&&choose[i]==1)
		{
			cout<<"name：";
			printf("%s",name[i]);
			cout<<"   ";
			cout<<"quantity：";
			cout<<number[i]/2;
			printf("%s",unit[i]);
			cout<<"   ";
			totalvipdiscount+=price[i]*(number[i]/2);
			cout<<endl;
		}
	}

	cout<<"total：";
	cout<<totaldiscout<<" (元)"<<endl;
	cout<<"save money：";
	cout<<totalprice-totaldiscout+totalvipdiscount<<" (元)"<<endl;
	num=0;
	totalprice=0; 
	totalvipprice=0;
	totaldiscout=0;
	totalvipdiscount=0;
}
//会员时输入结果
void opereat::vipoutput2()
{
	cout<<endl;
	cout<<"---------------------------"<<endl;
	cout<<"打印时间：";
	time_t t = time(0); 
    char tmp[64]; 
    strftime( tmp, sizeof(tmp), "%Y年%m月%d日 %X ",localtime(&t) ); 
    puts( tmp );
	totaldiscout=0;
	cout<<"---------------------------"<<endl;
	for(int i=0;i<num;i++)
	{
		cout<<"name：";
		printf("%s",name[i]);
		cout<<"   ";
		cout<<"quantity：";
	    cout<<number[i];
		printf("%s",unit[i]);
		cout<<"   ";
		cout<<"sales promotion(three for two)：";
		if(!choose[i])
		{
			cout<<"N"<<"   ";
			cout<<"price：";
			cout<<vipdiscount[i]*price[i]*discount[i];
			cout<<"(元)";
			cout<<"   ";
			cout<<"total：";
			cout<<vipdiscounts[i];
			cout<<"(元)"<<endl;
		}
		else
		{
			cout<<"Y"<<"   ";
			cout<<"price：";
			cout<<price[i];
			cout<<"(元)";
			cout<<"   ";
			cout<<"total：";
			cout<<prices[i];
			cout<<"(元)"<<endl;
		}
	}
	cout<<"----------------------"<<endl;
	cout<<"sales promotion(three for two)"<<endl;
	for(int i=0;i<num;i++)
	{
		if(number[i]>1&&choose[i]==1)
		{
			cout<<"name：";
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
	cout<<totalvipdiscount<<" (元)"<<endl;
	cout<<"save money：";
	cout<<totalprice-totalvipdiscount+totaldiscout<<" (元)"<<endl;
	num=0;
	totalprice=0; 
	totalvipprice=0;
	totaldiscout=0;
	totalvipdiscount=0;
}
void opereat::total()
{
	for(int i=0;i<num;i++)
	{
		totalprice+=prices[i];
		totalvipprice+=vipprices[i];
		if(!choose[i])
			totaldiscout+=discounts[i];
		else
			totaldiscout+=prices[i];
		if(!choose[i])
			totalvipdiscount+=vipdiscounts[i];
		else
			totalvipdiscount+=prices[i];
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
//简单扫码的过程
void opereat:: addin(Information &inf)
{
	char barcode[MAX];
	int numble;
	cout<<"please input shopping information（exit when code is0）"<<endl;
	do
	{
		cout<<"please input commodity code：：";
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
float opereat::returnmoney(int i)
{
	if(i==1)
		return totalvipprice;
	if(i==2)
		return totalvipdiscount;
}












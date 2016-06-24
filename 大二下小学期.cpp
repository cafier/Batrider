#include "stdafx.h"
#include"iostream"
#include "fstream"
#define MAX 50
using namespace std;
#pragma once 

class Information
{
	char barcode[MAX][10];//条形码 商品唯一标识 以字符串形式保存
	char name[MAX][10];   //商品名称
	
	float price[MAX];          //单价
	float discount[MAX];       //折扣价
	char unit[MAX][4];
	int sum;              //库存商品种类
public:
	Information(){sum=0;}
	//录入商品信息
	void input();
	//输出商品信息
	void output( );
	//通过条形码，查看商品是否存在
	int search(char barcodex[MAX]);
	void returninformation(char *barcodex,char *namex,char *unitx,float &price,float &discount);
};
void Information::input()
{
	char barcodex[10];
	int sumx=sum;
	int numx;
	cout<<"the number of input commodity：";
	cin>>numx;
	for(int i=0;i<numx;i++)
	{
		do{
			cout<<endl;
			cout<<"please input commodity code（ITEM000000）：";
			scanf("%s",barcodex);
			if(search(barcodex))
				cout<<"input commodity code fault!"<<endl;
		}while(search(barcodex));
		strcpy(barcode[i+sumx],barcodex);
		cout<<"please input commodity name：";
		scanf("%s",name[i+sumx]);

		cout<<"please input commodity unit name（瓶/个）：";
		scanf("%s",unit[i+sumx]);

		cout<<" input commodity price：";
		cin>>price[i+sumx];
		cout<<"input commodity discount price：";
		cin>>discount[i+sumx];
		
		sum++;
	}
	system("Cls");
}
//条形码内容是库内商品码，返回真
int Information::search(char barcodex[10])
{
	int result=0;
	for(int i=0;i<sum;i++)
	{
		if(!strcmp(barcode[i],barcodex))
		{
			result=1;
			break;
		}
	}
	return result;
}
void Information::output()
{
	for(int i=0;i<sum;i++)
	{
		cout<<"commodity basic information：";
		cout<<"code     name    unit name    price    discount price"<<endl;
		cout<<"                ";
		printf("%s",barcode[i]);
		cout<<"   ";
		printf("%s",name[i]);
		cout<<"   ";
		printf("%s",unit[i]);
		cout<<"   ";
		cout<<price[i];
		cout<<"   ";
		cout<<discount[i]<<endl;
	}
}
void Information::returninformation(char *barcodex,char *namex,char *unitx,float &pricex,float &discountx)
{
	for(int i=0;i<sum;i++)
	{
		if(!strcmp(barcode[i],barcodex))
		{
			strcpy(namex,name[i]);
			strcpy(unitx,unit[i]);
			pricex=price[i];
			discountx=discount[i];
			break;
		}
	}
}

// 大二下小学期.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Information database.h"
#include "opereat.h"
#define MAX 50
int mainmenu();
int mainmenuinf();
int mainmenuope();
void Salesprocess(opereat &ope,Information inf);



int _tmain(int argc, _TCHAR* argv[])
{
	int x;
	Information inf;//基本信息类对象
	opereat ope;    //基本操作类对象

	do{
		x=mainmenu();
		if (x==1)
		{
			int y=mainmenuinf();
			if(y==1)
			{
				inf.input();
			}
			if(y==2)
			{
				inf.output();
			}
		}
		if(x==2)
		{
			int y=mainmenuope();
			if(y==1)
			{
				Salesprocess(ope,inf);
				ope.output1();
			}
			if(y==2)
			{
				Salesprocess(ope,inf);
				ope.output2();
			}
		}
	}while(x!=3);	
	return 0;
}
int mainmenu()
{
	int i;
	do{
	cout<<endl<<endl<<endl;
	cout<<"        ****************************"<<endl;
	cout<<"        **  1、system entrance    **"<<endl;
	cout<<"        **  2、market entrance    **"<<endl;
	cout<<"        **  3、exit               **"<<endl;
	cout<<"        ****************************"<<endl;
	cout<<"            请选择：";
	cin>>i;
	system("Cls");
	}while(i!=2&&i!=1&&i!=3);
	return i;
}
int mainmenuinf()
{
	int i;
	do{
	cout<<endl<<endl<<endl;
	cout<<"        ********************************************"<<endl;
	cout<<"        **  1、create commodity information       **"<<endl;
	cout<<"        **  2、display commodity information      **"<<endl;
	cout<<"        **  3、update commodity information       **"<<endl;
	cout<<"        **  4、exit                               **"<<endl;
	cout<<"        ********************************************"<<endl;
	cout<<"            请选择：";
	cin>>i;
	system("Cls");
	}while(i<1&&i>4);
	return i;
}
int mainmenuope()
{
	int i;
	do{
	cout<<endl<<endl<<endl;
	cout<<"        ****************************************"<<endl;
	cout<<"        **  1、sell commodity                 **"<<endl;
	cout<<"        **  2、sell commodity in discount     **"<<endl;
	cout<<"        **  3、exit                           **"<<endl;
	cout<<"        ****************************************"<<endl;
	cout<<"            请选择：";
	cin>>i;
	system("Cls");
	}while(i<1&&i>3);
	return i;
}
void Salesprocess(opereat &ope,Information inf)
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
		if(!ope.search(inf,barcode))
		{
			cout<<"input fault！"<<endl;
			continue;
		}
		cout<<"please input commodity quantity：";
		cin>>numble;
		ope.input(inf,barcode,numble);
	}while(1);
	ope.total();
	
}

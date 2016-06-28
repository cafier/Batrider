// 大二下小学期.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Information database.h"
#include "opereat.h"
#define MAX 50
int mainmenu();
int mainmenuinf();
int mainmenuope();


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
				ope.Salesprocess(inf);
				ope.output1();
			}
			if(y==2)
			{
				ope.Salesprocess(inf);
				ope.output2();
			}
			if(y==3)
			{
				ope.addin(inf);
				ope.output1();
				ope.output2();
			}
			if(y==4)
			{
				ope.addin(inf);
				ope.output2();
			}
			if(y==5)
			{
				ope.Salesprocess(inf);
				ope.outputpromotion ();
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
	cout<<"          choose：";
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
	cout<<"            choose：";
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
	cout<<"        ************************************************"<<endl;
	cout<<"        **  1、sell commodity                         **"<<endl;
	cout<<"        **  2、sell commodity in discount             **"<<endl;
	cout<<"        **  3、sell commodity with code               **"<<endl;
	cout<<"        **  4、sell commodity with code in discount   **"<<endl;
	cout<<"        **  5、sales promotion(three for two)         **"<<endl;
	cout<<"        **  6、exit                                   **"<<endl;
	cout<<"        ************************************************"<<endl;
	cout<<"            请选择：";
	cin>>i;
	system("Cls");
	}while(i<1&&i>6);
	return i;
}

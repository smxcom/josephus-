#include<iostream>
#include<iomanip>
using namespace std;

struct Boy             //小孩结点
{
	int boy;
	Boy *pNext;
};


Boy* pFirst;      //第一个小孩
Boy* pCurrent;    //当前小孩
Boy* pivot;       //前一个小孩


int main()
{
	int numOfBoy, num;
	cout << "please input the number of boy" << endl       //输入小孩数与间隔数
		<< "please input the interval" << endl;
	cin >> numOfBoy >> num;

	pFirst = new Boy;
	pCurrent = pFirst;      //初始化第一个小孩
	pFirst->boy = 1;

	int code = 2;
	for (;code<=numOfBoy;code++)        //循环，以进行小孩数的初始化
	{
		pivot = pCurrent;
		pCurrent = new Boy;
		pivot->pNext = pCurrent;
		pCurrent->boy = code;
	}
	pCurrent->pNext = pFirst;
	pCurrent = pFirst;
	code = 2;

	cout << setw(4) << pFirst->boy;       //输出第一个小孩


	for (;code<=numOfBoy;code++)         //逐个输出小孩编号
	{
		pivot = pCurrent;
		pCurrent = pCurrent->pNext;
		cout << setw(4) << pCurrent->boy;
	}
	cout << endl;
	pCurrent->pNext = pFirst;
	pCurrent = pFirst;



	for (;pCurrent->pNext!=pCurrent;)       //阎王点卯
	{
		for (int j= num;j>1;j--)
		{
			pivot = pCurrent;
			
			pCurrent = pCurrent->pNext;
		}
		pivot->pNext = pCurrent->pNext;
		cout << setw(4) << pCurrent->boy;
		delete pCurrent;
		pCurrent = pivot->pNext;
	}

	cout << endl;


	cout << pCurrent->boy << endl;      //只剩一个结点并输出当前小孩
	delete pCurrent;


	system("pause");
}
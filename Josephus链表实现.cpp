#include<iostream>
#include<iomanip>
using namespace std;

struct Boy             //С�����
{
	int boy;
	Boy *pNext;
};


Boy* pFirst;      //��һ��С��
Boy* pCurrent;    //��ǰС��
Boy* pivot;       //ǰһ��С��


int main()
{
	int numOfBoy, num;
	cout << "please input the number of boy" << endl       //����С����������
		<< "please input the interval" << endl;
	cin >> numOfBoy >> num;

	pFirst = new Boy;
	pCurrent = pFirst;      //��ʼ����һ��С��
	pFirst->boy = 1;

	int code = 2;
	for (;code<=numOfBoy;code++)        //ѭ�����Խ���С�����ĳ�ʼ��
	{
		pivot = pCurrent;
		pCurrent = new Boy;
		pivot->pNext = pCurrent;
		pCurrent->boy = code;
	}
	pCurrent->pNext = pFirst;
	pCurrent = pFirst;
	code = 2;

	cout << setw(4) << pFirst->boy;       //�����һ��С��


	for (;code<=numOfBoy;code++)         //������С�����
	{
		pivot = pCurrent;
		pCurrent = pCurrent->pNext;
		cout << setw(4) << pCurrent->boy;
	}
	cout << endl;
	pCurrent->pNext = pFirst;
	pCurrent = pFirst;



	for (;pCurrent->pNext!=pCurrent;)       //������î
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


	cout << pCurrent->boy << endl;      //ֻʣһ����㲢�����ǰС��
	delete pCurrent;


	system("pause");
}
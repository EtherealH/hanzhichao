// better.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

const int w_1m = 1000000;
int w[w_1m];

bool is_match(int t, int low, int high)
{
	int med;
	while (low <= high)
	{
		med = (low + high) / 2;
		if (t == w[med])
		{
			return false;
		}
		else if (t < w[med])
		{
			high = med - 1;

		}
		else
		{
			low = med + 1;
		}
	}
	return true;
}

// brute -w whitelist < T
int main(int argc, char *argv[])//agrc������ĸ���
{
	if (argc != 3 || strcmp(argv[1], "-w"))//Ҫ�����������������������ͷ���1��������
	{
		return 1;
	}

	// init w
	////    for(int i=0;i<w_1m)
	////    {
	////        w[i]=-1; //���Ƿ�����
	////    }
	ifstream infile;
	//ofstream outfile;
	infile.open(argv[1]);//argv[0]��ִ�е�.exe���ļ���argv[1]��ִ�е�txt���ڵ�·��
	int i = 0;
	cout << argv[1] << endl;
	while (infile >> w[i++])//��whitelist�ж�ȡ����
	{

	}//������ȡ
	cout << i << endl;
	int w_length = i - 1;
	cout << w_length << endl;
	// check t
	int t;
	//outfile.open(argv[3]);
	//infilee.open(argv[2]);
	while (cin >> t)//����һ�����֣��ж��ı��ļ�����û�С�//tӦ����p�ṩ������
	{
		if (is_match(t, 0, w_length))
		{
			//outfile << t << endl;
			cout << t << endl;
		}
	}
	//outfile.close();
	//infilee.close();
}


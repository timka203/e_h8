#include <iostream>
#include <stdio.h>
#include <time.h>
#include <locale.h>
using namespace std;
int func3(int b[])
{
	int min = 1000;
	for (size_t i = 0; i < 100; i++)
	{
		if (b[i] == 0)
		{


		}
		else if (b[i] < min)
		{
			min = b[i];
		}
	}
	return min;

}
void func2(int a[])
{
	for (size_t i = 0; i < 100; i++)
	{
		a[i] = -100 + rand() % 200;
		cout << a[i] << endl;
	}
	for (size_t i = 0; i < 100; i++)
	{
		cout << a[i] << endl;
	}
}
void func4(int a[][10],int f)
{
	static int g = 0;
	static int p = 0;
	static int y = f;
	if (p>y)
		return;
	static int h = 1;
	if (h >= 5)
	{
		h = 1;
	}
	if (h == 1)
	{
		for (size_t i = p; i < p+1; i++)
		{
			
			for (int j = p; j < y+1; j++)
			{
				a[i][j] = g;
				g++;
			}
		}
		p = p + 1;
	}
	if (h == 2)
	{
		for (size_t i = y; i < y+1; i++)
		{

			for (int j = p; j < y+1; j++)
			{
				a[j][i] = g;
				g++;
			}

		}
	}
	if (h == 3)
	{
		for (size_t i = y; i < y+1; i++)
		{

			for (int j = y-1; j > p-2; j--)
			{
				a[i][j] = g;
				g++;
			}

		}
	}
	if (h == 4)
	{
		for (size_t i = p-1; i < p; i++)
		{
			for (int j = y-1; j > p-1; j--)
			{
				a[j][i] = g;
				g++;
			}

		}
		y = y - 1;
	}
	 h++;
	func4(a, f);
}
void task2()
{

	int a[10][10] = { 0 };
	int f;
	cin >> f;
	func4(a, f-1);
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			cout << a[i][j] << "   ";
		}
		printf("\n");
	}

}
void func1(int a[],int b[], int g)
{
	if (g >= 90)
		return ;
	b[g] = a[g] + a[g + 1] + a[g + 2] + a[g + 3] + a[g + 4] + a[g + 5] + a[g + 6] + a[g + 7] + a[g + 8] + a[g + 9];
	cout << b[g] << endl;
	func1(a, b, g + 1);


}
void task1()
{
	int a[100];
	int b[100] = { 0 };
	int g = 1;
	func2(a);
	printf("--------------\n");
	func1(a, b, g);
	printf("--------------\n");
	cout << func3(b) << endl;
}
int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int a, d;
	do
	{
		printf("Which task");
		scanf_s("%d", &d);
		switch (d)
		{
		case 1: task1(); break;
		case 2: task2(); break;

		default:
			break;
		}
		printf(" do you want continue y(1)/no(2)");
		scanf_s("%d", &a);
	} while (a == 1);
	system("pause");
}
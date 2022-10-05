#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	const double pi = 3.1415;
	double R, H, V, V0, x, y, z;

	int N = 100, n = 0;//Количевство внутренних точек в фигуре,повысить значение N для увеличения точности

	cout << "Enter Radius= ";
	cin >> R;
	cout << "Enter Height= ";
	cin >> H;
	V0 = 4 * R * R * (H + R);//Объём паралепипеда
	
	for (int i = 0; i <= N; i++) 
	{
		x = 2 * i * R / N - R;
		for (int j = 0; j <= N; j++) 
		{
			y = 2 * j * R / N - R;
			for (int k = 0; k <= N; k++)
			{
				z = k * (H + R) / N;
				if(((sqrt(x * x + y * y) / R <= z / H) && (z <= H)) || ((x * x + y * y + (z - H) * (z - H) <= R * R) && (z > H)))n++;
			}
		}
	}
	
	V = V0 * n / pow(N + 1, 3);
	cout << "Точное значение : Приближенное" << endl;
	cout << "V = " << V << " : "<< pi*R*R*H/3+2*pi*pow(R,3)/3 << endl;
	system("pause");
	return 0;
	
}

#include<iostream>
#define MAX 1000
using namespace std;

int a[50][50], n, d[50][50], next[50][50];

void nhap() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (i != j && a[i][j] == 0)
				a[i][j] = MAX;
		}
}
void Floyd() {
	for (int i = 1; i <= n; i++) /* Khoi tao */
		for (int j = 1; j <= n; j++) {
			d[i][j] = a[i][j];
			next[i][j] = j;
		}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					next[i][j] = next[i][k];
				}
}
void xuat(int x, int y) {
	int arr[100];
	int n = 0;
	if (d[x][y] == MAX) {
		cout << "NO" << endl;
	}
	else {
		cout << d[x][y] << endl; // xuat so dinh;

		cout << x << "->";
		arr[n++] = x;
		while (x != y) {
			x = next[x][y];
			if (x == y)
			{
				cout << y << endl;
				arr[n++] = y;
			}
			else
			{
				 cout << x << "->";
				arr[n++] = x;
			}
		}
		for (int i =-1; i >= 0; i--)
		{
			if (i == 0) cout << arr[i] << endl;
			else cout << arr[i] << "<-";
		}
	}
}
int main() {
	int x, y;
	cin >> n >> x >> y;
	nhap();
	Floyd();
	xuat(x, y);
	return 0;
}

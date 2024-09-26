#include <iostream>
using namespace std;


	char arr[10][10] {
				{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
				{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
				{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
				{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
				{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
				{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
				{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
				{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
				{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
				{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'}
			};

				
void clear() {
    cout << "\x1B[2J\x1B[H";
}

void matrix() {
	for (int i = 0; i < 10; i++) {
		int k = 0;
		for (;k < 10; k++) {
			cout<<arr[k][i];
		}
		cout<<endl;
	}
}

int main(int argc, char *argv[])
{
	
		
	matrix();
	
	int x = 0;
	int y = 0;
	char c = ' ';
	int a = 0;
	int xe = 9;
	int ye = 9;
	int q = 0;
	
	arr[xe][ye] = '@';
	arr[x][y] = '#';
	
	clear();
	
	matrix();
	
	bool IsRunning = true;

	while(IsRunning) {
		clear();
		matrix();
		arr[xe][ye] = '0';
		
		q++;
		int rx = x - xe;
		int ry = y - ye;
		int irx = rx;
		int iry = ry;
		if (rx < 0) {
			irx=rx*-1;
		}
		if (ry < 0) {
			iry=ry*-1;
		}
		if (q%2 == 0) {
			if (irx < iry) {
				if (ry < 0) {
					ye--;
				}
				else {
					ye++;
				}
			}
			else {
				if (rx < 0) {
					xe--;
				}
				else {
					xe++;
				}
			}
		}

		arr[x][y] = '0';
		cout<<"letter: ";
		cin>>c;
		switch(c) {
			case 'a':
				if ( x == 0) {
					cout<<"nope";
				}
				else {
					x=x-1;
				}
				break;
			case 'd':
				if (x == 9) {
					cout<<"nope";
				}
				else {
					x=x+1;
				}
				break;
			case 'w':
				if (y == 0) {
					cout<<"nope";
				}
				else {
					y--;
				}
				break;
			case 's':
				if (y == 9) {
					cout<<"nope";
				}
				else {
					y++;
				}
				break;
		}
		
		arr[xe][ye] = '@';
		arr[x][y] = '#';
		clear();
		if (arr[x][y] == arr[xe][ye]) {
                        cout<<"САС";
                        cin>>a;
                        IsRunning = false;
                }
	}
}


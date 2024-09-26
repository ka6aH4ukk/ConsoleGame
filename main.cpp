#include <iostream>
using namespace std;

char arr[10][10];

int moving(int wll, int dirctn, int& axis) {
	if (axis != wll) {
		if (dirctn) {
			axis++;
		}
		else {
			axis--;
		}
	}
	return axis;
}

void matrix() {
	cout << "\x1B[2J\x1B[H";
	for (int i = 0; i < 10; i++) {
		for (int k = 0;k < 10; k++) {
			cout<<arr[k][i];
		}
		cout<<endl;
	}
}

int main(int argc, char *argv[])
{
	
	for (int j = 0; j < 10; j++) {
		for (int p = 0; p < 10; p++) {
			arr[j][p] = ':';
		}
	}

	matrix();

	struct {
		int x;
		int y;
	} player, enemy;

	char c = ' ';
	int a = 0;
	int q = 0;
	
	player.x = 0;
	player.y = 0;
	enemy.x = 9;
	enemy.y = 9;
	
	arr[enemy.x][enemy.y] = '@';
	arr[player.x][player.y] = '#';
	
	matrix();
	
	bool IsRunning = true;

	while(IsRunning) {
		matrix();
		arr[enemy.x][enemy.y] = ':';
		
		q++;
		int diff_x = player.x - enemy.x;
		int diff_y = player.y - enemy.y;
		int i_diff_x = abs(diff_x);
		int i_diff_y = abs(diff_y);
		if (q%2 == 0) {
			if (i_diff_x < i_diff_y) {
				if (diff_y < 0) {
					enemy.y--;
				}
				else {
					enemy.y++;
				}
			}
			else {
				if (diff_x < 0) {
					enemy.x--;
				}
				else {
					enemy.x++;
				}
			}
		}

		arr[player.x][player.y] = ':';
		cout<<"letter: ";
		cin>>c;
		switch(c) {
			case 'a': moving(0, 0, player.x);
				break;
			case 'd': moving(9, 1, player.x);
				break;
			case 'w': moving(0, 0, player.y);
				break;
			case 's': moving(9, 1, player.y);
		}
		
		arr[enemy.x][enemy.y] = '@';
		arr[player.x][player.y] = '#';
		if (arr[player.x][player.y] == arr[enemy.x][enemy.y]) {
			matrix();
            cout<<"САС";
            cin>>a;
            IsRunning = false;
        }
	}
}


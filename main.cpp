#include <iostream>
using namespace std;

char arr[40][20];
bool IsRunning = true;


struct {
	int x;
	int y;
} player, enemy;

char c = ' ';
int a = 0;
int q = 0;
int LifeTime = 0;
	


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
	for (int i = 0; i < 20; i++) {
		for (int k = 0;k < 40; k++) {
			cout<<arr[k][i];
		}
		cout<<endl;
	}
}

void collision_check(bool &IsR, int LiT) {
	if (arr[player.x][player.y] == arr[enemy.x][enemy.y]) {
			matrix();
            cout<<"Game over!\nYour life time: "<<LiT<<endl;
            cin>>a;
            IsR = false;
	}
}

int main(int argc, char *argv[])
{
	
	for (int j = 0; j < 40; j++) {
		for (int p = 0; p < 20; p++) {
			arr[j][p] = ':';
		}
	}

	matrix();

	player.x = 0;
	player.y = 0;
	enemy.x = 39;
	enemy.y = 19;
	
	arr[enemy.x][enemy.y] = '@';
	arr[player.x][player.y] = '#';
	
	matrix();

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
			case 'd': moving(39, 1, player.x);
				break;
			case 'w': moving(0, 0, player.y);
				break;
			case 's': moving(19, 1, player.y);
		}
		
		arr[enemy.x][enemy.y] = '@';
		arr[player.x][player.y] = '#';
		collision_check(IsRunning, LifeTime);
		LifeTime++;
	}
}


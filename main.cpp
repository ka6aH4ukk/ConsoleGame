#include <iostream>
#include <ctime>
using namespace std;

char arr[40][20];
bool IsRunning = true;


struct {
	int x;
	int y;
} player, enemy, npc;

char choice = ' ';
int a = 0;
int q = 0;
int score = 0;
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
	if (arr[player.x][player.y] == arr[npc.x][npc.y]) {
		score++;
		npc.x = rand() % 38 + 1;
		npc.y = rand() % 18 + 1;
	}

	if (arr[player.x][player.y] == arr[enemy.x][enemy.y]) {
			matrix();
            cout<<"Game over!\nYour life time: "<<LiT<<endl;
			cout<<"Your score: "<<score<<endl;
            cin>>a;
            IsR = false;
	}
}

void enemy_moving(int wll, int &mov, int diff) {
		if (diff < 0) {
			if (mov != 0) {
				mov--;
			}
		}
		else {
			if (mov != wll) {
				mov++;
			}
		}



}

int main(int argc, char *argv[])
{
	
	for (int j = 0; j < 40; j++) {
		for (int p = 0; p < 20; p++) {
			arr[j][p] = ':';
		}
	}

	srand(time(0));

	matrix();

	player.x = 0;
	player.y = 0;
	enemy.x = 39;
	enemy.y = 19;
	npc.x = rand() % 38 + 1;
	npc.y = rand() % 18 + 1;
	
	arr[npc.x][npc.y] = '&';
	arr[enemy.x][enemy.y] = '@';
	arr[player.x][player.y] = '#';
	
	matrix();

	while(IsRunning) {
		matrix();
		arr[enemy.x][enemy.y] = ':';
		arr[npc.x][npc.y] = ':';
		
		q++;

		int diff_x = player.x - enemy.x;
		int diff_y = player.y - enemy.y;
		int nDiff_x = player.x - npc.x;
		int nDiff_y = player.y - npc.y;
		int i_diff_x = abs(diff_x);
		int i_diff_y = abs(diff_y);
		int i_nDiff_x = abs(nDiff_x);
		int i_nDiff_y = abs(nDiff_y);
		if (q%2 == 0) {
			if (i_nDiff_x < i_nDiff_y) {
				enemy_moving(19, npc.y, nDiff_y*-1);
			}
			else {
				enemy_moving(39, npc.x, nDiff_x*-1);
			}
			if (i_diff_x < i_diff_y) {
				enemy_moving(19, enemy.y, diff_y);
			}
			else {
				enemy_moving(39, enemy.x, diff_x);
			}
		}



		arr[player.x][player.y] = ':';

		cout<<"letter: ";
		cin>>choice;
		switch(choice) {
			case 'a': moving(0, 0, player.x);
				break;
			case 'd': moving(39, 1, player.x);
				break;
			case 'w': moving(0, 0, player.y);
				break;
			case 's': moving(19, 1, player.y);
		}
		
		arr[npc.x][npc.y] = '&';
		arr[enemy.x][enemy.y] = '@';
		arr[player.x][player.y] = '#';
		
		collision_check(IsRunning, LifeTime);
		LifeTime++;
	}
}


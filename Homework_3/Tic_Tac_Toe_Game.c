#include <stdio.h>

void print_array(char array[3][3]) {
	for(int i =0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				printf("%c", array[i][j]);
			}
			printf("\n");
		}
}

void move(char player, char array[][3]) {
	int x;
	int y;
	printf("Tell me the row and column you want %c respectively", player);
	fflush(stdout);
	scanf("%d %d", &x, &y);
	array[x][y] = player;

}

int game_checker(char array[][3]){
	for(int i = 0; i < 3; i++) {
		if((array[i][0] == array[i][1]) && (array[i][1] == array[i][2])&& array[i][1] != '*') {
			if(array[i][0] == 'X') {
				return 1;
			}else if(array[i][0] == 'Y') {
				return 2;
			}
		}else if((array[0][i] == array[1][i]) && (array[1][i] == array[2][i]) && array[1][i] != '*') {
			if(array[1][i] == 'X') {
				return 1;
			}else if(array[1][i] == 'Y') {
				return 2;
			}
		}
	}

	if((array[0][0] == array[1][1]) && (array[1][1] == array[2][2])) {
		if(array[1][1] == 'X') {
			return 1;
		}else if(array[1][1] == 'Y') {
			return 2;
		}
	}else if((array[0][2] == array[1][1]) && (array[1][1] == array[0][2])) {
		if(array[1][1] == 'X') {
			return 1;
		}else if(array[1][1] == 'Y') {
			return 2;
		}
	}


	return 0;
}


int main() {
	int counter = 0;
	char array[3][3];
	int game_done = 0;

	for(int i =0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			array[i][j] = '*';
		}
	}

	print_array(array);

	while(!game_done){
		move('X', array);
		counter++;
		if(counter == 9) {
			break;
		}
		game_done = game_checker(array);
		move('Y', array);
		counter++;
		if(counter == 9) {
			break;
		}
		game_done = game_checker(array);
		print_array(array);
		if(game_done == 1) {
			printf("Player X won.");
		}else if(game_done == 2) {
			printf("Player Y won.");
		}
	}
	if(counter == 9){
		printf("It was a tie.");
	}

	return 0;
}

#include <stdio.h>

/*int calculate_population(int start, int birth, int death, int years) {
	int population = 0;
	for(int i = 1; i <= years; i++) {
		if(i == 1) {
			population = start + (birth - death);
		}else{
			population = population + (birth - death);
		}
	}
	return population;
}

int get_start() {
	int start = 0;
	printf("What do you want your starting size to be?");
	fflush(stdout);
	scanf("%d", &start);
	if(start < 2) {
		printf("That isn't a valid number, try again.\n");
		start = get_start();
	}
	return start;
}

int get_birth() {
	int birth = 0;
	printf("What do you want your birth rate to be?");
	fflush(stdout);
	scanf("%d", &birth);
	if(birth < 0) {
		printf("That isn't a valid number, try again.\n");
		birth = get_birth();
	}
	return birth;
}

int get_death() {
	int death = 0;
	printf("What do you want your death rate to be?");
	fflush(stdout);
	scanf("%d", &death);
	if(death < 0) {
		printf("That isn't a valid number, try again.\n");
		death = get_death();
	}
	return death;
}

int get_year() {
	int year = 0;
	printf("How many years have gone by since the start.");
	fflush(stdout);
	scanf("%d", &year);
	if(year < 1) {
		printf("That isn't a valid number, try again.\n");
		year = get_year();
	}
	return year;
}

int main() {

	int starting_size = get_start();
	int birth_rate = get_birth();
	int death_rate = get_death();
	int year = get_year();
	int population = calculate_population(starting_size, birth_rate, death_rate, year);

	printf("This is the population: %d", population);

	return 0;
}*/

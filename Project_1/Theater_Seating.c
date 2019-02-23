#include <stdio.h>

/*
 * Function to print out the seating chart.
 * @array is the array that contains the seating chart.
 */
void print_seating(char array[][30]) {
	for(int i = 0; i < 15; i++) {
		if(i < 9) {
			printf("Row %d    ", i+1);
		}else {
			printf("Row %d   ", i+1);
		}
		for(int j = 0; j < 30; j++) {
			printf("%c", array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/*
 * Function to figure out if we can sell the seat then mark it as sold.
 * @array is the array that contain the seating chart.
 * @prices is the array that contains what the prices for each thing is.
 * @group_ticket_amount is how many tickets the person wants to buy
 * @profit is how much profit the theater has made so far.
 */
int set_seats(char array[][30], int prices[], int group_ticket_amount, int profit){
	int row;
	int column;
	while(group_ticket_amount) {
		printf("What is the row and column of the seat being sold, in that order?");
		fflush(stdout);
		scanf("%d %d", &row, &column);
		row--;
		column--;
		if(array[row][column] == '*') {
			printf("That seat is already taken, try again.\n");
		}else if((row >= 0 && row <= 15) && (column >= 0 && column <= 30)){
			profit += prices[row];
			array[row][column] = '*';
			group_ticket_amount--;
		}else {
			printf("That isn't a seat.\n");
		}
	}
	if(profit != 0) {
		printf("Those seat(s) will cost $%d\n", profit);
	}
	return profit;
}

/*
 * Function to figure out and print out how many seats there are available in the theater.
 * @seating is array that contains the seating chart
 */
void available_seat_counter(char seating[][30]) {
	int counter = 0;
	int total_counter = 0;

	for(int i = 0; i < 15; i++) {
		for(int j = 0; j < 30; j++) {
			if(seating[i][j] == '#') {
				counter++;
			}
		}
		printf("Row %d ", i+1);
		printf("has %d more seats available still.\n", counter);
		total_counter += counter;
		counter = 0;
	}
	printf("There are %d more seats available overall\n", total_counter);
}

/*
 *Function to print out the menu for the user.
 *@overall_profit is how much profit we've made so far
 *@seats_sold_total is how many seats have been sold so far
 *@seating is the array that contains the seating chart.
 */

int menu(int overall_profit, int seats_sold_total, char seating[][30]) {
	int ticket_amount = 0;;
	int answer;
	printf("1. You want to purchase a ticket\n2. You want to see the total ticket sales.\n3. You want to know "
			"how many seats are still available.");
	fflush(stdout);
	scanf("%d", &answer);
	if(answer == 1) {
		printf("How many tickets do you want to buy?");
		fflush(stdout);
		scanf("%d", &ticket_amount);
	}else if(answer == 2) {
		printf("The overall profit so far is: $%d\n", overall_profit);
	}else if(answer == 3){
		printf("We have sold this many seats so far: %d\n", seats_sold_total);
		available_seat_counter(seating);
	}
	return ticket_amount;
}

int main() {

	char seating[15][30];
	int prices[15];
	int still_running = 1;
	int group_ticket_amount;
	int ticket_counter = 0;
	int overall_profit = 0;


	for(int i = 0; i < 15; i++) {
		for(int j = 0; j < 30; j++) {
			seating[i][j] = '#';
		}
	}

	for(int i = 0; i < 15; i++) {
		printf("What price is the row %d?", i+1);
		fflush(stdout);
		scanf("%d", &prices[i]);
	}
	while(still_running) {
		print_seating(seating);
		group_ticket_amount = menu(overall_profit, ticket_counter,seating);
		overall_profit += set_seats(seating,prices,group_ticket_amount, 0);
		ticket_counter += group_ticket_amount;
		if(ticket_counter == 450) {
			still_running = 0;
		}
	}
	return 0;
}

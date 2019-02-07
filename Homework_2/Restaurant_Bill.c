#include <stdio.h>

int main(int argc, char **argv) {
	float bill_price = 88.67;
	float tax = 0.0675;
	float tax_amount = bill_price * tax;
	float tip = 0.20;
	float tip_amount = (bill_price + tax_amount)*tip;
	float total_bill = bill_price + tip_amount + tax_amount;


	printf("Meal Cost: %.4f\n", bill_price);
	printf("Tax Amount: %.4f\n" , tax_amount);
	printf("Tip Amount: %.4f\n",tip_amount);
	printf("Total Bill: %.4f\n",total_bill);

	return 0;
}

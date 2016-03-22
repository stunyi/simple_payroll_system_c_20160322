#include <stdio.h>

#define HOURLY_PAY_RATE 10
#define OVERTIME_LIMIT 40
#define OVERTIME_PAY_RATE (HOURLY_PAY_RATE * 1.5)

#define TAX_RATE_FIRST_BRACKET 0.15
#define TAX_RATE_SECOND_BRACKET 0.20
#define TAX_RATE_THIRD_BRACKET 0.25

#define FIRST_BRACKET_LIMIT 300
#define SECOND_BRACKET_LIMIT (FIRST_BRACKET_LIMIT + 150)

float calculateTaxForFirstBracket(float amount){
	if(amount > FIRST_BRACKET_LIMIT){
		return FIRST_BRACKET_LIMIT * TAX_RATE_FIRST_BRACKET;
	}else {
		return TAX_RATE_FIRST_BRACKET * amount;
	}
}

float calculateTaxForSecondBracket(float amount){
	
	if(amount > FIRST_BRACKET_LIMIT){
		if(amount <= SECOND_BRACKET_LIMIT){
			return (amount - FIRST_BRACKET_LIMIT) * TAX_RATE_SECOND_BRACKET;
		}else {
			return (SECOND_BRACKET_LIMIT - FIRST_BRACKET_LIMIT) * TAX_RATE_SECOND_BRACKET;
		}
	}
	
	return 0;
}

float calculateTaxForThirdBracket(float amount){
	
	if(amount > SECOND_BRACKET_LIMIT){
		return (amount - SECOND_BRACKET_LIMIT)	* TAX_RATE_THIRD_BRACKET;
	}	
	
	return 0;
}

float calculateTax(float grossPay){
	return calculateTaxForFirstBracket(grossPay) + calculateTaxForSecondBracket(grossPay) + calculateTaxForThirdBracket(grossPay);
}

float calculateNormalRate(float noOfHoursWorked){
	
	if(noOfHoursWorked > 0){
		if(noOfHoursWorked > OVERTIME_LIMIT){
			return OVERTIME_LIMIT * HOURLY_PAY_RATE;
		} else {
			return HOURLY_PAY_RATE * noOfHoursWorked;
		}
	}
}

float calculateOvertimeRate(float noOfHoursWorked){
	
	if(noOfHoursWorked > OVERTIME_LIMIT){
		return (noOfHoursWorked - OVERTIME_LIMIT) * OVERTIME_PAY_RATE;
	} else {
		return 0;
	}
}

float calculateGrossPay(float noOfHoursWorked){
	
	return calculateNormalRate(noOfHoursWorked) + calculateOvertimeRate(noOfHoursWorked);
}

void printPay(float noOfHoursWorked){
	printf("Number of Hours worked (%.1f hrs) \n", noOfHoursWorked);
	printf("Normal Pay:		%.2f\n",calculateNormalRate(noOfHoursWorked));
	printf("Overtime Pay: 		%.2f\n",calculateOvertimeRate(noOfHoursWorked));
	printf("Gross Pay: 		%.2f\n",calculateGrossPay(noOfHoursWorked));
	printf("------------------------------------\n");
	printf("Tax Bracket 1: 		%.2f\n",calculateTaxForFirstBracket(calculateGrossPay(noOfHoursWorked)));
	printf("Tax Bracket 2: 		%.2f\n",calculateTaxForSecondBracket(calculateGrossPay(noOfHoursWorked)));
	printf("Tax Bracket 3: 		%.2f\n",calculateTaxForThirdBracket(calculateGrossPay(noOfHoursWorked)));
	printf("Gross Tax:    		%.2f\n",calculateTax(calculateGrossPay(noOfHoursWorked)));
	printf("------------------------------------\n");
	printf("Net Pay:		%.2f\n", calculateGrossPay(noOfHoursWorked) - calculateTax(calculateGrossPay(noOfHoursWorked)));
	printf("====================================\n\n");
	
}

int main()
{
	float noOfHoursWorked = 0;
	
	for(;;){
		printf("Please enter the number of Hours Worked. Enter (0) to exit\n");
		scanf("%f",&noOfHoursWorked);
		if(noOfHoursWorked > 0){
			printPay(noOfHoursWorked);
		} else if(noOfHoursWorked == 0){
			break;
		} else {
			continue;
		}
			
	}

	return 0;
}

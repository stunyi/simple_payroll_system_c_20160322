#include <stdio.h>

#define HOURLY_PAY_RATE normalPayRate
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

float calculateNormalRate(float noOfHoursWorked, float HOURLY_PAY_RATE){
	
	if(noOfHoursWorked > 0){
		if(noOfHoursWorked > OVERTIME_LIMIT){
			return OVERTIME_LIMIT * HOURLY_PAY_RATE;
		} else {
			return HOURLY_PAY_RATE * noOfHoursWorked;
		}
	}
}

float calculateOvertimeRate(float noOfHoursWorked, float HOURLY_PAY_RATE){
	
	if(noOfHoursWorked > OVERTIME_LIMIT){
		return (noOfHoursWorked - OVERTIME_LIMIT) * OVERTIME_PAY_RATE;
	} else {
		return 0;
	}
}

float calculateGrossPay(float noOfHoursWorked, float HOURLY_PAY_RATE){
	
	return calculateNormalRate(noOfHoursWorked, HOURLY_PAY_RATE) + calculateOvertimeRate(noOfHoursWorked, HOURLY_PAY_RATE);
}

void printPay(float noOfHoursWorked, float HOURLY_PAY_RATE){
	printf("Number of Hours worked (%.1f hrs) \n", noOfHoursWorked);
	printf("Hourly rate (%.2f/hr) \n", HOURLY_PAY_RATE);
	printf("------------------------------------\n");
	printf("Normal Pay:		%.2f\n",calculateNormalRate(noOfHoursWorked, HOURLY_PAY_RATE));
	printf("Overtime Pay: 		%.2f\n",calculateOvertimeRate(noOfHoursWorked,HOURLY_PAY_RATE));
	printf("Gross Pay: 		%.2f\n",calculateGrossPay(noOfHoursWorked,HOURLY_PAY_RATE));
	printf("------------------------------------\n");
	printf("Tax Bracket 1: 		%.2f\n",calculateTaxForFirstBracket(calculateGrossPay(noOfHoursWorked,HOURLY_PAY_RATE)));
	printf("Tax Bracket 2: 		%.2f\n",calculateTaxForSecondBracket(calculateGrossPay(noOfHoursWorked,HOURLY_PAY_RATE)));
	printf("Tax Bracket 3: 		%.2f\n",calculateTaxForThirdBracket(calculateGrossPay(noOfHoursWorked,HOURLY_PAY_RATE)));
	printf("Gross Tax:    		%.2f\n",calculateTax(calculateGrossPay(noOfHoursWorked,HOURLY_PAY_RATE)));
	printf("------------------------------------\n");
	printf("Net Pay:		%.2f\n", calculateGrossPay(noOfHoursWorked, HOURLY_PAY_RATE) - calculateTax(calculateGrossPay(noOfHoursWorked,HOURLY_PAY_RATE)));
	printf("====================================\n\n");
	
}

int main()
{
	float noOfHoursWorked = 0;
	float hourlyRate = 0;
	int selectionOption = 0;
	
	for(;;){
		printf("*******************************************************************\n");
		printf("Enter the number corresponding to the desired pay rate or action:\n");
		printf("1) $8.75/hr\n");
		printf("2) $9.33/hr\n");
		printf("3) $10.00/hr\n");
		printf("4) $11.20/hr\n");
		printf("5) Quit\n");
		printf("*******************************************************************\n");
		scanf("%d",&selectionOption);
		switch(selectionOption){
			case 1:
				hourlyRate = 8.75;
				break;
			case 2:
				hourlyRate = 9.33;
				break;
			case 3:
				hourlyRate = 10.00;
				break;
			case 4:
				hourlyRate = 11.20;
				break;
			case 5:
				hourlyRate = 0;
				return 0;
			default:
				printf("You entered an option that deosn't' lie between 1 and 5.'Only enter options 1 through 5\n");
				continue;
				
		}
		printf("Please enter the number of Hours Worked\n");
		scanf("%f",&noOfHoursWorked);
		if(noOfHoursWorked > 0 && hourlyRate > 0){
			printPay(noOfHoursWorked, hourlyRate);
		}
			
	}

	return 0;
}

#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h>

#define NR_MAX_TRIES	3 

#define TRUE		1 
#define FALSE		0 

#define SUCCESS		1 
#define FAILURE		0 

#define MILLIMETER	1 
#define CENTIMETER	2
#define METER		3 
#define KILOMETER	4 
#define INCH		5 
#define FOOT		6 
#define YARD		7 
#define MILE		8 
#define EXIT_APP	9 

double millimeter_to_centimeter(double);
double millimeter_to_meter(double);
double millimeter_to_kilometer(double);
double millimeter_to_inch(double);
double millimeter_to_foot(double);
double millimeter_to_yard(double);
double millimeter_to_mile(double);

double centimeter_to_millimeter(double);
double meter_to_millimeter(double);
double kilometer_to_millimeter(double);
double inch_to_millimeter(double);
double foot_to_millimeter(double);
double yard_to_millimeter(double);
double mile_to_millimeter(double);

void do_conversion(int from_choice, int to_choice, double input_number); 

int get_choice(const char* prompt, int valid_response_start, int valid_response_end); 
void exit_application(void); 

int main(void)
{
	int from_choice;
	int to_choice; 
	double input_number = 0.0; 
 
	while (TRUE)
	{
		puts("-------------------------------------------------------------"); 
		printf("1:Millimeter(mm)\n2:Centimeter(cm)\n3:Meter(m)\n4:Kilometer(km)\n");
		printf("5:Inch(in)\n6:Foot(ft)\n7:Yard(yd)\n8:Mile(mi)\n9:Exit\n");
		from_choice = get_choice("Convert From:", 1, 9);
		if (from_choice == EXIT_APP)
			exit_application();

		printf("Enter magnitude:"); 
		scanf_s("%lf", &input_number); 

		to_choice = get_choice("Convert To:", 1, 9); 
		printf("from_choice=%d, to_choice=%d\n", from_choice, to_choice); 
		if (to_choice == EXIT_APP)
			exit_application();

		do_conversion(from_choice, to_choice, input_number); 
	}

	_getch(); 
	exit(EXIT_SUCCESS); 
}

void do_conversion(int from_choice, int to_choice, double input_number)
{
	char* input_unit = NULL;
	char* output_unit = NULL;
	
	double output_number = 0.0; 

	if (from_choice == MILLIMETER && to_choice == MILLIMETER)
	{
		output_number = input_number; 
		input_unit = "mm"; 
		output_unit = "mm"; 
	}
	else if (from_choice == MILLIMETER && to_choice == CENTIMETER)
	{
		output_number = millimeter_to_centimeter(input_number); 
		input_unit = "mm"; 
		output_unit = "cm"; 
	}
	else if (from_choice == MILLIMETER && to_choice == METER)
	{
		output_number = millimeter_to_meter(input_number);
		input_unit = "mm"; 
		output_unit = "m"; 
	}
	else if (from_choice == MILLIMETER && to_choice == KILOMETER)
	{
		output_number = millimeter_to_kilometer(input_number);
		input_unit = "mm";
		output_unit = "km";
	}
	else if (from_choice == MILLIMETER && to_choice == INCH)
	{
		output_number = millimeter_to_inch(input_number); 
		input_unit = "mm"; 
		output_unit = "in"; 
	}
	else if (from_choice == MILLIMETER && to_choice == FOOT)
	{
		output_number = millimeter_to_foot(input_number); 
		input_unit = "mm"; 
		output_unit = "ft"; 
	}
	else if (from_choice == MILLIMETER && to_choice == YARD)
	{
		output_number = millimeter_to_yard(input_number); 
		input_unit = "mm"; 
		output_unit = "yard"; 
	}
	else if (from_choice == MILLIMETER && to_choice == MILE)
	{
		output_number = millimeter_to_mile(input_number); 
		input_unit = "mm"; 
		output_unit = "mi"; 
	}
	else if (from_choice == CENTIMETER && to_choice == MILLIMETER)
	{
		output_number = centimeter_to_millimeter(input_number); 
		input_unit = "cm"; 
		output_unit = "mm"; 
	}
	else if (from_choice == CENTIMETER && to_choice == CENTIMETER)
	{
		output_number = input_number; 
		input_unit = "cm"; 
		output_unit = "cm"; 
	}
	else if (from_choice == CENTIMETER && to_choice == METER)
	{
		output_number = millimeter_to_meter(centimeter_to_millimeter(input_number)); 
		input_unit = "cm"; 
		output_unit = "m"; 
	}
	else if (from_choice == CENTIMETER && to_choice == KILOMETER)
	{
		output_number = millimeter_to_kilometer(centimeter_to_millimeter(input_number)); 
		input_unit = "cm"; 
		output_unit = "km"; 
	}
	else if (from_choice == CENTIMETER && to_choice == INCH)
	{
		output_number = millimeter_to_inch(centimeter_to_millimeter(input_number)); 
		input_unit = "cm"; 
		output_unit = "in"; 
	}
	else if (from_choice == CENTIMETER && to_choice == FOOT)
	{
		output_number = millimeter_to_foot(centimeter_to_millimeter(input_number)); 
		input_unit = "cm";
		output_unit = "ft";
	}
	else if (from_choice == CENTIMETER && to_choice == YARD)
	{
		output_number = millimeter_to_yard(centimeter_to_millimeter(input_number)); 
		input_unit = "cm";
		output_unit = "yard";
	}
	else if (from_choice == CENTIMETER && to_choice == MILE)
	{
		output_number = millimeter_to_mile(centimeter_to_millimeter(input_number)); 
		input_unit = "cm";
		output_unit = "mi";
	}
	else if (from_choice == METER && to_choice == MILLIMETER)
	{
		output_number = meter_to_millimeter(input_number); 
		input_unit = "mm";
		output_unit = "m";
	}
	else if (from_choice == METER && to_choice == CENTIMETER)
	{
		output_number = millimeter_to_centimeter(meter_to_millimeter(input_number)); 
		input_unit = "m";
		output_unit = "cm";
	}
	else if (from_choice == METER && to_choice == METER)
	{
		output_number = input_number; 
		input_unit = "m";
		output_unit = "m";
	}
	else if (from_choice == METER && to_choice == KILOMETER)
	{
		output_number = millimeter_to_kilometer(meter_to_millimeter(input_number)); 
		input_unit = "mm";
		output_unit = "km";
	}
	else if (from_choice == METER && to_choice == INCH)
	{
		output_number = millimeter_to_inch(meter_to_millimeter(input_number)); 
		input_unit = "m";
		output_unit = "in";
	}
	else if (from_choice == METER && to_choice == FOOT)
	{
		output_number = millimeter_to_foot(meter_to_millimeter(input_number)); 
		input_unit = "m";
		output_unit = "ft";
	}
	else if (from_choice == METER && to_choice == YARD)
	{
		output_number = millimeter_to_yard(yard_to_millimeter(input_number));
		input_unit = "m";
		output_unit = "yard";
	}
	else if (from_choice == METER && to_choice == MILE)
	{
		output_number = millimeter_to_mile(meter_to_millimeter(input_number)); 
		input_unit = "m";
		output_unit = "mi";
	}
	else if (from_choice == KILOMETER && to_choice == MILLIMETER)
	{
		output_number = kilometer_to_millimeter(input_number); 
		input_unit = "km";
		output_unit = "mm";
	}
	else if (from_choice == KILOMETER && to_choice == CENTIMETER)
	{
		output_number = millimeter_to_centimeter(kilometer_to_millimeter(input_number)); 
		input_unit = "km";
		output_unit = "cm";
	}
	else if (from_choice == KILOMETER && to_choice == METER)
	{
		output_number = millimeter_to_meter(kilometer_to_millimeter(input_number)); 
		input_unit = "km";
		output_unit = "m";
	}
	else if (from_choice == KILOMETER && to_choice == KILOMETER)
	{
		output_number = input_number; 
		input_unit = "km";
		output_unit = "km";
	}
	else if (from_choice == KILOMETER && to_choice == INCH)
	{
		output_number = millimeter_to_inch(kilometer_to_millimeter(input_number)); 
		input_unit = "km";
		output_unit = "in";
	}
	else if (from_choice == KILOMETER && to_choice == FOOT)
	{
		output_number = millimeter_to_foot(kilometer_to_millimeter(input_number));
		input_unit = "km";
		output_unit = "ft";
	}
	else if (from_choice == KILOMETER && to_choice == YARD)
	{
		output_number = millimeter_to_yard(kilometer_to_millimeter(input_number)); 
		input_unit = "km";
		output_unit = "yard";
	}
	else if (from_choice == KILOMETER && to_choice == MILE)
	{
		output_number = millimeter_to_mile(kilometer_to_millimeter(input_number)); 
		input_unit = "km";
		output_unit = "mi";
	}
	else if (from_choice == INCH && to_choice == MILLIMETER)
	{
		output_number = inch_to_millimeter(input_number);
		input_unit = "in";
		output_unit = "mm";
	}
	else if (from_choice == INCH && to_choice == CENTIMETER)
	{
		output_number = millimeter_to_centimeter(inch_to_millimeter(input_number)); 
		input_unit = "in";
		output_unit = "cm";
	}
	else if (from_choice == INCH && to_choice == METER)
	{
		output_number = millimeter_to_meter(inch_to_millimeter(input_number)); 
		input_unit = "in";
		output_unit = "m";
	}
	else if (from_choice == INCH && to_choice == KILOMETER)
	{
		output_number = millimeter_to_kilometer(inch_to_millimeter(input_number)); 
		input_unit = "in";
		output_unit = "km";
	}
	else if (from_choice == INCH && to_choice == INCH)
	{
		output_number = input_number; 
		input_unit = "in";
		output_unit = "in";
	}
	else if (from_choice == INCH && to_choice == FOOT)
	{
		output_number = millimeter_to_foot(inch_to_millimeter(input_number)); 
		input_unit = "in";
		output_unit = "ft";
	}
	else if (from_choice == INCH && to_choice == YARD)
	{
		output_number = millimeter_to_yard(inch_to_millimeter(input_number)); 
		input_unit = "in";
		output_unit = "yard";
	}
	else if (from_choice == INCH && to_choice == MILE)
	{
		output_number = millimeter_to_mile(inch_to_millimeter(input_number)); 
		input_unit = "in";
		output_unit = "mi";
	}
	else if (from_choice == FOOT && to_choice == MILLIMETER)
	{
		output_number = foot_to_millimeter(input_number); 
		input_unit = "ft";
		output_unit = "mm";
	}
	else if (from_choice == FOOT && to_choice == CENTIMETER)
	{
		output_number = millimeter_to_centimeter(foot_to_millimeter(input_number)); 
		input_unit = "ft";
		output_unit = "cm";
	}
	else if (from_choice == FOOT && to_choice == METER)
	{
		output_number = millimeter_to_meter(foot_to_millimeter(input_number)); 
		input_unit = "ft";
		output_unit = "m";
	}
	else if (from_choice == FOOT && to_choice == KILOMETER)
	{
		output_number = millimeter_to_kilometer(foot_to_millimeter(input_number)); 
		input_unit = "ft";
		output_unit = "km";
	}
	else if (from_choice == FOOT && to_choice == INCH)
	{
		output_number = millimeter_to_inch(foot_to_millimeter(input_number)); 
		input_unit = "ft";
		output_unit = "in";
	}
	else if (from_choice == FOOT && to_choice == FOOT)
	{
		output_number = input_number; 
		input_unit = "ft";
		output_unit = "ft";
	}
	else if (from_choice == FOOT && to_choice == YARD)
	{
		output_number = millimeter_to_yard(foot_to_millimeter(input_number)); 
		input_unit = "ft";
		output_unit = "yard";
	}
	else if (from_choice == FOOT && to_choice == MILE)
	{
		output_number = millimeter_to_mile(foot_to_millimeter(input_number)); 
		input_unit = "ft";
		output_unit = "mi";
	}
	else if (from_choice == YARD && to_choice == MILLIMETER)
	{
		output_number = yard_to_millimeter(input_number); 
		input_unit = "ft";
		output_unit = "mm";
	}
	else if (from_choice == YARD && to_choice == CENTIMETER)
	{
		output_number = millimeter_to_centimeter(yard_to_millimeter(input_number)); 
		input_unit = "yard";
		output_unit = "cm";
	}
	else if (from_choice == YARD && to_choice == METER)
	{
		output_number = millimeter_to_meter(yard_to_millimeter(input_number)); 
		input_unit = "yard";
		output_unit = "m";
	}
	else if (from_choice == YARD && to_choice == KILOMETER)
	{
		output_number = millimeter_to_kilometer(yard_to_millimeter(input_number)); 
		input_unit = "yard";
		output_unit = "km";
	}
	else if (from_choice == YARD && to_choice == INCH)
	{
		output_number = millimeter_to_inch(yard_to_millimeter(input_number)); 
		input_unit = "yard";
		output_unit = "in";
	}
	else if (from_choice == YARD && to_choice == FOOT)
	{
		output_number = millimeter_to_foot(yard_to_millimeter(input_number)); 
		input_unit = "yard";
		output_unit = "ft";
	}
	else if (from_choice == YARD && to_choice == YARD)
	{
		output_number = input_number; 
		input_unit = "yard";
		output_unit = "yard";
	}
	else if (from_choice == YARD && to_choice == MILE)
	{
		output_number = millimeter_to_mile(yard_to_millimeter(input_number)); 
		input_unit = "yard";
		output_unit = "mi";
	}
	else if (from_choice == MILE && to_choice == MILLIMETER)
	{
		output_number = mile_to_millimeter(input_number); 
		input_unit = "mi";
		output_unit = "mm";
	}
	else if (from_choice == MILE && to_choice == CENTIMETER)
	{
		output_number = millimeter_to_centimeter(mile_to_millimeter(input_number)); 
		input_unit = "mi";
		output_unit = "cm";
	}
	else if (from_choice == MILE && to_choice == METER)
	{
		output_number = millimeter_to_meter(mile_to_millimeter(input_number)); 
		input_unit = "mi";
		output_unit = "m";
	}
	else if (from_choice == MILE && to_choice == KILOMETER)
	{
		output_number = millimeter_to_kilometer(mile_to_millimeter(input_number)); 
		input_unit = "mi";
		output_unit = "km";
	}
	else if (from_choice == MILE && to_choice == INCH)
	{
		output_number = millimeter_to_inch(mile_to_millimeter(input_number)); 
		input_unit = "mi";
		output_unit = "in";
	}
	else if (from_choice == MILE && to_choice == FOOT)
	{
		output_number = millimeter_to_foot(mile_to_millimeter(input_number)); 
		input_unit = "mi";
		output_unit = "ft";
	}
	else if (from_choice == MILE && to_choice == YARD)
	{
		output_number = millimeter_to_yard(mile_to_millimeter(input_number)); 
		input_unit = "mi";
		output_unit = "yard";
	}
	else if (from_choice == MILE && to_choice == MILE)
	{
		output_number = input_number; 
		input_unit = "mi";
		output_unit = "mi";
	}

	printf("%lf(%s) = %lf(%s)\n", input_number, input_unit, output_number, output_unit); 
}

double millimeter_to_centimeter(double mm)
{
	return (mm / 10.0); 
}

double millimeter_to_meter(double mm)
{
	return (mm / 1000.0); 
}

double millimeter_to_kilometer(double mm)
{
	return (mm / 1000000.0); 
}

double millimeter_to_inch(double mm)
{
	return (mm / 25.4); 
}

double millimeter_to_foot(double mm)
{
	return (mm / 304.8); 
}

double millimeter_to_yard(double mm)
{
	return (mm / 914.4); 
}

double millimeter_to_mile(double mm)
{
	return (mm / 1.609e+6); 
}

double centimeter_to_millimeter(double cm)
{
	return (cm * 10.0); 
}

double meter_to_millimeter(double m)
{
	return (m * 1000.0); 
}

double kilometer_to_millimeter(double km)
{
	return (km * 1000000.0); 
}

double inch_to_millimeter(double inch)
{
	return (inch * 25.4); 
}

double foot_to_millimeter(double ft)
{
	return (ft * 304.8); 
}

double yard_to_millimeter(double yd)
{
	return (yd * 914.4); 
}

double mile_to_millimeter(double mi)
{
	return (mi * 1.609e+6); 
}

int get_choice(const char* prompt, int valid_response_start, int valid_response_end)
{
	int number_of_tries; 
	int choice; 
	int flag = FALSE; 

	for (number_of_tries = 0; number_of_tries < NR_MAX_TRIES; ++number_of_tries)
	{
		printf(prompt); 
		scanf_s("%d", &choice);
		if (choice >= valid_response_start && choice <= valid_response_end)
		{
			flag = TRUE; 
			break; 
		}
		puts("Please Enter a valid choice:"); 
	}

	if (flag == FALSE)
	{
		puts("Thank you for using application!"); 
		_getch(); 
		exit(EXIT_FAILURE); 
	}

	return (choice); 
}

void exit_application(void)
{
	puts("Thank you for using the application"); 
	_getch(); 
	exit(EXIT_SUCCESS); 
}
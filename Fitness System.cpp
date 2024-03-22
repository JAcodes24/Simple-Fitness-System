#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void login_menu(); 		
void calc(); 			
void bmi_calc(float, float); 	
void bmr_calc(float, float, int); 
void fitnessShop(); 
void displayPrice(); 
void searchBMI(); 
void averageBMI(); 
float get_input (string&, int&); 
float calcTotal(string, int); 
float member(float); 


int main()
{
	char quit, choice;
	bool exit= false;
	
	while (exit != true){
		system("cls");  // command to clear the screen of any output
		cout << "----- ELITE Fitness System ----\n\n";
		
		cout << "0. Quit\n";
		cout << "1. Login\n";
		cout << "Choose Menu : ";
		cin >> choice;
		
		if (choice == '0'){
			cout << "Are you really want to quit? ( Y / N ) : ";
			cin >> quit;
			if (toupper(quit)== 'Y'){
				exit = true;
				cout << "\nThank you.";
				return 0;
			}
			else if (toupper(quit)== 'N'){
				exit = false;
			}
			else{
				cout << "INVALID ! ";
			}
		}
		else if (choice == '1'){
			login_menu();
		}
}
}
	
void login_menu()//display login menu
{
	char option;

	while (option != 'C'){	
		system ("cls");
		cout << "Welcome !\n";
		cout << "\nA- Calculator\n";
		cout << "B- Fitness Shop\n";
		cout << "C- Back\n";
		cout << "Choose Menu : ";
		cin >> option;
				
		switch (toupper(option)){
			case 'A':
				calc();
				break;
			case 'B':
				fitnessShop();
				system ("pause"); //command to pause the program
				break;
			case 'C':
				break;
		}
			
	}
}

void calc()//display calculator menu
{
	int age;
	char calculator;
	float weight, height;
	

	while (calculator != '1' || calculator != '2'|| calculator != '3' || calculator != '4' || calculator != '5' )
	{	
		system ("cls");
		cout << "-----CALCULATOR-----\n";
		cout << "\n1- BMI Calculator\n";
		cout << "2- BMR Calculator\n";
		cout << "3- Search BMI Level\n";
		cout << "4- Check your average BMI\n";
		cout << "5- Back\n";
		cout << "Choose Menu : ";
		cin >> calculator;
		
		if (calculator == '1' || calculator == '2'){
			system ("cls");
			cout << "----- BMI/BMR CALCULATOR -----\n";
			cout << "\nPlease enter your weight (kg) : ";
			cin >> weight;
			cout << "Please enter your height (cm) : ";
			cin >> height;
			cout << "Please enter your age : ";
			cin >> age;	
			
			if (calculator == '1'){
				bmi_calc(weight, height);
				system ("pause");
			}
			else if (calculator == '2'){
				bmr_calc(weight, height, age);
				system ("pause");
			}
			else
				cout << "INVALID CHOICE";	
		}
		else if (calculator == '3') {
			searchBMI();
			system ("pause");
		}
		else if (calculator == '4') {
			averageBMI();
			system ("pause");
		}
		else if (calculator == '5'){
			break; //to break out of a loop early
		}
	}					
}

void bmi_calc(float weight, float height)//function to calculate BMI
{
	float bmi;

	
	bmi= weight/ pow((height/100),2);
	
	cout << "\nYour BMI is :" << fixed << setprecision(2) << bmi;
	
	if (bmi < 18.5 ){
		cout << "\nUnderweight" << endl;
	}
	else if (bmi >= 25.0 && bmi < 30.0 ){
		cout << "\nOverweight" << endl;
	}
	else if (bmi >= 30.0 ){
		cout << "\nObese" << endl;
	}
	else{
		cout << "\nNormal Weight" << endl;
	}
}

void bmr_calc(float weight, float height, int age)//function to calculate BMR
{
	float bmr;
	char gender;
	
	while (gender!='F' && gender!= 'f' && gender!= 'M' && gender!= 'm'){	
	
		cout << "Please enter your gender ( F = Female | M = Male ) :";
		
		cin >> gender;
	
		if (gender=='F' || gender== 'f'){
		
			bmr= (10*weight)+(6.25*height)-(5*age)-161;
			cout << "\nYour BMR is :" << bmr << " calories/day\n";
		}
		else if (gender=='M' || gender=='m'){
			
			bmr= (10*weight)+(6.25*height)-(5*age)+5;
			cout << "\nYour BMR is :" << bmr << " calories/day\n";		
		}
	}
	cout << "\nINFO !";
	cout << "\n *Your BMR is the amount of energy your body needs to carry out the ";
	cout << "\n  most basic functions like breathing and digesting food.";
	cout << "\n *You shouldn't eat fewer calories as indicated by your BMR";
	cout << "\n  -otherwise you can experience adverse health effects.\n\n";
}

void searchBMI () //search BMI category
{
	system ("cls");
	string BMI[4]= {"underweight", "normal", "overweight", "obese"};
	int i;
	string searchCategory;
	
	cout << "---SEARCH BMI LEVEL---\n\n";
	cout << "Weight Category :\n";
	cout << " -underweight\n";
	cout << " -normal\n";
	cout << " -overweight\n";
	cout << " -obese\n";
	cout << "\nEnter your weight category [small letter only] : ";
	cin >> searchCategory;
	
	for (i=0; i<4; i++){
		if (searchCategory == BMI[i]){
			cout << "Your BMI category level is Level " << i + 1 <<endl;
			if (searchCategory == BMI[0]) {
				cout << "You need to gain weight by eating healthy food.\n\n";
			} else if (searchCategory == BMI[1]) {
				cout << "You are healthy. Good job!\n\n";
			} else if (searchCategory == BMI[2] || searchCategory == BMI[3]) {
				cout << "You need to lose weight by eating healthy food and exercise regularly.\n\n";
			} 
			break;
		}
		if (i== 4-1) {
			cout << "Not Found.\n\n";
			break;
		}
	}
}

void averageBMI() //calculate the average BMI in a year
{
	system ("cls");
	int i, maxBMI=0, minBMI=0;
	float bmi[12], sum=0.00, average;
	string month[12]= {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}, minMonth, maxMonth;
	
	cout << "-----AVERAGE BMI-----\n";
	cout << "\nEnter your BMI in " << endl;
	for ( i=0; i < 12; i++){
		cout << month[i] << ": ";
		cin >> bmi[i];
		sum += bmi[i];
	}
	average = sum / 12;
	
	for ( i = 0; i< 12; i++)
	{
		if (bmi[i] > bmi[maxBMI]){	
			maxBMI = i;
			maxMonth = month[i];
		}
		if (bmi[i] < bmi[minBMI]){
			minBMI =i ;
			minMonth = month[i];
		}
	}
	cout << "\nYour BMI is highest in " << maxMonth;
	cout << "\nYour BMI is lowest in " << minMonth;
	cout << "\nYour average BMI : " << fixed << setprecision(2) << average << endl;// program outputs decimal number to two decimal places
	cout << endl;
	
}
void fitnessShop ()//display total price ot he products
{	
	system ("cls");
	string productCode;
	int quantity;
	float totalPrice, grandTotalPrice=0, discount = 0, memberPrice = 0;
	char response = 'Y';
		
	displayPrice();
	
	while(response ==  'Y'|| response == 'y'){
		get_input(productCode, quantity);
		totalPrice = calcTotal(productCode,quantity);
		grandTotalPrice = grandTotalPrice + totalPrice;
	
		cout << "Do you want to buy other product? (Y / N) : ";
		cin >> response;
	}
	discount = member(grandTotalPrice);
	memberPrice = grandTotalPrice - discount;

	cout << "\nTotal price : RM " << fixed << setprecision(2) << grandTotalPrice << endl;
	cout << "Total price after discount : RM " << fixed << setprecision(2) << memberPrice << endl;
	cout << "Thank you for shopping with us !\n";

}

void displayPrice() //display the product and the price
{
	float productPrice[4] = {3200.60, 138.75, 1667.00, 250.99};
	
	cout << "----- ELITE FITNESS SHOP-----";
	cout << "\nWelcome to Elite Fitness Shop\n\n";
	cout << "Our Products : \n";	
	cout << "EHT - ELITE Hybrid Treadmill           : RM " << fixed << setprecision(2) << productPrice[0] << endl;	
	cout << "ERK - ELITE 14KG Rubberized Kettlebell : RM " << fixed << setprecision(2) << productPrice[1] << endl;	
	cout << "EIC - ELITE Indoor Cycling Bike        : RM " << fixed << setprecision(2) << productPrice[2] << endl;	
	cout << "EAS - ELITE 20KG Adjustable Dumbbell   : RM " << fixed << setprecision(2) << productPrice[3] << endl;
}

float get_input(string& productCode,int& quantity) //get the product and quantity from user
{
	cout << "\nEnter your product code : ";
	cin >> productCode;
	
	if (productCode=="EHT" || productCode=="ERK" || productCode=="EIC" || productCode=="EAS") {
	cout << "Enter the quantity : ";
	cin >> quantity;
	} else {
		cout << "Invalid Product Code !" << endl;
	}
}

float calcTotal(string productCode, int quantity) //calculate the total price
{
	float totalPrice;
	float productPrice[4] = {3200.60, 138.75, 1667.00, 250.99};
	
		if (productCode=="EHT") {
			totalPrice = productPrice[0] * quantity;
		}	
		else if (productCode=="ERK") {
			totalPrice = productPrice[1] * quantity;
		}
		else if (productCode=="EIC") {
			totalPrice = productPrice[2] * quantity;
		}
		else if (productCode=="EAS") {
			totalPrice = productPrice[3] * quantity;
		}
	return totalPrice;
}


float member(float grandTotalPrice)//calculate discount for member
{
	char memberCard;
	float discount;
	
	cout << "Do you have a membership card ? (Y / N): ";
	cin >> memberCard;
	
	if (memberCard == 'Y' || memberCard == 'y'){
		discount = 0.2 * grandTotalPrice;
	}
	else 
		discount = 0;
	return discount;
}

#include <iostream>
#include <fstream>
using namespace std;

// Function prototypes
int number_of_digits(long long n);
int isprime(int n);
int isperfect(int n);
int isfibonacci(int n);
// Global constant and arrays for storing results
const int array_size = 5;
int even_numbers[array_size];
int odd_numbers[array_size];
int prime_numbers[array_size];
int perfect_numbers[array_size];
int fibonacci_numbers[array_size];
// Counters for each category
int size_even = 0, size_odd = 0, size_prime = 0, size_perfect= 0, size_fibonacci = 0;

int main(){
  	// Open file for appending results
	ofstream file("./test.txt",ios::app);
	/*
	Integer in C++ is usually 32 bits.
	The largest number it can hold is 2147483647.
	But we want to input a 10 digit number like 1234567890 which is bigger.(overflow)
	When it overflows, cin fails and nothing is put in the number.
	That is why we used long long int.
	*/
	long long int number;
	
	// Will store the five 2-digit numbers
	int numbers[array_size];
	cout<<"Enter a ten-digit number: ";
	cin>>number;
	
	// Input must be positive
	if (number <0){
		cout<<"ERROR. Just positive numbers!";
		return 0;
	}
	
	// Input must be exactly 10 digits
	if(number_of_digits(number)!= 10){
	
		cout<<"ERROR. Just ten-digit numbers!";
		return 0;
	}
	// Keep original for output
	long long original_number = number;
	
	/* Split the 10-digit number into five 2-digit numbers
    Numbers are extracted from the right (least significant digits) and stored from index 4 to 0 */
	for(int j=4;j>=0;j--){
		numbers[j] = number % 100; //Extract last 2 digits
		number /= 100; //Remove last 2 digits
	}
	// Analyze each 2-digit number and categorize
	for(int j=0;j<5;j++){
		// Check even/odd
		if(numbers[j] % 2 == 0)
			even_numbers[size_even++] = numbers[j];
		else
			odd_numbers[size_odd++] = numbers[j];
		// Check prime
		if(isprime(numbers[j]))
			prime_numbers[size_prime++] = numbers[j];
		// Check perfect
		if(isperfect(numbers[j]))
			perfect_numbers[size_perfect++] = numbers[j];
		 // Check Fibonacci
		if(isfibonacci(numbers[j]))
			fibonacci_numbers[size_fibonacci++] = numbers[j];
			
	}
	
	//Display result on console
	cout<<"Number: "<<original_number<<endl;
	cout<<"Number of prime numbers: "<<size_prime<<" (";
	for(int i = 0; i < size_prime ; i++){
		if(i>0)
			cout<<",";
		cout << prime_numbers[i];
	}
    cout<<")"<<endl;
    cout<<"Number of perfect numbers: "<<size_perfect<<" (";
    for(int i = 0; i < size_perfect; i++){
    	if(i>0)
			cout<<",";
    	cout << perfect_numbers[i];
    }
    cout<<")"<<endl;
    cout<<"Number of even numbers: "<<size_even<<" (";
    for(int i = 0; i < size_even; i++){
    	if(i>0)
			cout<<",";
    	cout << even_numbers[i] ;
    }
    cout<<")"<<endl;
    cout<<"Number of odd numbers: "<<size_odd<<" (";
    for(int i = 0; i < size_odd; i++){
    	if(i>0)
			cout<<",";
    	cout << odd_numbers[i];
    }
    cout<<")"<<endl;
    cout<<"Number of fibonacci numbers: "<<size_fibonacci<<" (";
    for(int i = 0; i < size_fibonacci; i++){
    	if(i>0)
			cout<<",";	
    	cout << fibonacci_numbers[i] ;
    }
    cout<<")"<<endl;
			
	// Write result to file(same format as console output)
	file<<"Number: "<<original_number<<endl;
	file<<"Number of prime numbers: "<<size_prime<<" (";
	for(int i = 0; i < size_prime ; i++){
		if(i>0)
			file<<",";
		file << prime_numbers[i];
	}
    file<<")"<<endl;
    file<<"Number of perfect numbers: "<<size_perfect<<" (";
    for(int i = 0; i < size_perfect; i++){
    	if(i>0)
			file<<",";
    	file << perfect_numbers[i];
    }
    file<<")"<<endl;
    file<<"Number of even numbers: "<<size_even<<" (";
    for(int i = 0; i < size_even; i++){
    	if(i>0)
			file<<",";
    	file << even_numbers[i] ;
    }
    file<<")"<<endl;
    file<<"Number of odd numbers: "<<size_odd<<" (";
    for(int i = 0; i < size_odd; i++){
    	if(i>0)
			file<<",";
    	file << odd_numbers[i];
    }
    file<<")"<<endl;
    file<<"Number of fibonacci numbers: "<<size_fibonacci<<" (";
    for(int i = 0; i < size_fibonacci; i++){
    	if(i>0)
			file<<",";	
    	file << fibonacci_numbers[i] ;
    }
    file<<")"<<endl<<endl;
		
	file.close();	
	return 0;
}

/*
Calculates the number of digits in a given long long integer.
param n the number of analyze.
return the count of digits in n.
*/
int number_of_digits(long long n){
	int i;
	for(i=0;n>0;i++)
		n/= 10;
	return i;

}
/* 
Determines if a number is a prime number.
return 1(true) if n is a prime number, 0(false) otherwise.
*/
int isprime(int n){
	
	if (n<2)
		return 0;
	for(int i=2;n/2>=i;i++){
		if (n%i==0)
			return 0;
	}
	return 1;
		
}

/*
Determines if a number is a perfet number.
A perfect number equals the sum of its proper divisors(excluding itself).
return 1(true) if n is a perfect number, 0(false) otherwise.
*/
int isperfect(int n){
	int sum = 0;
	for(int i=1; n/2>=i;i++){
		if (n%i==0)
			sum+=i;
	}
	return sum == n;

}
/*
Determines if a number is part of the Fibonacci sequence
The sequence starts: 0,1,1,2,3,5,8,13, ...
return 1(true) if n is Fibonacci number, 0(false) otherwise.
*/
int isfibonacci(int n){
	int f1 = 0, f2 = 1,f3;
	
	if(n == 0 || n == 1)
		return 1;
	while(n>f2){
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	return n == f2;
	
}

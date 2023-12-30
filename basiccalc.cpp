#include<iostream>
#include<cmath>

using namespace std;

void printoptions();

int main() {
	float a, b, ans; // a: Number 1 b: Number 2 ans: Answer
	int c; // Choice
	int d;
	do {
	cout << "Enter 2 numbers!\n";
	cout << "First Number: ";
	cin >> a;
	cout << "Second Number: ";
	cin >> b;
	
		printoptions();
		cin >> c; // Choice
		switch (c) {
		case 1: // Add
			cout << a << '+' << b << '=' << a + b << endl;
			break;
		case 2: // Subtract
			cout << a << '-' << b << '=' << a - b << endl;
			break;
		case 3: // Divide
			cout << a << '/' << b << '=' << a / b << endl;
			break;
		case 4: // Random
			cout << "Answer: " << ((a + b) * (sqrt(a * b) + pow(a, b))) << endl;
			break;
		default:
			cout << "Invalid Input Try Again\n";
			break;
		}
		cout << "Try another calculation?\n (1): Yes\n (0): No\n";
		cin >> d;
	} while (d == 1);
}

void printoptions() {
	cout << "What would you like to do!\n (1): Add \n (2): Subtract\n (3): Divide \n (4): Random Formula\n";
}

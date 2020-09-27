#include <iostream>
using namespace std;

// Prototype for the swap function.
void swap(int& rNum1, int& rNum2);

int main()
{
	int num1 = 5, num2 = 10;

	// Output the current contents of the variables.
	cout << "MAIN: Before swap." << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl << endl;

	//Call the swap function and pass through the variables using their addresses.
	swap(num1, num2);

	// Output the current contents of the variables.
	cout << "MAIN: After swap." << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl << endl;

	// Pause for input.
	cin.get();

	return 0;
}

void swap(int& rNum1, int& rNum2)
{
	// We need a temporary variable to hold a value whilst we swap.
	int temp;

	// Output the current contents of the variables.
	cout << "SWAP: Before swap." << endl;
	cout << "rNum1 = " << rNum1 << endl;
	cout << "rNum2 = " << rNum2 << endl << endl;

	// Do the actual swap.
	temp = rNum1;
	rNum1 = rNum2;
	rNum2 = temp;

	// Output the current contents of the variables.
	cout << "SWAP: After swap." << endl;
	cout << "rNum1 = " << rNum1 << endl;
	cout << "rNum2 = " << rNum2 << endl << endl;
}

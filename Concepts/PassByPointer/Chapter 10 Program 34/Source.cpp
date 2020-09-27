#include <iostream>
using namespace std;

// Prototype for the swap function.
void swap(int* pNum1, int* pNum2);

int main()
{
	int num1 = 5, num2 = 10;

	// Output the current contents of the variables.
	cout << "MAIN: Before swap." << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl << endl;

	//Call the swap function and pass through the variables using their addresses.
	swap(&num1, &num2);

	// Output the current contents of the variables.
	cout << "MAIN: After swap." << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl << endl;

	// Pause for input.
	cin.get();

	return 0;
}

void swap(int* pNum1, int* pNum2)
{
	// We need a temporary variable to hold a value whilst we swap.
	int temp;

	// Output the current contents of the variables.
	cout << "SWAP: Before swap." << endl;
	cout << " * pNum1 = " << *pNum1 << endl;
	cout << " * pNum2 = " << *pNum2 << endl << endl;

	// Do the actual swap.
	temp = *pNum1;
	*pNum1 = *pNum2;
	*pNum2 = temp;

	// Output the current contents of the variables.
	cout << "SWAP: After swap." << endl;
	cout << " * pNum1 = " << *pNum1 << endl;
	cout << " * pNum2 = " << *pNum2 << endl << endl;
}

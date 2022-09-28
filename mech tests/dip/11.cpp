// CPP program for count total zero in product of array
#include <iostream>
using namespace std;

// Returns count of zeros in product of array
int countZeros(int a[], int n)
{
	int count2 = 0, count5 = 0;
	for (int i = 0; i < n; i++) {

		while (a[i] % 2 == 0) {
			a[i] = a[i] / 2;
			count2++;
		}

		// count number of 5s in each element
		while (a[i] % 5 == 0) {
			a[i] = a[i] / 5;
			count5++;
		}
	}
	// return the minimum
	return (count2 < count5) ? count2 : count5;
}

// Driven Program
int main()
{
	int a[] = { 10, 100, 20, 30, 50, 90, 12, 80 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << countZeros(a, n);
	return 0;
}

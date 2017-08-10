#include <iostream>
#include "DateTime.h"
using namespace std;

int main()
{
    DateTime d;
    cout << endl;
	cout << d.getCurrentLocalDate() << endl;
    cout << d.getUTCTime() << endl;
	return 0;
}

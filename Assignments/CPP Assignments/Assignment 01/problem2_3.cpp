#include <iostream>
using namespace std;

int main(){
	int statusReg  = 0b10110001;   // Read-only from firmware side
	int controlReg = 0b00000000;   // Firmware writes here
	int dataReg    = 0b11001010;   // For reassignment demo

    // Pointer to constant integer
	const int* regPtr1 = &statusReg;
//	*regPtr1 = 0b11001010; (write - error)
//	error: assignment of read-only location '* regPtr1'
//  because regPtr1 is a pointer to const int.


// regPtr1 = &dataReg; (repoint - successful)
// cout << "Status Register: " << *regPtr1 << endl;
// Repoint attempt
// This is NOT an error.
// Repointing is allowed because regPtr1 itself is not const.


// Constant pointer to integer
	int* const regPtr2 = &controlReg;

    
/*

	*regPtr2 = 0b11001010; (write - successful)
	cout << "ControlReg after write: " << *regPtr2 << endl;

	regPtr2 = &dataReg; (repoint - error)
	error: assignment of read-only variable 'regPtr2'
*/


// Constant pointer to constant integer
	const int* const regPtr3 = &statusReg;
/*

*regPtr3 = 0b11001010; (write - error)
error: Neither read-only location, Nor read-only variable '* regPtr1'
because both integer and pointer is constant./

regPtr3 = &dataReg;
error: Neither read-only location, Nor read-only variable '* regPtr1'
because both integer and pointer is constant.

*/



	return 0;
}

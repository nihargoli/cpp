#include "accounts.h"
		//long int *acc_no;
		//int acc_type;
		//int acc_pin;
		//long int *acc_bal;
bool set_acc_no( long int *account_no ) {
	acc_no = account_no;
}

bool set_acc_type( int ) {

}

bool set_balance( long int *balance) {
	acc_bal = balance;
}

bool set_pin( int *pin) {
	acc_pin = pin;
}


long int account::get_acc_no() { 
	return *acc_no
} 

int account::get_acc_type() {
	//
}

long int account::get_available_balance() {
	return *acc_bal
}

int account::get_pin() {
	return *acc_pin
}

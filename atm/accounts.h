/*
 Class holding account details
*/

#ifndef _acc_class_h
#define _acc_class_h
using namespace std;
#include <string>
#include <iostream>
enum account_type {
	SAVINS = 0,
	CURRENT = 1
};

class account {
	private:
		string acc_no;
		long int acc_bal = 0;
		int acc_type;
		string acc_pin;
	public:	
		bool set_no( string account_no ) {
			acc_no = account_no;
		}
		
		bool set_type( int ) {
		
		}
		
		bool set_balance( long int balance ) {
			acc_bal = balance;
		}

		
		bool set_pin( string pin ) {
			acc_pin = pin;
		}
		
		string get_no() { 
			return acc_no;
		} 
		
		int get_type() {
		
		}
		
		long int get_balance() {
			return acc_bal;
		}
		
		string get_pin() {
			return acc_pin;
		}

};
#endif

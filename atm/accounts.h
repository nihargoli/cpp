#ifndef _acc_class_h
#define _acc_class_h
enum account_type {
	SAVINS = 0,
	CURRENT = 1
};
class account {
	private:
		long int acc_no;
		long int acc_bal = 0;
		int acc_type;
		int acc_pin;
	public:	
		bool set_no( long int account_no ) {
			acc_no = account_no;
		}
		
		bool set_type( int ) {
		
		}
		
		bool set_balance( long int balance ) {
			acc_bal = acc_bal + balance;
		}

		bool withdraw_balance ( long int amt ) {
			if ( amt > acc_bal )
				return false;
			else {  
				//if ( dispense_cash ( ) )
				//set_balance ( acc_bal - amt );
				acc_bal  = acc_bal - amt;
				return true;
			}
		}
		
		bool set_pin( int pin ) {
			acc_pin = pin;
		}
		
		
		long int get_no() { 
			return acc_no;
		} 
		
		int get_type() {
		
		}
		
		long int get_balance() {
			return acc_bal;
		}
		
		int get_pin() {
			return acc_pin;
		}

};
#endif

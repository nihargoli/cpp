#ifndef _acc_class_h
#define _acc_class_h
enum account_type {
	SAVINS = 0,
	CURRENT = 1
};
class account {
	private:
		long int acc_no;
		int acc_type;
		int pin;
	protected:
		long int get_acc_no();
		int  get_acc_type();
		long int get_available_balance();
		int get_pin();
};
#endif

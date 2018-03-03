#ifndef _acc_class_h
#define _acc_class_h
enum account_type {
	SAVINS = 0,
	CURRENT = 1
};
class account {
	private:
		long int *acc_no;
		long int *acc_bal;
		int      acc_type;
		int      *acc_pin;
	protected:
		bool set_acc_no( long int * );
		bool set_acc_type( int );
		bool set_balance( long int * );
		bool set_pin( int * );
		long int get_acc_no();
		int  get_acc_type();
		long int get_available_balance();
		int get_pin();
};
#endif

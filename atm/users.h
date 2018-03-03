#include "accounts.h"
#ifndef _users_h
#define _users_h

class users {
	private: 
		class accounts::account a1;
	public:
		bool fill_account_details();
		bool load_cash();
		int withdraw_cash();
		long int check_balance();
		int change_pin();
};

#endif

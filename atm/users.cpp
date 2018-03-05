#include "users.h"
using namespace std;
#include <string>

bool users::fill_account_details( class account *acc ){
	users::user_acc = acc;	
}
                
bool users::load_cash( long int amt ) {
	users::user_acc->set_balance ( (users::user_acc->get_balance()) + amt );
}
                
bool users::withdraw_cash ( long int amt ) {
	if ( amt > users::user_acc->get_balance() )
		return false;
	else {  
		users::user_acc->set_balance ( (users::user_acc->get_balance()) - amt );
		return true;
	}
}

long int users::check_balance() { 
	return ( users::user_acc->get_balance() );
}
                
bool users::change_pin( string pin ) { 
	users::user_acc->set_pin( pin );
	return true;
}

bool users::validate_pin( string pin ) {
	if ( users::user_acc->get_pin() == pin )
		return true;
	else
		return false;
}


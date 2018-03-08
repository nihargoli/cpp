#ifndef _test_
#define _test_
#include <iostream>
using namespace std;

//ATM state interface.
class atm_state {
	public:
		virtual atm_state* get_next_state( ) = 0;
		virtual void display_messages() = 0;	
};

//ATM context to drive state machine
class atm_context {
	public:
		//atm_context();
		atm_context(atm_state *st) {
			a_state = st;
		}
		//~atm_context();
		void state_change() {
			if ( a_state ) {
				atm_state *next_state = a_state->get_next_state ( );
				delete a_state;
				a_state = next_state;
			}
		}
		void display_helper() {
			a_state->display_messages();
		}
	protected:
		// Pointer holding current atm state
		atm_state *a_state;
		
};

//Created when program exits
class card_ejected: public atm_state {
	public:
		virtual atm_state* get_next_state ( ) {
			return new card_ejected;
		}
		virtual void display_messages() {
			cout<<"card_ejeceted"<<endl;
		}
};

//created after card validation
class card_validated: public atm_state {
	public:
		virtual atm_state* get_next_state ( ) {
			return new card_ejected;
		}
		virtual void display_messages() {
			std::cout<<"What would you like to do?"<<endl;
			std::cout<<"1.Load cash"<< endl <<"2.Withdraw cash"<< endl <<"3.Change Pin"<< endl <<"4.Check Available balance"<< endl <<"5.Eject & Exit"<< endl;
		}
		bool print_receipt() {

		}
		void display_denominations() {

		}
};

//Initial state
class no_card_inserted: public atm_state {
	public:
		virtual atm_state* get_next_state ( ) {
			return new card_validated;
		}
		virtual void display_messages() {
			std::cout<<"==============================================================="\
			<<endl;
			std::cout<<"Welcome!" << endl\
			<<"Please insert card(Just insert account now to proceed for now)"\
			<< endl;
		}
		bool print_receipt() {

		}
		void display_denominations() {

		}
};
#endif

/*
int main()
{
	atm_context a ( new no_card_inserted );
	a.helper();
	a.state_changed();
	a.helper();
	a.state_changed();
	a.helper();
}
*/

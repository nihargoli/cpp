/*
 Unused in the code
*/
#include "atm.h"
using namespace std;
#include "iostream"

//Arguments: None
//Displays available options for user
void atm::display_menu() {
	std::cout<<"What would you like to do?"<<endl;
	std::cout<<"1.Load cash"<< endl <<"2.Withdraw cash"<< endl <<"3.Change Pin"<< endl <<"4.Check Available balance"<< endl <<"5.Exit"<< endl;
}

void atm::display_denominations() {

}

bool atm::validate_card() {

}

bool atm::print_receipt() {

}

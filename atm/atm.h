#include "atm_tasks.h"

#ifndef _atm_h
#define _atm_h

class atm: public atm_tasks_interface {
public:
	void display_menu();
	void display_denominations();
	bool validate_card();
	bool print_receipt();
};

#endif

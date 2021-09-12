#include "Hashing.h"
#include "HashingSeparateChaining.h"
#include "HashingLinearProbing.h"
#include "HashingQuadraticProbing.h"
#include "HashingDoubleHashing.h"

void test_hashing ()
{
	Hashing h(50);
	h.insert_data (545);
	h.insert_data (78);
	h.insert_data (65);
	h.insert_data (99);
	h.insert_data (476);
	h.insert_data (688);
	h.insert_data (913);
	h.print_element ();
	h.search_data (67);
	h.search_data (545);
	h.search_data (476);
	h.search_data (913);
	h.delete_data (545);
	h.delete_data (78);
	h.delete_data (65);
	h.delete_data (99);
	h.delete_data (476);
	h.delete_data (688);
	h.delete_data (913);
}

void test_hashing_separate_chaining ()
{
	HashingSeparateChaining h;
	h.print_element ();
	h.insert_data (45);
	h.insert_data (145);
	h.insert_data (345);
	h.insert_data (454);
	h.insert_data (456);
	h.insert_data (458);
	h.insert_data (449);
	h.insert_data (450);
	h.print_element ();
	h.search_data (913);
	h.search_data (450);
	h.search_data (45);
	h.delete_data (913);
	h.delete_data (345);
}

void test_hashing_linear_probing ()
{
	HashingLinearProbing h (100);
	h.print_element ();
	h.insert_data (45);
	h.insert_data (145);
	h.insert_data (345);
	h.insert_data (454);
	h.insert_data (456);
	h.insert_data (458);
	h.insert_data (449);
	h.insert_data (450);
	h.print_element ();
	h.search_data (913);
	h.search_data (450);
	h.search_data (45);
	h.delete_data (913);
	h.delete_data (345);
}

void test_hashing_quadratic_probing ()
{
	HashingQuadraticProbing h (100);
	h.print_element ();
	h.insert_data (45);
	h.insert_data (145);
	h.insert_data (345);
	h.insert_data (454);
	h.insert_data (456);
	h.insert_data (458);
	h.insert_data (449);
	h.insert_data (450);
	h.print_element ();
	h.search_data (913);
	h.search_data (450);
	h.search_data (45);
	h.delete_data (913);
	h.delete_data (345);
}

void test_hashing_double_hashing ()
{
	HashingDoubleHashing h (100);
	h.print_element ();
	h.insert_data (45);
	h.insert_data (145);
	h.insert_data (345);
	h.insert_data (454);
	h.insert_data (456);
	h.insert_data (458);
	h.insert_data (449);
	h.insert_data (450);
	h.print_element ();
	h.search_data (913);
	h.search_data (450);
	h.search_data (45);
	h.delete_data (913);
	h.delete_data (345);
}

int main ()
{
	//test_hashing ();
	//test_hashing_separate_chaining ();
	//test_hashing_linear_probing ();
	//test_hashing_quadratic_probing ();
	test_hashing_double_hashing ();
}
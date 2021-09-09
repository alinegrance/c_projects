#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "unidade3.h"

//builda um customer pra teste.
CUSTOMER build_customer(char* name, int day, int month, int year, double expenses) {
    CUSTOMER customer;
    
    strncpy(customer.name, name, MAX_NAME);
    customer.birthday.day = day;
    customer.birthday.month = month;
    customer.birthday.year = year;
    customer.expenses = expenses;

    return customer;
}

bool test_build_customers() {
    CUSTOMERS customers = build_customers(10);
    
    return (customers.list != NULL) && (customers.capacity == 10) && (customers.size == 0);
}

bool test_build_customers_fail() {
    CUSTOMERS customers = build_customers(-1);
    
    return (customers.list == NULL) && (customers.capacity == 0) && (customers.size == 0);
}

//teste.
bool test_highest_expender() {
    CUSTOMERS customers = build_customers(3);

    CUSTOMER maria = build_customer("Maria", 1, 1, 1991, 10.0);
    CUSTOMER john = build_customer("John", 2, 2, 1992, 10.0);
    CUSTOMER peter = build_customer("Peter", 3, 3, 1993, 10.0);

    insert_customer(&customers, maria);
    insert_customer(&customers, john);
    insert_customer(&customers, peter);

    CUSTOMER* customer = find_highest_expender(&customers);

    return strcmp(customer->name, "Maria") == 0;
}

//teste.
bool test_insert_customer() {
    CUSTOMERS customers = build_customers(3);

    CUSTOMER maria = build_customer("Maria", 1, 1, 1991, 10.0);
    CUSTOMER john = build_customer("John", 2, 2, 1992, 10.0);
    CUSTOMER peter = build_customer("Peter", 3, 3, 1993, 10.0);

    insert_customer(&customers, maria);
    insert_customer(&customers, john);
    insert_customer(&customers, peter);

    return (strcmp(customers.list[0].name, "Maria") == 0)
            && (strcmp(customers.list[1].name, "John") == 0)
            && (strcmp(customers.list[2].name, "Peter") == 0)
            && (customers.size == 3);
}

bool test_remove_customer() {
    CUSTOMERS customers = build_customers(3);

    CUSTOMER maria = build_customer("Maria", 1, 1, 1991, 10.0);
    CUSTOMER john = build_customer("John", 2, 2, 1992, 10.0);
    CUSTOMER peter = build_customer("Peter", 3, 3, 1993, 10.0);

    insert_customer(&customers, maria);
    insert_customer(&customers, john);
    insert_customer(&customers, peter);

    remove_customer(&customers, john.name);

    return (strcmp(customers.list[0].name, maria.name) == 0)
            && (strcmp(customers.list[1].name, peter.name) == 0)
            && (customers.size == 2);
}

bool test_insert_expenses() {
    CUSTOMERS customers = build_customers(3);

    CUSTOMER maria = build_customer("Maria", 1, 1, 1991, 10.0);
    CUSTOMER john = build_customer("John", 2, 2, 1992, 10.0);
    CUSTOMER peter = build_customer("Peter", 3, 3, 1993, 10.0);

    insert_customer(&customers, maria);
    insert_customer(&customers, john);
    insert_customer(&customers, peter);

    bool result = insert_expenses(&customers, john.name, 200.00);

    return (customers.list[1].expenses == 210.00) && result;
}

bool test_reset_expenses() {
    CUSTOMERS customers = build_customers(3);

    CUSTOMER maria = build_customer("Maria", 1, 1, 1991, 10.0);
    CUSTOMER john = build_customer("John", 2, 2, 1992, 10.0);
    CUSTOMER peter = build_customer("Peter", 3, 3, 1993, 10.0);

    insert_customer(&customers, maria);
    insert_customer(&customers, john);
    insert_customer(&customers, peter);

    bool result = reset_expenses(&customers, john.name);

    return (customers.list[1].expenses == 0.0) && result;
}

void main() {
    printf("%d\n", test_highest_expender());
    printf("%d\n", test_insert_customer());
    printf("%d\n", test_remove_customer());
    printf("%d\n", test_build_customers());
    printf("%d\n", test_build_customers_fail());
    printf("%d\n", test_insert_expenses());
    printf("%d\n", test_reset_expenses());
}

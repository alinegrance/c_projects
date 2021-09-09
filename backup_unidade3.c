#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define EXIT 0

#define MAX_NAME 30

#define CAPACITY 10
#define CAPACITY_INCREMENT 10

typedef struct date{
    int day;
    int month;
    int year;
} DATE;

typedef struct customer {
    char name[MAX_NAME];
    DATE birthday;
    double expenses;
} CUSTOMER;

typedef struct customers {
    CUSTOMER* list;
    int size;
    int capacity;
} CUSTOMERS;

void remove_newline(char* s) {
    s[strlen(s) - 1] = '\0';
}

CUSTOMERS build_customers(int capacity) {
    
    CUSTOMERS customers;
    customers.list = (CUSTOMER*) malloc(capacity * sizeof(CUSTOMER));
    
    if(customers.list == NULL) {
        customers.size = 0;
        customers.capacity = 0;

    } else {
        customers.size = 0;
        customers.capacity = capacity;
    }

    return customers;
}

bool is_empty(CUSTOMERS* customers) {
    return (bool) customers->size == 0;
}

CUSTOMER read_customer() {
    CUSTOMER customer;

    printf("Customer name: ");
    fgets(customer.name, MAX_NAME, stdin);
    remove_newline(customer.name);
    
    printf("Birthday [dd mm YYYY]: ");
    scanf("%d %d %d", &customer.birthday.day, &customer.birthday.month, &customer.birthday.year);
    fflush(stdin);

    customer.expenses = 0.0;

    return customer;
}

void read_name(char* s) {
    printf("Customer name: ");
    fgets(s, MAX_NAME, stdin);
    remove_newline(s);
}

double read_value() {
    double n;
    printf("insert value: ");
    scanf("%lf", &n);
    return n;
}

bool insert_customer(CUSTOMERS* customers, CUSTOMER customer) {
    if (customers->size < customers->capacity) {
        customers->list[customers->size] = customer;
        customers->size++;

        return true;
    } else {
        customers->list = (CUSTOMER*) realloc(customers->list, (customers->capacity + CAPACITY_INCREMENT) * sizeof(CUSTOMER));       
        if (customers->list == NULL) {
            customers->size = 0;
            customers->capacity = 0;

            return false;
        } else {
            customers->capacity += CAPACITY_INCREMENT;
            insert_customer(customers, customer);
        }
    }
}

void do_insert_customer(CUSTOMERS* customers, CUSTOMER customer) {
    bool ok = insert_customer(customers, customer);

    if (ok) {
        printf("Costumer inserted successfuly.\n");
        printf("----------------------------------------------------\n");
    }
}

CUSTOMER* find_customer_by_name(CUSTOMERS* customers, char* name) {
    for(int i = 0; i < customers->size; i++) {
        if(strcmp(name, customers->list[i].name) == 0) {
            return &(customers->list[i]);
        }
    }
    return NULL;
}

bool remove_customer(CUSTOMERS* customers, char* name) {

    for(int i = 0; i < customers->size; i++) {
        int cmp = strcmp(name, customers->list[i].name);
        if(cmp == 0) {
            for(int j = i; j < customers->size-1; j++) {
                customers->list[j] = customers->list[j+1];          
            }
            customers->size--;
            return true;  
        }
    }  
    return false;
}

void do_remove_customer(CUSTOMERS* customers) {
    char name[MAX_NAME];

    if(is_empty(customers)){
        printf("list of customers is empty.\n");
    } else{
        read_name(name);
        remove_customer(customers, name);

        if(remove_customer) {
            printf("Customer removed successfully.\n");
        } else{
            printf("Customer not found");
        }
    }
    printf("----------------------------------------------------\n");
}

void print_customer(CUSTOMER customer) {
    printf("Name: %s\n", customer.name);
    printf("Birthday: %d/%d/%d\n", 
            customer.birthday.day, customer.birthday.month, customer.birthday.year);
    printf("Total expenses: %.2lf\n", customer.expenses);
    printf("----------------------------------------------------\n");

}

void print_customers(CUSTOMERS* customers) {
    if(is_empty(customers)){
        printf("list of customers is empty.\n");
        printf("----------------------------------------------------\n");
    } else {
        for(int i = 0; i < customers->size; i++) {     
            print_customer(customers->list[i]);
        }
    }
}

bool insert_expenses(CUSTOMERS* customers, char* name, double new_expense) {
    for(int i = 0; i < customers->size; i++) {
        int cmp = strcmp(name, customers->list[i].name);
        if(cmp == 0) {
            customers->list[i].expenses += new_expense;
            return true;
        } 
    }
    return false;
}

void do_insert_expenses(CUSTOMERS* customers) {
    char name[MAX_NAME];
    double new_expense;

    if(is_empty(customers)) {
        printf("list of customers is empty.\n");
        printf("----------------------------------------------------\n");
    } else {
        read_name(name);
        new_expense = read_value();
        insert_expenses(customers, name, new_expense);
        if(!insert_expenses){
            printf("Customer not found.\n");
            printf("----------------------------------------------------\n");
        } else {
            printf("Expense added\n");
            printf("----------------------------------------------------\n");
        }
    } 
}

bool reset_expenses(CUSTOMERS* customers, char* name) {
   
        for(int i = 0; i < customers->size; i++) {
            int cmp = strcmp(name, customers->list[i].name);
            if(cmp == 0) {
                customers->list[i].expenses = 0.0;
                return true;
            } 
        }
        return false;
}

void do_reset_expenses(CUSTOMERS* customers) {
    char name[MAX_NAME];
    read_name(name);

    if(is_empty(customers)){
        printf("list of customers is empty.\n");
    } else {
        reset_expenses(customers, name);
        if(!reset_expenses){
            printf("Fail removing expenses.\n");
        } else {
            printf("Expenses removed successfully.\n");
        }
    }
    printf("----------------------------------------------------\n");
}

void print_customer_expenses(CUSTOMERS* customers) {
    char name[MAX_NAME];
    CUSTOMER* customer;

    if(is_empty(customers)){
        printf("list of customers is empty.\n");
    } else {
        read_name(name);
        customer = find_customer_by_name(customers, name);
        if(customer == NULL){
            printf("Customer not found.\n");
            
        } else {
            printf("%s's total expenses: %.2lf\n", customer->name, customer->expenses);
        }       
    }
    printf("----------------------------------------------------\n");
}

CUSTOMER* find_highest_expender(CUSTOMERS* customers) {
    double highest_value;
    int i, customer_index = 0;

    if(!is_empty(customers)) {
        highest_value = customers->list[0].expenses;

        for(i = 0; i < customers->size; i++) {
            if(customers->list[i].expenses > highest_value) { 
                customer_index = i;
            }
        }
        return &(customers->list[customer_index]);
    } else {
        return NULL;
    }
}

void do_find_highest_expender(CUSTOMERS* customers) {
    CUSTOMER* highest_expender = find_highest_expender(customers);

    if (highest_expender == NULL) {
        printf("List of customers is empty.\n");
        printf("----------------------------------------------------\n");
    } else {
        print_customer(*highest_expender);
    }
}

void display_options() {
    printf("Welcome, choose one of the options above:\n");
    printf("1-Insert new customer\n");
    printf("2-Insert customer expenses\n");
    printf("3-Remove total expenses from a customer\n");
    printf("4-Display an especific customer's expenses.\n");
    printf("5-Remove customer\n");
    printf("6-List customers\n");
    printf("7-Display highest expender\n");
    printf("0-sair do programa\n");
    printf("----------------------------------------------------\n");
}

int read_option() {
    int option;
    scanf("%d", &option);
    getchar();

    return option;              
}

int main2() {
    int option;
    double highest_expense;

    CUSTOMERS customers = build_customers(CAPACITY);      

    if (customers.list == NULL) {
        exit(1);
    }

    do {
        display_options();
        option = read_option();

        switch(option) {
            case 1:          
                do_insert_customer(&customers,read_customer());
                printf("----------------------------------------------------\n");   
                
                break;

            case 2:
                do_insert_expenses(&customers); 
                printf("----------------------------------------------------\n");   
                break;
            
            case 3:
                do_reset_expenses(&customers);
                printf("----------------------------------------------------\n");   
                break;
            
            case 4:
                print_customer_expenses(&customers);
                printf("----------------------------------------------------\n");
                break;
            
            case 5:
                do_remove_customer(&customers);
                printf("----------------------------------------------------\n");   
                break;
                
            case 6:
                print_customers(&customers);
                printf("----------------------------------------------------\n");   
                break;

            case 7:
                do_find_highest_expender(&customers);
                printf("----------------------------------------------------\n");
                break;
            
            case 0:
                printf("Exiting program.\n");
                printf("----------------------------------------------------\n");   
                break;

            default:
                printf("Invalid option.\n");
                printf("----------------------------------------------------\n");
        }

    } while(option != EXIT);

    return 0;
}
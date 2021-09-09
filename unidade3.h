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

CUSTOMERS build_customers(int capacity);
bool insert_customer(CUSTOMERS* customers, CUSTOMER customer);
bool remove_customer(CUSTOMERS* customers, char* name);
bool insert_expenses(CUSTOMERS* customers, char* name, double new_expense);
bool reset_expenses(CUSTOMERS* customers, char* name);
CUSTOMER* find_highest_expender(CUSTOMERS* customers);

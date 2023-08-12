#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ID_LEN 7
#define MAX_CAPACITY 10

typedef struct Person {
    char name[100];
    char id[ID_LEN];
    unsigned int birthYear : 12;
    unsigned int birthMonth : 5;
    unsigned int birthDay : 5;
    unsigned int gender : 1;
} Person;

void* initArray(size_t capacity);
int addPerson(char *name, unsigned short birthYear, unsigned char birthDay, char gender);
void readPerson();
int printPerson(char *id);

Person *People;
static unsigned int Person_count = 0;

int main() {
    People = initArray(MAX_CAPACITY);
    addPerson("Stafan Popov", 1990, 15, 0);
    addPerson("Maria Georgieva", 1985, 25, 1);
    readPerson();
    printPerson(People[2].id);

    free(People);

    return 0;
}

void* initArray(size_t capacity) {
    return malloc(capacity * sizeof(Person));
}

int addPerson(char *name, unsigned short birthYear, unsigned char birthDay, char gender) {
    if (Person_count < MAX_CAPACITY) {
        strcpy(People[Person_count].name, name);
        People[Person_count].birthYear = birthYear;
        People[Person_count].birthDay = birthDay;
        People[Person_count].gender = gender;

        char name_prefix[3];
        strncpy(name_prefix, People[Person_count].name, 3);
        sprintf(People[Person_count].id, "%s%03d", name_prefix, Person_count + 1);

        Person_count++;
        return 0;
    } else {
        return -1;
    }
}

void readPerson() {
    char name[100];
    unsigned short birthYear;
    unsigned char birthDay;
    char gender;

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter birth year: ");
    scanf("%hu", &birthYear);

    printf("Enter birth day: ");
    scanf("%hhu", &birthDay);

    printf("Enter gender (0 for male, 1 for female): ");
    scanf(" %c", &gender);

    int result = addPerson(name, birthYear, birthDay, gender - '0');

    if (result == 0) {
        printf("Person added successfully!\n");
    } else {
        printf("Failed to add person. Maximum capacity exceeded.\n");
    }
}

int printPerson(char *id) {
    for (unsigned int i = 0; i < Person_count; i++) {
        if (strcmp(People[i].id, id) == 0) {
            printf("Name: %s\n", People[i].name);
            printf("ID: %s\n", People[i].id);
            printf("Birth Year: %hu\n", People[i].birthYear);
            printf("Birth Day: %hhu\n", People[i].birthDay);
            printf("Gender: %s\n", People[i].gender == 0 ? "Male" : "Female");
            return 1;
        }
    }

    printf("Person with ID %s not found.\n", id);
    return 0;
}

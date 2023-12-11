#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ROOMS 6
#define MAX_SCHEDULES 6
#define MAX_BOOKINGS 10
#define MAX_NIM_LENGTH 15
#define MAX_PASSWORD_LENGTH 20
#define MAX_CUSTOM_SCHEDULE_LENGTH 30

struct Booking {
    char room[20];
    char schedule[30];
};

struct User {
    char nim[MAX_NIM_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    struct Booking bookings[MAX_BOOKINGS];
    int bookingCount;
};

// Fungsi-fungsi utilitas
bool isValidNIM(const char nim[]) {
    char prefix[3];
    strncpy(prefix, nim, 2);
    prefix[2] = '\0';
    int year = atoi(prefix);

    return (year >= 20 && year <= 23);
}

int findUser(const char nim[], const struct User users[], int userCount) {
    for (int i = 0; i < userCount; ++i) {
        if (strcmp(users[i].nim, nim) == 0) {
            return i; // User found
        }
    }
    return -1; // User not found
}

void displaySchedule() {
    printf("\nJadwal kelas tersedia:\n");
    printf("1. MKB 1A\n");
    printf("2. MKB 1B\n");
    printf("3. MKB 1C\n");
    printf("4. LAB\n");
    printf("5. SMARTCLASS\n");
    printf("6. MKB 30\n");
}

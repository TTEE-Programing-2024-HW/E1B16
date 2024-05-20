#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 9
#define COLS 9
#define PASSWORD 2024

void displaySeats(char seats[ROWS][COLS]) {
    printf("  123456789\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", ROWS - i);
        for (int j = 0; j < COLS; j++) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

void clearScreen() {
    // 使用 ANSI escape code 清除螢幕
    printf("\033[H\033[J");
}

void initializeSeats(char seats[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            seats[i][j] = '-';
        }
    }

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (seats[r][c] == '-') {
            seats[r][c] = '*';
        } else {
            i--;
        }
    }
}

void welcomeScreen() {
    clearScreen();
    printf("****************************************\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*         Welcome to My Program        *\n");
    printf("*                                      *\n");
    printf("*           my name is hudson          *\n");
    printf("*                                      *\n");
    printf("*     My class seat number is E1B16    *\n");
    printf("*                                      *\n");
    printf("*        +------------------+          *\n");
    printf("*     |  [ Nice to meet you :) ]   |   *\n");
    printf("*        +------------------+          *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("****************************************\n");
}

int verifyPassword() {
    int password, attempts = 0;
    while (attempts < 3) {
        printf("請輸入4個數字的密碼 (預設為2024): ");
        scanf("%d", &password);
        if (password == PASSWORD) {
            printf("歡迎進入系統!\n");
            return 1;
        } else {
            printf("密碼錯誤!\n");
            attempts++;
        }
    }
    printf("密碼錯誤三次，系統鎖定。\n");
    return 0;
}

void availableSeats(char seats[ROWS][COLS]) {
    clearScreen();
    displaySeats(seats);
    printf("按任意鍵返回主選單...\n");
    getchar(); getchar();
}

void arrangeSeats(char seats[ROWS][COLS]) {
    int numSeats;
    printf("需要幾個座位 (1~4): ");
    scanf("%d", &numSeats);
    if (numSeats < 1 || numSeats > 4) {
        printf("輸入無效，請重新選擇。\n");
        return;
    }

    int found = 0;
    if (numSeats == 4) {
        for (int i = 0; i < ROWS - 1; i++) {
            for (int j = 0; j < COLS - 1; j++) {
                if (seats[i][j] == '-' && seats[i][j + 1] == '-' && seats[i + 1][j] == '-' && seats[i + 1][j + 1] == '-') {
                    seats[i][j] = seats[i][j + 1] = seats[i + 1][j] = seats[i + 1][j + 1] = '@';
                    found = 1;
                    break;
                }
            }
            if (found) break;
        }
    } else {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j <= COLS - numSeats; j++) {
                int k;
                for (k = 0; k < numSeats; k++) {
                    if (seats[i][j + k] != '-') break;
                }
                if (k == numSeats) {
                    for (k = 0; k < numSeats; k++) {
                        seats[i][j + k] = '@';
                    }
                    found = 1;
                    break;
                }
            }
            if (found) break;
        }
    }

    if (found) {
        displaySeats(seats);
        printf("是否滿意此安排? (y/n): ");
        char satisfied;
        scanf(" %c", &satisfied);
        if (satisfied == 'y') {
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    if (seats[i][j] == '@') seats[i][j] = '*';
                }
            }
        } else {
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    if (seats[i][j] == '@') seats[i][j] = '-';
                }
            }
        }
    } else {
        printf("無法找到足夠的連續座位。\n");
    }
    printf("按任意鍵返回主選單...\n");
    getchar(); getchar();
}

void chooseSeats(char seats[ROWS][COLS]) {
    int row, col;
    while (1) {
        clearScreen();
        displaySeats(seats);
        printf("請輸入座位選擇 (格式: 列-行，如1-2): ");
        char input[4];
        scanf("%s", input);
        if (sscanf(input, "%d-%d", &row, &col) != 2 || row < 1 || row > ROWS || col < 1 || col > COLS || seats[ROWS - row][col - 1] != '-') {
            printf("輸入無效或座位已被預訂，請重新輸入。\n");
        } else {
            seats[ROWS - row][col - 1] = '@';
            break;
        }
    }

    displaySeats(seats);
    printf("按任意鍵確認選擇並返回主選單...\n");
    getchar(); getchar();
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (seats[i][j] == '@') seats[i][j] = '*';
        }
    }
}

int main() {
    char seats[ROWS][COLS];
    char choice[2];

    initializeSeats(seats);

    welcomeScreen();

    if (!verifyPassword()) {
        return 1;
    }

    while (1) {
        clearScreen();
        printf("----------[BookingSystem]----------\n");
        printf("|  a. Available seats              |\n");
        printf("|  b. Arrange for you              |\n");
        printf("|  c. Choose by yourself           |\n");
        printf("|  d. Exit                         |\n");
        printf("------------------------------------\n");
        printf("選擇: ");
        scanf("%s", choice);

        if (choice[0] == 'a') {
            availableSeats(seats);
        } else if (choice[0] == 'b') {
            arrangeSeats(seats);
        } else if (choice[0] == 'c') {
            chooseSeats(seats);
        } else if (choice[0] == 'd') {
            printf("Continue? (y/n): ");
            char confirm;
            scanf(" %c", &confirm);
            if (confirm == 'n') {
                printf("程式結束，感謝使用！\n");
                break;
            }
        } else {
            printf("無效選擇，請重新輸入。\n");
        }
    }

    return 0;
}

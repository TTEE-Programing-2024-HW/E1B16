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
    // �ϥ� ANSI escape code �M���ù�
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
        printf("�п�J4�ӼƦr���K�X (�w�]��2024): ");
        scanf("%d", &password);
        if (password == PASSWORD) {
            printf("�w��i�J�t��!\n");
            return 1;
        } else {
            printf("�K�X���~!\n");
            attempts++;
        }
    }
    printf("�K�X���~�T���A�t����w�C\n");
    return 0;
}

void availableSeats(char seats[ROWS][COLS]) {
    clearScreen();
    displaySeats(seats);
    printf("�����N���^�D���...\n");
    getchar(); getchar();
}

void arrangeSeats(char seats[ROWS][COLS]) {
    int numSeats;
    printf("�ݭn�X�Ӯy�� (1~4): ");
    scanf("%d", &numSeats);
    if (numSeats < 1 || numSeats > 4) {
        printf("��J�L�ġA�Э��s��ܡC\n");
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
        printf("�O�_���N���w��? (y/n): ");
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
        printf("�L�k��쨬�����s��y��C\n");
    }
    printf("�����N���^�D���...\n");
    getchar(); getchar();
}

void chooseSeats(char seats[ROWS][COLS]) {
    int row, col;
    while (1) {
        clearScreen();
        displaySeats(seats);
        printf("�п�J�y���� (�榡: �C-��A�p1-2): ");
        char input[4];
        scanf("%s", input);
        if (sscanf(input, "%d-%d", &row, &col) != 2 || row < 1 || row > ROWS || col < 1 || col > COLS || seats[ROWS - row][col - 1] != '-') {
            printf("��J�L�ĩήy��w�Q�w�q�A�Э��s��J�C\n");
        } else {
            seats[ROWS - row][col - 1] = '@';
            break;
        }
    }

    displaySeats(seats);
    printf("�����N��T�{��ܨê�^�D���...\n");
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
        printf("���: ");
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
                printf("�{�������A�P�¨ϥΡI\n");
                break;
            }
        } else {
            printf("�L�Ŀ�ܡA�Э��s��J�C\n");
        }
    }

    return 0;
}

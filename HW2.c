#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    int password = 2024;
    int input_password;
    int attempts = 0;

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

    while (attempts < 3) {
        printf("請輸入4位數的密碼: ");
        scanf("%d", &input_password);

        if (input_password == password) {
            break;
        } else {
            attempts++;
            printf("密碼輸入錯誤，請再試一次。\n");
        }
    }

    if (attempts == 3) {
        printf("您已連續輸入錯誤三次,程式結束！\n");
        return 0;
    }

  
    system("cls");
    char choice;

    do {
        printf("--------------------------\n");
        printf("|  a. 畫出直角三角形    |\n");
        printf("|  b. 顯示乘法表        |\n");
        printf("|  c. 結束              |\n");
        printf("--------------------------\n");
        printf("請選擇: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
            case 'A': {
                system("cls");
                printf("請輸入'a'到'n'的字元: ");
                char character;
                scanf(" %c", &character);

                if (character < 'a' || character > 'n') {
                    printf("警告：請輸入'a'到'n'的字元！\n");
                } else {
                    system("cls");
                    printf("您輸入的字元為：%c\n", character);

            
                    for (char c = 'a'; c <= character; c++) {
                        for (char d = 'a'; d <= c; d++) {
                            printf("%c ", d);
                        }
                        printf("\n");
                    }

                    printf("\n按下任意鍵繼續...");
                    getch(); 
                    system("cls"); 
                }
                break;
            }
            case 'b':
            case 'B': {
                system("cls");
                int n;

                printf("請輸入1到9的整數n: ");
                scanf("%d", &n);

                if (n < 1 || n > 9) {
                    printf("警告：請輸入1到9的整數！\n");
                } else {
                    system("cls");
                    printf("乘法表（1*1 到 %d*%d）：\n\n", n, n);

                
                    for (int i = 1; i <= n; i++) {
                        for (int j = 1; j <= n; j++) {
                            printf("%d\t", i * j);
                        }
                        printf("\n");
                    }

                    printf("\n按下任意鍵繼續...");
                    getch(); 
                    system("cls"); 
                }
                break;
            }
            case 'c':
            case 'C': {
                char continue_choice;
                printf("Continue? (y/n): ");
                scanf(" %c", &continue_choice);

                if (continue_choice == 'n' || continue_choice == 'N') {
                    return 0;
                } else if (continue_choice != 'y' && continue_choice != 'Y') {
                    printf("錯誤的輸入！\n");
                }
                break;
            }
            default:
                printf("請選擇正確的選項！\n");
        }
    } while (choice != 'c' && choice != 'C');

    return 0;
}

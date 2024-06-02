#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10

// 定義學生資料結構
typedef struct {
    char name[50];
    int id;
    int math;
    int physics;
    int english;
    float average;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

// 函數宣告
void enter_grades();
void display_grades();
void search_grades();
void rank_grades();
void exit_system();
void calculate_average(Student *s);
void clearScreen();

int main() {
    int password = 2024;
    int attempt = 0;
    int input_password;
    printf(" ***************************************************\n");
    printf(" * 大家好我是:                                      *\n");
    printf(" * ______          _______          ________        *\n"); 
    printf(" * |         |     |      |    |    |               *\n");  
    printf(" * |         |     |      |    |    |               *\n");
    printf(" * |_____    |     |______/    |    |_______        *\n");
    printf(" * |         |     |      \\    |    |       |       *\n");  
    printf(" * |         |     |      |    |    |       |       *\n");
    printf(" * |_____    |     |______|    |    |_______|       *\n");
    printf(" *                                                  *\n");
    printf(" *                                    許顥薰    同學 *\n");
    printf("*****************************************************\n");
 
    printf("<<<<歡迎來到我的程式樂園>>>>\n");
    printf("請輸入enter鍵進入我的程式樂園吧!\n");

    getchar(); 
    clearScreen();          // 清除螢幕
    // 顯示畫面並要求輸入密碼
    while (attempt < 3) {
        clearScreen(); // 清除螢幕
        printf("***************************\n");
        printf("*   歡迎進入成績系統   *\n");
        printf("*   請輸入四位數密碼   *\n");
        printf("***************************\n");
        scanf("%d", &input_password);

        // 檢查密碼是否正確
        if (input_password == password) {
            // 如果正確，進入步驟2
            printf("密碼正確，歡迎使用成績系統！\n");
            system("pause"); 
            break;
        } else {
        
            attempt++;
            printf("密碼錯誤，請重新輸入。\n");
            system("pause");
        }
    }

    // 檢查嘗試次數，若達到上限則顯示警告並結束程式
    if (attempt == 3) {
        printf("您已連續錯誤三次，程式結束。\n");
        return 0;
    }

    // 步驟2：清除螢幕，顯示主選單
    char choice;
    while (1) {
        clearScreen(); // 清除螢幕
        printf("------------[Grade System]----------\n");
        printf("|  a. Enter student grades          |\n");
        printf("|  b. Display student grades        |\n");
        printf("|  c. Search for student grades     |\n");
        printf("|  d. Grade ranking                 |\n");
        printf("|  e. Exit system                   |\n");
        printf("------------------------------------\n");
        printf("請選擇: ");
        scanf(" %c", &choice);

        // 根據使用者選擇執行不同功能
        switch (choice) {
            case 'a':
            case 'A':
                enter_grades();
                break;

            case 'b':
            case 'B':
                display_grades();
                break;

            case 'c':
            case 'C':
                search_grades();
                break;

            case 'd':
            case 'D':
                rank_grades();
                break;

            case 'e':
            case 'E':
                exit_system();
                return 0;

            default:
                printf("無效的選擇，請重新輸入。\n");
                system("pause");
        }
    }

    return 0;
}

// 輸入學生成績
void enter_grades() {
    int n;
    clearScreen(); // 清除螢幕
    printf("請輸入學生人數 (5~10): ");
    scanf("%d", &n);

    // 檢查輸入的整數範圍
    if (n < 5 || n > 10) {
        printf("人數超出範圍，請重新輸入。\n");
        system("pause");
        return;
    }

    int i;
    for (i = 0; i < n; i++) {
        printf("輸入第%d位學生的資料:\n", i + 1);
        printf("姓名: ");
        scanf("%s", students[student_count].name);
        printf("學號(6位整數): ");
        scanf("%d", &students[student_count].id);
        printf("數學成績(0~100): ");
        scanf("%d", &students[student_count].math);
        printf("物理成績(0~100): ");
        scanf("%d", &students[student_count].physics);
        printf("英文成績(0~100): ");
        scanf("%d", &students[student_count].english);

        // 計算平均成績
        calculate_average(&students[student_count]);

        student_count++;
    }

    printf("輸入完畢，返回主選單。\n");
    system("pause");
}

// 顯示所有學生成績
void display_grades() {
    clearScreen(); // 清除螢幕
    printf("所有學生成績:\n");
    printf("姓名\t學號\t數學\t物理\t英文\t平均\n");

    int i;
    for (i = 0; i < student_count; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%.1f\n",
               students[i].name,
               students[i].id,
               students[i].math,
               students[i].physics,
               students[i].english,
               students[i].average);
    }

    printf("按任意鍵返回主選單...");
    getchar();
    getchar();
}

// 搜尋學生成績
void search_grades() {
    char search_name[50];
    clearScreen(); // 清除螢幕
    printf("請輸入要搜尋的學生姓名: ");
    scanf("%s", search_name);

    int i;
    for (i = 0; i < student_count; i++) {
        if (strcmp(students[i].name, search_name) == 0) {
            printf("姓名: %s\n", students[i].name);
            printf("學號: %d\n", students[i].id);
            printf("數學: %d\n", students[i].math);
            printf("物理: %d\n", students[i].physics);
            printf("英文: %d\n", students[i].english);
            printf("平均: %.1f\n", students[i].average);
            printf("按任意鍵返回主選單...");
            getchar();
            getchar();
            return;
        }
    }

    printf("資料不存在。\n");
    printf("按任意鍵返回主選單...");
    getchar();
    getchar();
}

// 成績排序並顯示
void rank_grades() {
    // 簡單的冒泡排序
    int i, j;
    for (i = 0; i < student_count - 1; i++) {
        for (j = 0; j < student_count - i - 1; j++) {
            if (students[j].average < students[j + 1].average) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    clearScreen(); // 清除螢幕
    printf("學生成績排名:\n");
    printf("姓名\t學號\t平均\n");

    for (i = 0; i < student_count; i++) {
        printf("%s\t%d\t%.1f\n", students[i].name, students[i].id, students[i].average);
    }

    printf("按任意鍵返回主選單...");
    getchar();
    getchar();
}

// 計算平均成績
void calculate_average(Student *s) {
    s->average = (s->math + s->physics + s->english) / 3.0;
}

// 退出系統
void exit_system() {
    char confirm;
    printf("確定離開？ (y/n): ");
    while (1) {
        scanf(" %c", &confirm);
        if (confirm == 'y' || confirm == 'Y') {
            printf("系統結束。\n");
            exit(0);
        } else if (confirm == 'n' || confirm == 'N') {
            break;
        } else {
            printf("無效的輸入，請輸入 'y' 或 'n': ");
        }
    }
}

// 清除螢幕函數實現
void clearScreen() {
    system("cls");
}


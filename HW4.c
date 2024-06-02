#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10

// �w�q�ǥ͸�Ƶ��c
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

// ��ƫŧi
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
    printf(" * �j�a�n�ڬO:                                      *\n");
    printf(" * ______          _______          ________        *\n"); 
    printf(" * |         |     |      |    |    |               *\n");  
    printf(" * |         |     |      |    |    |               *\n");
    printf(" * |_____    |     |______/    |    |_______        *\n");
    printf(" * |         |     |      \\    |    |       |       *\n");  
    printf(" * |         |     |      |    |    |       |       *\n");
    printf(" * |_____    |     |______|    |    |_______|       *\n");
    printf(" *                                                  *\n");
    printf(" *                                    �\�V��    �P�� *\n");
    printf("*****************************************************\n");
 
    printf("<<<<�w��Ө�ڪ��{���ֶ�>>>>\n");
    printf("�п�Jenter��i�J�ڪ��{���ֶ�a!\n");

    getchar(); 
    clearScreen();          // �M���ù�
    // ��ܵe���ín�D��J�K�X
    while (attempt < 3) {
        clearScreen(); // �M���ù�
        printf("***************************\n");
        printf("*   �w��i�J���Z�t��   *\n");
        printf("*   �п�J�|��ƱK�X   *\n");
        printf("***************************\n");
        scanf("%d", &input_password);

        // �ˬd�K�X�O�_���T
        if (input_password == password) {
            // �p�G���T�A�i�J�B�J2
            printf("�K�X���T�A�w��ϥΦ��Z�t�ΡI\n");
            system("pause"); 
            break;
        } else {
        
            attempt++;
            printf("�K�X���~�A�Э��s��J�C\n");
            system("pause");
        }
    }

    // �ˬd���զ��ơA�Y�F��W���h���ĵ�i�õ����{��
    if (attempt == 3) {
        printf("�z�w�s����~�T���A�{�������C\n");
        return 0;
    }

    // �B�J2�G�M���ù��A��ܥD���
    char choice;
    while (1) {
        clearScreen(); // �M���ù�
        printf("------------[Grade System]----------\n");
        printf("|  a. Enter student grades          |\n");
        printf("|  b. Display student grades        |\n");
        printf("|  c. Search for student grades     |\n");
        printf("|  d. Grade ranking                 |\n");
        printf("|  e. Exit system                   |\n");
        printf("------------------------------------\n");
        printf("�п��: ");
        scanf(" %c", &choice);

        // �ھڨϥΪ̿�ܰ��椣�P�\��
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
                printf("�L�Ī���ܡA�Э��s��J�C\n");
                system("pause");
        }
    }

    return 0;
}

// ��J�ǥͦ��Z
void enter_grades() {
    int n;
    clearScreen(); // �M���ù�
    printf("�п�J�ǥͤH�� (5~10): ");
    scanf("%d", &n);

    // �ˬd��J����ƽd��
    if (n < 5 || n > 10) {
        printf("�H�ƶW�X�d��A�Э��s��J�C\n");
        system("pause");
        return;
    }

    int i;
    for (i = 0; i < n; i++) {
        printf("��J��%d��ǥͪ����:\n", i + 1);
        printf("�m�W: ");
        scanf("%s", students[student_count].name);
        printf("�Ǹ�(6����): ");
        scanf("%d", &students[student_count].id);
        printf("�ƾǦ��Z(0~100): ");
        scanf("%d", &students[student_count].math);
        printf("���z���Z(0~100): ");
        scanf("%d", &students[student_count].physics);
        printf("�^�妨�Z(0~100): ");
        scanf("%d", &students[student_count].english);

        // �p�⥭�����Z
        calculate_average(&students[student_count]);

        student_count++;
    }

    printf("��J�����A��^�D���C\n");
    system("pause");
}

// ��ܩҦ��ǥͦ��Z
void display_grades() {
    clearScreen(); // �M���ù�
    printf("�Ҧ��ǥͦ��Z:\n");
    printf("�m�W\t�Ǹ�\t�ƾ�\t���z\t�^��\t����\n");

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

    printf("�����N���^�D���...");
    getchar();
    getchar();
}

// �j�M�ǥͦ��Z
void search_grades() {
    char search_name[50];
    clearScreen(); // �M���ù�
    printf("�п�J�n�j�M���ǥͩm�W: ");
    scanf("%s", search_name);

    int i;
    for (i = 0; i < student_count; i++) {
        if (strcmp(students[i].name, search_name) == 0) {
            printf("�m�W: %s\n", students[i].name);
            printf("�Ǹ�: %d\n", students[i].id);
            printf("�ƾ�: %d\n", students[i].math);
            printf("���z: %d\n", students[i].physics);
            printf("�^��: %d\n", students[i].english);
            printf("����: %.1f\n", students[i].average);
            printf("�����N���^�D���...");
            getchar();
            getchar();
            return;
        }
    }

    printf("��Ƥ��s�b�C\n");
    printf("�����N���^�D���...");
    getchar();
    getchar();
}

// ���Z�ƧǨ����
void rank_grades() {
    // ²�檺�_�w�Ƨ�
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

    clearScreen(); // �M���ù�
    printf("�ǥͦ��Z�ƦW:\n");
    printf("�m�W\t�Ǹ�\t����\n");

    for (i = 0; i < student_count; i++) {
        printf("%s\t%d\t%.1f\n", students[i].name, students[i].id, students[i].average);
    }

    printf("�����N���^�D���...");
    getchar();
    getchar();
}

// �p�⥭�����Z
void calculate_average(Student *s) {
    s->average = (s->math + s->physics + s->english) / 3.0;
}

// �h�X�t��
void exit_system() {
    char confirm;
    printf("�T�w���}�H (y/n): ");
    while (1) {
        scanf(" %c", &confirm);
        if (confirm == 'y' || confirm == 'Y') {
            printf("�t�ε����C\n");
            exit(0);
        } else if (confirm == 'n' || confirm == 'N') {
            break;
        } else {
            printf("�L�Ī���J�A�п�J 'y' �� 'n': ");
        }
    }
}

// �M���ù���ƹ�{
void clearScreen() {
    system("cls");
}


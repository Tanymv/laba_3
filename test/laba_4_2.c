#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COUNT 200 /* Максимальное значение счетчика */

void ChildProcess(void); /* Прототип функции дочернего процесса */
void ParentProcess(void); /* Прототип функции родительского процесса */

int main() {
    pid_t pid = fork(); // Создание дочернего процесса

    if (pid < 0) {
        // Ошибка при создании процесса
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Код для дочернего процесса
        ChildProcess();
    } else {
        // Код для родительского процесса
        wait(NULL); // Ожидание завершения дочернего процесса
        ParentProcess();
    }

    return 0; // Завершение программы
}

void ChildProcess(void) {
    for (int i = 0; i < MAX_COUNT; i++) {
        printf("   This line is from child, value = %d\n", i);
        usleep(100000); // Задержка 100 мс для наглядности
    }
}

void ParentProcess(void) {
    for (int i = 0; i < MAX_COUNT; i++) {
        printf("This line is from parent, value = %d\n", i);
        usleep(100000); // Задержка 100 мс для наглядности
    }
}
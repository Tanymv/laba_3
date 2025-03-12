#include <stdio.h>

int main() {
    char text[256]; 

    printf("Введите текст: "); 
    fgets(text, sizeof(text), stdin);

    printf("Вы ввели: %s", text); 

    return 0; 
}
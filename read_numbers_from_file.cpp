// C/C++ Считывание целых чисел из файла и запись их в массив

#include <stdio.h>


int main() {
    char str[128];  // Строка, в которую мы считаем данные из файла (максимальной длины 128)
    FILE *file_ptr;  // Указатель на файл, который будем считывать


    file_ptr = fopen("new_file.txt", "r");

    if (file_ptr != NULL) {  // Если удалось открыть файл
        printf("File was opened\n");
        fgets(str, 128, file_ptr);  // Считывание строки
        fprintf(stdout, "%s\n", str);  // Печать считанной строки

        int i = 0;  // Счётчик для прохождения по считанной строке
        int z[128];  // Массив, в который мы будем записывать считанные числа
        int a = 0;  // Переменная для подсчёта числа
        int count = 0;  // Переменная для того, чтобы могли поочерёдно вставлять в массив считанные числа
        while (str[i] != '\0'){
            if (str[i+1] == ' '){
                a = a * 10 + (str[i] - '0');
                z[count] = a;
                // printf("%d ", a);
                count++;
                a = 0;
            }
            else if (str[i] != ' ') {
                a = a * 10 + (str[i] - '0');
                // printf("%d ", a);
                z[count] = a;
            }
            i++;
        }
        
        // Вывод считанной строки чисел по одному числу (считываем эти данные из массива)
        for (int j = 0; j <= count; j++) {
            printf("%d ", z[j]);
        }

    }
    else {
        printf("File was not opened\n");
        return 1;
    }
    return 0;
}
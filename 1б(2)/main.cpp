#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, ".UTF8");
    
    printf("=== ОПЕРАТОРЫ ДЕЛЕНИЯ ===\n\n");

    printf("Пример 1: Деление нацело и деление с дробной частью\n");
    int a, b;
    printf("Введите первое число: ");
    scanf("%d", &a);
    printf("Введите второе число: ");
    scanf("%d", &b);
    int result1 = a / b;
    float result1_decimal = (float)a / b;
    printf("Целочисленное деление: %d / %d = %d\n", a, b, result1);
    printf("Деление с дробью: %d / %d = %.2f\n\n", a, b, result1_decimal);
    
    printf("Пример 2: Остаток от деления\n");
    int c, d;
    printf("Введите первое число: ");
    scanf("%d", &c);
    printf("Введите второе число: ");
    scanf("%d", &d);
    int result2 = c % d;
    printf("%d %% %d = %d\n\n", c, d, result2);
    
    printf("Пример 3: Деление нацело (делится без остатка)\n");
    int e, f;
    printf("Введите первое число: ");
    scanf("%d", &e);
    printf("Введите второе число: ");
    scanf("%d", &f);
    int result3 = e / f;
    float result3_decimal = (float)e / f;
    printf("Целочисленное деление: %d / %d = %d\n", e, f, result3);
    printf("Деление с дробью: %d / %d = %.2f\n\n", e, f, result3_decimal);
    
    printf("Пример 4: Остаток от деления (нет остатка)\n");
    int g, h;
    printf("Введите первое число: ");
    scanf("%d", &g);
    printf("Введите второе число: ");
    scanf("%d", &h);
    int result4 = g % h;
    printf("%d %% %d = %d\n\n", g, h, result4);
    
    printf("Пример 5: Меньшее число делится на большее\n");
    int i, j;
    printf("Введите первое число: ");
    scanf("%d", &i);
    printf("Введите второе число: ");
    scanf("%d", &j);
    int result5 = i / j;
    float result5_decimal = (float)i / j;
    printf("Целочисленное деление: %d / %d = %d\n", i, j, result5);
    printf("Деление с дробью: %d / %d = %.2f\n\n", i, j, result5_decimal);
    
    printf("Пример 6: Остаток когда делимое меньше делителя\n");
    int k, l;
    printf("Введите первое число: ");
    scanf("%d", &k);
    printf("Введите второе число: ");
    scanf("%d", &l);
    int result6 = k % l;
    printf("%d %% %d = %d\n\n", k, l, result6);
    
    printf("Пример 7: Проверка формулы\n");
    int x, y;
    printf("Введите первое число: ");
    scanf("%d", &x);
    printf("Введите второе число: ");
    scanf("%d", &y);
    int quotient = x / y;
    int remainder = x % y;
    float quotient_decimal = (float)x / y;
    printf("Целочисленное деление: %d / %d = %d\n", x, y, quotient);
    printf("Деление с дробью: %d / %d = %.2f\n", x, y, quotient_decimal);
    printf("Остаток: %d %% %d = %d\n", x, y, remainder);
    printf("Проверка формулы: %d * %d + %d = %d\n", y, quotient, remainder, y * quotient + remainder);
    
    return 0;
}

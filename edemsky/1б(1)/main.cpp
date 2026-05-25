extern "C" int printf(const char*, ...);
extern "C" double sqrt(double);

int main()
{
    int a = 8;
    float b = 7.6f;
    double c = 2.0;
    long d = 15;

    int sum = a + (int)b;
    float diff = b - c;
    double prod = c * d;
    long quot = d / a;

    printf("a = %d, b = %.1f, c = %.1f, d = %ld\n", a, b, c, d);
    printf("sum (a + b) = %d\n", sum);
    printf("diff (b - c) = %.1f\n", diff);
    printf("prod (c * d) = %.1f\n", prod);
    printf("quot (d / a) = %ld\n", quot);
    return 0;
}

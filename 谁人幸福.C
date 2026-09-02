#include <stdio.h>
#include <stdlib.h>

int main() {
    
    char str[100];                 /* 字符串 = char 数组，结尾自动有 '\0' */
    int i, upper = 0, lower = 0, digit = 0;

    printf("请输入一行字符串（可含空格）：");
    gets(str);                      /* ① 填一个函数名：读一整行，能读空格 */

    for (i = 0; str[i]!='\0'; i++) {     /* ② 填循环结束条件：到字符串结尾就停 */
        if (str[i]>='A'&& str[i]<='Z')        /* ③ 填判断条件：是大写字母（'A'~'Z'） */
            upper++;
        else if (str[i]>='a'&& str[i]<='z')   /* ④ 填判断条件：是小写字母（'a'~'z'） */
            lower++;
        else if (str[i]>='0'&& str[i]<='9')   /* ⑤ 填判断条件：是数字字符（'0'~'9'） */
            digit++;
    }

    printf("大写：%d  小写：%d  数字：%d\n", upper, lower, digit);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int strlen(const char *s){
    const char *sc;
    for(sc = s; *sc !='\0'; ++sc){

    }

    return sc - s;
}

int hex2int(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  } else if (c >= 'a' && c <= 'f') {
    return c - 'a' + 10;
  } else if (c >= 'A' && c <= 'F') {
    return c - 'A' + 10;
  } else {
    return -1;
  }
}

// 将一个十六进制字符串转换为整数
int hexstr2int(const char* str) {
  if (strlen(str) < 3 || str[0] != '0' || (str[1] != 'x' && str[1] != 'X')) {
    return -1; // 格式不正确，转换失败
  }

  int result = 0;
  for (int i = 2; str[i] != '\0'; ++i) {
    int digit = hex2int(str[i]);
    if (digit == -1) {
      return -1; // 存在非法字符，转换失败
    }
    result = result * 16 + digit;
  }
  return result;
}

int main()
{
    char *a[] = {"0xAB", "0xCD", "0xEF", "0xGH"};
    int n = sizeof(a) / sizeof(char *);
    char b[n];

    for (int i = 0; i < n; ++i)
    {
        b[i] = (char)hexstr2int(a[i]);
    }

    printf("b = {");
    for (int i = 0; i < n; ++i)
    {
        printf("0x%02X,", (unsigned char)b[i]);
    }
    printf("\b}\n");

    return 0;
}

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
// #include <string.h>

#include "../s21_string.h"

#define s21_size_t unsigned long long
typedef struct {
  int minus;
  int plus;
  int space;
  int hash;
  int zero;
  int width;
  int accuracy;
  char length;
  int dot;
  char specifier;
  int sign;
  int num_system;
  int upper_case;
  int percent;
  int oct;
  int hex;
  int hex_upper;

} Spec;
const char *get_flags(const char *format,
                      Spec *specs) {  // парсинг между % и длиной/шириной
  int eospec = 0;
  while (format) {
    switch (*format) {
      case '+':
        specs->plus = 1;
        break;
      case '-':
        specs->minus = 1;
        break;
      case '#':
        specs->hash = 1;
        break;
      case ' ':
        specs->space = specs->plus ? 0 : 1;
        break;
      case '0':

        specs->zero = specs->minus ? 0 : 1;
        break;
      default:
        eospec = 1;
        break;
    }
    if (eospec == 1) break;
    format++;
  }
  if (specs->space && specs->plus) specs->space = 0;
  if (specs->zero && specs->minus) specs->zero = 0;

  return format;
}

const char *get_width(const char *format, Spec *specs, va_list *args) {
  if (*format == '*') {
    specs->width = va_arg(*args, int);
    format++;
  }

  while (format) {
    if (*format >= 48 && *format <= 57) {
      specs->width *= 10;
      specs->width += *format - 48;

    } else
      break;
    format++;
  }

  return format;
}

const char *get_accuracy(const char *format, Spec *specs, va_list *args) {
  if (*format == '.') {
    specs->dot = 1;

    format++;
    if (*format == '*') {
      specs->length = va_arg(*args, int);
      format++;
    }

    while (format) {
      if (*format >= 48 && *format <= 57) {
        specs->accuracy *= 10;
        specs->accuracy += *format - 48;

      } else
        break;
      format++;
    }
  }

  return format;
}

const char *get_length(const char *format, Spec *specs) {
  switch (*format) {
    case 'h':
      specs->length = 'h';
      format++;
      break;
    case 'l':
      specs->length = 'l';
      format++;
      break;
    case 'L':
      specs->length = 'L';
      format++;
      break;
    default:
      break;
  }

  return format;
}

void intToString(long int number, char *str) {
  int index = 0;
  int isNegative = 0;

  // Обработка отрицательных чисел
  if (number < 0) {
    isNegative = 1;
    number = -number;
  }

  // Обработка случая, когда число равно 0
  if (number == 0) {
    str[index++] = '0';
  }

  // Запись цифр числа в строку в обратном порядке
  while (number > 0) {
    int digit = number % 10;
    str[index++] = '0' + digit;
    number /= 10;
  }

  // Добавление знака минус, если число отрицательное
  if (isNegative) {
    str[index++] = '-';
  }

  // Обратное развертывание строки
  for (int i = 0; i < index / 2; ++i) {
    char temp = str[i];
    str[i] = str[index - 1 - i];
    str[index - 1 - i] = temp;
  }

  // Добавление завершающего нуля
  str[index] = '\0';
}

void print_d_i(Spec *specs, va_list *args, char *str) {
  char buffer[4096] = {0};
  char d_buffer[4096] = {0};
  int total = 0;
  int is_negative = 0;

  int size_d = 0;

  long int num = 0;

  if (specs->length == 'h')
    num = (short)va_arg(*args, int);
  else if (specs->length == 'l')
    num = (/*long*/ int)va_arg(*args, long int);
  else
    num = (int)va_arg(*args, int);

  if (num < 0) {
    num *= -1;
    specs->plus = 0;
    is_negative = 1;
  }
  intToString(num, d_buffer);

  s21_size_t size = s21_strlen(d_buffer);
  size_d = (int)size;

  if (specs->accuracy > specs->width) {
    total = specs->accuracy;
  } else if (specs->accuracy == 0 && specs->width == 0) {
    total = size_d;
  } else
    total = specs->width;

  int not_num = 0;

  if (specs->plus == 1 && is_negative == 0) {
    if (specs->accuracy > size_d)
      not_num = total - specs->accuracy - 1;
    else
      not_num = total - size_d - 1;
  } else {
    if (specs->accuracy > size_d)
      not_num = total - specs->accuracy;
    else
      not_num = total - size_d;
  }
  if (is_negative == 1) not_num--;

  if ((total == specs->accuracy || total == size_d) && is_negative == 0 &&
      specs->plus == 0 && specs->space == 1)
    s21_strncat(buffer, " ", 1);

  if (specs->minus == 1) {
    if (specs->plus == 1 && is_negative == 0) s21_strncat(buffer, "+", 1);
    if (is_negative == 1) s21_strncat(buffer, "-", 1);

    if (specs->accuracy > size_d) {
      for (int i = 0; i < specs->accuracy - size_d; i++) {
        s21_strncat(buffer, "0", 1);
      }
    }
    s21_strncat(buffer, d_buffer, size_d);

    if (size_d < total) {
      if (specs->zero == 1)
        for (int i = 0; i < not_num; i++) {
          s21_strncat(buffer, "0", 1);
        }
      else if (specs->minus == 1)
        for (int i = 0; i < not_num; i++) {
          s21_strncat(buffer, " ", 1);
        }
    }
  } else {
    if (specs->plus == 1 && is_negative == 0 && specs->zero == 1)
      s21_strncat(buffer, "+", 1);
    if (size_d < total) {
      if (specs->zero == 1) {
        if (is_negative == 1) s21_strncat(buffer, "-", 1);
        for (int i = 0; i < not_num; i++) {
          s21_strncat(buffer, "0", 1);
        }
      } else if (specs->minus == 0) {
        for (int i = 0; i < not_num; i++) {
          s21_strncat(buffer, " ", 1);
        }
        if (is_negative == 1) s21_strncat(buffer, "-", 1);
      }
    } else if (is_negative == 1)
      s21_strncat(buffer, "-", 1);

    if (specs->plus == 1 && is_negative == 0 && specs->zero == 0)
      s21_strncat(buffer, "+", 1);

    if (specs->accuracy > size_d) {
      for (int i = 0; i < specs->accuracy - size_d; i++) {
        s21_strncat(buffer, "0", 1);
      }
    }
    s21_strncat(buffer, d_buffer, size_d);
  }

  s21_strncat(str, buffer, s21_strlen(buffer));
}
long int dec_to_oct(long int num) {
  long int num_cpy = 0;

  long int buf = 0;
  while (num > 0) {
    num_cpy *= 10;

    buf = num % 8;
    num_cpy += buf;
    num /= 8;
  }
  num = 0;
  while (num_cpy > 0) {
    num *= 10;
    num += num_cpy % 10;
    num_cpy /= 10;
  }

  return num;
}
void dec_to_hex_str(long int number, char *str, Spec *specs) {
  int index = 0;
  if (number == 0) {
    str[index++] = '0';
  }
  int toupper = 0;
  if (specs->hex_upper == 1) toupper = 32;

  while (number > 0) {
    int digit = number % 16;
    if (digit >= 0 && digit <= 9)
      str[index++] = '0' + digit;
    else {
      if (digit == 10) str[index++] = 'a' - toupper;
      if (digit == 11) str[index++] = 'b' - toupper;
      if (digit == 12) str[index++] = 'c' - toupper;
      if (digit == 13) str[index++] = 'd' - toupper;
      if (digit == 14) str[index++] = 'e' - toupper;
      if (digit == 15) str[index++] = 'f' - toupper;
    }
    number /= 16;
  }
  for (int i = 0; i < index / 2; ++i) {
    char temp = str[i];
    str[i] = str[index - 1 - i];
    str[index - 1 - i] = temp;
  }
}

void print_u(Spec *specs, va_list *args, char *str) {
  unsigned long int num = 0;

  if (specs->length == 'h')
    num = (unsigned short)va_arg(*args, unsigned long);
  else if (specs->length == 'l')
    num = (unsigned)va_arg(*args, unsigned long);
  else
    num = (unsigned long)va_arg(*args, unsigned long);

  //////
  if (specs->oct == 1) num = dec_to_oct(num);
  ///////

  char buffer[4096] = {0};
  char u_buffer[4096] = {0};
  int size_u = 0;
  int total = 0;
  if (specs->hex == 0)
    intToString(num, u_buffer);
  else
    dec_to_hex_str(num, u_buffer, specs);

  s21_size_t size = s21_strlen(u_buffer);
  size_u = (int)size;

  if (specs->accuracy >= specs->width) {
    total = specs->accuracy;
  } else if (specs->accuracy == 0 && specs->width == 0) {
    total = size_u;
  } else
    total = specs->width;
  if (specs->hash == 1 && specs->hex == 1) total -= 2;
  int not_num = 0;

  if (specs->accuracy > size_u)
    not_num = total - specs->accuracy;
  else
    not_num = total - size_u;

  if (specs->minus == 1) {
    if (specs->hash == 1 && specs->hex == 1 && specs->hex_upper == 0)
      s21_strncat(buffer, "0x", 2);
    if (specs->hash == 1 && specs->hex == 1 && specs->hex_upper == 1)
      s21_strncat(buffer, "0X", 2);
    if (specs->plus == 1) s21_strncat(buffer, "+", 1);

    if (specs->accuracy > size_u) {
      for (int i = 0; i < specs->accuracy - size_u; i++) {
        s21_strncat(buffer, "0", 1);
      }
    }
    if (specs->oct == 1 && specs->hash == 1 && size_u >= total)
      s21_strncat(buffer, "0", 1);

    s21_strncat(buffer, u_buffer, size_u);

    if (size_u < total) {
      if (specs->zero == 1)
        for (int i = 0; i < not_num; i++) {
          s21_strncat(buffer, "0", 1);
        }
      else if (specs->minus == 1)
        for (int i = 0; i < not_num; i++) {
          s21_strncat(buffer, " ", 1);
        }
    }
  } else {
    if (specs->plus == 1 && specs->zero == 1) s21_strncat(buffer, "+", 1);
    if (size_u < total) {
      if (specs->zero == 1) {
        for (int i = 0; i < not_num; i++) {
          s21_strncat(buffer, "0", 1);
        }
      } else if (specs->minus == 0) {
        for (int i = 0; i < not_num; i++) {
          s21_strncat(buffer, " ", 1);
        }
      }
    }
    if (specs->hash == 1 && specs->hex == 1 && specs->hex_upper == 0)
      s21_strncat(buffer, "0x", 2);
    if (specs->hash == 1 && specs->hex == 1 && specs->hex_upper == 1)
      s21_strncat(buffer, "0X", 2);
    if (specs->plus == 1 && specs->zero == 0) s21_strncat(buffer, "+", 1);

    if (specs->accuracy > size_u) {
      for (int i = 0; i < specs->accuracy - size_u; i++) {
        s21_strncat(buffer, "0", 1);
      }
    }
    if (specs->oct == 1 && specs->hash == 1 && size_u >= total)
      s21_strncat(buffer, "0", 1);
    s21_strncat(buffer, u_buffer, size_u);
  }

  s21_strncat(str, buffer, s21_strlen(buffer));
}

void print_c(Spec *specs, va_list *args, char *str) {
  char c = (char)va_arg(*args, int);
  char temp[2] = {'\0', '\0'};
  if (specs->percent == 1) {
    temp[0] = '%';
    temp[1] = '\0';
  } else
    temp[0] = c;
  temp[1] = '\0';

  if (specs->width > 1 && specs->minus == 0) {
    for (int i = 0; i < specs->width - 1; i++) {
      if (specs->zero == 1)
        s21_strncat(str, "0", 1);
      else
        s21_strncat(str, " ", 1);
    }
  }

  s21_strncat(str, temp, 1);
  if (specs->width > 1 && specs->minus == 1) {
    for (int i = 0; i < specs->width - 1; i++) {
      s21_strncat(str, " ", 1);
    }
  }
}

void double_to_string(char *res, long double number, int afterpoint,
                      Spec *specs) {
  if (number < 0) {
    number *= -1;
  }
  int ipart = (int)number;  // Целая часть числа
  long double fpart = number - (long double)ipart;  // Дробная часть числа

  int i = 0;
  // Преобразование целой части в строку
  do {
    int remainder = ipart % 10;
    res[i++] = '0' + remainder;
    ipart /= 10;
  } while (ipart != 0);
  // Если число было отрицательным, добавляем минус
  if (number < 0) {
    res[i++] = '-';
  }
  // Записываем строку в обратном порядке

  for (int j = 0; j < i / 2; j++) {
    char temp = res[j];
    res[j] = res[(i - 1 - j)];
    res[0 + (i - 1 - j)] = temp;
  }

  if (afterpoint != 0 || specs->hash == 1) {
    res[i++] = '.';
    int round = 0;
    while (afterpoint--) {
      if (fpart < 0.999999) {
        fpart *= 10;
        int digit = (int)fpart;
        if (afterpoint == 0 || (fpart - digit >= 0.999999)) {
          long double fpart_cpy = fpart;
          fpart_cpy -= digit;
          fpart_cpy *= 10;
          int digit_cpy = (int)fpart_cpy;
          if (digit_cpy >= 5) round++;
        }
        res[i++] = '0' + digit + round;
        fpart -= digit;

      } else
        res[i++] = '0' + 0;
    }
  }
  res[i] = '\0';
}

int SignAfterPoint(double num) {
  int int_num = (int)num;
  num -= int_num;
  double p = 1;
  int i = 0;
  if (num != 0) {
    while (num < p) {
      p /= 10;
      i++;
    }
  }
  return i;
}

char *removeTrailingZeros(char *numStr) {
  int len = s21_strlen(numStr);
  int dotPos = -1;
  for (int i = 0; i < len; i++) {
    if (numStr[i] == '.') {
      dotPos = i;
      break;
    }
  }
  for (int i = len - 1; i > dotPos; i--) {
    if (numStr[i] == '0') {
      numStr[i] = '\0';
    } else {
      break;
    }
  }
  if (numStr[len - 1] == '.') {
    numStr[len - 1] = '\0';
  }

  return numStr;
}

void print_f(Spec *specs, long double num, char *str) {
  char buffer[4096] = {0};
  char f_buffer[4096] = {0};

  int total = 0;
  int is_negative = 0;
  if (num < 0) {
    num *= -1;
    specs->plus = 0;
    is_negative = 1;
  }
  int itinf = 0;
  int itnan = 0;
  if (isinf(num) == 1) itinf = 1;
  if (isnan(num) == 1) itnan = 1;

  int length_after_point = 0;
  if (itinf != 1 && itnan != 1) {
    length_after_point = SignAfterPoint(num);
  }
  if (itinf == 1 || itnan == 1) length_after_point = 3;

  if (specs->accuracy == 0 && length_after_point <= 6 && specs->dot == 0)
    specs->accuracy = 6;
  else if (specs->accuracy && length_after_point > 6 && specs->dot == 0)
    specs->accuracy = length_after_point;

  if (itinf != 1 && itnan != 1) {
    double_to_string(f_buffer, num, specs->accuracy, specs);
  } else if (itinf == 1)
    s21_strncat(f_buffer, "inf", 3);
  else if (itnan == 1)
    s21_strncat(f_buffer, "nan", 3);
  int length_f = s21_strlen(f_buffer);

  if (specs->accuracy > specs->width) {
    total = specs->accuracy;
  } else if (specs->accuracy == 0 && specs->width == 0) {
    total = length_f;
  } else
    total = specs->width;

  int not_num = 0;

  if (specs->plus == 1 && is_negative == 0) {
    if (specs->accuracy > length_f)
      not_num = total - specs->accuracy - 1;
    else
      not_num = total - length_f - 1;
  } else {
    if (specs->accuracy > length_f)
      not_num = total - specs->accuracy;
    else
      not_num = total - length_f;
  }
  if (is_negative == 1) not_num--;

  if ((total == specs->accuracy || total == length_f) && is_negative == 0 &&
      specs->plus == 0 && specs->space == 1)
    s21_strncat(buffer, " ", 1);

  if (specs->minus == 1) {
    if (specs->plus == 1 && is_negative == 0) s21_strncat(buffer, "+", 1);
    if (is_negative == 1) s21_strncat(buffer, "-", 1);

    if (specs->accuracy > length_f) {
      for (int i = 0; i < specs->accuracy - length_f; i++) {
        s21_strncat(buffer, "0", 1);
      }
    }

    if ((specs->specifier == 'g' || specs->specifier == 'G') && num != 0) {
      removeTrailingZeros(f_buffer);

      if (f_buffer[s21_strlen(f_buffer) - 1] == '.')
        f_buffer[s21_strlen(f_buffer) - 1] = '\0';
    }
    s21_strncat(buffer, f_buffer, length_f);

    if (length_f < total) {
      if (specs->zero == 1)
        for (int i = 0; i < not_num; i++) {
          s21_strncat(buffer, "0", 1);
        }
      else if (specs->minus == 1)
        for (int i = 0; i < not_num; i++) {
          s21_strncat(buffer, " ", 1);
        }
    }
  } else {
    if (specs->plus == 1 && is_negative == 0 && specs->zero == 1)
      s21_strncat(buffer, "+", 1);
    if (length_f < total) {
      if (specs->zero == 1) {
        if (is_negative == 1) s21_strncat(buffer, "-", 1);
        for (int i = 0; i < not_num; i++) {
          s21_strncat(buffer, "0", 1);
        }
      } else if (specs->minus == 0) {
        for (int i = 0; i < not_num; i++) {
          s21_strncat(buffer, " ", 1);
        }
        if (is_negative == 1) s21_strncat(buffer, "-", 1);
      }
    } else if (is_negative == 1)
      s21_strncat(buffer, "-", 1);

    if (specs->plus == 1 && is_negative == 0 && specs->zero == 0)
      s21_strncat(buffer, "+", 1);

    if (specs->accuracy > length_f) {
      for (int i = 0; i < specs->accuracy - length_f; i++) {
        s21_strncat(buffer, "0", 1);
      }
    }
    if ((specs->specifier == 'g' || specs->specifier == 'G') && num != 0) {
      removeTrailingZeros(f_buffer);
      if (f_buffer[s21_strlen(f_buffer) - 1] == '.')
        f_buffer[s21_strlen(f_buffer) - 1] = '\0';
    }

    s21_strncat(buffer, f_buffer, length_f);
  }

  s21_strncat(str, buffer, s21_strlen(buffer));
}
void print_s(Spec *specs, va_list *args, char *str) {
  char *s = (char *)va_arg(*args, char *);
  s21_size_t size_s = s21_strlen(s);

  int k = specs->accuracy;

  if ((int)size_s < specs->accuracy) k = (int)size_s;
  if (specs->width > 0 && specs->minus == 0) {
    if (specs->dot == 1) {
      for (int i = 0; i < specs->width - k; i++) {
        if (specs->zero == 0)
          s21_strncat(str, " ", 1);
        else
          s21_strncat(str, "0", 1);
      }
    } else {
      for (int i = 0; i < specs->width - (int)size_s; i++) {
        if (specs->zero == 0)
          s21_strncat(str, " ", 1);
        else
          s21_strncat(str, "0", 1);
      }
    }
  }
  if (specs->dot == 1) {
    for (int i = 0; i < specs->accuracy && i <= (int)size_s; i++) {
      s21_strncat(str, s, 1);
      s++;
      if (i == (int)size_s) break;
    }
  } else
    s21_strncat(str, s, size_s);

  if (specs->minus == 1 && specs->width > k) {
    for (int i = 0; i < specs->width - k; i++) {
      s21_strncat(str, " ", 1);
    }
  }
}

int for_exp(double num) {
  int exponent = 0;
  double mantissa = num;
  while (mantissa >= 10.0 || mantissa <= -10.0) {
    mantissa /= 10.0;
    exponent++;
  }
  while (mantissa < 1.0 && mantissa > -1.0) {
    mantissa *= 10.0;
    exponent--;
  }
  return exponent;
}
double for_mantissa(double num) {
  double mantissa = num;
  while (mantissa >= 10.0 || mantissa <= -10.0) {
    mantissa /= 10.0;
  }
  while (mantissa < 1.0 && mantissa > -1.0) {
    mantissa *= 10.0;
  }
  return mantissa;
}

void print_e(Spec *specs, long double num, char *str) {
  int itinf = 0;
  int itnan = 0;
  if (isinf(num) == 1) itinf = 1;
  if (isnan(num) == 1) itnan = 1;

  int is_negative = 0;
  if (num < 0) {
    num *= -1;
    specs->plus = 0;
    is_negative = 1;
    specs->width -= 1;
  }

  char buffer[4096] = {0};
  char e_buffer[4096] = {0};
  if (specs->accuracy == 0) specs->accuracy = 6;

  int exponent;
  double mantissa;
  if (num != 0 && itnan != 1 && itinf != 1) {
    exponent = for_exp(num);
    mantissa = for_mantissa(num);
  } else if (num == 0) {
    exponent = 0;
    mantissa = num;
  }

  if (itnan != 1 && itinf != 1)
    double_to_string(e_buffer, mantissa, specs->accuracy, specs);
  if (itinf == 1)
    s21_strncat(e_buffer, "inf", 3);
  else if (itnan == 1)
    s21_strncat(e_buffer, "nan", 3);

  int length_e = s21_strlen(e_buffer);
  int not_num = 0;
  if (specs->plus == 1 && is_negative == 0)
    not_num = specs->width - length_e - 5;
  else
    not_num = specs->width - length_e - 4;

  if (itinf == 1 || itnan == 1) not_num += 4;

  if (is_negative == 0 && specs->plus == 0 && specs->space == 1 &&
      specs->width <= length_e)
    s21_strncat(buffer, " ", 1);
  if (specs->minus == 0) {
    if (specs->zero == 1) {
      if (is_negative == 1) s21_strncat(buffer, "-", 1);
      for (int i = 0; i < not_num; i++) s21_strncat(buffer, "0", 1);
    } else if (specs->minus == 1) {
      for (int i = 0; i < not_num; i++) s21_strncat(buffer, " ", 1);
    } else if (specs->minus == 0) {
      for (int i = 0; i < not_num; i++) s21_strncat(buffer, " ", 1);
      if (is_negative == 1) s21_strncat(buffer, "-", 1);
    }
  }
  if (specs->plus == 1 && is_negative == 0) s21_strncat(buffer, "+", 1);
  if (specs->minus == 1 && is_negative == 1) s21_strncat(buffer, "-", 1);

  if (specs->specifier == 'g' || specs->specifier == 'G') {
    removeTrailingZeros(e_buffer);
    if (specs->hash == 1 && e_buffer[s21_strlen(e_buffer) - 1] == '.')
      e_buffer[s21_strlen(e_buffer) - 1] = '\0';
  }

  s21_strncat(buffer, e_buffer, 53);

  if (itinf != 1 && itnan != 1) {
    if (specs->specifier == 'e' || specs->specifier == 'g')
      s21_strncat(buffer, "e", 1);
    else
      s21_strncat(buffer, "E", 1);
    if (num >= 1 || num == 0 || itinf == 1)
      s21_strncat(buffer, "+", 1);
    else
      s21_strncat(buffer, "-", 1);
    if (exponent < 0) exponent *= -1;

    if (exponent < 10) s21_strncat(buffer, "0", 1);
    char e[1000];
    intToString(exponent, e);
    s21_strncat(buffer, e, 2);
  }
  if (specs->minus == 1 && length_e < specs->width) {
    if (specs->zero == 1) {
      if (is_negative == 1) s21_strncat(buffer, "-", 1);
      for (int i = 0; i < not_num; i++) s21_strncat(buffer, "0", 1);
    } else if (specs->minus == 1) {
      for (int i = 0; i < not_num; i++) s21_strncat(buffer, " ", 1);
    } else if (specs->minus == 0) {
      for (int i = 0; i < not_num; i++) s21_strncat(buffer, " ", 1);
      if (is_negative == 1) s21_strncat(buffer, "-", 1);
    }
  }

  s21_strncat(str, buffer, s21_strlen(buffer));
}

void print_g(Spec *specs, va_list *args, char *str) {
  long double num = 0;

  if (specs->length == 'L') {
    num = va_arg(*args, long double);
  } else {
    num = va_arg(*args, double);
  }
  char buffer[4096] = {0};
  intToString((int)fabsl(num), buffer);
  int length = s21_strlen(buffer);

  if (isinf(num) == 1 || isnan(num) == 1)
    print_e(specs, num, str);
  else if ((fabsl(num) > 0.0001 && fabsl(num) < 999999.444444) || num == 0) {
    if (fabsl(num) > 1 && specs->accuracy == 0)
      specs->accuracy = 3;
    else if (fabsl(num) > 1 && specs->accuracy != 0 && specs->accuracy > length)
      specs->accuracy -= length;

    print_f(specs, num, str);

  } else {
    print_e(specs, num, str);
  }
}

void print_p(Spec *specs, va_list *args, char *str) {
  unsigned long int num = (unsigned long int)va_arg(*args, unsigned long int);

  char buffer[4096] = {0};
  char u_buffer[4096] = {0};
  int size_u = 0;
  int total = 0;
  dec_to_hex_str(num, u_buffer, specs);
  s21_size_t size = s21_strlen(u_buffer);
  size_u = (int)size;

  if (specs->accuracy >= specs->width) {
    total = specs->accuracy;
  } else if (specs->accuracy == 0 && specs->width == 0) {
    total = size_u;
  } else
    total = specs->width;
  total -= 2;
  int not_num = 0;

  if (specs->accuracy > size_u)
    not_num = total - specs->accuracy;
  else
    not_num = total - size_u;

  if (specs->minus == 1) {
    s21_strncat(buffer, "0x", 2);

    if (specs->accuracy > size_u) {
      for (int i = 0; i < specs->accuracy - size_u; i++) {
        s21_strncat(buffer, "0", 1);
      }
    }

    s21_strncat(buffer, u_buffer, size_u);

    if (size_u < total) {
      if (specs->zero == 1)
        for (int i = 0; i < not_num; i++) {
          s21_strncat(buffer, "0", 1);
        }
      else if (specs->minus == 1)
        for (int i = 0; i < not_num; i++) {
          s21_strncat(buffer, " ", 1);
        }
    }
  } else {
    if (specs->plus == 1 && specs->zero == 1) s21_strncat(buffer, "+", 1);
    if (size_u < total) {
      if (specs->zero == 1) {
        for (int i = 0; i < not_num; i++) {
          s21_strncat(buffer, "0", 1);
        }
      } else if (specs->minus == 0) {
        for (int i = 0; i < not_num; i++) {
          s21_strncat(buffer, " ", 1);
        }
      }
    }

    s21_strncat(buffer, "0x", 2);

    if (specs->accuracy > size_u) {
      for (int i = 0; i < specs->accuracy - size_u; i++) {
        s21_strncat(buffer, "0", 1);
      }
    }

    s21_strncat(buffer, u_buffer, size_u);
  }

  s21_strncat(str, buffer, s21_strlen(buffer));
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  *str = '\0';

  while (*format) {
    if (*format == '%') {
      format++;
      Spec specs = {0};
      format = get_flags(format, &specs);
      format = get_width(format, &specs, &args);
      format = get_accuracy(format, &specs, &args);
      format = get_length(format, &specs);
      specs.specifier = *format;

      if (specs.specifier == 'd' || specs.specifier == 'i') {
        print_d_i(&specs, &args, str);
      }

      if (specs.specifier == 'c') print_c(&specs, &args, str);

      if (specs.specifier == 'f' || specs.specifier == 'F') {
        long double num = 0;
        if (specs.specifier == 'L')
          num = va_arg(args, long double);
        else
          num = va_arg(args, double);
        print_f(&specs, num, str);
      }

      if (specs.specifier == 's') print_s(&specs, &args, str);

      if (specs.specifier == 'u') print_u(&specs, &args, str);
      if (specs.specifier == '%') {
        if (*format - 1 != '%') {
          specs.percent = 1;
          print_c(&specs, &args, str);
        }
      }
      if (specs.specifier == 'o') {
        specs.oct = 1;

        print_u(&specs, &args, str);
      }

      if (specs.specifier == 'g' || specs.specifier == 'G')
        print_g(&specs, &args, str);

      if (specs.specifier == 'x' || specs.specifier == 'X') {
        specs.hex = 1;
        if (specs.specifier == 'X') specs.hex_upper = 1;
        print_u(&specs, &args, str);
      }

      if (specs.specifier == 'e' || specs.specifier == 'E') {
        long double num = 0;
        if (specs.length == 'L')
          num = va_arg(args, long double);
        else
          num = va_arg(args, double);
        print_e(&specs, num, str);
      }

      if (specs.specifier == 'p') print_p(&specs, &args, str);

    } else
      s21_strncat(str, format, 1);

    format++;
  }

  return s21_strlen(str);
}

// int main() {
//   char str[80];
//   char str_orig[80];
//   double b_5 = -0.000000654;
//   double b_6 = 320.0;
//   int res_6 = s21_sprintf(str, "%+-25g%g", b_5, b_6);
//   int res_6_orig = sprintf(str_orig, "%+-25g%g", b_5, b_6);

//   printf("MY:%d\n", res_6);
//   printf("ORIG:%d\n", res_6_orig);
//   printf("HEREIS MY:%s\n", str);
//   printf("HEREIS OR:%s\n", str_orig);
//   return 0;
// }

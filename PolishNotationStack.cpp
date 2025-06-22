#include "ADT/Stack.hpp"
#include <iostream>
#include <cctype>
#include <string>

// ? Memberikan prioritas ke setiap operator
int priority(char c) {
  if (c == '^') return 3;
  if (c == '*' || c == '/') return 2;
  return 1; // * '+' atau '-'
}

// ? Mengecek apakah karakter adalah operator
bool is_operator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// ? Membalik string sekaligus menukar '(' dengan ')' dan sebaliknya
std::string reverse_string(std::string str) {
  Stack<char> stack;
  
  // * Proses setiap karakter untuk dibalik
  for (char s: str) {
    if (s == '(') stack.push(')');
    else if (s == ')') stack.push('(');
    else stack.push(s);
  }

  // * Ambil karakter dari stack untuk membentuk string terbalik
  std::string reversed = "";
  ptr_node<char> current = stack.top();
  while (current) {
    reversed += current->data;
    current = current->next;
  }

  return reversed;
}

// ? Mengubah ekspresi infix menjadi postfix
std::string get_postfix(std::string infix) {
  Stack<char> stack;
  std::string result = "";

  for (char c : infix) {
   if (std::isalnum(c)) {
    result += c;  // * Operand langsung ke hasil

   } else if (c == '(') {
    stack.push(c);  // * Kurung buka langsung ke stack

   } else if (c == ')') {
    // * Pop semua operator hingga kurung buka ditemukan
    while (!stack.is_stack_empty() && stack.top()->data != '(') {
      result += stack.pop();
    }
    if (!stack.is_stack_empty() && stack.top()->data == '(')
      stack.pop(); // * Pop kurung buka

   } else if (is_operator(c)) {
    // * Selama top stack adalah operator dengan prioritas ≥ current
    while (!stack.is_stack_empty() && is_operator(stack.top()->data) &&
         priority(c) <= priority(stack.top()->data)) {
      result += stack.pop();
    }
    stack.push(c); // * Masukkan operator saat ini
   }
  }

  // * Pop sisa operator dari stack
  while (!stack.is_stack_empty()) {
   char data = stack.pop();
   if (data != '(' && data != ')')  // * Abaikan kurung jika ada
    result += data;
  }

  return result;
}

// Mengubah infix menjadi prefix menggunakan helper postfix
std::string get_prefix(std::string infix) {
  std::string reversed_infix = reverse_string(infix);  // Balik dan swap '('/ ')'
  std::string postfix = get_postfix(reversed_infix);   // Dapatkan postfix dari reversed
  return reverse_string(postfix);                      // Reverse kembali hasil postfix → prefix
}

int main() {
  return 0;
}

/*
Гоша написал программу, которая сравнивает строки исключительно по их хешам. 
Если хеш равен, то и строки равны. Тимофей увидел это безобразие и поручил вам
сломать программу Гоши, чтобы остальным неповадно было.

В этой задаче вам надо будет лишь найти две различные строки, которые для 
заданной хеш-функции будут давать одинаковое значение.

Гоша использует следующую хеш-функцию:
h(s)=((( (s[0]*q+s[1])q+s[2] )q+...+s[n−2]) )q+s[n-1])modR.  
для a = 1000 и m = 123 987 123.

В данной задаче необходимо использовать в качестве значений отдельных 
символов их коды в таблице ASCII.

Формат ввода
В задаче единственный тест без ввода

Формат вывода
Отправьте две строки, по одной в строке. Строки могут состоять только из маленьких 
латинских букв и не должны превышать в длину 1000 знаков каждая. Код отправлять
 не требуется. Строки из примера использовать нельзя.

Пример вывода:

ezhgeljkablzwnvuwqvp

gbpdcvkumyfxillgnqrv

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

unsigned long long hash(const std::string &val) {
    unsigned long long a = 1000;
    unsigned long long m = 123987123;
    unsigned long long hash_value = 0;
    unsigned long long p_pow = 1;
    for(int i = val.length() - 1 ; i >= 0 ; --i) {
        hash_value = (hash_value + (val[i]) * p_pow) % m;
        p_pow = (p_pow * a) % m;
    }
    return hash_value;
}

int main(){
    // изи
    std::string s1 = "aabb";
    std::string s2 = "bbaa";
    // for (int i = 0 ; i < s1.length() ; ++i) {
    //     if (s1[i] != 'z') {
    //         s2[i] = s1[i] + 1;
    //     }
    //     // if (s1[i] != 'z') {
    //     //     s2[i] = s2[i] + 1;
    //     // }
    // }
    std::cout << hash(s1) << std::endl;
    std::cout << hash(s2) << std::endl;
}
/* номер посылки:  */
/*
-- ПРИНЦИП РАБОТЫ --
Приницип работы взят из описания задачи:
Для вычисления значения выражения, записанного в обратной польской нотации, 
нужно считывать выражение слева направо и придерживаться следующих шагов:

1. Обработка входного символа:
2. Если на вход подан операнд, он помещается на вершину стека.
3. Если на вход подан знак операции, то эта операция выполняется над 
требуемым количеством значений, взятых из стека в порядке добавления. 
Результат выполненной операции помещается на вершину стека.
4. Если входной набор символов обработан не полностью, перейти к шагу 1.
После полной обработки входного набора символов результат вычисления выражения 
находится в вершине стека. Если в стеке осталось несколько чисел, то надо 
вывести только верхний элемент.

Комментарий: в качесте очерреди для чисел буду использовать
FIFO очередь на базе вектора. В коде нет проверки на корректность 
выражения.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Добавление в очередь стоит O(1), вычисление для двух последних
элементов будет O(1). Худший случай будет, если в выржаении
будут отсутстовать опреации, т.е. будет только цифры, тогда
временная сложность будет O(n) для n элеменнтов, плюс разделение
выражение по пробелам тоже составит O(n), n + n = 2n,  в итоге
сложность составит O(n). 

-- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
Для каждой операции берутся послдение два элемента из очереди, 
и результат помещается обратно, таким образом все элементы буду 
обработаны в нужном порядке, если для каждой операции будет хотя 
бы два элемента в очереди.

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Худший случай будет, если в выржаении будут отсутстовать опреации,
то есть в стек потребуется положить все n элементов в очреди, 
так еж потребуется хранить все элементы выраженния разделенные по 
пробелу, то есть пространсвтенная сложность - О(2n) == O(n).
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <sstream>

/* Проверяет является выражение числом, принцип такой, 
что проверка подходит только для текущей задачи,
предполагается, что варажение корректно и есть только
целые числа и знаки. По-сути этот метод всего лиш отличает
операцию от числа. */
bool is_number(const std::string& s)
{
    for(char c: s) {
        if (std::isdigit(c)){
            return true;
        }
    }
    return false;
}

/* разделяет строку на элементы выражения и помещает в вектор */
std::vector<std::string> split_string(const std::string &expr_in) {
    std::vector<std::string> res;
    std::istringstream iss(expr_in);
    std::string item;
    while ( getline(iss, item, ' ' ) ) {
        res.push_back(item);
    }
    return res;
}

/* предназначения для округлени вниз отрицательных чисел */
int del_operation(int l, int r) {
    if (l < 0 && (l % r != 0)) {
        return (l / r) - 1;
    } else {
        return l / r;
    }
}

/* сам алгоритм */
int calculate(const std::string &expr_in) {
    if (expr_in.empty()) {
        return 0;
    }
    std::vector<int> values_stack;
    std::vector<std::string> symbols = split_string(expr_in);
    for(std::string & s: symbols) {
        if(is_number(s)) {
            values_stack.push_back(std::stoi(s));
        } else {
            int r_operand = values_stack.back();
            values_stack.pop_back();
            int l_operand = values_stack.back();
            values_stack.pop_back();
            const char op = *s.c_str();
            switch (op)
            {
            case '-':
                values_stack.push_back(l_operand - r_operand);
                break;
            case '+':
                values_stack.push_back(l_operand + r_operand);
                break;
            case '/':
                values_stack.push_back(del_operation(l_operand, r_operand));
                break;
            case '*':
                values_stack.push_back(l_operand * r_operand);
                break;
            default:
                break;
            }
        }
    }
    return values_stack.back();
}
int main() {
    std::string expr_in;
    std::getline(std::cin, expr_in);
    std::cout << calculate(expr_in) << std::endl;
}
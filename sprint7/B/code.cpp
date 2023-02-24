/*
Дано количество учебных занятий, проходящих в одной аудитории. Для каждого 
из них указано время начала и конца. Нужно составить расписание, в соответствии 
с которым в классе можно будет провести как можно больше занятий.

Если возможно несколько оптимальных вариантов, то выведите любой. Возможно 
одновременное проведение более чем одного занятия нулевой длительности.

Формат ввода
В первой строке задано число занятий. Оно не превосходит 1000. Далее для каждого 
занятия в отдельной строке записано время начала и конца, разделённые пробелом. 
Время задаётся одним целым числом h, если урок начинается/заканчивается ровно в 
h часов. Если же урок начинается/заканчивается в h часов m минут, то время 
записывается как h.m. Гарантируется, что каждое занятие начинается не позже, 
чем заканчивается. Указываются только значащие цифры.

Формат вывода
Выведите в первой строке наибольшее число уроков, которое можно провести в аудитории. 
Далее выведите время начала и конца каждого урока в отдельной строке в порядке их 
проведения.

in:
5
9 10
9.3 10.3
10 11
10.3 11.3
11 12

out:
3
9 10
10 11
11 12

in:
3
9 10
11 12.25
12.15 13.3
out:
2
9 10
11 12.25

int:
7
19 19
7 14
12 14
8 22
22 23
5 21
9 23
out:
3
7 14
19 19
22 23

*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

// using PairD = std::pair<double,double>;
struct Lesson
{
    double start;
    double end;
    double duration;
};

bool comp(Lesson &f, Lesson &s) {
    if(f.end < s.end) {
        return true;
    } else if(f.end == s.end && f.start < s.start) {
        return true;
    }
    return false;
}

std::vector<int> count_lessons(std::vector<Lesson> &vals) {
    std::sort(vals.begin(), vals.end(), comp);
    std::cout << "Sorted: "<< std::endl;
    for(Lesson &l: vals) {
        std::cout << l.start << " " << l.end << std::endl;
    }
    std::vector<int> res {0};
    // geting first element with earliest ending time
    double last_end = vals[0].end;
    for(int i = 1 ; i < vals.size() ; ++i) {
        if(vals[i].start >= last_end) {
            res.push_back(i);
            last_end = vals[i].end;
        }
    }
    return res;
}


int main() {
    int n;
    std::cin >> n;
    std::vector<Lesson> values(n);
    for(Lesson &v : values) {
        std::cin >> v.start;
        std::cin >> v.end;
        v.duration = v.start - v.end;
    }

    auto res = count_lessons(values);
    std::cout << res.size() << std::endl;
    for(int i : res) {
        std::cout << values[i].start << " " << values[i].end << std::endl;
    }
}
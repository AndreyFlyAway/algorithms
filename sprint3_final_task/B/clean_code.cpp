#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>


struct Student{
    std::string login;
    int task_solved;
    int penalties;
};

bool operator ==(const Student &a, const Student &b) {
    return (a.task_solved == b.task_solved && a.penalties == b.penalties);
}

bool operator !=(const Student &a, const Student &b) {
    return a == b;
}

bool operator <(const Student &a, const Student &b) {
    if (a.task_solved < b.task_solved) {
        return true;
    } else if (a.task_solved == b.task_solved && a.penalties > b.penalties) {
        return true;
    } else if (a.task_solved == b.task_solved && a.penalties == b.penalties) {
        return a.login > b.login;
    } else {
      return false;
    }
}


bool operator >(const Student &a, const Student &b) {
    if (a.task_solved > b.task_solved) {
        return true;
    } else if (a.task_solved == b.task_solved && a.penalties < b.penalties) {
        return true;
    } else if (a.task_solved == b.task_solved && a.penalties == b.penalties) {
        return a.login < b.login;
    } else {
        return false;
    }
}

bool operator <=(const Student &a, const Student &b) {
    return a < b || a == b;
}

bool operator >=(const Student &a, const Student &b) {
    return a > b || a == b;
}

std::ostream& operator<<(std::ostream& os, Student& st) {
    return os << st.login;
}

void print_students(std::vector<Student>& students) {
    for(Student &s: students) {
        std::cout << s << std::endl;
    }
}

int partition(std::vector<Student>& students, int left, int right, int op) {
    while(left <= right ) {
        while(students[left] > students[op] ) {
            ++left;
        }
        while(students[right] < students[op] ) {
            --right;
        }
        if (left >= right) {
            return right;
        } else {
            std::swap(students[right], students[left]);
        }
        ++left;
        --right;
    }
    return right;
}

// как выбрать опорный элемент? 
// сделать это при помощи итераторов!
void sort_part(std::vector<Student>& students, int left, int right) {
    if (left < right) {
        int op = partition(students, left, right, left);
        sort_part(students, left, op);
        sort_part(students, op+1, right);
    }
}

int main() {
    int n, tasks, penalties;
    std::string login;
    std::cin >> n;
    std::vector<Student> students;
    for(int i = 0 ; i < n ; ++i) {
        std::cin >> login;
        std::cin >> tasks;
        std::cin >> penalties;
        students.push_back(Student{login, tasks, penalties});
    }
    sort_part(students, 0, students.size()-1);
    print_students(students);
}
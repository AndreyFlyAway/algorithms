#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>

/*
5
alla 4 100
gena 6 1000
gosha 2 90
rita 2 90
timofey 4 80

res:
    gena
    timofey
    alla
    gosha
    rita

5
alla 0 0
gena 0 0
gosha 0 0
rita 0 0
timofey 0 0

res:
    alla
    gena
    gosha
    rita
    timofey

13
tufhdbi 76 58
rqyoazgbmv 59 78
qvgtrlkmyrm 35 27
tgcytmfpj 70 27
xvf 84 19
jzpnpgpcqbsmczrgvsu 30 3
evjphqnevjqakze 92 15
wwzwv 87 8
tfpiqpwmkkduhcupp 1 82
tzamkyqadmybky 5 81
amotrxgba 0 6
easfsifbzkfezn 100 28
kivdiy 70 47

res:
    easfsifbzkfezn
    evjphqnevjqakze
    wwzwv
    xvf
    tufhdbi
    tgcytmfpj
    kivdiy
    rqyoazgbmv
    qvgtrlkmyrm
    jzpnpgpcqbsmczrgvsu
    tzamkyqadmybky
    tfpiqpwmkkduhcupp
    amotrxgba

24
alpyx 3 49
qly 62 28
cpbablljhrnlejcwq 45 32
yusoldfqnjlvwrcruts 81 39
kzmleudk 52 89
hpnpszayf 4 12
ojywnxuyqgmf 54 31
tvomvisbqrflkghnojt 49 79
yc 17 84
k 16 14
dgmqeqezjgzxfwhcn 68 21
zdbonelpgmbou 47 64
ehtxaytzgcsim 21 66
burbwymmeal 56 80
wqzynngqasdjj 8 15
auirlnkhxtmmytr 23 14
poypocw 0 72
uf 40 68
ezfetpflzoi 0 30
ygegvjzlfgumbo 80 33
rcwp 8 30
oaes 7 59
zgbktifgwvsgesleqclp 4 8
knzsujegjqmer 99 72

res:
    knzsujegjqmer
    yusoldfqnjlvwrcruts
    ygegvjzlfgumbo
    dgmqeqezjgzxfwhcn
    qly
    burbwymmeal
    ojywnxuyqgmf
    kzmleudk
    tvomvisbqrflkghnojt
    zdbonelpgmbou
    cpbablljhrnlejcwq
    uf
    auirlnkhxtmmytr
    ehtxaytzgcsim
    yc
    k
    wqzynngqasdjj
    rcwp
    oaes
    zgbktifgwvsgesleqclp
    hpnpszayf
    alpyx
    ezfetpflzoi
    poypocw
*/



struct Student{
    std::string login;
    int task_solved;
    int penalties;
};

using Iterator = std::vector<Student>::iterator;
using CIterator = std::vector<Student>::const_iterator;

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
    // return (a.task_solved <= b.task_solved && a.penalties >= b.penalties);
    return a < b || a == b;
}

bool operator >=(const Student &a, const Student &b) {
    // return (a.task_solved >= b.task_solved && a.penalties <= b.penalties);
    return a > b || a == b;
}

std::ostream& operator<<(std::ostream& os, Student& st) {
    // return os << st.login;
    return os << st.login << " " << st.task_solved << " " << st.penalties;
}

void print_students(std::vector<Student>& students) {
    for(Student &s: students) {
        std::cout << s << std::endl;
    }
}

int test_students() {
    Student a{"poypocw", 0, 72};
    Student b{"ezfetpflzoi", 0, 30};
    std::cout << (a > b) << std::endl;
    if (a < b) {
        std::cout << a << " less than " << b << std::endl;
    }  else {
        std::cout << "Somthing wrong wiht " << a << " and " << b << std::endl;
    }
    if (b > a) {
        std::cout << b << " grater than " << a << std::endl;
    } else {
        std::cout << "Somthing wrong wiht " << a << " and " << b << std::endl;
    }
    return 0;
}


Iterator partition_iter(Iterator begin, Iterator end) {
    Iterator op = begin;
    // std::advance(op, std::distance(begin, end) / 2);
    while(begin < end) {
        // std::cout << "partition" << std::endl;
        while(*begin > *op) {
            std::cout << "left is " << *begin <<std::endl;
            ++begin;
        }
        while( *end < *op ) {
            std::cout << "right is " << *begin <<std::endl;

            --end;
        }
        if (begin >= end) {
            return end;
        // } else (students[left] < students[right] ) {
        } else {
            std::iter_swap(begin, end);
        }
        ++begin;
        --end;
    }
    return end;
}

void quic_sort_iter(Iterator begin, Iterator end) {
    if (begin < end) {
        Iterator op = partition_iter(begin, end);
        quic_sort_iter(begin, op);
        quic_sort_iter(op+1, end);
    }
}

int partition(std::vector<Student>& students, int left, int right, int op) {
    // std::cout << "partition from " << left << " to " << right << std::endl; 
    while(left <= right ) {
        // std::cout << "partition" << std::endl;
        // std::cout << "left is " << left << " values is " << students[left] << " op " << students[op] <<std::endl;
        while(students[left] > students[op] ) {
            // std::cout << "left is " << left << " values is " << students[left] <<std::endl;
            ++left;
        }
        while(students[right] < students[op] ) {
            // std::cout << "right is " << right << " values is " << students[right] <<std::endl;
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
        // int op = partition(students, left, right, (left+right)/3);
        int op = partition(students, left+1, right, left);
        sort_part(students, left, op);
        sort_part(students, op+1, right);
    }
}

// void quic_sort(std::vector<Student>& students) {
//     int op = partition(students, 0, students.size()-1, 0);
//     sort_part(students, 0, op);
//     sort_part(students, op+1, students.size()-1);
// }


int test_quic_sort() {
    std::vector<Student> students;
    // students.push_back(Student{"alla", 4, 100});
    // students.push_back(Student{"gena", 6, 1000});
    // students.push_back(Student{"gosha", 2, 90});
    // students.push_back(Student{"aaaa", 4, 100});
    // students.push_back(Student{"rita", 2, 90});
    // students.push_back(Student{"gosha", 2, 90});
    // students.push_back(Student{"rita", 2, 90});
    // students.push_back(Student{"timofey", 4, 80});
    // students.push_back(Student{"timofey", 4, 80});

    // students.push_back(Student{"aaaa", 4, 100});

    // students.push_back(Student{"k", 8, 1000});
    // students.push_back(Student{"e", 1, 4});
    // students.push_back(Student{"d", 1, 3});
    // students.push_back(Student{"c", 2, 1});
    // students.push_back(Student{"b", 3, 3});
    // students.push_back(Student{"a", 3, 0});
    // quic_sort_students(students, 0, students.size()-1);
    // students.push_back(Student{"alla", 0, 0});
    // students.push_back(Student{"gena", 0, 0});
    // students.push_back(Student{"gosha", 0, 0});
    // students.push_back(Student{"rita", 0, 0});
    // students.push_back(Student{"timofey", 0, 0});
    // std::sort(students.begin(), students.end(), [](auto &a, auto &b){ return a > b;});
    // quic_sort(students);

    // students.push_back(Student{"tufhdbi", 76, 58});
    // students.push_back(Student{"rqyoazgbmv", 59, 78});
    // students.push_back(Student{"qvgtrlkmyrm", 35, 27});
    // students.push_back(Student{"tgcytmfpj", 70, 27});
    // students.push_back(Student{"xvf", 84, 19});
    // students.push_back(Student{"jzpnpgpcqbsmczrgvsu", 30, 3});
    // students.push_back(Student{"evjphqnevjqakze", 92, 15});
    // students.push_back(Student{"wwzwv", 87, 8});
    // students.push_back(Student{"tfpiqpwmkkduhcupp", 1, 82});
    // students.push_back(Student{"tzamkyqadmybky", 5, 81});
    // students.push_back(Student{"amotrxgba", 0, 6});
    // students.push_back(Student{"easfsifbzkfezn", 100, 28});
    // students.push_back(Student{"kivdiy", 70, 47});

    // students.push_back(Student{"alpyx", 3, 49});
    // students.push_back(Student{"qly", 62, 28});
    // students.push_back(Student{"cpbablljhrnlejcwq", 45, 32});
    // students.push_back(Student{"yusoldfqnjlvwrcruts", 81, 39});
    // students.push_back(Student{"kzmleudk", 52, 89});
    // students.push_back(Student{"hpnpszayf", 4, 12});
    // students.push_back(Student{"ojywnxuyqgmf", 54, 31});
    // students.push_back(Student{"tvomvisbqrflkghnojt", 49, 79});
    // students.push_back(Student{"yc", 17, 84});
    // students.push_back(Student{"k", 16, 14});
    // students.push_back(Student{"dgmqeqezjgzxfwhcn", 68, 21});
    // students.push_back(Student{"zdbonelpgmbou", 47, 64});
    // students.push_back(Student{"ehtxaytzgcsim", 21, 66});
    // students.push_back(Student{"burbwymmeal", 56, 80});
    // students.push_back(Student{"wqzynngqasdjj", 8, 15});
    // students.push_back(Student{"auirlnkhxtmmytr", 23, 14});
    // students.push_back(Student{"poypocw", 0, 72});
    // students.push_back(Student{"uf", 40, 68});
    // students.push_back(Student{"ezfetpflzoi", 0, 30});
    // students.push_back(Student{"ygegvjzlfgumbo", 80, 33});
    // students.push_back(Student{"rcwp", 8, 30});
    // students.push_back(Student{"oaes", 7, 59});
    // students.push_back(Student{"zgbktifgwvsgesleqclp", 4, 8});
    // students.push_back(Student{"knzsujegjqmer", 99, 72});
    // students.push_back(Student{"knzsujegjqmer", 99, 72});

    students.push_back(Student{"alla", 0, 0});
    students.push_back(Student{"gena", 1, 0});
    students.push_back(Student{"gosha", 2, 0});
    students.push_back(Student{"rita", 3, 0});
    students.push_back(Student{"timofey", 4, 0});
    // students.push_back(Student{"poypocw", 0, 72});
    // students.push_back(Student{"ezfetpflzoi", 0, 30});

    sort_part(students, 0, students.size()-1);
    

    print_students(students);
}

int main() {
    // test_students();
    test_quic_sort();
    // int n, tasks, penalties;
    // std::string login;
    // std::cin >> n;
    // std::vector<Student> students;
    // for(int i = 0 ; i < n ; ++i) {
    //     std::cin >> login;
    //     std::cin >> tasks;
    //     std::cin >> penalties;
    //     students.push_back(Student{login, tasks, penalties});
    // }
    // quic_sort_students(students, 0, students.size());
    // print_students(students);
}
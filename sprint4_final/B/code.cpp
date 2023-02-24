#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

/*
Тимофей, как хороший руководитель, хранит информацию о зарплатах своих 
сотрудников в базе данных и постоянно её обновляет. Он поручил вам написать 
реализацию хеш-таблицы, чтобы хранить в ней базу данных с зарплатами 
сотрудников.

Хеш-таблица должна поддерживать следующие операции: 

put key value —– добавление пары ключ-значение. Если заданный ключ 
уже есть в таблице, то соответствующее ему значение обновляется. 
get key –— получение значения по ключу. Если ключа нет в таблице, 
то вывести «None». Иначе вывести найденное значение. 
delete key –— удаление ключа из таблицы. Если такого ключа нет, 
то вывести «None», иначе вывести хранимое по данному ключу значение и удалить ключ.
В таблице хранятся уникальные ключи.

Требования к реализации: 

Нельзя использовать имеющиеся в языках программирования реализации 
хеш-таблиц (std::unordered_map в С++, dict в Python, HashMap в Java, и т. д.)
Разрешать коллизии следует с помощью метода цепочек или с помощью открытой адресации.
Все операции должны выполняться за O(1) в среднем.
Поддерживать рехеширование и масштабирование хеш-таблицы не требуется.
Ключи и значения, id сотрудников и их зарплата, —– целые числа.
Поддерживать произвольные хешируемые типы не требуется.

10**5 ключей;
*/

using Pair = std::pair<int,int>;
using Buckets = std::vector<std::vector<std::pair<int,int>>>;

const long int _M_DEL=1371;
const long int _P = 10;
const long int _P_VAL=1024; // 2 ^ _P  
const long int _S=4294967296;

class HashMap {
public:
    HashMap(): _m(_M_DEL) {
        _buckets = Buckets(_M_DEL, std::vector<std::pair<int,int>> {});
    }

    void put(int key, int val) {
        int last_deleted = -1;
        int bucket_num = get_bucket_num(key);
        for(int i = 0 ; i < _buckets[bucket_num].size() ; ++i) {
             if (key == _buckets[bucket_num][i].first) {
                 _buckets[bucket_num][i].second = val;
                 return;
             } else if (key == -1) {
                 last_deleted = i;
             }
        }
        if (last_deleted != -1) {
            _buckets[bucket_num][last_deleted].first = key;
            _buckets[bucket_num][last_deleted].second = val;
        } else {
            _buckets[bucket_num].push_back({key, val});
        }
    }

    int get(int key) const {
        int bucket_num = get_bucket_num(key);
        if (_buckets[bucket_num].empty()) {
            return -1;
        } else {
            for(Pair &p : _buckets[bucket_num]) {
                if (key == p.first) {
                    return p.second;
                }
            }
        } 
        return -1;
    }

    int del(int key) {
        int bucket_num = get_bucket_num(key);
        if (_buckets[bucket_num].empty()) {
            return -1;
        } else {
            for(int i = 0 ; i < _buckets[bucket_num].size() ; ++i) {
                if (key == _buckets[bucket_num][i].first) {
                    if (i == _buckets[bucket_num].size() - 1) {
                        _buckets[bucket_num].pop_back();
                    } else {
                        _buckets[bucket_num][i].first = -1;
                    }
                    return _buckets[bucket_num][i].second;
                }
            }
        }
        return -1;
    }

private:
    int get_bucket_num(int key) const {
        // return int(key * _S % (_P_VAL)>>(32l - _P));
        return int(key % _M_DEL);
    }

private:
    Buckets _buckets;
    const int _m; // constant
};

int test_measure() {
    int n = 10000;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1234503, std::numeric_limits<int>::max() - 1); 

    std::cout << "Started" << std::endl;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    HashMap hm;


    for(int i = 0 ; i < n ; ++i) {
        hm.put(dist6(rng),dist6(rng));
        // hm.put(i,i);
    }

    for(int i = 0 ; i < n ; ++i) {
        hm.get(i);
        // if (i != hm.get(i)) {
        //     std::cout << "FAILED get at " << i << std::endl; 
        //     break;
        // }
    }

    for(int i = 0 ; i < n  ; ++i) {
        hm.del(i);
        //  if (i != hm.del(i)) {
        //     std::cout << "FAILED del at " << i << std::endl; 
        //     break;
        //  }
    }


    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    // std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms] for " << n << " elements" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << "[sec] for " << n << " elements" << std::endl;

    return 0;
}

int test() {
    HashMap hm;
    hm.put(0,1);
    hm.put(1,1);
    hm.put(2,3);
    hm.put(3,4);
    hm.put(5,6);
    hm.put(7,8);
    std::cout << hm.get(0) << std::endl;
    std::cout << hm.get(1) << std::endl;
    std::cout << hm.get(2) << std::endl;
    std::cout << hm.get(3) << std::endl;
    std::cout << hm.get(4) << std::endl;
    std::cout << hm.get(5) << std::endl;
    std::cout << hm.get(6) << std::endl;
    std::cout << hm.del(6) << std::endl;
    std::cout << hm.get(6) << std::endl;
    return 0;
}

int main() {
    return 0;
    int n, key_in, val_in, cmd_res;
    std::string cmd;
    std::cin >> n;
    HashMap hm;
    for(int i = 0 ; i < n ; ++i) {
        std::cin >> cmd;
        if (cmd == "put") {
            std::cin >> key_in >> val_in;
            hm.put(key_in, val_in);
        } else if (cmd == "get") {
            std::cin >> key_in ;
            cmd_res = hm.get(key_in);
            if (cmd_res != -1) {
                std::cout << cmd_res << std::endl;
            } else {
                std::cout << "None" << std::endl;
            }
        } else if (cmd == "delete") {
            std::cin >> key_in ;
            cmd_res = hm.del(key_in);
            if (cmd_res != -1) {
                std::cout << cmd_res << std::endl;
            } else {
                std::cout << "None" << std::endl;
            }
        }
    }
}
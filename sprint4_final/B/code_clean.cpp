/* номер посылки: 70358944*/
/*
Принцип работы:
Хеш таблица реализована по принципу списков связности (вектора в моем случае).
По номеру ключа получаю номер корзины для опреций. Формула получения номера 
корзинны B(k) = k % MOD, где k - ключ, MOD - простое число. Хеш ключа считать 
не требуется, т.к. ключ уже явлется числовым значением. Удлаение происходит
путем выставление объекта как удаленного (выставляю значение -1).

Времененная сложность:
Получение, помещение и удаление в среднем конастантое - O(1). Итоговая сложность
будет O(n), где n - колиичество операций.

Пространсвенная сложность:
O(MOD + n + k), где MOD - колиество корзин (1371 в моем случае), n - колиество
элемеентов в таблце, k - удаленных элеементов из таблицы. 

Доказательство коррекности:
Каждому значению однозначно будет соотвествоать своему номеру корзины, числа 
буду распределены равномерно, т.к. для операции получения номера корзины в 
формуле берется простое число. Удаленные значения помечаются, и если во время
помещения элемента в корзину был найден удаленный элемент - он заменяется новым 
значением.
*/

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using Pair = std::pair<int,int>;
using Buckets = std::vector<std::vector<std::pair<int,int>>>;

const long int _M_DEL=137213;

class HashMap {
public:
    HashMap(): 
     _buckets(Buckets(_M_DEL, std::vector<std::pair<int,int>> {})) {}

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
            for(const Pair &p : _buckets[bucket_num]) {
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
        return int(key % _M_DEL);
    }

private:
    Buckets _buckets;
};

int main() {
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

/* номре посылки: */
/*
Принцип работы:
I. Определен объект для описания студента у которого поля определяют 
логин, количество решенных задач, количество ошибок. Для объкета 
определены операции больше, меньше, равно.
II. Определен объект, который в куче (пирамиде) держит все объект:
1. При добавлении объекта в кучу он помещается в коннец массива
2. Объект из пункта 1 сранвиается с родителем, если он больше, то они меняются 
местами, операция повторяется, пока элемеент не окажется в нужном месте.
3. При формировании результата первый объект массива помещаеся в результа.
4. Последний элемент помещается в первы элемент массив, массив уменьшается на 1.
5. Первый элемент двигается вниз по дереву, пока он меньше какого-либо из детей 
текущего узла.
6. Пункты 3-5 повторяются, пока в массиве есть элементы.

Врмененная сложность:
Временная сложность пирамидальной сортировки в худшем случае имеет сложность O(nlogn)

Пространственна сложность:
Количесто элементов + 1, т.е. O(n+1) == O(n)

Доказательство коррекности:
Массив будет представлять дерево, для каждого узло будет верно, что его ребенок будет
меньше. Таким образом корнем дерева будет всегда наибольший элемент, при его изъятии
в него будет помещен следующий наибольший элемент. То есть при последовательном
изъятии корневого элемента получится отсортированный массив.
*/

#include <algorithm>
#include <vector>
#include <iostream>

struct Student{
  std::string login;
  int task_solved;
  int penalties;
};

bool operator ==(const Student &a, const Student &b) {
    return (a.task_solved == b.task_solved && a.penalties == b.penalties);
}

bool operator !=(const Student &a, const Student &b) {
    return !operator ==(a, b);
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
    return operator <(b, a);
}

std::ostream& operator<<(std::ostream& os, Student& st) {
    return os << st.login;
}

void print_students(std::vector<Student>& students) {
    for(Student &s: students) {
        std::cout << s << std::endl;
    }
}

template <class T>
class MaxHeap {
public:
	MaxHeap(): index_(0)
  {
    data_.push_back(T {});
  }

	void push_back(const T& obj) {
    ++index_;
    data_.push_back(obj);
    bubble_up();
  }

  std::vector<T> get_result()
  {
    std::vector<T> results;
    while(index_ != 0) {
      results.push_back(data_[1]);
      data_[1] = data_[index_];
      data_.pop_back();
      --index_;
      bubble_down();
    }
    return results;
  }

private:
	unsigned int index_;
	std::vector<T> data_;

private:
	void bubble_up() {
    unsigned int p = parent(index_);
    unsigned int c = index_;
    if (p == 0) {
      return;
    }
    while((p != 0) && data_[p] < data_[c]) {
      std::swap(data_[p], data_[c]);
      c = p;
      p = parent(c);
    }
  }

	unsigned int parent(unsigned int n)
	{
		return ((n == 1) ? 0 : (n / 2));
	}

	void bubble_down()
  {
    unsigned int in_tree_index = 1;
    unsigned int inserted_index = 1;
    while (true) {
      unsigned int c = inserted_index * 2;
      for (int i = 0; (i <= 1) && ((c + i) <= index_) ; ++i) {
        if (data_[in_tree_index] < data_[c + i]) {
          in_tree_index = c + i;
        }
      }
      if (in_tree_index != inserted_index) {
        std::swap(data_[inserted_index], data_[in_tree_index]);
        inserted_index = in_tree_index;
      } else {
        break;
      }
    }
  }
};


int main() {
  MaxHeap<Student> SortedStudents;
  int n, tasks, penalties;
  std::string login;
  
  std::cin >> n;
  for(int i = 0 ; i < n ; ++i) {
      std::cin >> login;
      std::cin >> tasks;
      std::cin >> penalties;
      SortedStudents.push_back(Student{login, tasks, penalties});
  }
  auto res = SortedStudents.get_result();
  for(Student& s: res) {
    std::cout << s << std::endl;
  }
}
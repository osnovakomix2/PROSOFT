/**
 * Definition for singly-linked list
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;          // Медленный указатель: начинает с головы, двигается на 1 шаг
        ListNode* fast = head;          // Быстрый указатель: начинает с головы, двигается на 2 шага
        while (fast != nullptr && fast->next != nullptr){  // Пока быстрый указатель и следующий за ним существуют
            slow = slow->next;          // Сдвигаем медленный указатель на 1 узел вперёд
            fast = fast->next->next;    // Сдвигаем быстрый указатель на 2 узла вперёд
        }
        // После цикла slow указывает на середину списка (конец первой половины)
        // Для чётной длины slow — это узел перед второй половиной
        // Для нечётной длины slow — центральный узел, который остаётся в первой половине

        ListNode* second = slow->next;  // second — начало второй половины списка (узел после slow)
        slow->next = nullptr;           // Разрываем список: первая половина заканчивается на slow
        ListNode* node = nullptr;       // node будет головой перевёрнутой второй половины (изначально nullptr)

        while (second != nullptr){      // Пока во второй половине есть узлы — разворачиваем её
            ListNode* temp = second->next; // Запоминаем следующий узел, чтобы не потерять его
            second->next = node;        // Меняем указатель: текущий узел теперь указывает на предыдущий (node)
            node = second;              // Сдвигаем node на текущий узел (новая голова перевёрнутой части)
            second = temp;              // Переходим к следующему узлу исходной второй половины
        }
        // После цикла node — голова развёрнутой второй половины

        ListNode* first = head;         // first — указатель на начало первой половины
        second = node;                  // second — указатель на начало развёрнутой второй половины

        while (second != nullptr){      // Пока во второй половине есть узлы — вставляем их между узлами первой половины
            ListNode* temp1 = first->next;  // Запоминаем следующий узел первой половины
            ListNode* temp2 = second->next; // Запоминаем следующий узел второй половины
            first->next = second;       // Вставляем узел second после first
            second->next = temp1;       // Узел second теперь указывает на следующий узел первой половины
            first = temp1;              // Переходим к следующему узлу первой половины
            second = temp2;             // Переходим к следующему узлу второй половины
        }
        // Если длина списка нечётная, последний узел первой половины остаётся в конце,
        // так как вторая половина закончилась, и цикл while(second) завершился
    }
};
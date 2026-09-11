class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int left_max = height[left];
        int right_max = height[right];
        int water = 0;

        while (left < right) {         // Пока левый не встретился с правым
            if (left_max < right_max) { // Если максимальная высота слева меньше, чем справа, то уровень воды ограничен слева
                left++;                // Сдвигаем левый на один шаг вправо
                left_max = std::max(left_max, height[left]); // Обновляем left_max: берём максимум из старого left_max и новой высоты
                water += left_max - height[left]; // Добавляем к общему объёму разницу между left_max и текущей высотой (сколько воды удержится над столбцом)
            } else {                   // Иначе уровень воды ограничен справа
                right--;               // Сдвигаем правый на один шаг влево
                right_max = std::max(right_max, height[right]); // Обновляем right_max: максимум из старого right_max и новой высоты
                water += right_max - height[right]; // Добавляем воду над текущим правым столбцом
            }
        }
        return water;
    }
};
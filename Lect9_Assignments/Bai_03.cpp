#include <iostream>
using namespace std;

int main() {
    int numItems, maxWeight; // Số lượng vật phẩm và trọng lượng tối đa của cái túi
    cin >> numItems >> maxWeight;

    int weights[100], values[100]; // Mảng lưu trọng lượng và giá trị của từng vật phẩm
    for (int i = 0; i < numItems; i++) {
        cin >> weights[i] >> values[i]; // Nhập từng vật phẩm với trọng lượng và giá trị tương ứng
    }

    int maxValues[1001] = {0}; // Mảng lưu giá trị tối đa có thể đạt được với mỗi trọng lượng

    // Duyệt qua từng vật phẩm để cập nhật giá trị tối đa
    for (int i = 0; i < numItems; i++) {
        // Duyệt ngược từ maxWeight về weights[i] để tránh ghi đè giá trị cũ
        for (int currentWeight = maxWeight; currentWeight >= weights[i]; currentWeight--) {
            // Kiểm tra xem nếu thêm vật phẩm này vào có làm tăng giá trị tổng không
            if (maxValues[currentWeight - weights[i]] + values[i] > maxValues[currentWeight]) {
                maxValues[currentWeight] = maxValues[currentWeight - weights[i]] + values[i]; // Cập nhật giá trị tối đa
            }
        }
    }

    cout << maxValues[maxWeight] << endl; // Xuất ra giá trị lớn nhất có thể đạt được khi túi đầy

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int numItems, targetSum; // Số lượng vật phẩm và tổng cần kiểm tra
    cin >> numItems >> targetSum;
    
    int itemValues[numItems]; // Mảng lưu giá trị của từng vật phẩm
    for(int &value : itemValues) cin >> value;

    vector<int> dp(targetSum + 1, 0); // Mảng động lưu trạng thái có thể tạo tổng bằng giá trị i hay không
    dp[0] = 1; // Có thể tạo tổng bằng 0 bằng cách không chọn vật phẩm nào

    for (int i = 0; i < numItems; i++) { 
        for(int sum = targetSum; sum >= itemValues[i]; sum--) { 
            // Nếu có thể tạo tổng bằng (sum - giá trị của vật phẩm i)
            // thì khi thêm vật phẩm i, ta sẽ có thể tạo tổng bằng sum
            if (dp[sum - itemValues[i]] == 1)  
                dp[sum] = 1; 
        }
    }

    // Nếu có thể tạo tổng đúng bằng targetSum, in "YES", ngược lại in "NO"
    if(dp[targetSum] == 1) cout << "YES";
    else cout << "NO";

    return 0;
}

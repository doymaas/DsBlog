#include <iostream>
#include <vector>
using namespace std;

// 递归函数，通过计算所有子集乘积的和, index 是当前下标, product 是当前乘积合
void subsetProductSumHelper(vector<double>& arr, int n, int index, double product, double& result) {
    // 遍历所有子数组结束
    if (index == n) {
        // 只有product不等于1.0时，才加入结果
        if (product != 1.0) {
            result += product;
        }
        return;
    }

    // 不包括当前元素
    subsetProductSumHelper(arr, n, index + 1, product, result);

    // 包括当前元素
    subsetProductSumHelper(arr, n, index + 1, product * arr[index], result);
}

// 主函数，初始化并调用递归函数
double subsetProductSum(vector<double>& arr) {
    double result = 0.0;
    subsetProductSumHelper(arr, arr.size(), 0, 1.0, result);
    return result;
}

int main() {
    int n;
    cin >> n;
    double* tmp=new double[n];
    for(int i=0;i<n;i++){
    	cin >> tmp[i];
	}
//	for(int i=0;i<n;i++)
//		cout << tmp[i]<<endl;
    vector<double> arr(tmp, tmp + n); // 使用临时数组初始化vector
    double a1=subsetProductSum(arr);
//    cout << a1; 
    int level;
    cin >> level;
    double a2;
    cin >> a2;
    double final=level*10*(a1+1)*(a2+1);
    cout << final;
    
    return 0;
}

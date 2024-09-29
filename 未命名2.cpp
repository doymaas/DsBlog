#include <iostream>
#include <vector>
using namespace std;

// �ݹ麯����ͨ�����������Ӽ��˻��ĺ�, index �ǵ�ǰ�±�, product �ǵ�ǰ�˻���
void subsetProductSumHelper(vector<double>& arr, int n, int index, double product, double& result) {
    // �����������������
    if (index == n) {
        // ֻ��product������1.0ʱ���ż�����
        if (product != 1.0) {
            result += product;
        }
        return;
    }

    // ��������ǰԪ��
    subsetProductSumHelper(arr, n, index + 1, product, result);

    // ������ǰԪ��
    subsetProductSumHelper(arr, n, index + 1, product * arr[index], result);
}

// ����������ʼ�������õݹ麯��
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
    vector<double> arr(tmp, tmp + n); // ʹ����ʱ�����ʼ��vector
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

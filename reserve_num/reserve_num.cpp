#include <iostream>

using namespace std; 

int main() {
    int num, reserve_num;
    cout << "please input your three digital num: ";
    cin >> num;
    reserve_num = num%10*100 + num%100/10*10 + num/100;
    cout << "the reserve num: " << reserve_num << endl;

    return 0;
}
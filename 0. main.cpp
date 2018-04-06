#include "0. Sort.cpp"

int main()
{
    cout << "Yep!" << endl;
    vector<int> v;
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(5);
    v.push_back(0);
    v.push_back(1);
    ShellSort(v);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "\t";
    cout << endl;
    return 0;
}
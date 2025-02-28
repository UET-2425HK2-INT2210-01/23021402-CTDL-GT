#include <bits/stdc++.h>
#include <string>
 using namespace std;

int main()
{
    string n;
    getline(cin, n);
    for (int i = n.length()-1; i >= 0; i--){
        cout << n[i];
    }
    return 0;
}

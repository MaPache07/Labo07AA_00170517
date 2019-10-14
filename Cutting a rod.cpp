#include <iostream>
#include <string>

using namespace std;

int mayor(int n, int m){
    if(n > m) return n;
    return m;
}

int cuttingRod(int n, int m[]){
    int r[n+1];
    r[0] = 0;
    string msg = "";
    int max = 0;
    for(int i = 1; i <= n; i++){
        max = 0;
        for(int j = 0; j < i; j++){
            max = mayor(max, m[j] + r[i-j-1]);
            if(m[j] + r[i-j-1] == max) msg = to_string(j+1) + "," + to_string(i-j-1);
        }
        r[i] = max;
    }
    cout << msg << endl;
    return r[n];
}

int main() {
    int n = 8;
    int p[8] = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << cuttingRod(n, p);
    return 0;
}

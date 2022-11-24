#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<double> vec={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    double parameter=5;

    for(auto i : vec)
    {
        double ans= abs((20 - i) / max(int(i), 20)) * parameter ;

        if (ans == 0)
            cout<< i <<"-->"<< 1<<endl;
        else if (ans > 1)
            cout<< i <<"-->"<< 0<<endl;
        else
            cout<< i <<"--->"<< 1 - ans<<endl;

    }

}

// import numpy as np
// import matplotlib.pyplot as plt
// n = [i for i in range(1, 17)]
// values = [0.46, 0.52, 0.58, 0.64, 0.7, 0.76, 0.82, 0.88, 0.94, 1, 0.94, 0.9, 0.86, 0.82, 0.8, 0.77]
// plt.scatter(n, values)
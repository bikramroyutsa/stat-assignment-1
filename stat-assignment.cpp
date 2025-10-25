/*
    Assignment 1, Stat 1103

    This code was written to calculate sample mean, median,
    mode, percentiles, variance, std deviation and to transform
    the dataset

    Bikram Roy Utsa
    bsse1702@iit.du.ac.bd
*/
#include<bits/stdc++.h>
#include<vector>
using namespace std;
float calc_s_mean(vector<int>& data){
    int n = data.size();
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += data[i];
    }
    return (float)sum / n;
}
float calc_s_median(vector<int>& data){
    int n = data.size();
    if(n % 2 == 0){
        return (float)(data[n / 2 - 1] + data[n / 2]) / 2;
    }
    return data[(n + 1) / 2 - 1];
}
int calc_s_mode(vector<int>& data){
    map<int, int> counts;
    for(int i = 0; i < data.size(); i++){
        counts[data[i]]++;
    }
    int max_count = 0;
    int mode = 0;
    for(const auto& pair: counts){
        if(pair.second > max_count){
            max_count = pair.second;
            mode = pair.first;
        }
    }
    return mode;

}
float calc_percentile(vector<int>& data, float p){
    p = p / 100;
    int n = data.size();
    float loc = n * p;
    if(loc == (int)loc){
        return (float)(data[loc - 1] + data[loc]) / 2;
    }
    return data[ceil(loc) - 1];
}
float calc_s_var(vector<int> &data, float s_mean){
    int n = data.size();
    float real_var = 0;
    for(int i = 0; i < n; i++){
        real_var += (data[i] - s_mean) * (data[i] - s_mean);
    }

    cout << "(x - xavg)^2 " << real_var << endl;
    return real_var / (n - 1);
}
void transform_data(vector<int>& data){
    for(int i = 0; i < data.size(); i++){
        cout << 20 + 3 * data[i] << " ";
    }
}
int main(){
    vector<int> data = {
        104, 104, 108, 108, 108, 108, 112, 116, 116, 117, 
        117, 117, 118, 119, 119, 120, 120, 120, 121, 124, 
        128, 130, 132, 132, 132, 133, 133, 134, 134, 135, 
        136, 136, 140, 140, 141, 147, 147, 151, 151, 152
    };
    float mean = calc_s_mean(data);
    float median = calc_s_median(data);
    int mode = calc_s_mode(data);
    float p10 = calc_percentile(data, 10);
    float p25 = calc_percentile(data, 25);
    float p50 = calc_percentile(data, 50);
    float p75 = calc_percentile(data, 75);
    float p90 = calc_percentile(data, 90);
    float var = calc_s_var(data, mean);
    cout << "mean " << mean << " median " << median << " mode " << mode;
    cout << endl;
    cout << "p10  " << p10 <<  " p25 " << p25 << " p50 "<< p50 << " p75 " << p75 << " p90 "<< p90;
    cout << endl;
    cout << "var "  << var << endl;
    cout << "std dev " << sqrt(var) << endl;;

    transform_data(data);
    return 0;
}
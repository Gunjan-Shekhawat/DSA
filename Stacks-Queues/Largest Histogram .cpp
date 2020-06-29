//  PROBLEM : Largest Rectangular Area in a Histogram 
//            Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars.
//            For simplicity, assume that all bars have same width and the width is 1 unit.
//            For example, consider the following histogram with 7 bars of heights {6, 2, 5, 4, 5, 1, 6}. 
//            The largest possible rectangle possible is 12 .

////////////////////////////////////////// CODE ////////////////////////////////////////////////////////////////



#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {
long max_area = 0;
long area_with_top;
long tp;
long i=0;
stack<int>s;
long n = h.size();
while(i<n)
{
    if(s.empty()||h[s.top()]<=h[i])
    {
        s.push(i);
        i++;
    }
    else
    {
        tp = s.top();
        s.pop();
        area_with_top = h[tp]*(s.empty()?i:i-s.top()-1);
        if(area_with_top>max_area)
        max_area = area_with_top;

    }
}
while(!s.empty())
{
    tp = s.top();
    s.pop();
    area_with_top = h[tp]*(s.empty()?i:i-s.top()-1);
    if(area_with_top>max_area)
    max_area = area_with_top;

}
return max_area;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

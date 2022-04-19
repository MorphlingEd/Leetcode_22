#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<functional>
#include<numeric>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */



int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int res = 0;
    vector<int> nums = {min(n - r_q, c_q - 1), n-r_q, min(n - r_q, n - c_q),
                        c_q - 1,                      n - c_q,
                        min(c_q - 1, r_q - 1), r_q-1, min(n - c_q, r_q - 1)};

    for (vector<int>& obs : obstacles){
        int r = obs[0], c = obs[1];
        if (r-r_q == c-c_q){
            if (r > r_q && r - r_q - 1 < nums[2])
                nums[2] = r - r_q - 1;
            else if (r < r_q && r_q - r - 1 < nums[5])
                nums[5] = r_q - r - 1;
        }
        else if (r-r_q == c_q-c){
            if (r > r_q && r - r_q - 1 < nums[7])
                nums[7] = r - r_q - 1;
            else if (r < r_q && r_q - r - 1 < nums[0])
                nums[0] = r_q - r - 1;
        }
        else if (r == r_q){
            if (c > c_q && c - c_q - 1 < nums[4])
                nums[4] = c - c_q - 1;
            else if (c < c_q && c_q - c - 1 < nums[3])
                nums[3] = c_q - c - 1;
        }
        else if (c == c_q){
            if (r > r_q && r - r_q - 1 < nums[1])
                nums[1] = r - r_q - 1;
            else if (r < r_q && r_q - r - 1 < nums[6])
                nums[6] = r_q - r - 1;
        }
    }

    for (int& num : nums)
        res += num;

    return res;
}

int main()
{
//    ofstream fout(getenv("OUTPUT_PATH"));
//
//    string first_multiple_input_temp;
//    getline(cin, first_multiple_input_temp);
//
//    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));
//
//    int n = stoi(first_multiple_input[0]);
//
//    int k = stoi(first_multiple_input[1]);
//
//    string second_multiple_input_temp;
//    getline(cin, second_multiple_input_temp);
//
//    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));
//
//    int r_q = stoi(second_multiple_input[0]);
//
//    int c_q = stoi(second_multiple_input[1]);
//
//    vector<vector<int>> obstacles(k);
//
//    for (int i = 0; i < k; i++) {
//        obstacles[i].resize(2);
//
//        string obstacles_row_temp_temp;
//        getline(cin, obstacles_row_temp_temp);
//
//        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));
//
//        for (int j = 0; j < 2; j++) {
//            int obstacles_row_item = stoi(obstacles_row_temp[j]);
//
//            obstacles[i][j] = obstacles_row_item;
//        }
//    }
//
//    int result = queensAttack(n, k, r_q, c_q, obstacles);
//
//    fout << result << "\n";
//
//    fout.close();
    int n = 8, k = 0;
    cout << queensAttack(n, k, 5, 4, {});
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
            );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
            );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
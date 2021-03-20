#include <iostream>
#include <sstream>
#include <bitset>
#include <vector>
#include <time.h>
using namespace std;

int PC_1[] = {57, 49,  41, 33, 25, 17,  9,
              1 , 58,  50, 42, 34, 26,  18,
              10, 2 ,  59, 51, 43, 35,  27,
              19, 11,  3 , 60, 52, 44,  36,
              63, 55,  47, 39, 31, 23,  15,
              7 , 62,  54, 46, 38, 30,  22,
              14, 6 ,  61, 53, 45, 37,  29,
              21, 13,  5 , 28, 20, 12,  4};

int PC_2[] = {14, 17, 11, 24, 1 , 5 ,
              3 , 28, 15, 6 , 21, 10,
              23, 19, 12, 4 , 26, 8 ,
              16, 7 , 27, 20, 13, 2 ,
              41, 52, 31, 37, 47, 55,
              30, 40, 51, 45, 33, 48,
              44, 49, 39, 56, 34, 53,
              46, 42, 50, 36, 29, 32};

int IP[] = {58, 50, 42, 34, 26, 18, 10, 2,
            60, 52, 44, 36, 28, 20, 12, 4,
            62, 54, 46, 38, 30, 22, 14, 6,
            64, 56, 48, 40, 32, 24, 16, 8,
            57, 49, 41, 33, 25, 17, 9, 1,
            59, 51, 43, 35, 27, 19, 11, 3,
            61, 53, 45, 37, 29, 21, 13, 5,
            63, 55, 47, 39, 31, 23, 15, 7};

int E[] = { 32, 1, 2, 3, 4, 5, 4, 5,
            6, 7, 8, 9, 8, 9, 10, 11,
            12, 13, 12, 13, 14, 15, 16, 17,
            16, 17, 18, 19, 20, 21, 20, 21,
            22, 23, 24, 25, 24, 25, 26, 27,
            28, 29, 28, 29, 30, 31, 32, 1};


int S[8][64] = {{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7, 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8, 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0, 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13},
                {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10, 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5, 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15, 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9},
                {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8, 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1, 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7, 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12},
                {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15, 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9, 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4, 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14},
                {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9, 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6, 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14, 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3},
                {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11, 10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8, 9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6, 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13},
                {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1, 13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6, 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2, 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12},
                {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7, 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2, 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8, 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}};

int P[] = {16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25};

int IP_inv[] = {40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25};

string string_to_binary_ascii(string &input)
{
    stringstream s1;
    for(char &it : input)
    {
        int num = int(it);
        bitset<8> bin(num);
        s1 << bin;
    }
    return s1.str();
}

void generate_subkeys(string K[],string &key)
{
    string kp = "";

    for(int i=0;i<56;++i)
        kp += key[PC_1[i]];

    string C[17] = "";
    string D[17] = "";
    C[0] = kp.substr(0,28);
    D[0] = kp.substr(28,28);
    C[0] = C[0]+C[0];
    D[0] = D[0]+D[0];
    int shifts[] = {0, 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

    string CD[16] = "";

    int s = 0;
    for(int i=1;i<17;++i)
    {
        s += shifts[i];
        C[i] = C[0].substr(s,28);
        D[i] = D[0].substr(s,28);
        CD[i-1] = C[i]+D[i];
        for(int j=0;j<48;++j)
            K[i-1] += CD[i-1][PC_2[j]];
        //cout << K[i-1] << "\n";
    }

}

string string_xor(string &a, string &b)
{
    string ans = "";
    for(int i=0;i<a.length() and i<b.length();++i)
    {
        if(a[i] == b[i])
            ans += "0";
        else
            ans += "1";
    }
    return ans;
}

int binarystring_to_int(string &a)
{
    int ans = 0;
    int base = 1;
    for(int i=a.length()-1;i>=0;--i)
    {
        if(a[i] == '1')
            ans += base;
        base *= 2;
    }
    return ans;
}

string F_function(string &R, string &K)
{
    string ER = "";
    for(int i=0;i<48;++i)
        ER += R[E[i]];

    string RK = string_xor(ER,K);
    string Sp = "";
    for(int i=0;i<48;i+=6)
    {
        string tmp = RK.substr(i,6);
        string two = tmp.substr(0,1)+tmp.substr(5,1);
        string four = tmp.substr(1,4);
        int row = binarystring_to_int(two);
        int col = binarystring_to_int(four);

        int look_s = S[i/6][16*row+col];
        bitset<4> num(look_s);
        stringstream s1;
        s1 << num ;
        Sp += s1.str();
    }
    string ans = "";
    for(int i=0;i<32;++i)
        ans += Sp[P[i]];
    return ans;
}

string DES(string key, string plaintext)
{
    key = string_to_binary_ascii(key);
    plaintext = string_to_binary_ascii(plaintext);
    string K[16] = "";
    generate_subkeys(K,key);
    string M = plaintext;
    string Mp = "";
    for(int i=0;i<64;++i)
        Mp += M[IP[i]];

    string L[17] = "";
    string R[17] = "";
    L[0] = Mp.substr(0,32);
    R[0] = Mp.substr(32,32);


    for(int i=1;i<17;++i)
    {
        L[i] = R[i-1];
        string f = F_function(R[i-1],K[i-1]);
        R[i] = string_xor(L[i-1],f);
    }

    string RL = R[16]+L[16];
    string ciphertext = "";
    for(int i=0;i<64;++i)
        ciphertext += RL[IP_inv[i]];
    return ciphertext;
}

void adjust()
{
    for(auto &it : PC_1)
        it--;
    for(auto &it : PC_2)
        it--;
    for(auto &it : IP)
        it--;
    for(auto &it : E)
        it--;
    for(auto &it : P)
        it--;
    for(auto &it : IP_inv)
        it--;
}

string binarystring_to_hex(string &a)
{
    vector<string> arr;
    string ans = "";
    for(int i=0;i<a.length();i+=4)
        arr.push_back(a.substr(i,4));
    for(auto &it : arr)
    {
        int num = binarystring_to_int(it);
        if(num < 10)
            ans += to_string(num);
        else if(num == 10)
            ans += "A";
        else if(num == 11)
            ans += "B";
        else if(num == 12)
            ans += "C";
        else if(num == 13)
            ans += "D";
        else if(num == 14)
            ans += "E";
        else if(num == 15)
            ans += "F";
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    adjust();
    string key = "12345678";
    string plaintext = "Advanced";

    while(cin >> key >> plaintext)
    {
        clock_t start, end;
        double cpu_time_used;
        start = clock();

        string ciphertext = DES(key,plaintext);
        string answer = binarystring_to_hex(ciphertext);


        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        cout << answer << "\ncpu_time_used: " << cpu_time_used << endl;
    }
}

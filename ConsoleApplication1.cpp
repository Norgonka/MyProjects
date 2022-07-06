#include <iostream>
#include <ctime>
#include <string>
using namespace std;
int Strlen(string a)
{
    int sum = 0;
    for (; a[sum] != '\0'; sum++)
    {

    }
    return sum;
}
int SumOfPoints(string a)
{
    int sum = 0;
    for (int i = 0; i < Strlen(a); i++)
    {
        if (a[i] == 'e' || a[i] == 'a' || a[i] == 'i' || a[i] == 'o' || a[i] == 'n' || a[i] == 'r' || a[i] == 't' || a[i] == 'l' || a[i] == 's' || a[i] == 'u')
        {
            sum++;
        }
        else if (a[i] == 'd' || a[i] == 'g')
        {
            sum += 2;
        }
        else if (a[i] == 'b' || a[i] == 'c' || a[i] == 'm' || a[i] == 'p')
        {
            sum += 3;
        }
        else if (a[i] == 'f' || a[i] == 'h' || a[i] == 'v' || a[i] == 'w' || a[i] == 'y')
        {
            sum += 4;
        }
        else if (a[i] == 'k')
        {
            sum += 5;
        }
        else if (a[i] == 'j' || a[i] == 'x')
        {
            sum += 8;
        }
        else if (a[i] == 'q' || a[i] == 'z')
        {
            sum += 10;
        }
    }
    return sum;
}

int main()
{
    int n;
    cin >> n; cin.ignore();
    string correctword = "";
    string bestword = "";
    int sum = 0;
    int bestsum = 0;
    string* allwords = new string[n];
    for (int i = 0; i < n; i++)
    {
        string w;
        getline(cin, w);
        allwords[i] = w;
    }
    string letters;
    getline(cin, letters);
    for (int i = 0; i < n; i++)
    {
        string word = allwords[i];
        int a = 0;
        string test = letters;
        for (int j = 0; j < Strlen(letters); j++)
        {

            if (word[a] == test[j])
            {
                a++;
                test[j] = '@';
                j = -1;
            }
            if (a == Strlen(word))
            {
                correctword = word;
                sum = SumOfPoints(correctword);
                if (sum > bestsum)
                {
                    bestword = correctword;
                }
            }
        }
    }
    delete[] allwords;
    allwords = nullptr;
    cout << bestword << endl;
}
#include <iostream>
using namespace std;

class MyString
{
    char* str;    
    int length;   

public:
    MyString() 
    {
        length = 80;
        str = new char[length + 1];
    }

    MyString(int size) 
    {
        length = size;
        str = new char[length + 1];
    }

    MyString(const char* input)
    {
        length = 0;
        while (input[length] != '\0') 
        {
            length++;
        }
        str = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            str[i] = input[i];
        }
        str[length] = '\0';
    }

    MyString(const MyString& other) 
    {
        length = other.length;
        str = new char[length + 1];
        for (int i = 0; i < length; i++) 
        {
            str[i] = other.str[i];
        }
        str[length] = '\0';
    }

    ~MyString() 
    {
        delete[] str;
    }

    void input()
    {
        cout << "Enter string: ";
        char temp[1000];
        cin.getline(temp, 1000);
        int newLength = 0;
        while (temp[newLength] != '\0') 
        {
            newLength++;
        }
        delete[] str;
        str = new char[newLength + 1];
        for (int i = 0; i < newLength; i++) 
        {
            str[i] = temp[i];
        }
        str[newLength] = '\0';
        length = newLength;
    }

    void output() const 
    {
        cout << str << endl;
    }

    void MyStrcpy(MyString& obj) 
    {
        delete[] str;
        length = obj.length;
        str = new char[length + 1];
        for (int i = 0; i < length; i++) 
        {
            str[i] = obj.str[i];
        }
        str[length] = '\0';
    }

    bool MyStrStr(const char* substr) 
    {
        int substrLen = 0;
        while (substr[substrLen] != '\0') 
        {
            substrLen++;
        }
        for (int i = 0; i <= length - substrLen; i++)
        {
            int j = 0;
            while (j < substrLen && str[i + j] == substr[j]) 
            {
                j++;
            }
            if (j == substrLen)
            {
                return true;
            }
        }
        return false;
    }

    int MyChr(char c)
    {
        for (int i = 0; i < length; i++) 
        {
            if (str[i] == c) 
            {
                return i;
            }
        }
        return -1;
    }

    int MyStrLen() 
    {
        return length;
    }

    void MyStrCat(MyString& b)
    {
        char* newStr = new char[length + b.length + 1];
        for (int i = 0; i < length; i++)
        {
            newStr[i] = str[i];
        }
        for (int i = 0; i < b.length; i++) 
        {
            newStr[length + i] = b.str[i];
        }
        newStr[length + b.length] = '\0';
        delete[] str;
        str = newStr;
        length += b.length;
    }

    void MyDelChr(char c)
    {
        int newLength = 0;
        for (int i = 0; i < length; i++) 
        {
            if (str[i] != c) {
                newLength++;
            }
        }
        char* newStr = new char[newLength + 1];
        int j = 0;
        for (int i = 0; i < length; i++)
        {
            if (str[i] != c) 
            {
                newStr[j++] = str[i];
            }
        }
        newStr[newLength] = '\0';
        delete[] str;
        str = newStr;
        length = newLength;
    }

    int MyStrCmp(MyString& b) 
    {
        for (int i = 0; i < length && i < b.length; i++) 
        {
            if (str[i] < b.str[i])
            {
                return -1;
            }
            if (str[i] > b.str[i]) 
            {
                return 1;
            }
        }
        if (length < b.length) 
        {
            return -1;
        }
        if (length > b.length)
        {
            return 1;
        }
        return 0;
    }
};

int main() 
{
    MyString s1("Hip");
    MyString s2("Hop");

    cout << "Source string:\n";
    s1.output();
    s2.output();

    MyString s3 = s1;
    cout << "Copy string s1 (s3):\n";
    s3.output();

    cout << "String comparison s1 and s2: " << s1.MyStrCmp(s2) << endl;

    s1.MyStrCat(s2);
    cout << "After the merger s1 and s2:\n";
    s1.output();

    s1.MyDelChr('и');
    cout << "After deleting symbol 'i' from s1:\n";
    s1.output();

    return 0;
}
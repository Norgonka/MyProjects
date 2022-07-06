#include <iostream>
using namespace std;
class MyString
{
public:
	MyString()
	{
		str = nullptr;
	};
	MyString(const char* str) 
	{
		this->length = strlen(str);
		this->str = new char[this->length + 1];
		for (int i = 0; i < this->length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[this->length] = '\0';
	};
	~MyString()
	{
		delete[] this->str;
		this->str = nullptr;
	};
	MyString(const MyString& other)
	{
		
		int length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
	}
	MyString &operator =(const MyString &other)
	{
		if (this->str != nullptr)
		{
			delete[] str;
		}
		int length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
		return *this;
	}
	MyString operator+(const MyString& other)
	{
		MyString result;
		int length1 = strlen(this->str);
		int length2 = strlen(other.str);
		int length3 = length1 + length2;
		int k = 0;
		result.str = new char[length3 + 1];
		for (int i = 0; i < length1; i++)
		{
			result.str[i] = this->str[i];
		}
		for (int j = length1; j < length3; j++, k++)
		{
			result.str[j] = other.str[k];
		}
		result.str[length3] = '\0';
		return result;
	}
	int	Length()
	{
		return this->length;
	}
	bool operator ==(const MyString &other)
	{
		bool result = this->length == other.length ? true : false;
		if (result == true)
		{
			for (int i = 0; i < length; i++)
			{
				result = this->str[i] == other.str[i];
				if (result == false)
				{
					break;
				}
			}
		}
		return result;
	}
	bool operator !=(const MyString& other)
	{
		bool result = this->length == other.length ? true : false;
		if (result == true)
		{
			for (int i = 0; i < length; i++)
			{
				result = this->str[i] == other.str[i];
				if (result == false)
				{
					break;
				}
			}
		}
		return (result == false) ? true : false;
	}
	char &operator[](int i)
	{
		return this->str[i];
	}
	void Print()
	{
		for (int i = 0; i < this->length; i++)
		{
			cout << this->str[i];
		}
	}
private:
	char* str;
	int length;
};
int main()
{
	MyString str("Hello");
	MyString str2("Hello");
	str[2] = 'e';
	str.Print();
	return 0;
}



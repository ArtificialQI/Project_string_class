#include<iostream>
using namespace std;




class my_string
{
public:

	my_string ()
	{
		str = nullptr;
		length = 0;
	}


	my_string(const char* str)
	{
		 length = strlen(str);

		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
			this->str[i] = str[i];

		this->str[length] = '\0';
	}

	~my_string()
	{
		delete[] this->str;
	}

	my_string(const my_string& other)
	{
		 length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';
	}

	my_string& operator =(const my_string & other)
	{
		if (this->str != nullptr)
			delete[] str;

		  length = strlen(other.str);

		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
			this->str[i] = other.str[i];

		this->str[length] = '\0';

		return *this;
	}

	my_string operator+(const my_string other)
	{
		
		my_string new_str;
		

		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);

		new_str.length = thisLength + otherLength;

		
		new_str.str = new char[thisLength + otherLength + 1];

		
		int i = 0;
		for (; i < thisLength; i++)
		{
			new_str.str[i] = this->str[i];
		}

		for (int j = 0; j < otherLength; j++, i++)
		{
			new_str.str[i] = other.str[j];
		}

		new_str.str[thisLength + otherLength] = '\0';

		
		return new_str;
	}

	void print()
	{
		cout << str;
	}

	int Length()
	{
		return length;
	}


	bool operator ==(const my_string& other)
	{
		if (this->length != other.length)
			return false;

		for (int i = 0; i < this->length; i++)
			if (this->str[i] != other.str[i])
				return false;
		return true;
			
	}

	bool operator !=(const my_string& other)
	{
		return !(this->operator ==(other));
	}

	char & operator [](int index)
	{
		return this->str[index];
	}

	my_string (my_string&& other) noexcept
	{
		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;
	}
private:
	char* str;
	int length;
};




int main()
{

	my_string str1("Hello");
	my_string str2("World");

	my_string res;

	res = str1 + str2;

	res.print();
	

	return 0;
}

#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

class IPAddress
{
public:
	IPAddress(string ip)
	{
		istringstream iss(ip);
		string token;
		while (getline(iss, token, '.'))
		{
			parts.push_back(stoi(token));
		}
		if (parts.size() != 4 || !isValid()) {
			cout << "Invalid IP address" << endl;
		}
	}
	bool isValid()
	{
		for (auto i : parts)
		{
			if (i < 0 || i > 255) return false;
		}
		return true;
	}
	void printIP()
	{
		string str_ip;
		for (int i = 0; i < parts.size(); i++)
		{
			str_ip += to_string(parts[i]);
			if (i != parts.size() - 1)
			{
				str_ip += '.';
			}
		}
		cout << str_ip << endl;
	}
private:
	vector<int> parts;
};


int main()
{
	IPAddress ip1("192.168.1.1");
	ip1.printIP();
}
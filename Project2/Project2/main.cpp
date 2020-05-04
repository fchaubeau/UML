#include <iostream>
#include <string>

using namespace std;

void menu()
{
	string buffer = "";

	cout << "===============AirWatcher===============" << endl;
	cout << "1 : Log-in" << endl
		<< "2 : Sign-in" << endl
		<< " > ";
	cin >> buffer;

	if (buffer.compare("1"))
	{
		bool isLoggedIn = false;
		while (!isLoggedIn)
		{
			cout << "EMail : ";
			string email = "";
			cin >> email;
			cout << "Password";
			string password = "";
			cin >> password;
		}
	}

	bool applicationClosed = false;
	while (!applicationClosed)
	{
		cout << endl;
		cout << "1 : ";
	}

	//try to connect
}


int main()
{
	return 0;
}
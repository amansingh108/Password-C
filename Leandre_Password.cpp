#include <iostream>					
#include <cstring>					//for cin.getline and strcmp
#include <cctype>					//for testing users entries indexes
using namespace std;

int main()
{
	const int SIZE = 80;				//const size of c-string
	char password[SIZE];				//users first password entry
	char password2[SIZE];			//users re-entered password entry
	int i;						//counter for password c-string
	int dig, low, up, error;				/*counters for the number of digits and lower and uppercase letters entered*/
	bool check;					//checks to see it password and password2 are equal

	cout << "\nCreate a password that meets the following requirements:" << endl;
    cout << "atleast 6 characters'" << endl;
    cout << "atleast 1 lowercase and uppercase letter" << endl;
    cout << "atleast 1 number" << endl << endl;
    do
	{

        cout << "Enter a password: ";
		cin.getline(password, SIZE, '\n');

		/*initialize variables counters here rather than the beginning; ruins program*/
		dig = 0;
		low = 0;
		up = 0;
		error = 0;

		for (i = 0; password[i] != '\0'; i++)		/*checks each entry to see if its a digit, lower or uppercase letter*/
		{
			if (isdigit(password[i]))
				dig++;				//adds one every time entry is digit
			else if (islower(password[i]))
				low++;				//adds one every time entry is lowercase
			else if (isupper(password[i]))
				up++;				//adds one every time entry is uppercase
			else if (ispunct(password[i]))
				error++;			//adds one every time entry is random symbol
			else
				break;				//breaks if neither
		}
	
		if (strlen(password) == 0)
		    cout << "Please enter a password" << endl;
		
        else
		{
            if (error > 0)
		        cout << "Password can only contain digits, and lowercase and uppercase letters" << endl;
		    
            else
            {
                if (strlen(password) < 6)			//if users entry is less than 6 characters long
		            cout << "Password needs to have 6 or more characters" << endl;
	            if (low == 0)					//if users entry contains no lowercase letters
		            cout << "Password needs to contain at least one lowercase letter" << endl;
		        if (up == 0)					//if users entry contains no uppercase letters
		            cout << "Password needs to contain at least one uppercase letter" << endl;
		        if (dig == 0)					//if users entry contains no digits
			        cout << "Password needs to contain at least one digit" << endl;
            }
		}	
        
        if (strlen(password) >= 6 && dig > 0 && low > 0 && up > 0 && error == 0)
		{
			cout << "Now re-enter you password for verification: ";
			cin.getline(password2, SIZE, '\n');
            check = strcmp(password, password2);		//checks if password = password2

			if (check == 0)
			{
				cout << endl << "You have now entered a valid password." << endl;
                cout << "Goodbye.";
				cout << endl << endl;
				break;				//ends program if password = password2 are equal
			}
			else
				cout << endl << "Password does not match. Start over." << endl;		//else program continues
		}
        
		cout << endl;

	} while (password != password2);			//program will continue to run as long as password != password2

	return 0;
}
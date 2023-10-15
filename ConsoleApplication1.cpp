#include<iostream>
#include<array>
#include<string>
#include<sstream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h> 
#include <fstream>
#include <chrono>
#include <ctime>
#include<time.h>
#include <iomanip>


using namespace std;
class Bookitems {
public:
	int book_id;
	int goodreads_book_id;
	int best_book_id;
	int work_id;
	int books_count;
	string isbn;
	long long isbn13;
	string authors;
	double original_publication_year;
	string original_title;
	string title;
	string language_code;
	double average_rating;
	int ratings_count;
	int work_ratings_count;
	int work_text_reviews_count;
	int ratings_1;
	int ratings_2;
	int ratings_3;
	int ratings_4;
	int ratings_5;
	string image_url;
	string small_image_url;
	bool isFloat(string input) {
		try {
			// Attempt to convert the input to a float
			float floatValue = stof(input);
			return true; // Conversion succeeded; input is a float
		}
		catch (exception& e) {
			return false; // Conversion failed; input is not a float
		}
	}


	int read_csv_book(array<Bookitems, 99>& books) {
	//C:\Users\shree\OneDrive\Desktop\oopd2
		ifstream file("books.csv");
		if (!file.is_open()) {
			cout << "Could not open file." << endl;
			return 0;
		}
		string line;
		getline(file, line);
		int record_count = 0;
		int MAX_RECORDS = 100;


		while (getline(file, line) && record_count < MAX_RECORDS) {
			stringstream ss(line);
			string field;

			Bookitems& book = books[record_count];

			// Read each field and assign it to the corresponding member of the Book class
			getline(ss, field, ',');
			book.book_id = stoi(field);

			//for skip purpose
			getline(ss, field, ',');
			getline(ss, field, ',');
			getline(ss, field, ',');

			getline(ss, field, ',');
			book.books_count = stoi(field);

			getline(ss, field, ',');
			book.isbn = field;

			//for isbn13
			getline(ss, field, ',');

			//for authors
			getline(ss, field, ',');
			bool flag = 1;
			string authorNames = field;
			while (flag) {
				getline(ss, field, ',');
				if (isFloat(field) == true) {
					flag = 0;
				}
				else
					authorNames = authorNames + ", " + field;

			}
			book.authors = authorNames;

			getline(ss, field, ',');
			book.original_title = field;

			record_count++;
		}
		// Close the file
		file.close();

	}
	void displayBooks(array<Bookitems, 99>& books) {
		for (Bookitems& book : books) {
			cout << "Book ID: " << book.book_id << ", Title: " << book.original_title << ",average_rating " << book.average_rating << endl;
		}
	}


	bool is_book_available(array<Bookitems, 99>& books, int B_id) {
		for (Bookitems& book : books) {
			if (book.book_id == B_id) {
				if (book.books_count > 0) {
					cout << "\n\t\t book is available at shelf " << (B_id) % 10 << endl;
					return true;
				}
			}
		}
		cout << "\n\t\t book is not available";
		return false;
	}
};

class magazineitems {
public:
	string publication;
	string rank;
	string totalPaid;
	string wordRate;
	string daysToBePaid;
	string paymentDifficulty;
	string rank_totalPaid;
	string rank_wordRate;
	string rank_daysToBePaid;
	string rank_paymentDifficulty;
	int read_csv_magazine(array<magazineitems, 81>& magazines) {
		//C:\Users\shree\OneDrive\Desktop\oopd2
		//magazine
		ifstream file("magazine.csv");
		if (!file.is_open()) {
			cout << "Could not open file." << endl;
			return 0;
		}
		string line;
		getline(file, line);
		int record_count = 0;
		int MAX_RECORDS = 82;


		while (getline(file, line) && record_count < MAX_RECORDS) {
			stringstream ss(line);
			string field;

			magazineitems& magazine = magazines[record_count];

			// Read each field and assign it to the corresponding member of the magazinesitems class
			getline(ss, field, ',');
			string result = field.substr(1, field.size() - 2);
			magazine.publication = result;

			

			getline(ss, field, ',');
			//stringstream geek;
			//geek << field;
			string result1 = field.substr(1, field.size() - 2);
			magazine.rank = result1;

			getline(ss, field, ',');
			magazine.totalPaid = field;

			getline(ss, field, ',');
			magazine.wordRate = field;

			getline(ss, field, ',');
			magazine.daysToBePaid = field;

			getline(ss, field, ',');
			magazine.paymentDifficulty = field;

			getline(ss, field, ',');
			magazine.rank_totalPaid = field;

			getline(ss, field, ',');
			magazine.rank_wordRate = field;

			getline(ss, field, ',');
			magazine.rank_daysToBePaid = field;
			getline(ss, field, ',');
			magazine.rank_paymentDifficulty = field;

			record_count++;
		}
		// Close the file
		file.close();

	}
	void displayMagazines(array<magazineitems, 81>& magazines) {

		for (magazineitems& magazine : magazines) {
			cout << "publication: " << magazine.publication << ", rank: " << magazine.rank << ",tatalPaid" << magazine.totalPaid << endl;
		}
	}

	bool is_magazine_available(array<magazineitems, 81>& magazines, string keys) {
		for (magazineitems& magazine : magazines) {
			if (magazine.rank == keys) {
				cout << "\n\t\t magazine is available on shell "<<(stoi(keys)+17)%10;
				return true;

			}
		}
		cout << "\n\t\t magazine is not available";
		return false;
	}
};







class User {
public:
	string Fname, Lname;
	string BookIssued[10];
};
class Student :public User {
public:
	int rollNo;
	void Register()
	{
		cout << "\n\t\tNEW STUDENT Registration...\n";
		cout << "\n\t\tEnter The Roll No.";
		cin >> rollNo;
		cout << "\n\t\tEnter The First Name ";
		cin >> Fname;
		cout << "\n\t\tEnter The Last Name ";
		cin >> Lname;
		cout << "\n\t\tStudent Register successfully...\n";
	}
};

class Faculty :public User {
public:
	int ID;
	string dept;

	void Register()
	{
		cout << "\n\t\tNEW Faculty Registration...\n";
		cout << "\n\t\tEnter The Department name.";
		cin >> dept;
		cout << "\n\t\tEnter The First Name ";
		cin >> Fname;
		cout << "\n\t\tEnter The Last Name ";
		cin >> Lname;
		cout << "\n\t\tEnter The ID ";
		cin >> ID;
		cout << "\n\tFaculty register successful...\n";

	}
};

Student students[100];
int stud_count = 0;

Faculty faculties[100];
int fac_count = 0;

class BorrowBook{
public:
	void borrow(array<Bookitems, 99>& books, int B_id,
		int type) {
		//type->1 for stud
		//type->2 for teacher
		int ID;
		cout << "Enter ID no /rollNo:\t";
		cin >> ID;
		int x = 0;
		int y = 0;
		if (type == 1) {
			for (Student &find : students) {
				if (find.rollNo == ID) {
					x = 1;
					break;
				}
			}
			if (x == 1) {
				for (Bookitems& book : books) {
					if (book.book_id == B_id) {
						book.books_count = book.books_count - 1;
						cout << "Book has been issued to ID no:" << ID << endl;

						std::time_t t = std::time(nullptr);
						std::tm now;
						int monthsToAdd = 1;
						//Use localtime_s for thread safety
						if (localtime_s(&now, &t) != 0) {
							std::cerr << "Error in localtime_s" << std::endl;
							return;


							// Set the time to the current date
							std::tm futureDate = now;

							// Add months to the date
							futureDate.tm_mon += monthsToAdd;

							// Normalize the date (adjust year and month if necessary)
							if (std::mktime(&futureDate) == -1) {
								std::cerr << "Error in mktime" << std::endl;
								return;
							}

							// Display the future date
							std::cout << "Daue date: ";
							cout << std::put_time(&futureDate, "%Y-%m-%d") << std::endl;
						}
					}
				}
			}
			else
				cout << "user not register:";
	
			
		}
		if (type == 2) {
			for (Faculty& find : faculties) {
				if (find.ID== ID) {
					y = 1;
					break;
				}
			}
			if (y == 1) {
				for (Bookitems& book : books) {
					if (book.book_id == B_id) {
						book.books_count = book.books_count - 1;
						cout << "Book has been issued to ID no:" << ID<<endl;
						std::time_t t = std::time(nullptr);
						std::tm now;
						int monthsToAdd = 6;
						// Use localtime_s for thread safety
						if (localtime_s(&now, &t) != 0) {
							std::cerr << "Error in localtime_s" << std::endl;
							return;
						}

						// Set the time to the current date
						std::tm futureDate = now;

						// Add months to the date
						futureDate.tm_mon += monthsToAdd;

						// Normalize the date (adjust year and month if necessary)
						if (std::mktime(&futureDate) == -1) {
							std::cerr << "Error in mktime" << std::endl;
							return;
						}

						// Display the future date
						std::cout << "Daue date: ";
						cout << std::put_time(&futureDate, "%Y-%m-%d") << std::endl;

					}
				}
			}
			else
				cout << "user not register:";


		}

	}

				
};

class BorrowMagazine {
public:
	void borrowM(array<magazineitems, 81>& magazines, string keys,
		int type) {
		//type->1 for stud
		//type->2 for teacher
		int ID;
		cout << "Enter ID no /rollNo:\t";
		cin >> ID;
		int x = 0;
		int y = 0;
		if (type == 1) {
			for (Student& find : students) {
				if (find.rollNo == ID) {
					x = 1;
					break;
				}
			}
			if (x == 1) {
				for (magazineitems& magazine : magazines) {
					if (magazine.rank==keys) {
						cout << "magazines has been issued to ID no:" << ID << endl;

						std::time_t t = std::time(nullptr);
						std::tm now;
						int monthsToAdd = 1;
						// Use localtime_s for thread safety
						if (localtime_s(&now, &t) != 0) {
							std::cerr << "Error in localtime_s" << std::endl;
							return;
						}

						// Set the time to the current date
						std::tm futureDate = now;

						// Add months to the date
						futureDate.tm_mon += monthsToAdd;

						// Normalize the date (adjust year and month if necessary)
						if (std::mktime(&futureDate) == -1) {
							std::cerr << "Error in mktime" << std::endl;
							return;
						}

						// Display the future date
						std::cout << "Daue date: ";
						cout << std::put_time(&futureDate, "%Y-%m-%d") << std::endl;
					}
				}
			}
			else
				cout << "user not register:";


		}
		if (type == 2) {
			for (Faculty& find : faculties) {
				if (find.ID == ID) {
					y = 1;
					break;
				}
			}
			if (y == 1) {
				for (magazineitems& magazine : magazines) {
					if (magazine.rank==keys) {
						cout << "magazines has been issued to ID no:" << ID << endl;
						std::time_t t = std::time(nullptr);
						std::tm now;
						int monthsToAdd = 6;
						// Use localtime_s for thread safety
						if (localtime_s(&now, &t) != 0) {
							std::cerr << "Error in localtime_s" << std::endl;
							return;
						}

						// Set the time to the current date
						std::tm futureDate = now;

						// Add months to the date
						futureDate.tm_mon += monthsToAdd;

						// Normalize the date (adjust year and month if necessary)
						if (std::mktime(&futureDate) == -1) {
							std::cerr << "Error in mktime" << std::endl;
							return;
						}

						// Display the future date
						std::cout << "Daue date: ";
						cout << std::put_time(&futureDate, "%Y-%m-%d") << std::endl;

					}
				}
			}
			else
				cout << "user not register:";


		}

	}
};

class Electronicitems {
public:
	int E_id;
	string Title;

	int read_csv_journal(array<Electronicitems, 99>& electronic) {
		//C:\Users\shree\OneDrive\Desktop\oopd2\ConsoleApplication1
		//magazine
		ifstream file("journals.csv");
		if (!file.is_open()) {
			cout << "Could not open file." << endl;
			return 0;
		}
		string line;
		int record_count = 0;
		int MAX_RECORDS = 100;
		int count = 1;

		while (getline(file, line) && record_count < MAX_RECORDS) {
			stringstream ss(line);
			string field;

			Electronicitems& journals = electronic[record_count];

			// Read each field and assign it to the corresponding member of the Electronicitems class
			//getline(ss, field, ',');
			//string result = field.substr(1, field.size() - 2);
			journals.Title = line;
			journals.E_id = count;
			count++;
			record_count++;

		}
		// Close the file
		file.close();
	}

	void displayElectronic(array<Electronicitems, 99>& electronic) {
		for (Electronicitems& journal : electronic) {
			cout << "E_ID: " << journal.E_id << ", Title: " << journal.Title<<endl;
		}
	}

	bool is_journal_available(array<Electronicitems, 99>& electronic, int E_id) {
		for (Electronicitems& journal : electronic) {
			if (journal.E_id == E_id) {
				cout << "\n\t\t magazine is available on shell "<<endl;
				return true;

			}
		}
		cout << "\n\t\t magazine is not available";
		return false;
	}


};

class BorrowJournal {
public:
	void borrowE(array<Electronicitems, 99>& electronic, int E_id,
		int type) {
		//type->1 for stud
		//type->2 for teacher
		int ID;
		cout << "Enter ID no /rollNo:\t";
		cin >> ID;
		int x = 0;
		int y = 0;
		if (type == 1) {
			for (Student& find : students) {
				if (find.rollNo == ID) {
					x = 1;
					break;
				}
			}
			if (x == 1) {
				for (Electronicitems& journal : electronic) {
					if (journal.E_id == E_id) {
						cout << "Journal has been issued to ID no:" << ID << endl;
					}
				}
			}
			else
				cout << "user not register:";


		}
		if (type == 2) {
			for (Faculty& find : faculties) {
				if (find.ID == ID) {
					y = 1;
					break;
				}
			}
			if (y == 1) {
				for (Electronicitems& journal : electronic) {
					if (journal.E_id == E_id) {
						cout << "journal has been issued to ID no:" << ID << endl;
						
					}
				}
			}
			else
				cout << "user not register:";


		}

	}


};

class purchaseitems {
public:
	int book_id;
	string title;
	float Book_price;

	int read_csv_purchase(array<purchaseitems, 20>& buy) {
		//C:\Users\shree\OneDrive\Desktop\oopd2\ConsoleApplication1
		//magazine
		ifstream file("purchase.csv");
		if (!file.is_open()) {
			cout << "Could not open file." << endl;
			return 0;
		}
		string line;
		int record_count = 0;
		int MAX_RECORDS = 21;
		getline(file, line);
		while (getline(file, line) && record_count < MAX_RECORDS) {
			stringstream ss(line);
			string field;

			purchaseitems& purchase = buy[record_count];

			getline(ss, field, ',');
			purchase.book_id = stoi(field);

			getline(ss, field, ',');
			purchase.title = field;

			getline(ss, field, ',');
			purchase.Book_price = stoi(field);

			record_count++;

		}
		// Close the file
		file.close();
	}

	void displayBuyitem(array<purchaseitems, 20>& buy) {
		for (purchaseitems& purchase : buy) {
			cout << "Book_id: " << purchase.book_id << ", Title: " << purchase.title <<",Book_price: "<<purchase.Book_price<<endl;
		}
	}

	int is_Bookbuy_available(array<purchaseitems, 20>& buy, int B_id) {
		for (purchaseitems& Bookbuy : buy) {
			if (Bookbuy.book_id== B_id) {
				cout << "\n\t\t book is available for purchase \t\t\n" << endl;
				return Bookbuy.Book_price;

			}
		}
		cout << "\n\t\t out of stock\n";
		return 0;
	}
	
	

};


	int main() {
     cout << "\n\t\t\t\t---LIBRARY MANAGEMENT SYSTEM ---\n" << "\n\t\t\t";

		array<Bookitems, 99> books;
		array<magazineitems, 81> magazines;
		array<Electronicitems, 99> electronic;
		array<purchaseitems, 20> buy;
		float x = 0;
		int i = 1;
		int choice;
		do
		{
			cout << "\n\t\t>>Please Choose Any Option To proceed \n";
			cout << "\n\t\t1.User Registration\n";
			cout << "\n\t\t2.Borrow\n";
			cout << "\n\t\t3.purchase\n";
			cout << "\n\t\t4.search Bookitems\n";
			cout << "\n\t\t5.Book on budget\n";
			cout << "\n\t\t0.Exit\n";
			cout << "\n\t\tEnter your choice(only integer allow) : ";
			// Prompt the user for input
			cin >> choice;
			system("cls");
			char ch;
			Bookitems bookfile;
			magazineitems magazinefile;
			Electronicitems journalfile;
			purchaseitems purchasefile;
			purchaseitems buyfile;

				switch(choice) {
				case 1:
					cout << "\n\t\t\t\t---LIBRARY MANAGEMENT SYSTEM ---\n" << "\n\t\t\t";
					cout << "\n\t\ta.register Student\n";
					cout << "\n\t\tb.register Teacher\n";
					cout << "\n\t\tEnter your choice : ";
					cin >> ch;
					system("cls");
					if (ch == 'a') {
						cout << "\n\t\t\t\t******** LIBRARY MANAGEMENT SYSTEM *******\n" << "\n\t\t\t";
						cout << "\n\t\t\t\t\t\tCreating new student...\n";
						//create array of student
						Student stud;
						stud.Register();
						students[stud_count] = stud;
						stud_count++;
						_getch();
						system("cls");
					}

					 if (ch == 'b') {
						cout << "\n\t\t\t\t---LIBRARY MANAGEMENT SYSTEM ---\n" << "\n\t\t\t";
						cout << "\n\t\t\t\t\tregister new faculty...\n";
						//create array of faculty
						Faculty fac;
						fac.Register();
						faculties[fac_count] = fac;
						fac_count++;
						_getch();
						system("cls");
					}
					if(ch != 'a' || ch != 'b')
						cout << "\n\t\tinvalid choice please try again\n";
					break;
				case 2:
					cout << "\n\t\t\t\t--- LIBRARY MANAGEMENT SYSTEM ---\n" << "\n\t\t\t";
					cout << "\n\t\t\t\t\t\t\tBorrow feature loading...\n";

					bookfile.read_csv_book(books);
					magazinefile.read_csv_magazine(magazines);

					cout << "\n\t\ta.Borrow Books\n";
					cout << "\n\t\tb.Borrow Electronic Item\n";
					cout << "\n\t\tc.Borrow Magzines\n";
					cout << "\n\t\tEnter your choice : ";
					cin >> ch;
					system("cls");
					if (ch == 'a') {
						cout << "\n\t\t\t\t---LIBRARY MANAGEMENT SYSTEM ---\n" << "\n\t\t\t";
						cout << "\n\t\t\t\t\tBook Borrow Feature loading...\n";
						cout << "\n\t\t\t\t\tThe books are available below...\n";
						bookfile.displayBooks(books);

						cout << "\n\n\t\t\t\t\tplease Enter the book ID:\t\t";
						int B_id;
						cin >> B_id;
						if (bookfile.is_book_available(books, B_id)) {
							cout << "\n\t\t\t\t\tWhom to be issued?\t\t";
							cout << "\n\t\t\t\t\t1.Student\t\t\t\t2.Faculty\n";
							int get_input;
							cout << "\n\t\t\t\t\tEnter choice:\t";
							cin >> get_input;
							if (get_input == 1) {
								//Student borrow
								BorrowBook Borrow_Book;
								Borrow_Book.borrow(books, B_id, 1);
							}
							if (get_input == 2) {
								//Teacherborrow
								BorrowBook Borrow_Book;
								Borrow_Book.borrow(books, B_id, 2);
							}
						}
					}

					if (ch == 'c') {
						cout << "\n\t\t\t\t---LIBRARY MANAGEMENT SYSTEM ---\n" << "\n\t\t\t";
						cout << "\n\t\t\t\t\tBook Borrow Feature loading...\n";
						cout << "\n\t\t\t\t\tThe magazines are available below...\n";
						magazinefile.displayMagazines(magazines);

						cout << "\n\n\t\t\t\t\tplease Enter the magazines rank:\t\t";
						string input;
						cin >>input;
                         if (magazinefile.is_magazine_available(magazines,input)) {
							cout << "\n\t\t\t\t\tWhom to be issued?\t\t";
							cout << "\n\t\t\t\t\t1.Student\t\t\t\t2.Faculty\n";
							int get_input;
							cout << "\n\t\t\t\t\tEnter choice:\t";
							cin >> get_input;
							if (get_input == 1) {
								//Student borrow
								BorrowMagazine Borrow_magazines;
								Borrow_magazines.borrowM(magazines, input, 1);
							}
							if (get_input == 2) {
								//Teacherborrow
								BorrowMagazine Borrow_magazines;
								Borrow_magazines.borrowM(magazines, input, 2);
							}
						}
						


					}
					
					if (ch == 'b') {
						cout << "\n\t\t\t\t---LIBRARY MANAGEMENT SYSTEM ---\n" << "\n\t\t\t";
						cout << "\n\t\t\t\t\tBook Borrow Feature loading...\n";
						cout << "\n\t\t\t\t\tThe Journal are available below...\n";
						journalfile.read_csv_journal(electronic);
						journalfile.displayElectronic(electronic);

						cout << "\n\n\t\t\t\t\tplease Enter the electronic ID:\t\t";
						int input;
						cin >> input;
						if (journalfile.is_journal_available(electronic, input)) {
							cout << "\n\t\t\t\t\tWhom to be issued?\t\t";
							cout << "\n\t\t\t\t\t1.Student\t\t\t\t2.Faculty\n";
							int get_input;
							cout << "\n\t\t\t\t\tEnter choice:\t";
							cin >> get_input;
							if (get_input == 1) {
								//Student borrow
								BorrowJournal Borrow_magazines;
								Borrow_magazines.borrowE(electronic, input, 1);
							}
							if (get_input == 2) {
								//Teacherborrow
								BorrowJournal Borrow_magazines;
								Borrow_magazines.borrowE(electronic, input, 2);
							}
						}
					}
						
					break;
				case 3:
					cout << "\n\t\t\t\t---LIBRARY MANAGEMENT SYSTEM ---\n" << "\n\t\t\t";
					cout << "\n\t\t\t\t\tBook purchase Feature loading...\n";
					cout << "\n\t\t\t\t\tThe below books are available for purchase...\n";
					purchasefile.read_csv_purchase(buy);
					purchasefile.displayBuyitem(buy);

					cout << "\n\n\t\t\t\t\tplease Enter the book ID:\t\t";
					int input;;
					cin >> input;;
					x = purchasefile.is_Bookbuy_available(buy, input);
					float budget;
					if (x > 0) {
						cout << "\t\tenter budget : ";
						cin >> budget;
						if (x <= budget)
							cout << "\t\t Book purchase successfully\t\t reamining budget="<<budget-x;
						else
							cout << "\t\tout of budget\t\t";
					}
	
					break;
				case 4:
					bookfile.read_csv_book(books);
					
						int B_id;
						cout << "enter B00k_id: ";
						cin >> B_id;
						bookfile.is_book_available(books, B_id);
					break;


				case 5:
					cout << "\n\t\t\t\t---LIBRARY MANAGEMENT SYSTEM ---\n" << "\n\t\t\t";
					cout << "\n\t\t\t\t\tBook on loan Feature loading...\n";
					cout << "\n\t\t\t\t\tThe below books are available on loan...\n";
					buyfile.read_csv_purchase(buy);
					buyfile.displayBuyitem(buy);

					cout << "\n\n\t\t\t\t\tplease Enter the book ID :";
					int Bid;
					cin >> Bid;
					cout << "\n\n\t\t\t Enter the budget :";
					float LibBudget;
					cin >> LibBudget;
					while (LibBudget) {
						 x = purchasefile.is_Bookbuy_available(buy, Bid);

						purchaseitems& file = buy[Bid];
						if (LibBudget >= x) {
							cout << i << file.book_id << file.title << " ," << file.Book_price << endl;
							i++;
							LibBudget = LibBudget - x;
							Bid++;
						}
						else
							LibBudget = 0;
				}
					break;

				case 0:
					cout << "Exiting the program." << endl;
					break;

				default:
					cout << "\n\t\tInvalid choice. Please try again." << endl;
					break;

				}
			
		} while (choice);


		return 0;
	}
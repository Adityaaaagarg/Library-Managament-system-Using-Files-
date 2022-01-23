#include <bits/stdc++.h>
using namespace std;

class student
{
    char first_name[15];
    char last_name[15];
    int admission_num;
    char clas[28];
    int no_of_books_issued = 0;

public:
    friend void issue_book();
    friend void deposit_book();
    void print()
    {
        student a;
        ifstream view;
        view.open("student.dat", ios::in | ios::binary);
        if (!view)
        {
            cout << "\nFile not found\n";
            return;
        }
        view.seekg(0, ios::end);
        int len = view.tellg();
        view.seekg(0);

        if (len)
        {
            cout << "\n=============================================================================================";
            cout << "====================\n";
            cout << "Student's name" << setw(40) << "Student's admission number";
            cout << setw(30) << "Class of the student" << setw(30) << "Number of books issued\n";
            cout << "=============================================================================================";
            cout << "====================\n";
            view.seekg(0);
            view.read((char *)&a, sizeof(a));
            do
            {
                string s = a.first_name;
                int y = s.size();
                if (y > 15)
                {
                    y = 15;
                }
                for (int i = 0; i < y; i++)
                {
                    cout << s[i];
                }
                for (int j = 0; j < 28 - y; j++)
                {
                    cout << ' ';
                }
                cout << a.admission_num << setw(35) << a.clas;
                cout << "\t\t\t\t" << a.no_of_books_issued;
                cout << endl;
                s = a.last_name;
                y = s.size();
                if (y > 15)
                {
                    y = 15;
                }
                for (int i = 0; i < y; i++)
                {
                    cout << s[i];
                }
                cout << endl;
                cout << "-------------------------------------------------------------------------------------------";
                cout << "----------------------\n";
                view.read((char *)&a, sizeof(a));
            } while (view.eof() == 0);
            cout << endl;
        }
        else
        {
            cout << "\nFile is empty\n\n";
        }
        view.close();
        system("Pause");
    }

    void add_student()
    {
        ofstream add;
        student st;
        add.open("student.dat", ios::app | ios::binary);
        cout << "Enter the student's first name(Max 15 character) : ";
        fflush(stdin);
        cin >> st.first_name;
        cout << "Enter the student's last name(Max 15 character) : ";
        fflush(stdin);
        cin >> st.last_name;
        cout << "Enter admission number(6 Digit) : ";
        cin >> st.admission_num;
        cout << "Enter class of student : ";
        fflush(stdin);
        cin >> st.clas;

        add.seekp(ios::end);
        add.write((char *)&st, sizeof(st));
        add.close();
        cout << "\nStudent added\n";
        system("Pause");
    }

    void print_specific()
    {
        ifstream find;
        find.open("student.dat", ios::in | ios::binary);
        if (!find)
        {
            cout << "\nFile not found\n";
            return;
        }
        bool check = true;
        cout << "Enter the admission number of the student : ";
        int roll;
        cin >> roll;
        student stu;
        find.seekg(0);
        do
        {

            find.read((char *)&stu, sizeof(stu));
            if (stu.admission_num == roll)
            {
                cout << "\n=============================================================================================";
                cout << "====================\n";
                cout << "Student's name" << setw(40) << "Student's admission number";
                cout << setw(30) << "Class of the student" << setw(30) << "Number of books issued\n";
                cout << "=============================================================================================";
                cout << "====================\n";
                string s = stu.first_name;
                int y = s.size();
                if (y > 15)
                {
                    y = 15;
                }
                for (int i = 0; i < y; i++)
                {
                    cout << s[i];
                }
                for (int j = 0; j < 28 - y; j++)
                {
                    cout << ' ';
                }
                cout << stu.admission_num << setw(35) << stu.clas;
                cout << "\t\t\t\t" << stu.no_of_books_issued;
                cout << endl;
                s = stu.last_name;
                y = s.size();
                if (y > 15)
                {
                    y = 15;
                }
                for (int i = 0; i < y; i++)
                {
                    cout << s[i];
                }
                cout << endl;
                cout << "-------------------------------------------------------------------------------------------";
                cout << "----------------------\n";
                check = false;
                break;
            }

        } while (find.eof() == 0);

        if (check)
        {
            cout << "No student have " << roll << " admission number" << endl;
        }
        cout << endl;
        find.close();
        system("Pause");
    }

    void modify_student()
    {
        fstream find;
        find.open("student.dat", ios::in | ios::out | ios::binary);
        if (!find)
        {
            cout << "\nFile not found\n";
            return;
        }
        bool check = true;
        cout << "Enter the admission number of the student(to be modify) : ";
        int roll;
        cin >> roll;
        student stu;
        int pos;

        while (find.eof() == 0)
        {
            pos = find.tellg();
            find.read((char *)&stu, sizeof(stu));
            if (stu.admission_num == roll)
            {
                student adi;
                cout << "\nEnter the new details\n";
                cout << "\nEnter Student's first name(Max 15 character) : ";
                fflush(stdin);
                cin >> adi.first_name;
                cout << "\nEnter Student's last name(Max 15 character) : ";
                fflush(stdin);
                cin >> adi.last_name;
                cout << "\nEnter Student's admission number(6 Digit) : ";
                cin >> adi.admission_num;
                cout << "\nEnter Class of the student : ";
                fflush(stdin);
                cin >> adi.clas;
                adi.no_of_books_issued = stu.no_of_books_issued;
                find.seekp(pos);
                find.write((char *)&adi, sizeof(adi));
                cout << "\n\t\tStudent Modified\n\n";
                check = false;
                break;
            }
        }
        if (check)
        {
            cout << "No student \n"
                 << endl;
        }
        find.close();
    }

    int modify_issue(int roll)
    {
        fstream find;
        find.open("student.dat", ios::in | ios::out | ios::binary);
        if (!find)
        {
            cout << "\nFile not found\n";
            return 0;
        }
        student stu;
        int pos;
        bool check = true;
        while (find.eof() == 0)
        {
            pos = find.tellg();
            find.read((char *)&stu, sizeof(stu));
            if (stu.admission_num == roll)
            {
                if (stu.no_of_books_issued >= 3)
                {
                    cout << "\nStudent reached their issue limit.Not issued\n";
                    return 0;
                }
                student adi;
                check = false;
                strcpy(adi.first_name, stu.first_name);
                strcpy(adi.last_name, stu.last_name);
                adi.admission_num = stu.admission_num;
                strcpy(adi.clas, stu.clas);
                adi.no_of_books_issued = stu.no_of_books_issued + 1;
                find.seekp(pos);
                find.write((char *)&adi, sizeof(adi));
                break;
            }
        }
        if (check)
        {
            cout << "\nError in admission number or add student\n";
            return 0;
        }
        else
        {
            return 1;
        }
        find.close();
        system("Pause");
    }

    int modify_deposit(int roll)
    {
        fstream find;
        find.open("student.dat", ios::in | ios::out | ios::binary);
        if (!find)
        {
            cout << "\nFile not found\n";
            return 0;
        }
        student stu;
        int pos;
        bool check = true;

        while (find.eof() == 0)
        {
            pos = find.tellg();
            find.read((char *)&stu, sizeof(stu));
            if (stu.admission_num == roll)
            {
                student adi;
                check = false;
                strcpy(adi.first_name, stu.first_name);
                strcpy(adi.last_name, stu.last_name);
                adi.admission_num = stu.admission_num;
                strcpy(adi.clas, stu.clas);
                adi.no_of_books_issued = stu.no_of_books_issued - 1;
                find.seekp(pos);
                find.write((char *)&adi, sizeof(adi));
                break;
            }
        }
        if (check)
        {
            cout << "\nError in admission number\n";
            return 0;
        }
        else
        {
            return 1;
        }

        find.close();
    }

    void delete_student()
    {
        ifstream red;
        ofstream writ;
        red.open("student.dat", ios::in | ios::binary);
        if (!red)
        {
            cout << "\nFile not found\n\n";
            return;
        }
        writ.open("temp.dat", ios::out | ios::binary);
        red.seekg(0, ios::end);
        bool check = true;
        int len = red.tellg();
        red.seekg(0);
        if (len)
        {
            cout << "Enter the admission number of student : ";
            int y;
            cin >> y;
            student a;
                red.read((char *)&a, sizeof(a));
            while (red.eof() == 0)
            {
                
                if (a.admission_num == y && a.no_of_books_issued > 0)
                {
                    cout << "\nBooks are issued to this student,Not deleted\n";
                    remove("temp.dat");
                    return;
                }
                else if (a.admission_num != y)
                {
                    writ.write((char *)&a, sizeof(a));
                }
                else
                {
                    check = false;
                }
                  red.read((char *)&a, sizeof(a));
            }
            writ.close();
            red.close();
            remove("student.dat");
            rename("temp.dat", "student.dat");
            if (check)
            {
                cout << "\nError in addmission number\n";
            }
            else
            {
                cout << "\n\tStudent's data deleted\n";
            }
        }
        else
        {
            cout << "\nFile is empty\n";
        }
        system("Pause");
    }
};

class book
{
    int book_num;
    char author_name[30];
    char book_title[30];
    char domain[30];
    int edition;
    int no_of_copies_ava;

public:
    friend void issue_book();
    friend void deposit_book();
    void print()
    {
        book a;
        ifstream view;
        view.open("book.dat", ios::in | ios::binary);
        if (!view)
        {
            cout << "\nFile not found\n";
            return;
        }
        view.seekg(0, ios::end);
        int len = view.tellg();
        view.seekg(0);
        if (len)
        {
            cout << "\n=============================================================================================";
            cout << "====================================\n";
            cout << "Book'title"
                 << "\t\t\tBook number";
            cout << setw(30) << "Author's name" << setw(31) << "Edition" << setw(26) << "Copies avaliable\n";
            cout << "=============================================================================================";
            cout << "====================================\n";
            view.seekg(0);

            view.read((char *)&a, sizeof(a));
            do
            {
                string s = a.book_title;
                int y = s.size();
                if (y > 30)
                {
                    y = 30;
                }
                for (int i = 0; i < y; i++)
                {
                    cout << s[i];
                }
                for (int j = 0; j < 36 - y; j++)
                {
                    cout << ' ';
                }
                cout << a.book_num << setw(24);
                s = a.author_name;
                y = s.size();
                if (y > 30)
                {
                    y = 30;
                }
                for (int i = 0; i < y; i++)
                {
                    cout << s[i];
                }
                for (int j = 0; j < 38 - y; j++)
                {
                    cout << ' ';
                }
                cout << a.edition << "\t" << setw(13);
                cout << a.no_of_copies_ava;
                cout << endl;
                cout << "-------------------------------------------------------------------------------------------";
                cout << "--------------------------------------\n";
                view.read((char *)&a, sizeof(a));
            } while (view.eof() == 0);
            cout << endl;
        }
        else
        {
            cout << "\nFile is empty\n\n";
        }
        view.close();
        system("Pause");
    }

    void add_book()
    {
        ofstream add;
        book b;
        add.open("book.dat", ios::app | ios::binary);
        cout << "Enter the book number : ";
        cin >> b.book_num;
        cout << "Enter the author name(Max 30 character) : ";
        fflush(stdin);
        gets(b.author_name);
        cout << "Enter the book title(Max 30 character) : ";
        fflush(stdin);
        gets(b.book_title);
        cout << "Enter the book domain(Max 30 character) : ";
        fflush(stdin);
        gets(b.domain);
        cout << "Enter the edition of book : ";
        cin >> b.edition;
        cout << "Enter the number of copies avaliable : ";
        cin >> b.no_of_copies_ava;
        add.write((char *)&b, sizeof(b));
        cout << endl;
        add.close();
        cout << "\nBook added\n";
        system("Pause");
    }

    void print_specific()
    {
        ifstream find;
        find.open("book.dat", ios::in | ios::binary);
        if (!find)
        {
            cout << "\nFile not found\n";
            return;
        }
        bool check = true;
        cout << "Enter the Book number : ";
        int num;
        cin >> num;
        book stu;
        find.seekg(0);
        do
        {
            find.read((char *)&stu, sizeof(stu));
            if (stu.book_num == num)
            {
                cout << "\n=============================================================================================";
            cout << "====================================\n";
            cout << "Book'title"
                 << "\t\t\tBook number";
            cout << setw(30) << "Author's name" << setw(31) << "Edition" << setw(26) << "Copies avaliable\n";
            cout << "=============================================================================================";
            cout << "====================================\n";
                 string s = stu.book_title;
                int y = s.size();
                if (y > 30)
                {
                    y = 30;
                }
                for (int i = 0; i < y; i++)
                {
                    cout << s[i];
                }
                for (int j = 0; j < 36 - y; j++)
                {
                    cout << ' ';
                }
                cout << stu.book_num << setw(24);
                s = stu.author_name;
                y = s.size();
                if (y > 30)
                {
                    y = 30;
                }
                for (int i = 0; i < y; i++)
                {
                    cout << s[i];
                }
                for (int j = 0; j < 38 - y; j++)
                {
                    cout << ' ';
                }
                cout << stu.edition << "\t" << setw(13);
                cout << stu.no_of_copies_ava;
                cout << endl;
                cout << "-------------------------------------------------------------------------------------------";
                cout << "--------------------------------------\n";
                
                check = false;
                break;
            }

        } while (find.eof() == 0);

        if (check)
        {
            cout << "Error book number" << endl;
        }
        cout << endl;
        find.close();
        system("Pause");
    }

    void modify_book()
    {
        fstream find;
        find.open("book.dat", ios::in | ios::out | ios::binary);
        if (!find)
        {
            cout << "\nFile not found\n";
            return;
        }
        bool check = true;
        cout << "Enter the book number(to be modify) : ";
        int num;
        cin >> num;
        book b;
        int pos;
        while (find.eof() == 0)
        {
            pos = find.tellg();
            find.read((char *)&b, sizeof(b));
            if (b.book_num == num)
            {
                book k;

                cout << "\nEnter the new Book number : ";
                cin >> k.book_num;
                cout << "\nEnter the new author name(Max 30 character) : ";
                fflush(stdin);
                gets(k.author_name);
                cout << "\nEnter the new book title(Max 30 character) : ";
                fflush(stdin);
                gets(k.book_title);
                cout << "\nEnter the new book domain(Max 30 character) : ";
                fflush(stdin);
                gets(k.domain);
                cout << "\nEnter the new book edition : ";
                cin >> k.edition;
                cout << "Enter the number of copies avaliable : ";
                cin >> k.no_of_copies_ava;
                find.seekp(pos);
                find.write((char *)&k, sizeof(k));
                cout << "\t\tBook Modified\n\n";
                check = false;
                break;
            }
        }
        if (check)
        {
            cout << "No student \n"
                 << endl;
        }
        find.close();
        system("Pause");
    }

    void modify_issue(int num)
    {
        fstream find;
        find.open("book.dat", ios::in | ios::out | ios::binary);
        if (!find)
        {
            cout << "\nFile not found\n";
            return;
        }
        book b;
        int pos;
        while (find.eof() == 0)
        {
            pos = find.tellg();
            find.read((char *)&b, sizeof(b));
            if (b.book_num == num)
            {
                book k;
                k.book_num = b.book_num;
                strcpy(k.author_name, b.author_name);
                strcpy(k.book_title, b.book_title);
                strcpy(k.domain, b.domain);
                k.edition = b.edition;
                k.no_of_copies_ava = b.no_of_copies_ava - 1;
                find.seekp(pos);
                find.write((char *)&k, sizeof(k));
                break;
            }
        }
        find.close();
    }

    void modify_deposit(int num)
    {
        fstream find;
        find.open("book.dat", ios::in | ios::out | ios::binary);
        if (!find)
        {
            cout << "\nFile not found\n";
            return;
        }
        book b;
        int pos;
        while (find.eof() == 0)
        {
            pos = find.tellg();
            find.read((char *)&b, sizeof(b));
            if (b.book_num == num)
            {
                book k;
                k.book_num = b.book_num;
                strcpy(k.author_name, b.author_name);
                strcpy(k.book_title, b.book_title);
                strcpy(k.domain, b.domain);
                k.edition = b.edition;
                k.no_of_copies_ava = b.no_of_copies_ava + 1;
                find.seekp(pos);
                find.write((char *)&k, sizeof(k));
                break;
            }
        }
        find.close();
    }

    void delete_book()
    {
        ifstream red;
        ofstream writ;
        red.open("book.dat", ios::in | ios::binary);
        if (!red)
        {
            cout << "\nFile not found\n";
            return;
        }
        writ.open("temp.dat", ios::out | ios::binary);
        red.seekg(0, ios::end);
        int len = red.tellg();
        red.seekg(0);
        bool check = true;
        if (len)
        {
            cout << "Enter the book number that is to be delete : ";
            int y;
            cin >> y;
            book a;
            red.read((char *)&a, sizeof(a));
            while (red.eof() == 0)
            {
                if (a.book_num != y)
                {
                    writ.write((char *)&a, sizeof(a));
                }
                else
                {
                    check = false;
                }
                red.read((char *)&a, sizeof(a));
            }
            red.close();
            writ.close();
            remove("book.dat");
            rename("temp.dat", "book.dat");
            if (check)
            {
                cout << "\nError in book number\n";
            }
            else
            {
                cout << "\n\tBook's data deleted\n";
            }
        }
        else
        {
            cout << "\nFile is empty\n";
        }
        system("Pause");
    }
};

void admin_menu()
{
    int op;
    do
    {
        cout << "\n------------------------------------------------------------------------------";
        cout << "\n\t\t\tAdmin menu\n";
        cout << "1.Add new student\t\t\t2.Add new book\n3.Modify any student\t";
        cout << "\t\t4.Modify any book\n5.Delete any student\t\t\t6.Delete any book\n";
        cout << "7.View any specific student\t\t8.View all student\n";
        cout << "9.View any specific book\t\t10.View all books\t\t0.Exit\n";
        cout << "------------------------------------------------------------------------------\n";
        cout << "Enter your option : ";
        cin >> op;
        switch (op)
        {
        case 1:
        {
            student adi;
            adi.add_student();
            break;
        }
        case 2:
        {
            book buk;
            buk.add_book();
            break;
        }
        case 3:
        {
            student adi;
            adi.modify_student();
            break;
        }
        case 4:
        {
            book b;
            b.modify_book();
            break;
        }
        case 5:
        {
            student adi;
            adi.delete_student();
            break;
        }
        case 6:
        {
            book buk;
            buk.delete_book();
            break;
        }
        case 7:
        {
            student adi;
            adi.print_specific();
            break;
        }
        case 8:
        {
            student adi;
            adi.print();
            break;
        }
        case 9:
        {
            book buk;
            buk.print_specific();
            break;
        }
        case 10:
        {
            book buk;
            buk.print();
            break;
        }
        }
    } while (op != 0);
}

class issue_detail
{
public:
    int admission_num;
    char book_name[30];
    int book_num;
    long long int seconds;
};

void issue_book()
{

    ofstream fobj;
    fobj.open("issue.dat", ios::app | ios::binary);
    cout << "Enter the book number to be issue : ";
    int num1, num2;
    cin >> num1;
    book buk;
    student stu;
    ifstream red;
    bool check = false;
    red.open("book.dat", ios::in | ios::binary);
    char arr[30];
    while (red.eof() == 0)
    {
        red.read((char *)&buk, sizeof(buk));
        if (buk.book_num == num1 && buk.no_of_copies_ava > 0)
        {
            strcpy(arr, buk.book_title);
            check = true;
            break;
        }
    }
    if (check)
    {
        cout << "Enter the student's admission number : ";
        ;
        cin >> num2;
        int x = stu.modify_issue(num2);

        if (x == 1)
        {
            issue_detail obj;
            obj.admission_num = num2;
            obj.book_num = num1;
            strcpy(obj.book_name, arr);
            time_t t = time(0);
            obj.seconds = t;
            fobj.write((char *)&obj, sizeof(obj));
            buk.modify_issue(num1);
            cout << "Book issued\n\n";
        }
    }
    else
    {
        cout << "Book Not avaliable or error in Book number\n\n";
    }
    fobj.close();
    red.close();
    system("Pause");
}

void deposit_book()
{
    student adi;
    cout << "Enter the book number to be deposit : ";
    int num1, num2;
    cin >> num1;
    book buk;
    issue_detail ak;
    student stu;
    ifstream red;
    bool check = false;
    red.open("issue.dat", ios::in | ios::binary);
    while (red.eof() == 0)
    {
        red.read((char *)&ak, sizeof(ak));
        if (ak.book_num == num1)
        {
            check = true;
            break;
        }
    }
    red.close();
    ifstream obj;
    obj.open("issue.dat", ios::in | ios::binary);
    if (check)
    {
        cout << "Enter the student's admission number : ";
        ;
        cin >> num2;
        int x = stu.modify_deposit(num2);
        long long int tym;
        if (x == 1)
        {
            ofstream writ;
            issue_detail adi;
            bool ch = true;
            writ.open("temp.dat", ios::out | ios::binary);
            obj.read((char *)&adi, sizeof(adi));
            while (obj.eof() == 0)
            {
                if (adi.book_num == num1 && adi.admission_num == num2 && ch == true)
                {
                    ch = false;
                    tym = adi.seconds;
                }
                else
                {
                    writ.write((char *)&adi, sizeof(adi));
                }
                obj.read((char *)&adi, sizeof(adi));
            }
            obj.close();
            writ.close();
            remove("issue.dat");
            rename("temp.dat", "issue.dat");
            if (ch)
            {
                cout << "\nStudent with admission num " << num2 << " has not issued this book\n";
            }
            else
            {
                buk.modify_deposit(num1);
                time_t cur_time = time(0);
                long long int dif = cur_time - tym;
                if (dif > 1296000)
                {
                    int a = dif / 1296000;
                    a++;
                    cout << "Late deposit fine = " << a * 10 << ". Please deposit it\n\n"
                         << endl;
                }
                cout << "Book deposited\n\n";
            }
        }
    }
    else
    {
        cout << "Book with this number is not issued\n\n";
    }
    system("Pause");
}

void details()
{
    int op;
    cout << "\n-----------------------------------------------------------------------------------\n";
    cout << "\t\t\t\tSearch Menu\n";
    cout << "1.Student's admission number\t\t\t2.Book number\t\t\t0.Exit";
    cout << "\n----------------------------------------------------------------------------------\n";
    cout << "Enter the option : ";
    cin >> op;
    issue_detail obj;
    ifstream red;
    red.open("issue.dat", ios::in | ios::binary);
    if (!red)
    {
        cout << "\nFile not found\n";
        return;
    }
    switch (op)
    {
    case 1:
    {
        cout << "Enter the admission number of student : ";
        int a;
        cin >> a;
        bool check = true;
        cout << "\n============================================================================\n";
        cout << "Admission Number" << setw(28) << "Book number" << setw(30) << "Book Title";
        ;
        cout << "\n============================================================================\n";
        while (red.eof() == 0)
        {
            red.read((char *)&obj, sizeof(obj));
            if (red.tellg() == -1)
            {
                break;
            }
            if (obj.admission_num == a)
            {
                check = false;
                cout << obj.admission_num << "\t\t\t\t" << obj.book_num << "\t\t\t" << obj.book_name << "\n";
            }
        }
        if (check)
        {
            cout << "\nNo data\n";
        }
        system("Pause");
        break;
    }
    case 2:
    {
        cout << "Enter the book number : ";
        int a;
        cin >> a;
        bool check = true;
        cout << "\n==============================================================================\n";
        cout << "Admission Number" << setw(28) << "Book number" << setw(30) << "Book Title";
        ;
        cout << "\n==============================================================================\n";
        while (red.eof() == 0)
        {

            red.read((char *)&obj, sizeof(obj));
            if (red.tellg() == -1)
            {
                break;
            }

            if (obj.book_num == a)
            {
                check = false;
                cout << obj.admission_num << "\t\t\t" << setw(6) << obj.book_num << "\t\t\t" << setw(12) << obj.book_name << "\n";
            }
        }
        if (check)
        {
            cout << "\nNo data\n";
        }
        system("Pause");
        break;
    }
    }
    red.close();
}

int main()
{
    cout << "\033[2J\033[1;1H";
    cout << "\n\t\t\tWelcome of library managment system\n"
         << endl;
    int op;
    do
    {
        cout << "\n---------------------------------------------";
        cout << "\n\t\tMain menu\n";
        cout << "1.Admin Menu\t\t\t2.Issue Book\n3.Deposit Book\t\t\t4.Issue details\n0.Exit";
        cout << "\n---------------------------------------------\n";
        cout << "Enter the option : ";
        cin >> op;
        switch (op)
        {
        case 1:
        {
            admin_menu();
            break;
        }
        case 2:
        {
            issue_book();
            break;
        }
        case 3:
        {
            deposit_book();
            break;
        }
        case 4:
        {
            details();
            break;
        }
        }

    } while (op != 0);

    return 0;
}

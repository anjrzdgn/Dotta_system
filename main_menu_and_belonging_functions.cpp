//
// Created by Ali on 2024-03-28.
//
#include "universal_header.h"

void loading()
{
    std::cout << RED() << std::endl;
    printf("%*s________   ___________________________________   \n", 20, "");
    printf("%*s\\______ \\  \\_____  \\__    ___/\\__    ___/  _  \\  \n", 20, "");
    printf("%*s |    |  \\  /   |   \\|    |     |    | /  /_\\  \\ \n", 20, "");
    printf("%*s |    `   \\/    |    \\    |     |    |/    |    \\\n", 20, "");
    printf("%*s/_______  /\\_______  /____|     |____|\\____|__  /\n", 20, "");
    printf("%*s        \\/         \\/                         \\/ \n", 20, "");

    std::cout << YELLOW() << std::endl;
    wprintf(L"\t\t    ");
    for (int i = 0; i < 23; i++)
    {
        std::cout << "#";
        Sleep(300);
    }
    for (int i = 0; i < 24; i++)
    {
        std::cout << "#";
        Sleep(100);
    }
    std::cout << WHITE() << std::endl;
    Sleep(500);
}

void online_user_reset()
{
    online_user.set_name("");
    online_user.set_password("");
    online_user.set_rule("");
    online_user.set_visibility(false);
}

void sign_in()
{
    cursor_on();
    system("cls");
    std::cout << YELLOW() << "------- "<< RED() << "SIGN IN" << YELLOW() <<" -------" << WHITE() << std::endl;

    std::cout << "Enter your name:" << std::endl;
    std::string temp_name;
    std::cin >> temp_name;
    person temp_person(" ", " ", " ", false);

    std::ifstream in("people.txt");
    std::string line;
    bool found_user = false;
    while(std::getline(in, line))
    {
        std::vector<std::string> info;
        std::istringstream iss(line);
        std::string word;
        while (iss >> word)
        {
            info.push_back(word);
        }
        if (temp_name == info[0] && info[3] == "1")
        {
            found_user = true;
            temp_person.set_name(info[0]);
            temp_person.set_password(info[1]);
            temp_person.set_rule(info[2]);
            if (info[3] == "1") temp_person.set_visibility(true);
            if (info[3] == "0") temp_person.set_visibility(false);
        }
    }
    in.close();

    if (found_user)
    {
        std::cout << "Enter your password:" << std::endl;
        std::string temp_password;
        std::cin >> temp_password;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (temp_password == temp_person.display_password())
        {
            std::cout << "Dear " << GREEN() << temp_person.display_name() << WHITE() << ", welcome back" << std::endl;
            online_user.set_name(temp_person.display_name());
            online_user.set_password(temp_person.display_password());
            online_user.set_rule(temp_person.display_rule());
            online_user.set_visibility(temp_person.display_visibility());

            if (online_user.display_rule() == "admin") command_and_check_for_admin();
            else if (online_user.display_rule() == "teacher") command_and_check_for_teacher();
            else if (online_user.display_rule() == "student") command_and_check_for_student();
        }
        else
        {
            std::cerr << RED() << "wrong password!" << WHITE() << std::endl;
            back_to_menu();
        }
    }
    else
    {
        std::cerr << RED() << "No account found with this name!" << WHITE() << std::endl;
        back_to_menu();
    }

}

void sign_up_for_students()
{
    cursor_on();
    system("cls");
    std::cout << YELLOW() << "------- "<< RED() << "SIGN UP" << YELLOW() <<" -------" << WHITE() << std::endl;

    std::cout << RED() <<"**ATTENTION:" << WHITE() << std::endl;
    std::cout << "only normal students can register here; for more description, contact with support" << std::endl;

    std::cout << std::endl;
    std::cout << "Enter your name:" << std::endl;
    std::string temp_name, temp_password, temp_password_again;
    std::cin >> temp_name;

    std::ifstream in("people.txt");
    std::string line;
    bool found_user = false;
    while(std::getline(in, line))
    {
        std::vector<std::string> info;
        std::istringstream iss(line);
        std::string word;
        while (iss >> word)
        {
            info.push_back(word);
        }
        if (temp_name == info[0])
        {
            found_user = true;
        }
    }
    in.close();

    if (found_user)
    {
        std::cerr << RED() << "This name is already gotten!" << WHITE() << std::endl;
        back_to_menu();
    }

    std::cout << "Enter your password:" << std::endl;
    std::cin >> temp_password;
    std::cout << "Enter your password again:" << std::endl;
    std::cin >> temp_password_again;

    if (temp_password != temp_password_again || temp_password.size() < 6)
    {
        std::cerr << RED() << "No match or week password" << WHITE() << std::endl;
        back_to_menu();
    }
    else
    {
        person temp_person(temp_name, temp_password, "student", true);
        temp_person.save_to_file("people.txt");

        std::cout << "Dear " << GREEN() << temp_name << WHITE() << ", Your registration was successful!" << std::endl;
        back_to_menu();
    }
}

void help()
{
    system("cls");
    std::cout << "any where you got confused, just command <SOS>." << std::endl;
    std::cout << "This is helps you to find proper command" << std::endl;
    std::cout << "CONSIDER that these commands are different for each user" << std::endl;
    back_to_menu();
}

void about_us()
{
    system("cls");
    std::cout << "\t\t\tIN THE NAME OF ALMIGHTY" << std::endl;
    std::cout << "IMTB.co presents:" << std::endl;
    std::cout << "Design and Development------------>Ali Najjarzadegan" << std::endl;
    std::cout << "Main Director--------------------->Ali Najjarzadegan" << std::endl;
    std::cout << "Producer and Finance-------------->Ali Najjarzadegan" << std::endl;
    std::cout << "System and BackUp----------------->ALi Najjarzadegan" << std::endl;
    std::cout << "Deepest thanks from who helped us to creat this game:" << std::endl;
    std::cout << "Copilot, Google, GitHub, GeeksForGeeks, StackOverFlow, etc" << std::endl;
    back_to_menu();
}

void back_to_menu()
{
    Sleep(3000);
    system("cls");
    main_menu();
}

void main_menu()
{
    system("cls");
    cursor_off();

    int j = 1;
    int menu;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    while (true)
    {
        COORD origin = {0, 0};
        SetConsoleCursorPosition(hStdout, origin);
        std::cout << YELLOW() << "------- "<< RED() << "MAIN MENU" << YELLOW() <<" -------" << WHITE() << std::endl;
        (j == 1) ? (printf("\033[1;31mSign In\033[33m\n")) : printf("Sign In\n");
        (j == 2) ? (printf("\033[1;31mSign Up\033[33m\n")) : printf("Sign Up\n");
        (j == 3) ? (printf("\033[1;31mHelp\033[33m\n")) : printf("Help\n");
        (j == 4) ? (printf("\033[1;31mAbout Us\033[33m\n")) : printf("About Us\n");
        (j == 5) ? (printf("\033[1;31mEXIT The program\033[33m\n")) : printf("EXIT The program\n");

        menu = _getch();
        if (menu == 80)
        {
            if (j < 5)
            {
                j++;
            }
        }
        if (menu == 72)
        {
            if (j > 1)
            {
                j--;
            }
        }
        if (menu == 13)
        {
            if (j == 1) sign_in();
            if (j == 2) sign_up_for_students();
            if (j == 3) help();
            if (j == 4) about_us();
            if (j == 5) exit(EXIT_SUCCESS);
        }

    }
}

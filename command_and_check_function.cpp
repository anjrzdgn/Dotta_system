//
// Created by Ali on 2024-03-28.
//
#include "universal_header.h"

void sos_ADDITION_COMMANDS_admin()
{
    std::cout << GREEN() << "ADDITION COMMANDS:" << WHITE() << std::endl;
    std::cout << "\t" << YELLOW() << "add admin <name> <password> <visibility> " << WHITE() << "to add new admin" << std::endl;
    std::cout << "\t" << YELLOW() << "add teacher <name> <password> <visibility> " << WHITE() << "to add new teacher" << std::endl;
    std::cout << "\t" << YELLOW() << "add student <name> <password> <visibility> " << WHITE() << "to add new student" << std::endl;
    std::cout << std::endl;
}
void sos_OBSERVATION_COMMANDS_admin()
{
    std::cout << GREEN() << "OBSERVATION COMMANDS:" << WHITE() << std::endl;
    std::cout << "\t" << YELLOW() << "show admin -A " << WHITE() << "to see all admins" << std::endl;
    std::cout << "\t" << YELLOW() << "show teacher -A " << WHITE() << "to see all teachers" << std::endl;
    std::cout << "\t" << YELLOW() << "show student -A " << WHITE() << "to see all students" << std::endl;
    std::cout << "\t" << YELLOW() << "show admin -n <name> " << WHITE() << "to see named admin" << std::endl;
    std::cout << "\t" << YELLOW() << "show teacher -n <name> " << WHITE() << "to see named teacher" << std::endl;
    std::cout << "\t" << YELLOW() << "show student -n <name> " << WHITE() << "to see named student" << std::endl;
    std::cout << "\t" << YELLOW() << "show course -A " << WHITE() << "to see all courses as brief" << std::endl;
    std::cout << "\t" << YELLOW() << "show course -D " << WHITE() << "to see all courses detailed" << std::endl;
    std::cout << "\t" << YELLOW() << "show duty -A " << WHITE() << "to see all duties as brief" << std::endl;
    std::cout << "\t" << YELLOW() << "show duty -D " << WHITE() << "to see all duties detailed" << std::endl;
    std::cout << std::endl;
}
void sos_MODIFICATION_COMMANDS_admin()
{
    std::cout << GREEN() << "MODIFICATION COMMANDS:" << WHITE() << std::endl;
    std::cout << "\t" << YELLOW() << "update <name> -n <newName> " << WHITE() << "to modify name of named member" << std::endl;
    std::cout << "\t" << YELLOW() << "update <name> -p <newPassword> " << WHITE() << "to modify password of named member" << std::endl;
    std::cout << "\t" << YELLOW() << "update <name> -r <newRole> " << WHITE() << "to modify role of named member" << std::endl;
    std::cout << "\t" << YELLOW() << "update <name> -v <newVisibility> " << WHITE() << "to modify visibility of named member" << std::endl;
    std::cout << std::endl;
}
void sos_DELETION_COMMANDS_admin()
{
    std::cout << GREEN() << "DELETION COMMANDS:" << WHITE() << std::endl;
    std::cout << "\t" << YELLOW() << "delete teacher -A " << WHITE() << "to remove all teachers" << std::endl;
    std::cout << "\t" << YELLOW() << "delete student -A " << WHITE() << "to remove all students" << std::endl;
    std::cout << "\t" << YELLOW() << "delete teacher -n <name> " << WHITE() << "to remove named teacher" << std::endl;
    std::cout << "\t" << YELLOW() << "delete student -n <name> " << WHITE() << "to remove named student" << std::endl;
    std::cout << std::endl;
}
void sos_RESTORATION_COMMANDS_admin()
{
    std::cout << GREEN() << "RESTORATION COMMANDS:" << WHITE() << std::endl;
    std::cout << "\t" << YELLOW() << "recovery admin -A " << WHITE() << "to restore all admins" << std::endl;
    std::cout << "\t" << YELLOW() << "recovery teacher -A " << WHITE() << "to restore all teachers" << std::endl;
    std::cout << "\t" << YELLOW() << "recovery student -A " << WHITE() << "to restore all students" << std::endl;
    std::cout << "\t" << YELLOW() << "recovery admin -n <name> " << WHITE() << "to restore named admin" << std::endl;
    std::cout << "\t" << YELLOW() << "recovery teacher -n <name> " << WHITE() << "to restore named teacher" << std::endl;
    std::cout << "\t" << YELLOW() << "recovery student -n <name> " << WHITE() << "to restore named student" << std::endl;
    std::cout << std::endl;
}
void sos_HELPER_COMMANDS_admin()
{
    std::cout << GREEN() << "HELPER COMMANDS:" << WHITE() << std::endl;
    std::cout << "\t" << YELLOW() << "SOS " << WHITE() << "to guide by help instruction" << std::endl;
    std::cout << "\t" << YELLOW() << "clear " << WHITE() << "to clean the console" << std::endl;
    std::cout << "\t" << YELLOW() << "light " << WHITE() << "to change Dotta theme to light" << std::endl;
    std::cout << "\t" << YELLOW() << "dark " << WHITE() << "to change Dotta theme to dark" << std::endl;
    std::cout << "\t" << YELLOW() << "backup " << WHITE() << "to get a back-up from all data" << std::endl;
    std::cout << "\t" << YELLOW() << "bye " << WHITE() << "to sign_out from your account" << std::endl;
    std::cout << "\t" << YELLOW() << "exit " << WHITE() << "to close the Dotta system" << std::endl;
    std::cout << std::endl;
}
void command_and_check_for_admin()
{
    cursor_on();
    std::vector<course>all_courses = read_courses_from_file();
    std::vector<HW>HWs = read_HW_from_file();
    while(true)
    {
        std::cout << std::endl;
        std::cout << online_user.display_name() << "@" << "admin ~ " << std::endl;
        std::cout << CYAN() << "$ " << WHITE();

        std::string line0;
        std::vector<std::string> commands;
        std::getline(std::cin, line0, '\n');
        std::istringstream iss0(line0);
        std::string word0;

        while (iss0 >> word0)
        {
            commands.push_back(word0);
        }

        if (commands[0] == "SOS")
        {
            if (commands[1] == "addition")
            {
                sos_ADDITION_COMMANDS_admin();
            }
            else if (commands[1] == "observation")
            {
                sos_OBSERVATION_COMMANDS_admin();
            }
            else if (commands[1] == "modification")
            {
                sos_MODIFICATION_COMMANDS_admin();
            }
            else if (commands[1] == "deletion")
            {
                sos_DELETION_COMMANDS_admin();
            }
            else if (commands[1] == "restoration")
            {
                sos_RESTORATION_COMMANDS_admin();
            }
            else if (commands[1] == "helper")
            {
                sos_HELPER_COMMANDS_admin();
            }
            else
            {
                sos_ADDITION_COMMANDS_admin();
                sos_OBSERVATION_COMMANDS_admin();
                sos_MODIFICATION_COMMANDS_admin();
                sos_DELETION_COMMANDS_admin();
                sos_RESTORATION_COMMANDS_admin();
                sos_HELPER_COMMANDS_admin();
            }
            continue;
        }
        else if (commands[0] == "backup")
        {
            std::string directoryName = GetCurrentDateTimeString();
            std::string directoryPath = R"(C:\Users\Ali\Desktop\dotta\cmake-build-debug\Back-up\)" + directoryName;
            CreateDirectoryA(directoryPath.c_str(), nullptr);

            std::string source_path1 = "people.txt";
            std::string destination_path1 = directoryPath + "\\people.txt";
            std::ifstream source_file1(source_path1, std::ios::binary);
            std::ofstream destination_file1(destination_path1, std::ios::binary);

            std::string source_path2 = "course.txt";
            std::string destination_path2 = directoryPath + "\\course.txt";
            std::ifstream source_file2(source_path2, std::ios::binary);
            std::ofstream destination_file2(destination_path2, std::ios::binary);

            std::string source_path3 = "HW.txt";
            std::string destination_path3 = directoryPath + "\\HW.txt";
            std::ifstream source_file3(source_path3, std::ios::binary);
            std::ofstream destination_file3(destination_path3, std::ios::binary);

            destination_file1 << source_file1.rdbuf();
            destination_file2 << source_file2.rdbuf();
            destination_file3 << source_file3.rdbuf();

            std::cout << GREEN() << "All data is backed up" << WHITE() <<std::endl;

        }
        else if (commands[0] == "clear")
        {
            system("cls");
            continue;
        }
        else if (commands[0] == "bye")
        {
            std::cout << "Good luck " << online_user.display_name() << std::endl;
            Sleep(1000);
            system("cls");
            save_courses_to_file(all_courses);
            save_HW_to_file(HWs);
            online_user_reset();
            main_menu();
        }
        else if (commands[0] == "exit")
        {
            save_courses_to_file(all_courses);
            save_HW_to_file(HWs);
            exit(EXIT_SUCCESS);
        }
        else if (commands[0] == "dark")
        {
            system("color 0F");
            continue;
        }
        else if (commands[0] == "light")
        {
            system("color F0");
            continue;
        }

        else if (commands[0] == "add")
        {
            if (commands.size() != 5)
            {
                std::cerr << RED() << "Wrong flag format!" << WHITE() << std::endl;
                continue;
            }

            if (commands[1] == "admin" || commands[1] == "teacher" || commands[1] == "student")
            {
                std::ifstream in("people.txt");
                std::string line;
                bool found_user = false;
                while (std::getline(in, line))
                {
                    std::vector<std::string> info;
                    std::istringstream iss(line);
                    std::string word;
                    while (iss >> word)
                    {
                        info.push_back(word);
                    }
                    if (info[0] == commands[2])
                    {
                        found_user = true;
                        break;
                    }
                }
                in.close();

                if (found_user)
                {
                    std::cerr << RED() << "This name is already gotten!" << WHITE() << std::endl;
                    continue;
                }
            }

            if (commands[1] == "admin")
            {
                if (commands[4] == "on")
                {
                    person admin(commands[2], commands[3], "admin", true);
                    admin.save_to_file("people.txt");
                    std::cout << GREEN() << "New admin added successfully!" << WHITE() << std::endl;
                }
                else if (commands[4] == "off")
                {
                    person admin(commands[2], commands[3], "admin", false);
                    admin.save_to_file("people.txt");
                    std::cout << GREEN() << "New admin added successfully!" << WHITE() << std::endl;
                }
                else
                {
                    std::cerr << RED() << "Wrong visibility switch" << WHITE() << std::endl;
                    continue;
                }
            }
            else if (commands[1] == "teacher")
            {
                if (commands[4] == "on")
                {
                    person admin(commands[2], commands[3], "teacher", true);
                    admin.save_to_file("people.txt");
                    std::cout << GREEN() << "New teacher added successfully!" << WHITE() << std::endl;
                }
                else if (commands[4] == "off")
                {
                    person admin(commands[2], commands[3], "teacher", false);
                    admin.save_to_file("people.txt");
                    std::cout << GREEN() << "New teacher added successfully!" << WHITE() << std::endl;
                }
                else
                {
                    std::cerr << RED() << "Wrong visibility switch" << WHITE() << std::endl;
                    continue;
                }
            }
            else if (commands[1] == "student")
            {
                if (commands[4] == "on")
                {
                    person admin(commands[2], commands[3], "student", true);
                    admin.save_to_file("people.txt");
                    std::cout << GREEN() << "New student added successfully!" << WHITE() << std::endl;
                }
                else if (commands[4] == "off")
                {
                    person admin(commands[2], commands[3], "student", false);
                    admin.save_to_file("people.txt");
                    std::cout << GREEN() << "New student added successfully!" << WHITE() << std::endl;
                }
                else
                {
                    std::cerr << RED() << "Wrong visibility switch" << WHITE() << std::endl;
                    continue;
                }
            }
            else
            {
                std::cerr << RED() << "Wrong flag format!" << WHITE() << std::endl;
                sos_ADDITION_COMMANDS_admin();
                continue;
            }
        }
        else if (commands[0] == "show")
        {
            if (commands[1] == "admin")
            {
                if (commands[2] == "-A")
                {
                    std::ifstream in("people.txt");
                    std::string line;
                    int index = 0;
                    while (std::getline(in, line))
                    {
                        std::vector<std::string> info;
                        std::istringstream iss(line);
                        std::string word;
                        while (iss >> word)
                        {
                            info.push_back(word);
                        }
                        if (info[2] == "admin")
                        {
                            index += 1;
                            std::cout << index << ". Name: " << info[0] << " Password: " << info[1] << " Visibility: "
                                      << info[3] << std::endl;
                        }
                    }
                    in.close();
                }
                if (commands[2] == "-n")
                {
                    std::ifstream in("people.txt");
                    std::string line;
                    while (std::getline(in, line))
                    {
                        std::vector<std::string> info;
                        std::istringstream iss(line);
                        std::string word;
                        while (iss >> word)
                        {
                            info.push_back(word);
                        }
                        if (info[2] == "admin" && info[0] == commands[3])
                        {
                            std::cout << "Name: " << info[0] << " Password: " << info[1] << std::endl;
                        }
                    }
                    in.close();
                }
            }
            else if (commands[1] == "teacher")
            {
                if (commands[2] == "-A")
                {
                    std::ifstream in("people.txt");
                    std::string line;
                    int index = 0;
                    while (std::getline(in, line))
                    {
                        std::vector<std::string> info;
                        std::istringstream iss(line);
                        std::string word;
                        while (iss >> word)
                        {
                            info.push_back(word);
                        }
                        if (info[2] == "teacher")
                        {
                            index += 1;
                            std::cout << index << ". Name: " << info[0] << " Password: " << info[1] << " Visibility: "
                                      << info[3] << std::endl;
                        }
                    }
                    in.close();
                }
                if (commands[2] == "-n")
                {
                    std::ifstream in("people.txt");
                    std::string line;
                    while (std::getline(in, line))
                    {
                        std::vector<std::string> info;
                        std::istringstream iss(line);
                        std::string word;
                        while (iss >> word)
                        {
                            info.push_back(word);
                        }
                        if (info[2] == "teacher" && info[0] == commands[3])
                        {
                            std::cout << "Name: " << info[0] << " Password: " << info[1] << std::endl;
                        }
                    }
                    in.close();
                }
            }
            else if (commands[1] == "student")
            {
                if (commands[2] == "-A")
                {
                    std::ifstream in("people.txt");
                    std::string line;
                    int index = 0;
                    while (std::getline(in, line))
                    {
                        std::vector<std::string> info;
                        std::istringstream iss(line);
                        std::string word;
                        while (iss >> word)
                        {
                            info.push_back(word);
                        }
                        if (info[2] == "student")
                        {
                            index += 1;
                            std::cout << index << ". Name: " << info[0] << " Password: " << info[1] << " Visibility: " << info[3] << std::endl;
                        }
                    }
                    in.close();
                }
                if (commands[2] == "-n")
                {
                    std::ifstream in("people.txt");
                    std::string line;
                    while (std::getline(in, line))
                    {
                        std::vector<std::string> info;
                        std::istringstream iss(line);
                        std::string word;
                        while (iss >> word)
                        {
                            info.push_back(word);
                        }
                        if (info[2] == "student" && info[0] == commands[3])
                        {
                            std::cout <<"Name: " << info[0] << " Password: " << info[1] << " Visibility: " << info[3] << std::endl;
                        }
                    }
                    in.close();
                }
            }
            else if (commands[1] == "course")
            {
                if (commands[2] == "-A")
                {
                    int index = 0;
                    for (auto& c : all_courses)
                    {
                        index += 1;
                        std::cout << index << ". Name: " << c.name << " Teacher: " << c.teacher << " Capacity: " << c.capacity << " Visibility: " << c.visibility << std::endl;
                    }
                }
                if (commands[2] == "-D")
                {
                    int index = 0;
                    for (auto& c : all_courses)
                    {
                        index += 1;
                        std::cout << index << ". Name: " << c.name << " Teacher: " << c.teacher << " Capacity: " << c.capacity << " Visibility: " << c.visibility << std::endl;
                        int index_s = 0;
                        for (auto& s : c.students)
                        {
                            index_s += 1;
                            std::cout << "\t" << index_s << ". Name: " << s.display_name() << " Score: " << s.score << std::endl;
                        }
                    }
                }
            }
            else if (commands[1] == "duty")
            {
                if (commands[2] == "-A")
                {
                    for (const auto& h : HWs)
                    {
                        std::cout << "Name: " << h.name << "\tTeacher: " << h.teacher << "\tCourse: " << h.course << "\tVisibility: " << h.visibility << std::endl;
                    }
                }
                if (commands[2] == "-D")
                {
                    for (const auto& h : HWs)
                    {
                        std::cout << "Name: " << h.name << "\tTeacher: " << h.teacher << "\tCourse: " << h.course << "\tVisibility: " << h.visibility << std::endl;
                        for (const auto& s : h.slaves)
                        {
                            if (s.sent)
                            {
                                std::cout << "\t Student: " << s.name_of_student << "\tHWSource: " << s.link_of_uploaded_HW << "\tGiven Score: " << s.score_of_HW << "\tSent? " << "yes"<< std::endl;
                            }
                            else
                            {
                                std::cout << "\t Student: " << s.name_of_student << "\tHWSource: " << s.link_of_uploaded_HW << "\tGiven Score: " << s.score_of_HW << "\tSent? " << "NO!"<< std::endl;
                            }
                        }
                    }
                }
            }
            else
            {
                std::cerr << RED() << "Wrong flag format!" << WHITE() << std::endl;
                sos_OBSERVATION_COMMANDS_admin();
                continue;
            }
        }
        else if (commands[0] == "delete")
        {
            if (commands[1] == "teacher")
            {
                std::string filename = "people.txt";
                std::vector<person> people;
                std::ifstream in(filename);
                std::string line;
                while (std::getline(in, line))
                {
                    std::vector<std::string> info;
                    std::istringstream iss(line);
                    std::string word;
                    while (iss >> word)
                    {
                        info.push_back(word);
                    }
                    person temp_person(info[0], info[1], info[2], info[3] == "1");
                    people.push_back(temp_person);
                }
                in.close();

                for (auto &p: people)
                {
                    if (commands[2] == "-A")
                    {
                        if (p.display_rule() == "teacher")
                        {
                            p.set_visibility(false);
                            std::cout << GREEN() << "All teachers have been deleted!" << WHITE() << std::endl;
                        }
                    }
                    else if (commands[2] == "-n")
                    {
                        if (p.display_rule() == "teacher" && p.display_name() == commands[3])
                        {
                            p.set_visibility(false);
                            std::cout << GREEN() << p.display_name() << " has been deleted!" << WHITE() << std::endl;
                        }
                    }
                }
                std::ofstream outfile(filename);
                for (const auto &p: people)
                {
                    outfile << p;
                }
                outfile.close();
                continue;
            }
            else if (commands[1] == "student")
            {
                std::string filename = "people.txt";
                std::vector<person> people;
                std::ifstream in(filename);
                std::string line;
                while (std::getline(in, line))
                {
                    std::vector<std::string> info;
                    std::istringstream iss(line);
                    std::string word;
                    while (iss >> word)
                    {
                        info.push_back(word);
                    }
                    person temp_person(info[0], info[1], info[2], info[3] == "1");
                    people.push_back(temp_person);
                }
                in.close();

                for (auto &p: people)
                {
                    if (commands[2] == "-A")
                    {
                        if (p.display_rule() == "student")
                        {
                            p.set_visibility(false);
                            std::cout << GREEN() << "All students have been deleted!" << WHITE() << std::endl;
                        }
                    }
                    else if (commands[2] == "-n")
                    {
                        if (p.display_rule() == "student" && p.display_name() == commands[3])
                        {
                            p.set_visibility(false);
                            std::cout << GREEN() << p.display_name() << " has been deleted!" << WHITE() << std::endl;
                        }
                    }
                }
                std::ofstream outfile(filename);
                for (const auto &p: people)
                {
                    outfile << p;
                }
                outfile.close();
                continue;
            }
            else
            {
                std::cerr << RED() << "Wrong flag format!" << WHITE() << std::endl;
                sos_DELETION_COMMANDS_admin();
                continue;
            }
        }
        else if (commands[0] == "recovery")
        {
            if (commands[1] == "teacher")
            {
                std::string filename = "people.txt";
                std::vector<person> people;
                std::ifstream in(filename);
                std::string line;
                while (std::getline(in, line))
                {
                    std::vector<std::string> info;
                    std::istringstream iss(line);
                    std::string word;
                    while (iss >> word) {
                        info.push_back(word);
                    }
                    person temp_person(info[0], info[1], info[2], info[3] == "1");
                    people.push_back(temp_person);
                }
                in.close();

                for (auto &p: people)
                {
                    if (commands[2] == "-A")
                    {
                        if (p.display_rule() == "teacher")
                        {
                            p.set_visibility(true);
                            std::cout << GREEN() << "All teachers have been restored!" << WHITE() << std::endl;
                        }
                    }
                    if (commands[2] == "-n")
                    {
                        if (p.display_rule() == "teacher" && p.display_name() == commands[3])
                        {
                            p.set_visibility(true);
                            std::cout << GREEN() << p.display_name() << " has been restored!" << WHITE() << std::endl;
                        }
                    }
                }
                std::ofstream outfile(filename);
                for (const auto &p: people)
                {
                    outfile << p;
                }
                outfile.close();
                continue;
            }
            else if (commands[1] == "student")
            {
                std::string filename = "people.txt";
                std::vector<person> people;
                std::ifstream in(filename);
                std::string line;
                while (std::getline(in, line))
                {
                    std::vector<std::string> info;
                    std::istringstream iss(line);
                    std::string word;
                    while (iss >> word)
                    {
                        info.push_back(word);
                    }
                    person temp_person(info[0], info[1], info[2], info[3] == "1");
                    people.push_back(temp_person);
                }
                in.close();

                for (auto &p: people)
                {
                    if (commands[2] == "-A")
                    {
                        if (p.display_rule() == "student")
                        {
                            p.set_visibility(true);
                            std::cout << GREEN() << "All students have been restored!" << WHITE() << std::endl;
                        }
                    }
                    if (commands[2] == "-n")
                    {
                        if (p.display_rule() == "student" && p.display_name() == commands[3])
                        {
                            p.set_visibility(true);
                            std::cout << GREEN() << p.display_name() << " has been restored!" << WHITE() << std::endl;
                        }
                    }
                }
                std::ofstream outfile(filename);
                for (const auto &p: people)
                {
                    outfile << p;
                }
                outfile.close();
                continue;
            }
            else
            {
                std::cerr << RED() << "Wrong flag format!" << WHITE() << std::endl;
                sos_RESTORATION_COMMANDS_admin();
                continue;
            }
        }
        else if (commands[0] == "update")
        {
            std::string filename = "people.txt";
            std::vector<person> people;
            std::ifstream in(filename);
            std::string line;

            while (std::getline(in, line))
            {
                std::vector<std::string> info;
                std::istringstream iss(line);
                std::string word;
                while (iss >> word)
                {
                    info.push_back(word);
                }
                person temp_person(info[0], info[1], info[2], info[3] == "1");
                people.push_back(temp_person);
            }
            in.close();

            for (auto &p : people)
            {
                if (commands[1] == p.display_name())
                {
                    if (commands[2] == "-n")
                    {
                        p.set_name(commands[3]);
                        std::cout << GREEN() << p.display_name() << "\'s name has been updated!" << WHITE()
                                  << std::endl;
                    }
                    else if (commands[2] == "-p")
                    {
                        p.set_password(commands[3]);
                        std::cout << GREEN() << p.display_name() << "\'s password has been updated!" << WHITE()
                                  << std::endl;
                    }
                    else if (commands[2] == "-r")
                    {
                        p.set_rule(commands[3]);
                        std::cout << GREEN() << p.display_name() << "\'s role has been updated!" << WHITE()
                                  << std::endl;
                    }
                    else if (commands[2] == "-v")
                    {
                        if (commands[3] == "on")
                            p.set_visibility(true);
                        else if (commands[3] == "off")
                            p.set_visibility(false);
                        else
                        {
                            std::cerr << RED() << "Wrong flag format!" << WHITE() << std::endl;
                            break;
                        }
                    }
                    else
                    {
                        std::cerr << RED() << "Wrong flag format!" << WHITE() << std::endl;
                        sos_MODIFICATION_COMMANDS_admin();
                        break;
                    }
                }
            }

            std::ofstream outfile(filename);
            for (const auto &p : people)
            {
                outfile << p;
            }
            outfile.close();
            continue;
        }
        else
        {
            std::cerr << RED() << "Wrong command prompt!" << WHITE() << std::endl;
            continue;
        }
    }
}

void sos_COURSE_COMMANDS_teacher()
{
    std::cout << GREEN() << "COURSE COMMANDS:" << WHITE() << std::endl;
    std::cout << "\t" << YELLOW() << "add <courseName> <capacity> <visibility> " << WHITE() << "to add new course" << std::endl;
    std::cout << "\t" << YELLOW() << "delete <courseName> " << WHITE() << "to remove your named course" << std::endl;
    std::cout << "\t" << YELLOW() << "delete course -A " << WHITE() << "to remove all your courses" << std::endl;
    std::cout << "\t" << YELLOW() << "update <courseName> -n <newName>" << WHITE() << "to modify course's name" << std::endl;
    std::cout << "\t" << YELLOW() << "update <courseName> -c <newCapacity>" << WHITE() << "to modify course's capacity" << std::endl;
    std::cout << "\t" << YELLOW() << "recovery <courseName> " << WHITE() << "to recover your named course" << std::endl;
    std::cout << "\t" << YELLOW() << "recovery course -A " << WHITE() << "to recover your named course" << std::endl;
    std::cout << std::endl;
}
void sos_DUTY_COMMANDS_teacher()
{
    std::cout << GREEN() << "DUTY COMMANDS:" << WHITE() << std::endl;
    std::cout << "\t" << YELLOW() << "define <courseName> <homeWorkName> " << WHITE() << "to impose new home work" << std::endl;
    std::cout << "\t" << YELLOW() << "withdraw <courseName> <homeWorkName> " << WHITE() << "to delete named home work" << std::endl;
    std::cout << "\t" << YELLOW() << "misery <courseName> <homeWorkName> " << WHITE() << "to restore named home work" << std::endl;
    std::cout << "\t" << YELLOW() << "mark <courseName> <homeWorkName> <studentName> <newScore> " << WHITE() << "to score student's home work" << std::endl;
    std::cout << std::endl;
}
void sos_PARTICIPATION_COMMANDS_teacher()
{
    std::cout << GREEN() << "PARTICIPATION COMMANDS:" << WHITE() << std::endl;
    std::cout << "\t" << YELLOW() << "enroll <studentName> <courseName> <firstScore> " << WHITE() << "to add new student to course" << std::endl;
    std::cout << "\t" << YELLOW() << "remove <studentName> <courseName> " << WHITE() << "to delete student from course" << std::endl;
    std::cout << "\t" << YELLOW() << "grade <studentName> <courseName> <newScore> " << WHITE() << "to modify student score in course" << std::endl;
    std::cout << std::endl;
}
void sos_OBSERVATION_COMMANDS_teacher()
{
    std::cout << GREEN() << "OBSERVATION COMMANDS:" << WHITE() << std::endl;
    std::cout << "\t" << YELLOW() << "show <courseName> " << WHITE() << "to see your named course detailed" << std::endl;
    std::cout << "\t" << YELLOW() << "show course -A " << WHITE() << "to see brief info of your courses" << std::endl;
    std::cout << "\t" << YELLOW() << "show course -B " << WHITE() << "to see brief info of your courses bluntly" << std::endl;
    std::cout << "\t" << YELLOW() << "show student -A " << WHITE() << "to see all available students" << std::endl;
    std::cout << "\t" << YELLOW() << "show duty -A " << WHITE() << "to see all your defined home works" << std::endl;
    std::cout << "\t" << YELLOW() << "show duty -B " << WHITE() << "to see all your defined home works bluntly" << std::endl;
    std::cout << "\t" << YELLOW() << "show duty -C <courseName> " << WHITE() << "to see all named courses duties" << std::endl;
    std::cout << "\t" << YELLOW() << "show duty -D <homeWorkName> " << WHITE() << "to see named home work detailed" << std::endl;
    std::cout << "\t" << YELLOW() << "show duty -S <homeWorkName> " << WHITE() << "to see all students who sent named home work" << std::endl;
    std::cout << "\t" << YELLOW() << "show duty -R <homeWorkName> " << WHITE() << "to see all students who didn't send named home work" << std::endl;
    std::cout << std::endl;
}
void sos_HELPER_COMMANDS_teacher()
{
    std::cout << GREEN() << "HELPER COMMANDS:" << WHITE() << std::endl;
    std::cout << "\t" << YELLOW() << "SOS " << WHITE() << "to guide by help instruction" << std::endl;
    std::cout << "\t" << YELLOW() << "clear " << WHITE() << "to clean the console" << std::endl;
    std::cout << "\t" << YELLOW() << "bye " << WHITE() << "to sign_out from your account" << std::endl;
    std::cout << "\t" << YELLOW() << "exit " << WHITE() << "to close the Dotta system" << std::endl;
    std::cout << std::endl;
}
void command_and_check_for_teacher()
{
    cursor_on();
    std::vector<course>all_courses = read_courses_from_file();
    std::vector<HW>HWs = read_HW_from_file();
    while(true)
    {
        std::cout << std::endl;
        std::cout << online_user.display_name() << "@" << "teacher ~ " << std::endl;
        std::cout << PURPLE() <<"# " << WHITE();

        std::string line0;
        std::vector<std::string> commands;

        std::getline(std::cin, line0);
        std::istringstream iss0(line0);
        std::string word0;

        while (iss0 >> word0)
        {
            commands.push_back(word0);
        }

        if (commands[0] == "SOS")
        {
            if (commands[1] == "course")
            {
                sos_COURSE_COMMANDS_teacher();
            }
            else if (commands[1] == "participation")
            {
                sos_PARTICIPATION_COMMANDS_teacher();
            }
            else if (commands[1] == "observation")
            {
                sos_OBSERVATION_COMMANDS_teacher();
            }
            else if (commands[1] == "helper")
            {
                sos_HELPER_COMMANDS_teacher();
            }
            else if (commands[1] == "duty")
            {
                sos_DUTY_COMMANDS_teacher();
            }
            else
            {
                sos_COURSE_COMMANDS_teacher();
                sos_DUTY_COMMANDS_teacher();
                sos_PARTICIPATION_COMMANDS_teacher();
                sos_OBSERVATION_COMMANDS_teacher();
                sos_HELPER_COMMANDS_teacher();
            }
            continue;
        }
        else if (commands[0] == "clear")
        {
            system("cls");
            continue;
        }
        else if (commands[0] == "bye")
        {
            std::cout << "Good luck " << online_user.display_name() << std::endl;
            Sleep(1000);
            system("cls");
            save_courses_to_file(all_courses);
            save_HW_to_file(HWs);
            online_user_reset();
            main_menu();
        }
        else if (commands[0] == "exit")
        {
            save_courses_to_file(all_courses);
            save_HW_to_file(HWs);
            exit(EXIT_SUCCESS);
        }

        else if (commands[0] == "add")
        {
            if (commands.size() > 4)
            {
                std::cerr << RED() << "Wrong flag format!" << WHITE() << std::endl;
                continue;
            }
            if (commands[3] == "on")
            {
                course temp_course(commands[1], online_user.display_name(), std::stoi(commands[2]), true);
                all_courses.push_back(temp_course);
                std::cout << GREEN() << "New course added successfully!" << WHITE() << std::endl;
                continue;
            }
            else if (commands[3] == "off")
            {
                course temp_course(commands[1], online_user.display_name(), std::stoi(commands[2]), false);
                all_courses.push_back(temp_course);
                std::cout << GREEN() << "New course added successfully!" << WHITE() << std::endl;
                continue;
            }
            else
            {
                std::cerr << RED() << "Wrong visibility switch" << WHITE() << std::endl;
                continue;
            }
        }
        else if (commands[0] == "show")
        {
            if (commands[1] == "course")
            {
                if (commands[2] == "-A")
                {
                    for (const auto& c : all_courses)
                    {
                        if (c.visibility && c.teacher == online_user.display_name())
                        {
                            std::cout << YELLOW() <<"Course Name: " << WHITE() << c.name << std::endl;
                        }
                    }
                }
                else if (commands[2] == "-B")
                {
                    for (const auto& c : all_courses)
                    {
                        if (c.teacher == online_user.display_name())
                        {
                            std::cout <<"Course Name: " << c.name << " Visibility: " << c.visibility << std::endl;
                        }
                    }
                }
            }
            else if (commands[1] == "student" && commands[2] == "-A")
            {
                std::ifstream in("people.txt");
                std::string line;
                int index = 0;
                while(std::getline(in, line))
                {
                    std::vector<std::string> info;
                    std::istringstream iss(line);
                    std::string word;
                    while (iss >> word)
                    {
                        info.push_back(word);
                    }

                    if (info[3] == "1" && info[2] == "student")
                    {
                        index += 1;
                        std::cout << index << ". " << info[0] << std::endl;
                    }
                }
                in.close();
                continue;
            }
            else if (commands[1] == "duty")
            {
                if (commands[2] == "-A")
                {
                    int index = 0;
                    for (auto& h : HWs)
                    {
                        if (h.teacher == online_user.display_name() && h.visibility)
                        {
                            index += 1;
                            std::cout << index << ". Name: " << h.name << " Course: " << h.course << std::endl;
                        }
                    }
                }
                else if (commands[2] == "-B")
                {
                    int index = 0;
                    for (auto& h : HWs)
                    {
                        if (h.teacher == online_user.display_name())
                        {
                            index += 1;
                            std::cout << index << ". Name: " << h.name << " Course: " << h.course << " Visibility: " << h.visibility << std::endl;
                        }
                    }
                }
                else if (commands[2] == "-C")
                {
                    int index = 0;
                    for (auto& h : HWs)
                    {
                        if (h.teacher == online_user.display_name() && h.visibility && h.course == commands[3])
                        {
                            index += 1;
                            std::cout << index << ". Name: " << h.name << std::endl;
                        }
                    }
                }
                else if (commands[2] == "-D")
                {
                    int index = 0;
                    for (auto& h : HWs)
                    {
                        if (h.teacher == online_user.display_name() && h.visibility && h.name == commands[3])
                        {
                            index += 1;
                            std::cout << index << ". Name: " << h.name << " Course: " << h.course << std::endl;
                            int index1 = 0;
                            for (const auto& s : h.slaves)
                            {
                                bool is_visible = false;
                                std::ifstream in("people.txt");
                                std::string line;
                                while(std::getline(in, line))
                                {
                                    std::vector<std::string> info;
                                    std::istringstream iss(line);
                                    std::string word;
                                    while (iss >> word)
                                    {
                                        info.push_back(word);
                                    }

                                    if (info[0] == s.name_of_student && info[3] == "1")
                                    {
                                        is_visible = true;
                                    }
                                }
                                in.close();
                                index1 += 1;
                                if (s.sent && is_visible)
                                {
                                    std::cout <<"\t" <<index1 << ". " << s.name_of_student << " Sent? yes " << "Score: " << s.score_of_HW << " Link: " << s.link_of_uploaded_HW << std::endl;
                                }
                                else if (is_visible)
                                {
                                    std::cout <<"\t" <<index1 << ". " << s.name_of_student << " Sent? NO! " << "Score: " << s.score_of_HW << std::endl;
                                }
                            }
                        }
                    }
                }
                else if (commands[2] == "-S")
                {
                    int index = 0;
                    for (auto& h : HWs)
                    {
                        if (h.teacher == online_user.display_name() && h.visibility && h.name == commands[3])
                        {
                            index += 1;
                            std::cout << index << ". Name: " << h.name << " Course: " << h.course << std::endl;
                            int index1 = 0;
                            for (const auto& s : h.slaves)
                            {
                                bool is_visible = false;
                                std::ifstream in("people.txt");
                                std::string line;
                                while(std::getline(in, line))
                                {
                                    std::vector<std::string> info;
                                    std::istringstream iss(line);
                                    std::string word;
                                    while (iss >> word)
                                    {
                                        info.push_back(word);
                                    }

                                    if (info[0] == s.name_of_student && info[3] == "1")
                                    {
                                        is_visible = true;
                                    }
                                }
                                in.close();
                                if (s.sent && is_visible)
                                {
                                    index1 += 1;
                                    std::cout <<"\t" <<index1 << ". " << s.name_of_student << "Score: " << s.score_of_HW << " Link: " << s.link_of_uploaded_HW << std::endl;
                                }
                            }
                        }
                    }
                }
                else if (commands[2] == "-R")
                {
                    int index = 0;
                    for (auto& h : HWs)
                    {
                        if (h.teacher == online_user.display_name() && h.visibility && h.name == commands[3])
                        {
                            index += 1;
                            std::cout << index << ". Name: " << h.name << " Course: " << h.course << std::endl;
                            int index1 = 0;
                            for (const auto& s : h.slaves)
                            {
                                bool is_visible = false;
                                std::ifstream in("people.txt");
                                std::string line;
                                while(std::getline(in, line))
                                {
                                    std::vector<std::string> info;
                                    std::istringstream iss(line);
                                    std::string word;
                                    while (iss >> word)
                                    {
                                        info.push_back(word);
                                    }

                                    if (info[0] == s.name_of_student && info[3] == "1")
                                    {
                                       is_visible = true;
                                    }
                                }
                                in.close();
                                if (!s.sent && is_visible)
                                {
                                    index1 += 1;
                                    std::cout <<"\t" <<index1 << ". " << s.name_of_student << std::endl;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                for (const auto& c : all_courses)
                {
                    if (c.visibility && commands[1] == c.name && c.teacher == online_user.display_name())
                    {
                        std::cout << YELLOW() <<"Course Name: " << WHITE() << c.name << std::endl;
                        std::cout << YELLOW() <<"Capacity: " << WHITE()<< c.capacity << std::endl;

                        std::cout << YELLOW() << "Enrolled Students:" << WHITE() << std::endl;
                        for (const auto& s : c.students)
                        {
                            std::cout << YELLOW() << "Student Name: " << WHITE() <<  s.display_name() << YELLOW() << " Score: " << s.score << WHITE() << std::endl;
                        }

                        std::cout << WHITE() << std::endl;
                    }
                }
                continue;
            }
        }
        else if (commands[0] == "delete")
        {
            if (commands[1] == "course" && commands[2] == "-A")
            {
                for (auto &c: all_courses)
                {
                    if (c.visibility && c.teacher == online_user.display_name())
                    {
                        c.visibility = false;
                        std::cout << GREEN() << "All your courses have been deleted!" << WHITE() << std::endl;
                    }
                }
                continue;
            }
            else
            {
                for (auto &c: all_courses)
                {
                    if (c.visibility && c.teacher == online_user.display_name() && commands[1] == c.name)
                    {
                        c.visibility = false;
                        std::cout << GREEN() << c.name <<" has been deleted!" << WHITE() << std::endl;
                    }
                }
                continue;
            }
        }
        else if (commands[0] == "recovery")
        {
            if (commands[1] == "course" && commands[2] == "-A")
            {
                for (auto &c: all_courses)
                {
                    if (c.visibility && c.teacher == online_user.display_name())
                    {
                        c.visibility = true;
                        std::cout << GREEN() << c.name <<"has been restored!" << WHITE() << std::endl;
                    }
                }
            }
            else
            {
                for (auto &c: all_courses)
                {
                    if (c.visibility && c.teacher == online_user.display_name() && commands[1] == c.name)
                    {
                        c.visibility = true;
                        std::cout << GREEN() << c.name <<"has been restored!" << WHITE() << std::endl;
                    }
                }
            }

            continue;
        }
        else if (commands[0] == "update")
        {
            for (auto &c: all_courses)
            {
                if (c.visibility && c.teacher == online_user.display_name() && commands[1] == c.name)
                {
                    if (commands[2] == "-n")
                    {
                        c.name = commands[3];
                        std::cout << GREEN() << c.name <<"'s name has been updated!" << WHITE() << std::endl;
                    }
                    if (commands[2] == "-c")
                    {
                        c.capacity= std::stoi(commands[3]);
                        std::cout << GREEN() << c.name <<"'s capacity has been updated!" << WHITE() << std::endl;
                    }
                }
            }
            continue;
        }

        else if (commands[0] == "grade")
        {
            for (auto &c: all_courses)
            {
                if (c.visibility && c.teacher == online_user.display_name() && commands[2] == c.name)
                {
                    for (auto &s: c.students)
                    {
                        if (s.display_name() == commands[1]) s.score = std::stoi(commands[3]);
                        std::cout << GREEN() << s.display_name() <<"'s score has been set!" << WHITE() << std::endl;
                        break;
                    }
                }
            }
            continue;
        }
        else if (commands[0] == "enroll")
        {
            for (auto &c: all_courses)
            {
                if (c.visibility && c.teacher == online_user.display_name() && commands[2] == c.name)
                {
                    std::ifstream in("people.txt");
                    std::string line;
                    while(std::getline(in, line))
                    {
                        std::vector<std::string> info;
                        std::istringstream iss(line);
                        std::string word;
                        while (iss >> word)
                        {
                            info.push_back(word);
                        }
                        if (info[3] == "1" && info[2] == "student" && commands[1] == info[0])
                        {
                            student temp_person(info[0], info[1], info[2], true);
                            c.add_student(temp_person, std::stoi(commands[3]));
                            std::cout << GREEN() << "named student added to this course" << WHITE() << std::endl;
                            break;
                        }
                    }
                    in.close();
                }
            }
            continue;
        }
        else if (commands[0] == "remove")
        {
            for (auto &c: all_courses)
            {
                if (c.visibility && c.teacher == online_user.display_name() && commands[2] == c.name)
                {
                    for (auto& s : c.students)
                    {
                        if (s.display_name() == commands[1])
                        {
                            auto it = std::find(c.students.begin(), c.students.end(), s);
                            if (it != c.students.end())
                            {
                                c.students.erase(it);
                                std::cout << GREEN() << s.display_name() << " removed from course successfully" << WHITE() << std::endl;
                            }
                        }
                    }
                }
            }
        }

        else if (commands[0] == "define")
        {
            for (const auto& c : all_courses)
            {
                if (commands[1] == c.name && c.teacher == online_user.display_name())
                {
                    HW temp_HW(commands[2], online_user.display_name(), commands[1], true);
                    for (const auto& s : c.students)
                    {
                        temp_HW.bring_student_to_HW(s.display_name(), "", 0, false);
                    }
                    HWs.push_back(temp_HW);
                    std::cout << GREEN() << "New Home work added for this class" << WHITE() << std::endl;
                }
            }
        }
        else if (commands[0] == "withdraw")
        {
            for (const auto& c : all_courses)
            {
                if (commands[1] == c.name && c.teacher == online_user.display_name())
                {
                    for (auto& h : HWs)
                    {
                        if (commands[2] == h.name)
                        {
                            h.visibility = false;
                            std::cout << GREEN() << h.name << " removed from your home works successfully" << WHITE() << std::endl;
                        }
                    }
                }
            }
        }
        else if (commands[0] == "misery")
        {
            for (const auto& c : all_courses)
            {
                if (commands[1] == c.name && c.teacher == online_user.display_name())
                {
                    for (auto& h : HWs)
                    {
                        if (commands[2] == h.name)
                        {
                            h.visibility = true;
                            std::cout << GREEN() << h.name << " restored in your home works successfully" << WHITE() << std::endl;
                        }
                    }
                }
            }
        }
        else if (commands[0] == "mark")
        {
            for (const auto& c : all_courses)
            {
                if (commands[1] == c.name && c.teacher == online_user.display_name())
                {
                    for (auto& h : HWs)
                    {
                        if (commands[2] == h.name)
                        {
                            for (auto& s : h.slaves)
                            {
                                if (s.name_of_student == commands[3])
                                {
                                    s.score_of_HW = std::stoi(commands[4]);
                                    std::cout << GREEN() << h.name << " removed from course successfully" << WHITE() << std::endl;
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            std::cerr << RED() << "Wrong command prompt!" << WHITE() << std::endl;
            continue;
        }
    }
}

void sos_OBSERVATION_COMMANDS_student()
{
    std::cout << GREEN() << "OBSERVATION COMMANDS:" << WHITE() << std::endl;
    std::cout << "\t" << YELLOW() << "show course -A " << WHITE() << "to see all your courses" << std::endl;
    std::cout << "\t" << YELLOW() << "show score -A " << WHITE() << "to see all scores you got in courses" << std::endl;
    std::cout << "\t" << YELLOW() << "show score -C <courseName> " << WHITE() << "to see your score in called course" << std::endl;
    std::cout << "\t" << YELLOW() << "show duty -A " << WHITE() << "to see all your home works" << std::endl;
    std::cout << "\t" << YELLOW() << "show duty -R " << WHITE() << "to see all remaining your home works" << std::endl;
    std::cout << "\t" << YELLOW() << "show duty -C <courseName> " << WHITE() << "to see all your home works in called course" << std::endl;
    std::cout << "\t" << YELLOW() << "show duty -D <courseName> <homeWorkName> " << WHITE() << "to see named home works detailed" << std::endl;
    std::cout << std::endl;
}
void sos_DUTY_COMMANDS_student()
{
    std::cout << GREEN() << "DUTY COMMANDS:" << WHITE() << std::endl;
    std::cout << "\t" << YELLOW() << "send duty <courseName> <homeWorkName> <linkOfUploadedHW> " << WHITE() << "to attach your named home work" << std::endl;
    std::cout << "\t" << YELLOW() << "change duty <courseName> <homeWorkName> <newLinkOfUploadedHW> " << WHITE() << "to change your attachment" << std::endl;
    std::cout << "\t" << YELLOW() << "explode duty <courseName> <homeWorkName> " << WHITE() << "to delete your attachment" << std::endl;
}
void command_and_check_for_student()
{
    cursor_on();
    std::vector<course>all_courses = read_courses_from_file();
    std::vector<HW>HWs = read_HW_from_file();
    while(true)
    {
        std::cout << std::endl;
        std::cout << online_user.display_name() << "@" << "student ~ " << std::endl;
        std::cout << BLUE() << "& " << WHITE();

        std::string line;
        std::vector<std::string> commands;

        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string word;

        while (iss >> word)
        {
            commands.push_back(word);
        }

        if (commands[0] == "SOS")
        {
            if (commands[1] == "observation")
            {
                sos_OBSERVATION_COMMANDS_student();
            }
            else if (commands[1] == "helper")
            {
                sos_HELPER_COMMANDS_teacher();
            }
            else if (commands[1] == "duty")
            {
                sos_DUTY_COMMANDS_student();
            }
            else
            {
                sos_OBSERVATION_COMMANDS_student();
                sos_DUTY_COMMANDS_student();
                sos_HELPER_COMMANDS_teacher();
            }
            continue;
        }
        else if (commands[0] == "clear")
        {
            system("cls");
            continue;
        }
        else if (commands[0] == "bye")
        {
            std::cout << "Good luck " << online_user.display_name() << std::endl;
            Sleep(1000);
            system("cls");
            save_courses_to_file(all_courses);
            save_HW_to_file(HWs);
            online_user_reset();
            main_menu();
        }
        else if (commands[0] == "exit")
        {
            save_courses_to_file(all_courses);
            save_HW_to_file(HWs);
            exit(EXIT_SUCCESS);
        }
        else if (commands[0] == "show")
        {
            if (commands[1] == "score")
            {
                if (commands[2] == "-A")
                {
                    for (const auto& c : all_courses)
                    {
                        if (c.visibility)
                        {
                            int  index = 0;
                            for (auto& s : c.students)
                            {
                                if (s.display_name() == online_user.display_name())
                                {
                                    index += 1;
                                    std::cout << YELLOW() << index <<". Course Name: " << WHITE() << c.name << std::endl;
                                    std::cout << YELLOW() <<"\tTeacher: " << WHITE() << c.teacher << std::endl;
                                    std::cout << YELLOW() <<"\tYour Score: " << WHITE() << s.score << std::endl;
                                }
                            }
                        }
                    }
                }
                else if (commands[2] == "-C")
                {
                    for (const auto& c : all_courses)
                    {
                        if (c.visibility)
                        {
                            for (auto& s : c.students)
                            {
                                if (s.display_name() == online_user.display_name() && commands[3] == c.name)
                                {
                                    std::cout << YELLOW() <<"Teacher: " << WHITE() << c.teacher << YELLOW() <<" Your Score: " << WHITE() << s.score << std::endl;
                                }
                            }
                        }
                    }
                }
            }
            else if (commands[1] == "course" && commands[2] == "-A")
            {
                for (const auto& c : all_courses)
                {
                    for (const auto& s : c.students)
                    {
                        if (online_user.display_name() == s.display_name() && c.visibility)
                        {
                            std::cout << "Course name: " << c.name << std::endl;
                        }
                    }
                }
            }
            else if (commands[1] == "duty")
            {
                if (commands[2] == "-A")
                {
                    int index = 0;
                    for (const auto& h : HWs)
                    {
                        for (const auto& s : h.slaves)
                        {
                            if (online_user.display_name() == s.name_of_student && h.visibility)
                            {
                                index += 1;
                                std::cout << index << ". Name: " << h.name << " Teacher: " << h.teacher << " Course: " << h.course << " Sent? " << s.sent << std::endl;
                            }
                        }
                    }
                }
                else if (commands[2] == "-R")
                {
                    int index = 0;
                    for (const auto& h : HWs)
                    {
                        for (const auto& s : h.slaves)
                        {
                            if (online_user.display_name() == s.name_of_student && !s.sent && h.visibility)
                            {
                                index += 1;
                                std::cout << index << ". Name: " << h.name << " Teacher: " << h.teacher << " Course: " << h.course << std::endl;
                            }
                        }
                    }
                }
                else if (commands[2] == "-C")
                {
                    int index = 0;
                    for (const auto& h : HWs)
                    {
                        for (const auto& s : h.slaves)
                        {
                            if (online_user.display_name() == s.name_of_student && h.course == commands[3] && h.visibility)
                            {
                                std::cout << index << ". Name: " << h.name << " Teacher: " << h.teacher << " Sent? " << s.sent << std::endl;
                            }
                        }
                    }
                }
                else if (commands[2] == "-D")
                {
                    int index = 0;
                    for (const auto& h : HWs)
                    {
                        for (const auto& s : h.slaves)
                        {
                            if (online_user.display_name() == s.name_of_student && h.course == commands[3] && h.visibility)
                            {
                                index += 1;
                                std::cout << index << ". Name: " << h.name << " Teacher: " << h.teacher << " Sent? " << s.sent << std::endl;
                                std::cout << "\t" << "Gotten score: " << s.score_of_HW << " Source: " << s.link_of_uploaded_HW << std::endl;
                                break;
                            }
                        }
                    }
                }
            }
        }
        else if (commands[0] == "send" && commands[1] == "duty")
        {
            for (auto& h : HWs)
            {
                if (h.name == commands[3])
                {
                    if (commands[2] == h.course)
                    {
                        for (auto& s : h.slaves)
                        {
                            if (online_user.display_name() == s.name_of_student && h.visibility)
                            {
                                if (!s.sent)
                                {
                                    s.link_of_uploaded_HW = commands[4];
                                    s.sent = true;
                                    std::cout << GREEN() << "We caught your home work successfully!" << WHITE() << std::endl;
                                    break;
                                }
                                else
                                {
                                    std::cerr << RED() << "You have sent your home work, if you want, you can change it" << WHITE() << std::endl;
                                    std::cout << YELLOW() << "change duty <courseName> <homeWorkName> <newLinkOfUploadedHW> " << WHITE() << "to change your attachment" << std::endl;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        else if (commands[0] == "change" && commands[1] == "duty")
        {
            for (auto& h : HWs)
            {
                if (h.name == commands[3])
                {
                    if (commands[2] == h.course)
                    {
                        for (auto& s : h.slaves)
                        {
                            if (online_user.display_name() == s.name_of_student && s.sent && h.visibility)
                            {
                                s.link_of_uploaded_HW = commands[4];
                                std::cout << GREEN() << "We changed your home work successfully!" << WHITE() << std::endl;
                                break;
                            }
                        }
                    }
                }
            }
        }
        else if (commands[0] == "explode" && commands[1] == "duty")
        {
            for (auto& h : HWs)
            {
                if (h.name == commands[3])
                {
                    if (commands[2] == h.course)
                    {
                        for (auto& s : h.slaves)
                        {
                            if (online_user.display_name() == s.name_of_student && h.visibility)
                            {
                                if (s.sent)
                                {
                                    s.sent = false;
                                    std::cout << GREEN() << "We terminated your home work successfully!" << WHITE() << std::endl;
                                    break;
                                }
                                else
                                {
                                    std::cerr << RED() << "What do you actually want to delete? You sent nothing baby!" << WHITE() << std::endl;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
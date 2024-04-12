//
// Created by Ali on 2024-03-30.
//
#include "universal_header.h"

std::vector<course> read_courses_from_file()
{
    std::vector<course> courses;
    std::ifstream file("course.txt");
    if (file.is_open())
    {
        std::string line0;
        while (std::getline(file, line0))
        {
            std::vector<std::string> info0;
            std::istringstream iss0(line0);
            std::string word0;

            while (iss0 >> word0)
            {
                info0.push_back(word0);
            }

            course temp(info0[0], info0[1], std::stoi(info0[2]), (info0[3] == "1"));
            if (info0.size() > 4)
            {
                for (int i = 4; i < info0.size() ; i += 2)
                {
                    student temp_student(info0[i], "1383", "student", true);
                    temp_student.score = std::stoi(info0[i + 1]);
                    temp.add_student(temp_student, std::stoi(info0[i + 1]));
                }
            }
            courses.push_back(temp);
        }
        file.close();
    }
    else
    {
        std::cerr << RED() << "Unable to open file for reading" << WHITE() << std::endl;
    }
    return courses;
}
void save_courses_to_file(const std::vector<course>& courses)
{
    std::ofstream file("course.txt");
    if (!file)
    {
        std::cerr << RED() << "Unable to open file for writing" << WHITE() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    for (const auto& c : courses)
    {
        file << c.name << "\t";
        file << c.teacher << "\t";
        file << c.capacity << "\t";
        file << c.visibility << "\t";
        for (const auto& s : c.students)
        {
            file << s.display_name() << "\t";
            file << s.score << "\t";
        }
        file << "\n";
    }
    file.close();
}
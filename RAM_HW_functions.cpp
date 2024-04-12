//
// Created by Ali on 2024-04-07.
//
#include "universal_header.h"

std::vector<HW> read_HW_from_file()
{
    std::vector<HW> HWs;
    std::ifstream file("HW.txt");
    if (file.is_open())
    {
        HW temp_HW("", "", "", false);
        std::string line;
        while (std::getline(file, line))
        {
            std::vector<std::string> info;
            std::istringstream iss(line);
            std::string word;

            while (iss >> word)
            {
                info.push_back(word);
            }
            if (info[0] == "HW")
            {
                temp_HW.name = info[1];
                temp_HW.teacher = info[2];
                temp_HW.course = info[3];
                temp_HW.visibility = info[4] == "1";
                continue;
            }
            else if (info[0] == "EOH")
            {
                HWs.push_back(temp_HW);
                temp_HW.name = "";
                temp_HW.teacher = "";
                temp_HW.course = "";
                temp_HW.visibility = false;
                temp_HW.slaves.clear();
                continue;
            }
            else
            {
                temp_HW.bring_student_to_HW(info[0], info[1], std::stoi(info[2]), (info[3] == "1"));
            }
        }
        file.close();
    }
    else
    {
        std::cerr << RED() << "Unable to open file for reading" << WHITE() << std::endl;
    }
    return HWs;
}
void save_HW_to_file(const std::vector<HW>& HWs)
{
    std::ofstream file("HW.txt");
    if (!file)
    {
        std::cerr << RED() << "Unable to open file for writing" << WHITE() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    for (const auto& h : HWs)
    {
        file << "HW" << "\t";
        file << h.name << "\t";
        file << h.teacher << "\t";
        file << h.course << "\t";
        file << h.visibility << "\n";
        for (const auto& s : h.slaves)
        {
            file << s.name_of_student << "\t";
            file << s.link_of_uploaded_HW << "\t";
            file << s.score_of_HW << "\t";
            file << s.sent << "\n";
        }
        file << "EOH\n";
    }
    file.close();
}
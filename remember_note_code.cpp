//
// Created by Ali on 2024-04-03.
//
/*
 * A function which reads data from people.txt file and bring each line of that into a vector to be processed:
 *
 * std::ifstream in("people.txt");
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
        std::cout << info[0] << " " << info[1] << " " << info[2] << std::endl;
    }
    in.close();
 */
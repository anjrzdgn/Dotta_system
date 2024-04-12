//
// Created by Ali on 2024-03-28.
//

#ifndef DOTTA_DOTTA_IDENTIFIED_CLASSES_H
#define DOTTA_DOTTA_IDENTIFIED_CLASSES_H

#include "universal_header.h"

class person
{
    private:
        std::string name;
        std::string password;
        std::string rule;
        bool visibility;

    public:
        person(std::string  name, std::string  pass, std::string  rule, bool vis)
                : name(std::move(name)), password(std::move(pass)), rule(std::move(rule)), visibility(vis) {}

        std::string display_name() const
        {
            return this->name;
        }

        std::string display_password() const
        {
            return this->password;
        }

        std::string display_rule() const
        {
            return this->rule;
        }

        bool display_visibility() const
        {
            return this->visibility;
        }

        void set_name(const std::string& new_name)
        {
            this->name = new_name;
        }

        void set_password(const std::string& new_password)
        {
            this->password = new_password;
        }

        void set_rule(const std::string& new_rule)
        {
            this->rule = new_rule;
        }

        void set_visibility(const bool new_visibility)
        {
            this->visibility = new_visibility;
        }

        void save_to_file(const std::string& filename) const
        {
            std::ofstream out(filename, std::ios::app);
            if (out.is_open() && out.good())
            {
                out << name << "\t\t" << password << "\t\t" << rule << "\t\t" << visibility << '\n';
                out.close();
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const person& p)
        {
            os << p.name << "\t\t" << p.password << "\t\t" << p.rule << "\t\t" << p.visibility << '\n';
            return os;
        }
};

class student : public person
{
    public:
        using person::person;
        int score{};
        bool operator==(const student& other) const
        {
            return this->display_name() == other.display_name() && this->score == other.score;
        }
};

class course
{
    public:
        std::string name;
        std::string teacher;
        int capacity;
        bool visibility;
        std::vector<student> students;

        course(std::string name, std::string teacher, int capacity, bool visibility)
        : name(std::move(name)), teacher(std::move(teacher)), capacity(capacity), visibility(visibility) {}

        void add_student(student& s, int score)
        {
            students.push_back(s);
            students.back().score = score;
        }
};

class slave
{
    public:
        std::string name_of_student;
        std::string link_of_uploaded_HW;
        int score_of_HW;
        bool sent;

        slave(std::string name, std::string link, int HW_score, bool sent)
        : name_of_student(std::move(name)), link_of_uploaded_HW(std::move(link)), score_of_HW(HW_score), sent(sent) {}
};

class HW
{
    public:
        std::string name;
        std::string teacher;
        std::string course;
        bool visibility;
        std::vector<slave> slaves;

        HW(std::string name, std::string teacher, std::string course, bool visibility)
        : name(std::move(name)), teacher(std::move(teacher)), course(std::move(course)), visibility(visibility) {}

        void bring_student_to_HW(const std::string& student_name, const std::string& HW_link, int HW_score, bool sent)
        {
            slave temp_slave(student_name, HW_link, HW_score, sent);
            slaves.push_back(temp_slave);
        }
};

#endif //DOTTA_DOTTA_IDENTIFIED_CLASSES_H

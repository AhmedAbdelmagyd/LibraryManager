#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member {
public:
    Member(const std::string& name, const std::string& member_id);
    std::string get_name() const;
    std::string get_member_id() const;

private:
    std::string name;
    std::string member_id;
};

#endif // MEMBER_H

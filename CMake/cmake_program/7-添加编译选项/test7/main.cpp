#include <iostream>

using namespace std;

class Person{
public:
    Person(string name, int age){
        this->m_name = name;
        this->m_age = age;
    }

    void showPerson(){
        cout << "name=" << m_name << " age=" << m_age << endl;
    }

public:
    string m_name;
    int m_age;
};

int main(void)
{
    auto data = 100;
    cout << "data: " << data << "\n";

    Person p("Kownzird",18);
    p.showPerson();
    
    return 0;
}
#include <iostream>
using namespace std;

struct Student {
    int id;
    string name;
    string cls;
    Student* next;
};

Student* head = nullptr;

void add(int id, string name, string cls) {
    Student* newStu = new Student{id, name, cls, head};
    head = newStu;
}

void remove(int id) {
    Student* cur = head;
    Student* prev = nullptr;
    while (cur != nullptr && cur->id != id) {
        prev = cur;
        cur = cur->next;
    }
    if (cur != nullptr) {
        if (prev == nullptr) {
            head = cur->next;
        } else {
            prev->next = cur->next;
        }
        delete cur;
    }
}

void info(int id) {
    cout << "----------" << endl;
    Student* cur = head;
    while (cur != nullptr) {
        if (cur->id == id) {
            cout << cur->name << "," << cur->cls << endl;
            return;
        }
        cur = cur->next;
    }
    cout << "NA,NA" << endl;
}

void process(string cmd) {
    if (cmd.substr(0, 6) == "Insert") {
        int id;
        string name, cls;
        size_t p1 = cmd.find('(') + 1;
        size_t p2 = cmd.find(',', p1);
        id = stoi(cmd.substr(p1, p2 - p1));
        p1 = p2 + 1;
        p2 = cmd.find(',', p1);
        name = cmd.substr(p1, p2 - p1);
        p1 = p2 + 1;
        p2 = cmd.find(')', p1);
        cls = cmd.substr(p1, p2 - p1);
        add(id, name, cls);
    } else if (cmd.substr(0, 6) == "Delete") {
        int id = stoi(cmd.substr(7));
        remove(id);
    } else if (cmd.substr(0, 5) == "Infor") {
        int id = stoi(cmd.substr(6));
        info(id);
    }
}

int main() {
    string cmd;
    while (getline(cin, cmd)) {
        process(cmd);
    }
    return 0;
}

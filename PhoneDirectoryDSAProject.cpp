#include <iostream>
#include <fstream>
#include <sstream>

class BSTNode {
public:
    std::string contactname;
    std::string email;
    std::string phonenumber;
    BSTNode* left;
    BSTNode* right;

    BSTNode() : left(nullptr), right(nullptr) {}

    BSTNode(const std::string& contactname, const std::string& email, const std::string& phonenumber)
        : contactname(contactname), email(email), phonenumber(phonenumber), left(nullptr), right(nullptr) {}

    void insert(const std::string& contactname, const std::string& email, const std::string& phonenumber) {
        if (contactname.compare(this->contactname) < 0) {
            if (left == nullptr) {
                left = new BSTNode(contactname, email, phonenumber);
            }
            else {
                left->insert(contactname, email, phonenumber);
            }
        }
        else if (contactname.compare(this->contactname) > 0) {
            if (right == nullptr) {
                right = new BSTNode(contactname, email, phonenumber);
            }
            else {
                right->insert(contactname, email, phonenumber);
            }
        }
    }

    std::string search(const std::string& contactname) {
        if (contactname == this->contactname) {
            return contactname + "," + email + "," + phonenumber;
        }
        else if (contactname.compare(this->contactname) < 0 && left != nullptr) {
            return left->search(contactname);
        }
        else if (contactname.compare(this->contactname) > 0 && right != nullptr) {
            return right->search(contactname);
        }
        else {
            return "no contact found please check";
        }
    }

    std::string displayfirst() {
        if (left == nullptr) {
            return contactname + "," + email + "," + phonenumber;
        }
        else {
            return left->displayfirst();
        }
    }

    std::string displaylast() {
        if (right == nullptr) {
            return contactname + "," + email + "," + phonenumber;
        }
        else {
            return right->displaylast();
        }
    }

    void display() {
        if (left != nullptr) {
            left->display();
        }
        std::cout << contactname + "," + email + "," + phonenumber << std::endl;
        if (right != nullptr) {
            right->display();
        }
    }

    ~BSTNode() {
        delete left;
        delete right;
    }
};

class BST {
public:
    BSTNode* root;

    BST() : root(nullptr) {}

    void display() {
        if (root == nullptr) {
            return;
        }
        else {
            root->display();
        }
    }

    std::string displayfirst() {
        if (root == nullptr) {
            return "";
        }
        else {
            return root->displayfirst();
        }
    }

    std::string displaylast() {
        if (root == nullptr) {
            return "";
        }
        else {
            return root->displaylast();
        }
    }

    std::string search(const std::string& contactname) {
        if (root == nullptr) {
            return "";
        }
        else {
            return root->search(contactname);
        }
    }

    void insert(const std::string& contactname, const std::string& email, const std::string& phonenumber) {
        if (root == nullptr) {
            root = new BSTNode(contactname, email, phonenumber);
        }
        else {
            root->insert(contactname, email, phonenumber);
        }
    }

    ~BST() {
        delete root;
    }
};

int main() {
    try {
        BST d;
        std::string contactname;
        std::string email;
        std::string phonenumber;
        std::string arr[3];
        std::ifstream contact("mycontacts.txt");
        std::string line;

        while (std::getline(contact, line)) {
            std::istringstream iss(line);
            for (int i = 0; i < 3; ++i) {
                iss >> arr[i];
            }
            contactname = arr[0];
            email = arr[1];
            phonenumber = arr[2];
            d.insert(contactname, email, phonenumber);
        }

        contact.close();

        while (true) {
            std::cout << "0.exit  1.diplay  2.displayfirst  3.displaylast  4.search 5.Insert" << std::endl;
            std::cout << "What would you like to do? ";
            int z;
            std::cin >> z;
            std::cin.ignore(); // consume newline character
            if (z == 0) {
                break;
            }
            else if (z == 1) {
                d.display();
            }
            else if (z == 2) {
                std::string s = d.displayfirst();
                std::cout << s << std::endl;
            }
            else if (z == 3) {
                std::string s = d.displaylast();
                std::cout << s << std::endl;
            }
            else if (z == 4) {
                std::cout << "Enter name: ";
                std::getline(std::cin, contactname);
                std::string a = d.search(contactname);
                std::cout << a << std::endl;
            }
            else if (z == 5) {
                std::cout << "Enter contactname: ";
                std::getline(std::cin, contactname);
                std::cout << "Enter e-mail: ";
                std::getline(std::cin, email);
                std::cout << "Enter contactnum: ";
                std::getline(std::cin, phonenumber);
                d.insert(contactname, email, phonenumber);
            }
            else {
                std::cout << "Please Check the number" << std::endl;
            }
        }
    }
    catch (const std::ifstream::failure& file_error) {
        std::cerr << "File not found" << std::endl;
        file_error.what();
    }

    return 0;
}

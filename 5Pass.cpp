
#include <iostream>

using namespace std;


class Password {

public:
    Password(string _pass) {
        pass = _pass;
    }
    
    int checkComp() {
        return contains_number() + contains_sign() + contains_letter();
    }
    
    void setPass(string _pass) {
        pass = _pass;
    }
    
    
    bool operator==(const Password &p) const {
        return (p.pass == pass);
    } 
    
    
    bool operator!=(const Password &p) const {
        return (p.pass != pass);
    } 
    
    
private:
    string pass;
    
    bool contains_number() {
        return (pass.find_first_of("0123456789") != string::npos);
    } 
    
    bool contains_sign() {
        return (pass.find_first_of(".,!&?()=+-_") != string::npos);
    } 
    
    bool contains_letter() {
        return (pass.find_first_of("abcdefghijklmnopqrstuvwxyz") != string::npos);
    } 
};


int main() {
    
    Password pass("12345");
    cout << pass.checkComp() << endl;

    pass.setPass("qwert");
    cout << pass.checkComp() << endl;

    pass.setPass("123qw");
    cout << pass.checkComp() << endl;

    pass.setPass("123!!");
    cout << pass.checkComp() << endl;

    pass.setPass("123qw!!");
    cout << pass.checkComp() << endl;

    return 0;
}

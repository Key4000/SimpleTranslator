#include <iostream>
#include <ctype.h>
#include <cstdio>

using namespace std;

class Parser {

    static int lookahead;

public:
    Parser() {
        cin >> lookahead;
    }
    void expr() {
        term();
        while (true) {
            if (lookahead == '+') {
                match('+'); term(); std::cout << '+';
            }
            else if (lookahead == '-')
            {
                match('-'); term(); std::cout << '-';
            }
            else return;
        }
    };
    void term() {
        if (isdigit((char)lookahead)) {
            std::cout << (char)lookahead;
            match(lookahead);
        }
    
    };
    void match(int t) {
        if (lookahead == t)
            std::cin >> lookahead;
        else 
            throw("Syntax error");
    }
};

class Postfix {
    public:
        static void main() {
            Parser parse = Parser();
            parse.expr(); std::cout << '\n';
        }

};

int main()
{
    Postfix postfix;
    postfix.main();
}

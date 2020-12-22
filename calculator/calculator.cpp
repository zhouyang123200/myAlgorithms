#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

class ExpressionEvaluator {

    public:
        ExpressionEvaluator(vector<pair<string, string>>& toks):tokens {toks} {
            tok = tokens.begin();
        }

        float parse() {

            return expr();
        }

        float expr() {
            float exprval {term()};
            while (accept("plus"s) || accept("minus"s)) {
                string op {(tok - 1)->first};
                float right {term()};
                if (op == "plus"s)
                    exprval += right; 
                else if (op == "minus"s)
                    exprval -= right;
            }

            return exprval;
        }

        float term() {
            float termval {factor()};
            while (accept("times"s) || accept("divide"s)) {
                string op {(tok - 1)->first};
                float right {factor()};
                if (op == "times"s)
                    termval *= right;
                else if (op == "divide"s)
                    termval /= right;
            }

            return termval;
        }

        float factor() {
            float val;
            if (accept("num"s)) {
                val = stof((tok - 1)->second);
            }
            else if (accept("lparen"s)) {
                float exprval {expr()};
                accept("rparen"s);
                val = exprval;
            }

            return val;
        }

    private:
        vector<pair<string, string>>& tokens;
        vector<pair<string, string>>::iterator tok;

        void advance() {
            tok++;
        }

        bool accept(string toktype) {
            bool ret {true};
            if (tok != tokens.end() && tok->first == toktype)
                advance();
            else
                ret = false;
            return ret;
        }
};
void generate_tokens(string, vector<pair<string, string>>&);

int main() {
    string expr {"43.2*2"};
    vector<pair<string, string>> tokens;

    generate_tokens(expr, tokens);

    // for (auto token: tokens) {
    //     cout << "type: " << token.first << ' ' << "val: " << token.second << endl;
    // }
    ExpressionEvaluator expression{tokens};

    cout << expression.parse() << endl;

    return 0;
}

void generate_tokens(string text, vector<pair<string, string>>& tokens) {
    string token {""};
    for (auto x: text) {
        if ((x >= '0' && x <='9') or x == '.') {
            token += x;
        } else {
            if (token.length() != 0) {
                tokens.push_back(pair<string, string> {"num"s, token});
                token = "";
            }
            if (x == '+') {
                tokens.push_back(pair<string, string> {"plus"s, "+"s});
            } else if (x == '-') {
                if (tokens.size() == 0 || tokens.back().first == "lparen"s) {
                    token += x;
                }
                else {
                    tokens.push_back(pair<string, string> {"minus"s, "-"s});
                }
            } else if (x == '*') {
                tokens.push_back(pair<string, string> {"times"s, "*"s});
            } else if (x == '/') {
                tokens.push_back(pair<string, string> {"divide"s, "/"s});
            } else if (x == '(') {
                tokens.push_back(pair<string, string> {"lparen"s, "("s});
            } else if (x == ')') {
                tokens.push_back(pair<string, string> {"rparen"s, ")"s});
            }
        }
    }
    if (token.length() != 0)
        tokens.push_back(pair<string, string> {"num"s, token});
}


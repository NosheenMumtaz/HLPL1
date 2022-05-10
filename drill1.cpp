                                                          //CHAPTER NO 6

#include <iostream>
using namespace std;
//------------------------------------------------------------------------------

// Logical error no 1: lass changed to class:
class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    
    if (full) perror("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------
/* Here return type is Token
*  get was defined in class Token_stream
* so we change Token get() into Token Token_stream ::  get()
*/
Token Token_stream ::  get()
{
    {
    
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case '=':    // we changed ';' to '=' for print 
    case 'x':    // we changed 'q' to 'x' for print
    case '(': case ')': case '+': case '-': case '*': case '/':case '%':// add remainder
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':// case '8' was missing here
    {
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token('8', val);   // let '8' represent "a number"
    }
    default:
        perror("Bad token");
    }
}
    return 0;
}
//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    {
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        // " is missing here so it gives error
        if (t.kind != ')') perror("')' expected");
            return d;
    }
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
    default:
        perror("primary expected");
    }
}
    return 0;
}
//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        // add {} and break in every case:
        case '*':
        {
            left *= primary();
            t = ts.get();
            break;
        }
         
        case '/':
        {
            double d = primary();
            if (d == 0) perror("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }

        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    // we change term( to term() in next line:
    double left = term();     // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
        {
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
           }
        case '-':
        {
        // we change '+' into '-' because this case evaluates -:
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
           }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

int main()
// we define val and add greeting line in calculator along with description:
{
    cout << "Welcome to our simple calculator."<< endl;
    cout << "Please enter expressions using floating-point numbers" << endl;
    cout << "Please use + for sum | * for multiplication | / for division | - for subtraction | % for remainder !" << endl;
    cout << "Use = to print your value" << endl;
    cout << "Use x to quit" << endl;
    double val = 0.0;
    try
    {
        while (cin) {
            Token t = ts.get();

            if (t.kind == 'x')  // we change 'q' to 'x':
                break;
            if (t.kind == '=')        // we change ';' to '=':
                cout << "" << val << '\n';
            else
                ts.putback(t);
            val = expression();
        }
       
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << '\n';
        
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
       
        return 2;
    }
}
//------------------------------------------------------------------------------

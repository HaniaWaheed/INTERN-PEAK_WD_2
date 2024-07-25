/* Hania Waheef
roll no: 22i-0982
Section C
*/

#include <iostream>
using namespace std;

int function_watch_time(int indx, int ln) {
    if (ln >= 9)
        return 0;
    if (ln == 1) {
        if (indx == 7)
            cout << "/ ";
        else if (indx == 16) {
            cout << "\\" << endl;;
            function_watch_time(0, ++ln);
            return 0;
        }
        else if (indx == 8 || indx == 15)
            cout << ". ";
        else if (indx == 9 || indx == 14)
            cout << "'";
        else if (indx == 11)
            cout << "1";
        else if (indx == 12)
            cout << "2";
        else
            cout << " ";
    }
    else if (ln == 2) {
        if (indx == 6 || indx == 7)
            cout << "/";
        else if (indx == 16) {
            cout << "\\";

        }
        else if (indx == 17)
        {
            cout << "\\" << endl;
            function_watch_time(0, ++ln);
            return 0;
        }
        cout << " ";
    }
    else if (ln == 3) {
        if (indx == 5 || indx == 6 || indx == 16 || indx == 17) {
            cout << "|";
            if (indx == 17) {
                cout << endl;
                function_watch_time(0, ++ln);
                return 0;
            }
        }
        else if (indx == 13)
            cout << "/";

        cout << " ";
    }
    else if (ln == 4) {
        if (indx == 5 || indx == 6 || indx == 14 || indx == 15) {
            cout << "|";
        }
        else if (indx == 7) cout << "9";
        else if (indx == 10) cout << ".";
        else if (indx == 13) cout << "3";
        else if (indx == 16) {
            cout << ")" << endl;
            function_watch_time(0, ++ln);
            return 0;
        }
        if (indx != 15)
            cout << " ";
    }
    else if (ln == 5) {
        if (indx == 5 || indx == 6 || indx == 16 || indx == 17) {
            cout << "|";
            if (indx == 17) {
                cout << endl;
                function_watch_time(0, ++ln);
                return 0;
            }
        }
        else if (indx == 10)
            cout << "/";

        cout << " ";
    }
    else if (ln == 6) {
        if (indx == 6 || indx == 7)
            cout << "\\";
        else if (indx == 16) {
            cout << "/";

        }
        else if (indx == 17)
        {
            cout << "/" << endl;
            function_watch_time(0, ++ln);
            return 0;
        }
        cout << " ";
    }
    else if (ln == 7) {
        if (indx == 7)
            cout << "\\ ";
        else if (indx == 16) {
            cout << "/" << endl;;
            function_watch_time(0, ++ln);
            return 0;
        }
        else if (indx == 8)
            cout << "' ";
        else if (indx == 14)
            cout << " '";
        else if (indx == 9 || indx == 13)
            cout << ".";
        else if (indx == 11)
            cout << "6";
        else if (indx > 8 && indx < 15)
            cout << "_";
        else
            cout << " ";
    }
    else if (ln == 8) {
        cout << " ";
        if (indx == 7)
            cout << "(";
        else if (indx == 8 || indx == 13)
            cout << "=";
        else if (indx == 14) {
            ln++;
            cout << ")" << endl;
        }
    }

    function_watch_time(++indx, ln);
    return 0;


}

int function_watch_strap(int indx, int ln) {
    if (ln >= 3)
        return 0;
    if (ln < 3 && (indx == 8 || indx == 15)) {
        cout << "|";
        if (indx == 15) {
            indx = 0;
            cout << endl;
            ln++;
        }
    }
    else if (ln < 3 && (indx == 9 || indx == 14))
        cout << ":";
    cout << " ";
    function_watch_strap(++indx, ln);
    return 0;
}

int function_main_recursion(int indx, int ln) {
    if (ln > 3) {
        function_watch_time(0, 1);
        function_watch_strap(0, 0);
        return 0;
    }

    if (ln < 3 && (indx == 8 || indx == 15)) {
        cout << "|";
        if (indx == 15) {
            indx = 0;
            cout << endl;
            ln++;
        }
    }
    else if (ln < 3 && (indx == 9 || indx == 14))
        cout << ":";

    if (ln != 3 && ln != 2)
        cout << " ";
    else if ((ln == 3 || ln == 2) && indx > 8 && indx < 14)
        cout << "_";
    else
        cout << " ";


    if (ln == 3) {
        if (indx == 7)
            cout << "(";
        else if (indx == 8 || indx == 13)
            cout << "=";
        else if (indx == 14) {
            ln++;
            cout << ")" << endl;
            function_main_recursion(indx, ln);

            return 0;
        }

        function_main_recursion(++indx, ln);

        return 0;
    }

    function_main_recursion(++indx, ln);
    return 0;
}



int main() {
    int indx = 0;
    int ln = 0;
    function_main_recursion(indx, ln);
    return 0;
}
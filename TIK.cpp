
///HELLO TO ALL OF U,

#include <iostream>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;

int i = 0;
char s[3][3];
int bl = 1;
int x = 0;
string p1, p2;
int sc1 = 0;
int sc2 = 0;
int dr = 0;
string c1;
string c2;

int status()
{
    int flag = 0;
    int flag2 = 0;
    int count = 0;

    int cx = 0, co = 0, c_ = 0;

    for (int i = 0; i < 3; i++) {//vertical match
        if ((s[0][i] == s[1][i]) && (s[1][i] == s[2][i])){
            if ((s[0][i]) != '_'){
                count++;
            }
        }
    }
    for (int i = 0; i < 3; i++) {//horizontal match
        if ((s[i][0] == s[i][1]) && (s[i][1] == s[i][2])){
            if ((s[i][0]) != '_'){
                count++;
            }
        }
    }

    if ((s[0][0] == s[1][1]) && (s[1][1] == s[2][2])){ //digonal match
        if ((s[1][1]) != '_'){
            count++;
        }
    }

    if ((s[2][0] == s[1][1]) && (s[1][1] == s[0][2])){
        if ((s[1][1]) != '_'){
            count++;
        }
    }

    ///////////////////////////////Counting no. of X,O and _
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){

            if (s[i][j] == 'X'){
                cx++;
            }
            else if (s[i][j] == 'O'){
                co++;
            }
            else{
                c_++;
            }
        }
    }

    if (count > 1){
        flag2 = 1;
    }

    if (c_ != 1){

        // cout << "x" << cx << "o" << co << "-" << c_ << endl;
        //cout << "count--" << count << endl;

        ////////////////////////////codition

        if (((c_ == 0) || (count == 1)) && ((cx == co) || (cx == ++co)) && (count <= 1)){
            return 1;
        }
        else if (((cx == co) || (cx == ++co)) && (count <= 1) && (c_ > 0)){
            return 2;
        }
        else{
            return 3;
        }
    }
    else{

        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (s[i][j] == '_'){
                    s[i][j] = 'X';
                    i++;
                }
            }
        }

        ////////////////////////////////
        int count = 0;

        int cx = 0, co = 0, c_ = 0;

        ///////////////////////////////

        for (int i = 0; i < 3; i++) {//vertical match
            if ((s[0][i] == s[1][i]) && (s[1][i] == s[2][i])){
                if ((s[0][i]) != '_'){
                    count++;
                }
            }
        }
        for (int i = 0; i < 3; i++) {//horizontal match
            if ((s[i][0] == s[i][1]) && (s[i][1] == s[i][2])){
                if ((s[i][0]) != '_'){
                    count++;
                }
            }
        }

        if ((s[0][0] == s[1][1]) && (s[1][1] == s[2][2])) { //digonal match
            if ((s[1][1]) != '_') {
                count++;
            }
        }

        if ((s[2][0] == s[1][1]) && (s[1][1] == s[0][2])) {
            if ((s[1][1]) != '_') {
                count++;
            }
        }

        ///////////////////////////////Counting no. of X,O and _
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (s[i][j] == 'X') {
                    cx++;
                }
                else if (s[i][j] == 'O') {
                    co++;
                }
                else {
                    c_++;
                }
            }
        }

        if (count > 1) {
            flag = 1;
        }

        ////////////////////////////codition
        if ((flag == flag2) && (flag == 1)) {
            return 1;
        }
        else if (flag == 1) {
            return 3;
        }

        else{
            if (((count == 1)) && ((cx == co) || (cx == ++co)) && (count <= 1)) {
                return 1;
            }
            else if (((cx == co) || (cx == ++co)) && (count <= 1)) {
                return 2;
            }
            else {
                return 3;
            }
        }
    }
    cout << "YOU FIND #BUG in BISWA CODE...REQUEST TO YOU PLEASE CONTACT BISWA AND TAKE HIM THIS INPUT DATA" << endl;

    return 3;
}
void space(int x) {
    for (int i = 0; i < x; i++) {
        cout << endl;
    }
}
int input(char x, int pos) {
    int a = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a == pos) {
                if (s[i][j] == '_') {
                    s[i][j] = x;
                    return 0;
                }
                else {
                    cout << "                 # WARNING ALREADY VALUE EXIST THERE" << endl;
                    //Beep(800, 1000);
                    cin.get();
                    return 1;
                }
            }
            a++;
        }
    }

    return 0;
}

void output()
{
    Beep(2500, 250);

    cout << "                                                                  SCORE BOARD" << endl;
    cout << "                                                                _-_-_-_-_-_-_-_" << endl;
    cout << "                                                                " << c1 << "-" << sc1 << endl;
    cout << "                                                                " << c2 << "-" << sc2 << endl;
    space(1);
    cout << "                                                                "
         << "---DRAW---"
         << "->" << dr << endl;

    for (int i = 0; i < 3; i++) {
        cout << "               ";
        for (int j = 0; j < 3; j++) {
            if (j != 0) {
                cout << "|";
            }
            cout << " " << s[i][j] << " ";
        }
        cout << endl;
        if (i != 2) {
            cout << "               ";
            cout << "------------" << endl;
        }
    }
    //space(10);
}

void initial() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            s[i][j] = '_';
        }
    }
}
int take_value() {
    char v;
    cin >> v;
    x = (int)v - 48;
    x = x % 9;
    /* if (x == 0)
    {
        cout << endl;
        return 3;
    } */
    cout << endl;

    ////////////////////////////////////////////////////////////////////////////
    ///  CASE STATEMENT FOR PROGRAM INPUT ACCORDING TO STANDARD KEYBOARD    ////
    //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
    switch (x)
    {
    case 0:
        return 3;
        break;

    case 1:
        return 7;
        break;

    case 2:
        return 8;
        break;

    case 3:
        return 9;
        break;

    case 4:
        return 4;
        break;

    case 5:
        return 5;
        break;

    case 6:
        return 6;
        break;

    case 7:
        return 1;
        break;

    case 8:
        return 2;
        break;
    }
    //case statement end here

    return 9; //due to error forcefully i return 9 other wise not requred.
}

void design()
{
    system("COLOR E");

    int x;
    int y;
    int z;
    int a;

    for (z = 0; z < 50; z++)
    {

        a = z % 10;

        for (x = 0; x < a; x++)
        {
            cout << "   ";
        }

        for (y = 0; y < 4; y++)
        {
            cout << "^   ";
        }

        cout << endl;
    }
}

void welcome()
{
    cout << "-------------------------------------------------" << endl;
    space(1);
    cout << "-------WELCOME TO TIK TAK TOE--------" << endl;

    cout << "                                    -by BISWA RANJAN" << endl;
    space(1);
    cout << "-------------------------------------------------" << endl;
    cout << "_________________________________________________" << endl;
    cout << "NOTE :-" << endl;

    cout << "      ONLY VALID INPUT IS ACCPTABLE(FROM 1 TO 9)" << endl;
    cout << "OTHER WISE ALGORITHIM TAKE ASCII CODE FOR INPUT" << endl;
    space(1);
    for (int i = 0; i < 3; i++)

    {
        static int cou = 7;
        for (int j = 0; j < 3; j++)
        {
            if (j != 0)
            {
                cout << "|";
            }

            cout << " " << cou << " ";
            cou++;
            if (cou == 10)
            {
                cou = 4;
            }
            if (cou == 7)
            {
                cou = 1;
            }
        }
        cout << endl;
        if (i != 2)
        {
            cout << "------------" << endl;
        }
    }
    space(1);
    cout << "These are respective valid no. with respect to position " << endl;
    space(1);
    cout << "      ACCORDING TO STANDARD KEYBOARD NUMBER PAD " << endl;
    space(3);
}
int ex()
{

    char v;
    cin >> v;
    int x;

    x = (int)v - 48;

    if (x == 1)
    {
        design();

        cout << "player are EXCHANGED now first move by " << p1 << endl;
        return 1;
    }
    else if (x == 0)
    {
        if (sc1 > sc2)
        {
            cout << "[[[[[[[[[[[[[[[[[[-- " << c1 << " WIN THE GAME WITH " << sc1 - sc2 << " POINT --"
                 << "]]]]]]]]]]]]]]]]" << endl;
        }
        else if (sc1 < sc2)
        {
            cout << "[[[[[[[[[[[[[[[[[[-- " << c2 << " WIN THE GAME WITH " << sc2 - sc1 << " POINT --"
                 << "]]]]]]]]]]]]]]]]" << endl;
        }
        else
        {
            cout << "[[[[[[[[[[[[[[[[[[[[[[[[[[[[[ NO ONE WIN ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]" << endl;
        }
        exit(0);
    }
    else
    {
        space(2);

        cout << "YOU ENTER LOT OF GARBEG, GAME SEEMS LIKE BOARING GAME RIGHT" << endl;
        space(1);
        cout << "LAST TIME I REQUEST-->Please press valid input AGAIN" << endl;
        Beep(1500, 3000);

        space(2);

        cin >> v;
        x = (int)v - 48;
        if (x == 1)
        {
            design();
            return 1;
        }

        else
        {
            space(1);
            if (sc1 > sc2)
            {
                cout << "[[[[[[[[[[[[[[[[[[-- " << c1 << " WIN THE GAME WITH " << sc1 - sc2 << " POINT --"
                     << "]]]]]]]]]]]]]]]]" << endl;
            }
            else if (sc1 < sc2)
            {
                cout << "[[[[[[[[[[[[[[[[[[-- " << c2 << " WIN THE GAME WITH " << sc2 - sc1 << " POINT --"
                     << "]]]]]]]]]]]]]]]]" << endl;
            }
            else
            {
                cout << "[[[[[[[[[[[[[[[[[[[[[[[[[[[[[ NO ONE WIN ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]" << endl;
            }
            space(1);
            exit(0);
        }
        space(1);
        if (sc1 > sc2)
        {
            cout << "[[[[[[[[[[[[[[[[[[-- " << c1 << " WIN THE GAME WITH " << sc1 - sc2 << " POINT --"
                 << "]]]]]]]]]]]]]]]]" << endl;
        }
        else if (sc1 < sc2)
        {
            cout << "[[[[[[[[[[[[[[[[[[-- " << c2 << " WIN THE GAME WITH " << sc2 - sc1 << " POINT --"
                 << "]]]]]]]]]]]]]]]]" << endl;
        }
        else
        {
            cout << "[[[[[[[[[[[[[[[[[[[[[[[[[[[[[ NO ONE WIN ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]" << endl;
        }
        space(1);

        exit(0);
    }
    space(1);
    if (sc1 > sc2)
    {
        cout << "[[[[[[[[[[[[[[[[[[-- " << c1 << " WIN THE GAME WITH " << sc1 - sc2 << " POINT --"
             << "]]]]]]]]]]]]]]]]" << endl;
    }
    else if (sc1 < sc2)
    {
        cout << "[[[[[[[[[[[[[[[[[[-- " << c2 << " WIN THE GAME WITH " << sc2 - sc1 << " POINT --"
             << "]]]]]]]]]]]]]]]]" << endl;
    }
    else
    {
        cout << "[[[[[[[[[[[[[[[[[[[[[[[[[[[[[ NO ONE WIN ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]" << endl;
    }
    space(1);
    exit(0);
}

int main()
{
    system("COLOR B");

    int mc = 0;

    int fd = 0;
    string temp;
    bool draw = 1;

    int z;
    int x;

    int y;

    int flag = 0;
    cout << "*************************************************" << endl;

    Beep(100, 500);
    Beep(200, 500);
    Beep(300, 500);

    welcome();

    Beep(400, 500);
    Beep(600, 1000);
    Beep(800, 500);
    Beep(1000, 500);
    Beep(1200, 500);
    Beep(1500, 1000);

    cout << "---> Enter player 1 name" << endl;
    cin >> p1;
    space(2);
    Beep(1200, 400);
    cout << "---> Enter player 2 name" << endl;
    cin >> p2;
    Beep(1200, 400);

    if (p1 == p2)
    {
        space(3);

        p1 = p1 + " 1";
        p2 = p2 + " 2";
        cout << "NOTICE --> Here two player have same name so I will deside to call you " << p1 << " and " << p2 << endl;
    }
    c1 = p1;
    c2 = p2;

    space(50);

    do
    {
        bl = 0;
        i = 0;

        initial();
        output();

        while ((status() != 1) && (fd == 0))
        {

            if (i % 2 == 0)
            {
                system("COLOR A");
            }
            else
            {
                system("COLOR C");
            }
            if (i % 2 == 0)
            {
                space(2);
                cout << "............." << p1 << "---> Please enter position of 'X'-->";
                x = take_value();

                y = 'X';

                flag = input(y, x);

                if (flag == 1)
                {

                    cout << "--------------------------------------------------------" << endl;

                    cout << ".....FOOLISH " << p1 << " PLEASE ENTER VALUE AGAIN....." << endl;
                    cout << "_______________________________________________________" << endl;
                    space(2);
                    i--;
                    // flag = 0;
                }
                if (status() == 1)
                {
                    if (i % 2 == 0)
                    {
                        cout << "###############__" << p1 << " WON THE GAME____################" << endl;
                        system("COLOR B");
                    }
                    else
                    {
                        cout << "###############__" << p2 << " WON THE GAME____################" << endl;
                        system("COLOR B");
                    }

                    //sc1++;
                    draw = 0;
                    Beep(1000, 2000);
                    Beep(1500, 2000); // 523 hertz (C5) for 500 milliseconds
                    cin.get();
                }
                if (status() == 3)
                {
                    cout << "###############__" << p2 << " WON THE GAME____################" << endl;
                    system("COLOR B");
                    //sc2++;
                    draw = 0;
                    Beep(1000, 2000);
                    Beep(1500, 2000); // 523 hertz (C5) for 500 milliseconds
                    cin.get();
                    fd++;
                }
                if (((status() != 1) || (status() != 3)) && (flag == 0))
                {
                    space(45);
                }
                flag = 0;

                if (draw != 0)
                {
                    output();
                }
                space(2);
                if (fd == 1)
                {
                    fd = 0;
                    break;
                }
            }
            else
            {
                space(2);
                cout << "............." << p2 << "--->  Please enter position of 'O'-->";
                x = take_value();

                y = 'O';

                flag = input(y, x);

                if (flag == 1)
                {
                    cout << "--------------------------------------------------------" << endl;

                    cout << ".....FOOLISH " << p2 << " PLEASE ENTER VALUE AGAIN....." << endl;
                    cout << "_____________________" << endl;
                    space(2);
                    i--;
                    // flag = 0;
                }
                if (status() == 1)
                {
                    if (i % 2 != 1)
                    {
                        cout << "###############__" << p2 << " WON THE GAME____################" << endl;
                        system("COLOR B");
                    }
                    else
                    {
                        cout << "###############__" << p1 << " WON THE GAME____################" << endl;
                        system("COLOR B");
                    }
                    //sc2++;
                    draw = 0;

                    Beep(1000, 2000);
                    Beep(1500, 2000); // 523 hertz (C5) for 500 milliseconds
                    cin.get();
                }
                if (status() == 3)
                {
                    cout << "###############__" << p1 << " WON THE GAME____################" << endl;
                    system("COLOR B");
                    //sc1++;
                    draw = 0;
                    Beep(1000, 2000);
                    Beep(1500, 2000); // 523 hertz (C5) for 500 milliseconds
                    cin.get();
                    fd++;
                }
                if (((status() != 1) && (status() != 3)) && (flag == 0))
                {
                    space(45);
                }

                if (draw != 0)
                {
                    output();
                }

                flag = 0;

                space(2);
                if (fd == 1)
                {
                    fd = 0;
                    break;
                }
            }

            i++;
        }

        if ((mc % 2 == 0) && (draw != 1))
        {
            sc1++;
            mc++;
            output();
        }
        else if ((mc % 2 == 1) && (draw != 1))
        {
            sc2++;
            mc++;
            output();
        }
        else
        {
            dr++;

            output();
        }

        fd = 0;

        if (draw == 1)
        {
            cout << "_______________________________________________________________________________" << endl;
            space(1);
            cout << "..................DRAW GAME......DRAW GAME.......DRAW GAME..................." << endl;
            Beep(200, 3500); // 200 hertz (C5) for 5000 milliseconds
            space(8);
        }

        draw = 1;

        space(3);

        cout << "WOULD YOU WANT TO PLAY IT AGAIN   -> if YES then press 1 other wise 0" << endl;

        temp = p1;
        p1 = p2;
        p2 = temp;

        bl = ex();
        space(3);
        //design();

    } while (bl);

    return 0;
}
#include <iostream>
#include "RankOneTensor.h"
#include "RankTwoTensor.h"

using namespace std;

void testIncrementOperatorRankOne();
void testIncrementOperatorRankTwo();
void testAddOperatorRankOne();
void testAddOperatorRankTwo();
void testAssignmentOperatorRankOne();
void testAssignmentOperatorRankTwo();
void testIndexOperatorRankOne();
void testIndexOperatorRankTwo();
void testCinStreamOperatorRankOne();
void testCinStreamOperatorRankTwo();
void testCoutStreamOperatorRankOne();
void testCoutStreamOperatorRankTwo();

int main() {
    testIncrementOperatorRankOne(); 
    testIncrementOperatorRankTwo();
    testAddOperatorRankOne(); 
    testAddOperatorRankTwo();
    testAssignmentOperatorRankOne();
    testAssignmentOperatorRankTwo();
    testIndexOperatorRankOne();
    testIndexOperatorRankTwo();
    testCinStreamOperatorRankOne();
    testCinStreamOperatorRankTwo();
    testCoutStreamOperatorRankOne();
    testCoutStreamOperatorRankTwo();
}

void testIncrementOperatorRankOne() {
    RankOneTensor t(3); 
    bool pass = true;
    string message;

    t++; // Post-increment
    for (int i = 0; i < 3; ++i) {
        if (t[i] != 1.0) {
            pass = false;
        }
    }

    message = (pass == true) ? "t++ passes" : "t++ fails";
    cout << message << endl;

    ++t; // Pre-increment
    pass = true;
    for (int i = 0; i < 3; ++i) {
        if (t[i] != 2.0) {
            pass = false;
        }
    }

    message = (pass == true) ? "++t passes" : "++t fails";
    cout << message << endl;
}

void testIncrementOperatorRankTwo() {
    RankTwoTensor t(3, 2); 
    bool pass = true;
    string message;

    t++; // Post-increment
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (t[i][j] != 1.0) {
                pass = false;
            }
        }
    }

    message = (pass == true) ? "t++ passes" : "t++ fails";
    cout << message << endl;

    ++t; // Pre-increment
    pass = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (t[i][j] != 2.0) {
                pass = false;
            }
        }
    }

    message = (pass == true) ? "++t passes" : "++t fails";
    cout << message << endl;
}

void testAddOperatorRankOne() {
    RankOneTensor t1(3), t2(3);
    t1.loadData();
    t2.loadData();
    RankOneTensor test(t1 + t2); // Adding two RankOneTensor objects
    bool pass = true;
    string message;

    for (int i = 0; i < 3; ++i) {
        if (test[i] != t1[i] + t2[i]) {
            pass = false;
        }
    }

    message = (pass == true) ? "+ operator works for two tensors" : "+ operator fails for two tensors";
    cout << message << endl;

    // Test for scalar addition
    RankOneTensor t(3);
    t = t + 0.5;
    pass = true;
    for (int i = 0; i < 3; ++i) {
        if (t[i] != 0.5) {
            pass = false;
        }
    }

    message = (pass == true) ? "+ operator works for scalar" : "+ operator fails for scalar";
    cout << message << endl;
}

void testAddOperatorRankTwo() {
    RankTwoTensor t1(3, 2), t2(3, 2);
    t1.loadData();
    t2.loadData();
    bool pass = true;
    string message;

    RankTwoTensor t3 = t1 + t2;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (t1[i][j] + t2[i][j] != t3[i][j]) {
                pass = false;
            }
        }
    }

    message = (pass == true) ? "+ operator works for two tensors" : "+ operator fails for two tensors";
    cout << message << endl;

    // Test for scalar addition
    RankTwoTensor t(3,2);
    t = t + 0.5;
    pass = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (t[i][j] != 0.5) {
                pass = false;
            }
        }
    }

    message = (pass == true) ? "+ operator works for scalar" : "+ operator fails for scalar";
    cout << message << endl;
}

void testAssignmentOperatorRankOne() {
    RankOneTensor t1(3), t2(3);
    t1.loadData();
    t2.loadData();

    RankOneTensor t3 = t1 + t2; // Assignment
    bool pass = true;
    string message;

    for (int i = 0; i < 3; ++i) {
        if (t3[i] != t1[i] + t2[i]) {
            pass = false;
        }
    }

    message = (pass == true) ? "= operator works" : "= operator fails";
    cout << message << endl;
}

void testAssignmentOperatorRankTwo() {
    RankTwoTensor t1(3, 2), t2(3, 2);
    t1.loadData();
    t2.loadData();

    RankTwoTensor t3 = t1 + t2; // Assignment
    bool pass = true;
    string message;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (t3[i][j] != t1[i][j] + t2[i][j]) {
                pass = false;
            }
        }
    }

    message = (pass == true) ? "= operator works" : "= operator fails";
    cout << message << endl;
}


void testCinStreamOperatorRankOne(){
    RankOneTensor t(3);
    cin >> t;
}
void testCinStreamOperatorRankTwo(){
    RankTwoTensor t(3, 2);
    cin >> t;
}

void testCoutStreamOperatorRankOne(){
    RankOneTensor t(3);
    t.loadData();
    cout << t << endl;
}
void testCoutStreamOperatorRankTwo(){
    RankTwoTensor t(3, 2);
    t.loadData();
    cout << t << endl;
}

void testIndexOperatorRankOne() {
    RankOneTensor t(2);
    cin >> t; 
    cout << "The first value is " << t[0] << endl; 
}

void testIndexOperatorRankTwo() {
    RankTwoTensor t(2, 2);
    cin >> t;
    cout << "The value in row 0 and column 1 is " << t[0][1] << endl; 
}


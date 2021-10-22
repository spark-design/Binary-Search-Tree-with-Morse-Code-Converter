#pragma once

class Node
{
    public:
        char morseChar;
        int bstVal;
        Node *left;
        Node *right;

        // Node(): 
            // bstVal(0), left(nullptr), right(nullptr) {}

        // Node(int val):
            // bstVal(val), left(nullptr), right(nullptr) {}

        Node(): 
            morseChar(' '), bstVal(0), left(nullptr), right(nullptr) {}

        Node(char mChar, int val):
            morseChar(mChar), bstVal(val), left(nullptr), right(nullptr) {}

        int degree();
};
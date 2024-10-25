// CIS-566-HW2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <string>
#include <fstream>
using namespace std;



// GUI Components
class Panel
{
public:
    virtual void test() {}
};


class Button
{
public:
    virtual void test() {}
};


class Textbox
{
public:
    virtual void test() {}
};

class Word90Panel : public Panel
{
public:
    void test() override
    {
        cout << "Panel Word90\n";
    }
};


// Version Specific GUI Components
class Word00Panel : public Panel
{
public:
    void test() override
    {
        cout << "Panel Word00\n";
    }
};


class Word10Panel : public Panel
{
public:
    void test() override
    {
        cout << "Panel Word10\n";
    }
};


class Word21Panel : public Panel
{
public:
    void test() override
    {
        cout << "Panel Word21\n";
    }
};





class Word90Button : public Button
{
public:
    void test() override
    {
        cout << "Button Word90\n";
    }
};


class Word00Button : public Button
{
public:
    void test() override
    {
        cout << "Button Word00\n";
    }
};


class Word10Button : public Button
{
public:
    void test() override
    {
        cout << "Button Word10\n";
    }
};


class Word21Button : public Button
{
public:
    void test() override
    {
        cout << "Button Word21\n";
    }
};






class Word90Textbox : public Textbox
{
public:
    void test() override
    {
        cout << "Textbox Word90\n";
    }
};


class Word00Textbox : public Textbox
{
public:
    void test() override
    {
        cout << "Textbox Word00\n";
    }
};


class Word10Textbox : public Textbox
{
public:
    void test() override
    {
        cout << "Textbox Word10\n";
    }
};


class Word21Textbox : public Textbox
{
public:
    void test() override
    {
        cout << "Textbox Word21\n";
    }
};





// Factories
class WordFactory
{
public:
    virtual Panel* getPanel() { return new Panel(); }

    virtual Button* getButton() { return new Button(); }

    virtual Textbox* getTextbox() { return new Textbox(); }
};



class Word90Factory : public WordFactory
{
public:
    static int instanceCount;

    Panel* getPanel() override
    {
        return new Word90Panel();
    }

    Button* getButton() override
    {
        return new Word90Button();
    }

    Textbox* getTextbox() override
    {
        return new Word90Textbox();
    }
};


class Word00Factory : public WordFactory
{
public:
    static int instanceCount;

    Panel* getPanel() override
    {
        return new Word00Panel();
    }

    Button* getButton() override
    {
        return new Word00Button();
    }

    Textbox* getTextbox() override
    {
        return new Word00Textbox();
    }
};



class Word10Factory : public WordFactory
{
public:
    static int instanceCount;

    Panel* getPanel() override
    {
        return new Word10Panel();
    }

    Button* getButton() override
    {
        return new Word10Button();
    }

    Textbox* getTextbox() override
    {
        return new Word10Textbox();
    }
};


class Word21Factory : public WordFactory
{
public:
    static int instanceCount;

    Panel* getPanel() override
    {
        return new Word21Panel();
    }

    Button* getButton() override
    {
        return new Word21Button();
    }

    Textbox* getTextbox() override
    {
        return new Word21Textbox();
    }
};






int main()
{
    // Read the config file
    ifstream file("config_file.txt");
    string str;

    // Go through each line of the config file
    while (getline(file, str))
    {
        if (str == "") // If we don't have text, continue
        {
            continue;
        }

        cout << str << endl;
    }

    WordFactory* wordFactory;

    wordFactory = new Word10Factory();

    Panel* panel = wordFactory->getPanel();
    Button* button = wordFactory->getButton();
    Textbox* textbox = wordFactory->getTextbox();

    panel->test();
    button->test();
    textbox->test();
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

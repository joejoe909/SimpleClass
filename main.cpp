#include <iostream>
#include <string>
#include <vector>

using namespace std;

class idea {
public:

    idea(string ttl, string thgt)
    {
        this->title = ttl;
        this->thought = thgt;
    }

    void dpIda()
    {
        cout << title << endl;
        cout << thought << endl;
    }

    void setTitle(string *ttle)
    {
        title = *ttle;
    }

    void setThought(string *tht)
    {
        thought = *tht;
    }

    void outTht(){
        cout << title << endl;
        cout << thought << endl;
    }

private:
    string title;
    string thought;

};

int main()
{
    string ttl = "title";
    string tht = "Thoughts";
    idea testTh1(ttl, tht);
    idea testTh2("test2 title", "test2 idea");    //Inline
    idea *testTh3 = new idea("test3 title", "test3 idea");

    testTh1.outTht();
    testTh2.outTht();
    testTh3->outTht();

    cout << endl << endl;

    vector<idea*> mindmap;
    mindmap.push_back(testTh3); //passing a pointer.
    mindmap.push_back(&testTh1); //passing by reference.
    mindmap.push_back(&testTh2);
    mindmap.push_back(new idea("test mind map title id:1", "test mind map thought."));
    mindmap.at(0)->outTht();
    mindmap.at(1)->outTht();

    cout << endl << endl;

    vector<idea> mindmap2;
    mindmap2.push_back(testTh1);
    mindmap2.push_back(testTh2);
    mindmap2.push_back(*testTh3);
    mindmap2.at(0).outTht();
    mindmap2.at(1).outTht();

    return 0;
}

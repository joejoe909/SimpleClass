# Simple Class C++ 
#### A quick example to help me keep my c++ wheels turning.
#### This is a good refrence for vectors, strings, classes, and constructors.
#### Feel free to use this as you like. 

#### The main component of interest is all in the main.cpp file.

The Class

```cpp
class idea {
public:

    idea(string ttl, string thgt)   //Constructor
    {
        this->title = ttl;
        this->thought = thgt;
    }

    void setTitle(string *ttle)     //Function in a class.
    {
        title = *ttle;
    }

    void setThought(string *tht)    // '''
    {
        thought = *tht;
    }

    void outTht(){                  //Use a function in the class to output information.
        cout << title << endl;
        cout << thought << endl;
    }

private:                            //We can keep these variable private, this practice is good for security.
    string title;                   //we can expose them with a function.
    string thought;

};
```

In the main function we use the idea class.
the main() function:

```cpp
int main()
{
    string ttl = "ttl title";
    string tht = "ttl thought";
    idea testTh1(ttl, tht); //initialize an idea by passing a string by value.
    idea testTh2("test2 title", "test2 thought");    //Inline initialization.
    idea *testTh3 = new idea("test3 title", "test3 idea"); //Inline initialization of a pointer and a new idea for pointer exploitation.

    testTh1.outTht();   //here we call our variables output function.
    testTh2.outTht();
    testTh3->outTht(); //same but using a pointer.

    cout << endl << endl;

    vector<idea*> mindmap;      //This is the more dynamic C++ way to work. I dont recomend vector<idea> *mindmap;
    mindmap.push_back(testTh3); //passing a pointer.
    mindmap.push_back(&testTh1); //passing by reference.
    mindmap.push_back(&testTh2);
    mindmap.push_back(new idea("test mind map title id:1", "test mind map thought.")); //initializeing and pushing back at the same time.
    mindmap.at(0)->outTht();    //output idea elements in the mindmap vector.
    mindmap.at(1)->outTht();

    cout << endl << endl;

    //You can do this but it's not as good as useing vector<idea*> mindmap;
    vector<idea> mindmap2;  // you can use a idea *pntida in push_back with the new operator...
    mindmap2.push_back(testTh1); //passing by value.
    mindmap2.push_back(testTh2);
    mindmap2.push_back(*testTh3); //passing by refrence.
    mindmap2.at(0).outTht();    //output idea elements in the mindmap2 vector.
    mindmap2.at(1).outTht();

    return 0;
}
```

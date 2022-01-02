#include<iostream>
#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
#define INF 0x7fffffffffffffff

using namespace std;

//Problem 5
//Node Class:
class Node
{
public:
	int key;

	// Array to hold pointers to node of different level
	Node **forward;
	Node(int, int);
	void DisplayNode();
};

//Implementing Node Functions:
Node::Node(int key, int level)
{
	this->key = key;

	// Allocate memory to forward
	forward = new Node*[level+1];

	// Fill forward array with 0(NULL)
	memset(forward, 0, sizeof(Node*)*(level+1));
};

void Node::DisplayNode()
{
    cout<<"key is " << key << endl;
}

//SkipList Class:
class SkipList
{
    // Maximum level for this skip list
    int MaxLevel;

    // P is the fraction of the nodes with level
    // i pointers also having level i+1 pointers
    float P;

    // current level of skip list
    int level;

    // pointer to header node
    Node *header;
public:
    SkipList(int, float);
    int randomLevel();
    Node* createNode(int, int);
    void insertElement(int);
    void deleteElement(int);
    void searchElement(int);
    void displaySkipList();
    void printLayer(int);
    void getLevels();
};

//Implementing Skip List Functions:
SkipList::SkipList(int MaxLevel, float P)
{
    this->MaxLevel = MaxLevel;
    this->P = P;
    level = 0;

    // create header node and initialize key to -1
    header = new Node(-1, MaxLevel);
};

// create random level for node
int SkipList::randomLevel()
{
    float r = (float)rand()/RAND_MAX;
    int lvl = 0;
    while(r < P && lvl < MaxLevel)
    {
        lvl++;
        r = (float)rand()/RAND_MAX;
    }
    return lvl;
};

// create new node
Node* SkipList::createNode(int key, int level)
{
    Node *n = new Node(key, level);
    return n;
};

// Insert given key in skip list
void SkipList::insertElement(int key)
{
    Node *current = header;

    // create update array and initialize it
    Node *update[MaxLevel+1];
    memset(update, 0, sizeof(Node*)*(MaxLevel+1));

    for(int i = level; i >= 0; i--)
    {
        while(current->forward[i] != NULL && current->forward[i]->key < key)
            current = current->forward[i];
        update[i] = current;
    }

    current = current->forward[0];

    if (current == NULL || current->key != key)
    {
        // Generate a random level for node
        int rlevel = randomLevel();

        if(rlevel > level)
        {
            for(int i=level+1;i<rlevel+1;i++)
                update[i] = header;

            // Update the list current level
            level = rlevel;
        }

        // create new node with random level generated
        Node* n = createNode(key, rlevel);

        // insert node by rearranging pointers
        for(int i=0;i<=rlevel;i++)
        {
            n->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = n;
        }
        cout<<"Successfully Inserted key "<<key<<"\n";
    }
};

// Search for element in skip list
void SkipList::searchElement(int key)
{
    Node *current = header;
    int i = level;
    int s = 0;
    for(i; i >= 0; i--)
    {
        while(current->forward[i] && current->forward[i]->key < key)
        {
            current = current->forward[i];
            s++;
        }
        s++;
    }

    current = current->forward[0];

    if(current and current->key == key)
    {
        cout<<"Found key: "<< key << " in " << s-1 << " steps" <<endl;
    }
    else
    {
        cout<<"Key not found"<<endl;
    }
};

// Display skip list by levels
void SkipList::displaySkipList()
{
    cout<<"\n*****Skip List*****"<<"\n";
    for(int i=0;i<=level;i++)
    {
        Node *node = header->forward[i];
        cout<<"Level "<<i<<": ";
        while(node != NULL)
        {
            cout<<node->key<<" ";
            node = node->forward[i];
        }
        cout<<endl;
    }
};

void SkipList::printLayer(int n)
{
    Node *node = header->forward[n];
    cout<<"Level "<<n<<": ";
    while(node != NULL)
    {
        cout<<node->key<<" ";
        node = node->forward[n];
    }
    cout<<endl;
};

void SkipList::getLevels()
{
    cout<<"Number of current levels is: " << level << endl;
}


int main()
{
        // Seed random number generator
	    srand((unsigned)time(0));

	    // create SkipList object with MAXLVL and P
	    SkipList SkpLst1(10, 0.5);

	    SkpLst1.insertElement(1);
	    SkpLst1.insertElement(7);
	    SkpLst1.insertElement(9);
	    SkpLst1.insertElement(2);
	    SkpLst1.insertElement(4);
	    SkpLst1.insertElement(5);
	    SkpLst1.insertElement(17);
	    SkpLst1.insertElement(11);
	    SkpLst1.insertElement(14);
	    SkpLst1.insertElement(19);

	    SkpLst1.displaySkipList();
	    SkpLst1.getLevels();

	    cout<<"---------------------------"<<endl;
        cout<<"searching"<<endl;
	    SkpLst1.searchElement(17);

        cout<<"---------------------------"<<endl;
        cout<<"printing one level"<<endl;
        SkpLst1.printLayer(2);
        //End of problem 5 Test
}

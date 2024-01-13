#include <iostream>
using namespace std;


struct dataNode
{
   int     data;
   dataNode  *left;
   dataNode  *right;
}; 


class BinaryTree {

private:
dataNode *root;


public:
BinaryTree(){
    root = NULL ;
} // constructor


void Insert(int newNodeData){
    dataNode *current;  
    dataNode *parentNode; 
    dataNode *newNode; 

    newNode = new dataNode;
    newNode->data = newNodeData;
    newNode->left = NULL;
    newNode->right = NULL;

    if(root == NULL)
       root = newNode;
    else
    {
       current = root;
 
       while(current != NULL)
       {
           parentNode = current;

           if(current->data == newNodeData)
           {
              cout<<"The insert newNodeData is already in the list - duplicates are not allowed."<<endl;
              return;
           }
           else
              if(current->data > newNodeData)
                 current = current->left;
              else
                 current = current->right;
       }//end while

       if(parentNode->data > newNodeData)
          parentNode->left = newNode;
       else
          parentNode->right = newNode;
   }
} // insertNewNode


dataNode* GetParent(int value) {
    dataNode* current = root;
    dataNode* parentNode = nullptr;

    while (current != nullptr && current->data != value) {
        parentNode = current;
        if (value < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (current == nullptr || current->data != value) {
        cout << "Node with value " << value << " not found in the tree." << endl;
        return nullptr;
    }

    if (parentNode != nullptr) {
        return parentNode;
    } else {
        cout << "Node with value " << value << " is the root, it has no parent." << endl;
        return nullptr;
    }
}






void DeleteNodeByPointer (dataNode* &p){
     dataNode *current;
     dataNode *parentNode;
     dataNode *temp;

	 if(p->left == NULL && p->right == NULL)
     {
		delete p;
		p = NULL;
     }
     else if(p->left == NULL)
     {
		temp = p;
        p = p->right;
        delete temp;
     }
     else if(p->right == NULL)
     {
		temp = p;
        p = p->left;
        delete temp;
     }
     else
     {
        current = p->left;
        parentNode = NULL;

        while(current->right != NULL)
        {
            parentNode = current;
            current = current->right;
        }//end while

        p->data = current->data;

        if(parentNode == NULL) 
           p->left = current->left;
        else
           parentNode->right = current->left;
        delete current;
     }//end else
}//end DeleteNodeByPointer



void Delete(int item){
	dataNode *current;  //pointer to traverse the tree
	dataNode *parentNode; //pointer behind current

	if(root == NULL){
		cout<<"Cannot delete from the empty tree."<<endl;
		return;
	}
	if(root->data == item){
		DeleteNodeByPointer(root);
		return;
	}

	parentNode = root;

	if(root->data > item)
		current = root->left;
	else
		current = root->right;
	
	//search for the item to be deleted.
	while(current != NULL)
	{
		if(current->data == item)
			break;
		else
		{
			parentNode = current;
			if(current->data > item)
				current = current->left;
			else
				current = current->right;
		}
	}

    // Now we delete the dataNode if present
	if(current == NULL)
		cout<<"The delete item is not in the tree."<<endl;	
	else if(parentNode->data > item)
		DeleteNodeByPointer(parentNode->left);
	else
		DeleteNodeByPointer(parentNode->right);
} // endDelete



void InOrderFromNode(dataNode *p){
	if(p != NULL)
	{
		InOrderFromNode(p->left);
		cout<<p->data<<" ";
		InOrderFromNode(p->right);
	}
} // inOrderMethod


void InOrder() {
        InOrderFromNode(root);  // Start from the root
        cout << endl;
}


int Count(dataNode *p){
	if(p == NULL)
		return 0;
	else
		return 1 + Count(p->left) + Count(p->right);
} // nodeCountMethod





}; // end BinaryTree Class


int main(){

BinaryTree t;
    t.Insert(50);
    t.Insert(60);
    t.Insert(30);
    t.Insert(25);
    t.Insert(40);
    t.Insert(35);
    t.Insert(70);
    t.Insert(65);
    ////////////////////////////////////////////////////////////////
    t.Insert(11);
    t.Insert(27);
    t.Insert(26);
    t.Insert(29);
    t.Insert(45);
    t.InOrder();
    cout << "****************" << endl;
    dataNode *dataNode = t.GetParent(65);

    cout << "Parent of 65=" << dataNode->data << endl;
    cout << "****************" << endl;
    t.Delete(30);
    t.InOrder();
    cout << "****************" << endl;
    //cout << t.Count(t.root) << endl;
    system("pause");
    return 0;



}
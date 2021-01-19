#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

//#include <list>

using namespace std;	
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data=d;
            left=right=NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data){
            if(root==NULL){
                return new Node(data);
            }
            else{
                Node* cur;
                if(data<=root->data){
                    cur=insert(root->left,data);
                    root->left=cur;
                }
                else{
                   cur=insert(root->right,data);
                   root->right=cur;
                 }           
           return root;
           }
        }
//#include <list>     
   void op(Node *node,vector<int> &nlist)
   
   {
	 //  cout<<__LINE__<<endl;
       if(node)
       {
	   //cout<<"Vec size before "<<nlist.size()<<endl;    
           //cout<<node->data<<" ";
           if (node->left)
            {
                nlist.push_back((node->left)->data);
		//cout<<"Lvalue :"<<node->left->data<<endl;
            }
            
            if(node->right)
            {
                nlist.push_back((node->right)->data);
		//cout<<"RValue :"<<node->right->data<<endl;
            }
	   // cout<<__LINE__<<endl;
	   //cout<<"Vec size after "<<nlist.size()<<endl; 
       }
   }
	void levelOrder(Node * root){
        Node *node = NULL;
        vector<int> nList = std::vector<int> ();
        vector<Node*> nodeList = vector<Node*> ();
        vector<Node*>::iterator it = nodeList.begin();
        if(root)
        {
            nodeList.push_back(root);
            //node = it
            nList.push_back(root->data);
	    it = nodeList.begin();
	   // cout<<__LINE__<<endl;
            //while(it != nodeList.end())
	    for( int z=0 ; z< nodeList.size();++z)
            {
		//    cout<<__LINE__<<endl;
                //node = *it;
		node = nodeList.at(z);
		op(node,nList);
                if(node->left)
                {
                   // nList->push_back(node->left->data);		
		    //op(node->left,nList);
		    
                    nodeList.push_back(node->left);
                }
                  
                if(node->right)
                {
		    //nList->push_back(node->right->data);
                    //op(node->right,nList);

                    nodeList.push_back(node->right);
                }
                //  cout<<__LINE__<<endl;
               // node =  nodeList.next();   
             // ++it;  
            }
            
           for (int j =0 ; j< nList.size(); ++j)
	   {
              cout<<nList.at(j)<<" ";
	   } 
        }
      //Write your code here
  	
  
	}

};//End of Solution
int main(){
    Solution myTree;
    Node* root=NULL;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        root= myTree.insert(root,data);
    }
    myTree.levelOrder(root);
    return 0;
}

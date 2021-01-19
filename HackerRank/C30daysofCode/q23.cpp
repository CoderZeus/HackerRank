#include <iostream>
#include <cstddef>

using namespace std;	

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            }
            else {
                Node* cur;
                if(data <= root->data){
                    cur = insert(root->left, data);
                    root->left = cur;
                }
                else{
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
        int getH(Node *node,int depth)
        {
            Node *n1= NULL;
            if( node != NULL)
            {
                int ld1=depth;
                int rd1 =depth;
                if(node->left)
                {
                    n1 = node->left;
                    int ndepth = depth +1;
                    
                   ld1= getH(n1,ndepth);
                }
                 if(node->right)
                {
                    n1 = node->right;
                    int ndepth = depth +1;
                    
                    rd1 = getH(n1,ndepth);
                }
                
                if( rd1 > ld1)
                  return rd1;
                
                return ld1;  
                
            }
            return depth;
        }
		int getHeight(Node* root){
          //Write your code here
          int height = 0;
           height = getH(root,0);
         
         //cout<<height;
         return height;
        }

}; //End of Solution

int main() {
    Solution myTree;
    Node* root = NULL;
    int t;
    int data;

    cin >> t;

    while(t-- > 0){
        cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.getHeight(root);
    cout << height;

    return 0;
}
    
       
            
        

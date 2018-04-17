/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
#include <vector>

   bool checkBST(Node* root) {
      vector<int> s;
       inOrder(s,root);
       int treesize=s.size();
       int i=0;
       while (i< treesize-1){
           if (s[i] >= s[i+1])
               return false;
            i++;
       }
       return true;
       
   }

    void inOrder(vector<int> &s,Node *root)
    {
        if (root!=NULL){
            if (root->left!=NULL)
                inOrder(s,root->left);
            s.push_back(root->data);
            if (root->right!=NULL)
                inOrder(s,root->right);
        }
        
            
    }
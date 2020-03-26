int sumOfLeafNodes(Node *root ){
    if(!root)
        return 0;
    
    else{
        if(root->left == NULL && root->right == NULL)
            return root->data;
        
        else
            return sumOfLeafNodes(root->left) + sumOfLeafNodes(root->right);
    }
}

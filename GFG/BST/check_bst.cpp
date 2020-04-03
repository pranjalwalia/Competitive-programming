bool _bst(Node* root , int minval , int maxval){
    if(!root)
        return true;
    if( root->data < maxval && root->data > minval && _bst(root->left ,minval , root->data) && _bst(root->right , root->data , maxval) ){
        return true;
        
    }
    else return false;
}

bool isBST(Node* root) {
    return _bst(root , INT_MIN , INT_MAX);
}

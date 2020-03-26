bool search(Node* root, int x)
{
    if(!root)
        return false;
    
    if(root->data == x)
        return true;
    
    if(root->data > x)
        return search(root->left , x);
    
    if(root->data < x)
        return search(root->right , x);
        
}

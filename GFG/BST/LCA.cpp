Node* LCA(Node *root, int n1, int n2)
{
    if(!root)  
        return NULL;

    if(root->data > n1 && root->data > n2)
        return LCA(root->left , n1 ,n2 );

    if(root->data < n1 && root->data < n2)
        return LCA(root->right , n1 , n2);

    return root;

}
/*
iF WE LOOK AT THE TREE, IF N1 AND N2 LIE ON OPPOSITE SIDES I.E DIFFERENT SUBTREES, THEN
NODE ACROSS WHICH THEY LIE ON DIFF SIDES IS THE REQUIRED ANCESTOR
    
    If node lies in range [n1,n2] then that is the required node.
*/    




//iterative 

Node* LCA(Node* root , int n1 , int n2){
    if(!root)
        return NULL;

    while(root){
        if(root->data < n1 && root->data < n2)
            root = root->left;
        else if(root->data > n1 && root->data > n2)
            root = root->right;

        else break;
    }
    return root;
}
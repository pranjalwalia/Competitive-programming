void Inorder(Node* root, vector<Node*>& v){
  if(root){
    Inorder(root->left, v);
    v.push_back(root);
    Inorder(root->right, v);
  }
}

Node* makebal(vector<Node*>& nodes, int start, int end){
  if(start > end)
    return NULL;
  int mid = (start+end)/2;
  Node *temp = nodes[mid];
  temp->left = makebal(nodes, start, mid-1);
  temp->right = makebal(nodes, mid+1, end);
  return temp;
}

Node* buildBalancedTree(Node* root)
{
  vector<Node*> v;
  Inorder(root, v);
  return makebal(potato, 0, potato.size()-1);
}

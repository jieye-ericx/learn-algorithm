class Solution {
  public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector < int > vin) {
  int mid = 0, len = vin.size();
  if (len == 0) return NULL;
  vector < int > preL, preR, vinL, vinR;

  TreeNode * root=new TreeNode(pre[0]);

  for (int i = 0; i < len; i++) {
    if (vin[i] == pre[0]) {
      mid = i;
      break;
    }
  }

  for (int i = 0; i < mid; i++) {
    preL.push_back(pre[i + 1]);
    vinL.push_back(vin[i]);
  }
  for (int i = mid + 1; i < len; i++) {
    preR.push_back(pre[i]);
    vinR.push_back(vin[i]);
  }
  root -> left=reConstructBinaryTree(preL, vinL);
  root -> right=reConstructBinaryTree(preR, vinR);
  return root;
}
};
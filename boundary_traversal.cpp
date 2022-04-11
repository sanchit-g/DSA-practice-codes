bool isLeaf(TreeNode<int>* node) {
	return node->left == NULL and node->right == NULL;
}

void addLeftBoundary(TreeNode<int>* root, vector<int>& res) {
	TreeNode<int>* curr = root -> left;

	while (curr) {
		if (!isLeaf(curr))
			res.push_back(curr -> data);
		if (curr -> left)
			curr = curr -> left;
		else
			curr = curr -> right;
	}
}

void addLeaves(TreeNode<int>* root, vector<int>& res) {
	if (isLeaf(root)) {
		res.push_back(root -> data);
		return;
	}

	if (root -> left)
		addLeaves(root -> left, res);
	if (root -> right)
		addLeaves(root -> right, res);
}

void addRightBoundary(TreeNode<int>* root, vector<int>& res) {
	TreeNode<int>* curr = root -> right;
	vector<int> temp;

	while (curr) {
		if (!isLeaf(curr))
			temp.push_back(curr -> data);
		if (curr -> right)
			curr = curr -> right;
		else
			curr = curr -> left;
	}

	for (int i = temp.size() - 1; i >= 0; i--)
		res.push_back(temp[i]);
}

vector<int> traverseBoundary(TreeNode<int>* root) {

	vector<int> res;

	if (!root)
		return res;

	if (!isLeaf(root))
		res.push_back(root -> data);

	addLeftBoundary(root, res);
	addLeaves(root, res);
	addRightBoundary(root, res);

	return res;
}
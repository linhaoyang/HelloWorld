unfinished

class Codec {
public:

	queue<TreeNode*> qt;
	

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {

		string s;

		qt.push(root);

		while (!qt.empty()) {
		
			TreeNode* a = qt.front();
			qt.pop();

			if (a == NULL) {
				s += "#";
				continue;
			}

			s += to_string(a->val);

			//if (a->left) {
				qt.push(a->left);
			//}
			//if (a->right) {
				qt.push(a->right);
			//}

		}

		cout << "Serialzie node:"<<s << endl;

		return s;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {

		TreeNode* t [1000];

		t[0] = new TreeNode(t data[0])

		for (int i = 0; i < data.length(); i++){
			if (data[i] != '#') {
			
			}
		}

		return NULL;
	}
};


--------------------
OTHERS

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return mydeserialize(data);
    }
    TreeNode* mydeserialize(string& data) {
        if (data[0]=='#') {
            if(data.size() > 1) data = data.substr(2);
            return nullptr;
        } else {
            TreeNode* node = new TreeNode(helper(data));
            node->left = mydeserialize(data);
            node->right = mydeserialize(data);
            return node;
        }
    }
private:
    int helper(string& data) {
        int pos = data.find(',');
        int val = stoi(data.substr(0,pos));
        data = data.substr(pos+1);
        return val;
    }
};`

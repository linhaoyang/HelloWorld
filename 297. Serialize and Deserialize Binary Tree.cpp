注意Queue与List的配合遍历 
BFS与Queue的关系紧密
----------------------------------------------------
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
};

-------------------------------------------------------------------
BFS!!!
	
    public String serialize(TreeNode root) { //O(n);O(w)
        if (root == null) {
            return "";
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        StringBuilder res = new StringBuilder();
        while (!queue.isEmpty()) {
            TreeNode head = queue.poll();
            if (head == null) {
                res.append("#,");
                continue;
            }
            res.append(head.val + ",");
            queue.offer(head.left);
            queue.offer(head.right);
        }
        return res.toString();
    }

    public TreeNode deserialize(String data) { //O(n);O(n)
        if (data == "") {
            return null;
        }

        String[] values = data.split(",");
        TreeNode root = new TreeNode(Integer.parseInt(values[0]));
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        for (int i = 1; i < values.length; i++) {
            TreeNode parent = queue.poll();
            if (!values[i].equals("#")) {
                TreeNode left = new TreeNode(Integer.parseInt(values[i]));
                parent.left = left;
                queue.offer(left);
            }
            if (!values[++i].equals("#")) {
                TreeNode right = new TreeNode(Integer.parseInt(values[i]));
                parent.right = right;
                queue.offer(right);
            }
        }
        return root;
    }

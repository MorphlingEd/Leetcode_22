#include<iostream>
#include<list>
#include<string>
#include<sstream>
#include "Binary_Tree.h"
using namespace std;

class Codec {
public:
    string SEP = ",";
    string NUL = "#";

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";

        string res;
        list<string> nodes;
        preSerialize(nodes, root);

        while(!nodes.empty()){
            res.append(nodes.front());
            nodes.pop_front();
        }

        return res;
    }

    void preSerialize(list<string>& nodes, TreeNode* node){
        if (!node){
            nodes.push_back(NUL);
            nodes.push_back(SEP);
            return;
        }

        nodes.push_back(to_string(node->val));
        nodes.push_back(SEP);

        preSerialize(nodes, node->left);
        preSerialize(nodes, node->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        list<string> nodes;

        size_t pos;
        string val;
        while ((pos = data.find(SEP)) != string::npos){
            val = data.substr(0, pos);
            nodes.push_back(val);
            data.erase(0, pos + SEP.length());
        }
        nodes.push_back(data);


        return deserialize(nodes);
    }

    TreeNode* deserialize(list<string>& nodes){
        if (nodes.empty())
            return nullptr;

        string s = nodes.front();
        nodes.pop_front();
        if (s == NUL)
            return nullptr;

        TreeNode* node = new TreeNode(stoi(s));
        node->left = deserialize(nodes);
        node->right = deserialize(nodes);
        return node;
    }
};

class CodeII {
public:
    string SEP = ",";
    string NUL = "#";

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return NUL;
        return to_string(root->val) + SEP
                + serialize(root->left) + SEP
                + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == NUL) return nullptr;

        stringstream s(data);

        return deserialize(s);
    }

    TreeNode* deserialize(stringstream& s){
        string str;
        getline(s, str, ',');

        if (str == NUL)
            return nullptr;

        TreeNode* node = new TreeNode(stoi(str));
        node->left  = deserialize(s);
        node->right = deserialize(s);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
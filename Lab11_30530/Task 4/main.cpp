// You are required to implement a binary search tree (BST) to simulate a basic file management system.
// Each node in the BST must represent a file, storing its name, size (in megabytes), and type (e.g., "txt", "pdf", "exe").
// The BST should be ordered based on file names using lexicographic comparison.
// You must support standard BST operations including insertion, deletion, and traversal.
// The tree must also allow searching for files whose size exceeds a given threshold.
// You are expected to handle the following error conditions: inserting a duplicate file name, deleting a non-existent file, or
// performing operations on an empty tree.
// Destructors must be used to manage dynamic memory properly.
// 1) Each file node must contain:
// ● string fileName
// ● int fileSize
// ● string fileType
// ● overloaded << operator for printing

// 2) Functionality to implement:
// ● Insert a new file node
// ● Delete a file by name
// ● Rename a file
// ● Search for a file by name
// ● Retrieve all files with size > given threshold
// ● Inorder, preorder, and postorder traversals

// 3) Constraints:
// ● Must handle the following cases:
// ▪ Duplicate insertions
// ▪ Invalid deletions
// ▪ Operations on an empty tree

#include <iostream>
#include <string>

using namespace std;

struct FileNode
{
    string fileName;
    int fileSize;
    string fileType;
    FileNode *left;
    FileNode *right;

    // Constructor to initialize a file node
    FileNode(string name, int size, string type) : fileName(name), fileSize(size), fileType(type), left(nullptr), right(nullptr) {}

    // Overloaded << operator for printing the file node
    friend ostream &operator<<(ostream &os, const FileNode &node)
    {
        os << "File Name: " << node.fileName << ", Size: " << node.fileSize << "MB, Type: " << node.fileType;
        return os;
    }
};

class FileBST
{
public:
    FileNode *root;

    // Helper function to insert a file node into the BST
    FileNode *insert(FileNode *node, string fileName, int fileSize, string fileType)
    {
        if (node == nullptr)
            return new FileNode(fileName, fileSize, fileType);

        if (fileName < node->fileName)
            node->left = insert(node->left, fileName, fileSize, fileType);
        else if (fileName > node->fileName)
            node->right = insert(node->right, fileName, fileSize, fileType);
        else
            cout << "Duplicate file name: " << fileName << endl; // Duplicate insertion

        return node;
    }

    // Function for Inorder Traversal
    void inorder(FileNode *node)
    {
        if (node != nullptr)
        {
            inorder(node->left);
            cout << *node << endl;
            inorder(node->right);
        }
    }

    // Function to search for a file by name
    FileNode *search(FileNode *node, string fileName)
    {
        if (node == nullptr || node->fileName == fileName)
            return node;

        if (fileName < node->fileName)
            return search(node->left, fileName);
        else
            return search(node->right, fileName);
    }

    // Function to rename a file
    void renameFile(FileNode *node, string oldName, string newName)
    {
        FileNode *fileNode = search(node, oldName);
        if (fileNode != nullptr)
        {
            fileNode->fileName = newName;
            cout << "File renamed from " << oldName << " to " << newName << endl;
        }
        else
        {
            cout << "File not found: " << oldName << endl;
        }
    }
};

int main()
{
    FileBST bst;
    bst.root = nullptr;

    // Insert some file nodes
    bst.root = bst.insert(bst.root, "file2.txt", 10, "txt");
    bst.root = bst.insert(bst.root, "file1.pdf", 20, "pdf");
    bst.root = bst.insert(bst.root, "file3.exe", 30, "exe");

    // Attempt to insert a duplicate file name
    bst.root = bst.insert(bst.root, "file3.exe", 15, "txt");

    // Print the file nodes
    cout << "Inorder Traversal:" << endl;
    bst.inorder(bst.root);

    cout << endl;
    // Search for a file
    string searchName = "file1.pdf";
    FileNode *foundFile = bst.search(bst.root, searchName);
    if (foundFile != nullptr)
    {
        cout << "Found: " << *foundFile << endl;
    }
    else
    {
        cout << "File not found: " << searchName << endl;
    }

    // Rename a file
    bst.renameFile(bst.root, "file1.pdf", "file1_renamed.pdf");
    cout << "After renaming:" << endl;
    bst.inorder(bst.root);
    return 0;
}
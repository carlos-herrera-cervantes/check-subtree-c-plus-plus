
#include <iostream>
#include <string>
#include <locale>
#include "treeNode.cpp"

using namespace std;

class BinarySearchTree
{

  Node *root;
  int length;

  /**
  * Prints the elements
  * @param node Node object class
  * @returns Void
  */
  void inorder(Node *node)
  {
    if (!node)
      return;

    cout << node->data << ": ";

    if (node->left)
      cout << "L" << node->left->data << " ";
    if (node->rigth)
      cout << "R" << node->rigth->data << " ";

    cout << endl;

    inorder(node->left);
    inorder(node->rigth);
  }

  /** Inserts a new node
  * @param node Node object class
  * @param value Number value
  * @returns Node object class
  */
  Node *insert(Node *node, int value)
  {
    if (!node)
    {
      node = new Node();
      node->data = value;
      node->left = node->rigth = NULL;
    }
    else if (value < node->data)
    {
      node->left = insert(node->left, value);
    }
    else if (value > node->data)
    {
      node->rigth = insert(node->rigth, value);
    }

    return node;
  }

  /**
   * Returns the string with values of the nodes
   * @param node Node object class
   * @param builder String
   */
  void getOrderString(Node* node, string *builder)
  {
    if (!node)
    {
      builder->append("X");
      return;
    }

    builder->append(to_string(node->data) + " ");
    getOrderString(node->left, builder);
    getOrderString(node->rigth, builder);
  }

  /**
   * Finds the portion of a string in another string
   * @param text First string
   * @param pattern Second string
   * @returns If finds the portion it will returns the index otherwise will returns -1
   */
  int indexof(std::string& text, std::string& pattern)
  {
    string::size_type loc = text.find(pattern, 0);

    if(loc != std::string::npos)
    {
        return loc;
    }
    else
    {
        return -1;
    }
  }

  public:

    BinarySearchTree()
    {
      root = NULL;
      length = 0;
    }

    /**
    * Prints the elements to the console
    * @returns Void
    */
    void print()
    {
      inorder(root);
      cout << endl;
    }

    /**
    * Inserts a new value
    * @param data Number value
    * @returns Void
    */
    void insert(int data)
    {
      root = insert(root, data);
      length++;
    }

    /**
     * Returns the root node
     * @returns Node object class
     */
    Node* getRoot()
    {
      return root;
    }

    /**
     * Checks if the second tree is a subtree of the first one
     * @param node Node object class
     * @returns If the tree is a subtree returns a number different from -1
     */
    int isSubtree(Node* node)
    {
      string builder1;
      string builder2;

      getOrderString(root, &builder1);
      getOrderString(node, &builder2);

      return indexof(builder1, builder2);    
    }
};
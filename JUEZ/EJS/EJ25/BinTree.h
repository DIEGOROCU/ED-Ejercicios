/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

/*
 * Esta implementación utiliza smart pointers para prevenir
 * fugas de memoria y problemas con la destrucción.
 */

 #ifndef __BINTREE_H
 #define __BINTREE_H
 
 #include <cassert>
 #include <iostream>
 #include <memory>
 
 template <class T> class BinTree {
 public:
   BinTree() : root_node(nullptr) {}
 
   BinTree(const T &elem)
       : root_node(std::make_shared<TreeNode>(nullptr, elem, nullptr)) {}
 
   BinTree(const BinTree &left, const T &elem, const BinTree &right)
       : root_node(std::make_shared<TreeNode>(left.root_node, elem,
                                              right.root_node)) {}
 
   bool empty() const { return root_node == nullptr; }
 
   const T &root() const {
     assert(root_node != nullptr);
     return root_node->elem;
   }
 
   BinTree left() const {
     assert(root_node != nullptr);
     BinTree result;
     result.root_node = root_node->left;
     return result;
   }
 
   BinTree right() const {
     assert(root_node != nullptr);
     BinTree result;
     result.root_node = root_node->right;
     return result;
   }
 
   void display(std::ostream &out) const { display_node(root_node, out); }

   int size() const;
  int leafs() const;
  int height() const;

  T mini() const
  {
    if (left().empty() && right().empty())
    {
      return root();
    }
    else if (left().empty())
    {
      return std::min(root(), right().mini());
    }
    else if (right().empty())
    {
      return std::min(root(), left().mini());
    }
    else {
      return std::min(root(), std::min(left().mini(), right().mini()));
    }
  }
 
 private:
   // Las definiciones de TreeNode y NodePointer dependen recursivamente
   // la una de la otra. Por eso declaro 'struct TreeNode;' antes de NodePointer
   // para que el compilador sepa, cuando analice la definición de NodePointer,
   // que TreeNode va a ser definida más adelante.
 
   struct TreeNode;
   using NodePointer = std::shared_ptr<TreeNode>;
 
   struct TreeNode {
     TreeNode(const NodePointer &left, const T &elem, const NodePointer &right)
         : elem(elem), left(left), right(right) {}
 
     T elem;
     NodePointer left, right;
   };
 
   NodePointer root_node;
 
   static void display_node(const NodePointer &root, std::ostream &out) {
     if (root == nullptr) {
       out << ".";
     } else {
       out << "(";
       display_node(root->left, out);
       out << " " << root->elem << " ";
       display_node(root->right, out);
       out << ")";
     }
   }
 };
 
 template <typename T>
 std::ostream &operator<<(std::ostream &out, const BinTree<T> &tree) {
   tree.display(out);
   return out;
 }
 
 template <typename T> BinTree<T> read_tree(std::istream &in) {
   char c;
   in >> c;
   if (c == '.') {
     return BinTree<T>();
   } else {
     assert(c == '(');
     BinTree<T> left = read_tree<T>(in);
     T elem;
     in >> elem;
     BinTree<T> right = read_tree<T>(in);
     in >> c;
     assert(c == ')');
     BinTree<T> result(left, elem, right);
     return result;
   }
 }

 template <typename T>
int BinTree<T>::size() const
{
  if (empty())
  {
    return 0;
  }
  else
  {
    return 1 + left().size() + right().size();
  }
}

template <typename T>
int BinTree<T>::leafs() const
{
  if (empty())
  {
    return 0;
  }
  else if (left().empty() && right().empty())
  {
    return 1;
  }
  else
  {
    return left().leafs() + right().leafs();
  }
}

template <typename T>
int BinTree<T>::height() const
{
  if (empty())
  {
    return 0;
  }
  else
  {
    return 1 + std::max(left().height(), right().height());
  }
}
 
 #endif
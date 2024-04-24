#pragma once
template <typename T>
struct Node {
    T value;
    int nrchildren;
    Node* children;

    Node(T valoare) 
    {
        value = valoare;
        children = nullptr;
        nrchildren = 0;
    }

};

template<typename T>
int Compare(T a, T b)
{
    if (a == b) return 1;
    return 0;
}

template<typename T>
int sortare(T a, T b)
{
    if(a < b) return 1;
    return 0;
}

template <typename T>
class Tree 
{
public:
    Node<T>* root;
    int maxchildren = 0;
    Tree(T maxchildren) 
    {
        this->maxchildren = maxchildren;
    }

    ~Tree() 
    {   
        delete_node(root);
    }

    void add_node(Node<T>* parent, T value) 
    {
        Node<T>* newNode = new Node<T>(value);
        if (parent == nullptr)
        {
            root = newNode;
            
        }
        else
        {
            if (parent->children == nullptr)
                parent->children = newNode;
            else
            {
                Node<T>* aux = parent->children;
                while (aux != nullptr)
                    aux = aux->children;
                aux->children = newNode;
            }
            parent->nrchildren++;
        }
        
    }

    Node<T>* get_node(Node<T>* parent) 
    {
        if (parent == nullptr)
            return root;
        else
            return parent->children;
    }

    void delete_node(Node<T>* parent) 
    {
        if (parent == nullptr) return;
        if (parent->children != nullptr)
        {
            Node<T>* aux = parent->children;
            while (aux != nullptr)
            {
                delete_node(aux);
                aux = aux->children;
            }
            delete parent;
        }
    }

    
    Node<T>* find(Node<T>* startNode, T value, T(*callback)(T, T))
    {
        if (startNode == nullptr) 
            return nullptr;
        if (Compare(startNode->value, value) == 1)
            return startNode;
        Node<T>* result = nullptr;
        Node<T>* aux = startNode->children;
        while (aux != nullptr && result == nullptr) 
        {
            result = find(aux, value, callback);
            aux = aux->children;
        }
        return result;
    }

    void insert(Node<T>* parent, T val, int index)
    {
        if (parent == nullptr) return;
        if (index > parent->nrchildren + 1)
        {
            printf("Index out of range!");

        }
        Node<T>* newNode = new Node<T>(val);
        if (index == 0) 
        {
            newNode->children = parent->children;
            parent->children = newNode;
        }
        else 
        {
            Node<T>* aux = parent->children;
            for (int i = 1; i < index && aux != nullptr; ++i) 
                aux = aux->children;
            newNode->children = aux->children;
            aux->children = newNode;
        }
        parent->childrencount++;
    }

    void sort(Node<T>* start, T(*callback)(T, T))
    {
        if(callback != nullptr)
        for (int i = 0; i < start->nrchildren - 1; i++) 
        {
            for (int j = i + 1; j < start->nrchildren; j++) 
            {
                if (!callback(start->children[i]->val, start->copii[j]->val)) 
                {
                    T aux = start->children[i]->val;
                    start->children[i]->val = start->children[j]->val;
                    start->children[j]->val = aux;
                }
            }
        }
        else
            for (int i = 0; i < start->nrchildren - 1; i++)
            {
                for (int j = i + 1; j < start->nrchildren; j++)
                {
                    if (start->children[i]->val > start->copii[j]->val)
                    {
                        T aux = start->children[i]->val;
                        start->children[i]->val = start->children[j]->val;
                        start->children[j]->val = aux;
                    }
                }
            }
    }

    int count(Node<T>* parent) 
    {
        if (parent == nullptr)
            return root->nrchildren;
        return parent->nrchildren;
    }

};


#include "Tree.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;
using namespace ariel;

Node::Node(int data){
    this->_data = data;
    this->left = NULL;
    this->right = NULL;
}

int Node::getData(){
    return this->_data;
}

Node* Node::getLeft(){
    return this->left;
}

Node* Node::getRight(){
    return this->right;
}

void Node::setLeft(Node* left){
    this->left = left;
}

void Node::setRight(Node* right){
    this->right = right;
}

Tree::Tree(){
    rootValue = NULL;
    _size = 0;
}

Tree::~Tree(){
    Destroy(rootValue);
}

void Tree::Destroy(Node* nodeCheck){
    if(nodeCheck == NULL){
        return;
    }
    Destroy(nodeCheck->getLeft());
    Destroy(nodeCheck->getRight());
    delete nodeCheck;
}

Node* Tree::getRoot(){
    return this->rootValue;
}

Tree& Tree::insert(int i){
    if(contains(i)){
        throw runtime_error("The tree already contain this number");
    }else if(_size==0){
        rootValue = new Node(i);
        _size++;
    }else{
        Node* newNode = new Node(i);
        Node* nodeCheck = rootValue;
        bool flagInserted = false;
        while(!flagInserted){
            if(i < nodeCheck->getData()) {
                if(nodeCheck-> getLeft() == NULL){
                    nodeCheck->setLeft(newNode);
                    _size++;
                    flagInserted = true;
                }else{
                    nodeCheck = nodeCheck->getLeft();
                }
            }else{
                if(nodeCheck->getRight() == NULL){
                nodeCheck->setRight(newNode);
                _size++;
                break;
                }else{
                    nodeCheck = nodeCheck->getRight();
                }
            }
        }
    }
    return *this;
}

void Tree::remove(int i){
    if(!contains(i)){
        throw runtime_error("You tried to remove non-existent node from the tree.");
    }
    if(_size==1){
        _size--;
        delete rootValue;
        return;
    }
    Node* toRemove = containsPrivate(i);
    if(i != root()){
        Node* parentOf = containsPrivate(parent(i));
        bool toRemoveIsRightChild = toRemove->getData() > parentOf->getData();
        if(toRemove->getLeft() == NULL && toRemove->getRight() == NULL){
            if(toRemoveIsRightChild){
                parentOf->setRight(NULL);
            }else{
                parentOf->setLeft(NULL);
            }
            delete toRemove;
            _size--;
        }else if(toRemove->getRight() != NULL && toRemove ->getLeft()==NULL){
            if(toRemoveIsRightChild){
            parentOf->setRight(toRemove->getRight());
            }else{
                parentOf->setLeft(toRemove->getRight());
            }
            delete toRemove;
            _size--;
            return;
        }else if(toRemove ->getRight() == NULL && toRemove->getLeft()!=NULL){
            if(toRemoveIsRightChild){
                parentOf->setRight(toRemove->getLeft());
            }else{
                parentOf->setLeft(toRemove->getLeft());
            }
            delete toRemove;
            _size--;
            return;
        }else{
            if(toRemoveIsRightChild){
            Node* nodeCheck = toRemove->getRight();
                while(nodeCheck->getLeft() != NULL){ 
                    nodeCheck = nodeCheck->getLeft();
                }
                nodeCheck->setLeft(toRemove->getLeft());
                parentOf->setRight(toRemove->getRight());
                delete toRemove;
                _size--;
                return;
            }else{
                Node* concat = toRemove->getLeft();
                while(concat->getRight() != NULL){
                    concat = concat -> getRight();
                }
                concat->setRight(toRemove->getRight()); 
                parentOf->setLeft(toRemove->getLeft());
                delete toRemove;
                _size--;
                return;
            }
        }
    }else{
            if(toRemove->getLeft() != NULL && toRemove->getRight() == NULL){
                rootValue = toRemove->getLeft();
                delete toRemove;
                _size--;
            }else if(toRemove->getLeft() == NULL && toRemove->getRight() != NULL){
                rootValue = toRemove->getRight();
                delete toRemove;
                _size--;
            }else{
                Node* concat = toRemove->getRight();
                while(concat->getLeft() != NULL){
                    concat = concat->getLeft();
                }
                concat->setLeft(toRemove->getLeft());
                rootValue = toRemove->getRight();
                delete toRemove;
                _size--;
            }
        }
}

int Tree::size(){
    return _size;
}

bool Tree::contains(int i){
    try{
        Node* isIn = containsPrivate(i);
    }
    catch(exception& e){
        return false;
    }
    return true;
}

int Tree::root(){
    if(_size>0){
        return getRoot()->getData();
    }else{
        throw invalid_argument("there is no root");
    }
}

int Tree::parent(int i){
    if(size()==0 || !contains(i) || root() == i){
        throw invalid_argument("check the tree. it can be empty");
    }else{
        Node* nodeCheck = this->getRoot();
        bool foundflag = false;
        while(!foundflag){
            if((nodeCheck->getLeft() !=NULL && nodeCheck->getLeft()->getData() == i) || (nodeCheck->getRight() != NULL && nodeCheck->getRight()->getData() == i)){
                foundflag = true;
            }
            else if(i < nodeCheck->getData()){
                nodeCheck = nodeCheck->getLeft();
            }else{
                nodeCheck = nodeCheck->getRight();
            }
        }
        return nodeCheck->getData();
    }
}

int Tree::left(int i){
    Node* nodeCheck = containsPrivate(i);
    if(nodeCheck->getLeft() != NULL){
        return nodeCheck->getLeft()->getData();
    }else{
        throw invalid_argument("There is no left child for requested node.");
    }
}

int Tree::right(int i){
    Node* nodeCheck = containsPrivate(i);
    if(nodeCheck->getRight() != NULL){
        return nodeCheck->getRight()->getData();
    }else {
        throw invalid_argument("There is no right child for requested node.");
    }
}

void Tree::print(){
  printPrivate(rootValue);
}

void Tree::printPrivate(Node* nodeCheck){
    if(nodeCheck==NULL){
        return;
    }
    printPrivate(nodeCheck->getLeft());
    cout << nodeCheck->getData() << " ";
    printPrivate(nodeCheck->getRight());
}


Node* Tree::containsPrivate(int i){
    if(size() == 0 ){
        throw invalid_argument("Cannot find in an empty tree");
    }
    Node* nodeCheck = getRoot();
    while(nodeCheck!=NULL){
        if(nodeCheck->getData() == i){
            return nodeCheck;
        }
        else if(nodeCheck->getData()>i){
            nodeCheck = nodeCheck->getLeft();
        }else{
            nodeCheck = nodeCheck->getRight();
        }
    }
    throw runtime_error("Cannot find requested node.");
}
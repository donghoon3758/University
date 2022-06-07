#define _CRT_SECURE_NO_WARNINGS

#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
const int MAX = 100;

struct Student {
    char name[81];
    char ID[10];
    float GPA;
    float weight;
    float height;
    int age;
};
struct StudentQry {
    char condition[6] = {'\0'};
    float min=0;
    float max=0;
};
Student create_struct(ifstream& fin) {
    Student student;
    string name, ID, GPA, weight, height, age;
    getline(fin, name, ',');
    getline(fin, ID, ',');
    ID.erase(0, 1);
    getline(fin, GPA, ',');
    GPA.erase(0, 1);
    getline(fin, weight, ',');
    weight.erase(0, 1);
    getline(fin, height, ',');
    height.erase(0, 1);
    getline(fin, age);
    age.erase(0, 1);
    strcpy(student.name, name.c_str());
    strcpy(student.ID, ID.c_str());
    student.GPA = stof(GPA);
    student.weight = stof(weight);
    student.height = stof(height);
    student.age = stoi(age);

    return student;
}
StudentQry create_struct1(ifstream& fqry) {
    StudentQry query;
    string condition, min, max;
    getline(fqry, condition, ',');
    getline(fqry, min, ',');
    min.erase(0, 1);
    getline(fqry, max);
    max.erase(0, 1);
    strcpy(query.condition, condition.c_str());
    query.min = stof(min);
    query.max = stof(max);

    return query;
}
class BPNode {
    bool LEAF;
    int size;
    float* value;
    BPNode** nodePtr;
    friend class BPlusTree;

public:
    BPNode();
};

// BP tree
class BPlusTree {
    BPNode* root;
    void insertInternal(float, BPNode*, BPNode*);
    BPNode* findParent(BPNode*, BPNode*);

public:
    BPlusTree();
    void rangeSearch(string,vector<Student>,int,float,float);
    void insert(float);
};

BPNode::BPNode() {
    value = new float[MAX];
    nodePtr = new BPNode * [MAX + 1];
}

BPlusTree::BPlusTree() {
    root = NULL;
}

void BPlusTree::rangeSearch(string key, vector<Student>v1, int num, float min, float max) {
    int count = 0;
    ofstream fout;
    fout.open("students.out", fstream::out | fstream::app);
    if (fout.is_open()) {
        if (root == NULL) {
        }
        else {
            BPNode* node = root;
            while (node->LEAF == false) {
                for (int i = 0; i < node->size; i++) {
                    if (min < node->value[i]) {
                        node = node->nodePtr[i];
                        break;
                    }
                    if (i == node->size - 1) {
                        node = node->nodePtr[i + 1];
                        break;
                    }
                }
            }
            for (int i = 0; i < node->size; i++) {
                if (node->value[i] >= min && node->value[i] <= max) {
                    if (key == "GPA") {
                        for (int j = 0; j < num; j++) {
                            if (node->value[i] == v1[j].GPA) {
                                count++;
                            }
                        }
                    }
                    else if (key == "Weight") {
                        for (int j = 0; j < num; j++) {
                            if (node->value[i] == v1[j].weight) {
                                count++;
                            }
                        }
                    }
                    else if (key == "Height") {
                        for (int j = 0; j < num; j++) {
                            if (node->value[i] == v1[j].height) {
                                count++;
                            }
                        }
                    }
                    else
                        break;
                }
            }
            fout << count << endl;
            fout.close();
        }
    }
}

void BPlusTree::insert(float recordValue) {
    if (root == NULL) {
        root = new BPNode;
        root->value[0] = recordValue;
        root->LEAF = true;
        root->size = 1;
    }
    else {
        BPNode* currentNode = root;
        BPNode* parentNode=NULL;
        while (currentNode->LEAF == false) {
            parentNode = currentNode;
            for (int i = 0; i < currentNode->size; i++) {
                if (recordValue < currentNode->value[i]) {
                    currentNode = currentNode->nodePtr[i];
                    break;
                }
                if (i == currentNode->size - 1) {
                    currentNode = currentNode->nodePtr[i + 1];
                    break;
                }
            }
        }
        if (currentNode->size < MAX) {
            int i = 0;
            while (recordValue > currentNode->value[i] && i < currentNode->size)
                i++;
            for (int j = currentNode->size; j > i; j--) {
                currentNode->value[j] = currentNode->value[j - 1];
            }
            currentNode->value[i] = recordValue;
            currentNode->size++;
            currentNode->nodePtr[currentNode->size] = currentNode->nodePtr[currentNode->size - 1];
            currentNode->nodePtr[currentNode->size - 1] = NULL;
        }
        else {
            BPNode* newLeafNode = new BPNode;
            float virtualNode[MAX + 1];
            for (int i = 0; i < MAX; i++) {
                virtualNode[i] = currentNode->value[i];
            }
            int i = 0, j;
            while (recordValue > virtualNode[i] && i < MAX)
                i++;
            for (int j = MAX + 1; j > i; j--) {
                virtualNode[j] = virtualNode[j - 1];
            }
            virtualNode[i] = recordValue;
            newLeafNode->LEAF = true;
            currentNode->size = (MAX + 1) / 2;
            newLeafNode->size = MAX + 1 - (MAX + 1) / 2;
            currentNode->nodePtr[currentNode->size] = newLeafNode;
            newLeafNode->nodePtr[newLeafNode->size] = currentNode->nodePtr[MAX];
            currentNode->nodePtr[MAX] = NULL;
            for (i = 0; i < currentNode->size; i++) {
                currentNode->value[i] = virtualNode[i];
            }
            for (i = 0, j = currentNode->size; i < newLeafNode->size; i++, j++) {
                newLeafNode->value[i] = virtualNode[j];
            }
            if (currentNode == root) {
                BPNode* newRootNode = new BPNode;
                newRootNode->value[0] = newLeafNode->value[0];
                newRootNode->nodePtr[0] = currentNode;
                newRootNode->nodePtr[1] = newLeafNode;
                newRootNode->LEAF = false;
                newRootNode->size = 1;
                root = newRootNode;
            }
            else {
                insertInternal(newLeafNode->value[0], parentNode, newLeafNode);
            }
        }
    }
}

void BPlusTree::insertInternal(float recordValue, BPNode* currentNode, BPNode* childNode) {
    if (currentNode->size < MAX) {
        int i = 0;
        while (recordValue > currentNode->value[i] && i < currentNode->size)
            i++;
        for (int j = currentNode->size; j > i; j--) {
            currentNode->value[j] = currentNode->value[j - 1];
        }
        for (int j = currentNode->size + 1; j > i + 1; j--) {
            currentNode->nodePtr[j] = currentNode->nodePtr[j - 1];
        }
        currentNode->value[i] = recordValue;
        currentNode->size++;
        currentNode->nodePtr[i + 1] = childNode;
    }
    else {
        BPNode* newInternalNode = new BPNode;
        float virtualValue[MAX + 1];
        BPNode* virtualPtr[MAX + 2];
        for (int i = 0; i < MAX; i++) {
            virtualValue[i] = currentNode->value[i];
        }
        for (int i = 0; i < MAX + 1; i++) {
            virtualPtr[i] = currentNode->nodePtr[i];
        }
        int i = 0, j;
        while (recordValue > virtualValue[i] && i < MAX)
            i++;
        for (int j = MAX + 1; j > i; j--) {
            virtualValue[j] = virtualValue[j - 1];
        }
        virtualValue[i] = recordValue;
        for (int j = MAX + 2; j > i + 1; j--) {
            virtualPtr[j] = virtualPtr[j - 1];
        }
        virtualPtr[i + 1] = childNode;
        newInternalNode->LEAF = false;
        currentNode->size = (MAX + 1) / 2;
        newInternalNode->size = MAX - (MAX + 1) / 2;
        for (i = 0, j = currentNode->size + 1; i < newInternalNode->size; i++, j++) {
            newInternalNode->value[i] = virtualValue[j];
        }
        for (i = 0, j = currentNode->size + 1; i < newInternalNode->size + 1; i++, j++) {
            newInternalNode->nodePtr[i] = virtualPtr[j];
        }
        if (currentNode == root) {
            BPNode* newRootNode = new BPNode;
            newRootNode->value[0] = currentNode->value[currentNode->size];
            newRootNode->nodePtr[0] = currentNode;
            newRootNode->nodePtr[1] = newInternalNode;
            newRootNode->LEAF = false;
            newRootNode->size = 1;
            root = newRootNode;
        }
        else {
            insertInternal(currentNode->value[currentNode->size], findParent(root, currentNode), newInternalNode);
        }
    }
}

BPNode* BPlusTree::findParent(BPNode* currentNode, BPNode* childNode) {
    BPNode* parentNode = NULL;
    if (currentNode->LEAF || (currentNode->nodePtr[0])->LEAF) {
        return NULL;
    }
    for (int i = 0; i < currentNode->size + 1; i++) {
        if (currentNode ->nodePtr[i] == childNode) {
            parentNode = currentNode;
            return parentNode;
        }
        else {
            parentNode = findParent(currentNode->nodePtr[i], childNode);
            if (parentNode != NULL)
                return parentNode;
        }
    }
    return parentNode;
}

int main() {
    string recordNum, searchNum, condition;
    Student student;
    StudentQry query;
    vector<Student>v1;
    vector<StudentQry>v2;
    ifstream fin, fqry;

    BPlusTree GPA_Tree;
    BPlusTree weight_Tree;
    BPlusTree height_Tree;

    fin.open("students.inp", fstream :: in);
    fqry.open("students.qry", fstream :: in);
    if (fin.is_open() &&  fqry.is_open()) {
        getline(fin, recordNum);
        for (int i = 0; i < stoi(recordNum); i++) {
            student = create_struct(fin);
            v1.push_back(student);
        }
        for (int k = 0; k < stoi(recordNum); k++) {
            GPA_Tree.insert(v1[k].GPA);
        }
        for (int k = 0; k < stoi(recordNum); k++) {
            weight_Tree.insert(v1[k].weight);
        }
        for (int k = 0; k < stoi(recordNum); k++) {
            height_Tree.insert(v1[k].height);
        }
        getline(fqry, searchNum);
        for (int i = 0; i < stoi(searchNum); i++) {
            query = create_struct1(fqry);
            v2.push_back(query);
        }
        for (int i = 0; i < v2.size(); i++) {
            string condition = v2[i].condition;
            if (condition == "GPA") {
                GPA_Tree.rangeSearch(condition, v1, stoi(recordNum), v2[i].min, v2[i].max);
            }
            else if (condition == "Weight") {
                weight_Tree.rangeSearch(condition, v1, stoi(recordNum), v2[i].min, v2[i].max);
            }
            else if (condition == "Height") {
                height_Tree.rangeSearch(condition, v1, stoi(recordNum), v2[i].min, v2[i].max);
            }
        }
        recordNum.clear();
        v1.clear();
        searchNum.clear();
        v2.clear();
    }
    fin.close();
    fqry.close();

    return 0;
}
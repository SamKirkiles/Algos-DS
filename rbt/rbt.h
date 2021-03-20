enum color {RED, BLACK};

struct RBTNode {

        int value;
        RBTNode *left;
        RBTNode *right;
        RBTNode *parent;
        color c;
};

void insert_node(RBTNode* tree, int insert);
void leftRotate (RBTNode * tree, RBTNode* rotate);

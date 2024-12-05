#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 创建二叉树节点
TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 添加全局索引变量
int charIndex = 0;

// 创建树
TreeNode* createTree(char* str) {
    char data = str[charIndex++];
    
    if (data == '#' || data == '\0') {
        return NULL;
    }
    
    TreeNode* root = createNode(data);
    root->left = createTree(str);
    root->right = createTree(str);
    return root;
}

// 先序遍历
void preOrder(TreeNode* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// 中序遍历
void inOrder(TreeNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%c ", root->data);
        inOrder(root->right);
    }
}

// 后序遍历
void postOrder(TreeNode* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%c ", root->data);
    }
}

// 计算节点总数
int countNodes(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// 计算树的深度
int getDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// 修改查找节点深度的函数
int findNodeDepth(TreeNode* root, char target, int level) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == target) {
        return level;
    }
    
    int depth = findNodeDepth(root->left, target, level + 1);
    return depth > 0 ? depth : findNodeDepth(root->right, target, level + 1);
}

// 计算叶子节点数
int countLeaves(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right);
}

// 交换左右子树
void swapSubtrees(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    swapSubtrees(root->left);
    swapSubtrees(root->right);
}

int main() {
    char str[] = "ABCD##E##F##G##";  // 新的二叉树表示

    charIndex = 0;  // 重置索引
    
    TreeNode* root = createTree(str);
    
    printf("先序遍历：");
    preOrder(root);
    
    printf("\n中序遍历：");
    inOrder(root);
    
    printf("\n后序遍历：");
    postOrder(root);
    
    printf("\n节点总数：%d", countNodes(root));
    printf("\n树的深度：%d", getDepth(root));
    
    char target = 'D';  // 示例目标节点
    printf("\n节点%c的深度：%d", target, findNodeDepth(root, target, 1));
    
    printf("\n叶子节点数：%d", countLeaves(root));
    
    printf("\n交换左右子树后的中序遍历：");
    swapSubtrees(root);
    inOrder(root);
    printf("\n");
    
    return 0;
}

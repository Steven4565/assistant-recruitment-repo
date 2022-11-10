#include <stdio.h>
#include <stdlib.h>
// look up konsep tree, dimana data yg lebih kecil dr root akan ditaro di left child,
// sedangkan data yg lebih besar dr root akan ditaro di right child

// tree utilizes struct
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{ // create new node misah
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct node *insert(struct node *root, int data)
{ // inserting into the tree, dmn root itu parent nodenya
    // 3 base conds
    if (root == NULL)
        return newNode(data); // jika belum ada tree, lgsg buat node
    else if (data < root->data)
        root->left = insert(root->left, data); // jika new node lebih kecil, taro di cabang kiri
    else if (data > root->data)
        root->right = insert(root->right, data); // jika lebih besar, taro di cabang kanan
    else
        printf("Duplicate value, new node data equals to root node\n"); // jika sama, maka tdk bs dimasukkin

    return root;
}

void search(struct node *root, int data)
{
    // 3 base conds
    if (root == NULL)
        printf("Node not found\n"); // udah sampe akhir, ngga ketemu
    else if (root->data > data)
        search(root->left, data); // lebih gede, cari ke sebelah kiri yg lebih kecil
    else if (root->data < data)
        search(root->right, data); // lebih besar, cari ke data yg lebih besar
    else if (root->data == data)
        printf("Value found\n"); // udah sama, ketemu
}

// VIEW
// terbagi jadi 3, preorder(prefix), inorder(infix), postorder(postfix)
// preorder: kiri-kanan-print (print parent node kiri, print parent node kanan)
// inorder: kiri-print-kanan (hasilnya, print akan tersort)
// postoder: dibaca dulu semua br print, print dari bawah

void prefix(struct node *curr)
{
    if (curr != NULL)
    {
        printf("%d\n", curr->data);
        prefix(curr->left);
        prefix(curr->right);
    }
}

void infix(struct node *curr)
{
    if (curr != NULL)
    {
        infix(curr->left);
        printf("%d\n", curr->data);
        infix(curr->right);
    }
}

void postfix(struct node *curr)
{
    if (curr != NULL)
    {
        postfix(curr->left);
        postfix(curr->right);
        printf("%d\n", curr->data);
    }
}

struct node *deleteNode(struct node *root, int data)
{
    // 3 base conds
    if (root == NULL)
        return NULL; // either tree emg udah kosong, ato udh smpe pojok tp ganemu node yg dicari
    else if (data < root->data)
        root->left = deleteNode(root->left, data); // data kekecilan, cari ke sblh kiri
    else if (data > root->data)
        root->right = deleteNode(root->right, data); // data kebesaran, cari ke sblh kanan
    else if (data == root->data)
    {
        if (root->left == NULL && root->right == NULL)
        {
            // node yg mau didelete gapunya child
            free(root);
            root = NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            root = temp;
            // struct node *temp = root->left;
            //			root = temp;
            //			free(temp);
        }
        else if (root->left == NULL && root->right != NULL)
        {
            struct node *temp = root->right;
            free(root);
            root = temp;
            // struct node *temp = root->right;
            //			root = temp;
            //			free(temp);
        }
        else if (root->left != NULL && root->right != NULL)
        {
            // node punya 2 child
            struct node *temp;
            temp = root->left;
            // loop hingga kanan null
            while (temp->right != NULL)
                temp = temp->right;
            // ganti value root ke temp
            root->data = temp->data;
            // value dr kiri ke kanan blm abis
            root->left - deleteNode(root->left, data);
        }
    }
}

int main()
{
    struct node *root = NULL;
    printf("Add data? ");
    int opt;
    int num;

    scanf("%c", &opt);
    getchar();
    if (opt == 'y')
    {
        printf("How many? ");
        scanf("%d", &num);
        getchar();
        for (int i = 0; i < num; i++)
        {
            printf("Enter data: "); // ini dibikin disini soalnya kita punya func create newnode, jadi skalian aja di main
            int val;
            scanf("%d", &val);
            getchar();
            root = insert(root, val);
        }
    }
    // make search func
    search(root, 30);
    deleteNode(root, 30);

    printf("Prefix:\n");
    prefix(root);
    printf("Infix:\n");
    infix(root);
    printf("Postfix:\n");
    postfix(root);

    return 0;
}
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int key;
    struct node *lchild, *rchild;
};

struct node* create(struct node *tree, int value);
int inorder(struct node *tree);
int preorder(struct node *tree);
int postorder(struct node *tree);
struct node* maximum_finder(struct node *tree);
struct node *minimum_finder(struct node *tree);
struct node *minimum_finder_recursive(struct node *tree);
struct node *maximum_finder_recursive(struct node *tree);
int number_of_nodes(struct node *tree);
int LeafNodeCounter(struct node *tree);
int ParentNodeCounter(struct node *tree);
int ParentNodeHavingLchild(struct node *tree);
int ParentNodeHavingRchild(struct node *tree);
int ParentNodeHavingRchildLchild(struct node *tree);
int DeleteLeafNode(struct node *tree, int value);
struct node *DeleteNodeRecursive(struct node *tree, int value);
struct node *TreeSplit( struct node *tree, int value);


void main()
{
    struct node *tree, *temptree, *q;
    int value, i, a;
    tree = NULL;
    for(i=0; i<9; ++i)
    {
        printf("\n Enter a KEY to add to the tree: ");
        scanf("%d", &value);
        tree = create(tree, value);
    }

    printf("\n INORDER: ");
    inorder(tree);
    printf("\n PREORDER: ");
    preorder(tree);
    printf("\n POSTORDER: ");
    postorder(tree);
    q=maximum_finder(tree);
    printf("\n MAXIMUM NUMBER IN THE TREE IS: %d", q->key);
    q=minimum_finder(tree);
    printf("\n MINIMUM NUMBER IN THE TREE IS: %d\n", q->key);
    q=minimum_finder_recursive(tree);
    printf("\n MINIMUM NUMBER BY RECURSIVE METHOD IS: %d", q->key);
    q=maximum_finder_recursive(tree);
    printf("\n MAXIMUM NUMBER BY RECURSIVE METHOD IS: %d\n", q->key);
    a=number_of_nodes(tree);
    printf("\n NUMBER OF NODES IN THE GIVEN TREE ARE: %d", a);
    a=LeafNodeCounter(tree);
    printf("\n NUMBER OF LEAF NODES IN THE GIVEN TREE ARE: %d", a);
    a=ParentNodeCounter(tree);
    printf("\n NUMBER OF PARENT NODES IN THE GIVEN TREE ARE: %d\n", a);
    a=ParentNodeHavingLchild(tree);
    printf("\n NUMBER OF PARENT NODES WITH LCHILD ARE: %d", a);
    a=ParentNodeHavingRchild(tree);
    printf("\n NUMBER OF PARENT NODES WITH RCHILD ARE: %d", a);
    a=ParentNodeHavingRchildLchild(tree);
    printf("\n NUMBER OF PARENTS HAVING BOTH RCHILD AND LCHILD ARE: %d", a);

    /*printf("\n ENTER THE VALUE TO DELETE: ");
    scanf("%d", &value);
    a=DeleteLeafNode(tree, value);
    printf("\n %d USED \n", a);

    printf("\n INORDER: ");
    inorder(tree);

    printf("\n ENTER THE VALUE TO DELETE: ");
    scanf("%d", &value);
    printf("\n DELETE NODE RECURSIVE: ");
    q=DeleteNodeRecursive(tree, value);

    printf("\n INORDER: ");
    inorder(tree);*/

    printf("\n ENTER THE NODE TO SPLIT THE TREE FROM: ");
    scanf("%d", &value);
    printf("\n TREE SPLITING \n");
    q=TreeSplit(tree, value);

    printf("\n INORDER: ");
    inorder(tree);
}


struct node* create(struct node *tree, int value)
{
    struct node *newnode, *p, *space, *q;
    q = tree;
    if(q == NULL)
    {
        newnode = (struct node*)malloc (sizeof(struct node));
        q = newnode;
        q->key = value;
        q->lchild = NULL;
        q->rchild = NULL;
        return(q);
    }
    else
    {
        while(q != NULL)
        {
            p = q;
            if(value == q->key)
            {
                printf("\n Same data is already present in the tree \n");
                return(q);
            }
            if(value < q->key)
            {
                q = q->lchild;
            }
            else if(value > q->key)
            {
                q = q->rchild;
            }
        }
        if(value < p->key)
        {

            space = (struct node *)malloc(sizeof(struct node));
            p->lchild = space;
            space->lchild = NULL;
            space->rchild = NULL;
            space->key = value;

        }
        if(value > p->key)
        {
            space = (struct node *)malloc(sizeof(struct node));
            p->rchild = space;
            space->lchild = NULL;
            space->rchild = NULL;
            space->key = value;
        }
    }
    return(tree);
}

int inorder(struct node *tree)
{
    if(tree == NULL)
    {
        return(0);
    }

    inorder(tree->lchild);
    printf(" %d ", tree->key);
    inorder(tree->rchild);

}

int preorder(struct node *tree)
{
    if(tree == NULL)
    {
        return(0);
    }
    printf(" %d ", tree->key);
    preorder(tree->lchild);
    preorder(tree->rchild);

}

int postorder(struct node *tree)
{
    if(tree == NULL)
    {
        return(0);
    }
    postorder(tree->lchild);
    postorder(tree->rchild);
    printf(" %d ", tree->key);

}

struct node* maximum_finder(struct node *tree)
{
    if(tree == NULL)
    {
        printf("\n NO ELEMENT IN THE LIST \n");
        return(tree);
    }
    else
    {
        while(tree->rchild != NULL)
        {
            tree = tree->rchild;
        }
    }
    return(tree);
}


struct node *minimum_finder(struct node *tree)
{
    if(tree == NULL)
    {
        printf("\n NO ELEMENT IN THE LIST \n");
        return(tree);
    }
    else
    {
        while(tree->lchild != NULL)
        {
            tree = tree->lchild;
        }
    }
    return(tree);
}


struct node *minimum_finder_recursive(struct node *tree)
{
    if(tree == NULL)
    {
        return(tree);
    }
    if(tree->lchild != NULL)
    {
        minimum_finder_recursive(tree->lchild);
    }
    else if(tree->lchild == NULL)
    {
        return(tree);
    }
}

struct node *maximum_finder_recursive(struct node *tree)
{
    if(tree == NULL)
    {
        return(tree);
    }
    if( tree->rchild != NULL)
    {
       maximum_finder_recursive(tree->rchild);
    }
    else if(tree->rchild == NULL)
    {
        return(tree);
    }
}


int number_of_nodes(struct node *tree)
{
    int static count=0;

    if(tree == NULL)
    {
        return(0);
    }

    number_of_nodes(tree->lchild);

    count++;

    number_of_nodes(tree->rchild);

    return(count);

}

int LeafNodeCounter(struct node *tree)
{
    int static CountLeaf=0;

    if(tree == NULL)
    {
        return(0);
    }

    LeafNodeCounter(tree->lchild);

    if(tree->lchild == NULL && tree->rchild == NULL)
    {
        CountLeaf++;
    }

    LeafNodeCounter(tree->rchild);

    return(CountLeaf);
}

int ParentNodeCounter(struct node *tree)
{
    int static CountParent = 0;

    if(tree == NULL)
    {
        return(0);
    }

    ParentNodeCounter(tree->lchild);

    if(tree->lchild != NULL || tree->rchild != NULL)
    {
        CountParent++;
    }

    ParentNodeCounter(tree->rchild);

    return(CountParent);
}

int ParentNodeHavingLchild(struct node *tree)
{
    int static CountLchildNode;

    if(tree == NULL)
    {
        return(0);
    }

    ParentNodeHavingLchild(tree->lchild);

    if(tree->lchild != NULL)
    {
        CountLchildNode++;
    }

    ParentNodeHavingLchild(tree->rchild);

    return(CountLchildNode);
}

int ParentNodeHavingRchild(struct node *tree)
{
    int static CountRchildNode = 0;

    if(tree == NULL)
    {
        return(0);
    }

    ParentNodeHavingRchild(tree->lchild);

    if(tree->rchild != NULL)
    {
        CountRchildNode++;
    }

    ParentNodeHavingRchild(tree->rchild);

    return(CountRchildNode);
}

int ParentNodeHavingRchildLchild(struct node *tree)
{
    int static CountNodeRchildLchild;

    if(tree == NULL)
    {
        return(0);
    }

    ParentNodeHavingRchildLchild(tree->lchild);

    if(tree->lchild != NULL && tree->rchild != NULL)
    {
        CountNodeRchildLchild++;
    }

    ParentNodeHavingRchildLchild(tree->rchild);

    return(CountNodeRchildLchild);
}


int DeleteLeafNode(struct node *tree, int value)
{
    struct node *parent, *minimum, *minimum_parent;

    parent = tree;

    if(tree == NULL)
    {
        printf("\n TREE IS EMPTY \n");
    }

    while(tree != NULL)
    {
        if(tree == NULL)
        {
            printf("\n TREE IS EMPTY \n");
        }
        if(value == tree->key)
        {
            break;
        }
        if(value < tree->key)
        {
            parent = tree;
            tree = tree->lchild;
        }
        if(value > tree->key)
        {
            parent = tree;
            tree = tree->rchild;
        }
    }

    if(tree == NULL)
    {
        printf("\n NO SUCH ENTRY FOUND \n");
        return(0);
    }

    if(tree->lchild == NULL && tree->rchild == NULL)
    {
            if(value < parent->key)
            {
                parent->lchild = NULL;
            }
            else if(value > parent->key)
            {
                parent->rchild = NULL;
            }

        printf("\n %d freed \n", tree->key);

        free(tree);
        return(1);
    }
    else
    {
        printf("\n CANNOT BE DELETED BY LEAF NODE METHOD \n");
    }



    if((tree->lchild != NULL && tree->rchild == NULL) || (tree->lchild == NULL && tree->rchild != NULL))
    {
        if(tree->lchild != NULL && parent->lchild == tree)
        {
            parent->lchild = tree->lchild;
        }
        if(tree->rchild != NULL && parent->lchild == tree)
        {
            parent->lchild = tree->rchild;
        }
        if(tree->lchild != NULL && parent->rchild == tree)
        {
            parent->rchild = tree->lchild;
        }
        if(tree->rchild != NULL && parent->rchild == tree)
        {
            parent->rchild = tree->rchild;
        }

        printf("\n %d FREED \n", tree->key);
        free(tree);

        return(2);
    }
    else
    {
        printf("\n CANNOT BE DELETED BY 1 CHILD METHOD \n");
    }

    if(tree->rchild != NULL && tree->lchild != NULL)
    {
        minimum = tree->rchild;
        minimum_parent = tree;

        while(minimum->lchild != NULL)
        {
            minimum_parent = minimum;
            minimum = minimum->lchild;
        }

        tree->key = minimum->key;

        if(tree->rchild == minimum)
        {
            tree->rchild = minimum->rchild;
        }
        else if(tree->rchild != minimum)
        {
            minimum_parent->lchild = minimum->rchild;
        }

        printf("\n %d FREED \n", minimum->key);
        free(minimum);
        return(3);
    }
    else
    {
        printf("\n CANNOT DELETE WITH THE 2 CHILD METHOD \n");
    }
}



struct node *TreeSplit( struct node *tree, int value)
{
    struct node *parent ;

    if ( tree == NULL )
    {
        return(tree);
    }

    if ( tree->key == value )
    {
        printf( "/n ITS THE TREE ROOT!!! \n " ,  tree->key  ) ;
        return ( NULL ) ;
    }

    parent = tree ;

    while( tree != NULL )
    {
        if ( value == tree->key )
        {
            break ;
        }
        else if ( value < tree->key )
        {
            parent = tree ;
            tree = tree->lchild ;
        }
        else
        {
            parent = tree ;
            tree = tree->rchild ;
        }
    }

    if ( tree == NULL )
    {
        printf( "\n NODE NOT FOUND \n ", tree->key) ;
        return ( NULL ) ;
    }
    else if ( parent->lchild == tree )
    {
        parent->lchild = NULL ;
    }
    else
    {
        parent->rchild = NULL ;
    }

    return (tree) ;
}



struct node *DeleteNodeRecursive(struct node *tree, int value)
{
    struct node *ReturnValue, *minimum;
    if(tree == NULL)
    {
        return(tree);
    }

    if(value < tree->key)
    {
        tree->lchild = DeleteNodeRecursive(tree->lchild, value);
    }
    else if(value > tree->key)
    {
        tree->rchild = DeleteNodeRecursive(tree->rchild, value);
    }
    else
    {
        if(tree->lchild == NULL)
        {
            ReturnValue = tree->rchild;

            free(tree);

            return(ReturnValue);
        }
        else if(tree->rchild == NULL)
        {
            ReturnValue = tree->lchild;

            free(tree);

            return(ReturnValue);
        }

        minimum = tree->rchild;

        while(minimum->rchild != NULL)
        {
            minimum = minimum->lchild;
        }

        tree->key = minimum->key;

        tree->rchild = DeleteNodeRecursive(minimum, minimum->key);
    }

    return(tree);
};

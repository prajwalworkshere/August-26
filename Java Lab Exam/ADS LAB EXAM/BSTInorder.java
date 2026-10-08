import java.util.*;

class BST{
    private static class node{
        int data;
        node left;
        node right;
    
        node(int data){
            this.data=data;
            left=null;
            right= null;
        }
    }

    private node root;

    public void insert(int value){
        root=insertRecursive(root,value);
    }

    private node insertRecursive(node current,int value){
        
        if(current==null){
            return new node(value);
        }

        if(value<current.data){
            current.left=insertRecursive(current.left,value);
        }
        else if (value>current.data){
            current.right=insertRecursive(current.right,value);
        }

        return current;
    }

    public void inorder(){
        inorderRecursive(root);
        System.out.println();
    }

    private void inorderRecursive(node current){
        if(current==null){
            return;
        }

        inorderRecursive(current.left);
        System.out.print(current.data+" ");
        inorderRecursive(current.right);
    }
}


public class BSTInorder {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Number of Elements you want to Insert");
        int input= sc.nextInt();
        BST tree= new BST();
        for(int i=0;i<input;i++){
            tree.insert(sc.nextInt());
        }
        System.out.print(" Inorder:");
        tree.inorder();

    }
}

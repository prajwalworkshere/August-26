import java.util.*;
class LLClass{
	static class node{
		int data;
		node next;

		node(int data){
			this.data= data;
		}
	}

	// node current;
	node head;
	public void insert(int data){
		node newnode= new node(data);
		if(head==null){
			head=newnode;
			return ;
		}
		node current=head;
		while (current.next!=null) {
			current=current.next;
		}
		current.next=newnode;
		return;
	}

	public void displayDuplicates(){
		if (head==null) {
			System.out.println("LinkedList Is Empty Nothing to Display");
			return;
		}
		node current=head;
		boolean duplicateFound=false;
		while(current!=null){
			int tempData=current.data;
			int count=0;
			node checkNode=head;

			while(checkNode!=null){
				if(checkNode.data==tempData){
					count++;
				}
				checkNode=checkNode.next;
			}

			if (count>1) {
				node previous=head;
				boolean alreadyPrinted=false;

				while(previous!=current){
					if(previous.data==tempData){
						alreadyPrinted=true;
						break;
					}
					previous=previous.next;
				}

			if(!alreadyPrinted){
				System.out.println(tempData+" Repeated "+ count+" Times");
				duplicateFound=true;
			}
		}
		current=current.next;
		}
		if(!duplicateFound){
				System.out.println("No Data Repeated");
		}
	}
}

public class MainClass{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		LLClass LL=new LLClass();
		System.out.println("Enter the no of elements to insert");
		int input=sc.nextInt();
		for(int i=0;i<input;i++){
			LL.insert(sc.nextInt());
		}
		LL.displayDuplicates();
	}
}
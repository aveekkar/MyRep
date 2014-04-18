/*Algo to check if a list has a cycle and give the starting of the cycle...*/

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class CyclicList{
	public static void main(String args[]){
		String s=null;
		String sarr[];
		int[] arr;
		int k=0;
		int start=0;
		System.out.println("enter numbers separated by spaces to create list with those numbers");
		try{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			s=br.readLine();
		}catch(Exception e){
			System.out.println(e.toString());
		}
		
		sarr=s.split(" ");
		arr=new int[sarr.length];
		
		for(String str:sarr){
			arr[k]=Integer.parseInt(str);
			k++;
		}
		
		System.out.println("enter a node number(not the data in the list) to introduce a cycle...to skip enter an integer greater than list size");
		
		try{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			s=br.readLine();
		}catch(Exception e){
			System.out.println(e.toString());
		}
		
		start=Integer.parseInt(s);
		
		Node root=new Node(arr[0],null);
		Node current=root;
		Node temp;
		for(int i=1;i<arr.length;i++){
			temp=new Node(arr[i],null);
			current.next(temp);
			current=temp;
		}
		if(start<=arr.length){
			temp=root;
			for(int i=0;i<start-1;i++){
				temp=temp.next();
			}
			current.next(temp);
		}
		
		//display(root);
		//The actual method calls..
		if(hasCycle(root)){
			System.out.println("cycle starts at "+cycleStart(root));
		}
		else{
			System.out.println("no cycles are present");
		}
	}
	
	public static void display(Node root){
		while(root!=null){
			System.out.print(root.val()+" ");
			root=root.next();
		}
	}
	
	public static boolean hasCycle(Node root){
		Node n1=root;
		Node n2=root;
		
		while(n2.next()!=null){
			n1=n1.next();
			n2=n2.next();
			if(n2.next()!=null){
				n2=n2.next();
			}
			if(n1==n2){
				return true;
			}
		}
		
		return false;
	}
	
	public static int cycleStart(Node root){
		Node n1=root;
		Node n2=root;
		while(n2.next()!=null){
			n1=n1.next();
			n2=n2.next().next();
			
			if(n1==n2){
				break;
			}
		}
		
		n1=root;
		
		while(n1!=n2){
			n1=n1.next();
			n2=n2.next();
		}
		
		return n2.val();
	}
}

class Node{
	protected int val;
	protected Node next=null;
	
	public Node(int val,Node next){
		this.val=val;
		this.next=next;
	}
	
	public Node next(){
		return this.next;
	}
	
	public void next(Node next){
		this.next=next;
	}
	
	public int val(){
		return this.val;
	}
}

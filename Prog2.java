import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class Prog2 {

	
	public static void main(String[] args) {
		try{
		Node a=get_list();
		a=sort(a);
		System.out.println("------------sorted-----------");
		print_list(a);
		System.out.println("-----------------------------");
		Node b=get_list();
		b=sort(b);
		System.out.println("-------------sorted----------");
		print_list(b);
		System.out.println("-----------------------------");
		System.out.println("starting merge");
		Node z=merge(a,b);
		System.out.println("________after merge_________");
		print_list(z);
		System.out.println("____________________________");
		System.out.println("___________reverse___________");
		Node r=reverse(z);
		print_list(r);
		System.out.println("____________________________");
		}catch(Exception e){System.out.println(e.toString());}
		
	}
	public static Node sort(Node l){
		if(l.get_next()!=null){
			Node x=halve(l);
			return merge(sort(l),sort(x));
		}
		else{
			return l;
		}
		
	}
	
	public static Node halve(Node l){
		Node temp=l;
		Node prev=temp;
		while(l.get_next()!=null){
			prev=temp;
			temp=temp.get_next();
			l=l.get_next();
			if(l.get_next()!=null){
				l=l.get_next();
			}
		}
		prev.set_next(null);
		return temp;
	}
	
	public static Node merge(Node a,Node b){
		if(a==null){
			print_list(b);
			return b;
		}
		else if(b==null){
			print_list(a);
			return a;
		}
		else{
			if(a.get_val()>=b.get_val()){
				b.set_next(merge(b.get_next(),a));
				print_list(b);
				return b;
			}
			else{
				a.set_next(merge(a.get_next(),b));
				print_list(a);
				return a;
			}
		}
	}
	
	public static Node get_list() throws IOException{
		
		System.out.println("to make a list enter the numbers with spaces");
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String str=br.readLine();
		String[] tmp=str.split(" ");
		int arr[]=new int[tmp.length];
		for(int i=0;i<tmp.length;i++){
			arr[i]=Integer.parseInt(tmp[i]);
		}
		
		Node start=new Node(arr[0],null);
		Node current=null;
		Node prev=start;
		
		for(int i=1;i<arr.length;i++){
			current=new Node(arr[i],null);
			prev.set_next(current);
			prev=current;
		}
		return start;
	}
	
	public static void print_list(Node start){
		
		while(start!=null){
			System.out.print(start.get_val()+" ");
			start=start.get_next();
		}
		System.out.println();
	}
	
	public static Node reverse(Node l){
		Node current=l;
		Node prev;
		Node next;
		next=current.get_next();
		current.set_next(null);
		prev=current;
		current=next;
		while(current!=null){
			next=current.get_next();
			current.set_next(prev);
			prev=current;
			current=next;
			
		}
		return prev;
	}

}




class Node{
	private int val;
	private Node next;
	
	public Node(int val,Node next){
		this.val=val;
		this.next=next;
	}
	
	public void set_next(Node nxt){
		this.next=nxt;
	}
	
	public Node get_next(){
		return this.next;
	}
	
	public void set_val(int val){
		this.val=val;
	}
	
	public int get_val(){
		return this.val;
	}
	
	
}




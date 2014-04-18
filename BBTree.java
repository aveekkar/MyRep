import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;

class Tree{
	private int val;
	private Tree left=null;
	private Tree right=null;
	
	public int get_val(){
		return this.val;
	}
	
	public Tree get_left(){
		return this.left;
	}
	
	public Tree get_right(){
		return this.right;
	}
	
	public void set_val(int val){
		this.val=val;
	}

	public void set_left(Tree left){
		this.left=left;
	}
	
	public void set_right(Tree right){
		this.right=right;
	}
}


public class BBTree{
	public static void main(String[] args){
		System.out.println("enter the sorted array");
		String s=null;
		try{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			s=br.readLine();
		}catch(Exception e){}
		String[] sarr=s.split(" ");
		int[] arr=new int[sarr.length];
		for(int i=0;i<sarr.length;i++){
			arr[i]=Integer.parseInt(sarr[i]);
		}
		
		Tree root=new Tree();
		makeTree(arr,0,arr.length-1,root);
		Queue<Tree> q=new LinkedList<Tree>();
		breadthFirst(root,q);
		
	}
	public static void makeTree(int[] arr,int start,int end,Tree t){
		if((end>start)){
			int mid=(end+start)/2;
			t.set_val(arr[mid]);
			System.out.println(t.get_val()+"@...");
			Tree lft=new Tree();
			Tree rght=new Tree();
			t.set_left(lft);
			t.set_right(rght);
			makeTree(arr,start,mid-1,lft);
			makeTree(arr,mid+1,end,rght);
		}
		else if(end==start){
			t.set_val(arr[start]);
			System.out.println(t.get_val()+"@ leaf");
		}
		
	}
	
	public static void breadthFirst(Tree t,Queue q){
		q.offer(t);
		while(!q.isEmpty()){
			Tree temp=(Tree)q.poll();
			System.out.print(temp.get_val()+" ");
			if(temp.get_left()==null&&temp.get_right()==null){
				continue;
			}
			else{
				if(temp.get_left()!=null){
					q.offer(temp.get_left());
				}
				if(temp.get_right()!=null){
					q.offer(temp.get_right());
				}
			}
			System.out.println();
		}
		
	}
	
	
}

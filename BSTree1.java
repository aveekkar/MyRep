import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;

class BSTree{
	int val;
	BSTree left=null;
	BSTree right=null;
	
	public void create_node(int val){
		if(val>this.val){
			if(this.right==null){
				BSTree node=new BSTree();
				node.set_val(val);
				this.right=node;
			}
			else{
				this.right.create_node(val);
			}
		}
		else{
			if(this.left==null){
				BSTree node=new BSTree();
				node.set_val(val);
				this.left=node;
			}
			else{
				this.left.create_node(val);
			}
			
		}
	}
	
	public void set_val(int val){
		this.val=val;
	}
	
	public int get_val(){
		return this.val;
	}
	
	public void set_left(BSTree left){
		this.left=left;
	}
	
	public void set_right(BSTree right){
		this.right=right;
	}
	
	public BSTree get_left(){
		return this.left;
	}
	
	public BSTree get_right(){
		return this.right;
	}
}


public class BSTree1{
	public static void main(String[] args){
		System.out.println("entr the list of numbers");
		String s=null;
		try{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			s=br.readLine();
		}catch(Exception e){
			System.out.println("Exception:- IO");
		}
		
		String[] sarr=s.split(" ");
		int[] arr=new int[sarr.length];
		int j=0;
		for(String str:sarr){
			arr[j]=Integer.parseInt(str);
			j++;
		}
		BSTree root=new BSTree();
		root.set_val(arr[0]);
		for(int i=1;i<arr.length;i++){
			root.create_node(arr[i]);
		}
		
		Queue<BSTree> q=new LinkedList<BSTree>();
		breadthFirst(root,q);
	}
	
	public static void breadthFirst(BSTree t,Queue q){
		q.offer(t);
		while(!q.isEmpty()){
			BSTree temp=(BSTree)q.poll();
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

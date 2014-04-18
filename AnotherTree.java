public class AnotherTree{
	public static void main(String args[]){
		Tree root=new Tree(20,new Tree(6,new Tree(8,null,null),new Tree(11,new Tree(3,null,null),new Tree(3,null,null))),new Tree(90,null,new Tree(0,new Tree(121,null,null),new Tree(65,null,null))));
		System.out.println(root.common().val);
	}
}

class Tree{
	public int val;
	public Tree left;
	public Tree right;
	
	public Tree(int val,Tree left,Tree right){
		this.val=val;
		this.left=left;
		this.right=right;
	}
	
	public Tree common(){
		return commonHelper(this,this.left!=null?this.left:null,this.right!=null,this.right:null);
	}
	
	public static Tree commonHelper(Tree parent,Tree currLeft,Tree currRight){
		return null;
	}
}

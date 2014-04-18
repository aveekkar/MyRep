public class In2{
	public static void main(String args[]){
		A b=new B(100);
		b.getA();
		
	}
}


class A{
	protected int a;
	public A(int a){
		this.a=a;
	}
	
	private void setA(int a){
		this.a=a;
	}
	
	public void getA(){
		System.out.println("a in A "+a);
	}
}


class B extends A{
	public B(int a){
		super(a);
	}
	
	public void setA(int a){
		this.a=a;
	}
	
	public void getA(){
		super.getA();
		System.out.println("a in B "+a);
	}
}

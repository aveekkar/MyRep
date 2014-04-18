public class In1{
	public static void main(String[] args){
		Derived derived=new Derived();
		Change change=new Change();
		change.changeFinal(20);
		System.out.println("after change: "+change.getFinalChanged());
		System.out.println("static test: "+WithStatic.i);
	}
}

class Base{
	public Base(int a){
		System.out.println("in base");
	}
}

class Derived extends Base{
	public Derived(){
		super(10);
		System.out.println("in derived");
	}
}

class FinalCheck{
	public int data;
	
	public FinalCheck(int data){
		this.data=data;
	}
	
	public void setData(int data){
		this.data=data;
	}
}

class Change{
	final FinalCheck f=new FinalCheck(10);
	
	public void changeFinal(int data){
		f.setData(20);
	}
	
	public int getFinalChanged(){
		return f.data;
	}
}

class WithStatic{
	public static int i=1000;
	
	static{
		System.out.println("??");
	}
}


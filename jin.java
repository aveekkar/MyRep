import java.util.Random;


public class jin{
	public static void main(String[] args){
		int r;
		Child ob=new Child();
		ob.meth1();
		Random random=new Random();
		for(int i=0;i<50;i++){
			r=random.nextInt(6-0) + 0;
			System.out.println(r);
		}
		
	}
}

class Parent{
	public void meth1(){
		System.out.println("in parent meth1");
		over();
	}
	
	public void over(){
		System.out.println("parent over");
	}
}

class Child extends Parent{
	public void over(){
		System.out.println("child over");
	}
}


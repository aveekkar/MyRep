import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class SumList{
	public static void main(String args[]){
		System.out.println("enter first num as digits with spaces");
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String input1=null;
		String input2=null;
		try{
			input1=br.readLine();
			input2=br.readLine();
		}catch(Exception e){
			System.err.println(e.toString());
		}
		MyList<Integer> one=null;
		MyList<Integer> two=null;
		if(input1!=null){
			String arr[]=input1.split("(\\s+)");
			for(String s:arr){
				MyList<Integer> temp=new MyList<Integer>(Integer.parseInt(s));
				temp.setNext(one);
				one=temp;
			}
		}
		
		if(input2!=null){
			String arr[]=input2.split("(\\s+)");
			for(String s:arr){
				MyList<Integer> temp=new MyList<Integer>(Integer.parseInt(s));
				temp.setNext(two);
				two=temp;
			}
		}
		
		MyList<Integer> result=add(one,two);
		
		while(result.getNext()!=null){
			System.out.print(result.getVal()+" ");
		}
		
		System.out.println();
	}
	
	public static MyList<Integer> add(MyList<Integer> one,MyList<Integer> two){
		if(one==null && two==null){
			return null;
		}
		else{
			return null;
		}
	}
}


class MyList<T>{
	private T val;
	private MyList<T> next;
	
	public MyList(T val){
		this.val=val;
		this.next=null;
	}
	
	public void setNext(MyList<T> next){
		this.next=next;
	}
	
	public MyList<T> getNext(){
		return this.next;
	}
	
	public void modVal(T val){
		this.val=val;
	}
	
	public T getVal(){
		return this.val;
	}
}

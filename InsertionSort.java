import java.io.BufferedReader;
import java.io.InputStreamReader;

public class InsertionSort{
	public static void main(String []args){
		String s=null;
		String sarr[];
		int[] arr;
		int k=0;
		System.out.println("enter numbers to create array");
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
		
		inSort(arr);
		
		for(int a:arr){
			System.out.print(a+" ");
		}
	}
	
	public static void inSort(int[] arr){
		int key;
		int j;
		for(int i=1;i<arr.length;i++){
			key=arr[i];
			j=i-1;
			while(j>=0&&arr[j]>=key){
				arr[j+1]=arr[j];
				j--;
			}
			arr[j+1]=key;
		}
		
	}
}

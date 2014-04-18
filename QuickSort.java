import java.io.BufferedReader;
import java.io.InputStreamReader;

public class QuickSort{
	public static void main(String[] args){
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
		
		quickSort(arr,0,arr.length-1);
		
		for(int u:arr){
			System.out.print(u+" ");
		}
		
		System.out.println();
		
		
	}
	
	public static void quickSort(int[] a,int start,int end){
		if(start<end){
			int q=partition(a,start,end);
			quickSort(a,start,q-1);
			quickSort(a,q+1,end);
		}
	}
	
	public static int partition(int[] a,int start,int end){
		int x=a[end];
		int i=start-1;
		int temp=0;
		
		for(int j=start;j<end;j++){
			if(a[j]<=x){
				i += 1;
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		temp=a[i+1];
		a[i+1]=a[end];
		a[end]=temp;
		return i+1;
	}
}

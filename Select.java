import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Random;

public class Select{
	public static void main(String []args){
		String s=null;
		String sarr[];
		int[] arr;
		int k=0;
		int t=0;
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
		System.out.println("entr the ..th index");
		try{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			s=br.readLine();
		}catch(Exception e){
			System.out.println(e.toString());
		}
		t=Integer.parseInt(s);
		int res=select(arr,0,arr.length-1,t);
		
		for(int i=0;i<=res;i++){
			System.out.print(arr[i]+" ");
		}
		System.out.println();
	}
	
	public static int select(int[] arr,int start,int end,int i){
		if(start==end){
			return start;
		}
		int q=randPartition(arr,start,end);
		int k=q-start+1;
		if(i==k){
			return q; 
		}
		else if(i>k){
			return select(arr,q+1,end,i-k); //recurse left
		}
		else{
			return select(arr,start,q-1,i); //recurse right
		}
	}
	
	public static int randPartition(int[] arr,int start,int end){
		Random random=new Random();
		int r=random.nextInt(end+1-start) + start;
		int temp=arr[end];
		arr[end]=arr[r];
		arr[r]=temp;
		return partition(arr,start,end);
		
	}
	
	public static int partition(int[] a,int start, int end){
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

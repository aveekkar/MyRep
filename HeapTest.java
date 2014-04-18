import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class HeapTest{
	public static void main(String args[]){
		int i=0;
		System.out.println("enter the numbers to create list");
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String input=null;
		try{
			input=br.readLine();
		}catch(IOException e){
			System.err.println(e.toString());
		}
		String inpArray[]=input.split(" ");
		int[] intInput=new int[inpArray.length];
		for(String s:inpArray){
			intInput[i]=Integer.parseInt(s.trim());
			i++;
		}
		System.out.println();
		System.out.println(" -------------------------------");
		
		Heap heap=new Heap(intInput);
		heap.printHeap();
		
		for(i=0;i<3;i++){
			heap.insert((-24)*(5+i));
			System.out.println("inserting: "+(-24)*(5+i));
		}
		
		heap.printHeap();
		
		while(!heap.isEmpty()){
			System.out.print("top: "+heap.getTop()+" ");
		}
		System.out.println();
	}
	
}

class Heap{
	ArrayList<Integer> mInput=new ArrayList<Integer>();
	
	public Heap(int[] iInput){
		for(int i=0;i<iInput.length;i++){
			mInput.add(iInput[i]);
		}

		for(int i=(mInput.size()-1)/2;i>=0;i--){
			minHeapify(i);
		}
	}
	
	public void printHeap(){
		for(int i:mInput){
			System.out.print(i+" ");
		}
		System.out.println();
	}
	
	private void minHeapify(int index){
		int leftIndex=leftChildIndex(index);
		int rightIndex=rightChildIndex(index);
		int minIndex=index;
		
		if((leftIndex<=(mInput.size()-1)) && mInput.get(minIndex)>=mInput.get(leftIndex)){
			minIndex=leftIndex;
		}
		if((rightIndex<=(mInput.size()-1)) && mInput.get(minIndex)>=mInput.get(rightIndex)){
			minIndex=rightIndex;
		}
		if(minIndex!=index){
			int temp=mInput.get(index);
			mInput.set(index,mInput.get(minIndex));
			mInput.set(minIndex,temp);
			minHeapify(minIndex);
		}
	}
	
	private int leftChildIndex(int index){
		return (2*index)+1;
	}
	
	private int rightChildIndex(int index){
		return (2*index)+2;
	}
	
	public void insert(int elem){
		mInput.add(elem);
		percolate(mInput.size()-1);
	}
	
	public int getTop(){
		int ret=mInput.get(0);
		mInput.set(0,mInput.get(mInput.size()-1));
		mInput.remove(mInput.size()-1);
		minHeapify(0);
		return ret;
	}
	
	public boolean isEmpty(){
		return mInput.isEmpty();
	}
	
	private int parentIndex(int index){
		return index%2==0?((index-1)/2):index/2;
	}
	
	private void percolate(int index){
		int parent=parentIndex(index);
		System.out.println("index="+index+" parent="+parent);
		if(parent>=0 && mInput.get(parent)>mInput.get(index)){
			int temp=mInput.get(parent);
			mInput.set(parent,mInput.get(index));
			mInput.set(index,temp);
			percolate(parent);
		}
	}
}











template <class T>
void swap(T *a, T *b)
{
	T t;

	t=*a;
	*a=*b;
	*b=t;

}

template <class T>
void bubbleSort(T a[], int n)
{   
    for (int i = 0; i < n-1; i++)      // Last i elements are already in place  
    	for (int j = 0; j < n-i-1; j++)  
        	if (a[j] > a[j+1])  
            	swap(&a[j], &a[j+1]);  
}  


int  main(void)
{
	 int s=5;
     int *p=new int[s];

     for(int i=0;i<s;i++)
     {
     	cout<<"Enter"<<i<<" th array value :";
     	cin>>p[i];
     }

     bubbleSort(p,s);

     for(int i=0;i<s;i++)
     	cout<<i<<" th value of sorted array:"<<p[i]<<endl;
   //-------------------------------------------------
     //int s=5;
     float *q=new float[s];

     for(int i=0;i<s;i++)
     {
     	cout<<"Enter"<<i<<" th array value :";
     	cin>>q[i];
     }

     bubbleSort(q,s);

     for(int i=0;i<s;i++)
     	cout<<i<<" th value of sorted array:"<<q[i]<<endl;


}
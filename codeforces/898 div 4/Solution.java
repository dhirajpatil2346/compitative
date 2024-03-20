public class Solution {

    public static int largestRectangleArea(int[] A) {
    
        int n=A.length;
    
        int []l=new int[n];
    
        int []r=new int [n];
    
        Arrays.fill(l,-1);
    
        Arrays.fill(r,n);
    
        Stack<Integer> s= new Stack<>();
    
        for(int i=0;i<n;i++)
        {
            while(s.size()>0&&A[s.peek()]>=A[i])
            {
    
                 s.pop();
            }
            if(s.size()>0)
            {
        
                l[i]=s.peek();
        
            }
        
            s.push(i);
    
        }
    
        while(s.size()>0)
        {
        
            s.pop();
        
        }
        
        
        for(int i=n-1;i>=0;i--)
        {
        
            while(s.size()>0&&A[i]>=A[s.peek()])
            {
        
                s.pop();
        
            }
        
            if(s.size()>0)
            {
            
                r[i]=s.peek();
            
            }
            
            s.push(i);
        
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
        
            int k=A[i]*(r[i]-l[i]-1);
            
            ans=Math.max(ans,k);
        
        }
    
        return ans;
    
    }
    public static void main(String []args)
    {
        int n = 10;
        int A[] = { 90, 58, 69, 70, 82, 100, 13, 57, 47, 18};
        System.out.println(largestRectangleArea(A));
    }
}
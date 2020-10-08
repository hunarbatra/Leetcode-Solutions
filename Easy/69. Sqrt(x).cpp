class Solution {
public:
    int mySqrt(int x) { //O(n)
     /*   if(x==1) return 1;
         for(long long int i=1;i<=x;i++)
        {
            if(i*i>x)
                return i-1;
        }
        return 0; //Can we do better? this is O(n) rn. */
        //e.g. 4---> 1,2,3,4,5,6,7,8,9....x 
                   //0,0,1,2,2,2,2,2,3..... */
        //Lets use binary search as this is more like a parition problem type so to achieve a RT of O(log n)
        if(x==0) return 0;
        long start=1, end=x;
        while(start<=end)
        {
            long middle = (start+end)/2;
            if(middle*middle==x) return middle;
            if(middle*middle<x) start=middle+1;
            else {end=middle-1;}
        }
        return start-1; //start points right next to the answer, hence, we return start-1
    }
};

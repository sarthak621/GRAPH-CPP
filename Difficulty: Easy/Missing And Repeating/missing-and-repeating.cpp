class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        long long n=arr.size();
        long long N=n;
        
        long long arrSum=0;
        long long arr_sqSum=0;
        
        for(long long i=0;i<n;i++){
            arrSum+=arr[i];
            arr_sqSum +=1LL *arr[i]*arr[i];
        }
        
        long long sum=1LL *(N*(N+1))/2; //sum of N natural no.
        long long sqSum=1LL * (N*(N+1)*((2*N)+1))/6; // sq sum of N natural no.
        
        long long sumDiff=arrSum-sum;
        long long sqSumDiff=arr_sqSum-sqSum;
        
        long long a=(sumDiff + (sqSumDiff/sumDiff))/2;
        long long b=((sqSumDiff/sumDiff) - sumDiff )/2;

        return {a,b};
    }
};


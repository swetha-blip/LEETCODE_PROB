int maxSubArray(int* nums, int numsSize){
    int maxsum=nums[0];
    int maxsumsofar=0;
    for(int i=0;i<numsSize;i++)
    {
        maxsumsofar+=nums[i];

        if(maxsum<maxsumsofar){
            maxsum=maxsumsofar;
        }
        if(maxsumsofar<0)
        maxsumsofar=0;
    }

return maxsum;
}
// https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1#

class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n)
    {
        reverse(arr, arr+n);//reverse the whole array
        
        reverse(arr, arr+n-d); //first reversing n-d elements from starting index
        
        reverse(arr+n-d, arr+n); //then reversing last n-d index.
    }
};

class Solution {
    public int mostWordsFound(String[] sentences) {
        int[] result = new int[sentences.length];
        for(int i = 0; i < sentences.length; i++){
            result[i] = sentences[i].split("\\s").length;
        }
        return getmax(result,sentences.length);
    }
    static int getmax(int arr[], int n){
       if(n==1)
       return arr[0];

       return Math.max(arr[n-1], getmax(arr, n-1));
   }
}
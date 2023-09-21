class Solution {
    public boolean checkIfPangram(String sentence) {
        int[] ascii = new int[256];
        for(char c : sentence.toCharArray()){
            ascii[c]++;
        }
        for(int i = 97; i <= 122; i++){
            if(ascii[i] == 0) return false;
        }
        return true;
    }
}

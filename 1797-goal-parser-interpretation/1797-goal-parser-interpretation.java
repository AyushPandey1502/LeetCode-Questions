class Solution {
    public String interpret(String command) {
        StringBuilder result = new StringBuilder(command.length());
        for(int i = 0; i < command.length(); i++){
            if(command.charAt(i) == 'G') result.append('G');
            if(command.charAt(i) == '('){
                if(command.charAt(i+1) == ')') {result.append('o'); i++;}
                else{result.append("al"); i+=3;}
            }
        }
        return result.toString();
    }
}
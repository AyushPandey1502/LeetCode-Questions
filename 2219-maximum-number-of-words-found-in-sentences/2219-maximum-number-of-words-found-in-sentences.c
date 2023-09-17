int mostWordsFound(char ** sentences, int sentencesSize){
    int maxLen = 0;
    for(int i = 0; i < sentencesSize; i++){
        int counter = 0;
        for(int count = 0; sentences[i][count] != '\0'; count++){
            if(sentences[i][count] == ' '){
                counter++;
            }
        }
        if(maxLen < counter){
            maxLen = counter;
        }
    }
    return maxLen + 1;
}
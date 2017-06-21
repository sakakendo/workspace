class Main{
    public static void main(String args[]){
        int memory[]=new int[3000];
        int mptr=0;
        String program="+++++++++++[>++++++++++++<-].";
        char[] p=program.toCharArray();
        for(int pptr=0;pptr<program.length();pptr++){
          System.out.println(p[pptr]);
          if(p[pptr]=='+'){
            memory[mptr]++;
          }else if(p[pptr]=='>'){
            mptr++;
          }else if(p[pptr]=='.'){
            System.out.println(memory[mptr]);  
          }
        } 


//        System.out.println(args[0]);
    }
}

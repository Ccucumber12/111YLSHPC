import java.util.Scanner ;

class pA{  
    public static void main(String args[]){  
        int n, c ;
        Scanner stdin = new Scanner(System.in) ;
        n = stdin.nextInt() ;
        c = stdin.nextInt() ;

        for (int i=0; i<n; ++i) {
            int k = stdin.nextInt() ;
            System.out.print(Math.min(100, k+c) + " ") ;
        }
    }  
}  
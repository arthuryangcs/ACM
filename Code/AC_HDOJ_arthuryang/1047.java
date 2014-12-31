////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-12-27 13:52:01
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1047
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:4996KB
//////////////////System Comment End//////////////////
import java.util.Scanner;  
import java.math.BigInteger;  
  
public class Main {  
  
    /** 
     * @param args 
     */  
    public static void main(String[] args) {  
        // TODO Auto-generated method stub  
        Scanner scanner=new Scanner(System.in);  
        int n;  
        BigInteger m,sum;  
            n=scanner.nextInt();  
            for(int i=1;i<=n;i++){  
                sum=BigInteger.ZERO;  
                while(scanner.hasNextBigInteger()){  
                    m=scanner.nextBigInteger();  
                    if(m.equals(BigInteger.ZERO))  
                    //if(m.intValue()==0)  
                        break;  
                    sum=sum.add(m);  
                }  
                System.out.println(sum);  
                if(i<n)  
                    System.out.println();  
            }  
        }  
  
} 
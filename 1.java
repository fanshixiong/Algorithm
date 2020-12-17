import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回在所有合法的三角形的组成中，最大的三角形的周长减去最小的三角形的周长的值
     * @param n int整型 代表题目中的n
     * @param a int整型一维数组 代表n个数的大小
     * @return int整型
     */
    public int solve (int n, int[] a) {
        // write code here
        Arrays.sort(a);
        int s1=  0;
        int s2 = 0;
        int ct=  0;
        for(int i=a.length-3;i>=0;--i){
            if(a[i]+a[i+1]>a[i+2]){
                ct++;
                if(s1==0){
                    s1 = a[i] + a[i+1] + a[i+2];
                }else{
                    s2 = a[i] + a[i+1] + a[i+2];
                }
            }
        }
        if(ct==1){
            return 0;
        }
        return s1-s2;
        
        
    }

    public static void main(){
        int []a = [1];
        System.out.println(solve(1, a));
    }
}
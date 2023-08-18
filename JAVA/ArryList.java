import java.util.*;
public class ArryList {
    public static void main(String[] args){
        ArrayList<String> voucherName = new ArrayList<>();
        ArrayList<String> voucherDate = new ArrayList<>(3);
        voucherName.add("收款凭证001");
        voucherName.add("收款凭证002");
        voucherDate.add("2013/07/06");
        voucherDate.add("2013/07/07");
        voucherDate.add("2013/07/08");	
        voucherDate.add("2013/07/09");
        System.out.println(voucherName);
        System.out.println(voucherDate);
        if(voucherDate.contains("2013/07/09")){
            System.out.println("存在");
        }
    }
}

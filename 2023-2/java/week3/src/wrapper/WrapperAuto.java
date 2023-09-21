package wrapper;

public class WrapperAuto {

    public static void main(String[] args){

        Float obj;
        float f1 = 100.10f;
        obj = f1;

        Float num = Float.valueOf("12.33"); //autoBoxing
        Integer intNum = Integer.valueOf("12");
        Integer test = Integer.valueOf(12);

        System.out.println(obj);
        System.out.println(num);
        System.out.println(intNum);
        System.out.println(test);

        System.out.println("Unboxing: " + intNum.intValue());
    }
}

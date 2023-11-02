package exercise;

class ComputeInt {

    int compute(int i) {
        return i;
    }
}

class ComputeFloat extends ComputeInt {

    float compute(float i) {
        return i;
    }
}

public class Ex4 {

    public static void main(String[] args){
        ComputeFloat compute = new ComputeFloat();
        System.out.println(compute.compute(10));
        System.out.println(compute.compute(10.6f));
    }
}

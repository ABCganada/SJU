package week12;

import java.io.FileWriter;
import java.io.IOException;

public class Q4 {

    public static void main(String[] args) throws IOException {

        try {
            FileWriter fw = new FileWriter("writeTest.txt");

            fw.write("This is java class");
            fw.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}

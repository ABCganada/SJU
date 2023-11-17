package file;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;

public class MultipleLines {

    public static void main(String[] args) throws IOException {
        InputStream f = new FileInputStream("/Users/abcganada/SJU/2023-2/java/week11/test1.txt");
        Scanner sc = new Scanner(f);

        while (sc.hasNextLine()) {
            System.out.println(sc.nextLine());
        }

    }
}

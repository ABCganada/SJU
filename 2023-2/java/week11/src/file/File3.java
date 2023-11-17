package file;

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class File3 {

    public static void main(String[] args) {
        File f = new File("/Users/abcganada/SJU/2023-2/java/week11/test333.txt");

        try {
            f.createNewFile();
            FileWriter fw = new FileWriter(f);
            String str;
            Scanner sc = new Scanner(System.in);
            str = sc.nextLine();
            fw.write(str);
            fw.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

    }
}

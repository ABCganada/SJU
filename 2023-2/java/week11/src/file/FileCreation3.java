package file;

import java.io.File;
import java.io.IOException;

public class FileCreation3 {

    public static void main(String[] args) {

        File f = new File("/Users/abcganada/SJU/2023-2/java/week11/testCreation3.txt");
        try {
            f.createNewFile();
            if (f.exists()) {
                System.out.println("file is created");
            }
        } catch (IOException e) {
            System.out.println("File Exception");
        }
    }
}

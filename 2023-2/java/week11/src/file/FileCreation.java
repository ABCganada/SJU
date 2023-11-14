package file;

import java.io.File;
import java.io.IOException;

public class FileCreation {

    public static void main(String[] args) throws IOException {
        File f1 = new File("/Users/abcganada/SJU/2023-2/java/week11/testCreation.txt");
        f1.createNewFile();
        System.out.println(f1.exists());
    }
}

package file;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class FileWrite {

    public static void main(String[] args) throws IOException {
        File f = new File("/Users/abcganada/SJU/2023-2/java/week11/test3.txt");
        FileWriter fw = new FileWriter(f);

        fw.write("This is a Java class");
        fw.close();
    }
}

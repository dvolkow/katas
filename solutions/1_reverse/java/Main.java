import java.io.*;
import java.io.IOException;

public class Main {

    public static String reverseIt(String source) {
        int i, len = source.length();
        StringBuilder dest = new StringBuilder(len);

        for (i = (len - 1); i >= 0; i--) {
            dest.append(source.charAt(i));
        }

        return dest.toString();
    }

    public static void main(final String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = "";
        try {
            s = br.readLine();
        }
        catch (IOException e)
        { }
        System.out.println(reverseIt(s));
    }
}

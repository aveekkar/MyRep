import java.net.*;
import java.io.*;

public class JGet {
    public static void main (String[] args) throws IOException {
        try {
            URL url = new URL("https://facebook.com");
    
            BufferedReader in = 
                new BufferedReader(new InputStreamReader(url.openStream()));
            String str;

            while ((str = in.readLine()) != null) {
                System.out.println(str);
            }

            in.close();
        } 
        catch (MalformedURLException e) {} 
        catch (IOException e) {}
    }
}

import javafx.util.Pair;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.*;


import java.io.*;


public class Main {

    /**
     *  This function call the web site and parse the input znd the output
     * @param problem the url of the problem
     * @return
     */
    public static Pair<String,String>[] getSimpleTestes(String problem){
        Document doc = null;
        try {
            doc = Jsoup.connect(problem).get();
            Elements newsHeadlines;

            Elements inputs = doc.select(".input");
            Elements outputs=doc.select(".output");
            Element input = null,output = null;
            int n = inputs.size();
            Pair<String,String> result[] = new Pair[n];
            for(int i=0;i<n;i++){
                input = inputs.get(i);
                output = outputs.get(i);
                result[i] = new Pair<String, String>(input.select("pre").html(),
                        output.select("pre").html());
            }

            return result;

        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    public static File createfile(String path){
        File f = new File(path);
        if(f.exists())
            f.delete();
        try {
            f.createNewFile();
            return f;
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    public static void main(String argv[]) throws IOException {

        if(argv.length!=1){
            System.out.println("Please inter in params de main source & the url of the problem");
        } else {
            Pair<String,String> tests[] = Main.getSimpleTestes(argv[0]);

            File dir = new File("TT");
            if(dir.exists())
                dir.delete();
            dir.mkdir();
            Writer writer;
            File f =Main.createfile("TT/numberofinput");
            writer = new FileWriter(f);
            writer.write(""+tests.length);
            writer.close();
            for(int i=0;i<tests.length;i++){
                File in = Main.createfile("TT/input-"+(i+1));
                File out = Main.createfile("TT/output-"+(i+1));

                writer = new FileWriter(in);
                writer.write(tests[i].getKey());
                writer.close();
                writer = new FileWriter(out);
                writer.write(tests[i].getValue());
                writer.close();
            }

        }

    }
}

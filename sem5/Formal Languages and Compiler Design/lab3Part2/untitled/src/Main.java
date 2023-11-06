import java.io.FileNotFoundException;
import java.io.PrintStream;

public class Main {
    private static void printToFile(String filePath, Object object) {
        try(PrintStream printStream = new PrintStream(filePath)) {
            printStream.println(object);
        }
        catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private static void run(String filePath) {
        Scaner scanner = new Scaner(filePath);
        scanner.scan();
        printToFile(filePath.replace(".txt", "ST.txt"), scanner.getSymbolTable());
        printToFile(filePath.replace(".txt", "PIF.txt"), scanner.getPif());
    }

    public static void main(String[] args) {
        run("inputOutput/p1.txt");
        run("inputOutput/p2.txt");
        run("inputOutput/p3.txt");
        run("inputOutput/peror.txt");
    }
}
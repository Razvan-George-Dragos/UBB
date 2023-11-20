import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.stream.Collectors;
import java.util.regex.Pattern;

public class Scaner {
    private final ArrayList<String> operators = new ArrayList<>(
            List.of("+", "-", "*", "/", "=", "%", "!=", ">", "<", "<=", ">=", "==")
    );
    private final ArrayList<String> separators = new ArrayList<>(
            List.of("{", "}", "[", "]", "(", ")", ":", ";", " ", ",")
    );
    private final ArrayList<String> reservedWords = new ArrayList<>(
            List.of("intero", "float", "bool", "const", "char", "string", "leggere", "scrivere", "qualora", "qualoraFalso", "qualoraFalsoPero", "finoAQuando", "and", "or", "not", "return", "principale")
    );
    private final String filePath;
    private SymbolTable symbolTable;
    private ProgramInternalForm pif;

    public Scaner(String filePath) {
        this.filePath = filePath;
        this.symbolTable = new SymbolTable(100);
        this.pif = new ProgramInternalForm();
    }

    public String readFile() throws FileNotFoundException {
        StringBuilder fileContent = new StringBuilder();
        Scanner scanner = new Scanner(new File(this.filePath));
        while(scanner.hasNextLine()){
            fileContent.append(scanner.nextLine()).append("\n");
        }
        return fileContent.toString().replace("\t", "");

    }
    public ProgramInternalForm getPif(){
        return this.pif;
    }
    public SymbolTable getSymbolTable(){
        return this.symbolTable;
    }

    private List<Pair<String, Pair<Integer,Integer>>> createListOfProgramsElems(){
        try {
            String content = this.readFile();
            String separatorsString = this.separators.stream().reduce("", (a,b)->(a+b));
            StringTokenizer tokenizer = new StringTokenizer(content, separatorsString, true);
            List<String> tokens = Collections.list(tokenizer)
                    .stream()
                    .map(t->(String) t)
                    .collect(Collectors.toList());
            return tokenize(tokens);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        return null;
    }

    private List<Pair<String, Pair<Integer, Integer>>> tokenize(List<String> tokensToBe){

        List<Pair<String, Pair<Integer, Integer>>> resultedTokens = new ArrayList<>();
        boolean isStringConstant = false;
        boolean isCharConstant = false;
        StringBuilder createdString = new StringBuilder();
        int numberLine = 1;
        int numberColumn = 1;
        for(String t: tokensToBe){
            switch (t) {
                case "\"":
                    if (isStringConstant) {
                        createdString.append(t);
                        resultedTokens.add(new Pair<>(createdString.toString(), new Pair<>(numberLine, numberColumn)));
                        createdString = new StringBuilder();
                    }else {
                        createdString.append(t);
                    }
                    isStringConstant = !isStringConstant;
                    break;
                case "'":
                    if (isCharConstant) {
                        createdString.append(t);
                        resultedTokens.add(new Pair<>(createdString.toString(), new Pair<>(numberLine, numberColumn)));
                        createdString = new StringBuilder();
                    }
                    else {
                        createdString.append(t);
                    }
                    isCharConstant = !isCharConstant;
                    break;
                case "\n":
                    numberLine++;
                    numberColumn = 1;
                    break;
                default:
                    if (isStringConstant) {
                        createdString.append(t);
                    } else if (isCharConstant) {
                        createdString.append(t);
                    } else if (!t.equals(" ")) {
                        resultedTokens.add(new Pair<>(t, new Pair<>(numberLine, numberColumn)));
                        numberColumn++;
                    }
                    break;
            }
        }
        return resultedTokens;
    }

    public void scan(){

        List<Pair<String, Pair<Integer, Integer>>> tokens = createListOfProgramsElems();
        AtomicBoolean lexicalErrorExists = new AtomicBoolean(false);

        if(tokens == null){
            return;
        }

        tokens.forEach(t -> {
            String token = t.getFirst();
            if(this.reservedWords.contains(token)) {
                this.pif.add(new Pair<>(token, new Pair<>(-1, -1)), 2);
            } else if(this.operators.contains(token)){
                this.pif.add(new Pair<>(token, new Pair<>(-1, -1)), 3);
            } else if(this.separators.contains(token)){
                this.pif.add(new Pair<>(token, new Pair<>(-1, -1)), 4);
            } else if(Pattern.compile("^0|[-|+][1-9]([0-9])*|'[1-9]'|'[a-zA-Z]'|\"[0-9]*[a-zA-Z ]*\"$").matcher(token).matches()) {
                this.symbolTable.add(token);
                this.pif.add(new Pair<>("CONST", symbolTable.findPositionOfTerm(token)), 0);
            }
            else if(Pattern.compile("^([a-zA-Z]|_)|[a-zA-Z_0-9]*").matcher(token).matches() || new FiniteAutomaton("inputOutput/FA_integer_constant.txt").acceptsSequence(token)) {
                this.symbolTable.add(token);
                this.pif.add(new Pair<>("IDENTIFIER", symbolTable.findPositionOfTerm(token)), 1);
            }
            else if(new FiniteAutomaton("inputOutput/FA_identifier.txt").acceptsSequence(token)) {
                this.symbolTable.add(token);
                this.pif.add(new Pair<>(token, symbolTable.findPositionOfTerm(token)), 1);
            }
            else {
                Pair<Integer, Integer> pairLineColumn = t.getSecond();
                System.out.println("Error at line: " + pairLineColumn.getFirst() + " and column: " + pairLineColumn.getSecond() + ", invalid token: " + t.getFirst());
                lexicalErrorExists.set(true);
            }
        });

        if(!lexicalErrorExists.get()){
            System.out.println("Program is lexically correct!");
        }
    }
}

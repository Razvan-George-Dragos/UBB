public class Main {
    public static void main(String[] args) {
        SymbolTable symbolTable = new SymbolTable(5);

        symbolTable.add(">");
        System.out.println(symbolTable.containsTerm(">"));
        Pair position = symbolTable.findPositionOfTerm(">");
        System.out.println(position);

        symbolTable.add("false");
        System.out.println(symbolTable.containsTerm("false"));
        System.out.println(symbolTable.findPositionOfTerm("false"));


        symbolTable.add("5");
        System.out.println(symbolTable.containsTerm("5"));
        System.out.println(symbolTable.findPositionOfTerm("5"));

        System.out.println(symbolTable.getHashTable());
    }
}
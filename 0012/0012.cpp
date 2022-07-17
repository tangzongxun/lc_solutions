class Solution {
    static TreeMap<Integer, String> table;
    
    private static TreeMap<Integer, String> buildTable(){
        TreeMap<Integer, String> table = new TreeMap<Integer, String>();
        table.put(1000, "M");
        table.put(900, "CM");
        table.put(500, "D");
        table.put(400, "CD");
        table.put(100, "C");
        table.put(90, "XC");
        table.put(50, "L");
        table.put(40, "XL");
        table.put(10, "X");
        table.put(9, "IX");
        table.put(5, "V");
        table.put(4, "IV");
        table.put(1, "I");
        return table;
    }
    
    static {
        table = buildTable();  
    }

    public String intToRoman(int num) {
        StringBuilder sb = new StringBuilder();
        for(int n : table.descendingKeySet()){
            while(num > 0 && num >= n){
                num -= n;
                sb.append(table.get(n));
            }
        }
        return sb.toString();
    }
}

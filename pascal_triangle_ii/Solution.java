import java.util.ArrayList;
import java.util.List;

/**
 * Created by luxy on 4/14/16.
 */
public class PascalTriangle {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if (numRows <= 0){
            return result;
        }
        for (int i = 0; i < numRows; i++){
            List<Integer> row = new ArrayList<Integer>();
            row.add(1);
            for (int j = 1; j < i; j++){
                List<Integer> preRow = result.get(i-1);
                row.add(preRow.get(j-1) + preRow.get(j));
            }
            if (i > 0){ row.add(1); }
            result.add(row);
        }
        return result;
    }

    public void printTriangle(List<List<Integer>> triangle){
        for (List<Integer> row: triangle){
            for (int a: row){
                System.out.print(a + " ");
            }
            System.out.println();
        }
    }

    public List<Integer> getRow(int rowIndex) {
        List<Integer> row = new ArrayList<Integer>();
        if (rowIndex <= 0){
            return row;
        }
        for (int i = 0; i < rowIndex + 1; i++){
            row.add(0, 1);
            for (int j = 1; j < row.size()-1; j++){
                row.set(j, row.get(j) + row.get(j+1));
            }
        }
        return row;
    }

    public void printRow(List<Integer> row){
        for (int a: row){
            System.out.print(a + " ");
        }
        System.out.println();
    }
}


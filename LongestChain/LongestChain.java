import java.util.*;

public class LongestChain {

    public static void main(String[] args) {
        System.out.println(longest_chain(new String[] {
            "a",
            "b",
            "ba",
            "bca",
            "bda",
            "bdca",
            "asdfghjk",
            "asdfghj",
            "asdfgj",
            "asdfg",
            "sdfg",
            "sdg",
            "dg"
        }));
    }
    
    static Integer longest_chain(String[] w)
    {
        Map<String, Integer> history = new HashMap<String, Integer>();
        
        HashSet<String> set = new HashSet<String>();
        for (int i = 0; i < w.length; i++)
        {
            set.add(w[i]);
        }

        int max = -1;

        for (int i = 0; i < w.length; i++)
        {
            int temp = find(set, history, w[i]);
            if (temp > max)
            {
                max = temp;
            }
        }

        return max;
    }
    
    static int find (HashSet<String> set, Map<String, Integer> history, String word)
    {
        if (history.containsKey(word))
        {
            return history.get(word);
        }

        System.out.println(word);
        int len = word.length();
        int max = 0;

        if (len == 1)
        {
            history.put(word, 1);
            return 1;
        }
        
        for (int i = 0; i < len; i++)
        {
            String subword = word.substring(0, i) +
                (i < len ? word.substring(i + 1) : "");

            if (!set.contains(subword))
            {
                continue;
            }

            int temp = find(set, history, subword);
            if (temp > max)
            {
                max = temp;
            }
        }

        history.put(word, max + 1);
        return max + 1;
    }

}
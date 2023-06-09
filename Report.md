# Sort Analysis Data

## Results Table
Make sure to go out to at least 100,000 (more are welcome), and you have 10 different values (more welcome). You are welcome to go farther, but given 100,000 can take about 20 seconds using a selection sort on a fast desktop computer, and 200,000 took 77 seconds, you start having to wait much longer the more 0s you add. However, to build a clearer line, you will want more data points, and you will find merge and quick are able to handle higher numbers easier (but at a cost you will explore below). 

You are free to write a script to run the program and build your table (then copy that table built into the markdown). If you do that, please include the script into the repo.  Note: merge and quick sorts are going to be explored in the team activity for Module 06. You can start on it now, but welcome to wait.

### Table [^note]
| N | Bubble | Selection | Insertion | Merge | Quick |
| :-- | :--: | :--: | :--: | :--: | :--: |





## BigO Analysis  / Questions

### 1. Build a line chart
Build a line chart using your favorite program. Your X axis will be N increasing, and your Y access will be the numbers for each type of sort. This will create something similar to the graph in the instructions, though it won't be as smooth. Due to speed differences, you may need to break up the $O(\log n)$ and $O(n^2)$ into different charts.

Include the image in your markdown. As a reminder, you save the image in your repo, and use [image markdown].



### 2. Convinced?
Given the direction of the line chart, are you "convinced" of the complexity of each of the sorts? Why or why not?


### 3. Big O
Build another table that presents the best, worst, and average case for Bubble, Selection, Insertion, Merge, and Quick. You are free to use resources for this, but please reference them if you do. 


#### 3.2 Worst Case
Provide example of arrays that generate _worst_ case for Bubble, Selection, Insertion, Merge Sorts


#### 3.3 Best Case
Provide example of arrays that generate _best_ case for Bubble, Selection, Insertion, Merge Sorts 


#### 3.4 Memory Considerations
Order the various sorts based on which take up the most memory when sorting to the least memory. You may have to research this, and include the mathematical notation. 

### 4. Growth of Functions
Give the following values, place them correctly into *six* categories. Use the bullets, and feel free to cut and paste the full LatexMath we used to generate them.  

$n^2$  
$n!$  
$n\log_2n$  
$5n^2+5n$  
$10000$  
$3n$    
$100$  
$2^n$  
$100n$  
$2^{(n-1)}$
#### Categories
* $100$, $10000$  
* $3n$, $100n$ 
* $n\log_2n$
* $n^2$, $5n^2+5n$ 
* $2^n$, $2^{(n-1)}$
* $n!$  

### 5. Growth of Function Language

Pair the following terms with the correct function in the table. 
* Constant, Logarithmic, Linear, Quadratic, Cubic, Exponential, Factorial

| Big $O$     |  Name  |
| ------      | ------ |
| $O(n^3)$    |  Cubic |
| $O(1)$      |  Constant |
| $O(n)$      |  Linear |
| $O(\log_2n)$ | Logarithmic  |
| $O(n^2)$    |  Quadratic |
| $O(n!)$     | Factorial  |
| $O(2^n)$    |  Exponential |


### 6. Stable vs Unstable
Look up stability as it refers to sorting. In your own words, describe one sort that is stable and one sort that isn't stable  

One example of a stable sorting algorithm is Insertion Sort. In Insertion Sort, elements are iteratively inserted into their correct position in the sorted portion of the array. When we meet elements with equal keys, the algorithm compares their positions and ensures that the one appearing first in the original array remains first in the sorted array. This makes Insertion Sort stable.[1]

One example of an unstable sorting algorithm is Quick Sort. Quick Sort divides the array into partitions based on a pivot element and recursively sorts the partitions. The partitioning process does not guarantee the relative order of elements with equal keys. As a result, the final sorted sequence may not maintain the original order of elements with equal keys, making Quick Sort an unstable algorithm.[2]

### 6.2 When stability is needed?
Explain in your own words a case in which you will want a stable algorithm over an unstable. Include an example. 

Below is an explanation of a case where a stable sorting algorithm is preferred over an unstable one. [3]

Let's consider a case where we have a dataset containing student records with their names and corresponding scores. We need to sort the records based on the scores in ascending order. However, there might be cases where multiple students have the same score. In this case, maintaining the original order of the students with the same score becomes important. Here, a stable sorting algorithm is preferred over an unstable one because it ensures that students who obtained the same score are sorted based on their original order.

Let's illustrate this with an example:

Suppose we have the following dataset of student records:

| Student Name | Score |
|--------------|-------|
| John         | 85    |
| Emma         | 78    |
| Alex         | 85    |
| Sarah        | 92    |
| Michael      | 78    |
| Lily         | 92    |

If we sort this dataset based on scores using a stable sorting algorithm like Insertion Sort, the result would be:

| Student Name | Score |
|--------------|-------|
| Emma         | 78    |
| Michael      | 78    |
| John         | 85    |
| Alex         | 85    |
| Sarah        | 92    |
| Lily         | 92    |

In the resulting sorted arrangement, we observe that the relative positions of students with identical scores are maintained, such as the cases of Emma and Michael, John and Alex, and Sarah and Lily. This preservation of order holds significance when the original sequence carries meaning, such as the order of record entry or when subsequent operations rely on the sorted data.

Conversely, an unstable sorting algorithm like Quick Sort may not uphold the original order of students with the same score, leading to a different arrangement.

Hence, in scenarios where preserving the relative order of elements with equal keys is crucial, as illustrated in the given example, the preference lies with a stable sorting algorithm over an unstable one.

### 7. Gold Thief

You are planning a heist to steal a rare coin that weighs 1.0001 ounces. The problem is that the rare coin was mixed with a bunch of counter fit coins. You know the counter fit coins only weight 1.0000 ounce each. There are in total 250 coins.  You have a simple balance scale where the coins can be weighed against each other. Hint: don't think about all the coins at once, but how you can break it up into even(ish) piles. 

#### 7.1 Algorithm
Describe an algorithm that will help you find the coin. We encourage you to use pseudo-code, but not required.

    Function findRareCoin(coins):
        Divide the coins into equal piles, each containing an even number of coins (except for one pile if the total number of coins is odd).
        For each pile:
            Weigh two random piles of coins against each other using the balance scale.
            If the two piles balance each other, it means the rare coin is not in those two piles. Discard those two piles.
            If the two piles don't balance each other, it means the rare coin is in one of those two piles. Keep the heavier pile.
        
        Repeat the above steps until there is only one pile left.
        
        Weigh the remaining pile against a single coin (which can be any coin).
        If they balance, the remaining coin is the rare coin.
        If they don't balance, the rare coin is the one that caused the imbalance on the scale.

        Return the rare coin.

    End Function


#### 7.2 Time Complexity
What is the average time complexity of your algorithm? 

The average time complexity of my algorithm can be analyzed as follows:

1. Dividing the coins into equal piles: This step requires dividing the total number of coins into equal piles. Since the number of piles is directly related to the number of coins, this step can be considered to have a time complexity of $O(1)$.

2. Weighing two random piles of coins: For each pile, we need to weigh it against another randomly chosen pile. Since the number of piles is halved after each weighing, this step would require $\log_2n$ weighings, where n is the total number of coins. Each weighing operation takes a constant amount of time, resulting in a time complexity of $O(\log_2n)$.

3. Repeating the steps until there is only one pile left: The number of weighings required in this step is $\log_2n$, where n is the total number of coins. Hence, the time complexity for this step is $O(\log_2n)$.

4. Weighing the remaining pile against a single coin: This step involves comparing the weight of the remaining pile with a single coin. Since it involves only a constant number of comparisons, the time complexity is $O(1)$.

Therefore, the overall time complexity of the algorithm can be approximated as $O(\log_2n)$, where n is the total number of coins.


### 8. Modern Sort
Sorting algorithms are still being studied today. They often include a statistical analysis of data before sorting. This next question will require some research, as it isn't included in class content. When you call `sort()` or `sorted()` in Python 3.6+, what sort is it using?  

In Python 3.6 and later versions, the built-in sort() function and sorted() function use a sorting algorithm called Timsort. Timsort is a hybrid sorting algorithm derived from merge sort and insertion sort. [4]  

#### 8.1 Visualize
Find a graphic / visualiation (can be a youtube video) that demonstrates the sort in action. 

Timsort visualiation [5]: https://www.chrislaux.com/timsort


#### 8.2 Big O
Give the worst and best case time-complexity, and examples that would generate them. 

<hr>

## References
Add your references here. A good reference includes an inline citation, such as [1] , and then down in your references section, you include the full details of the reference. Computer Science research often uses [IEEE] or [ACM Reference format].

[1] CS61B: Data Structures, "Sorting," UC Berkeley, Spring 2020. Available: https://inst.eecs.berkeley.edu/~cs61b/sp20/docs/sorting_notes.html.  
[2] Scaler Academy, "Quick Sort in Java," Scaler, Accessed June 9, 2023. [Online]. Available: https://www.scaler.com/topics/quick-sort-in-java/.  
[3] Interview Kickstart, "Stability in Sorting Algorithms," Interview Kickstart. [Online]. Available: https://www.interviewkickstart.com/learn/stability-in-sorting-algorithms.  
[4] Educative Answers Team, "What is the Python sorted() function?" Retrieved June 9, 2023. Available: https://www.educative.io/answers/what-is-the-python-sorted-function  
[5] Laux, C, "Timsort," Chris Laux. Available: https://www.chrislaux.com/timsort


## Footnotes:
[^note]: You will want at least 10 different N values, probably more to see the curve for Merge and Quick. If bubble, selection, and insertion start to take more than a  minute, you can say $> 60s$. 


<!-- links moved to bottom for easier reading in plain text (btw, this a comment that doesn't show in the webpage generated-->
[image markdown]: https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax#images

[ACM Reference Format]: https://www.acm.org/publications/authors/reference-formatting
[IEEE]: https://www.ieee.org/content/dam/ieee-org/ieee/web/org/conferences/style_references_manual.pdf

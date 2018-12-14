Hi,

This program was given to me as a project from my Computer Algorithm class. It was inspired from John C. Bowers' "Sorting Project" (Link: https://w3.cs.jmu.edu/bowersjc/page/courses/fall16/cs240/projects/sorting/). However, my professor only required to follow steps 3 and 5.

For the project, students are to import data from "unsorted7.txt", which includes 7 lines of N amounts of numbers. After importing, it will be stored inside a vector before being sorted in ascending order. The numbers will be sorted by a few popular sorting algorithms: Quick Sort, Insertion Sort, and Merge Sort. However, merge sort and quick sort must be improved.

For merge sort, one line of numbers inside the array will be split into two. Elements from the first half will be copied and sorted to a temporary array. The other half will be sorted, instead of copying it into another temporary array, it will stay inside the original array. Once both halves are sorted, merge both of them into ascending order. Please review Bowers' article for an illustrated example.

Quick sort is improved by checking the running time of itself. If running time is O(n^2), it will follow a different set of instructions to change the running time to O(n log n). Please read comments for more details.

Enjoy,

Anthony

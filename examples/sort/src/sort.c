void sort(int* ptr, int n) 
{ 
    int i, j, t; 

    // Sort the numbers using pointers 
    for (i = 0; i < n; i++) { 

        for (j = i + 1; j < n; j++) { 

            if (*(ptr + j) < *(ptr + i)) { 

                t = *(ptr + i); 
                *(ptr + i) = *(ptr + j); 
                *(ptr + j) = t; 
            } 
        } 
    } 
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool is_ordered(int *array, int n);
void simple_sort(int *array, int n);
void permutation(int *array, int n);

void selection_sort(int *array, int n);
int min(int *array, int k, int n);

void bubble_sort(int *array, int n);

void insertion_sort(int *array, int n);

void quick_sort(int *array, int first, int last);
int pivot(int *array, int first, int last);

void merge_sort(int *array, int first, int last);
void merge(int *array, int first, int last, int middle);

void print_array(int *array, int n);


/******************************** MAIN PROGRAM ********************************/
int main(void) {
        int V[10] = {5,7,3,9,2,0,1,4,8,6};

        print_array(V, 10);

	//selection_sort(V, 10);	// O(n^2)
        //bubble_sort(V,10);	
        //insertion_sort(V, 10);
        //quick_sort(V,0,9);
        //     da testate ---> 
        merge_sort(V,0,9);

        print_array(V, 10);

        return 0;
}
/****************************** END MAIN PROGRAM ******************************/


bool is_ordered(int *array, int n) {
/*
        @param array: puntatore primo elemento del vettore
        @param n: dimensione dell'array
        @return bool: true se l'array è ordinato, 0 altrimenti
*/
        for(int i=1; i<n; i++) {
                if(array[i-1] > array[i])
                        return false;
        }
      
        return true;
}

void simple_sort(int *array, int n) {
/*
        @param array: puntatore primo elemento del vettore
        @param n: dimensione dell'array
*/
        for(int i=0; i<n; i++){
                permutation(array, n); 
                if(is_ordered(array, n))
                        break;
        }
}

void permutation(int *array, int n) {
        // DA RIVEDERE <---------------------
}

void selection_sort(int *array, int n) {
/*
        @param array: puntatore primo elemento del vettore
        @param n: dimensione dell'array
*/
	for(int i=0; i<n;i++) {
		int j = min(array, i, n);
		
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

int min(int *array, int k, int n) {
/*
        @param array: puntatore primo elemento del vettore
        @param k: primo indice dacui scorrere il vettore
        @param n: dimensione dell'array
        @return min: indice posizionale del minimo
*/
	int min = k;
	for(int i = k+1; i<n; i++) {
		if(array[i] < array[min])
			min = i;
	}
	return min;
}

void bubble_sort(int *array, int n) {
/*
        @param array: puntatore primo elemento del vettore
        @param n: dimensione dell'array
*/
        int temp;
        bool change = true;

        while(change) {
                change = false;
                for(int i=0; i<=n-2; i++) {
                        if(array[i] > array[i+1]) {
                                /* swap */
                                temp = array[i];
                                array[i] = array[i+1];
                                array[i+1] = temp;

                                change = true;
                        }
                }
        }
}

/* https://www.youtube.com/watch?v=D0EosBYYcuo */
void insertion_sort(int *array, int n) {
/*
        @param array: puntatore primo elemento del vettore
        @param n: dimensione dell'array
*/
        int temp, j;
        for(int i=1; i<n; i++) {
                temp = array[i];
                j = i;
                while(j>0 && array[j-1]>temp) {
                        array[j] = array[j-1];
                        j--;
                }
                array[j] = temp;
        }
}

void quick_sort(int *array, int first, int last) {
/*
        @param array: puntatore primo elemento del vettore
        @param first: indice primo elemento
        @param last: indice ultimo elemento
*/
        if(first < last) {
                int k = pivot(array, first, last);

                quick_sort(array, first, k-1);
                quick_sort(array, k+1, last);
        }
}

int pivot(int *array, int first, int last) {
/*
        @param array: puntatore primo elemento del vettore
        @param first: indice primo elemento
        @param last: indice ultimo elemento
*/
        int x = array[first];
        int k = first;
        int temp;
        
        for(int i=first; i<=last; i++) {
                if(array[i] < x) {
                        k++;

                        /* swap */
                        temp = array[i];
                        array[i] = array[k];
                        array[k] = temp;
                }
        }

        array[first] = array[k];
        array[k] = x;

        return k;
}

/* https://www.youtube.com/watch?v=ya2s98-CCUI */
void merge_sort(int *array, int first, int last) {
/*
        @param array: puntatore primo elemento del vettore
        @param first: indice primo elemento
        @param last: indice ultimo elemento
*/
        if(first < last) {
                int middle = (first + last)/2;


                merge_sort(array, first, middle);
                merge_sort(array, middle+1, last);

                merge(array, first, last, middle);
        }
}

void merge(int *array, int first, int last, int middle) {
/*
        @param array: puntatore primo elemento del vettore
        @param first: indice primo elemento
        @param last: indice ultimo elemento
        @param middle: indice della metà del vettore
*/
        int i = first;			// indice per array '
        int j = middle + 1;		// indice per array ''
        int k = 0;			// indice per temp[]
        int temp[last+1 - first];	// vettore di appogio per il merge
        
        while(i <= middle && j <= last) {       //Finché non ho esaurito almeno uno dei due sottoarray
                if(array[i] <= array[j]) {
                        temp[k] = array[i];
                        i++;
                }else {
                        temp[k] = array[j];
                        j++;
                }
                k++;
        }
        
        if(i>middle) {
        	while(j<=last) {
        		temp[k] = array[j];
        		j++;
        		k++;
        	}
        }else if(j>last) {
        	while(i<=middle) {
        		temp[k] = array[i];
        		i++;
        		k++;
        	}
        }
        
        k=0;
        for(int h=first; h <= last; h++) {
        	array[h] = temp[k];
        	k++;
        }
}

void print_array(int *array, int n) {
/*
        @param array: puntatore primo elemento del vettore
        @param n: dimensione dell'array
*/
        printf("{ ");
        for(int i=0; i<n; i++) {
                printf("%d, ", array[i]);
        }
        printf("\b\b }\n");
}

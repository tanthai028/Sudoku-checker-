/* Name: Tan Thai                                  *
 * NetID: tanhoangthai                             *
 * Description: this code contains my solution for *
 *              the third project of COP3514.002   */


#include <stdio.h>
#include <stdlib.h>
#define SIZE 9

int find_duplicates(int arr[]);
int check_boxes(int arr[][SIZE]);
int check_column(int arr[][SIZE]);
int check_rows(int arr[][SIZE]);

int main() {

	// initalize and create 2d array from input
	int arr[SIZE][SIZE];
	  
	for (int i = 0; i < SIZE; ++i) {

		for (int j = 0; j < SIZE; ++j) {

		int x;
		scanf("%d", &x);
		arr[i][j] = x;

		// printf("%d ", arr[i][j]);
		}

	}

	// if true, valid
	if (check_boxes(arr) && check_column(arr) && check_rows(arr)) {
    printf("YES\n");
  }
	else printf("NO\n");
	
	return 0;
}

int check_boxes(int arr[][SIZE]){
	 // check validity for each 3x3 box

	// traverse 3x3 boxes (i and j)
	for (int i = 0; i < SIZE; i += 3) {
	  
		for (int j = 0; j < SIZE; j += 3) {

			// reset temp arr and x
			int x = 0;
			int temp_arr[SIZE] = {};

			// traverse values in 3x3 box (k and l)
			for (int k = i; k < i + 3; k++) {
			
				for (int l = j; l < j + 3; l++) {

				// printf("%d %d\n", k,l);
				// create array with 3x3 box values
				temp_arr[x] = arr[k][l];
				x++;
				}

				// printf("%d", temp_arr[i]);
			}
	  
			// if duplicate found in box
			if(find_duplicates(temp_arr)) {
			
				return 0;

			}
		}
	}
	
	return 1;
}

int check_column(int arr[][SIZE]){
	
	
	// check column validity
	for (int i = 0; i < SIZE; i++) {
	  
		int temp_arr[SIZE] = {};
      
		for (int j = 0; j < SIZE; j++) {
		  
		  // create array with column values
		  temp_arr[j] = arr[j][i];
		  // printf("%d", temp_arr[j]);
		  
		}

		// if duplicate found in row
		if(find_duplicates(temp_arr)) {
		  
		  return 0;

		}

	}
	
	return 1;
}

int check_rows(int arr[][SIZE]){
	
	// check row validity
	for (int i = 0; i < SIZE; i++) {
	  
		int temp_arr[SIZE] = {};
      
		for (int j = 0; j < SIZE; j++) {
		  
		  // create array with row values
		  temp_arr[j] = arr[i][j];
		  // printf("%d", temp_arr[j]);
		  
		}
		
		// if duplicate found in row
		if(find_duplicates(temp_arr)) {
		  
		  return 0;

		}

	} 
	
	return 1;
	
}



int find_duplicates(int arr[]) {
	
  // find duplicates with hashmap
    
  for (int i = 0; i < SIZE; ++i) {
    
    int index = abs(arr[i]) - 1;
    
    // if negative, then already found
    if (arr[index] < 0) {
      return 1;
    }
    
	// if not found
    arr[index] = -arr[index];
  }

  return 0;
}
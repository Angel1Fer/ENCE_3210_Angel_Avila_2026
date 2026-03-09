#define maximum 100 //setting up limit on storage//

//function//
long twice_square(int x){//long bc #of bits//
  return 2L * x * x;
} 
  
int main(void){
    long results[maximum + 1];
    for (int i = 0; i <= maximum; i++)
    {
        results[i] = twice_square(i);
    }
    
    //print//
    printf("Results[0]   = %ld\n", results[0]);
    printf("Results[10]  = %ld\n", results[10]);
    printf("Results[511] = %ld\n", results[100]);

    return 0;
}

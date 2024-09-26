/*
 * kernel.c file main file
 */

void kmain(void){
  const char *str = "Hello from my Kernel";
  char *vidptr = (char*)0xb8000; /*video pointer*/
  unsigned int i = 0;
  unsigned int j = 0;

  /*clear the screen*/
  while(j< 80*25*2){
    vidptr[j] = ' ';
    vidptr[j+1] = 0x07; /*light grey color on black screen*/
    j = j+2;
  }
  j =0;

  /*write string to video memory*/
  while(str[j] != '\0'){
    vidptr[i] = str[j];
    vidptr[i+1]= 0x07;

    ++j;
    i =i +2;
  }
  return;
}

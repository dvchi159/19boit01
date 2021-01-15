#include <stdio.h>
int intInput(const char* mess){
  int inputValue;
  printf("%s", mess);
  scanf("%d", &inputValue);
  return inputValue;
}
void tableHeader(){
	printf("\nDEPRECIATION TABLE\n------------------\n");
	printf("\t\t\t\t\t\tACCUMULATED\n");
	printf("YEAR\tDEPRECIATION\tEND-OF-YEAR VALUE\tDEPRECIATION\n");
	printf("----\t------------\t-----------------\t--------------------\n");
}
void tableDepreciation() {
  int machineCost, depreciationRate, year;
  machineCost = intInput("Input Machine Cost: ");
  depreciationRate = intInput("Input Depreciation Rate: ");
  year = intInput("Input Number of Year: ");
  tableHeader();
  for (int i = 1; i <= year; ++i){
    printf("%d\t%d\t\t%d\t\t\t%d\n",i, depreciationRate, (machineCost-depreciationRate*i), depreciationRate*i);
    if ((machineCost-depreciationRate*i) <= 0){
      printf("Machine is out of date.\n");
      break;
    }
  }
}
void main(){
  tableDepreciation();
}

 
#include <stdio.h>
int intInput(const char* mess){
  int inputValue;
  printf("%s", mess);
  scanf("%d", &inputValue);
  return inputValue;
}
void tableDepreciation() {
  FILE *outputFile = fopen("/home/fdc/Documents/Code_OUT/Test.txt", "w");
  int machineCost, depreciationRate, year;
  {//Input Value
    machineCost = intInput("Input Machine Cost: ");
    fprintf(outputFile, "Machine cost: %d\n", machineCost);
    depreciationRate = intInput("Input Depreciation Rate: ");
    fprintf(outputFile, "Depreciation rate: %d\n", depreciationRate);
    year = intInput("Input Number of Year: ");
    fprintf(outputFile, "Year: %d\n", year);
  }
  {//Table Header
    printf("\nDEPRECIATION TABLE\n------------------\n");
    fprintf(outputFile,"\nDEPRECIATION TABLE\n------------------\n");
    printf("\t\t\t\t\t\tACCUMULATED\n");
    fprintf(outputFile,"\t\t\t\t\t\tACCUMULATED\n");
    printf("YEAR\tDEPRECIATION\tEND-OF-YEAR VALUE\tDEPRECIATION\n");
    fprintf(outputFile,"YEAR\tDEPRECIATION\tEND-OF-YEAR VALUE\tDEPRECIATION\n");
    printf("----\t------------\t-----------------\t--------------------\n");
    fprintf(outputFile,"----\t------------\t-----------------\t--------------------\n");
  }
  for (int i = 1; i <= year; ++i){
    printf("%d\t%d\t\t%d\t\t\t%d\n",i, depreciationRate, (machineCost-depreciationRate*i), depreciationRate*i);
    fprintf(outputFile,"%d\t%d\t\t%d\t\t\t%d\n",i, depreciationRate, (machineCost-depreciationRate*i), depreciationRate*i);
    if ((machineCost-depreciationRate*i) <= 0){
      printf("Machine is out of date.\n");
      fprintf(outputFile,"Machine is out of date.\n");
      break;
    }
  }
  fclose(outputFile);
}
int main(){
  tableDepreciation();
  printf("Report file in '/home/fdc/Documents/Code_OUT/Test.txt' ");
}

 #include<stdio.h>

char globalArray[64];

int newPow(int n1, int n2);
float newPowfloat(int n1, int n2) ;
int strln (char *c);
long newAtoi(char *s);
int *int2Bin(int x , int size);
int bin2Int(char *s);
int hex2int(char *s);
float bin2f(char *s);
float bin2float(char *c);
float bin2double(char *c);
void hex2bin(char *c);



int main(int argc, char **argv) {

    int i;
    char I='I';
    char B='B';
    char F='F';
    char H='H';
    char D='D';
    char dash ='-';

if( argc != 4){
    fprintf(stderr, "ERROR: The number of arguments is wrong.\nUsage: ./clc -<input format> -<output format> <input>\n");
    return 1;

} else if( argv[1][0]!= dash || (argv[1][1]!=B && argv[1][1]!=H && argv[1][1]!=I && argv[1][1]!=F && argv[1][1]!=D) ) {
    fprintf(stderr,"ERROR: The input argument is wrong.\nPossible input arguments are -B, -H, -I, -F and -D.\n");
    return 1;

} else if (argv[2][0]!= dash || (argv[2][1]!= B && argv[2][1]!= H && argv[2][1]!= I && argv[2][1]!= F && argv[2][1]!=D)){
    fprintf(stderr,"ERROR: The output argument is wrong.\nPossible output arguments are -B, -H, -I, -F and -D.\n");
    return 1;

// Input format INTEGER
} else if (argv[1][1] == I ) {
    // Checking for input format error in Integer input
    for (i=0; i< strln(argv[3]) ; i++){
        if( argv[3][0]!= dash && argv[3][i] != '0'  &&  argv[3][i]!='1' && argv[3][i]!='2' && argv[3][i]!='3' && argv[3][i]!='4' && argv[3][i]!='5' && argv[3][i]!='6' && argv[3][i]!='7' && argv[3][i]!='8' && argv[3][i]!='9' ){
            fprintf(stderr,"ERROR: Input format error at location %d.\n",i);
            return 1;
        }
    }

    if ((newAtoi(argv[3]) > 2147483647) || (newAtoi(argv[3]) < -2147483648) ) {
        fprintf(stderr,"ERROR: The input size is wrong.\n");
        return 1;
    }

    if (argv[1][1]==argv[2][1]) {
	fprintf(stdout,"%s\n",argv[3]);
	return 1;
    }

    int integer = newAtoi(argv[3]);

    // Converting integer to Binary
    if (argv[2][1]== B){
        int *p;
        p= int2Bin(integer, 32);
        for(i=0 ; i <=31 ; i++) {
            fprintf(stdout,"%d", *(p+i));
        }
    printf("\n");
    }

    // Converting integer to Hexadecimal
    if (argv[2][1]== H){
        fprintf(stdout,"ox%08X\n", integer);


    // Converting Integer to Float
    } else if (argv[2][1]== F){
        float f= integer;
        fprintf(stdout,"%0.2f\n", f);


    // Converting integer to Decimal
    } else if (argv[2][1]== D){
        fprintf(stderr,"ERROR: This conversion is not possible.\n");
        return 1;
    }

// input format BINARY
} else if (argv[1][1] == B) {
    // Checking for input format error in binary input
    for (i=0; i< strln(argv[3]) ; i++){
        if( argv[3][i] !='0'  && argv[3][i]!='1' ){
            fprintf(stderr,"Error:  Input format error at location %d.\n",i);
            return 1;
        }
    }

    if ((strln(argv[3])!=32) && (strln(argv[3])!=64) ){
        fprintf(stderr,"ERROR: The input size is wrong.\n");
        return 1;
    }

    if (argv[1][1]==argv[2][1]) {
	fprintf(stdout,"%s\n",argv[3]);
	return 1;
    }

    // Converting Binary to Hexadecimal
    if (argv[2][1]== H){
        int integer = bin2Int(argv[3]);
        fprintf(stdout,"%X\n", integer);

    // Converting Binary to Integer
    } else if (argv[2][1]== I) {
        fprintf(stdout,"%d\n", bin2Int(argv[3]));


    // Converting Binary to float
    } else if (argv[2][1]== F ){
        fprintf( stdout, "%f\n", bin2float(argv[3]));

    // Converting Binary to Double
    } else if (argv[2][1]== D) {
        fprintf( stdout, "%lf\n", bin2double(argv[3]));
    }


// Input format HEXADECIMAL
} else if (argv[1][1] == H) {
    //Checking for input format error in hexadecimal input
     for (i=0; i< strln(argv[3]) ; i++){
        if(argv[3][i] != '0'  &&  argv[3][i]!='1' && argv[3][i]!='2' && argv[3][i]!='3' && argv[3][i]!='4' && argv[3][i]!='5' && argv[3][i]!='6' && argv[3][i]!='7' && argv[3][i]!='8' && argv[3][i]!='9' && argv[3][i]!='A' && argv[3][i]!='B' && argv[3][i]!='C' && argv[3][i]!='D' && argv[3][i]!='E' && argv[3][i]!='F' ){
            fprintf(stderr,"ERROR: Input format error at location %d.\n",i);
            return 1;
        }
    }
    if ( (strln(argv[3])!=8) && (strln(argv[3])!=16) ) {
        fprintf(stderr,"ERROR: The input size is wrong.\n");
        return 1;
    }

    if (argv[1][1]==argv[2][1]) {
	fprintf(stdout,"%s\n",argv[3]);
	return 1;
    }

    // Converting Hexadecimal to Integer
    if (argv[2][1] == I) {
        if( strln(argv[3]) == 8){
            fprintf(stdout, "%d\n" , hex2int(argv[3]));
        } else if (strln(argv[3]) == 16) {
             fprintf(stderr,"ERROR: This conversion is not possible.\n");
            return 1;
        }
    // Converting Hexadecimal to Binary
    } else if (argv[2][1] == B){
        if( strln(argv[3]) == 8){
            int a= hex2int(argv[3]);
            int *q;
            q = int2Bin(a, 32);
            for(i=0 ; i <=31 ; i++) {
                fprintf(stdout,"%d", *(q+i));
            }
        printf("\n");
        } else if(strln(argv[3]) == 16){
            hex2bin(argv[3]);
            for (i=0; i< 64 ; i++){
                fprintf(stdout, "%c", globalArray[i]);
            }
        }

    // Converting Hexadecimal to Float
    } else if (argv[2][1] == F) {
        int intarray[32];
        char charArray[32];
        int b= hex2int(argv[3]);
        int *q;
        q = int2Bin(b , 32);
        for(i=0 ; i <=31 ; i++) {
             intarray[i] = *(q+i);
        }

        for(i=0 ; i <=31 ; i++) {
             if(intarray[i] == 0) charArray[i] = '0';
             else charArray[i] = '1' ;
        }
    fprintf( stdout, "%f\n", bin2float(charArray));


    // Converting Hexadecimal to Double
    } else if (argv[2][1] == D){

        //~ int binArray[64];
        if( strln(argv[3]) != 16) {
            fprintf(stderr,"ERROR: The input size is wrong.\n");
            return 1;
        } else {
             hex2bin(argv[3]);
             float s = bin2double(globalArray);
             fprintf(stdout, "%lf\n" , s);
        }
    }

// Input format FLOAT
} else if(argv[1][1] == F) {
    //Checking for input format error in hexadecimal input
     int count=0,k=0;
      int i=0;
        while(argv[3][i]!='\0'){
            if(!((argv[3][i]>=48 && argv[3][i]<=57) || (argv[3][i]=='.' )|| (argv[3][i] == '-'))){
                fprintf(stderr,"ERROR: Input format error at location %d.\n",i);
                return 1;
            }
            i++;
        }

        // checking extra dots in the input
        while(argv[3][k]!='\0'){
            if(argv[3][k]=='.'){
                ++count;
            }
            if(count>1){
                fprintf(stderr,"ERROR: Input format error at location %d.\n",k);
                return 1;
            }
            k++;
        }

    if (argv[1][1]==argv[2][1]) {
	fprintf(stdout,"%s\n",argv[3]);
	return 1;
    }

        // Converting float to double
        if(argv[2][1]== D) {
           fprintf(stderr,"ERROR: This conversion is not possible.\n");
           return 1;
        }

// Input format is DOUBLE
} else if (argv[1][1] == D) {
int count=0,k=0 , j=0;
        // checking  input format error
        while(argv[3][j]!='\0'){
            if(!((argv[3][j]>=48 && argv[3][j]<=57) || (argv[3][j]=='.' )|| (argv[3][j] == '-'))){
                fprintf(stderr,"ERROR: Input format error at location %d.\n",j);
                return 1;
            }
            j++;
        }

         // checking extra dots in the input
        while(argv[3][k]!='\0'){
            if(argv[3][k]=='.'){
                ++count;
            }
            if(count>1){
                fprintf(stderr,"ERROR: Input format error at location %d.\n",k);
                return 1;
            }
            k++;
        }

    if (argv[1][1]==argv[2][1]) {
	fprintf(stdout,"%s\n",argv[3]);
	return 1;
    }


}

return 0;
}


// Defining the newPow function
int newPow(int n1, int n2) {
 int i, prod =1;
 for(i=0 ; i< n2 ; i++ ) {
    prod = prod* n1;
 }
 return prod;
}

// Defining the string length function
int strln (char *c) {
 int j,count=0;
 for(j=0 ; c[j] != '\0' ; j++){
    count ++ ;
 }
 return count;
}


// Defining the newAtoi function
long newAtoi(char *s) {
int i;
long num=0;
if( s[0] == '-'){
    for(i=1; i< strln(s) ; i++ ){
        int v=(s[i] - 48 ) * newPow(10, (strln(s)-1 -i));
        num = num + v;
    }
    num = -1*num;
} else {
    for(i=0; i< strln(s) ; i++ ){
        int v=(s[i] - 48 ) * newPow(10, (strln(s)-1 -i));
        num = num + v;
    }
}
return num;
}


// INTEGER to BINARY function

int *int2Bin(int x, int size) {
    int i=0;
    int b[size];
    //~ int b1[size];
    int b2[size];
    static int b3[32];
    int r;
    //~ int y;

	if ( x >= 0) {
	while(i<= size -1) {
		r=x%2; // Getting the remainder when divided by 2
		b[i]=r; // Creating an array using the remainders
		x=x/2;
		i=i+1;
	}

	for(i=0 ; i <= size-1 ; i++) { // Creating the new b3 array which gives the binary representation of the positive number
		b3[i]=b[size-1-i];
	}

	printf("\n");

	} else {
     x= x*(-1);
     while(i<= size-1) {
		r=x%2; // Getting the remainder when divided by 2
		b[i]=r; // Creating an array using the remainders
		x=x/2;
		i=i+1;
	}
	for(i=0 ; i <= size-1 ; i++) { // Creating the new b2 array which gives the binary representation of the positive number
		b2[i]=b[size-1-i];
	}


    for (i=0 ; i <= size-1 ; i++) { //creating the array b3 which represents the inverse of b2, to get the 1's complement
       if(b2[i]==0){
         b3[i]=1;
       } else  {
         b3[i]=0;
       }
	}

	for (i=size-1 ;i>=0;i--){ // Adding 1 to get the 2's complement
        if (b3[i]==0){
           b3[i]=1;
           break;
        } else {
           b3[i]=0;
        }
	}
}

	return b3;

}


// BINARY to INTEGER function

int bin2Int(char *s){

    int i,y,sum=0;
	for(i=0;i< strln(s);i=i+1) {
		if (s[i]=='1') {
		y=newPow(2,(strln(s)-1-i));
		sum=sum+y;
		}
}

return sum;
}


// HEXADECIMAL to INTEGER function

int hex2int(char *s) {

    int i,y,sum=0;

	for(i=0;i< strln(s);i=i+1) {
		if (s[i]=='1') {
		y=newPow(16,(strln(s)-1-i)) *1;
		sum=sum+y;
		} else if (s[i]=='2') {
		y=newPow(16,(strln(s)-1-i)) * 2;
		sum=sum+y;
		} else if (s[i]=='3') {
		y=newPow(16,(strln(s)-1-i)) * 3;
		sum=sum+y;
		}else if (s[i]=='4') {
		y=newPow(16,(strln(s)-1-i)) * 4;
		sum=sum+y;
		}else if (s[i]=='5') {
		y=newPow(16,(strln(s)-1-i)) * 5;
		sum=sum+y;
		}else if (s[i]=='6') {
		y=newPow(16,(strln(s)-1-i)) * 6;
		sum=sum+y;
		}else if (s[i]=='7') {
		y=newPow(16,(strln(s)-1-i)) * 7;
		sum=sum+y;
		}else if (s[i]=='8') {
		y=newPow(16,(strln(s)-1-i)) * 8;
		sum=sum+y;
		}else if (s[i]=='9') {
		y=newPow(16,(strln(s)-1-i)) * 9;
		sum=sum+y;
		}else if (s[i]=='A') {
		y=newPow(16,(strln(s)-1-i)) * 10;
		sum=sum+y;
		}else if (s[i]=='B') {
		y=newPow(16,(strln(s)-1-i)) * 11;
		sum=sum+y;
		}else if (s[i]=='C') {
		y=newPow(16,(strln(s)-1-i)) * 12;
		sum=sum+y;
		}else if (s[i]=='D') {
		y=newPow(16,(strln(s)-1-i)) * 13;
		sum=sum+y;
		}else if (s[i]=='E') {
		y=newPow(16,(strln(s)-1-i)) * 14;
		sum=sum+y;
		}else if (s[i]=='F') {
		y=newPow(16,(strln(s)-1-i)) * 15;
		sum=sum+y;
		}
}

return sum;
}

// Defining a power function which returns a float value

float newPowfloat(int n1, int n2) {
 int i, prod =1;
 for(i=0 ; i< n2 ; i++ ) {
    prod = prod* n1;
 }
 return prod;
}


// Defining a function to convert binary to float
float bin2f(char *s){
    int i;
    int d=0;
    float y,sum=0;
    float y1;
    float sum1=0;
    float y2;
    float sum2=0;
    char dot = '.';

	for(i=0;i< strln(s);i=i+1) {
		if( s[i] == dot) d=i;
	}

	if (d==0) {
        for(i=0;i< strln(s);i=i+1) {
            if (s[i]=='1') {
                y=newPowfloat(2,(strln(s)-1-i));
                sum=sum+y;
            }
        }

	} else {

    for(i=0; i<d ; i++){
        if (s[i]=='1') {
            y1 = newPowfloat(2, d-1-i);
            sum1 = sum1 + y1;
        }
    }

    for(i= d+1; i< strln(s) ; i++){
        if (s[i]=='1') {
            y2 = 1/( newPowfloat(2,i-d ) );
            sum2 = sum2 + y2;
        }
    }
    sum = sum1 + sum2 ;
    }
	return sum;
}

// Function to convert binary to float using IEEE format
float bin2float(char *c) {
    int s,i,degree;
    int exponent = 0;
    float finalVal;
    char exArray[8];
    char sigArray[25];
    char dot ='.';

    if(c[0] == '0'){
        s = 0;
    } else{
        s = 1;
    }
    for(i=1; i <= 8 ; i++) {
       exArray[i-1] = c[i]-48;
    }

    for(i=0;i< 8;i=i+1) {
		if (exArray[i]== 1) {
		int x =newPow(2,(7-i));
		exponent = exponent+x;
		}
    }
    if (exponent >= -126 && exponent <= 127) degree = exponent - 127;
    else fprintf(stderr,"ERROR: The input size is wrong.\n");

    sigArray[0]= '1';
    sigArray[1] = dot;

    for(i=2 ; i < 25 ; i++) {
       sigArray[i]= c[7+i];
    }

    float Val= bin2f(sigArray);
    float e = newPowfloat(-1, s) * Val;
    if (degree >= 0){
        finalVal= e* newPowfloat(2, degree);
    } else {
        finalVal= e* (1/newPowfloat(2, -1*degree));
    }
    //float largestVal =

return finalVal;
}

// Function to convert binary to double using IEEE format
float bin2double(char *c) {

    int s,i,degree;
    int exponent = 0;
    float finalVal;
    char exArray[11];
    char sigArray[54];
    char dot ='.';

    if(c[0] == '0'){
        s = 0;
    } else{
        s = 1;
    }
    for(i=1; i <= 11 ; i++) {
       exArray[i-1] = c[i]-48;
    }

    for(i=0;i< 11;i=i+1) {
		if (exArray[i]== 1) {
		int x =newPow(2,(10-i));
		exponent = exponent+x;
		}
    }
    if (exponent >= -1022 && exponent <= 1023) degree = exponent - 1023;
    else fprintf(stderr,"ERROR: The input size is wrong.\n");

    sigArray[0]= '1';
    sigArray[1] = dot;

    for(i=2 ; i < 54 ; i++) {
       sigArray[i]= c[10+i];
    }

    float Val= bin2f(sigArray);
    float e = newPowfloat(-1, s) * Val;
    if (degree >= 0){
        finalVal= e* newPowfloat(2, degree);
    } else {
        finalVal= e* (1/newPowfloat(2, -1*degree));
    }
    //float largestVal =

return finalVal;
}


void hex2bin(char *c) {
    int i,k;
    for(i=0, k=0;  i< 16 && k<= 60 ; i++ , k=k+4){
    switch (c[i])
    {
    case '0':
        globalArray[k]=0; globalArray[k+1]=0; globalArray[k+2]=0; globalArray[k+3]=0; break;
    case '1':
        globalArray[k]=0; globalArray[k+1]=0; globalArray[k+2]=0; globalArray[k+3]=1; break;
    case '2':
        globalArray[k]=0; globalArray[k+1]=0; globalArray[k+2]=1; globalArray[k+3]=0; break;
    case '3':
        globalArray[k]=0; globalArray[k+1]=0; globalArray[k+2]=1; globalArray[k+3]=1; break;
    case '4':
        globalArray[k]=0; globalArray[k+1]=1; globalArray[k+2]=0; globalArray[k+3]=0; break;
    case '5':
        globalArray[k]=0; globalArray[k+1]=1; globalArray[k+2]=0; globalArray[k+3]=1; break;
    case '6':
        globalArray[k]=0; globalArray[k+1]=1; globalArray[k+2]=1; globalArray[k+3]=0; break;
    case '7':
        globalArray[k]=0; globalArray[k+1]=1; globalArray[k+2]=1; globalArray[k+3]=1; break;
    case '8':
        globalArray[k]=1; globalArray[k+1]=0; globalArray[k+2]=0; globalArray[k+3]=0; break;
    case '9':
        globalArray[k]=1; globalArray[k+1]=0; globalArray[k+2]=0; globalArray[k+3]=1; break;
    case 'A':
        globalArray[k]=1; globalArray[k+1]=0; globalArray[k+2]=1; globalArray[k+3]=0; break;
    case 'B':
        globalArray[k]=1; globalArray[k+1]=0; globalArray[k+2]=1; globalArray[k+3]=1; break;
    case 'C':
        globalArray[k]=1; globalArray[k+1]=1; globalArray[k+2]=0; globalArray[k+3]=0; break;
    case 'D':
        globalArray[k]=1; globalArray[k+1]=1; globalArray[k+2]=0; globalArray[k+3]=1; break;
    case 'E':
        globalArray[k]=1; globalArray[k+1]=1; globalArray[k+2]=1; globalArray[k+3]=0; break;
    case 'F':
        globalArray[k]=1; globalArray[k+1]=1; globalArray[k+2]=1; globalArray[k+3]=1; break;
    }
  }

}






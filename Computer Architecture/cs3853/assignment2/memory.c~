#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>


/* Block */
struct block {
	int valid;
	int tag;
		
};


/* Cache */
struct cache {
	int hits;
	int misses;
	int cachesize;
	int blocksize;
	struct block* blocks;

};

unsigned int htoi(const char str[])
{
    /* Local Variables */
    unsigned int result;
    int i;

    i = 0;
    result = 0;
    
    if(str[i] == '0' && str[i+1] == 'x')
    { 
        i = i + 2;
    }

    while(str[i] != '\0')
    {
        result = result * 16;
        if(str[i] >= '0' && str[i] <= '9')
        {
            result = result + (str[i] - '0');
        }
        else if(tolower(str[i]) >= 'a' && tolower(str[i]) <= 'f')
        {
            result = result + (tolower(str[i]) - 'a') + 10;
        }
        i++;
    }

    return result;
}

char *getBinary(unsigned int num)
{
    char* bstring;
    int i;
    
    /* Calculate the Binary String */
    
    bstring = (char*) malloc(sizeof(char) * 33);
    assert(bstring != NULL);
    
    bstring[32] = '\0';
    
    for( i = 0; i < 32; i++ )
    {
        bstring[32 - 1 - i] = (num == ((1 << i) | num)) ? '1' : '0';
    }
    
    return bstring;
}

char *formatBinary(char *bstring, int tag, int index, int offset)
{
    char *formatted;
    int i;
    
    /* Format for Output */
    
    formatted = (char *) malloc(sizeof(char) * 35);
    assert(formatted != NULL);
    
    formatted[34] = '\0';
    
    for(i = 0; i < tag; i++)
    {
        formatted[i] = bstring[i];
    }
    
    formatted[tag] = ' ';
    
    for(i = tag + 1; i < index + tag + 1; i++)
    {
        formatted[i] = bstring[i - 1];
    }
    
    formatted[index + tag + 1] = ' ';
    
    for(i = index + tag + 2; i < offset + index + tag + 2; i++)
    {
        formatted[i] = bstring[i - 2];
    }

    return formatted;
}

int btoi(char *bin)
{
    int  b, k, m, n;
    int  len, sum;

    sum = 0;
    len = strlen(bin) - 1;

    for(k = 0; k <= len; k++)
    {
        n = (bin[k] - '0'); 
        if ((n > 1) || (n < 0))
        {
            return 0;
        }
        for(b = 1, m = len; m > k; m--)
        {
            b *= 2;
        }
        sum = sum + n * b;
    }
    return(sum);
}

void parseMemoryAddress(char *address, int TAG, int INDEX, int OFFSET, int *ta , int *in)
{
    unsigned int dec;
    char *bstring, *bformatted, *tag, *index, *offset;
    int i;
    
    //dec = htoi(address);
    //bstring = getBinary(dec);
    
    //bformatted = formatBinary(bstring, TAG, INDEX, OFFSET);
    //bformatted = formatBinary(address, TAG, INDEX, OFFSET);
    bformatted = address;    

    /*
    if(DEBUG)
    {
        printf("Hex: %s\n", address);
        printf("Decimal: %u\n", dec);
        printf("Binary: %s\n", bstring);
        printf("Formatted: %s\n", bformatted);
    }
    */
    i = 0;
    
    tag = (char *) malloc( sizeof(char) * (TAG + 1) );
    assert(tag != NULL);
    tag[TAG] = '\0';
    
    for(i = 0; i < TAG; i++)
    {
        tag[i] = bformatted[i];
    }
    
    index = (char *) malloc( sizeof(char) * (INDEX + 1) );
    assert(index != NULL);
    index[INDEX] = '\0';
    
    for(i = TAG + 1; i < INDEX + TAG + 1; i++)
    {
        index[i - TAG - 1] = bformatted[i];
    }
    
    offset = (char *) malloc( sizeof(char) * (OFFSET + 1) );
    assert(offset != NULL);
    offset[OFFSET] = '\0';
    
    for(i = INDEX + TAG + 2; i < OFFSET + INDEX + TAG + 2; i++)
    {
        offset[i - INDEX - TAG - 2] = bformatted[i];
    }
    *ta = btoi(tag);
    *in = btoi(index);
    //printf("Tag: %s (%i)\n", tag, btoi(tag));
    //printf("Index: %s (%i)\n", index, btoi(index));
    //printf("Offset: %s (%i)\n", offset, btoi(offset));
}


int main (int argc, char *argv[]){

int tracing = 0;

/* checking for correct number of parameters */	
if (argc != 5){
	printf("Incorrect number of parameters\n");
	exit(-1);	
}		

/* Cache size  */
int cachesize = atoi(argv[1]);
if (cachesize < 1) {
	printf("Cache size must be greater than 0\n");
	exit(-1);
}

/* Block size  */
int blocksize = atoi(argv[2]);
if (blocksize < 1){
	printf("Block size must be greater than 0\n");
	exit(-1);
}

/* checking to see if the block size is greater than the cache size */
if (blocksize > cachesize){
	printf("Block size cannot be greater than Cache size\n");
	exit(-1);
}

/* Checking 3rd parameter  */
if ( (strlen(argv[3]) < 2) || (strlen(argv[3]) > 3) ){
	printf("Please enter on or off for the 3rd parameter\n");
	exit(-1);
}

/* Checking for On  */
if ( strlen(argv[3]) == 2   ){
	if ((argv[3][0] != 'o') && (argv[3][0] != 'O') && (argv[3][0] != 'n') && (argv[3][1] != 'N')   ){
		printf("Please enter on or off for the 3rd parameter\n");
		exit(-1);
	}
	tracing = 1;
}

/* Checking for Off  */
if ( strlen(argv[3]) == 3 ) {
	if ( (argv[3][0] != 'o') && (argv[3][0] != 'O') && (argv[3][1] != 'f') && (argv[3][1] != 'F') && (argv[3][2] != 'f') && ( argv[3][2] != 'F' )  ) {
		printf("Please enter on or off for the 3rd parameter\n");
		exit(-1);
	}
	tracing = 0;
}

/* Read in file */
FILE *filelinecount;
FILE *file;
char buffer[11];
int lines = 0;

filelinecount = fopen( argv[4], "r" );
if ( filelinecount == NULL ){
	fprintf(stderr, "Error: Could not open file.\n");
	return 1;
}

while ( fgets( buffer, 11, filelinecount  ) != NULL   ){
		
	lines++;
}

int i = 0;
int i2 = 0;
file = fopen( argv[4], "r");
char addressvalues[11][lines];
int hexvalues[lines];
int temphex;

double t = (5.0/6.0);
//printf("\n%lf\n",t);

int intval = 0;
char hexval[11];
sprintf(hexval,"%0x",intval);
//printf("\n\n hexval : %s\n\n ",hexval); 


while (fgets(buffer,11, file) != NULL ){
	
	i2 = 0;
	if ( (buffer[0] != '0') && (buffer[1] != 'x') ){
		intval = atoi(buffer);
		sprintf(hexval,"%0x",intval);		
		
		temphex = strtol(hexval,NULL,16);
		hexvalues[i] = temphex;		
		while((hexval[i2] != '\0')){
			if (hexval[i2] != '\n'){		
				addressvalues[i2][i] = hexval[i2];		
			}
			i2++;
		}		
		addressvalues[i2][i] = '\0';		
	}else {	
		
		temphex = strtol(buffer,NULL,16);	
		hexvalues[i] = 	temphex;
		//printf("%s",buffer);
        
		while((buffer[i2] != '\0')){
			if (buffer[i2] != '\n'){		
				addressvalues[i2][i] = buffer[i2];		
			}
			i2++;
		}
		addressvalues[i2-1][i] = '\0';
	}	
	
	
	
	i2 = 0;
	i++;
	
}
//printf("\n");

int csize =(int) pow((double)2,(double)cachesize);
int bsize =(int) pow((double)2,(double)blocksize);

int totalblocks = csize/bsize;
int index = log2(totalblocks);
int tag = (32 - index - blocksize);

//printf("cache size in bytes : %d\n", csize);
//printf("block size in bytes : %d\n", bsize);
//printf("Blocks in cache : %d\n",totalblocks);
//printf("Offset : %d\n", blocksize);
//printf("Index : %d\n", index);

struct block blocks[totalblocks];
for (i = 0; i < totalblocks; i++){ 
	blocks[i].valid = 0;
	blocks[i].tag = 0;
}
int tags[lines];
int indexes[lines];

int ta;
int in;

char *testbin;
char *formatbin;
testbin = getBinary(hexvalues[5]);
//printf("\n");
for ( i = 0; i < 32; i++){
	//printf("%c",testbin[i]);
}
//printf("\n");
formatbin = formatBinary(testbin, tag, index, blocksize );
//printf("\n");
for ( i = 0; i < 34; i++){
	//printf("%c",formatbin[i]);
}
//printf("\n");
parseMemoryAddress(formatbin,tag,index,blocksize,&ta,&in);

//printf("tag value :%d\n", ta);
//printf("index value :%d\n", in);


char *tempbin;
char *tempformattedbin;

for (i = 0; i < lines; i++){
	tempbin = getBinary(hexvalues[i]);
	tempformattedbin = formatBinary(tempbin,tag,index,blocksize);
	
	parseMemoryAddress(tempformattedbin, tag, index, blocksize, &tags[i], &indexes[i]);
	
	
}


double missratio = 0.0;
double accesses = 0.0;
double misses = 0.0;
int hits = 0;
char hit[4];
char miss[5];
int oldtag = 0;
hit[0] = 'h';
hit[1] = 'i';
hit[2] = 't';
hit[3] = '\0';

miss[0] = 'm';
miss[1] = 'i';
miss[2] = 's';
miss[3] = 's';
miss[4] = '\0';

int hitflag = 0;
int missflag = 0;

	if (tracing) {	
		printf("address\ttag\tblock\tmem tag\th/m \thits\tmisses\taccesses\tmiss ratio\n");
	}
	for ( i = 0; i < lines; i++){				
		//printf("tags : %d , indexes : %d \n",tags[i], indexes[i]);	
		
		if (blocks[indexes[i]].valid == 0){
			blocks[indexes[i]].valid = 1;
			blocks[indexes[i]].tag = tags[i];		
			missflag = 1;
			misses += 1.0;				
			//printf("here");		
		}
		 else if (blocks[indexes[i]].valid == 1){
			if (blocks[indexes[i]].tag == tags[i]){
				oldtag = blocks[indexes[i]].tag;				
				blocks[indexes[i]].tag = tags[i];
				hits += 1;
				hitflag = 1;
			} else {
				misses += 1.0;
				missflag = 1;
				oldtag = blocks[indexes[i]].tag;
				blocks[indexes[i]].tag = tags[i];
							
			}
		
		}
		accesses += 1.0;		
		missratio = (misses/accesses);
		
		if (tracing) {
		i2 = 0;
		
			while (addressvalues[i2][i] != '\0'){
				if ( (i2 == 0) && (addressvalues[i2][i] == '0') && (addressvalues[i2+1][i] == 'x') ){
				
				} else if ( ( i2 == 1 ) && (addressvalues[i2][i] == 'x') ){ 

				} else {				
					printf("%c" ,addressvalues[i2][i]); 
				}				
				i2++;		
			}
		i2 = 0;	
		}
		if ( tracing ){

			printf("\t %x \t %x \t", tags[i], indexes[i]);
				
			if (oldtag > 0){
				printf(" %x \t", oldtag);
			} else {
				printf("   \t");
			}
			if (hitflag == 1){
				printf("%s \t", hit);
			} else if (missflag == 1){
				printf("%s \t", miss);
			}
			
			printf(" %d \t %d \t %d \t     %.8f" , hits , (int)misses , (int)accesses , missratio ); 

		}
				
		
		if (tracing){			
			printf("\n");
		}
		hitflag = 0;
		missflag = 0;		
		oldtag = 0;
		
	}
	printf("Ivan Capistran\n");
	printf("%s %s %s %s\n", argv[1], argv[2], argv[3], argv[4]);
	printf("memory accesses: %d\n" , (int) accesses);
	printf("hits: %d\n" , hits);
	printf("misses: %d\n", (int)misses);
	printf("miss ratio: %.8f\n", missratio);


	return 0;
}

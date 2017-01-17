#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>


/* Set */
struct set {
	
	struct block *blocks;
};


/* Block */
struct block {
	int valid;
	int tag;
	int timebrought;
	int firstbrought;		
};


/* Cache */
struct cache {
	int hits;
	int misses;
	int cachesize;
	int blocksize;
	struct block* blocks;

};


/* Makes hex string array to int value */
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


/* Returns array of binary numbers */
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

/* Formats a binary string based on tag index and offset */
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

/* Converts array of binary characters to int */
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

/* Takes a char array of binary characters and splits it into a tag and index */
void parseMemoryAddress(char *address, int TAG, int INDEX, int OFFSET, int *ta , int *in)
{
    unsigned int dec;
    char *bstring, *bformatted, *tag, *index, *offset;
    int i;
    
    //dec = htoi(address);
    //bstring = getBinary(dec);
    
    //bformatted = formatBinary(bstring, TAG, INDEX, OFFSET);
    //bformatint tags[lines];
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

/* Flags */
int tracing = 0;
int fifolru = 0;
int i;
int directmapped = 0;
int fullyassociative = 0;
int associativity = 1;

/* Checking for correct number of parameters */	
if (argc != 7){
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

/* Checking to see if the block size is greater than the cache size */
if (blocksize > cachesize){
	printf("Block size cannot be greater than Cache size\n");
	exit(-1);
}

/* Associativity  3rd parameter*/
if ( atoi(argv[3]) < 0 ){  }
for (i = 0; i < strlen(argv[3]); i++){
	if ( isalpha(argv[3][i]) ){
       		fprintf(stderr, " Please only enter digits \n");
        	exit(-1);         
	} else if ( isdigit(argv[3][i])  ) {
        
	} else {
       		fprintf(stderr," Please only enter digits \n");
       		exit(-1);
	}               
}	
int p = atoi(argv[3]);




/* Checking 4th parameter */
if ( ( strlen(argv[4]) < 3 ) ||  ( strlen(argv[4]) > 4 ) ){
	printf("Please enter fifo or lru for the 4th parameter\n");
	exit(-1);
}

/* Checking for fifo */
if ( strlen(argv[4]) == 4 ){
	if ( (( argv[4][0] == 'f' ) || ( argv[4][0] == 'F' )) && (( argv[4][1] == 'i'  ) || ( argv[4][1] == 'I'  )) &&  (( argv[4][2] == 'f' ) ||  (argv[4][2] == 'F'  ) ) &&  (( argv[4][3] == 'o'  ) ||  ( argv[4][3] == 'O'  ))  ){
		
	} else {
		printf("Please enter fifo or lru for the 4th parameter\n");
		exit(-1);
	}
	fifolru = 0;
}

/* checking for lru */
if ( strlen(argv[4]) == 3   ) {
	if ( ((argv[4][0] == 'l'  ) || ( argv[4][0] == 'L'    ))  &&  (( argv[4][1] == 'r'   ) ||  ( argv[4][1] == 'R'   )) &&  (( argv[4][2] == 'u' ) ||  ( argv[4][2] == 'U'   )) ){
		
	}else {
		printf("Please enter fifo or lru for the 4th parameter\n");
		exit(-1);
	}
	fifolru = 1;
}

/* Checking 5th parameter  */
if ( (strlen(argv[5]) < 2) || (strlen(argv[5]) > 3) ){
	printf("Please enter on or off for the 5th parameter\n");
	exit(-1);
}

/* Checking for On  */
if ( strlen(argv[5]) == 2   ){
	if (  ((argv[5][0] == 'o') || (argv[5][0] == 'O')) && ((argv[5][1] == 'n') || (argv[5][1] == 'N'))   ){
		
	}else {
		printf("Please enter on or off for the 5th parameter\n");
		exit(-1);
	}
	tracing = 1;
}

/* Checking for Off  */
if ( strlen(argv[5]) == 3 ) {
	if ( ((argv[5][0] == 'o') || (argv[5][0] == 'O')) && ((argv[5][1] == 'f') || (argv[5][1] == 'F')) && ((argv[5][2] == 'f') || ( argv[5][2] == 'F' ))  ) {
		
	} else {
		printf("Please enter on or off for the 5th parameter\n");
		exit(-1);
	}
	tracing = 0;
}

/* Read in file get number of addresses  */
FILE *filelinecount;
FILE *file;
char buffer[11];
int lines = 0;

filelinecount = fopen( argv[6], "r" );
if ( filelinecount == NULL ){
	fprintf(stderr, "Error: Could not open file.\n");
	return 1;
}

while ( fgets( buffer, 11, filelinecount  ) != NULL   ){
		
	lines++;
}

/* Set up address values */
/* Set up hex values */
i = 0;
int i2 = 0;
int i3 = 0;
file = fopen( argv[6], "r");
char addressvalues[11][lines];
int hexvalues[lines];
int temphex;

int intval = 0;
char hexval[11];
//sprintf(hexval,"%0x",intval);
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

/* Checks size of p to determine associativity */
if ( (p < 0 ) || ( p > ( cachesize - blocksize )  )  ){
	fullyassociative = 1;
} else if ( p == 0 ){
	directmapped = 1;
}else {
	associativity = (int) pow((double)(2),(double) p);
} 


/* Direct mapped */
int csize =(int) pow((double)2,(double)cachesize);
int bsize =(int) pow((double)2,(double)blocksize);

int totalblocks = csize/bsize;
int index = log2(totalblocks);
int tag = (32 - index - blocksize);


/* Direct mapped */
struct block blocks[totalblocks];
for (i = 0; i < totalblocks; i++){ 
	blocks[i].valid = 0;
	blocks[i].tag = 0;
	blocks[i].timebrought = 0;
	blocks[i].firstbrought = 0;
}


/* N-way */
int numsets = totalblocks/associativity;
//printf("%d numsets\n",numsets);
int setindex = log2(numsets);
//printf("%d setindex\n",setindex);
int settag = (32 - setindex - blocksize);
//printf("%d settag\n",settag);
struct set sets[numsets];
for (i = 0; i < numsets; i++){
	sets[i].blocks = (struct block *)malloc(sizeof(struct block) * associativity);
	for (i2 = 0; i2 < associativity; i2++){
		sets[i].blocks[i2].valid = 0;
		sets[i].blocks[i2].tag = 0;
		sets[i].blocks[i2].timebrought = 0;
		sets[i].blocks[i2].firstbrought = 0;
	}
}



/* Fully Associative */
int fullytag = (32-blocksize);
int fullyindex = 0;
struct set fully;
fully.blocks = (struct block*)malloc(sizeof(struct block) * totalblocks);
for (i = 0; i < totalblocks; i++){
	fully.blocks[i].valid = 0;
	fully.blocks[i].tag = 0;
	fully.blocks[i].timebrought = 0;
	fully.blocks[i].firstbrought = 0;
}




//printf("cache size in bytes : %d\n", csize);
//printf("block size in bytes : %d\n", bsize);
//printf("Blocks in cache : %d\n",totalblocks);
//printf("Offset : %d\n", blocksize);
//printf("Index : %d\n", index);



/* testing */
/*
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
*/
/* testing */


/* Direct mapped Tags and indexes  */
int tags[lines];
int indexes[lines];

char *tempbin;
char *tempformattedbin;

for (i = 0; i < lines; i++){
	tempbin = getBinary(hexvalues[i]);
	tempformattedbin = formatBinary(tempbin,tag,index,blocksize);
	parseMemoryAddress(tempformattedbin, tag, index, blocksize, &tags[i], &indexes[i]);
}

/* N-way tags and indexes */
int settags[lines];
int setindexes[lines];

*tempbin;
*tempformattedbin;

for (i = 0; i < lines; i++){
	tempbin = getBinary(hexvalues[i]);
	tempformattedbin = formatBinary(tempbin,settag,setindex,blocksize);
	parseMemoryAddress(tempformattedbin, settag, setindex, blocksize, &settags[i], &setindexes[i]);
}



/* Fully Associative */
int fullytags[lines];
int fullyindexes[lines];
*tempbin;
*tempformattedbin;

for (i = 0; i < lines; i++){
	tempbin = getBinary(hexvalues[i]);
	tempformattedbin = formatBinary(tempbin,fullytag,fullyindex,blocksize);
	parseMemoryAddress(tempformattedbin, fullytag, fullyindex, blocksize, &fullytags[i], &fullyindexes[i]);
}



/* variables to be used  */
double missratio = 0.0;
double accesses = 0.0;
double misses = 0.0;
int hits = 0;
char hit[4];
char miss[5];
int oldtag = 0;
int oldtime = 0;
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

int arraytags[lines][2];
int arraytagsindex = 0;
int arraytagsflag = 0;
for (i = 0; i < lines; i++){
	arraytags[i][0] = 0;
	arraytags[i][1] = 0;
}

int c = 0;
int d = 0;
int t = 0;
int t2 = 0;




if (directmapped){
	if (tracing) {	
		//printf("address\ttag\tblock\tmem tag\th/m \thits\tmisses\taccesses\tmiss ratio\t tags\n");
		printf("address\ttag\tblock\th/m \thits\tmisses\taccesses\tmiss ratio\t tags\n");
	}
	for ( i = 0; i < lines; i++){				
		//printf("tags : %d , indexes : %d \n",tags[i], indexes[i]);	
		
		accesses += 1.0;
		if (blocks[indexes[i]].valid == 0){
			blocks[indexes[i]].valid = 1;
			blocks[indexes[i]].tag = tags[i];
			blocks[indexes[i]].timebrought = accesses;
			blocks[indexes[i]].firstbrought = accesses;		
			missflag = 1;
			misses += 1.0;
			

			

				
			//printf("here");		
		}
		 else if (blocks[indexes[i]].valid == 1){
			if (blocks[indexes[i]].tag == tags[i]){
				oldtag = blocks[indexes[i]].tag;				

				

				/* here */
				if (fifolru){
					
					oldtime = blocks[indexes[i]].timebrought;		
					blocks[indexes[i]].timebrought = accesses;
				}else {
					
					oldtime = blocks[indexes[i]].firstbrought;
				}				


				blocks[indexes[i]].tag = tags[i];
				hits += 1;
				hitflag = 1;
				
				



			} else {
				misses += 1.0;
				missflag = 1;
				oldtag = blocks[indexes[i]].tag;

				if (fifolru){
					oldtime = blocks[indexes[i]].timebrought;
					
				}else {
					oldtime = blocks[indexes[i]].firstbrought;
					
				}

				blocks[indexes[i]].tag = tags[i];
				blocks[indexes[i]].timebrought = accesses;
				blocks[indexes[i]].firstbrought = accesses;		

							
			}
		
		}
		
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
				
			
			if (hitflag == 1){
				printf("%s \t ", hit);
			} else if (missflag == 1){
				printf("%s \t ", miss);
			}
							
				
				
				
			printf(" %d \t %d \t %d \t     %.8f\t " , hits , (int)misses , (int)accesses , missratio );
			if (oldtag > 0){
				printf("\t %x(%d) ", oldtag, oldtime);
			} else {
				printf("\t  ");
			}

 

		}
				
		
		if (tracing){			
			printf("\n");
		}
		arraytagsflag = 0;
		hitflag = 0;
		missflag = 0;		
		oldtag = 0;
		oldtime = 0;
		
	}
	printf("Ivan Capistran\n");
	printf("%s %s %s %s %s %s\n", argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
	printf("memory accesses: %d\n" , (int) accesses);
	printf("hits: %d\n" , hits);
	printf("misses: %d\n", (int)misses);
	printf("miss ratio: %.8f\n", missratio);
}
/* end of direct mapped */





/* Flags for N-way  */
int setempty = 1;
int notmatch = 1;
int setfull = 1;
int accesschecker = 0;
int accessindex = 0;


/* N-way set associative  */
if (!directmapped && !fullyassociative){
	if (tracing) {	
		printf("address\ttag\tset\th/m \thits\tmisses\taccesses\tmiss ratio\ttags\n");
	}
	
	for (i = 0; i < lines; i++){

		
	        accesses += 1.0;


		/* Checks if the set is empty */
		for (i2 = 0; i2 < associativity; i2++){
			if ( sets[setindexes[i]].blocks[i2].valid == 1  ){
				setempty = 0;
				//printf("not empty");
				break;
			}	
		}

		if (setempty){
			//printf("empty");
			misses += 1.0;
			sets[setindexes[i]].blocks[0].valid = 1;
			sets[setindexes[i]].blocks[0].tag = settags[i];
			sets[setindexes[i]].blocks[0].timebrought = accesses;
			sets[setindexes[i]].blocks[0].firstbrought = accesses;
			missflag = 1;

			/* depends on policy */
			/* for loop in array tags if it's in the array update it */
			/* if not in the array add it to the next value */
			if (fifolru){
				/* lru */

				if (arraytagsindex == 0){
					
					arraytags[0][0] = sets[setindexes[i]].blocks[0].tag;
					arraytags[0][1] = sets[setindexes[i]].blocks[0].timebrought;
					arraytagsindex += 1;
				}else {
				
					for (i2 = 0; i2 < arraytagsindex; i2++){
						if (arraytags[i2][0] == sets[setindexes[i]].blocks[0].tag ){
							
							arraytags[i2][1] = sets[setindexes[i]].blocks[0].timebrought;
							arraytagsflag = 1; 
						}				
											
						
					}

					if (arraytagsflag == 0){
						arraytags[arraytagsindex][0] = sets[setindexes[i]].blocks[0].tag;
						arraytags[arraytagsindex][1] = sets[setindexes[i]].blocks[0].timebrought;
						arraytagsindex += 1;

					}
					

				}


			} else {
				/* fifo */
				if (arraytagsindex == 0){
					
					arraytags[0][0] = sets[setindexes[i]].blocks[0].tag;
					arraytags[0][1] = sets[setindexes[i]].blocks[0].firstbrought;
					arraytagsindex += 1;
				}else {
				
					for (i2 = 0; i2 < arraytagsindex; i2++){
						if (arraytags[i2][0] == sets[setindexes[i]].blocks[0].tag ){
							
							//arraytags[i2][1] = sets[setindexes[i]].blocks[0].timebrought;
							arraytagsflag = 1; 
						}				
											
						
					}

					if (arraytagsflag == 0){
						arraytags[arraytagsindex][0] = sets[setindexes[i]].blocks[0].tag;
						arraytags[arraytagsindex][1] = sets[setindexes[i]].blocks[0].firstbrought;
						arraytagsindex += 1;

					}
					

				}



			}

			

		}else {
			//printf("checking for a hit\n");
			/* Checking for a hit */
			for (i2 = 0; i2 < associativity; i2++){
				if ( ( sets[setindexes[i]].blocks[i2].valid == 1) && (settags[i] == sets[setindexes[i]].blocks[i2].tag )){
				//if ((settags[i] == sets[setindexes[i]].blocks[i2].tag )){
					//printf("here");	
					hitflag = 1;
					if (fifolru){
						/* lru */					
						sets[setindexes[i]].blocks[i2].timebrought = accesses;
			

						/* need to update the array here also */
						for (i3 = 0; i3 < arraytagsindex; i3++){
							if (arraytags[i3][0] == sets[setindexes[i]].blocks[i2].tag ){
							
								arraytags[i3][1] = sets[setindexes[i]].blocks[i2].timebrought;
								//arraytagsflag = 1; 
							}			

						}


						
					
						
						hits += 1;	
					}else {
						/* fifo */			
							

						/* need to update the array here also maybe depending on algorithm */

				
						hits += 1;
					}
					break;				
				}
			}
			if (hitflag == 0){
				//printf("it was a miss");
				missflag = 1;
				misses += 1;
				for (i2 = 0; i2 < associativity; i2++){
					if (sets[setindexes[i]].blocks[i2].valid == 0){
						setfull = 0;
						//printf("not full at %d ", i2);
						break;
					}									
				}
				if ( setfull == 0  ) {
					//printf(" so not full\n");
					for (i2 = 0; i2 < associativity; i2++){
						if (sets[setindexes[i]].blocks[i2].valid == 0){
							//printf(" adding to block at :%d",i2);
							sets[setindexes[i]].blocks[i2].valid = 1;
							sets[setindexes[i]].blocks[i2].tag = settags[i];
							sets[setindexes[i]].blocks[i2].timebrought = accesses;
							sets[setindexes[i]].blocks[i2].firstbrought = accesses;



							/* for loop in array tags if it's in the array update it */
							/* if not in the array add it to the next value */
							if (fifolru){
								/* lru */

								
				
									for (i3 = 0; i3 < arraytagsindex; i3++){
										if (arraytags[i3][0] == sets[setindexes[i]].blocks[i2].tag ){
							
											arraytags[i3][1] = sets[setindexes[i]].blocks[i2].timebrought;
											arraytagsflag = 1; 
										}				
											
						
									}

									if (arraytagsflag == 0){
										arraytags[arraytagsindex][0] = sets[setindexes[i]].blocks[i2].tag;
										arraytags[arraytagsindex][1] = sets[setindexes[i]].blocks[i2].timebrought;
										arraytagsindex += 1;

									}
					

							


							} else {
								/* fifo */
								
				
									for (i3 = 0; i3 < arraytagsindex; i3++){
										if (arraytags[i3][0] == sets[setindexes[i]].blocks[i2].tag ){
							
											//arraytags[i2][1] = sets[setindexes[i]].blocks[0].timebrought;
											arraytagsflag = 1; 
										}				
											
						
									}

									if (arraytagsflag == 0){
										arraytags[arraytagsindex][0] = sets[setindexes[i]].blocks[i2].tag;
										arraytags[arraytagsindex][1] = sets[setindexes[i]].blocks[i2].firstbrought;
										arraytagsindex += 1;

									}
					

								



							}


							//printf(" %x %d \n",);

							break;
						}									
					}	
					
					
				//}else if (setfull){
				} else {
					/* replace policy if miss */
					if (fifolru){
						/* lru */

						accesschecker = sets[setindexes[i]].blocks[0].timebrought;
						
						for (i2 = 1; i2 < associativity; i2++){
							if (sets[setindexes[i]].blocks[i2].timebrought < accesschecker){
								accesschecker = sets[setindexes[i]].blocks[i2].timebrought;
								accessindex = i2;
							}									
						}

						sets[setindexes[i]].blocks[accessindex].tag = settags[i];
						sets[setindexes[i]].blocks[accessindex].timebrought = accesses;	

						/* depends on policy */
						/* for loop in array tags if it's in the array update it */
						/* if not in the array add it to the next value */
						if (fifolru){
							/* lru */
							for (i3 = 0; i3 < arraytagsindex; i3++){
								if (arraytags[i3][0] == sets[setindexes[i]].blocks[accessindex].tag ){
							
									arraytags[i3][1] = sets[setindexes[i]].blocks[accessindex].timebrought;
									arraytagsflag = 1; 
								}				
											
						
							}

							if (arraytagsflag == 0){
								arraytags[arraytagsindex][0] = sets[setindexes[i]].blocks[accessindex].tag;
								arraytags[arraytagsindex][1] = sets[setindexes[i]].blocks[accessindex].timebrought;
								arraytagsindex += 1;

							}
							
						}


					
						




					}else {
						/* fifo */

						accesschecker = sets[setindexes[i]].blocks[0].timebrought;
						for (i2 = 1; i2 < associativity; i2++){
							if (sets[setindexes[i]].blocks[i2].timebrought < accesschecker){
								accesschecker = sets[setindexes[i]].blocks[i2].timebrought;
								accessindex = i2;
							}									
						}

						sets[setindexes[i]].blocks[accessindex].tag = settags[i];
						sets[setindexes[i]].blocks[accessindex].timebrought = accesses;

						/* depends on policy */
						/* for loop in array tags if it's in the array update it */
						/* if not in the array add it to the next value */
						if (fifolru){
							/* lru */
				



						} else {
							/* fifo */
							for (i3 = 0; i3 < arraytagsindex; i3++){
								if (arraytags[i3][0] == sets[setindexes[i]].blocks[accessindex].tag ){
							
									//arraytags[i3][1] = sets[setindexes[i]].blocks[accessindex].timebrought;
									arraytagsflag = 1; 
								}				
											
						
							}

							if (arraytagsflag == 0){
								arraytags[arraytagsindex][0] = sets[setindexes[i]].blocks[accessindex].tag;
								arraytags[arraytagsindex][1] = sets[setindexes[i]].blocks[accessindex].firstbrought;
								arraytagsindex += 1;

							}



						}
					}	
				}					
			}
		}

		/* testing */
		//for (i2 = 0; i2< associativity; i2++){
		//	printf(" %x:%d ",sets[setindexes[i]].blocks[i2].tag, sets[setindexes[i]].blocks[i2].timebrought ); 										
		//}
		//printf("\n");



		/* Debugging */
		//printf("tag:%x index:%x \n",settags[i],setindexes[i]);
		
		
		missratio = (misses/accesses);
	
		if (tracing){					
			
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

			printf("\t %x\t %x \t", settags[i], setindexes[i]);
			
			if (hitflag == 1){
				printf("%s \t", hit);
			} else if (missflag == 1){
				printf("%s \t", miss);
			}
			
			printf(" %d \t %d \t %d \t     %.8f" , hits , (int)misses , (int)accesses , missratio ); 

			
			/* for loop the tags in the cache with the times */
			/* sort based on tag */			
						 
			for (c = 1 ; c <= arraytagsindex - 1; c++) {
   			 	d = c;
 
    				while ( d > 0 && arraytags[d][0] < arraytags[d-1][0]) {
      					t          = arraytags[d][0];
					t2	   = arraytags[d][1];
      					arraytags[d][0]   = arraytags[d-1][0];
      					arraytags[d][1]   = arraytags[d-1][1];
      					arraytags[d-1][0] = t;
       					arraytags[d-1][1] = t2;
      					d--;
    				}
  			}
			
			for (i2 = 0; i2 < arraytagsindex; i2++){
				printf (" %x(%d)", arraytags[i2][0], arraytags[i2][1] );
				
			} 


			printf("\n");
		}

		setempty = 1;
		hitflag = 0;
		missflag = 0;
		setfull = 1;
		accesschecker = 0;
		accessindex = 0;
		notmatch = 1;
		arraytagsflag = 0;
	}
	/* end of simulation -- end of main loop */



	printf("Ivan Capistran\n");
	printf("%s %s %s %s %s %s\n", argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
	printf("memory accesses: %d\n" , (int) accesses);
	printf("hits: %d\n" , hits);
	printf("misses: %d\n", (int)misses);
	printf("miss ratio: %.8f\n", missratio);
}
/* N-Way end */



int tagmatch = 0;
/* Fully associative */
if (fullyassociative){
	if (tracing){
		printf("address\ttag\tset\th/m \thits\tmisses\taccesses\tmiss ratio\ttags\n");
	}

	

	for (i = 0; i < lines; i++){
		accesses += 1.0;
		/* Go through and see about whether the tags match.  */
		/* If they match set a flag */
		for (i2 = 0; i2 < totalblocks; i2++){
			if ( ( fully.blocks[i2].valid == 1 ) && ( fully.blocks[i2].tag == fullytags[i] ) ){
				//fully.blocks[i2].tag = fullytags[i];
				hits += 1;
				hitflag = 1;			
				if (fifolru){
					/* LRU */
					fully.blocks[i2].timebrought = accesses;

				} else {
					/* FIFO */


				}
				

				tagmatch = 1;
			}
		}
			
				
			
					
		if (!tagmatch){
			misses += 1.0;
			missflag = 1;
			for (i2 = 0; i2 < totalblocks; i2++){
				if (fully.blocks[i2].valid == 0){
					fully.blocks[i2].tag = fullytags[i];
					fully.blocks[i2].valid = 1;
					fully.blocks[i2].timebrought = accesses;
					fully.blocks[i2].firstbrought = accesses;
					break;
				}
			}
		
		}
		
	
		missratio = (misses/accesses);

		if (tracing){
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

			printf("\t %x\t %x \t", fullytags[i], fullyindexes[i]);
			
			if (hitflag == 1){
				printf("%s \t", hit);
			} else if (missflag == 1){
				printf("%s \t", miss);
			}
			
			printf(" %d \t %d \t %d \t     %.8f" , hits , (int)misses , (int)accesses , missratio ); 


			printf("\n");

			tagmatch = 0;
			hitflag = 0;
			missflag = 0;



		}



		
	}


	printf("Ivan Capistran\n");
        printf("%s %s %s %s %s %s\n", argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
        printf("memory accesses: %d\n" , (int) accesses);
        printf("hits: %d\n" , hits);
        printf("misses: %d\n", (int)misses);
        printf("miss ratio: %.8f\n", missratio);
}



/* Free blocks for n-way */
for (i = 0; i < numsets; i++){
	free(sets[i].blocks);
}
/* Free set for fully */
	free(fully.blocks);

	return 0;
}

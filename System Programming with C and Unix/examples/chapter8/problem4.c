
	/* Code for problm 4 (pg 292) */

#include <stdio.h>
#include <stdlib.h>
#include <wintrust.h>

	/* ... */

WINTRUST_FILE_INFO	FileData;

memset(&FileData, 0, sizeof(FileData));
FileData.cbStruct = sizeof(WINTRUST_FILE_INFO);
FileData.pcwszFilePath = pwszSourceFile;
FileData.hFile = NULL;
FileData.pgKnownSubject = NULL;


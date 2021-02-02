#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>

// recursive function to traverse through directories
void traverseDir(const char *path, short iteration);

// used for concatenating two directory names
char* concat(const char *s1, const char *s2);

// converts bits into human readable format
void printSize(double sizeInBytes);

static const char* sizes[] = {"bytes", "KB", "MB", "GB"};

// detect files with size greater than threshold
long m_threshold;

// for not to get lost in chained folders
// since it searches in a very DFS way
short m_iteration;

int main(int argc, char *argv[])
{
	const char *path = argv[1];
	
	m_threshold = strtol(argv[2], NULL, 10);
	
	m_iteration = strtol(argv[3], NULL, 10);
	
	traverseDir(path, 0);
	
	return 0;
}


void traverseDir(const char *path, short iteration)
{
	struct dirent *dp;
	struct stat file_info;
	DIR *dir = opendir(path);
	
	// read twice to escape /. and /..
	dp = readdir(dir);
	dp = readdir(dir);
	
	while(dp = readdir(dir))
	{
		stat(concat(concat(path, "/"), dp->d_name), &file_info);
		
		// get into folders those are not so deep
		if(S_ISDIR(file_info.st_mode) && iteration<=m_iteration)
		{
			traverseDir(concat(concat(path, "/"), dp->d_name), iteration+1);
		}
		else
		{
			// print once you find a file with gigantic size
			if(file_info.st_size >= m_threshold)
			{
				printf("%s/%s, ", path, dp->d_name);
				printSize((double)file_info.st_size);
			}
		}
	}
	closedir(dir);
}

char* concat(const char *s1, const char *s2)
{
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);
    char *result = (char*) malloc(len1 + len2 + 1);
    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2 + 1);
    return result;
}

void printSize(double sizeInBytes)
{
	double result;
	short iterator = -1;
	while(sizeInBytes > 1 && iterator < 3)
	{
		result = sizeInBytes;
		
		sizeInBytes /= 1024;
		
		iterator++;
	}
	
	printf("%.1f %s\n", result, sizes[iterator]);
}

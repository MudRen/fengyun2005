#include <ansi.h>
#include <mudlib.h>
#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int mark_loaded;
	int i,totalCount;
	string dir;
	mixed *file;
	object *objectlist;
	
	dir = resolve_path(me->query("cwd"), arg);

	if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";
	file = get_dir(dir, -1);
	if( !sizeof(file) )
	{
		if (file_size(dir) == -2) 
			return notify_fail("dir is empty。\n");
		else 
			return notify_fail("no such dir or file。\n");
	}

	i = sizeof(file);
	
	write("object info for " + dir + "\n");
	
	if (sizeof(file))
	{
		int obCount;
		string obFileFullPath,obFile;
		for(i=0; i < sizeof(file); i++){
			obFileFullPath = dir + file[i][0];
			
			if(sscanf(obFileFullPath,"%s.c",obFile) == 1 || sscanf(obFileFullPath,"%s.o",obFile)){
				objectlist = children(obFile);
				obCount = sizeof(objectlist);
				if(obCount > 0){
					printf("object base name %s:  %d \n",obFile,obCount);
					totalCount += obCount;
				}
			}
				
			//find_object(dir + file[i][0])) 
		}
		printf("Total object count : %d \n",totalCount);
	}
	else 
		write("    no file。\n");
	write("\n");	
	return 1;	
}
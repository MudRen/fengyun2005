// purge.c

#include <ansi.h>

inherit F_CLEAN_UP;
int rmhirdir(string dir);
int main(object me, string arg)
{
        if(!me->query("env/yesiknow")) return notify_fail("这个指令已经被废除了！\n");
	rmhirdir(arg);
	return 1;
}

int rmhirdir(string dirstr)
{
string *dir;
int i;
dir = get_dir(dirstr+"/");
        for(i=0; i<sizeof(dir); i++) {
		if(file_size(dirstr+"/"+dir[i]) == -2 ) {
				rmhirdir( dirstr +"/"+dir[i]);
				rmdir(dirstr+"/"+dir[i]);
						}
		rm(dirstr+"/"+dir[i]);
	}
rmdir(dirstr);

return 1;

}

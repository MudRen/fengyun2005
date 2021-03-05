#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
        string *files;
        int i;
        int size;
        set_eval_limit(1); 
        seteuid(getuid());
        if(!arg || arg=="") return notify_fail("格式不对！\n");
    
    
        files= get_dir(arg);
        reset_eval_cost();
        for(i=0; i<sizeof(files); i++) 
        {
                    size=sizeof(files[i]);
                if(files[i][(size-2)..size]==".c")
                        {
				size=SKILL_D(files[i])->skill_difficulty();
                                if (size>200)
                        write(sprintf("%s diff=%d\n",files[i],size));
                        }
        }               
        return 1;
}

